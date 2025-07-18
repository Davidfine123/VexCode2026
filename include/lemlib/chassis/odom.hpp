#pragma once

#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pose.hpp"
#include "pros/distance.hpp"

namespace lemlib {
/**
 * @brief Set the sensors to be used for odometry
 *
 * @param sensors the sensors to be used
 * @param drivetrain drivetrain to be used
 */
void setSensors(lemlib::OdomSensors sensors, lemlib::Drivetrain drivetrain);
/**
 * @brief Get the pose of the robot
 *
 * @param radians true for theta in radians, false for degrees. False by default
 * @return Pose
 */
Pose getPose(bool radians = false);
/**
 * @brief Set the Pose of the robot
 *
 * @param pose the new pose
 * @param radians true if theta is in radians, false if in degrees. False by default
 */
void setPose(Pose pose, bool radians = false);
/**
 * @brief Get the speed of the robot
 *
 * @param radians true for theta in radians, false for degrees. False by default
 * @return lemlib::Pose
 */
Pose getSpeed(bool radians = false);
/**
 * @brief Get the local speed of the robot
 *
 * @param radians true for theta in radians, false for degrees. False by default
 * @return lemlib::Pose
 */
Pose getLocalSpeed(bool radians = false);
/**
 * @brief Estimate the pose of the robot after a certain amount of time
 *
 * @param time time in seconds
 * @param radians False for degrees, true for radians. False by default
 * @return lemlib::Pose
 */
Pose estimatePose(float time, bool radians = false);

/**
 * @brief calculate the distance traveled by the robot in each time step
 *
 */
float getDistanceTraveled();
/**
 * @brief Update the pose of the robot
 *
 */
void update();
/**
 * @brief Initialize the odometry system
 *
 */
void init();

/**
 * @brief Correct the odometry using sensors
 */
void correctByDistanceSensors();

/**
 * @brief best pose
 */
lemlib::Pose bestPoe();

/**
 * @brief Expected pose
 */
lemlib::Pose estimatePose();

void correctAt0(std::set<std::string> sensors);
void correctAt90(std::set<std::string> sensors);
void correctAt180(std::set<std::string> sensors);
void correctAt270(std::set<std::string> sensors);
} // namespace lemlib
