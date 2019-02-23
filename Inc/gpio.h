/*
 * gpio.h
 *
 *  Created on: Sep 7, 2018
 *      Author: Keung
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f0xx_hal.h"

#define LED_R_Pin GPIO_PIN_5
#define LED_R_GPIO_Port GPIOA
#define LED_G_Pin GPIO_PIN_6
#define LED_G_GPIO_Port GPIOA
#define LED_B_Pin GPIO_PIN_7
#define LED_B_GPIO_Port GPIOA


void GPIO_Init(void);
void GPIO_LED_On(uint8_t pin);

#endif /* GPIO_H_ */
