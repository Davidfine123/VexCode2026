#pragma once
#include "components.hpp"

void blue_rush_mobile() {
    conveyor.setInitColor(ConveyorNamespace::Color::BLUE);

    chassis.setPose(56.5, -31, -90);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 1200);

    chassis.moveToPoint(24, -48, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    chassis.turnToHeading(-270, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    chassis.moveDistance(-12, 1000, {.forwards = false, .maxSpeed = 50}, false);
    chassis.waitUntilDone();

    holder.moveToState(HolderNamespace::State::HOLD);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.moveToPoint(36, -48, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    chassis.turnToHeading(-90, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    holder.moveToState(HolderNamespace::State::RELEASE);
    chassis.moveDistance(-10, 1000, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();

    chassis.moveDistance(5, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    chassis.turnToPoint(24, -24, 1000, {.forwards = false, .maxSpeed = 70}, false);
    chassis.waitUntilDone();

    chassis.moveToPoint(24, -24, 1000, {.forwards = false, .maxSpeed = 70}, false);
    holder.moveToState(HolderNamespace::State::HOLD);
    chassis.waitUntilDone();

    chassis.turnToPoint(48, -20, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    chassis.moveToPoint(52, -20, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    chassis.moveToPose(13, -17.5, 0, 3000, {.maxSpeed = 70}, false);

    
}