
#include "motor.h"

static stMotorPins motorPinGroup[2] = {
    {RCC_AHB1ENR_GPIOEEN, MOTOR1_PIN_1, MOTOR1_PIN_2, MOTOR1_PWM,
     MOTOR1_GPIO_PORT},
    {RCC_AHB1ENR_GPIOEEN, MOTOR2_PIN_1, MOTOR2_PIN_2, MOTOR2_PWM,
     MOTOR2_GPIO_PORT}};

DCMotor::DCMotor(uint8_t pinGroup) : pinGroup_(pinGroup) {

  uint32_t tmp;
  GPIO_InitTypeDef GPIO_InitStruct;

  // Motor Pin 1 Initialization
  RCC->AHB1ENR = motorPinGroup[pinGroup_].gpioclk;
  tmp = RCC->AHB1ENR;
  GPIO_InitStruct.Pin = motorPinGroup[pinGroup_].motorDir1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(motorPinGroup[pinGroup_].gpioport, &GPIO_InitStruct);

  // Motor Pin 2 Initialization
  RCC->AHB1ENR = motorPinGroup[pinGroup_].gpioclk;
  tmp = RCC->AHB1ENR;
  GPIO_InitStruct.Pin = motorPinGroup[pinGroup_].motorDir2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(motorPinGroup[pinGroup_].gpioport, &GPIO_InitStruct);

  // Motor PWM Pin Initialization
  RCC->AHB1ENR = motorPinGroup[pinGroup_].gpioclk;
  tmp = RCC->AHB1ENR;
  GPIO_InitStruct.Pin = motorPinGroup[pinGroup_].enable;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(motorPinGroup[pinGroup_].gpioport, &GPIO_InitStruct);
}

void DCMotor::togglePin(void) {
  HAL_GPIO_TogglePin(motorPinGroup[pinGroup_].gpioport,
                     motorPinGroup[pinGroup_].enable);
  HAL_GPIO_TogglePin(motorPinGroup[pinGroup_].gpioport,
                     motorPinGroup[pinGroup_].motorDir1);
  HAL_GPIO_TogglePin(motorPinGroup[pinGroup_].gpioport,
                     motorPinGroup[pinGroup_].motorDir2);
}