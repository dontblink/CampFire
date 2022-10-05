/* 
 * File:   SRXL2.h
 * Author: Marc H
 *
 * Created on March 8, 2022, 3:38 PM
 */

#ifndef SRXL2_H
#define	SRXL2_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>

#define STATE_START_1       0
#define STATE_START_2       1
#define STATE_LENGTH        2
#define STATE_COMMAND       3
#define STATE_REPLYID       4
#define STATE_RSSI          5
#define STATE_FRAMELOSS_1   6
#define STATE_FRAMELOSS_2   7
#define STATE_CHANNELMASK_1 8
#define STATE_CHANNELMASK_2 9
#define STATE_CHANNELMASK_3 10
#define STATE_CHANNELMASK_4 11
#define STATE_PAYLOAD_1     12
#define STATE_PAYLOAD_2     13
#define STATE_CRC_1         14
#define STATE_CRC_2         15

inline void SetSRLX2Interrupt(void);
uint8_t getLastVal(void);
void SRXL2_StateMachine(void);
void CalcCRC(uint8_t val);
void ConvertUARTValues(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SRXL2_H */

