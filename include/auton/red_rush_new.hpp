#pragma once
#include "components.hpp"

void red_rush_new() {
    conveyor.setInitColor(ConveyorNamespace::Color::RED);

    chassis.setPose(-50.5, -60, 73.5);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 1500);
    chassis.moveDistance(30, 1000, {.minSpeed = 127}, false);

    doinker.moveToState(HolderNamespace::State::HOLD);

    chassis.moveDistance(4, 1000, {.minSpeed = 127}, false);

    chassis.moveDistance(-4, 1000,{.forwards = false, .minSpeed = 127}, false);

    chassis.turnToHeading(180, 1000, {.maxSpeed = 70}, false);

    // chassis.correctByDistanceSensors();
   

    

    // chassis.moveToPoint(-30,-52, 1000,{.forwards = false, .minSpeed = 127}, false);

    doinker.moveToState(HolderNamespace::State::RELEASE);
    pros::delay(500);

    chassis.moveDistance(-5,1000,{.forwards = false, .maxSpeed = 100}, false);

    // chassis.correctByDistanceSensors();

    chassis.turnToHeading(0, 2000, {.maxSpeed = 70}, false);

    chassis.moveDistance(-10, 1500, {.forwards = false, .maxSpeed = 50}, false); 

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 1000);

}




    