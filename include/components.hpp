#pragma once
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "subsystems/conveyor.hpp"
#include "subsystems/spinner.hpp"
#include "subsystems/holder.hpp"
#include "pros/adi.hpp"


// controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// motor groups
pros::MotorGroup leftMotors({-18, -20, 19},
                            pros::MotorGearset::blue); // left motor group - ports 10, 8 (reversed), 7
pros::MotorGroup rightMotors({8, 10, -9},
                             pros::MotorGearset::blue); // right motor group - ports 1 (reversed), 2 , 3 (reversed)
//No Arm Use this year
// lemlib::ControllerSettings armAngularController(2, // proportional gain (kP)
//                                                 0, // integral gain (kI)
//                                                 10, // derivative gain (kD)
//                                                 3, // anti windup
//                                                 0.5, // small error range, in degrees
//                                                 100, // small error range timeout, in milliseconds
//                                                 1, // large error range, in degrees
//                                                 500, // large error range timeout, in milliseconds
//                                                 0 // maximum acceleration (slew)
// );
// ArmNamespace::Arm arm(std::make_shared<pros::Motor>(6, pros::v5::MotorGears::red), // arm - motor port 5 (reversed)
//                       std::make_shared<pros::Rotation>(-21), // rotation sensor - port 17 (reversed)
//                       armAngularController, armAngularControllerSmallAngle); // PID controller
// lemlib::ControllerSettings armAngularControllerSmallAngle(2, // proportional gain (kP)
//                                                 0, // integral gain (kI)
//                                                 10, // derivative gain (kD)
//                                                 3, // anti windup
//                                                 0.5, // small error range, in degrees
//                                                 100, // small error range timeout, in milliseconds
//                                                 1, // large error range, in degrees
//                                                 500, // large error range timeout, in milliseconds
//                                                 0 // maximum acceleration (slew)
// );

// Other Subsystems
std::unordered_map<std::string, std::shared_ptr<pros::Distance>> distances {
    {"left", std::make_shared<pros::Distance>(16)},
    {"right", std::make_shared<pros::Distance>(5)},
    {"front", std::make_shared<pros::Distance>(11)}};

pros::Distance clampSensor(3); // distance sensor - port 4

SpinnerNamespace::Spinner bottomRoller(std::make_shared<pros::Motor>(-4, pros::v5::MotorGears::green)); // intake - motor port 7
SpinnerNamespace::Spinner insideRoller(std::make_shared<pros::Motor>(7, pros::v5::MotorGears::green)); // hooks - motor port 11
SpinnerNamespace::Spinner scoreRoller(std::make_shared<pros::Motor>(8, pros::v5::MotorGears::blue)); // hooks - motor port 11
ConveyorNamespace::Conveyor conveyor(&bottomRoller, // intake
                                     &insideRoller, // hooks
                                     &scoreRoller, // score roller
                                     std::make_shared<pros::Optical>(15), // optical sensor - port 14
                                     std::make_shared<pros::Distance>(1) // distance sensor - port 20
);
HolderNamespace::Holder holder(std::make_shared<pros::adi::DigitalOut>('G'),
                               std::make_shared<pros::Distance>(6)); // mobile goal holder - port 'B'
HolderNamespace::Holder doinker(std::make_shared<pros::adi::DigitalOut>('D')); // doinker - port 'A'
HolderNamespace::Holder hanger(std::make_shared<pros::adi::DigitalOut>('C')); // hanger - port 'H'
HolderNamespace::Holder intake_raiser(std::make_shared<pros::adi::DigitalOut>('H')); // intake peu - port 'C'

// Inertial Sensor on port 21
pros::Imu imu(2);

// tracking wheels
// horizontal tracking wheel encoder. Rotation sensor, port 20, reversed
pros::Rotation horizontalEnc(14);
// vertical tracking wheel encoder. Rotation sensor, port 19, reversed
pros::Rotation verticalEnc(-13);
// horizontal tracking wheel. 2" diameter, 3.625" offset, back of the robot (negative)
lemlib::TrackingWheel horizontal(&horizontalEnc, 2, -0.5);
// vertical tracking wheel. 2" diameter, 0.5" offset, left of the robot (negative)
lemlib::TrackingWheel vertical(&verticalEnc, 2, 0.6);

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
                              &rightMotors, // right motor group
                              12.5, // 11.5 inch track width
                              3.25, // using new 2.75" omnis
                              450, // drivetrain rpm is 450
                              2 // horizontal drift is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
lemlib::ControllerSettings linearController(10, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            3, // derivative gain (kD)
                                            3, // anti windup
                                            0.5, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            1, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            20 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(2, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             10, // derivative gain (kD)
                                             3, // anti windup
                                             0.5, // small error range, in degrees
                                             100, // small error range timeout, in milliseconds
                                             1, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);

// sensors for odometry
lemlib::OdomSensors sensors(&vertical, // vertical tracking wheel
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
                            &horizontal, // horizontal tracking wheel
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu, // inertial sensor
                            &distances // distance sensors
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.019 // expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors, &throttleCurve, &steerCurve);


// angular motion controller
lemlib::ControllerSettings angularControllerSmall(1.1, // proportional gain (kP)
                                             0.05, // integral gain (kI)
                                             0, // derivative gain (kD)
                                             3, // anti windup
                                             0.5, // small error range, in degrees
                                             100, // small error range timeout, in milliseconds
                                             1, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);

// create the chassis
lemlib::Chassis chassisSmall(drivetrain, linearController, angularControllerSmall, sensors, &throttleCurve, &steerCurve);