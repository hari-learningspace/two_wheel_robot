#include "main.h"
#include "gpio.h"
#include "tim.h"
#include <mbed.h>

int main() {

  Serial pc(USBTX, USBRX); // tx, rx
  uint16_t EncVal;

  printf("hello from mcu");
  // put your setup code here, to run once:
  MX_GPIO_Init();
  MX_TIM1_Init();

  HAL_TIM_Encoder_Start(&htim1, TIM_ENCODERMODE_TI12);

  while (1) {
    // put your main code here, to run repeatedly:
    EncVal = TIM1->CNT;
    pc.printf("Encoder -> %d \n\r", EncVal);
  }
}

void Error_Handler(void) {
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while (1)
    ;
  /* USER CODE END Error_Handler_Debug */
}
