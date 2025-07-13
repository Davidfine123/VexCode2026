#pragma once
#include "components.hpp"

void red_pos_Alliance(){

       
        arm.resetRotation(2100.0f);
        conveyor.setInitColor(ConveyorNamespace::Color::RED);
        chassis.setPose(-60, -15, -31);

        //pros::delay(2500);h
        //normal arm code
    
        //back up arm code
        // arm.moveToState(ArmNamespace::State::WAIT);
        // pros::delay(300);
        // conveyor.moveToState(ConveyorNamespace::State::FORWARDS, 500);
        // comment 4 lines below for no wall stake


        arm.moveToState(ArmNamespace::State::AUTO_UP);
        pros::delay(300);
    
        chassis.moveDistance(-5, 300, {.forwards = false, .maxSpeed = 127}, true);
        chassis.waitUntil(4);
        arm.moveToState(ArmNamespace::State::DOWN);
        conveyor.moveToState(ConveyorNamespace::State::INTAKE_FORWARD);
        intake_raiser.moveToState(HolderNamespace::State::HOLD);
        chassisSmall.turnToPoint(-48, 0, 600,{.maxSpeed = 127},false);
   
        chassis.moveDistance(12, 600,{.maxSpeed = 127},true);
        chassis.waitUntil(9);
        intake_raiser.moveToState(HolderNamespace::State::RELEASE);
        chassis.waitUntilDone();
        pros::delay(100);
        chassis.moveDistance(-5,500,{.forwards = false, .maxSpeed = 127},false);
        chassis.turnToPoint(-24,-24,800,{.forwards = false, .maxSpeed = 127},false);
        chassis.moveDistance(-13, 600, {.forwards = false, .maxSpeed= 127}, false);
        chassis.moveToPoint(-24,-24,900,{.forwards = false, .maxSpeed = 70},true);
        chassis.waitUntil(10);
        holder.moveToState(HolderNamespace::State::HOLD);
        chassis.waitUntilDone();
        conveyor.moveToState(ConveyorNamespace::State::FORWARDS);
        chassis.turnToPoint(-24,-43,600,{.maxSpeed = 127},false);
        chassis.moveToPoint(-24,-43,700,{.maxSpeed = 127},false);
        chassis.turnToPoint(-53,-48,500,{.maxSpeed = 127},false);
        chassis.moveToPoint(-53,-48,1000,{.maxSpeed = 127},false);
      

        chassis.turnToPoint(-72, -72, 500,{.maxSpeed = 127}, false);
        chassis.moveToPoint(-72, -72, 1000,{.maxSpeed = 80},false);
        
       
        chassis.moveDistance(-18, 800, {.forwards = false, .maxSpeed = 127}, false);
        chassis.moveDistance(12, 600, {.maxSpeed = 100}, false);
        pros::delay(300);
        chassis.moveToPoint(-72, -72, 800,{.maxSpeed = 127},false);

        chassis.moveDistance(-15, 500, {.forwards = false, .maxSpeed = 127}, false);
        chassis.moveToPoint(-72, -72, 800,{.maxSpeed = 127},false);

        chassis.turnToHeading(90, 500,{.maxSpeed = 127},false);
        
        conveyor.moveToState(ConveyorNamespace::State::STOP);

        chassis.waitUntilDone();
        chassis.turnToPoint(-24,-48,600,{.maxSpeed = 127},false);



        

        chassis.moveToPoint(-24,-48,600,{.maxSpeed = 127},true);
        chassis.waitUntil(4);
        holder.moveToState(HolderNamespace::State::RELEASE);
        chassis.turnToPoint(0,-48,600,{.forwards = false,.maxSpeed = 127},false);
        
}

        
        


        