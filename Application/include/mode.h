#ifndef MODE_H
#define MODE_H

#include <stdint.h>

#define NUM_MODES 3
#define CENTERBRAKE 1
#define NO_CENTERBRAKE 0

void (*CurrentModeSetup)(void);
void (*RespondToInput_CH1)(void);
void (*RespondToInput_CH2)(void);


void HandleReverse(void);
void HandleReverseNoBrakes(void);
void HandleBrake(uint8_t centerBrake);
void HandleBrakeNO(void);
void HandleTurnSignals(void);

//inline void SetupButtonInterrupt(void);
//void ButtonInterrupt(void);

void CheckModeSwitch(void);
void SetMode(uint8_t Mode);

//void RespondToInputsTurn_CH1(void);
inline void RespondToInputsTurn_CH2(void);
inline void RespondToInputsNoResponse_CHX(void);

void InitializeMode(uint8_t * ledOn, uint8_t * ledOff, uint8_t * pwmOn);
void SetupMode0(void);
//void RespondToInputsMode0_CH1(void);
void RespondToInputsMode0_CH2(void);

void SetupMode1(void);
//void RespondToInputsMode1_CH1(void);
void RespondToInputsMode1_CH2(void);

void SetCrawlerMode(void);
void SetupMode2(void);
void RespondToInputsMode2_CH1(void);
void RespondToInputsMode2_CH2(void);

void SetupMode3(void);
void RespondToInputsMode3_CH1(void);
//void RespondToInputsMode3_CH2(void);

void SetupMode4(void);
// void RespondToInputsMode4_CH1(void);
// void RespondToInputsMode4_CH2(void);

void SetupMode5(void);
// void RespondToInputsMode5_CH1(void);
// void RespondToInputsMode5_CH2(void);

void SetupMode6(void);
void RespondToInputsMode6_CH1(void);
void RespondToInputsMode6_CH2(void);

void SetupMode7(void);
void RespondToInputsMode7_CH1(void);
void RespondToInputsMode7_CH2(void);

void SetupMode8(void);
//void RespondToInputsMode8_CH1(void);
//void RespondToInputsMode8_CH2(void);

void SetupMode9(void);
// void RespondToInputsMode9_CH1(void);
// void RespondToInputsMode9_CH2(void);

void SetupMode10(void);
// void RespondToInputsMode10_CH1(void);
// void RespondToInputsMode10_CH2(void);

void CheckHazard(void);
//void HazardRespondToInput(uint16_t);
void ExitHazard(void);

void HandleLastInputTime(uint16_t pulse);
#endif /* MODE_H */
