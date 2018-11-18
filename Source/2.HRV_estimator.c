#include <p18f452.h>
#include <stdlib.h>
#include <stdio.h>

#include <delays.h>
#include <timers.h>
#include <capture.h>
#include <math.h>

#include "xlcd.h"

/*Set configuration bits for use with PICKit3 and 4MHz oscillator*/
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

/*Defining a new data type with two states called boolean with additional key-words*/
typedef int bool;               
#define true 1
#define false 0;

bool isCapturing = 0;

int timer1_overflow_count = 0;
unsigned int CCP1_value = 0;
float nn = 0;
float nn50 = 0;
float temp_interval = 0;
float pnn50 = 0;
float HRV = 0;
int test = 0;

int value_number = 0;

unsigned int HRV2 = 0;
unsigned int new_value = 0;
unsigned int previous_value = 0;
unsigned int interval = 0;

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
 
void init_lcd(void){ 
     OpenXLCD(FOUR_BIT & LINES_5X7);
     while(BusyXLCD());
     WriteCmdXLCD(SHIFT_DISP_LEFT);
     while(BusyXLCD());
}

/*Function prototypes*/
void highISR (void);
void configCCP (void);
void configTimers (void);
void configInterrupts (void);
void readCurrentCount (void);
void calculateHRV (void);
void printHRV (void);

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
    if(PIR1bits.CCP1IF == 1){
        PIE1bits.CCP1IE = 0;
        PIR1bits.CCP1IF = 0;
        
        PORTBbits.RB4 = !PORTBbits.RB4;
        
        isCapturing = 1;
        value_number += 1;
        readCurrentCount();
        
        PIE1bits.CCP1IE = 1;
    }
    
    /*Routine for Timer0 interrupt on overflow*/
    if(PIR1bits.TMR1IF == 1){
        PIE1bits.TMR1IE = 0;
        PIR1bits.TMR1IF = 0;
        
        PORTBbits.RB3 = !PORTBbits.RB3;
        timer1_overflow_count += 1;
        
        PIE1bits.TMR1IE = 1;
    }   
    INTCONbits.GIE = 1;
}

void configTimers (void){
    OpenTimer1(TIMER_INT_ON & T1_16BIT_RW & T1_SOURCE_INT & T1_PS_1_1
            & T1_OSC1EN_OFF & T1_SYNC_EXT_OFF & T1_SOURCE_CCP);
    //T1CONbits.TMR1ON = 0;   
}

void configCCP (void){
    TRISCbits.RC2 = 1;                                  //configures RC2 (pin 17) as an input for use in capture mode   
    OpenCapture1(CAPTURE_INT_ON & C1_EVERY_RISE_EDGE);
}

void configInterrupts(void){
    RCONbits.IPEN = 1;                                  //allows the priority level interrupts to be used
    INTCONbits.GIE = 1;                                 //enables global interrupt sources
    
    PIE1bits.TMR1IE = 1;                                //enables the Timer 1 interrupt
    PIE1bits.CCP1IE = 1;                                //enables the capture interrupt
    
    IPR1bits.TMR1IP = 1;                                //sets TIMER 1 interrupt as the priority 
    //IPR1bits.CCP1IP = 1;
}

void printHRV (void){
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    sprintf(lcdVariable, "%d:HRV:%d%", value_number, HRV2);
    putsXLCD(lcdVariable);
    while(BusyXLCD());
}

void readCurrentCount (void){
    if(value_number == 1){
        CCP1_value = ReadCapture1();
        previous_value = CCP1_value;//(65535*timer1_overflow_count) + CCP1_value;
    }
    if (value_number == 2){
        CCP1_value = ReadCapture1();
        new_value = CCP1_value;//(65535*timer1_overflow_count) + CCP1_value;
        //calculateHRV();
    }
    if (value_number > 2){
        CCP1_value = ReadCapture1();
        previous_value = new_value;
        new_value = (65535*timer1_overflow_count) + CCP1_value;
    } 
    calculateHRV();
}

void calculateHRV (void){
    interval = new_value - previous_value;
    temp_interval = interval/1000;
    
    nn+=1;
    
    if( temp_interval > 50){
        nn50+=1;
    }
    
    if(nn == 15){
      pnn50 = (nn50/nn);
      HRV = pnn50*100;
      HRV2 = HRV;
      CloseCapture1();
      CloseTimer1();
    }

    
}

void main (void){
    TRISBbits.RB4 = 0;
    TRISBbits.RB3 = 0;
    PORTBbits.RB3 = 0;
    PORTBbits.RB4 = 0;
    init_lcd();
    configInterrupts();
    configTimers();
    configCCP();
    
    printHRV();
    
    while(1){
        if(isCapturing == 1){
            printHRV();
        }
    }
        
    Sleep();
}

