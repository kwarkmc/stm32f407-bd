#include "hw.h"





bool hwInit(void)
{
	cliInit(); //모든 모듈에서 CLI를 쓸 수 있어야 하기 때문에 맨 처음으로 초기화
	ledInit();
	uartInit();
	for (int i=0; i<UART_MAX_CH; i++)
	{
		uartOpen(i, 115200);
	}

	return true;
}

void delay(uint32_t ms)
{
	HAL_Delay(ms);
}

uint32_t millis(void)
{
	HAL_GetTick();
}