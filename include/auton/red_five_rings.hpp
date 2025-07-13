#pragma once
#include "components.hpp"

void red_five_rings() {
    conveyor.setInitColor(ConveyorNamespace::Color::RED);

    chassis.setPose(-55.5, 24, -90);

    chassis.moveToPoint(-26, 24, 2000, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntil(25);

    holder.moveToState(HolderNamespace::State::HOLD);

    pros::delay(300);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.turnToHeading(45, 1000, {.maxSpeed = 70}, false);
    // chassis.waitUntilDone();

    chassis.moveDistance(18, 1000, {.maxSpeed = 70}, false);
    // chassis.waitUntilDone();

    chassis.turnToHeading(10, 1000, {.maxSpeed = 70}, false);
    // chassis.waitUntilDone();

    chassis.moveDistance(15, 1000, {.maxSpeed = 70}, false);
    // chassis.waitUntilDone();

    pros::delay(300);

    chassis.moveToPoint(-24, 24, 1000, {.forwards = false, .maxSpeed = 70}, false);
    // chassis.waitUntilDone();

    chassis.turnToHeading(0, 1000);
    // chassis.waitUntilDone();

    chassis.moveDistance(15, 1000, {.maxSpeed = 70}, false);
    // chassis.waitUntilDone();

    chassis.turnToHeading(-55, 1000, {.maxSpeed = 70}, false);
    // chassis.waitUntilDone();

    doinker.moveToState(HolderNamespace::State::HOLD);

    chassis.moveDistance(38, 2000, {.maxSpeed = 80}, false);
    // chassis.waitUntilDone();

    chassis.turnToHeading(-165, 1000, {.maxSpeed = 100}, false);
    // chassis.waitUntilDone();

    // chassis.moveToPoint(-56, 30, 2000, {.maxSpeed = 100}, false);
    // chassis.waitUntilDone();

    chassis.moveDistance(12, 2000);

    pros::delay(1300);

    conveyor.moveToState(ConveyorNamespace::State::REVERSE);

    chassis.moveToPoint(-56, -48, 2000, {}, false);

    // doinker.moveToState(HolderNamespace::State::RELEASE);
}
