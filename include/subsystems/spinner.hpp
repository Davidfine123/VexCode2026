#pragma once
#include "subsystem.hpp"
#include "pros/motors.hpp"

namespace SpinnerNamespace {

enum class State {  IDLE, FORWARD, BACKWARD };

class Spinner : public subsystem<State> {
    public:
        explicit Spinner(std::shared_ptr<pros::Motor> motor)
            : motor_(std::move(motor)) {
            motor_->set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
            motor_->tare_position();
        }

        virtual ~Spinner() override = default; // Virtual destructor for safe inheritance

        void stuckDetected() {
            if (fabs(motor_->get_actual_velocity()) < STUCK_RPM && motor_->get_current_draw() > STUCK_CURRENT && motor_->get_torque() > STUCK_TORQUE) {
                stucked_ = true;
            }
        }
        bool getStucked() const {
            return stucked_;
        }

        double get_speed() { // rpm
            return motor_->get_actual_velocity();
        }
        double get_current() { // mA
            return motor_->get_current_draw();
        }
        void set_speed(double speed) {
            motor_->move(speed * 1.27);
        }
        void reverseSpinnerWhenStuck() {
            stuckDetected();
            if (stucked_) {
                int sign = motor_->get_actual_velocity() > 0 ? 1 : -1;
                motor_-> move_velocity(-sign * 127);
                pros::delay(100);
                motor_->move_velocity(0);
                stucked_ = false;
            }
        }

        // Get motor object
        std::shared_ptr<pros::Motor> getMotor() { return motor_; }
    protected:
        std::shared_ptr<pros::Motor> motor_; // Encapsulate member variable
        bool stucked_ = false; // Flag to indicate if the spinner is stuck

        // Task to control the arm's movement
        void runTask() override final {
            //reverseSpinnerWhenStuck();
            switch (currState) {
                case State::FORWARD: motor_->move(127); break;
                case State::BACKWARD: motor_->move(-127); break;
                case State::IDLE: motor_->move(0); break;
            }
        }
};

} // namespace SpinnerNamespace
