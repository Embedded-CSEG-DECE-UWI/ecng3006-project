/*This version of the pulse rate sensor has a continuous pulse interval of 10s via
 Timer 0. An external interrupt on pin INT1 is used to measure the number of pulse
 events to be displayed on the screen. It differs from IR_pulse_sensor_v2 such that
 the sensor is now has a reduced timing interval of 10s in order to reduce the time
 taken for consecutive readings as well as a transistor switch that starts readings*/

#include <p18f452.h> 
#include <stdlib.h>
#include <stdio.h>
#include <delays.h>
#include <timers.h>
#include "xlcd.h"

 /*Set configuration bits for use with PICKit3 and 4MHz oscillator*/
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

/*Defining a new data type with two states called boolean with additional key-words*/
typedef int bool;               
#define TRUE 1
#define FALSE 0

bool isCounting = FALSE;                                //state that defines whether the program is currently counting pulses or not
volatile int int1Events = 0;                            //stores the event/pulse count received by INT1
unsigned int int1TotalPulse = 0;                        //stores the adjusted pulse count that gives the number of pulses in 1 min

char lcdVariable[20];                                   //array that will contain the pulse count to display on the LCD

/*Delays for 18 instruction cycles*/
void DelayFor18TCY(void){
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();         
}
 
/*Delays for 5ms*/
void DelayXLCD(void){                                   //1000us = 1ms
    Delay1KTCYx(5);  
 }
 
/*Delays for 15ms*/
void DelayPORXLCD(void){
    Delay1KTCYx(15);
 }
 
/*Initializes LCD screen for use*/
void initLCD(void){ 
     OpenXLCD(FOUR_BIT & LINES_5X7);
     while(BusyXLCD());
     WriteCmdXLCD(SHIFT_DISP_LEFT);
     while(BusyXLCD());
}

/*Function prototypes*/
void configDebugLED (void);
void configTimers (void);
void configInterrupts (void);
void startPulseInterval (void);
void stopPulseInterval (void);
void printPulse (void);
void highISR (void);

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
        INTCON3bits.INT1IE = 0;
        INTCON3bits.INT1IF = 0;
        
        isCounting = TRUE; 
        
        PORTBbits.RB3 = !PORTBbits.RB3;                 //toggles a debugging LED that indicates when an external interrupt has occurred
        int1Events++;                                   //increments the event counter
        
        INTCON3bits.INT1IE = 1;
    }
    
    /*Routine for Timer0 interrupt on overflow*/
    if(INTCONbits.TMR0IF == 1){
        INTCONbits.TMR0IE = 0;
        INTCONbits.TMR0IF = 0;
        
        isCounting = FALSE;
                
        PORTBbits.RB2 = !PORTBbits.RB2;                 //toggles a debugging LED that indicates when TIMER 0 overflows 
        int1TotalPulse = (int1Events*6);                //calculation to obtain number of pulses in 1 min (15s*4)
        int1Events = 0;                                 //resets the pulse count
        
        stopPulseInterval();
        startPulseInterval();                  
        
        INTCONbits.TMR0IE = 1;
    }   
    INTCONbits.GIE = 1;
}


void main (void)
{
    /*Configuration functions*/
    configDebugLED();
    configInterrupts();
    configTimers();
    initLCD();
    
    startPulseInterval();
    
    TRISBbits.RB1 = 1;
    PORTBbits.INT1 = 1;
    PORTBbits.INT1 = 0;
    PORTBbits.INT1 = 1;
    PORTBbits.INT1 = 0;
    PORTBbits.INT1 = 1;
    PORTBbits.INT1 = 0;
    PORTBbits.INT1 = 1;
    PORTBbits.INT1 = 0;
    PORTBbits.INT1 = 1;
    PORTBbits.INT1 = 0;
    
    while (1){
        PORTBbits.RB4 = !PORTBbits.RB4;
        Delay10KTCYx(10);
        
        if(isCounting == FALSE){
            printPulse();                               //prints the result as long as the program is not currently counting
        }
    }
}

void configDebugLED (void){
    //This controls the IR circuit
    TRISBbits.RB0 = 0; 
    PORTBbits.RB0 = 0;
    //This LED determines whether TIMER0 is interrupting every 15s
    TRISBbits.RB2 = 0; 
    PORTBbits.RB2 = 0;
    //This LED determines whether the external interrupt is being serviced
    TRISBbits.RB3 = 0; 
    PORTBbits.RB3 = 0;
    //This LED is a "main" program
    TRISBbits.RB4 = 0; 
    PORTBbits.RB4 = 0;
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

void printPulse (void){
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    sprintf(lcdVariable, "Heartbeat: %d", int1TotalPulse);
    putsXLCD(lcdVariable);
    while(BusyXLCD());
}

void startPulseInterval (void){
    WriteTimer0(0x6769);                                  //0x6769 is the value obtained that is need to be written to TIMER 0 with a ps of 256 to obtain a 10s interval
    T0CONbits.TMR0ON = 1;
}

void stopPulseInterval (void){
    T0CONbits.TMR0ON = 0;
}





