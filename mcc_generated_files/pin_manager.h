/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1824
        Driver Version    :  2.11
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set TOP aliases
#define TOP_TRIS                 TRISAbits.TRISA0
#define TOP_LAT                  LATAbits.LATA0
#define TOP_PORT                 PORTAbits.RA0
#define TOP_WPU                  WPUAbits.WPUA0
#define TOP_ANS                  ANSELAbits.ANSA0
#define TOP_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define TOP_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define TOP_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define TOP_GetValue()           PORTAbits.RA0
#define TOP_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define TOP_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define TOP_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define TOP_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define TOP_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define TOP_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set LED_1 aliases
#define LED_1_TRIS                 TRISAbits.TRISA1
#define LED_1_LAT                  LATAbits.LATA1
#define LED_1_PORT                 PORTAbits.RA1
#define LED_1_WPU                  WPUAbits.WPUA1
#define LED_1_ANS                  ANSELAbits.ANSA1
#define LED_1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LED_1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LED_1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LED_1_GetValue()           PORTAbits.RA1
#define LED_1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LED_1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LED_1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define LED_1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define LED_1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define LED_1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set SW_1 aliases
#define SW_1_TRIS                 TRISAbits.TRISA2
#define SW_1_LAT                  LATAbits.LATA2
#define SW_1_PORT                 PORTAbits.RA2
#define SW_1_WPU                  WPUAbits.WPUA2
#define SW_1_ANS                  ANSELAbits.ANSA2
#define SW_1_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define SW_1_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define SW_1_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define SW_1_GetValue()           PORTAbits.RA2
#define SW_1_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define SW_1_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define SW_1_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define SW_1_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define SW_1_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define SW_1_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set IO_RA4 aliases
#define IO_RA4_TRIS                 TRISAbits.TRISA4
#define IO_RA4_LAT                  LATAbits.LATA4
#define IO_RA4_PORT                 PORTAbits.RA4
#define IO_RA4_WPU                  WPUAbits.WPUA4
#define IO_RA4_ANS                  ANSELAbits.ANSA4
#define IO_RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define IO_RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define IO_RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define IO_RA4_GetValue()           PORTAbits.RA4
#define IO_RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define IO_RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define IO_RA4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define IO_RA4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define IO_RA4_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define IO_RA4_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set IO_RA5 aliases
#define IO_RA5_TRIS                 TRISAbits.TRISA5
#define IO_RA5_LAT                  LATAbits.LATA5
#define IO_RA5_PORT                 PORTAbits.RA5
#define IO_RA5_WPU                  WPUAbits.WPUA5
#define IO_RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define IO_RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define IO_RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define IO_RA5_GetValue()           PORTAbits.RA5
#define IO_RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define IO_RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define IO_RA5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define IO_RA5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)

// get/set GRPD aliases
#define GRPD_TRIS                 TRISCbits.TRISC0
#define GRPD_LAT                  LATCbits.LATC0
#define GRPD_PORT                 PORTCbits.RC0
#define GRPD_WPU                  WPUCbits.WPUC0
#define GRPD_ANS                  ANSELCbits.ANSC0
#define GRPD_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define GRPD_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define GRPD_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define GRPD_GetValue()           PORTCbits.RC0
#define GRPD_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define GRPD_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define GRPD_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define GRPD_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define GRPD_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define GRPD_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set TL aliases
#define TL_TRIS                 TRISCbits.TRISC1
#define TL_LAT                  LATCbits.LATC1
#define TL_PORT                 PORTCbits.RC1
#define TL_WPU                  WPUCbits.WPUC1
#define TL_ANS                  ANSELCbits.ANSC1
#define TL_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define TL_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define TL_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define TL_GetValue()           PORTCbits.RC1
#define TL_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define TL_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define TL_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define TL_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define TL_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define TL_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set GRPC aliases
#define GRPC_TRIS                 TRISCbits.TRISC2
#define GRPC_LAT                  LATCbits.LATC2
#define GRPC_PORT                 PORTCbits.RC2
#define GRPC_WPU                  WPUCbits.WPUC2
#define GRPC_ANS                  ANSELCbits.ANSC2
#define GRPC_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define GRPC_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define GRPC_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define GRPC_GetValue()           PORTCbits.RC2
#define GRPC_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define GRPC_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define GRPC_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define GRPC_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define GRPC_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define GRPC_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set CH2_PWM aliases
#define CH2_PWM_TRIS                 TRISCbits.TRISC3
#define CH2_PWM_LAT                  LATCbits.LATC3
#define CH2_PWM_PORT                 PORTCbits.RC3
#define CH2_PWM_WPU                  WPUCbits.WPUC3
#define CH2_PWM_ANS                  ANSELCbits.ANSC3
#define CH2_PWM_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define CH2_PWM_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define CH2_PWM_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define CH2_PWM_GetValue()           PORTCbits.RC3
#define CH2_PWM_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define CH2_PWM_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define CH2_PWM_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define CH2_PWM_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define CH2_PWM_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define CH2_PWM_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set GRPB aliases
#define GRPB_TRIS                 TRISCbits.TRISC4
#define GRPB_LAT                  LATCbits.LATC4
#define GRPB_PORT                 PORTCbits.RC4
#define GRPB_WPU                  WPUCbits.WPUC4
#define GRPB_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define GRPB_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define GRPB_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define GRPB_GetValue()           PORTCbits.RC4
#define GRPB_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define GRPB_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define GRPB_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define GRPB_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)

// get/set CH1_PWM aliases
#define CH1_PWM_TRIS                 TRISCbits.TRISC5
#define CH1_PWM_LAT                  LATCbits.LATC5
#define CH1_PWM_PORT                 PORTCbits.RC5
#define CH1_PWM_WPU                  WPUCbits.WPUC5
#define CH1_PWM_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define CH1_PWM_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define CH1_PWM_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define CH1_PWM_GetValue()           PORTCbits.RC5
#define CH1_PWM_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define CH1_PWM_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define CH1_PWM_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define CH1_PWM_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/