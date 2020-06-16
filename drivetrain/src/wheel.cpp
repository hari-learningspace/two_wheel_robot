#include "wheel.h"

// ------------------ Constructors --------------------------
// This is for a powered wheel so we need a motor and a set of GPIO pins to
// connect it to the microcontroller.
Wheel::Wheel(uint8_t pinGroup, float wheelDiameter, uint8_t wheelType)
    : motor(pinGroup), diameter(wheelDiameter), type(wheelType) {}

// This is for an unpowered wheel so no motor gets attached.
Wheel::Wheel(float wheelDiameter, uint8_t wheelType)
    : diameter(wheelDiameter), type(wheelType) {}