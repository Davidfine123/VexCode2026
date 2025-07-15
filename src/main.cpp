#include "components.hpp"
#include "auton/utility.hpp"
#include <numeric>
#include <random>
#include "particle_filter.h"
#include "constants.hpp"



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    chassis.calibrate(); // calibrate sensors
    conveyor.getOpticalSensor()->set_led_pwm(100);


    // Selector callback example, prints selected auton to the console
    if(autonSelector){
        selector.on_select([](std::optional<rd::Selector::routine_t> routine) {
            if (routine == std::nullopt) {
                std::cout << "No routine selected" << std::endl;
            } else {
                std::cout << "Selected Routine: " << routine.value().name << std::endl;
            }
        });
    }

    // bool routineSelected = false;

    // selector.on_select([&](std::optional<rd::Selector::routine_t> routine) {
    //     while (true) {
    //         if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
    //             std::cout << "Selected Routine: " << routine.value().name << std::endl;
    //             autonName = routine.value().name;
    //             routineSelected = true;
    //             break;
    //         }
    //         pros::delay(100);
    //     }
    // });
    
    // // Wait until a routine is selected
    // while (!routineSelected) {
    //     pros::delay(100);
    // }


    // the default rate is 50. however, if you need to change the rate, you
    // can do the following.
    // lemlib::bufferedStdout().setRate(...);
    // If you use bluetooth or a wired connection, you will want to have a rate of 10ms

    // for more information on how the formatting for the loggers
    // works, refer to the fmtlib docs

        // thread to for brain screen and position logging
    if(autonSelector == false){
        pros::Task screenTask   ([&]() {
            while (true) {
                pros::screen::erase();
                // print robot location to the brain screen
                pros::screen::print(pros::text_format_e_t::E_TEXT_MEDIUM_CENTER, 0, "X: %f, Y: %f, Theta: %f",
                                    chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta); // x
                pros::screen::print(pros::text_format_e_t::E_TEXT_MEDIUM_CENTER, 1, "init Color: %s",
                                    conveyor.getInitColor() == ConveyorNamespace::Color::RED ? "RED" : "BLUE");
                pros::screen::print(pros::text_format_e_t::E_TEXT_MEDIUM_CENTER, 2, "Detected the wrong ring: %s",
                                    conveyor.detectWrongRing() ? "True" : "False");
                pros::screen::print(pros::text_format_e_t::E_TEXT_MEDIUM_CENTER, 3, "Conveyor Motor Current Limit: %d",
                                    conveyor.getHooks()->getMotor()->get_current_limit());
                pros::screen::print(pros::text_format_e_t::E_TEXT_MEDIUM_CENTER, 4, "Conveyor Motor Current: %d",
                                    conveyor.getHooks()->getMotor()->get_current_draw());
                pros::screen::print(pros::text_format_e_t::E_TEXT_MEDIUM_CENTER, 5, "Conveyor reverse: %s",
                                    conveyor.is_reversed() ? "True" : "False");
               
                pros::screen::print(pros::text_format_e_t::E_TEXT_MEDIUM_CENTER, 9, "Mogo holder detected: %s",
                                    holder.detectedMogo() ? "True" : "False");
                // pros::screen::print(pros::text_format_e_t::E_TEXT_MEDIUM_CENTER, 10, "Particle filter size: %d",
                //                     pf.num_particles, "weight: %f",
                //                     std::accumulate(pf.weights.begin(), pf.weights.end(), 0.0));
                pros::delay(50);
            }
        });
    }
}

/**
 * Runs while the robot is disabled
 */
void disabled() {}

/**
 * runs after initialize if the robot is connected to field control
 */
void competition_initialize() {}

// get a path used for pure pursuit
// this needs to be put outside a function
ASSET(example_txt); // '.' replaced with "_" to make c++ happy

/**
 * Runs during auto
 *
 * This is an example autonomous routine which demonstrates a lot of the features LemLib has to offer
 */

//  void autonomous() {

//     if (withAutoClamp) {
//         pros::Task mobileGoalClamp([&]() {
//             while (true) {
    
//                 if (holder.getState() == HolderNamespace::State::RELEASE && !activeAutoClamp) {
//                     pros::delay(2000);
//                     activeAutoClamp = true;
//                 }    
                
