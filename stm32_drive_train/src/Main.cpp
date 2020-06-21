#include "Main.h"
#include "Motor.h"

int main() {

  Motor rightwheel(MOTOR1_PWM, MOTOR1_FWD, MOTOR1_REV);

  rightwheel.speed(0.5);
  while (1)
    ;
  return 0;
}