/**
   EXT_INT Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     ext_int.c
 
   @Summary
     This is the generated driver implementation file for the EXT_INT driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs
 
   @Description
     This source file provides implementations for driver APIs for EXT_INT.
     Generation Information :
         Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
         Device            :  PIC16F1824
         Driver Version    :  1.11
     The generated drivers are tested against the following:
         Compiler          :  XC8 2.31 and above
         MPLAB             :  MPLAB X 5.45
 */ 

 /**
   Section: Includes
 */
#include <xc.h>
#include "ext_int.h"
#include "globals.h"
#include "utility.h"
#include "led.h"
//void (*INT_InterruptHandler)(void);

void ButtonInterrupt(void)
{
    static uint16_t startTime = 0;

    //on button press, start timer, set
    //interrupt to rising edge
    if (!OPTION_REGbits.INTEDG)
    {
        if(!glbMode.debounce)
        {
            //button pressed
            startTime = currTime;

            //set to rising edge
            EXT_INT_risingEdgeSet();
        }

    }
    else
    {
        //on button released, find how long the button has been pressed
        //toggle hazard mode if its >= 3s
        //otherwise, change mode
        //reset interrupt on falling edge       
        if ((currTime - startTime) >= 3)
        {
            //glbMode.buttonPressed = 1;
            glbMode.toggleHazardMode = !glbMode.toggleHazardMode;
        }
        else
        {
            glbMode.buttonPressed = 1;
        }
        EXT_INT_fallingEdgeSet();

        glbMode.debounce = 10;

    }

}

void INT_ISR(void)
{
    // Callback function gets called everytime this ISR executes
    // INT_CallBack();
    ButtonInterrupt();
    //INT_InterruptHandler();    
    EXT_INT_InterruptFlagClear();

}

void EXT_INT_Initialize(void)
{
    
    // Clear the interrupt flag
    // Set the external interrupt edge detect
    EXT_INT_InterruptFlagClear();   
    EXT_INT_fallingEdgeSet();    
    EXT_INT_InterruptEnable();      

}

// uint8_t isRisingEdge(void)
// {
//     return OPTION_REGbits.INTEDG;
// }
