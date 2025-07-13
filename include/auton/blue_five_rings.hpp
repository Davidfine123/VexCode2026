#pragma once
#include "components.hpp"

void blue_five_rings() {
    conveyor.setInitColor(ConveyorNamespace::Color::BLUE);

    chassis.setPose(55.5, 24, 90);

    chassis.moveToPoint(28, 24, 2000, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntil(25);

    holder.moveToState(HolderNamespace::State::HOLD);

    pros::delay(300);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.turnToHeading(-45, 1000, {.maxSpeed = 70}, false);
    // chassis.waitUntilDone();

    chassis.moveDistance(18, 1000, {.maxSpeed = 70}, false);
    // chassis.waitUntilDone();

    chassis.turnToHeading(-10, 1000, {.maxSpeed = 70}, false);
    // chassis.waitUntilDone();

    chassis.moveDistance(15, 1000, {.maxSpeed = 70}, false);
    // chassis.waitUntilDone();

    // pros::delay(300);

    chassis.turnToHeading(0, 800);
    chassis.moveDistance(-26, 1000, {.forwards = false}, false);

    // chassis.moveToPoint(22, 24, 1000, {.forwards = false, .maxSpeed = 70}, false);
    // chassis.waitUntilDone();

    chassis.turnToHeading(25, 1000);
    // chassis.waitUntilDone();

    chassis.moveDistance(18, 1000, {.maxSpeed = 127}, false);
    // chassis.waitUntilDone();

    chassis.turnToHeading(65, 1000, {.maxSpeed = 70}, false);
    // chassis.waitUntilDone();

    doinker.moveToState(HolderNamespace::State::HOLD);

    chassis.moveDistance(39, 2000, {.maxSpeed = 80}, false);
    // chassis.waitUntilDone();

    chassis.turnToHeading(-40, 1000, {.maxSpeed = 100}, false);
    chassis.waitUntilDone();

    // chassis.moveToPoint(56, 20, 2000, {.maxSpeed = 100}, false);
    // chassis.waitUntilDone();
    
    chassis.moveDistance(12, 2000);

    pros::delay(1500);

    // conveyor.moveToState(ConveyorNamespace::State::REVERSE);

    chassis.turnToHeading(180, 1000);

    // doinker.moveToState(HolderNamespace::State::RELEASE);
}