//                 if (clampSensor.get_distance() < 53 && activeAutoClamp) {
//                     holder.moveToState(HolderNamespace::State::HOLD);
//                     activeAutoClamp = false;
//                 }                 
//                 pros::delay(20);
//             }
//         });
//     }

//     if (competitionStatus == "practice") {
//         if (autonName == "signature_blue_negtive") {
//             signature_blue_negtive();
//         }
//         else if (autonName == "signature_red_negtive_qual") {
//             signature_red_negtive_qual();
//         }
 
//     }
//     else if (competitionStatus == "competition") {
//         if (RUN_SKILLS) skills();
//         else selector.run_auton();
//     }
//     return;
// }

void autonomous() {
    // skills();
    if (withAutoClamp) {
        pros::Task mobileGoalClamp([&]() {
            while (withAutoClamp) {
    
                if (holder.getState() == HolderNamespace::State::RELEASE && !activeAutoClamp) {
                    pros::delay(2000);
                    activeAutoClamp = true;
                }    
                
                if (clampSensor.get_distance() < 46 && activeAutoClamp) {
                    holder.moveToState(HolderNamespace::State::HOLD);
                    activeAutoClamp = false;
                }                 
                pros::delay(20);
            }
            pros::delay(20);
        });
    }

    if (withAntiJam) {
        pros::Task antiJam([&]() {
            while (withAntiJam) {
                if (conveyor.getIntake()->getMotor()->get_actual_velocity() > 100 && conveyor.getHooks()->getMotor()->get_actual_velocity() < 50 && conveyor.getHooks()->getMotor()->get_current_draw() > 1500) {
                    ConveyorNamespace::State curState = conveyor.getState();
                    conveyor.moveToState(ConveyorNamespace::State::REVERSE);
                    pros::delay(100);
                    conveyor.moveToState(curState);
                }
                pros::delay(20);
            }
            pros::delay(20);
        });
    }


    if (autonSelector) {
        if (RUN_SKILLS) skills();
        else selector.run_auton();

    }
    else  {
        Test();
        //signature_red_negative_qual();
        //signature_blue_negative();
        //red_pos_Alliance();
        //blue_pos_Alliance
        
    }
    return;
    // signature_blue_negtive();
  
    //blue_rush_sweep();
    //blue_positive();
    //red_positive(); 
    //red_right_sweep();
    // if (RUN_SKILLS) skills();
    // else selector.run_auton();
    //blue_six_rings();
    //red_six_rings();
    //red_right_sweep();
    // red_solo();
    // blue_solo();
    // return;
}

/**
 * Runs in driver control
 */
void opcontrol() {
    lemlib::Timer timer(15000);
    withAutoClamp = false;
    withAntiJam = false;

    if (RUN_SKILLS) {
        // Need to comment out for normal driving
        //arm.resetRotation(1800);
        // conveyor.disable_color_sensor();
    }

    lemlib::Timer hanger_timer(55000);
    holder.deactivateAuto();
    // controller
    // loop to continuously update motors
    while (true) {
        if (timer.isDone()) {
            controller.rumble(".-.-");
            timer.reset();
        }
        if (hanger_timer.isDone()) {
            if (RUN_SKILLS) { hanger.moveToState(HolderNamespace::State::HOLD); }
            hanger_timer.reset();
        }
        // get joystick positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        // Get button states with clearer variable names
        bool buttonR2 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
        bool buttonY = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y);
        bool buttonL1 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
        bool buttonL2 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
        bool buttonR1 = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1);
        bool buttonA = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A);
        bool buttonUp = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP);
        bool buttonDown = controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
        bool buttonLeft = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT);
        bool buttonRight = controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT);
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
            conveyor.enable_or_disable_color_sensor();
        }
        bool buttonB = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B);
        // Move the chassis with arcade drive
        chassis.arcade(leftY, rightX);
        // Control subsystems based on button inputs
        //arm.control(buttonR2, buttonY, buttonRight, buttonUp);
        conveyor.control(buttonL1, buttonL2, buttonDown, buttonB);
        holder.control(buttonR1);
        doinker.control(buttonLeft);
        hanger.control(buttonDown);
        intake_raiser.control(buttonA);
        // Delay to save resources
        pros::delay(10);
    }
}