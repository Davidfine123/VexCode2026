#pragma once
#include "components.hpp"

void signature_skills() {
    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    chassis.setPose(-61.5, 0, 90);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 500);

    pros::delay(400);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 1500);

    chassis.moveToPoint(-48, 0, 800, {.maxSpeed = 90}, false);

    chassis.turnToHeading(0, 900, {.maxSpeed = 90}, false);

    chassis.moveToPoint(-48, -24, 900, {.forwards = false, .maxSpeed = 90});
    holder.moveToState(HolderNamespace::State::HOLD);
    pros::delay(400);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.moveToPoint(-26, -24, 900, {.maxSpeed = 115}, false);

    // chassis.turnToHeading(125, 500, {}, false);
    // chassis.moveDistance(30, 1000, {}, false);

    // chassis.turnToHeading(95, 500, {}, false);
    // chassis.moveToPoint(24, -48, 1000, {}, false);

    // chassis.turnToPoint(24, -48, 600, {}, false);
    // chassis.moveDistance(80, 2000, {}, false);
    chassis.moveToPose(0, -42, 135, 950, {.maxSpeed = 120}, false);
    chassis.moveToPose(24, -48, 105, 950, {.maxSpeed = 120}, false);
    pros::delay(300);

    chassis.moveToPoint(0, -36, 900, {.forwards = false, .maxSpeed = 90}, false);

    chassis.turnToHeading(180, 700, {.maxSpeed = 127}, false);

    arm.moveToState(ArmNamespace::State::WAIT);
    chassis.moveDistance(17, 750, {.maxSpeed = 85}, false);

    pros::delay(800);
    conveyor.moveToState(ConveyorNamespace::State::STOP);

    arm.moveToState(ArmNamespace::State::UP);
    pros::delay(700);

    arm.moveToState(ArmNamespace::State::DOWN);
    chassis.moveDistance(14, 900, {.forwards = false, .maxSpeed = 90}, false);

    // wall stake; end section 1
    // section 2:

    chassis.turnToPoint(-24, -48, 700, {.maxSpeed = 127}, false);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    chassis.moveToPoint(-24, -48, 800, {.maxSpeed = 127}, false);

    chassis.turnToHeading(-90, 700, {.maxSpeed = 127}, false);

    chassis.moveDistance(36, 800, {.maxSpeed = 127}, false);

    chassis.turnToHeading(135, 600, {.maxSpeed = 127}, false);

    chassis.moveDistance(17, 750, {.maxSpeed = 75}, false);
    pros::delay(650);

    chassis.moveDistance(-15, 800, {.forwards = false, .maxSpeed = 75}, false);

    holder.moveToState(HolderNamespace::State::RELEASE);

    conveyor.moveToState(ConveyorNamespace::State::STOP);

    // mobile goal drop 1

    chassis.turnToPoint(48, -48, 800, {.maxSpeed = 127}, false);
    chassis.moveToPoint(48, -48, 2000, {.maxSpeed = 127}, false);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 400);

    chassis.turnToHeading(-140, 800, {.maxSpeed = 127}, false);
    chassis.moveToPoint(60, -24, 800, {.forwards = false, .maxSpeed = 127}, false);

    chassis.turnToHeading(165, 900, {.maxSpeed = 127}, false);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 600);
    chassis.moveDistance(35, 600, {.forwards = false, .maxSpeed = 127});

    doinker.moveToState(HolderNamespace::State::HOLD);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 400);
    chassis.turnToHeading(-15, 1000, {.maxSpeed = 127}, false);

    chassis.moveToPose(48, 0, 0, 1500, {.forwards = false, .maxSpeed = 127}, false);
    chassis.moveDistance(-12, 500, {.forwards = false, .maxSpeed = 127}, false);

    chassis.moveDistance(12, 500, {.maxSpeed = 127}, false);

    chassis.turnToHeading(-90, 600, {.maxSpeed = 127}, false);
    chassis.moveDistance(-22, 700, {.forwards = false, .maxSpeed = 127}, false);

    conveyor.disable_color_sensor();

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    pros::delay(600);

    // Alliance stake blue ^

    chassis.moveDistance(22, 700, {.maxSpeed = 127}, false);

    chassis.turnToHeading(180, 600, {.maxSpeed = 127}, false);
    chassis.moveToPoint(48, 24, 1000, {.maxSpeed = 127}, false);

    holder.moveToState(HolderNamespace::State::HOLD);
    chassis.moveToPose(24, -24, -135, 1000, {.maxSpeed = 127}, false);

    chassis.turnToHeading(-45, 1000, {.maxSpeed = 127}, false);
    chassis.moveDistance(100, 2000, {.maxSpeed = 110}, false);

    chassis.turnToHeading(-90, 600, {.maxSpeed = 127}, false);
    chassis.moveDistance(12, 600, {.maxSpeed = 127}, false);

    chassis.moveToPose(-48, 60, 45, 1000, {.maxSpeed = 80}, false);
    pros::delay(400);

    chassis.turnToHeading(105, 600, {.maxSpeed = 127}, false);
    chassis.moveDistance(-35, 700, {.forwards = false, .maxSpeed = 90}, false);

    holder.moveToState(HolderNamespace::State::RELEASE);

    // Second mobile goal drop

    chassis.turnToPoint(24, 48, 800, {.maxSpeed = 127}, false);
    arm.moveToState(ArmNamespace::State::WAIT);
    chassis.moveToPoint(24, 48, 1000, {.maxSpeed = 127}, false);

    chassis.turnToHeading(45, 700, {.maxSpeed = 127}, false);
    chassis.moveDistance(34, 800, {.maxSpeed = 127}, false);

    holder.moveToState(HolderNamespace::State::HOLD);

    chassis.turnToPoint(0, 36, 700, {.maxSpeed = 127}, false);
    chassis.moveToPoint(0, 36, 800, {.maxSpeed = 127}, false);

    chassis.turnToHeading(0, 700, {.maxSpeed = 127}, false);
    conveyor.moveToState(ConveyorNamespace::State::STOP);

    chassis.moveDistance(30, 800, {.maxSpeed = 127}, false);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 400);

    arm.moveToState(ArmNamespace::State::UP);
    pros::delay(700);

    arm.moveToState(ArmNamespace::State::DOWN);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.moveDistance(-18, 700, {.forwards = false, .maxSpeed = 105}, false);
    chassis.turnToHeading(90, 700, {.maxSpeed = 127}, false);
    chassis.moveDistance(24, 750, {.maxSpeed = 127}, false);

    chassis.turnToHeading(180, 700, {.maxSpeed = 127}, false);
    chassis.moveDistance(24, 700, {.maxSpeed = 127}, false);

    chassis.turnToHeading(45, 600, {.maxSpeed = 127}, false);
    chassis.moveDistance(34, 800, {.maxSpeed = 127}, false);

    chassis.turnToHeading(90, 700, {.maxSpeed = 127}, false);
    chassis.moveDistance(10, 600, {.maxSpeed = 127}, false);

    chassis.moveToPose(48, 60, -45, 800, {}, false);

    chassis.turnToHeading(-135, 600, {}, false);
    chassis.moveDistance(-21, 600, {.forwards = false, .maxSpeed = 80}, false);

    // arm.moveToState(ArmNamespace::State::UP);

    // chassis.moveToPoint(0, 0, 3000, {.forwards = false, .maxSpeed = 70, .earlyExitRange = 50}, false);
    // leftMotors.move(-50);
    // rightMotors.move(-50);
}