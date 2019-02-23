
#include "stm32f0xx_hal.h"
#include "stm32f0xx.h"
#include "stm32f0xx_it.h"
#include "uart.h"

extern UART_HandleTypeDef huart1;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;

volatile uint32_t ms_count = 0;


void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1)
  {
  }

}

void SVC_Handler(void)
{
}

void PendSV_Handler(void)
{
}

void SysTick_Handler(void)
{
	ms_count--;
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

void DMA1_Channel2_3_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&hdma_usart1_tx);
	HAL_DMA_IRQHandler(&hdma_usart1_rx);
}

void USART1_IRQHandler(void)
{
	HAL_UART_IRQHandler(&huart1);
}

void delay_ms(uint32_t t)
{
	ms_count = t;
	while (ms_count > 0);
}
