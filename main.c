/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1824
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include <xc.h>
__EEPROM_DATA(0,1,6,0,0,0,0,0);
#include "led.h"
#include "pwm.h"
#include "ledblinkpatterns.h"
#include "mode.h"
#include "utility.h"
#include "input.h"
#include "globals.h"
#include "SRXL2.h"
//#include "memory.h"
#include "eusart.h"

#ifdef TEST
#include "TestLEDs.h"
#include "TestPWM.h"
#endif

void AutoDetect(void);
void SetUARTAuxChannel(void);
/*
                         Main application
 */
void main(void)
{

    // initialize the device
    SYSTEM_Initialize();
    EXT_INT_Initialize();
    TurnOnIndicatorLED();
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    BlinkIndicatorLED(VERSION_MAJOR << 1, 64);
    
    while (numBlinks != 0);

    BlinkIndicatorLED(VERSION_MINOR << 1, 32);
    while(numBlinks != 0);
     
     
    glbMode.mode = eeprom_read(0);

    //decrement mode because checkmodeswitch will increment
    glbMode.mode--;
    glbMode.buttonPressed = 1;
    CheckModeSwitch();

    while(1) 
    {
        CheckModeSwitch();

        //check inputs
        // if (glbInt.callbackFlag_CH1)
        // {
        //     HandleLastInputTime(glbInt.pulseTime_CH1);
        //     RespondToInput_CH1();
        //     glbInt.callbackFlag_CH1 = 0;
        // }

        // if (glbInt.callbackFlag_CH2)
        // {
        //     HandleLastInputTime(glbInt.pulseTime_CH2);
        //     RespondToInput_CH2();
        //     glbInt.callbackFlag_CH2 = 0;
        // }
    }
}

/**ma
 End of File
*/
