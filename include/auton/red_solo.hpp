#pragma once
#include "components.hpp"

void red_solo() {
    arm.resetRotation(3500.0f);
    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    chassis.setPose(-51.25, 11, 238);
    
    chassis.moveDistance(5, 350, {.maxSpeed = 127}, true);
    arm.moveToState(ArmNamespace::State::UP);
    chassis.waitUntilDone();


    chassis.moveToPoint(-37.5, 17.5, 600, {.forwards = false, .maxSpeed = 127}, false);
    chassis.moveToPoint(-24, 24, 1100, {.forwards = false, .maxSpeed = 65}, true);
    arm.moveToState(ArmNamespace::State::DOWN);
    chassis.waitUntil(13);
    holder.moveToState(HolderNamespace::State::HOLD);

    
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    chassis.turnToHeading(26, 750, {.maxSpeed = 127}, false); 
    chassis.waitUntilDone();
 
    chassis.moveDistance(20, 750, {.maxSpeed = 127}, false);
    chassis.moveToPoint(-26, 24, 800, {.forwards = false, .maxSpeed = 100}, false);
    chassis.turnToHeading(0, 500, {.maxSpeed = 127}, false);
    chassis.moveDistance(20, 650, {.maxSpeed = 127}, false);
    chassis.correctAt0({"front"});

    chassis.moveToPoint(-48, 24,1000, {.maxSpeed = 127}, false);
    chassis.turnToHeading(180, 675, {.maxSpeed = 127}, false);
    chassis.correctAt180({"right"});

    chassis.moveToPoint(-48, 0, 1000, {.maxSpeed = 100}, false);
    chassis.moveDistance(30, 1000, {.maxSpeed = 90}, false);
    chassis.waitUntil(24);
    conveyor.moveToState(ConveyorNamespace::State::STOP);
    holder.moveToState(HolderNamespace::State::RELEASE);

    chassis.turnToPoint(-24, -24, 600, {.forwards = false, .maxSpeed = 127},false);
    chassis.moveToPoint(-24, -24, 1200, {.forwards = false, .maxSpeed = 65},false);
    chassis.waitUntil(15);
    holder.moveToState(HolderNamespace::State::HOLD);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.turnToHeading(180, 675, {.maxSpeed = 127}, false);
    chassis.moveDistance(20, 750, {.maxSpeed = 127}, false);
    chassis.moveToPoint(-18, 8, 1000, {.maxSpeed = 127}, false);

}