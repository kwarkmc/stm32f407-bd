#ifndef HW_DEF_H_
#define HW_DEF_H_


#include "main.h"
#include "def.h"



#define _USE_HW_LED
#define      HW_LED_MAX_CH		3	//LED의 개수를 정의해줌

#define _USE_HW_UART
#define      HW_UART_MAX_CH		1	//UART 채널 수수

#define logPrintf printf

void delay(uint32_t ms);
uint32_t millis(void);

#endif