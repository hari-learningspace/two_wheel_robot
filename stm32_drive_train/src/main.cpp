#include "main.h"
#include "motor.h"

int main() {

  HAL_Init();
  DCMotor RightWheel(0);

  while (1) {
    RightWheel.togglePin();
    HAL_Delay(1000);
  }

  return 0;
}