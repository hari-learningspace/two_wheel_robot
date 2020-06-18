#ifndef MAIN_H
#define MAIN_H

#include <ros.h>
#include <stdint.h>

// Define the GPIO pins for the motors
static struct MotorPins {
  const byte motorDir1; // motor direction pin1
  const byte motorDir2; // motor direction pin2
  const byte enable;    // Enable PMW
  const byte encoderA;  // encoder channel A
  const byte encoderB;  // encoder channel B
} motorPinGroup[2] = {27, 26, 25, 36, 37, 14, 12, 13, 38, 39};

#endif