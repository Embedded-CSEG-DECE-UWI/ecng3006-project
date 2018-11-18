/*This version of the pulse rate monitor has a continuous pulse interval of 15s
 via Timer 0. An external interrupt on pin INT1 is used to measure the 
 number of pulse events to be displayed on the screen. A push button is installed
 to create the 'external events' that would trigger the external interrupt in order
 to test whether the system is responding as expected*/

#include <p18cxxx.h> 
#include <delays.h>
#include <timers.h>
#include <p18f452.h>
//#include "xlcd.h"

 /* Set configuration bits for use with PICKit3 and 4MHz oscillator */
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

/*Defining a new data type with two states called boolean with additional key-words*/
typedef int bool;               
#define true 1
#define false 0;

volatile int int1Events = 0;
unsigned int int1Pulse = 0;
bool isCounting = 0;

/*Function prototypes*/
void configTimers (void);
void configInterrupts (void);
void startPulseInterval (void);
void stopPulseInterval (void);
void highISR (void);

#pragma code HIGH_INTERRUPT_VECTOR = 0x08                   //tells the compiler that the high interrupt vector is located at 0x08
void high_interrupt_vector(void){                           //high interrupt vector ISR
    _asm                                                    //allows asm code to be used into a C source file
    goto highISR                                            //goes to interrupt routine
    _endasm                                                 //ends asm code insertion
}
#pragma code

#pragma interrupt highISR
void highISR (void){                                        //interrupt service routine for high interrupt vector
    INTCONbits.GIE = 0;
    
    /*Routine for external interrupt on INT1*/
    if(INTCON3bits.INT1IF == 1){
        INTCON3bits.INT1IE = 0;
        INTCON3bits.INT1IF = 0;
        
        PORTBbits.RB3 = !PORTBbits.RB3;
        startPulseInterval();
        int1Events++;
        
        
        INTCON3bits.INT1IE = 1;
    }
    
    /*Routine for Timer0 interrupt on overflow*/
    if(INTCONbits.TMR0IF == 1){
        INTCONbits.TMR0IE = 0;
        INTCONbits.TMR0IF = 0;
        
        //PORTBbits.RB3 = 0;
        
        PORTBbits.RB2 = !PORTBbits.RB2; 
        int1Pulse = int1Events;
        int1Events = 0;
        //startPulseInterval();   
        stopPulseInterval();
        INTCONbits.TMR0IE = 1;
    }   
    INTCONbits.GIE = 1;
}

void configTimers (void){
    OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_128);
    T0CONbits.TMR0ON = 0;
    //OpenTimer1(TIMER_INT_OFF & T1_8BIT_RW & T1_SOURCE_EXT & T1_OSC1EN_OFF & T1_SYNC_EXT_OFF);
    //T1CONbits.TMR1ON = 0;
}

void configInterrupts(void){
    RCONbits.IPEN = 1;                                      //allows the priority level interrupts to be used
    INTCONbits.GIE = 1;                                     //enables global interrupt sources
    
    INTCONbits.TMR0IE = 1;                                  //enables the TMR0 interrupt source  

    INTCON2bits.INTEDG1 = 0;
    INTCON2bits.TMR0IP = 1;
    INTCON3bits.INT1IP = 1;
    INTCON3bits.INT1E = 1;
}

void configDebugLED (void){
    //This LED determines whether TIMER0 is interrupting every 50s
    TRISBbits.RB2 = 0; 
    PORTBbits.RB2 = 0;
    //This LED determines whether the external interrupt is being serviced
    TRISBbits.RB3 = 0; 
    PORTBbits.RB3 = 0;
    //This LED is a "main" program
    TRISBbits.RB4 = 0; 
    PORTBbits.RB4 = 0;
}

void main (void)
{
    /*Configuration functions*/
    configDebugLED();
    configInterrupts();
    configTimers();
    startPulseInterval();
            
    while (1){
        PORTBbits.RB4 = !PORTBbits.RB4;
        Delay10KTCYx(10);
    }
}

void startPulseInterval (void){
    WriteTimer0(6941);
    T0CONbits.TMR0ON = 1;
}

void stopPulseInterval (void){
    //INTCON3bits.INT1E = 0;
    T0CONbits.TMR0ON = 0;
}



