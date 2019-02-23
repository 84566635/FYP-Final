
#ifndef __MAIN_H__
#define __MAIN_H__

#define PWRC_Pin GPIO_PIN_1
#define PWRC_GPIO_Port GPIOA
#define RF_CONTROL_Pin GPIO_PIN_4
#define RF_CONTROL_GPIO_Port GPIOA
#define POWER_CONTROL_Pin GPIO_PIN_1
#define POWER_CONTROL_GPIO_Port GPIOB

#define TX
//#define RX

#ifdef __cplusplus
 extern "C" {
#endif

void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */
