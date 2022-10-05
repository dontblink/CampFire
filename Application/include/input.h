/* 
 * File:   input.h
 * Author: Marc H
 *
 * Created on February 17, 2022, 5:49 PM
 */

#ifndef INPUT_H
#define	INPUT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "globals.h"


inline void SetCH1InterruptHandler(void);
inline void CH1_InterruptHandler(uint16_t captureValue);

inline void SetCH2InterruptHandler(void);
inline void CH2_InterruptHandler(uint16_t captureValue);

void CHX_Handler(uint16_t captureValue,
                 void (*SetRisingEdge)(void),
                 void (*SetFallingEdge)(void),
                 uint8_t (*IsRisingEdge)(void),
                 uint16_t * startTime,
                 uint16_t * pulseTime,
                 uint8_t * callbackFlag);


#ifdef	__cplusplus
}
#endif

#endif	/* INPUT_H */

