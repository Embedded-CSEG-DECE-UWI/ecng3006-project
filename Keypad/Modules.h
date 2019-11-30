<<<<<<< HEAD
/* 
 * File:   Modules.h
 * Author: 815008434
 *
 * Created on November 11, 2019, 7:01 PM
 * Edited on November 28, 2019, 11:01 PM
 */

#ifndef MODULES_H
#define	MODULES_H

#include    <p18f452.h>
#include    <delays.h>
#include    "FreeRTOS.h"
#include    <semphr.h>
#include    <queue.h>

/*****GLOBAL SEMAPHORE/QUEUE VARIABLES*****/

extern SemaphoreHandle_t keypadSem;

/**********KEYPAD MODULE**********/

/*
 * Key Press cases.
 * (key)(4bit#) -   Function
 * (1)(0000)  -   Select
 * (2)(0001)  -   
 * (3)(0010)  -   
 * (A)(0011)  -   
 * (4)(0100)  -   
 * (5)(0101)  -   
 * (6)(0110)  -   
 * (B)(0111)  -   
 * (7)(1000)  -   
 * (8)(1001)  -   
 * (9)(1010)  -  
 * (C)(1011)  -
 * (0)(1100)  -   
 * (F)(1101)  -
 * (E)(1110)  -
 * (D)(1111)  -
 */

/*CONFIGURATION*/

#define BIT0    PORTCbits.RC4
#define BIT1    PORTCbits.RC5
#define BIT2    PORTCbits.RC6
#define BIT3    PORTCbits.RC7

/*VARIABLE DECLARATIONS*/

/*
 * configKeypad
 * 
 * configures the keypad by enabling the RB0 interrupt
 * and setting the TRISC upper nibble as inputs
 */
void configKeypad(void);

void keypadTask(void *pvParameter);

void keypadISR(void);

#endif	/* MODULES_H */

=======
/* 
 * File:   Modules.h
 * Author: 815008434
 *
 * Created on November 11, 2019, 7:01 PM
 * Edited on November 28, 2019, 11:01 PM
 */

#ifndef MODULES_H
#define	MODULES_H

#include    <p18f452.h>
#include    <delays.h>
#include    "FreeRTOS.h"
#include    <semphr.h>
#include    <queue.h>

/*****GLOBAL SEMAPHORE/QUEUE VARIABLES*****/

extern SemaphoreHandle_t keypadSem;

/**********KEYPAD MODULE**********/

/*
 * Key Press cases.
 * (key)(4bit#) -   Function
 * (1)(0000)  -   Select
 * (2)(0001)  -   
 * (3)(0010)  -   
 * (A)(0011)  -   
 * (4)(0100)  -   
 * (5)(0101)  -   
 * (6)(0110)  -   
 * (B)(0111)  -   
 * (7)(1000)  -   
 * (8)(1001)  -   
 * (9)(1010)  -  
 * (C)(1011)  -
 * (0)(1100)  -   
 * (F)(1101)  -
 * (E)(1110)  -
 * (D)(1111)  -
 */

/*CONFIGURATION*/

#define BIT0    PORTCbits.RC4
#define BIT1    PORTCbits.RC5
#define BIT2    PORTCbits.RC6
#define BIT3    PORTCbits.RC7

/*VARIABLE DECLARATIONS*/

/*
 * configKeypad
 * 
 * configures the keypad by enabling the RB0 interrupt
 * and setting the TRISC upper nibble as inputs
 */
void configKeypad(void);

void keypadTask(void *pvParameter);

void keypadISR(void);

#endif	/* MODULES_H */

>>>>>>> b587c5aa9c9fcf01a242fc30d0430e5349df2f53
