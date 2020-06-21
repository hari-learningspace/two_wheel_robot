#ifndef MAIN_H
#define MAIN_H

#include <mbed.h>

#define MOTOR1_FWD PE_9
#define MOTOR1_REV PE_7
#define MOTOR1_PWM PE_11

typedef struct {
  PinName fwd;
  PinName rev;
  PinName pwm;
} stMotorPins;

#endif