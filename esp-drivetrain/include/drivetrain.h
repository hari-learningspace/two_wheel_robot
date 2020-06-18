#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "main.h"
#include "wheel.h"
#include <nav_msgs/Odometry.h>

class DriveTrain {
public:
  // Constructor
  DriveTrain(ros::NodeHandle *nodeHandle);

  uint8_t leftWheelPinGroup = 0;  // GPIO pin group config.h
  uint8_t rightWheelPinGroup = 1; // GPIO pin group config.h

  const float wheelDiameter = 0.063;   // wheel diameter in meters
  const uint8_t wheelType = 0;         // STANDARD_FIXED;
  const float wheelSeparation = 0.179; // wheel separation in meters

  // Wheel leftWheel = Wheel(leftWheelPinGroup, wheelDiameter, wheelType);
  // Wheel rightWheel = Wheel(rightWheelPinGroup, wheelDiameter, wheelType);

  // Pointer to the ROS node
  ros::NodeHandle *nh_;

  // Robot state
  nav_msgs::Odometry state;

  // Define publisher for ROS
  ros::Publisher *pub_odom;
  //--- Drive train functions ---
  void setWheelSpeeds(float leftWheelSpeed, float rightWheelSpeed);

  void publishState();

  float *getLocalPose();

  float *getLocalVelocity();

  void printLocalPose();

private:
  // --- Odometry state variables and methods ---
  static DriveTrain *instances[1];
  // Keeps track of encoder pulses from each wheel
  uint32_t leftPositionLast_ = 0, rightPositionLast_ = 0;
  const int maxPulsesPerSecond_ = 600;
  // Static instance to update robot state
  static void updateStateISR(void *pArg) {
    if (DriveTrain::instances[0] != NULL)
      DriveTrain::instances[0]->updateState_();
  }

  // Instance member to update robot state. Called from updateStateISR
  void updateState_();
};

#endif