/* 
 * File:   Keypad.h
 * Author: Yehu Carrington
 *
 * Created on November 17, 2018, 10:38 PM
 */

/*
 * Key Press cases.
 * (key)(4bit#) -   Function
 * (1)(0000)  -   Left in RAM
 * (2)(0001)  -   Right in RAM
 * (3)(0010)  -   Set RAM write rate Low
 * (A)(0011)  -   Set RAM write rate High
 * (4)(0100)  -   Call Temperature Read Task
 * (5)(0101)  -   Call Heart-Rate Read Task
 * (6)(0110)  -   Call Glucose Read Task
 * (B)(0111)  -   Call SPO2/Heart-Rate Variability
 * (7)(1000)  -   Call a speaker test Beep
 * (8)(1001)  -   Call an LCD Write Routine
 * (9)(1010)  -   Blink an LED to Show Keypad is working.
 * (C-D)(1011-1111) -   Unimplemented Keys.
 */

#ifndef KEYPAD_H
#define	KEYPAD_H
#include <p18f452.h>

//Configuration

#define PCB7     PORTCbits.RC7
#define PCB6     PORTCbits.RC6
#define PCB5     PORTCbits.RC5
#define PCB4     PORTCbits.RC4

void ConfigKeypad(void);
/*ConfigKeypad
 *Configures the Keypad
 */
#endif	/* KEYPAD_H */

