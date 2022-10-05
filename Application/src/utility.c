#include "utility.h"
#include "globals.h"
#include "tmr4.h"
#include "led.h"

//static uint16_t currTime = 0;
//static uint16_t lastInputTime = 0;
static uint8_t timeCount = 0;
static uint8_t ledIndicatorCount = 0;

//runs at 25mS
void Time_InterruptHandler(void)
{
	if (numBlinks)
	{
		if (++ledIndicatorCount >= ledIndicatorPeriod)
		{
			numBlinks--;
			ledIndicatorCount = 0;
			if (numBlinks != 0)
				ToggleLEDPortA(OUT_LED);      
		}		
	}

	if (glbMode.debounce)
		glbMode.debounce--;

	if (++timeCount >= 40)
	{
		timeCount = 0;
		currTime++;
	}
}
