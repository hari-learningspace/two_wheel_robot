#include "motor.h"
#include <mbed.h>

int main() {

  DigitalOut motorpin1(PE_7);
  DigitalOut motorpin2(PE_9);
  PwmOut motorpwm(PE_11);

  // put your setup code here, to run once:
  motorpin1 = 1;
  motorpin2 = 0;
  motorpwm.period(0.001);
  motorpwm.write(0.5);
  while (1) {
  }

#ifdef LED_BLINKING
  while (1) {
    // put your main code here, to run repeatedly:
    motorpin = 1;
    wait(0.5);
    motorpin = 0;
    wait(0.5);
  }
#endif
}
