#pragma once
#include "components.hpp"

void red_right_three_rings() {
    chassis.setPose(-55.5, -16.5, 0);

    doinker.moveToState(HolderNamespace::State::HOLD);
    chassis.moveToPoint(-55.5, 24, 2000, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();

    chassis.turnToPoint(-24, -24, 2000, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();

    chassis.moveToPoint(-24, -24, 2000, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntil(25);

    holder.moveToState(HolderNamespace::State::HOLD);

    pros::delay(300);

    chassis.turnToHeading(180, 1000);
    chassis.waitUntilDone();

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.moveDistance(24, 2000, {.maxSpeed = 80});
    chassis.waitUntilDone();

    pros::delay(300);

    chassis.moveToPoint(-18, -18, 2000, {.maxSpeed = 80});
}
