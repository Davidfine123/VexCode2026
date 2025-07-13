#pragma once
#include "components.hpp"

void red_alliance_ladder() {
    // pros::delay(1000);

    conveyor.setInitColor(ConveyorNamespace::Color::RED);

    chassis.setPose(-61, -13.5, 0);

    chassis.turnToHeading(-29.3, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    arm.moveToState(ArmNamespace::State::UP, 1000);

    pros::delay(800);

    arm.moveToState(ArmNamespace::State::DOWN, 1000);

    chassis.moveToPoint(-24, -26, 1500, {.forwards = false, .maxSpeed = 70}, false);
    chassis.waitUntilDone();

    holder.moveToState(HolderNamespace::State::HOLD);

    pros::delay(200);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.turnToPoint(-24, -48, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    chassis.moveDistance(18, 1000);
    chassis.waitUntilDone();

    pros::delay(300);

    chassis.turnToHeading(60, 2000, {.maxSpeed = 80});
    holder.moveToState(HolderNamespace::State::RELEASE);
    chassis.moveDistance(-30, 1000, {.forwards = false, .maxSpeed = 100}, false);
    chassis.turnToHeading(90, 1000);

    chassis.moveToPoint(-18, -18, 2000, {.maxSpeed = 80});
}