#pragma once
#include "components.hpp"

void red_right_wp() {
    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    chassis.setPose(-55, -15, 180);

    chassis.moveDistance(-16, 1000, {.forwards = false, .maxSpeed = 70}, false);
    chassis.waitUntilDone();

    chassis.turnToHeading(90, 1000, {.maxSpeed = 50}, false);
    chassis.waitUntilDone();

    chassis.moveDistance(-5, 2000, {.forwards = false, .maxSpeed = 50}, false);
    chassis.waitUntilDone();

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    pros::delay(300);

    chassis.moveToPoint(-48, 0, 1000, {.forwards = true, .maxSpeed = 80}, false);
    chassis.waitUntilDone();

    chassis.turnToPoint(-24, -21, 1000, {.forwards = false, .maxSpeed = 100}, false);
    chassis.waitUntilDone();

    chassis.moveToPoint(-24, -21, 1000, {.forwards = false, .maxSpeed = 75}, false);
    chassis.waitUntil(20);

    holder.moveToState(HolderNamespace::State::HOLD);

    chassis.turnToHeading(180, 1000, {.maxSpeed = 80}, false);
    chassis.waitUntilDone();

    chassis.moveDistance(14, 1000, {.maxSpeed = 80}, false);
    chassis.waitUntilDone();

    chassis.turnToHeading(-115, 1000, {.maxSpeed = 80}, false);
    chassis.waitUntilDone();

    doinker.moveToState(HolderNamespace::State::HOLD);

    chassis.moveDistance(35, 2000, {.maxSpeed = 80}, false);
    chassis.waitUntilDone();

    chassis.turnToHeading(180, 1000, {.maxSpeed = 100}, false);
    chassis.waitUntilDone();

    chassis.moveToPoint(-20, -20, 2000, {.maxSpeed = 100}, false);
    chassis.waitUntilDone();

    conveyor.moveToState(ConveyorNamespace::State::STOP);
    doinker.moveToState(HolderNamespace::State::RELEASE);
}