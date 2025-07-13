#pragma once
#include "components.hpp"

void blue_six_rings() {
    conveyor.setInitColor(ConveyorNamespace::Color::BLUE);

    chassis.setPose(52, 24, 90);

    chassis.moveDistance(-28, 1200, {.forwards = false, .maxSpeed = 70}, true);

    chassis.waitUntil(24);

    holder.moveToState(HolderNamespace::State::HOLD);
    chassis.waitUntilDone();

    chassis.turnToPoint(4, 40, 900, {.maxSpeed = 127}, false);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    chassis.moveDistance(18, 700, {.maxSpeed = 127}, false);

    chassis.turnToHeading(-16, 500, {.maxSpeed = 100}, false);
    chassis.moveDistance(13, 800, {.maxSpeed = 127}, false);
    


    chassis.moveToPoint(17, 26, 1000, {.forwards = false, .maxSpeed = 100}, false);
    chassis.turnToHeading(-16, 500, {.maxSpeed = 127}, false);
    chassis.moveToPoint(17, 45, 800, {.maxSpeed = 127}, false);
    //chassis.correctAt0({"front"});
    chassis.turnToHeading(65, 800, {.maxSpeed = 127}, false);
    
    chassis.moveDistance(26, 800, {.maxSpeed = 100}, false);




    chassis.turnToHeading(55, 600, {.maxSpeed = 127}, false);
    chassis.moveDistance(40, 1200, {.maxSpeed = 90}, false);
    //chassis.turnToHeading(45, 300, {.maxSpeed = 127}, false);
    chassis.moveDistance(-18, 600, {.forwards = false, .maxSpeed = 127}, false);
    chassis.moveDistance(13, 800, {.maxSpeed = 127}, false);
    pros::delay(200);
    intake_raiser.moveToState(HolderNamespace::State::HOLD);
    chassis.moveToPose(55, 7, 180, 2000, {.minSpeed = 127}, false);
    intake_raiser.moveToState(HolderNamespace::State::RELEASE);

    chassis.turnToHeading(-15, 1000, {.maxSpeed = 80}, false);
    chassis.waitUntilDone();
    chassis.moveDistance(-35, 1200, {.forwards = false, .minSpeed = 127}, false);
    
    holder.moveToState(HolderNamespace::State::RELEASE);

    //intake_raiser.moveToState(HolderNamespace::State::RELEASE);
    
    //intake_raiser.moveToState(HolderNamespace::State::HOLD);
}
