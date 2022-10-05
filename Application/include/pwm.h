/* 
 * File:   pwm.h
 * Author: Marc H
 *
 * Created on January 27, 2022, 8:04 PM
 */

#ifndef PWM_H
#define	PWM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "led.h"

void next(void);
// void Set_PWM_InterruptHandler(void);
void SetFireInterruptHandler(void);
void FireInterrupt(void);
void PWM_InterruptHandler(void);
// void PWM_FireFly(void);
// void PWM_FireFly2(void);
void Fire(uint8_t *lowpass);
void PWM_Fire(void);
void PWM_Fire2(void);
void HandleFire(void);
void TurnOnPWMLEDs(uint8_t leds[]);
void TurnOffPWMLEDs(uint8_t leds[]);
void TurnOnAllPWMLEDs(void);
void TurnOffAllPWMLEDs(void);

void TogglePWMLEDsOn(uint8_t leds[]);
#ifdef	__cplusplus
}
#endif

#endif	/* PWM_H */

