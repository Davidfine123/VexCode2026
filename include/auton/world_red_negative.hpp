#pragma once
#include "components.hpp"

void world_red_negative(){
    arm.resetRotation(2000.0f);
    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    chassis.setPose(-53.775, 10.225, 237.25);
    arm.moveToState(ArmNamespace::State::AUTO_UP);
    chassis.moveForward(3, 300, {.maxSpeed = 127}, true);
    chassis.waitUntil(3);
    chassis.moveForward(16, 550, {.forwards = false, .maxSpeed = 127}, true);
    
    chassis.waitUntil(13);
    arm.moveToState(ArmNamespace::State::DOWN);

    chassis.turnToPoint(-24, 24, 200, {.forwards = false, .maxSpeed = 127}, false);
    chassis.waitUntilDone();
    chassis.moveToPoint(-24, 24, 700, {.forwards = false, .maxSpeed = 70}, true);
    chassis.waitUntil(11);
    holder.moveToState(HolderNamespace::State::HOLD);
    chassis.waitUntilDone();
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    chassisSmall.turnToPoint(-10, 38, 800, {.maxSpeed = 127}, false);
    chassis.moveToPoint(-10, 38, 800, {.maxSpeed = 127}, false);
    chassis.moveDistance(-15, 500, {.forwards = false, .maxSpeed = 127}, false);
    chassis.turnToHeading(0, 600, {.maxSpeed = 127}, false);
    chassis.moveToPoint(-24, 43, 600, {.maxSpeed = 127}, false);
    chassisSmall.turnToPoint(-3.5, 55, 700, {.maxSpeed =127}, false);
    //chassis.correctAt90({"left"});

    chassis.moveToPoint(-10, 52, 800, {.maxSpeed = 127}, false);
    chassis.moveToPoint(-40, 53, 1000, {.forwards = false, .maxSpeed = 127}, false);
    chassisSmall.turnToPoint(-68, 68, 800, {.maxSpeed = 127}, false);

    chassis.waitUntilDone();
    chassis.moveToPoint(-68, 68, 1000, {.maxSpeed = 100}, false);

    chassis.moveDistance(-18, 700, {.forwards = false, .maxSpeed = 127}, false);
    
    chassis.moveToPoint(-58, 58, 500, {.maxSpeed = 90}, false);


    
  
    chassis.moveToPoint(-48, 54, 600, {.forwards = false, .maxSpeed = 127}, false);
    chassis.turnToHeading(180, 300, {.maxSpeed = 127}, false);
    chassis.moveToPoint(-48, 8, 1200, {.maxSpeed = 127}, true);
    chassis.waitUntil(5);
    intake_raiser.moveToState(HolderNamespace::State::HOLD);
    arm.moveToState(ArmNamespace::State::DISCORE_UP);
    chassis.waitUntilDone();
    intake_raiser.moveToState(HolderNamespace::State::RELEASE);
    chassis.moveDistance(-10, 500, {.forwards = false, .maxSpeed = 127}, true);
    chassis.waitUntil(5);
    chassis.moveToPoint(-24, 0, 800, {.minSpeed = 80}, false);
  
 
}
    