#include "led.h"
#include "globals.h"

inline void SetLEDOnPortA(uint8_t leds)
{
	LATA |= leds;
}

inline void SetLEDOffPortA(uint8_t leds)
{
	LATA &= ~leds;
}

inline void ToggleLEDPortA(uint8_t leds)
{
	LATA ^= leds;
}

inline void SetLEDOnPortC(uint8_t leds)
{
	LATC |= leds;
}


inline void SetLEDOffPortC(uint8_t leds)
{
	LATC &= ~leds;
}

inline void ToggleLEDPortC(uint8_t leds)
{
	LATC ^= leds;
}

void SetLEDOn(uint8_t leds[])
{
	SetLEDOnPortA(leds[PORT_A]);    
	SetLEDOnPortC(leds[PORT_C]);
}

void SetLEDOff(uint8_t leds[])
{	
	SetLEDOffPortA(leds[PORT_A]);
	SetLEDOffPortC(leds[PORT_C]);
}

void ToggleLED(uint8_t leds[])
{
	ToggleLEDPortA(leds[PORT_A]);
	ToggleLEDPortC(leds[PORT_C]);
}

void SetAllLEDOn(void)
{
	uint8_t leds[2] = {	OUT_AUX | OUT_F | OUT_E, 
						OUT_C | OUT_A | OUT_B | OUT_D};
	SetLEDOn(leds);
}

void SetAllLEDOff(void)
{
	uint8_t leds[2] = {	OUT_AUX | OUT_F | OUT_E, 
						OUT_C | OUT_A | OUT_B | OUT_D};
	SetLEDOff(leds);
}

inline void TurnOnIndicatorLED(void)
{
	SetLEDOffPortA(OUT_LED);
}

inline void TurnOffIndicatorLED(void)
{
	SetLEDOnPortA(OUT_LED);
}

void BlinkIndicatorLED(uint8_t num, uint8_t blinkLengthx25mS)
{
	numBlinks = num;
	ledIndicatorPeriod = blinkLengthx25mS;
	SetLEDOnPortA(OUT_LED);
}
