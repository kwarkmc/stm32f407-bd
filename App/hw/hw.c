#include "hw.h"





bool hwInit(void)
{


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