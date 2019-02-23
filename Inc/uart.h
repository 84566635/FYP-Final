
#ifndef UART_H_
#define UART_H_

#include "stm32f0xx_hal.h"

void USART1_UART_Init(void);
void HAL_UART_MspInit(UART_HandleTypeDef* huart);
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart);
HAL_StatusTypeDef UART_Send(uint8_t *pData, uint16_t size);
HAL_StatusTypeDef UART_Receive(uint8_t *pData, uint16_t size);
void DMA_Init(void);

#endif /* UART_H_ */
