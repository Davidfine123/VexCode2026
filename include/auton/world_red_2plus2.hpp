#pragma once
#include "components.hpp"

void world_red_2p2() {
    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    chassis.setPose(-51.5, -35, 121);

    //chassis.turnToPoint(-24, -48, 200, {.maxSpeed = 90}, false);
    conveyor.moveToState(ConveyorNamespace::State::INTAKE_FORWARD,1000);
    chassis.moveToPoint(-24, -48, 1000, {.maxSpeed = 65}, false);
    chassis.waitUntilDone();
    chassis.turnToPoint(-10 ,-48, 800, {.forwards = false, .maxSpeed = 65}, false);
    chassis.waitUntilDone();
    chassis.moveToPoint(-10, -48, 1000, {.forwards = false, .maxSpeed = 50}, true);
    chassis.waitUntil(8);
    holder.moveToState(HolderNamespace::State::HOLD);
    pros::delay(100);
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.waitUntilDone();
    chassis.moveToPoint(-24, -48, 800, {.forwards = true, .maxSpeed = 110}, true);
    chassis.waitUntil(8);
    holder.moveToState(HolderNamespace::State::RELEASE);
    chassis.turnToPoint(-24, -24, 800, {.forwards = false, .maxSpeed = 80}, false);
    chassis.moveToPoint(-24, -24, 1100, {.forwards = false, .maxSpeed = 60}, true);
    chassis.waitUntil(24);
    holder.moveToState(HolderNamespace::State::HOLD);
    chassis.waitUntilDone();
    chassis.turnToPoint(-54, -54, 500, {.maxSpeed = 127}, false);
    chassis.moveToPoint(-54,-54,800,{.maxSpeed = 127},false);

    chassis.turnToPoint(-65, -65, 500, {.maxSpeed = 127}, false);
    chassis.moveToPoint(-72,-72,1000,{.maxSpeed = 75},false);

    
    
    chassis.moveDistance(-15, 800, {.forwards = false, .maxSpeed = 127}, true);
    chassis.waitUntil(12);

    chassis.moveDistance(8, 600, {.maxSpeed = 75}, false);
    pros::delay(300);
    chassis.waitUntilDone();
    chassis.moveToPoint(-72,-72,500,{.maxSpeed = 75},false);

    chassis.moveDistance(-10, 500, {.forwards = false, .maxSpeed = 127}, false);

    chassis.moveDistance(30, 900, {.maxSpeed = 127}, false);
    
    conveyor.moveToState(ConveyorNamespace::State::STOP);

    chassis.waitUntilDone();
    chassis.turnToPoint(-24,-52,600,{.maxSpeed = 127},false);



    

    chassis.moveToPoint(-35,-56,600,{.maxSpeed = 115},false);

}
