#pragma once
#include "components.hpp"

    void red_six_rings() {
        conveyor.setInitColor(ConveyorNamespace::Color::RED);
    
        chassis.setPose(-52, 24, -90);
    
        chassis.moveDistance(-28, 1300, {.forwards = false, .maxSpeed = 60}, true);
    
        chassis.waitUntil(23);
    
        holder.moveToState(HolderNamespace::State::HOLD);
    
        chassis.turnToPoint(-4, 48, 1000, {.maxSpeed = 127}, false);
        conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
        chassis.moveDistance(18, 700, {.maxSpeed = 127}, false);
    
        chassis.turnToHeading(14, 500, {.maxSpeed = 100}, false);
        chassis.moveDistance(12, 800, {.maxSpeed = 127}, false);
        
    
    
        chassis.moveToPoint(-23, 26, 1000, {.forwards = false, .maxSpeed = 100}, false);
        chassis.turnToHeading(5, 500, {.maxSpeed = 127}, false);
        chassis.moveDistance(10, 700, {.maxSpeed = 127}, false);
        //chassis.correctAt0({"front"});
        chassis.turnToHeading(-40, 300, {.maxSpeed = 127}, false);
    
        chassis.moveToPoint(-52, 54, 1200, {.maxSpeed = 127}, false);
        chassis.turnToHeading(-45, 500, {.maxSpeed = 127}, false);
    
        chassis.moveDistance(40, 1000, {.maxSpeed = 127}, false);
        pros::delay(200);
    
        //chassis.turnToHeading(45, 300, {.maxSpeed = 127}, false);
        chassis.moveDistance(-20, 600, {.forwards = false, .maxSpeed = 90}, false);
        chassis.moveDistance(20, 800, {.maxSpeed = 127}, false);
        pros::delay(500);
    
        intake_raiser.moveToState(HolderNamespace::State::HOLD);
        chassis.moveToPose(-56, 7, 180, 2000, {.minSpeed = 127}, false);
        intake_raiser.moveToState(HolderNamespace::State::RELEASE);
        pros::delay(100);
    
        chassis.turnToHeading(25, 1000, {.maxSpeed = 80}, false);
        chassis.waitUntilDone();
        chassis.moveDistance(-10, 1200, {.forwards = false, .minSpeed = 127}, false);
        
        holder.moveToState(HolderNamespace::State::RELEASE);
    
        //intake_raiser.moveToState(HolderNamespace::State::RELEASE);
        
        //intake_raiser.moveToState(HolderNamespace::State::HOLD);
    

}

