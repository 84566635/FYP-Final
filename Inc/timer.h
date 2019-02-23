
#ifndef TIMER_H_
#define TIMER_H_

#include "stm32f0xx_hal.h"

void TIM3_Init(void);
void TIM14_Init(void);
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* htim_pwm);
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* htim_base);
void HAL_TIM_MspPostInit(TIM_HandleTypeDef* htim);
void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef* htim_pwm);
void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* htim_base);

#endif /* TIMER_H_ */
