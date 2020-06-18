#ifndef WHEEL_H
#define WHEEL_H

#include "main.h"
#include "motor.h"

class Wheel {
public:
  // Constructor for powered wheels
  Wheel(uint8_t pinGroup, float wheelDiameter, uint8_t wheelType);

  // Constructor for unpowered wheels
  Wheel(float wheelDiameter, uint8_t wheelType);

  // -------------------- Member variables -----------------

  // --- Configuration (physical) properties ---
  float diameter; // wheel diameter in meters
  uint8_t type;

  DCMotor motor;

  // ---  Kinematic (motion) properties ----
  // const float distancePerPulse = (PI * diameter) / Encoder::PPR; // PI*D/PPR

  // Current direction of the wheel
  int currentDirection = 0;

  // Get the current linear_x position of the wheel
  float currentPosition();

  // ------------------- Convenience methods ------------------

  // Set wheel speed in meters/sec
  void setSpeed(float speed);

  // Encoder pulses from attached motor
  int32_t encoderPulses();
};

#endif