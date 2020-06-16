#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>
#include <stdint.h>
// This Class Define the Encoder Functionality of the DC Motor
// Motor Description
/*
Description : 6V 100 RPM Encoder Motor DC Gear Motor
Specification : Voltage : DC 6.0V
                Speed : 100RPM
                Shaft diameter : 4mm Length : 12mm
                Encoder motor end 11 signals
                Terminal connection length 20cm class Encoder {}
                Hall Encoder -  823.1PPR

*/
class Encoder {
public:
  // Class Variables
  static const int PPR = 20;

  // Default Constructor
  Encoder() {}

  // Constructor to Connect encoder GPIO pins to Microcontroller
  Encoder(uint8_t pinGroup);

  volatile int32_t pulses;
  // int8_t wheelDirection = 0; currently only one pin is configured for

  static Encoder *instances[2];

private:
  uint8_t pinEncoder_;

  void encoderFired_();

  // Encoder Interrupt Routines
  static void encoderISR0() {
    if (Encoder::instances[0] != NULL)
      Encoder::instances[0]->encoderFired_();
  }

  static void encoderISR1() {
    if (Encoder::instances[1] != NULL)
      Encoder::instances[1]->encoderFired_();
  }
};

#endif