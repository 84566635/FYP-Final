/*
 * i2c.h
 *
 *  Created on: Sep 7, 2018
 *      Author: Keung
 */

#ifndef I2C_H_
#define I2C_H_

#include "stm32f0xx_hal.h"

#define I2C_TIMEOUT		100

void I2C1_Init(void);
void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c);
void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c);
HAL_StatusTypeDef I2C_ReadBytes_NoReg(uint16_t addr, uint8_t *pData, uint16_t size);
HAL_StatusTypeDef I2C_WriteBytes_NoReg(uint16_t addr, uint8_t *pData, uint16_t size);
HAL_StatusTypeDef I2C_WriteBytes(uint16_t addr, uint16_t reg, uint8_t *pData, uint16_t size);

#endif /* I2C_H_ */
