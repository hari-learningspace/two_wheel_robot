#ifndef ROBOT_H
#define ROBOT_H

#include "drivetrain.h"
#include "main.h"
#include "wheel.h"

// Define wheel types
enum WheelTypes {
  STANDARD_FIXED = 1,
  STANDARD_FIXED_POWERED,
  STANDARD_FIXED_CONNECTED,
  STANDARD_FIXED_CONNECTED_POWERED,
  STANDARD_STEERABLE,
  STANDARD_STEERABLE_CONNECTED,
  CASTER,
  SWEDISH,
  MECANUM,
  SPHERIC
};

class TwoWheeledRobot {
public:
  // --- Constructor ---
  TwoWheeledRobot(ros::NodeHandle *nodeHandle);

  // --- Robot configuration ---

  // Define the shape and size of the robot
  struct Geometry {
    uint8_t type = 0; // CYLINDER;
    float radius = 0.11;
    float length = 0.20;
  };

  // Drive train of robot
  DriveTrain driveTrain;

  // Unmotorized wheels
  const float casterDiameter = 0.020; // caster diameter in meters
  Wheel frontCaster = Wheel(casterDiameter, CASTER);
  Wheel backCaster = Wheel(casterDiameter, CASTER);

  // --- Kinematic functions ---------
  void moveAngular(float *refPose, float arcRadius);

  void moveLinear(float *refPose);

  void poseController(float *refPose);

private:
  // --- Variables used for kinematics

  // Error matrix for feedback loop
  float poseError[3] = {0.0, 0.0, 0.0};

  double currentTime_;
  const double poseLoopPeriod_ = 0.05;                      // 50 milliseconds
  const int poseLoopPeriodMillis_ = poseLoopPeriod_ * 1000; // 50 milliseconds
  const int poseLoopPeriodsPerSecond_ = 1000 / poseLoopPeriodMillis_;
  const int timeOut_ = poseLoopPeriodsPerSecond_ * 8; // 8 seconds

  // PI control for pose loop. Adjust gain constants as necessary
  const float startUpKi_ = 0.05; // Ki value to startup robot
  const float Kp_ = 3.0;         // Gets within 15% of target
  const float Ki_ = 0.3;         // Maintains a minimum speed of 0.3

  // Move phases
  const byte STARTUP = 1;
  const byte RUNNING = 2;
  const byte SHUTDOWN = 3;
  const byte STOPPED = 4;
};

#endif