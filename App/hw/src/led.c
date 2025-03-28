#include "led.h"


#ifdef _USE_HW_LED
#include "cli.h"


// 내부 참조 데이터 정의 
//
typedef struct
{
	GPIO_TypeDef* port;
	uint16_t pin;
	GPIO_PinState on_state;
	GPIO_PinState off_state;
} led_tbl_t;


// 외부 참조 데이터
//
//extern

// 내부 참조 데이터 
//
static led_tbl_t led_tbl[LED_MAX_CH] = {
	{GPIOE, GPIO_PIN_13, GPIO_PIN_RESET, GPIO_PIN_SET},
	{GPIOE, GPIO_PIN_14, GPIO_PIN_RESET, GPIO_PIN_SET},
	{GPIOE, GPIO_PIN_15, GPIO_PIN_RESET, GPIO_PIN_SET}
};

static void cliLed(cli_args_t *);

bool ledInit(void)
{

  for (int i=0; i<LED_MAX_CH; i++)
  {
    ledOff(i);
  }

  cliAdd("led", cliLed);

  return true;
}

void ledOn(uint8_t ch)
{
  if (ch >= LED_MAX_CH) return;

  HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].on_state);
}

void ledOff(uint8_t ch)
{
  if (ch >= LED_MAX_CH) return;

  HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].off_state);
}

void ledToggle(uint8_t ch)
{
  if (ch >= LED_MAX_CH) return;

  HAL_GPIO_TogglePin(led_tbl[ch].port, led_tbl[ch].pin);
}



void cliLed(cli_args_t *args) 
{
  bool ret = false;

  if (args->argc == 1 && args->isStr(0, "on"))
  {
    uint8_t led_ch;
    led_ch = (uint8_t)args->getData(1);
    ledOn(led_ch);
    ret = true;
  }
  
  if (args->argc == 1 && args->isStr(0, "off"))
  {
    uint8_t led_ch;
    led_ch = (uint8_t)args->getData(1);
    ledOff(led_ch);
    ret = true;
  }

  if (args->argc == 1 && args->isStr(0, "test"))
  {
    while(cliKeepLoop())
    {
      cliPrintf("led on\n");
      ledOn(_DEF_LED1);
      delay(500);
      //바로 빠져나오고 싶으면 Delay 아니라 millis 함수 사용할 것.
      cliPrintf("led off\n");
      ledOff(_DEF_LED1);
      delay(500);
    }
    ret = true;
  }

  if (!ret)
  {
    cliPrintf("led on 0~%d\n", LED_MAX_CH - 1);
    cliPrintf("led off 0~%d\n", LED_MAX_CH - 1);
    cliPrintf("led test\n");
  }
}

#endif