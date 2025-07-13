#pragma once
#include "components.hpp"

void blue_left_solo() {
    conveyor.setInitColor(ConveyorNamespace::Color::BLUE);
    chassis.setPose(61, -13.5, 0);

    chassis.turnToHeading(29.3, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    arm.moveToState(ArmNamespace::State::UP, 1000);

    pros::delay(800);

    arm.moveToState(ArmNamespace::State::DOWN, 1000);

    chassis.moveToPoint(30, -24, 2000, {.forwards = false, .maxSpeed = 70}, false);
    chassis.waitUntilDone();

    holder.moveToState(HolderNamespace::State::HOLD);

    chassis.moveToPoint(24, -48, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.turnToHeading(140, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    chassis.moveToPoint(68, -68, 2000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    pros::delay(800);

    holder.moveToState(HolderNamespace::State::RELEASE);

    conveyor.moveToState(ConveyorNamespace::State::STOP);

    chassis.turnToHeading(150, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();
    
    chassis.moveToPoint(24, 24, 3000, {.forwards = false, .maxSpeed = 110}, false);
    chassis.waitUntilDone();

    holder.moveToState(HolderNamespace::State::HOLD);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.moveToPoint(24, 48, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();
}