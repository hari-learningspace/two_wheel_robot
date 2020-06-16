#include "encoder.h"
#include <Arduino.h>

//----------------------Constructors---------------------------------
Encoder::Encoder(uint8_t pinEncoder) : pinEncoder_(pinEncoder) {
  pinMode(pinEncoder_, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinEncoder_), encoderISR0, RISING);
  pulses = 0;
}

void Encoder::encoderFired_() {
  noInterrupts();
  pulses++;
  interrupts();
}