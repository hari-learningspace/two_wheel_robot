#ifndef MOTOR_H
#define MOTOR_H

#include "main.h"
#include <stdint.h>

class DCMotor {
public:
  DCMotor() {} // Default constructor

  // Constructor to connect motor GPIO pins to microcontroller
  DCMotor(uint8_t pinGroup);

  static DCMotor *instances[2];

  void setSpeed(int pwm);

  void togglePin(void);

private:
  uint8_t pinGroup_;

  void Motor_gpio_pins_initialization(uint8_t pinGroup);
};

#endif