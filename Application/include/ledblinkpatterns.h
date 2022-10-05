#ifndef LEDBLINKPATTERNS_H
#define LEDBLINKPATTERNS_H

#include <stdint.h>

#define RIGHT_TURN 0
#define LEFT_TURN 1

void Set10msInterrupt(void);
void SetTurnSignalInterrupt(void);
void ResetTurnSignal(void);
void SetTurnSignalInterruptConfig(uint8_t turn);
void SetTurn(uint8_t turn);
void SetDimTurnBlink(uint8_t blink);
void TurnSignalInterrupt(void);

void SetupSlowBlink(void);
void SlowBlinkInterrupt(void);

void SetupWigWagAndStrobe(void);
void WigWagAndStrobeInterrupt(void);
void WigWagInterrupt(void);

void BackFireInterrupt(void);

void HazardLightsSetup(void);
void HazardLightsInterrupt(void);

void ResetTimers(void);
void ResetMode(void);



#endif /* LEDBLINKPATTERNS_H */
