/* 
 * File:   Modules.h
 * Author: 815008434
 *
 * Created on November 12, 2019, 3:53 PM
 */

#ifndef MODULES_H
#define	MODULES_H

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

void KeyPressInterrupt(void);

/******************HEART RATE MODULE********************/
void heartRateModule(void);
void timer10sIsr(void);
void bpmCountIsr(void);
//void hrVarTmrIsr(void);

/***********************SPEAKER MODULE**************************/
void initSpeakerModule(void);
void bpmAlert(void);

/***********************TEMPRATURE MODULE***********************/
#define OW_LAT LATBbits.LATB4
#define OW_PIN PORTBbits.RB4
#define OW_TRIS TRISBbits.TRISB4

#define OUTPUT 0
#define INPUT 1

unsigned char initSequence(void);
void writeByte(unsigned char data);
char readByte(void);

/***************************BOR Modules*************************/
void LVDisr (void);
void configBOR (void);



#endif	/* MODULES_H */

