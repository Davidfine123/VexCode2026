#pragma once
#include "components.hpp"

void right_two_rings() {
    chassis.setPose(-60, -15.5, 0);
    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    
    pros::delay(2500);

    arm.resetRotation(3000.0f);

    arm.changeVelocity(0.5);

    chassis.turnToHeading(-40, 1000, {.maxSpeed = 70}, false);

    arm.moveToState(ArmNamespace::State::UP, 1000);
    

    pros::delay(1500);

    arm.changeVelocity(1);

    chassis.moveToPoint(-27, -28, 1500, {.forwards = false, .maxSpeed = 60}, false);
    chassis.waitUntilDone();

    arm.moveToState(ArmNamespace::State::DOWN);

    pros::delay(200);

    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.turnToPoint(-20, -46, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    chassis.turnToPoint(-45, -40, 1000, {.maxSpeed = 70}, false);
    chassis.waitUntilDone();

    pros::delay(500);
    
    //conveyor.moveToState(ConveyorNamespace::State::STOP);
    chassis.turnToHeading(-120, 1000, {}, false);
    doinker.moveToState(HolderNamespace::State::RELEASE);
    chassis.waitUntilDone();

    chassis.moveDistance(35,3000);
    chassis.waitUntilDone();
    chassis.turnToHeading(-110,1000);
    chassis.moveDistance(10,1000,{.maxSpeed = 50}, false);
    chassis.waitUntilDone();
    chassis.moveDistance(-10,1000);
    
    pros::delay(100);
    chassis.turnToHeading(45,2000);
    chassis.moveDistance(45,5000);
    pros::delay(1000);
    arm.moveToState(ArmNamespace::State::UP, 1000);



    /*
   

    

    chassis.waitUntil(21);

    holder.moveToState(HolderNamespace::State::HOLD);

    pros::delay(300);

    chassis.turnToHeading(0, 1000);
    chassis.waitUntilDone();
    conveyor.moveToState(ConveyorNamespace::State::FORWARDS);

    chassis.moveDistance(24, 2000, {.maxSpeed = 100});
    chassis.waitUntilDone();

    pros::delay(300);
    chassis.turnToHeading(120, 1000);
    chassis.moveDistance(-30, 1000, {.forwards = false, .maxSpeed = 100}, false);
    holder.moveToState(HolderNamespace::State::RELEASE);

    chassis.moveToPoint(-18, 18, 2000, {.maxSpeed = 80});*/
}

void red_right_two_rings() {
    conveyor.setInitColor(ConveyorNamespace::Color::RED);
    right_two_rings();
}

void blue_right_two_rings() {
    conveyor.setInitColor(ConveyorNamespace::Color::BLUE);
    right_two_rings();
}

void no_color_right_two_rings() {
    conveyor.disable_color_sensor();
    right_two_rings();
}
