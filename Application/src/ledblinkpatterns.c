#include "ledblinkpatterns.h"
#include "pwm.h"
#include "led.h"
#include "tmr0.h"
#include "tmr2.h"
#include "tmr4.h"
#include "tmr6.h"
#include "globals.h"
#include "utility.h"



void Set10msInterrupt(void)
{
	// PR6 77; 
    PR6 = 0x4D;

    // TMR6 0; 
    TMR6 = 0x00;

    // Clearing IF flag before enabling the interrupt.
    PIR3bits.TMR6IF = 0;

    // Enabling TMR6 interrupt.
    PIE3bits.TMR6IE = 1;
    
    // T6CKPS 1:64; T6OUTPS 1:16; TMR6ON on; 
    T6CON = 0x7F;       	
}

void SetTurnSignalInterrupt(void)
{
    // PR6 207; 
    PR6 = 0xCF;

    // TMR6 0; 
    TMR6 = 0x00;

    // Clearing IF flag before enabling the interrupt.
    PIR3bits.TMR6IF = 0;

    // Enabling TMR6 interrupt.
    PIE3bits.TMR6IE = 1;

    // Set Default Interrupt Handler
    //TMR6_SetInterruptHandler(TMR6_DefaultInterruptHandler);

    // T6CKPS 1:64; T6OUTPS 1:16; TMR6ON on; 
    T6CON = 0x7F;	
}

void ResetTimers(void)
{
	glbLED.count = 0;
	glbLED.timer2_count = 0;
	glbLED.timer6_count = 0;

	TMR2_StopTimer();
	TMR6_StopTimer();
	TMR2_WriteTimer(0);
	TMR6_WriteTimer(0);
}

void ResetMode(void)
{
	TurnOffAllPWMLEDs();
	TMR0_SetInterruptHandler(TMR0_DefaultInterruptHandler);
	//SetAllLEDOff();
	glbLED.currentLED = OUT_A;
	glbLED.strobeState	 = 0;
	glbLED.isBackfire = 0;
	glbLED.turnBlinkDim = 0;
	glbLED.excludeTurn = 0;
	glbLED.combinedTurn = 0;
	glbMode.interruptSet_CH2 = 0;
	glbMode.interruptSet_CH1 = 0;
	//glbMode.hazardModeOn = 0;
	//glbMode.lastHazardSet = 0;
	glbMode.overrideCH = 0;
	glbMode.crawlerModes = 0;
	ResetTimers();
	//lastInputTime = currTime;
}

