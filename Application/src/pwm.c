#include "pwm.h"
#include "tmr0.h"
#include "tmr2.h"
#include "tmr4.h"
#include "utility.h"

volatile uint16_t onTime = 0xFFFF;
volatile uint16_t onTime2 = 0xFFFF;

volatile uint16_t rnd_lfsr = 0x55ce;
#define FF_OFF 0
#define FF_RISE 1
#define FF_STAY 2
#define FF_FALLING 3
#define FF_NUM_STATES 4

volatile uint8_t fireFlyState[2] = {FF_OFF, FF_OFF};
volatile uint16_t fireFlyCurrCount[2] = {0, 0};
volatile uint8_t fireFlyOffTime[2] = {2, 3};
volatile uint8_t fireFlyDutyCycle[2] = {0, 0};
volatile uint8_t ffOUT[2] = {OUT_E, OUT_F};

void next(void) 
{
	if (rnd_lfsr & 1)
		rnd_lfsr = (rnd_lfsr >> 1) ^ 0x822B;
	else
		rnd_lfsr = (rnd_lfsr >> 1);
}


static uint8_t pwmList[NUM_LED_PORTS];


void SetFireInterruptHandler(void)
{
	SetLEDOffPortA(OUT_E | OUT_F);
	TMR0_SetInterruptHandler(HandleFire);
	TMR2_SetInterruptHandler(FireInterrupt);
	TMR2_StartTimer();	
	fireFlyCurrCount[0] = fireFlyCurrCount[1] = currTime;
}
void FireInterrupt(void)
{
	// Fire(onTime);
	// Fire(onTime2);
	PWM_Fire();
	//	onTime = 128;
	PWM_Fire2();
	//	onTime2 = 1;
}

void PWM_Fire( void )
{	

	uint16_t newval = (uint8_t)(rnd_lfsr & 255);

	onTime = onTime - (onTime >> 1) + (newval << 7);

	//adjust pwm values using lowpass

	for (uint8_t i = 0; i < 3; i++)
	{
		next();
		if((rnd_lfsr & 0xff) > 128)
			return;
	}
}

void PWM_Fire2( void )
{	

	uint16_t newval = (uint8_t)(rnd_lfsr & 255);

	onTime2 = onTime2 - (onTime2 >> 1) + (newval << 7); //IIR filter with lag 2

	//adjust pwm values using lowpass

	for (uint8_t i = 0; i < 1; i++)
	{
		next();
		if((rnd_lfsr & 0xff) > 128)
			return;
	}
}

void HandleFire(void)
{
	static uint8_t count = 0;
	static uint8_t count2 = 0;
	static uint8_t flyCount[2] = {0, 0};	

//handle camp fire
	if (count > (uint8_t)(onTime >> 8))
		SetLEDOffPortC(OUT_A);
	else if (count == 0)
		SetLEDOnPortC(OUT_A);
    count++;
	if (count2 > (uint8_t)(onTime2 >> 8))
		SetLEDOffPortC(OUT_B);
	else if (count2 == 0)
		SetLEDOnPortC(OUT_B);
    count2++;

//handle fire flies
    for (uint8_t i = 0; i < 2; i++)
    {
    	switch(fireFlyState[i])
    	{
    		//keep off for a random amount of time so fireflies aren't synced
    		case FF_OFF:
    			if (currTime - fireFlyCurrCount[i] >fireFlyOffTime[i])
    			{
    				fireFlyState[i] = FF_RISE;
    				fireFlyDutyCycle[i] = 0;
                    flyCount[i] = 0;
    			}
    		break;

    		//slowly increase duty cycle until we hit max brightness
    		//go from 0-100% over two seconds
    		case FF_RISE:
    			if (flyCount[i] >fireFlyDutyCycle[i])    			
    				SetLEDOffPortA(ffOUT[i]);
    			else if (flyCount[i] == 0)
    			{
    				SetLEDOnPortA(ffOUT[i]);
    				fireFlyDutyCycle[i]+=8;
    			}
    			flyCount[i]++;
    			
    			//each pwm period is 256*32uS
    			//increase the duty cycle 256 times to max brightness should
    			//take 2.097s
    			if (fireFlyDutyCycle[i] == 0)
    			{
    				fireFlyState[i] = FF_STAY;
    				fireFlyCurrCount[i] = currTime;
                    flyCount[i] = 0;
    			}
    		break;

    		case FF_STAY:
                flyCount[i] +=4;
    			if(flyCount[i] == 0)
    			{
    				fireFlyState[i] = FF_FALLING; 
                    flyCount[i] = 0;
    			}
    		break;

    		case FF_FALLING:
    			if (flyCount[i] > fireFlyDutyCycle[i])    			
    				SetLEDOffPortA(ffOUT[i]);
    			else if (flyCount[i] == 0)
    			{
    				SetLEDOnPortA(ffOUT[i]);
    				fireFlyDutyCycle[i]-=8;
    			}
    			flyCount[i]++;
    			
    			//each pwm period is 256*32uS
    			//increase the duty cycle 256 times to max brightness should
    			//take 2.097s
    			if (fireFlyDutyCycle[i] == 0)
    			{
                    SetLEDOffPortA(ffOUT[i]);
    				fireFlyState[i] = FF_OFF;
    				fireFlyCurrCount[i] = currTime;
    				//randomize the next time this light turns on
    				fireFlyOffTime[i] = 1 + (rnd_lfsr & 7);
    			}
    		break;

    		default:
    		break;
    	}
        //if they use the same random seed, they'll sync up. feels wasteful to 
        //have to generate a new random number when we're generating them constantly
        if (fireFlyOffTime[0] == fireFlyOffTime[1])
            fireFlyOffTime[0]++;
    }
}

void TurnOnPWMLEDs(uint8_t leds[])
{	
	for (uint8_t i = 0; i < NUM_LED_PORTS; i++)
	{
		pwmList[i] |= leds[i];
	}
}

void TurnOffPWMLEDs(uint8_t leds[])
{
	for (uint8_t i = 0; i < NUM_LED_PORTS; i++)
	{
		pwmList[i] &= ~leds[i];
	}
}

void TurnOffAllPWMLEDs(void)
{
	uint8_t leds[2] = {	OUT_AUX | OUT_LED | OUT_F | OUT_E, 
						OUT_C | OUT_A | OUT_B | OUT_D};
	TurnOffPWMLEDs(leds);
}

void TogglePWMLEDsOn(uint8_t leds[])
{
	uint8_t onLEDs[2];
	for (uint8_t i = 0; i < NUM_LED_PORTS; i++)
	{
		//figure out which leds have their pwm turned off
		//and need to be set on
		onLEDs[i] = pwmList[i] & leds[i];
		
		//toggle bits in pwmList
		pwmList[i] ^= leds[i];
	}
	SetLEDOn(onLEDs);
}
