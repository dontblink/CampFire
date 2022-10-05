#include "input.h"
#include "eccp1.h"
#include "eccp2.h"

static uint16_t startTime_CH1 = 0;
static uint16_t startTime_CH2 = 0;

inline void CH1_InterruptHandler(uint16_t captureValue)
{
	if (ECCP1_IsRisingEdge())
	{
		startTime_CH1 = captureValue;
		ECCP1_SetFallingEdge();
	}
	else
	{		
		if (glbInt.callbackFlag_CH1 == 0)
		{
			glbInt.pulseTime_CH1 = captureValue - startTime_CH1;
			glbInt.callbackFlag_CH1 = 1;
		}
		ECCP1_SetRisingEdge();
		//set callback flag so main can act on input info
	}	
	// CHX_Handler( captureValue, 
	//              ECCP1_SetRisingEdge,
	//              ECCP1_SetFallingEdge,
	//              ECCP1_IsRisingEdge,
	//              &startTime_CH1,
	//              &glbInt.pulseTime_CH1,
	//              &glbInt.callbackFlag_CH1);
}

inline void CH2_InterruptHandler(uint16_t captureValue)
{
	if (ECCP2_IsRisingEdge())
	{
		startTime_CH2 = captureValue;
		ECCP2_SetFallingEdge();
	}
	else
	{		
		if (glbInt.callbackFlag_CH2 == 0)
		{
			glbInt.pulseTime_CH2 = captureValue - startTime_CH2;
			glbInt.callbackFlag_CH2 = 1;
		}
		ECCP2_SetRisingEdge();
		//set callback flag so main can act on input info
	}
	// CHX_Handler( captureValue, 
	//              ECCP2_SetRisingEdge,
	//              ECCP2_SetFallingEdge,
	//              ECCP2_IsRisingEdge,
	//              &startTime_CH2,
	//              &glbInt.pulseTime_CH2,
	//              &glbInt.callbackFlag_CH2);
}

void CHX_Handler(uint16_t captureValue,
                 void (*SetRisingEdge)(void),
                 void (*SetFallingEdge)(void),
                 uint8_t (*IsRisingEdge)(void),
                 uint16_t * startTime,
                 uint16_t * pulseTime,
                 uint8_t * callbackFlag)
{
	if (IsRisingEdge())
	{
		*startTime = captureValue;
		SetFallingEdge();
	}
	else
	{		
		if (*callbackFlag == 0)
		{
			*pulseTime = captureValue - *startTime;
			*callbackFlag = 1;
		}
		SetRisingEdge();
		//set callback flag so main can act on input info
	}
}
