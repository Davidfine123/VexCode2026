#include <cmath>
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/logger/logger.hpp"
#include "lemlib/timer.hpp"
#include "lemlib/util.hpp"
#include "pros/misc.hpp"
#include "components.hpp"
#include "lemlib/chassis/odom.hpp"

void lemlib::Chassis::moveForward(float dist, int timeout, MoveToPointParams params, bool async) {
    params.earlyExitRange = fabs(params.earlyExitRange);
    this->requestMotionStart();
    // were all motions cancelled?
    if (!this->motionRunning) return;
    // if the function is async, run it in a new task
    if (async) {
        pros::Task task([&]() {
            moveForward(dist,timeout, params, false);
        });
        this->endMotion();
        pros::delay(10); // delay to give the task time to start
        return;
    }

    // reset PIDs and exit conditions
    lateralPID.reset();
    lateralLargeExit.reset();
    lateralSmallExit.reset();
    

    // initialize vars used between iterations
    Pose lastPose = getPose();
    distTraveled = 0;
    Timer timer(timeout);
    bool close = false;
    float prevLateralOut = 0; // previous lateral power
    const int compState = pros::competition::get_status();


    float initTheta = getPose(true, true).theta;
    float initDistanceTraveled = lemlib::getDistanceTraveled();
    if (dist < 0) dist = -dist;
    // main loop
    while (!timer.isDone() && ((!lateralSmallExit.getExit() && !lateralLargeExit.getExit())) &&
           this->motionRunning) {
        

        // update distance traveled
        distTraveled = lemlib::getDistanceTraveled() - initDistanceTraveled;
         

        // check if the robot is close enough to the target to start settling
        if (distTraveled > dist * 0.8) {
            params.maxSpeed = fmax(fabs(prevLateralOut), 60);
        }

        // calculate error

        float lateralError = dist - distTraveled;

        // update exit conditions
        lateralSmallExit.update(lateralError);
        lateralLargeExit.update(lateralError);

        // get output from PIDs
        float lateralOut = lateralPID.update(lateralError);


        // apply restrictions on lateral speed
        lateralOut = std::clamp(lateralOut, -params.maxSpeed, params.maxSpeed);
        // constrain lateral output by max accel
        // but not for decelerating, since that would interfere with settling

        // prevent moving in the wrong direction
        if (params.forwards) lateralOut = std::fmax(lateralOut, 0);
        else if (!params.forwards) lateralOut = std::fmin(-lateralOut, 0);

        // constrain lateral output by the minimum speed
        if (params.forwards && lateralOut < fabs(params.minSpeed) && lateralOut > 0) lateralOut = fabs(params.minSpeed);
        if (!params.forwards && -lateralOut < fabs(params.minSpeed) && lateralOut < 0)
            lateralOut = -fabs(params.minSpeed);

        // update previous output
        prevLateralOut = lateralOut;

        infoSink()->debug(" Lateral Out: {}",  lateralOut);

        // ratio the speeds to respect the max speed
        float leftPower = lateralOut;
        float rightPower = lateralOut;
        const float ratio = std::max(std::fabs(leftPower), std::fabs(rightPower)) / params.maxSpeed;
        if (ratio > 1) {
            leftPower /= ratio;
            rightPower /= ratio;
        }
        float currentTheta = getPose(true, true).theta;
        bool isTurningLeft = false;
        float thetaDiff = 0;
        float penalty = 100;
        if ( currentTheta > initTheta) {
            isTurningLeft = false;
            thetaDiff = currentTheta - initTheta;
        }
        if (initTheta > 300 && fabs(currentTheta - initTheta) > 90) {
            isTurningLeft = false;
            thetaDiff = currentTheta + 360 - initTheta;
        }
        if ( currentTheta <= 359.99 && currentTheta < initTheta) {
            isTurningLeft = true;
            thetaDiff = currentTheta - initTheta;
        }
        if (currentTheta > 300 && fabs(currentTheta - initTheta) > 90) {
            isTurningLeft = true;
            thetaDiff = currentTheta - 360 - initTheta;
        }

        // move the drivetrain
        drivetrain.leftMotors->move(leftPower + thetaDiff * penalty);
        drivetrain.rightMotors->move(rightPower - thetaDiff * penalty);

        // delay to save resources
        pros::delay(10);
    }

    // stop the drivetrain
    drivetrain.leftMotors->move(0);
    drivetrain.rightMotors->move(0);
    // pros::v5::MotorBrake brake_mode = drivetrain.leftMotors->get_brake_mode();
    // drivetrain.leftMotors->set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
    // drivetrain.rightMotors->set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
    drivetrain.leftMotors->brake();
    drivetrain.rightMotors->brake();

    // set distTraveled to -1 to indicate that the function has finished
    distTraveled = -1;
    this->endMotion();
    // drivetrain.leftMotors->set_brake_mode_all(brake_mode);
    // drivetrain.rightMotors->set_brake_mode_all(brake_mode);
}