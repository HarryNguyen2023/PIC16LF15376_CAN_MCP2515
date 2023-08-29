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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16LF15376
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

// get/set SW1 aliases
#define SW1_TRIS                 TRISAbits.TRISA5
#define SW1_LAT                  LATAbits.LATA5
#define SW1_PORT                 PORTAbits.RA5
#define SW1_WPU                  WPUAbits.WPUA5
#define SW1_OD                   ODCONAbits.ODCA5
#define SW1_ANS                  ANSELAbits.ANSA5
#define SW1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SW1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SW1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SW1_GetValue()           PORTAbits.RA5
#define SW1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SW1_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SW1_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SW1_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define SW1_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define SW1_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define SW1_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set SW3 aliases
#define SW3_TRIS                 TRISCbits.TRISC5
#define SW3_LAT                  LATCbits.LATC5
#define SW3_PORT                 PORTCbits.RC5
#define SW3_WPU                  WPUCbits.WPUC5
#define SW3_OD                   ODCONCbits.ODCC5
#define SW3_ANS                  ANSELCbits.ANSC5
#define SW3_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SW3_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SW3_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SW3_GetValue()           PORTCbits.RC5
#define SW3_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SW3_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SW3_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SW3_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SW3_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SW3_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define SW3_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define SW3_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set INT_SENSOR aliases
#define INT_SENSOR_TRIS                 TRISCbits.TRISC7
#define INT_SENSOR_LAT                  LATCbits.LATC7
#define INT_SENSOR_PORT                 PORTCbits.RC7
#define INT_SENSOR_WPU                  WPUCbits.WPUC7
#define INT_SENSOR_OD                   ODCONCbits.ODCC7
#define INT_SENSOR_ANS                  ANSELCbits.ANSC7
#define INT_SENSOR_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define INT_SENSOR_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define INT_SENSOR_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define INT_SENSOR_GetValue()           PORTCbits.RC7
#define INT_SENSOR_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define INT_SENSOR_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define INT_SENSOR_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define INT_SENSOR_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define INT_SENSOR_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define INT_SENSOR_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define INT_SENSOR_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define INT_SENSOR_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISDbits.TRISD0
#define LED2_LAT                  LATDbits.LATD0
#define LED2_PORT                 PORTDbits.RD0
#define LED2_WPU                  WPUDbits.WPUD0
#define LED2_OD                   ODCONDbits.ODCD0
#define LED2_ANS                  ANSELDbits.ANSD0
#define LED2_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define LED2_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define LED2_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define LED2_GetValue()           PORTDbits.RD0
#define LED2_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define LED2_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set SW2 aliases
#define SW2_TRIS                 TRISDbits.TRISD1
#define SW2_LAT                  LATDbits.LATD1
#define SW2_PORT                 PORTDbits.RD1
#define SW2_WPU                  WPUDbits.WPUD1
#define SW2_OD                   ODCONDbits.ODCD1
#define SW2_ANS                  ANSELDbits.ANSD1
#define SW2_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define SW2_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define SW2_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define SW2_GetValue()           PORTDbits.RD1
#define SW2_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define SW2_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define SW2_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define SW2_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define SW2_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define SW2_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define SW2_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define SW2_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set LED3 aliases
#define LED3_TRIS                 TRISDbits.TRISD2
#define LED3_LAT                  LATDbits.LATD2
#define LED3_PORT                 PORTDbits.RD2
#define LED3_WPU                  WPUDbits.WPUD2
#define LED3_OD                   ODCONDbits.ODCD2
#define LED3_ANS                  ANSELDbits.ANSD2
#define LED3_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define LED3_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define LED3_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define LED3_GetValue()           PORTDbits.RD2
#define LED3_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define LED3_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define LED3_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define LED3_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define LED3_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define LED3_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define LED3_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set cSTBY aliases
#define cSTBY_TRIS                 TRISDbits.TRISD4
#define cSTBY_LAT                  LATDbits.LATD4
#define cSTBY_PORT                 PORTDbits.RD4
#define cSTBY_WPU                  WPUDbits.WPUD4
#define cSTBY_OD                   ODCONDbits.ODCD4
#define cSTBY_ANS                  ANSELDbits.ANSD4
#define cSTBY_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define cSTBY_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define cSTBY_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define cSTBY_GetValue()           PORTDbits.RD4
#define cSTBY_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define cSTBY_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define cSTBY_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define cSTBY_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define cSTBY_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define cSTBY_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define cSTBY_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define cSTBY_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set CS aliases
#define CS_TRIS                 TRISDbits.TRISD7
#define CS_LAT                  LATDbits.LATD7
#define CS_PORT                 PORTDbits.RD7
#define CS_WPU                  WPUDbits.WPUD7
#define CS_OD                   ODCONDbits.ODCD7
#define CS_ANS                  ANSELDbits.ANSD7
#define CS_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define CS_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define CS_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define CS_GetValue()           PORTDbits.RD7
#define CS_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define CS_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define CS_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define CS_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define CS_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define CS_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define CS_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define CS_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISEbits.TRISE0
#define LED1_LAT                  LATEbits.LATE0
#define LED1_PORT                 PORTEbits.RE0
#define LED1_WPU                  WPUEbits.WPUE0
#define LED1_OD                   ODCONEbits.ODCE0
#define LED1_ANS                  ANSELEbits.ANSE0
#define LED1_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define LED1_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define LED1_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define LED1_GetValue()           PORTEbits.RE0
#define LED1_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define LED1_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELEbits.ANSE0 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELEbits.ANSE0 = 0; } while(0)

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


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF7 pin functionality
 * @Example
    IOCCF7_ISR();
 */
void IOCCF7_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF7 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF7 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF7_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF7_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF7 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF7_SetInterruptHandler() method.
    This handler is called every time the IOCCF7 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF7_SetInterruptHandler(IOCCF7_InterruptHandler);

*/
extern void (*IOCCF7_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF7 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF7_SetInterruptHandler() method.
    This handler is called every time the IOCCF7 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF7_SetInterruptHandler(IOCCF7_DefaultInterruptHandler);

*/
void IOCCF7_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/