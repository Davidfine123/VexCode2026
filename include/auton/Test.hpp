#pragma once
#include "components.hpp"

void Test() {
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    pros::delay(50000);

    arm.resetRotation(2100.0f);
    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    chassis.setPose(-60, 15, 211);
    arm.moveToState(ArmNamespace::State::AUTO_UP);
    pros::delay(300);
    
    chassis.moveForward(-5, 400, {.forwards = false, .maxSpeed = 127}, true);
    chassis.waitUntil(4);
    arm.moveToState(ArmNamespace::State::DOWN);
    chassis.waitUntilDone();
    chassis.turnToPoint(-24, 24, 700, {.forwards = false, .maxSpeed = 127}, false);
    chassis.moveForward(-15, 500, {.forwards = false, .maxSpeed = 127}, false);
    chassis.moveToPoint(-24, 24, 600, {.forwards = false, .maxSpeed = 80}, true);
    chassis.waitUntil(10); 
    holder.moveToState(HolderNamespace::State::HOLD);
    chassis.waitUntilDone();
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    chassis.turnToPoint(-10, 39, 800, {.maxSpeed = 127}, false);
    chassis.moveToPoint(-10, 39, 800, {.maxSpeed = 127}, false);
    chassis.moveDistance(-11, 500, {.forwards = false, .maxSpeed = 127}, false);
    chassis.turnToHeading(0, 600, {.maxSpeed = 127}, false);
    chassis.moveToPoint(-24, 44, 600, {.maxSpeed = 127}, false);
    chassisSmall.turnToPoint(-3.5, 55, 700, {.maxSpeed =127}, false);
    //chassis.correctAt90({"left"});

    chassis.moveToPoint(-9, 52, 800, {.maxSpeed = 127}, false);
    chassis.moveToPoint(-46, 53, 1000, {.forwards = false, .maxSpeed = 127}, false);
    chassis.turnToHeading(315, 700, {.maxSpeed = 127}, false);
    chassis.waitUntilDone();

    
    chassis.moveDistance(40, 800, {.maxSpeed = 127}, true);
    chassis.waitUntilDone();

    chassis.moveDistance(-18, 500, {.forwards = false, .maxSpeed = 127}, false);
    
    chassis.waitUntilDone();
    chassis.moveDistance(13, 500, {.minSpeed = 127}, false);
    chassis.waitUntilDone();
    
  
    chassis.moveToPoint(-48, 54, 600, {.forwards = false, .maxSpeed = 127}, false);
    chassis.turnToHeading(180, 300, {.maxSpeed = 127}, false);
    chassis.moveToPoint(-48, 0, 1200, {.maxSpeed = 127}, true);
    chassis.waitUntil(20);
    intake_raiser.moveToState(HolderNamespace::State::HOLD);
    arm.moveToState(ArmNamespace::State::DISCORE_UP);
    chassis.waitUntilDone();
    intake_raiser.moveToState(HolderNamespace::State::RELEASE);
    chassis.moveDistance(-5, 500, {.forwards = false, .maxSpeed = 127}, true);
    chassis.waitUntil(3);
    chassis.moveToPoint(-24, 0, 800, {.minSpeed = 80}, false);;


    
}
