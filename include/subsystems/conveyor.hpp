#pragma once

#include "lemlib/timer.hpp"
#include "subsystem.hpp"
#include "spinner.hpp"
#include <cmath>
#include "pros/optical.hpp"

namespace ConveyorNamespace {

enum class State { STOP, Intake, LowGoal, MiddleGoal, HighGoal };

enum Color { RED = 0, BLUE = 1 };

class Conveyor : public subsystem<ConveyorNamespace::State> {
    public:
        Conveyor(SpinnerNamespace::Spinner* bottomRoller, SpinnerNamespace::Spinner* insideRoller, SpinnerNamespace::Spinner* scoreRoller,
                 std::shared_ptr<pros::Optical> optical_sensor, std::shared_ptr<pros::Distance> distance)
            : bottomRoller_(std::move(bottomRoller)),
              insideRoller_(std::move(insideRoller)),
              scoreRoller_(std::move(scoreRoller)),
              optical_sensor_(std::move(optical_sensor)),
              distance_(std::move(distance)) {
            //insideRoller_->getMotor()->set_brake_mode(pros::MotorBrake::brake);
        }

        ~Conveyor() override = default;

        void setInitColor(const Color color) { init_color_ = color; }

        // Control conveyor direction based on buttons
        void control(bool button_intake, bool button_low_goal, bool button_middle_goal, bool button_high_goal,
                     bool button_intake_forward, bool button_intake_reverse) {

            if (button_intake)  {
                currState = ConveyorNamespace::State::Intake;
            } else if (button_low_goal) {
                currState = ConveyorNamespace::State::LowGoal;
            } else if (button_intake_forward) {
                currState = ConveyorNamespace::State::MiddleGoal;
            } else if (button_intake_reverse) {
                currState = ConveyorNamespace::State::HighGoal;
            } else {
                currState = ConveyorNamespace::State::STOP;
            }
            moveToState(currState);
        }


        // Check if a wrong ring is detected based on hue
        bool detectWrongRing() {
            // Check if a hue value can be read otherwise do not use
            if (optical_sensor_ != nullptr and optical_sensor_->get_hue() != PROS_ERR_F) {
                switch (this->init_color_) {
                    case RED:
                        if (optical_sensor_->get_hue() > BLUE_THRESHOLD and optical_sensor_->get_hue() < BLUE_HIGH_THRESHOLD)
                            return true;
                        return false;
                    case BLUE:
                        if (optical_sensor_->get_hue() < RED_THRESHOLD or optical_sensor_->get_hue() > RED_HIGH_THRESHOLD)
                            return true;
                        return false;
                }
            }
            return false;
        }

        // Get the initial wrong hue value
        Color getInitColor() const { return init_color_; }

        SpinnerNamespace::Spinner* getIntake() { return intake_; }

        SpinnerNamespace::Spinner* getHooks() { return hooks_; }

        // Get the optical sensor object
        std::shared_ptr<pros::Optical> getOpticalSensor() { return optical_sensor_; }

        // Enable or disable color sensor
        void enable_or_disable_color_sensor() { enable_color_sensor_ = !enable_color_sensor_; }

        // Disable color sensor
        void disable_color_sensor() { enable_color_sensor_ = false; }

        // Enable color sensor
        void enable_color_sensor() { enable_color_sensor_ = true; }

        bool is_reversed() { return reverse_; }

        // Helper function to move the conveyor
        // void moveConveyor(SpinnerNamespace::State state) {
        //     if (reverse_ and distance_ != nullptr and distance_->get_distance() < DIST_THRESHOLD and
        //         state == SpinnerNamespace::State::FORWARD) {
        //         intake_->moveToState(SpinnerNamespace::State::BACKWARD, 300);
        //         hooks_->moveToState(SpinnerNamespace::State::BACKWARD, 300);
        //         reverse_ = false;
        //         return;
        //     }

        //     intake_->moveToState(state); // Move forward normally
        //     hooks_->moveToState(state); // Move forward normally
        // }
    private:
        SpinnerNamespace::Spinner* intake_;
        SpinnerNamespace::Spinner* hooks_;
        std::shared_ptr<pros::Optical> optical_sensor_ = nullptr;
        std::shared_ptr<pros::Distance> distance_ = nullptr;
        Color init_color_;
        bool enable_color_sensor_ = true;
        bool reverse_ = false;

        // Task that runs based on the current state
        void runTask() override final {

            if (timer.isDone() && timer.getTimeSet() > 0) {
                moveToState(ConveyorNamespace::State::STOP);
                timer.set(0);
            }
            if (currState == ConveyorNamespace::State::FORWARDS) {
                if (enable_color_sensor_ && detectWrongRing()) reverse_ = true;
                if (reverse_ && distance_ != nullptr && distance_->get_distance() < DIST_THRESHOLD) {
                    intake_->moveToState(SpinnerNamespace::State::FORWARD);
                    hooks_->moveToState(SpinnerNamespace::State::FORWARD);
                    pros::delay(170);

                    intake_->moveToState(SpinnerNamespace::State::BACKWARD);
                    hooks_->moveToState(SpinnerNamespace::State::BACKWARD);
                    pros::delay(300);
                    reverse_ = false;
                }
                intake_->moveToState(SpinnerNamespace::State::FORWARD);
                hooks_->moveToState(SpinnerNamespace::State::FORWARD);
            }
            if (currState == ConveyorNamespace::State::REVERSE) {
                intake_->moveToState(SpinnerNamespace::State::BACKWARD);
                hooks_->moveToState(SpinnerNamespace::State::BACKWARD);               
            }
            if (currState == ConveyorNamespace::State::INTAKE_FORWARD) {
                intake_->moveToState(SpinnerNamespace::State::FORWARD);
                hooks_->moveToState(SpinnerNamespace::State::IDLE);
            }
            if (currState == ConveyorNamespace::State::INTAKE_REVERSE) {
                intake_->moveToState(SpinnerNamespace::State::BACKWARD);
                hooks_->moveToState(SpinnerNamespace::State::IDLE);
            }
            if (currState == ConveyorNamespace::State::STOP) {
                intake_->moveToState(SpinnerNamespace::State::IDLE);
                hooks_->moveToState(SpinnerNamespace::State::IDLE);
            }
            // if (enable_color_sensor_ and detectWrongRing()) reverse_ = true;

            // // Handle timed states
            // if (timer.isDone() and timer.getTimeSet() > 0) {
            //     moveToState(ConveyorNamespace::State::STOP);
            //     timer.set(0);
            // }

            // switch (currState) {
            //     case ConveyorNamespace::State::FORWARDS: moveConveyor(SpinnerNamespace::State::FORWARD); break;
            //     case ConveyorNamespace::State::REVERSE: moveConveyor(SpinnerNamespace::State::BACKWARD); break;
            //     case ConveyorNamespace::State::STOP: moveConveyor(SpinnerNamespace::State::IDLE); break;
            //     case ConveyorNamespace::State::INTAKE_FORWARD:
            //         intake_->moveToState(SpinnerNamespace::State::FORWARD);
            //         hooks_->moveToState(SpinnerNamespace::State::IDLE);
            //         break;
            // }
        }
};
} // namespace ConveyorNamespace