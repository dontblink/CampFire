/* 
 * File:   led.h
 * Author: Marc H
 *
 * Created on January 27, 2022, 6:43 PM
 */

#ifndef LED_H
#define	LED_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <xc.h>

#define NUM_LED_PORTS 	2
#define PORT_A 			0
#define PORT_C 			1

//these leds are all defined on port A
#define OUT_AUX 		1
#define OUT_LED 		2
#define OUT_F 			16
#define OUT_E 			32

//these leds are all defined on port C
#define OUT_C 			1
#define OUT_A 			4
#define OUT_B 			2
#define OUT_D 			16

uint8_t numBlinks = 0;
uint8_t ledIndicatorPeriod = 0;

inline void SetLEDOnPortA(uint8_t leds);
inline void SetLEDOffPortA(uint8_t leds);
inline void ToggleLEDPortA(uint8_t leds);

inline void SetLEDOnPortC(uint8_t leds);
inline void SetLEDOffPortC(uint8_t leds);
inline void ToggleLEDPortC(uint8_t leds);

void SetLEDOn(uint8_t leds[]);
void SetLEDOff(uint8_t leds[]);
void ToggleLED(uint8_t leds[]);

void SetAllLEDOn(void);
void SetAllLEDOff(void);

inline void TurnOnIndicatorLED(void);
inline void TurnOffIndicatorLED(void);
void BlinkIndicatorLED(uint8_t num, uint8_t blinkLengthx25mS);

#ifdef	__cplusplus
}
#endif

#endif	/* LED_H */

