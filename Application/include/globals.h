#ifndef GLOBALS_H
#define GLOBALS_H

#define _XTAL_FREQ 32000000

//these were all originally static variables
typedef struct GlobalInputs
{
	//taken from input
	uint16_t pulseTime_CH1;
	uint16_t pulseTime_CH2;
	uint8_t callbackFlag_CH1;
	uint8_t callbackFlag_CH2;
	uint8_t useCH1;
	uint8_t useCH2;
	uint8_t useUART;

}GlobalInputs_t;

typedef struct GlobalMode
{
	//taken from mode
	uint16_t reverseTimeout;
	uint16_t lastThrottleBackfire;
	uint8_t buttonPressed;
	uint8_t toggleHazardMode;
	uint8_t interruptSet_CH1;
	uint8_t interruptSet_CH2;
	uint8_t reverseState;
	uint8_t mode;
	uint8_t hazardModeOn;
	uint8_t lastHazardSet;
	uint8_t debounce;
	uint8_t overrideCH;
	uint8_t crawlerModes;
}GlobalMode_t;

typedef struct GlobalLEDBlink
{
	//taken from ledblinkpatterns
	uint8_t count;
	uint8_t count2;
	uint8_t timer2_count;
	uint8_t timer6_count;
	uint8_t strobeState;

	uint8_t currentLED;


	uint8_t turnLEDs[2];
	uint8_t isBackfire;
	uint8_t turnBlinkDim;
	uint8_t excludeTurn;
	uint8_t combinedTurn;

}GlobalLEDBlink_t;

typedef struct GlobalComm
{
	//from SRXL2
	uint32_t channelMask;
	uint32_t UARTCallbackChannels;
	uint16_t UART_CH[3];
	uint16_t tempValue;
	uint16_t crc;
	uint8_t UARTCallback;

	uint8_t state;
	uint8_t payloadCh;
	uint8_t numChannels;
	uint8_t auxChannel;

}GlobalComm_t;

volatile GlobalInputs_t glbInt;
volatile GlobalMode_t glbMode;
volatile GlobalLEDBlink_t glbLED;
volatile GlobalComm_t glbComm;

#define VERSION_MAJOR 1
#define VERSION_MINOR 1
#endif /* GLOBALS_H */
