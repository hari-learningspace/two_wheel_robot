#include "robot.h"

// ----------------------------- Constructor ---------------------
TwoWheeledRobot::TwoWheeledRobot(ros::NodeHandle *nodeHandle)
    : driveTrain(nodeHandle) {}

#if 0
//--------------------------------------------//
// Control the position of the robot
//--------------------------------------------//
void TwoWheeledRobot::poseController(float *refPose) {

  // Get the current x position of the robot
  // float *currentPose = robot->driveTrain.getLocalPose();

  // Subtract the target pose from the current pose to get the error
  // Matrix.Subtract(refPose, currentPose, 3, 1, poseError);

  // ROSLOGFLabel("Start error X", poseError[X_POS]);
  // ROSLOGFLabel("Start error Psi", poseError[PSI]);

  // Save the original pose errors
  // float linear_error = poseError[X_POS];
  // float angular_error = poseError[PSI];

  // -------- Process linear error ------------------
  // if (fabs(linear_error) > 0.0) {
  //  moveLinear();
  //}

  // -------- Process angular error -----------------
  // if (fabs(angular_error) > 0.0) {
  // Pass in the arc length
  //  moveAngular(0.0); // Turn on the spot
  //}
}

// PI control for pose loop. Adjust gain constants as necessary
const float Kp = 1.5; // Gets within 15% of target
const float Ki = 0.3; // Maintains a minimum speed of 0.3
//----------------------------------------------//
// Move in a straight line forward or backward
//----------------------------------------------//
void moveLinear() {

  // Save the direction of motion
  // int dir = sgn(int(poseError[X_POS] * 1000));

  // Set min and max speed.
  float maxSpeed = 1.0;
  float wheelSpeed = maxSpeed;
  int loopCounter = 0; // Loop counter for timeout

  // while (fabs(poseError[X_POS]) > 0.0) {

  // Process the loop every 50 milliseconds
  // current_time = nh.now().toSec();
  // while (nh.now().toSec() < current_time + poseLoopPeriod) {
  // wait 50ms
  //}

  // Timeout after 5 seconds
  // if (loopCounter > timeOut) {
  //  ROSLOGString("Timed out!");
  //  break;
  //}

  // End loop if the direction sign has changed (went passed the target)
  // if (sgn(int(poseError[X_POS] * 1000)) != dir) {
  //  break;
  //}

  // Actuate the wheels

  // Slows down when we get near the target position
  // Sets wheel speed proportionally to the position error
  // wheelSpeed = (poseError[X_POS] * Kp) + (Ki * dir); // Kp = 2.0, Ki = 0.3

  // Keep max speed to 1.0
  // if (fabs(wheelSpeed) > maxSpeed) {
  //  wheelSpeed = (maxSpeed * dir); // Max 1.0
  //}
  // ROSLOGFLabel("wheelSpeed", wheelSpeed);

  // robot->setWheelSpeeds(wheelSpeed, wheelSpeed); // left and right wheel

  // Get the current x position of the robot
  // float *currentPose = robot->getLocalPose();

  // Calculate the error
  // Matrix.Subtract(refPose, currentPose, 3, 1, poseError);

  // publishToROS(currentPose); // Publish robot state to ROS

  loopCounter++;

  //} // End while loop

  // Stop the wheels
  // robot->setWheelSpeeds(0.0, 0.0); // Stop
  // ROSLOGString("--- Done linear movement ---");
}


//----------------------------------------------//
// Move in an arc clockwise or anti-clockwise
//----------------------------------------------//
void moveAngular(float arcRadius) {


  // Calculate the relative wheel speeds based on the
  // radius of the turn.
  float ratio = robot->calculateArcWheelRatios(arcRadius);

  // Save the direction of motion
  int dir = sgn(int(poseError[PSI] * 1000));

  // Use half of max speed for turn.
  float maxSpeed = 0.5;

  // Set initial wheel speeds
  float outsideWheelSpeed = maxSpeed;
  float insideWheelSpeed = maxSpeed * ratio;

  int loopCounter = 0; // Loop counter for timeout

  while (fabs(poseError[PSI]) > 0.0) {

    // Process the loop every 50 milliseconds
    current_time = nh.now().toSec();
    while (nh.now().toSec() < current_time + poseLoopPeriod) {
      // wait 50ms
    }

    // Timeout after 10 seconds
    if (loopCounter > (timeOut * 2)) {
      ROSLOGString("Timed out!");
      break;
    }

    // End while loop if the direction sign has changed (went passed the target)
    if (sgn(int(poseError[PSI] * 1000)) != dir) {
      break;
    }

    // Slows down when we get near the target orientation
    // Sets the outside wheel speed proportionally to the orientation error
    float outsideWheelSpeed =
        (poseError[PSI] * Kp) + (Ki * dir); // Kp = 3.0, Ki = 0.3

    // Keep max speed to 1.0
    if (fabs(outsideWheelSpeed) > maxSpeed) {
      outsideWheelSpeed = maxSpeed; // Max 1.0
    }

    // Calculate the inside wheel speed. Ratio will be -1 for turn on the spot
    insideWheelSpeed = outsideWheelSpeed * ratio;
    ROSLOG2FLabel("Wheel speeds (left,right)", insideWheelSpeed,
                  outsideWheelSpeed);

    // Actuate the wheels
    if (poseError[PSI] > 0.0) { // Moving anti-clockwise. Inside wheel is left
      robot->setWheelSpeeds(insideWheelSpeed,
                            outsideWheelSpeed); // (left wheel, right wheel)
    } else { // Moving clockwise. Outside wheel is left
      robot->setWheelSpeeds(outsideWheelSpeed,
                            insideWheelSpeed); // (left wheel, right wheel)
    }

    // Get the current x position of the robot
    float *currentPose = robot->getLocalPose();

    // Calculate the error
    Matrix.Subtract(refPose, currentPose, 3, 1, poseError);

    publishToROS(currentPose); // Publish robot state to ROS

    loopCounter++;

  } // End while loop

  // Stop the wheels
  robot->setWheelSpeeds(0.0, 0.0); // Stop
  ROSLOGString("--- Done angular movement ---");


}

#endif