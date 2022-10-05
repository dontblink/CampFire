/**
  ECCP2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    eccp2.c

  @Summary
    This is the generated driver implementation file for the ECCP2 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides implementations for driver APIs for ECCP2.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1824
        Driver Version    :  2.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
         MPLAB 	          :  MPLAB X 5.45
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "eccp2.h"
#include "input.h"

/**
  Section: Capture Module APIs:
*/

void ECCP2_Initialize(void)
{
    // Set the ECCP2 to the options selected in the User Interface
	
	// CCP2M Every rising edge; DC2B 0; P2M single; 
	CCP2CON = 0x05;    
	
	// CCPR2H 0; 
	CCPR2H = 0x00;    
	
	// CCPR2L 0; 
	CCPR2L = 0x00;    
    
    // Clear the ECCP2 interrupt flag
    PIR2bits.CCP2IF = 0;

    // Enable the ECCP2 interrupt
    PIE2bits.CCP2IE = 1;
	
}

void ECCP2_DeInitialize(void)
{
    PIE2bits.CCP2IE = 0;
}

void ECCP2_CaptureISR(void)
{
    CCP2_PERIOD_REG_T module;

    // Clear the ECCP2 interrupt flag
    PIR2bits.CCP2IF = 0;
    
    // Copy captured value.
    module.ccpr2l = CCPR2L;
    module.ccpr2h = CCPR2H;
    
    // Return 16bit captured value
    CH2_InterruptHandler(module.ccpr2_16Bit);
}

inline void ECCP2_SetRisingEdge(void)
{
    CCP2CON = 0x05;  
}

inline void ECCP2_SetFallingEdge(void)
{
    CCP2CON = 0x04;  
}

inline uint8_t ECCP2_IsRisingEdge(void)
{
    return (CCP2CON == 0x05);
}
/**
 End of File
*/
