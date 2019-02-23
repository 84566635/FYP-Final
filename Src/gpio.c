/*
 * pio.c
 *
 *  Created on: Sep 7, 2018
 *      Author: Keung
 */


#include "gpio.h"


void GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, PWRC_Pin|LED_R_Pin|LED_G_Pin|LED_B_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PWRC_Pin LED_R_Pin LED_G_Pin LED_B_Pin */
  GPIO_InitStruct.Pin = PWRC_Pin|LED_R_Pin|LED_G_Pin|LED_B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

void GPIO_LED_On(uint8_t pin)
{
	HAL_GPIO_WritePin(GPIOA, LED_R_Pin | LED_G_Pin | LED_B_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, pin, SET);
}

