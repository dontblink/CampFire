/* 
 * File:   utility.h
 * Author: Marc H
 *
 * Created on February 11, 2022, 9:05 PM
 */

#ifndef UTILITY_H
#define	UTILITY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
	

volatile uint16_t currTime = 0;
volatile uint16_t lastInputTime = 0;
/* 1 second timer functions */
inline void Set_Time_Interrupt_Handler(void);
void Time_InterruptHandler(void);


#ifdef	__cplusplus
}
#endif

#endif	/* UTILITY_H */

