#ifndef MAIN_H
#define MAIN_H

#include "stm32f4xx_hal.h"

#define MOTOR1_CLK_ENABLE __HAL_RCC_GPIOE_CLK_ENABLE
#define MOTOR1_PIN_1 GPIO_PIN_7
#define MOTOR1_PIN_2 GPIO_PIN_8
#define MOTOR1_PWM GPIO_PIN_9
#define MOTOR1_GPIO_PORT GPIOE

#define MOTOR2_CLK_ENABLE __HAL_RCC_GPIOE_CLK_ENABLE
#define MOTOR2_PIN_1 GPIO_PIN_10
#define MOTOR2_PIN_2 GPIO_PIN_11
#define MOTOR2_PWM GPIO_PIN_12
#define MOTOR2_GPIO_PORT GPIOE

// Define the GPIO pins for the motors
typedef struct {
  const uint32_t gpioclk;
  const uint16_t motorDir1; // motor direction pin1
  const uint16_t motorDir2; // motor direction pin2
  const uint16_t enable;    // Enable PMW
  // const byte encoderA;  // encoder channel A
  // const byte encoderB;  // encoder channel B
  GPIO_TypeDef *gpioport;
} stMotorPins;

#endif