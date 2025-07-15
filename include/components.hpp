#pragma once
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "subsystems/conveyor.hpp"
#include "subsystems/spinner.hpp"
#include "subsystems/holder.hpp"
#include "pros/adi.hpp"


// controller
extern pros::Controller controller;

// motor groups
extern pros::MotorGroup leftMotors; // left motor group - ports 10, 8 (reversed), 7
extern pros::MotorGroup rightMotors; // right motor group - ports 1 (reversed), 2 , 3 (reversed)
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
extern std::unordered_map<std::string, std::shared_ptr<pros::Distance>> distances;

extern pros::Distance clampSensor; // distance sensor - port 4

extern SpinnerNamespace::Spinner bottomRoller; // intake - motor port 7
extern SpinnerNamespace::Spinner insideRoller; // hooks - motor port 11
extern SpinnerNamespace::Spinner scoreRoller; // hooks - motor port 11
extern ConveyorNamespace::Conveyor conveyor;
extern HolderNamespace::Holder doinker; // doinker - port 'A'


// Inertial Sensor on port 21
extern pros::Imu imu;

// tracking wheels
// horizontal tracking wheel encoder. Rotation sensor, port 20, reversed
extern pros::Rotation horizontalEnc;
// vertical tracking wheel encoder. Rotation sensor, port 19, reversed
extern pros::Rotation verticalEnc;
// horizontal tracking wheel. 2" diameter, 3.625" offset, back of the robot (negative)
extern lemlib::TrackingWheel horizontal;
// vertical tracking wheel. 2" diameter, 0.5" offset, left of the robot (negative)
extern lemlib::TrackingWheel vertical;

// drivetrain settings
extern lemlib::Drivetrain drivetrain;
                              
// lateral motion controller
extern lemlib::ControllerSettings linearController;
                                            

// angular motion controller
extern lemlib::ControllerSettings angularController;
                                             

// sensors for odometry
extern lemlib::OdomSensors sensors;

// input curve for throttle input during driver control
extern lemlib::ExpoDriveCurve throttleCurve;

// input curve for steer input during driver control
extern lemlib::ExpoDriveCurve steerCurve;

// create the chassis
extern lemlib::Chassis chassis;


// angular motion controller
extern lemlib::ControllerSettings angularControllerSmall;

// create the chassis
extern lemlib::Chassis chassisSmall;