// #include "TestPWM.h"
// #include "tmr0.h"
// #include "pwm.h"

// void TestPWM(void)
// {	
// 	Set_PWM_InterruptHandler();
// 	//TMR0_StartTimer();
// 	uint8_t leds[2];
// 	leds[PORT_A] |= OUT_F | OUT_E;
// 	leds[PORT_C] |= OUT_D | OUT_C | OUT_B | OUT_A;	

// 	TurnOnPWMLEDs(leds);

// 	for (uint8_t i = 0; i < 100; i++)
// 		__delay_ms(10);

// 	TurnOffPWMLEDs(leds);
//     SetLEDOn(leds);

// 	for (uint8_t i = 0; i < 100; i++)
// 		__delay_ms(10);	

// 	SetLEDOff(leds);
// }
