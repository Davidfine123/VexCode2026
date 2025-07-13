#pragma once
#include "components.hpp"

void left_two_rings() {
    chassis.setPose(55.5, -24, 90);

    chassis.moveToPoint(24, -24, 2000, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntil(25);

    holder.moveToState(HolderNamespace::State::HOLD);

    pros::delay(300);

    chassis.turnToHeading(180, 1000);
    chassis.waitUntilDone();

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.moveDistance(24, 2000, {.maxSpeed = 100});
    chassis.waitUntilDone();

    pros::delay(300);
    chassis.turnToHeading(-60,1000);
    holder.moveToState(HolderNamespace::State::RELEASE);
    chassis.moveDistance(-30, 1000, {.forwards = false, .maxSpeed = 100}, false);
    chassis.turnToHeading(270, 1000);

    chassis.moveDistance(-30, 2000, {.forwards = false, .maxSpeed = 70}, false);

    


    // chassis.moveToPoint(18, -18, 2000, {.maxSpeed = 80});
}

void blue_left_two_rings() {
    conveyor.setInitColor(ConveyorNamespace::Color::BLUE);
    left_two_rings();
}

void red_left_two_rings() {
    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    left_two_rings();
}

void no_color_left_two_rings() {
    conveyor.disable_color_sensor();
    left_two_rings();
}