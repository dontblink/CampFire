#include "TestLEDs.h"
#include "led.h"



// void TestLEDOn(void)
// {
// 	uint8_t leds[2];
// 	leds[PORT_A] |= OUT_F | OUT_E;
// 	leds[PORT_C] |= OUT_D | OUT_C | OUT_B | OUT_A;
// 	SetLEDOn(leds);
// }

// void TestLEDOff(void)
// {
// 	uint8_t leds[2];
// 	leds[PORT_A] |= OUT_F | OUT_E;
// 	leds[PORT_C] |= OUT_D | OUT_C | OUT_B | OUT_A;	
// 	SetLEDOff(leds);
// }

// void TestToggleLED(void)
// {
// 	uint8_t leds[2];
// 	leds[PORT_A] |= OUT_F | OUT_E;
// 	leds[PORT_C] |= OUT_D | OUT_C | OUT_B | OUT_A;
	
// 	for (uint8_t j = 0; j < 2; j++)
// 	{
// 		ToggleLED(leds);
// 		for (uint8_t i = 0; i < 100; i++)
// 		{
// 			//__delay_ms(20);
// 		}
// 	}

// }

// void TestLEDs(void)
// {
// 	uint8_t i = 0;
// 	TestLEDOn();

// 	//delay for 2 seconds
// 	for (i = 0; i < 100; i++)
// 	{
// 		__delay_ms(10);
// 	}

// 	TestLEDOff();

// 	for (i = 0; i < 100; i++)
// 	{
// 		__delay_ms(10);
// 	}

// 	for (i = 0; i < 2; i++)
// 	{
// 		TestToggleLED();
// 		for (uint8_t j = 0; j < 50; j++)
// 		{
// 			__delay_ms(10);
// 		}
// 	}
// }


