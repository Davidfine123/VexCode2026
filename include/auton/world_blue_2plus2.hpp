#pragma once
#include "components.hpp"

void world_blue_2p2() {
    chassis.setPose(55.5, -24, 90);

    chassis.moveToPoint(24, -24, 2000, {.forwards = false, .maxSpeed = 60});
    chassis.waitUntil(25);

    holder.moveToState(HolderNamespace::State::HOLD);

    pros::delay(300);

    chassis.turnToHeading(180, 1000);
    chassis.waitUntilDone();

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.moveDistance(24, 2000, {.maxSpeed = 100});
    chassis.waitUntilDone();

    // chassis.moveDistance(18, 1000);
    // chassis.waitUntilDone();

    pros::delay(700);

    // chassis.moveDistance(-18, 1000, {.forwards = false}, false);
    // chassis.waitUntilDone();

    conveyor.moveToState(ConveyorNamespace::State::STOP);

    // chassis.turnToHeading(-120, 1000, {}, false);
    // chassis.waitUntilDone();

    chassis.turnToPoint(58, -61, 1000);

    doinker.moveToState(HolderNamespace::State::HOLD);
    chassis.moveToPoint(58, -61, 1500, {.maxSpeed = 80}, false);
    chassis.waitUntilDone();

    holder.moveToState(HolderNamespace::State::RELEASE);

    chassis.turnToHeading(0, 1000);
    chassis.waitUntilDone();

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.moveToPoint(30, -48, 2000, {}, false);

    doinker.moveToState(HolderNamespace::State::RELEASE);

    chassis.turnToPoint(0, -48, 1000);
    chassis.moveDistance(15, 1000);
    chassis.turnToHeading(60, 1000);
}
