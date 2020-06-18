#ifndef MOTOR_H
#define MOTOR_H

#include "encoder.h"

#define periodsPerSec 100

class DCMotor {
public:
  DCMotor() {} // Default constructor

  // Constructor to connect motor GPIO pins to microcontroller
  DCMotor(uint8_t pinGroup);

  // Encoder attached to the motor
  Encoder encoder;

  // Set the wheel speed
  void setSpeed(float pulseSetpoint);

private:
  uint8_t pinGroup_; // motor GPIO pins

  static DCMotor *instances[2];

  // Encoder interrupt routines
  static void motorISR0(void *pArg) {
    if (DCMotor::instances[0] != NULL)
      DCMotor::instances[0]->setPower_();
  }

  static void motorISR1(void *pArg) {
    if (DCMotor::instances[1] != NULL)
      DCMotor::instances[1]->setPower_();
  }

  // Motor speed variables
  int32_t pulsesLast_ = 0;
  int32_t pulsesPerSec_ = 0;
  int error_ = 0;
  float pPart_ = 0.0, iPart_ = 0.0; // PI control
  int PWM_ = 0;                     // Current PWM
  int pulseSetpoint_ = 0;           // Current pulse setpoint

  // PI control. Adjust gain constants as necessary.
  const float Kp = 0.1, Ki = 0.1; // gain constants

  // Set motor power
  void setPower_();

  // Apply power to the motor
  void applyPower_(int dir, int PWM);
};

#endif