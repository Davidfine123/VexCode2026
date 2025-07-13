#pragma once
#include "components.hpp"

void blue_signature_solo() {
    conveyor.setInitColor(ConveyorNamespace::Color::BLUE);

    chassis.setPose(61, 13.5, -180);

    chassis.turnToHeading(-209.3, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    arm.moveToState(ArmNamespace::State::UP, 1000);

    pros::delay(800);

    arm.moveToState(ArmNamespace::State::DOWN, 1000);

    chassis.moveToPoint(24, 26, 1500, {.forwards = false, .maxSpeed = 70}, false);
    chassis.waitUntilDone();

    holder.moveToState(HolderNamespace::State::HOLD);

    pros::delay(300);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.turnToHeading(-25, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    chassis.moveDistance(12, 1000);
    chassis.waitUntilDone();

    chassis.turnToHeading(-5, 1000);

    chassis.moveDistance(9, 1000);

    chassis.moveToPoint(24, 24, 1600, {.forwards = false, .maxSpeed = 70}, false);

    chassis.turnToHeading(0, 1000);

    chassis.moveDistance(24, 1000, {.maxSpeed = 80}, false);

    doinker.moveToState(HolderNamespace::State::HOLD);

    // add second mobile goal below



    arm.moveToState(ArmNamespace::State::UP);
    // hang
    chassis.moveToPoint(35, 16, 2000, {.maxSpeed = 100}, false);
    chassis.turnToHeading(-90, 2000, {.maxSpeed = 30}, false);
}
