#pragma once
#include "components.hpp"

void blue_left_sweep() {
    // pros::delay(1000);

    conveyor.setInitColor(ConveyorNamespace::Color::BLUE);

    chassis.setPose(61, -13.5, 0);

    chassis.turnToHeading(29.3, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    arm.moveToState(ArmNamespace::State::UP, 1000);

    pros::delay(800);

    arm.moveToState(ArmNamespace::State::DOWN, 1000);

    chassis.moveToPoint(24, -26, 1500, {.forwards = false, .maxSpeed = 70}, false);
    chassis.waitUntilDone();

    holder.moveToState(HolderNamespace::State::HOLD);

    pros::delay(300);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.turnToPoint(24, -48, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    chassis.moveDistance(18, 1000);
    chassis.waitUntilDone();

    pros::delay(500);

    // chassis.moveDistance(-18, 1000, {.forwards = false}, false);
    // chassis.waitUntilDone();

    conveyor.moveToState(ConveyorNamespace::State::STOP);

    // chassis.turnToHeading(-120, 1000, {}, false);
    // chassis.waitUntilDone();

    doinker.moveToState(HolderNamespace::State::HOLD);

    chassis.moveToPoint(58, -61, 1500, {.maxSpeed = 80}, false);
    chassis.waitUntilDone();

    doinker.moveToState(HolderNamespace::State::HOLD);

    chassis.turnToHeading(0, 1000);
    chassis.waitUntilDone();

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    holder.moveToState(HolderNamespace::State::RELEASE);

    chassis.moveToPoint(30, -48, 2000, {}, false);

    chassis.turnToHeading(90, 2000, {}, false);
}