#include <delays.h>
#include <timers.h>
#include <stdlib.h>
#include <stdio.h>
#include <p18f452.h>
#include "xlcd.h"

/*Set configuration bits for use with PICKit3 and 4MHz oscillator*/
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

/*Defining a new data type with two states called boolean with additional key-words*/
typedef int bool;               
#define true 1
#define false 0;

char lcdVariable[20];                                   //array that will contain the pulse count to display on the LCD

void DelayFor18TCY(void){
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();         
}
 
void DelayXLCD(void){                                   //1000us = 1ms
    Delay1KTCYx(5);  
 }
 
void DelayPORXLCD(void){
    Delay1KTCYx(15);
 }
 
void init_lcd(void)
{ 
     OpenXLCD(FOUR_BIT & LINES_5X7);
     while(BusyXLCD());
     WriteCmdXLCD(SHIFT_DISP_LEFT);
     while(BusyXLCD());
}

/*Function prototypes*/
void highISR (void);
void configTimers (void);
void configInterrupts (void);
void printGlucose (void);

#pragma code HIGH_INTERRUPT_VECTOR = 0x08               //tells the compiler that the high interrupt vector is located at 0x08
void high_interrupt_vector(void){                   
    _asm                                                //allows asm code to be used into a C source file
    goto highISR                                        //goes to interrupt routine
    _endasm                                             //ends asm code insertion
}
#pragma code

#pragma interrupt highISR
void highISR (void){                                    //interrupt service routine for the high priority vector
    INTCONbits.GIE = 0;
    
    /*Routine for external interrupt on INT1*/
    if(INTCON3bits.INT1IF == 1){
        
    }
    
    /*Routine for Timer0 interrupt on overflow*/
    if(INTCONbits.TMR0IF == 1){
        
    }   
    INTCONbits.GIE = 1;
}

void configTimers (void){
    OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_256);
    T0CONbits.TMR0ON = 0;
}

void configInterrupts(void){
    RCONbits.IPEN = 1;                                  //allows the priority level interrupts to be used
    INTCONbits.GIE = 1;                                 //enables global interrupt sources
    
    INTCONbits.TMR0IE = 1;                              //enables the TMR0 interrupt source  

    INTCON2bits.INTEDG1 = 0;                            //sets the pin to interrupt on a low to high transition 
    INTCON2bits.TMR0IP = 1;                             //sets the TIMER 0 interrupt as priority
    INTCON3bits.INT1IP = 1;
    INTCON3bits.INT1E = 1;                              //enables the INT1 interrupt source
}

void printGlucose (void){
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    putsXLCD(lcdVariable);
    while(BusyXLCD());
}

void main (void){
    
    Sleep();
}
