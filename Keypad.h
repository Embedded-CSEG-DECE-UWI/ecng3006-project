/* 
 * File:   Keypad.h
 * Author: Yehu Carrington - 815008434
 *
 * Created on November 5, 2019, 7:28 PM
 */

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


#ifndef KEYPAD_H
#define	KEYPAD_H

#include    <p18f452.h>
#include    "FreeRTOS.h"
#include    <semphr.h>

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
void configKeypad ( void );


void keypadISR ( void );
#endif	/* KEYPAD_H */

