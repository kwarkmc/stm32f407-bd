#include "ap.h"





void apInit(void)
{

}

void apMain(void)
{
	while(1)
	{
		// ledToggle(_DEF_LED1);
		// delay(500);

		if (uartAvailable(_DEF_UART1) > 0)
		{
			uartPrintf(_DEF_UART1, "rx : 0x%X\n", uartRead(_DEF_UART1));
		}
	}
}