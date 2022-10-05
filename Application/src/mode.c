#include "mode.h"
#include "ledblinkpatterns.h"
#include "led.h"
#include "pwm.h"
#include "tmr0.h"
#include "tmr2.h"
#include "tmr4.h"
#include "tmr6.h"
#include "ext_int.h"
#include "globals.h"
#include "utility.h"
#include "memory.h"
#include "interrupt_manager.h"
#include "eccp2.h"

void (*CurrentModeSetup)(void);
void (*RespondToInput_CH1)(void);
void (*RespondToInput_CH2)(void);
void (*RestoreRespondToInput_CH1)(void);
void (*RestoreRespondToInput_CH2)(void);

inline void SetupButtonInterrupt(void)
{
	INT_SetInterruptHandler(ButtonInterrupt);
}

void CheckModeSwitch(void)
{

	if (glbMode.buttonPressed)
	{
		glbMode.buttonPressed = 0;

		if(++glbMode.mode == NUM_MODES)
			glbMode.mode = 0;

		//~150ms
		//don't blink for mode 0
		eeprom_write(0, glbMode.mode);
		
		if (glbMode.mode)
			BlinkIndicatorLED(glbMode.mode << 1, 4);

		SetMode(glbMode.mode);
	}
}

void SetMode(uint8_t Mode)
{
	glbMode.hazardModeOn = 0;
	lastInputTime = currTime;
	ResetMode();	

	// //enable/disable ch2 if uart is enabled and based on mode
	// if (glbInt.useUART)
	// {
	// 	if ((1 << glbMode.mode) & 0x00f0)
	// 	{
	// 		ECCP2_Initialize();
	// 	}
	// 	else
	// 	{
	// 		ECCP2_DeInitialize();
	// 	}
	// }

	switch(Mode)
	{
		case 0:
			//CurrentModeSetup = SetupMode2;			
			CurrentModeSetup = SetAllLEDOff;			
		break;
		
		case 1:
			CurrentModeSetup = SetAllLEDOn;			
		break;
		
		case 2:
			 CurrentModeSetup = SetupMode2;			
		break;
		
		case 3:
			// CurrentModeSetup = SetupMode3;			
		break;
		
		case 4:
			// CurrentModeSetup = SetupMode4;			
		break;
		
		case 5:
			// CurrentModeSetup = SetupMode5;			
		break;
		
		case 6:
			// CurrentModeSetup = SetupMode9;			
		break;

		case 7:
			// CurrentModeSetup = SetupMode10;			
		break;

		case 8:
			// CurrentModeSetup = SetupMode6;			
		break; 
		
		case 9:
			// CurrentModeSetup = SetupMode7;			
		break;
		
		case 10:			
			// CurrentModeSetup = SetupMode8;			
		break;


	}
	
	//run the mode setup if the mode is valid
	CurrentModeSetup();
}

void InitializeMode(uint8_t * ledOn, uint8_t * ledOff, uint8_t * pwmOn)
{
	TurnOnPWMLEDs(pwmOn);
	TurnOffPWMLEDs( (uint8_t[]){~pwmOn[0], ~pwmOn[1]} );
	SetLEDOn(ledOn);
	SetLEDOff(ledOff);
}



//basher/crawler (for vehicles with brakes)
void SetupMode2(void)
{
	SetFireInterruptHandler();
	SetLEDOnPortC(OUT_C | OUT_D);
	SetLEDOnPortA(OUT_AUX);
	//A off, B Dim, C Slow Blink, D Dim, E ON F Off
	// InitializeMode(	(uint8_t[]){0, 0},
	// 				(uint8_t[]){OUT_AUX | OUT_E | OUT_F, OUT_A},
	// 				(uint8_t[]){0, OUT_B | OUT_D});
	// SetupSlowBlink();
	// SetCrawlerMode();
}

