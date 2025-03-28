#ifndef LED_H_
#define LED_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "hw_def.h"
//하드웨어에 있는 모든 파일들은 hw_def.h를 포함한다.

#ifdef _USE_HW_LED

#define LED_MAX_CH  HW_LED_MAX_CH


bool ledInit(void);
void ledOn(uint8_t ch);
void ledOff(uint8_t ch);
void ledToggle(uint8_t ch);

#endif

#ifdef __cplusplus
}
#endif

#endif