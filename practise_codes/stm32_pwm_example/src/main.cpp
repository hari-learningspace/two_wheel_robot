#include "main.h"
#include "tim.h"
#include <mbed.h>

int main() {

  MX_TIM4_Init();

  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);

  while (1) {
  }
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while (1)
    ;
  /* USER CODE END Error_Handler_Debug */
}