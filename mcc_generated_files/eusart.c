/**
  EUSART Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    eusart.c

  @Summary
    This is the generated driver implementation file for the EUSART driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for EUSART.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1824
        Driver Version    :  2.1.1
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
#include "eusart.h"
/**
  Section: Macro Declarations
*/

#define EUSART_RX_BUFFER_SIZE 8 

/**
  Section: Global Variables
*/

volatile uint8_t eusartRxHead = 0;
volatile uint8_t eusartRxTail = 0;
volatile uint8_t eusartRxBuffer[EUSART_RX_BUFFER_SIZE];
volatile uint8_t eusartRxCount;

/**
  Section: EUSART APIs
*/
void (*EUSART_RxDefaultInterruptHandler)(void);

void EUSART_Initialize(void)
{
    // disable interrupts before changing states
    PIE1bits.RCIE = 0;
    EUSART_RxDefaultInterruptHandler = EUSART_RxDataHandler;
    //EUSART_SetRxInterruptHandler(EUSART_RxDataHandler);
    // Set the EUSART module to the options selected in the user interface.

    // ABDOVF no_overflow; SCKP Non-Inverted; BRG16 16bit_generator; WUE disabled; ABDEN disabled; 
    BAUDCON = 0x08;

    // SPEN enabled; RX9 8-bit; CREN enabled; ADDEN disabled; SREN disabled; 
    RCSTA = 0x90;

    // TX9 8-bit; TX9D 0; SENDB sync_break_complete; TXEN disabled; SYNC asynchronous; BRGH hi_speed; CSRC slave; 
    TXSTA = 0x04;

    // SPBRGL 68; 
    SPBRGL = 0x44;

    // SPBRGH 0; 
    SPBRGH = 0x00;

    eusartRxHead = 0;
    eusartRxTail = 0;
    eusartRxCount = 0;

    // enable receive interrupt
    PIE1bits.RCIE = 1;
}

void EUSART_DeInitialize(void)
{
    PIE1bits.RCIE = 0;
    RCSTAbits.CREN = 0;
    RCSTAbits.SPEN = 0;
}

bool EUSART_is_rx_ready(void)
{
    return (eusartRxCount ? true : false);
}

uint8_t EUSART_Read(void)
{
    uint8_t readValue  = 0;

    //we're explicitly validating rxCount before reading, this is unecessary    
    // while(0 == eusartRxCount)
    // {
    // }

    readValue = eusartRxBuffer[eusartRxTail++];
    if(EUSART_RX_BUFFER_SIZE <= eusartRxTail)
    {
        eusartRxTail = 0;
    }
    //PIE1bits.RCIE = 0;
    eusartRxCount--;
    //PIE1bits.RCIE = 1;

    return readValue;
}

void EUSART_RxDataHandler(void){
    // use this default receive interrupt handler code
    uint8_t err = 0;
    if (RCSTAbits.FERR)
    {
        RCREG;
        err = 1;
    }
    if (RCSTAbits.OERR)
    {
        RCSTAbits.CREN = 0;
        RCSTAbits.CREN = 1;
        RCREG;
        RCREG;
        err = 1;
    }
    
    if (!err)
    {
        eusartRxBuffer[eusartRxHead++] = RCREG;
        if(EUSART_RX_BUFFER_SIZE <= eusartRxHead)
        {
            eusartRxHead = 0;
        }
        eusartRxCount++;
    }
}

// void EUSART_SetRxInterruptHandler(void (* interruptHandler)(void)){
//     EUSART_RxDefaultInterruptHandler = interruptHandler;
//}
/**
  End of File
*/
