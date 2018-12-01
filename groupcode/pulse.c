#include <stdio.h>
#include <stdlib.h>
#include <p18f452.h>
#include <timers.h>
#include <delays.h>
#include <capture.h>
#include <pwm.h>
#include <math.h>
#include "xlcd.h"

#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF


void DelayFor18TCY(void){
     Nop();
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop();
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop();
     return;
}

void DelayXLCD(void){
    Delay1KTCYx(5);	
    return;
}

void DelayPORXLCD(void){
    Delay1KTCYx(15);
    return;
}

volatile int pulse;
volatile int tpulse;
int pnn;
char displaypulse[15]; 
//char displaypnn[15];

void LCDinit(void)                       //function to initialize the LCD
{ 
    OpenXLCD(FOUR_BIT & LINES_5X7);     //open the LCD and sets it to 4 bit and multiple line mode
    while(BusyXLCD());
    SetDDRamAddr(0x00);                 //sets the cursor to the top left
    while(BusyXLCD()); 
    WriteCmdXLCD(BLINK_ON);             //allow the cursor to blink
    while(BusyXLCD());          
    WriteCmdXLCD(SHIFT_DISP_LEFT);      //shift the display to the left
    while(BusyXLCD());
}
void interrupt_setup(void);
void TMR0_setup (void);
void PWM_setup (void);
//void pnn50 (void);

void high_isr(void);

#pragma code high_vector=0x08
void interrupt_at_high_vector(void)
{
_asm GOTO high_isr _endasm
}
#pragma code

#pragma interrupt high_isr
void high_isr (void)
{
if (INTCONbits.TMR0IF == 1)                 //checks if Timer 0 interrupt flag
    {                                       //is set
        PORTDbits.RD1 = !PORTDbits.RD1;     //led turns of indicating 10s has passed
        INTCONbits.TMR0IF = 0;              //clears Timer 0 interrupt flag
        T0CONbits.TMR0ON = 0;               //disables Timer 0
        PORTBbits.RB2 = 0;                  //disables pulse detector pin
        tpulse = (pulse * 6);               //pulse rate per minute
        WriteTimer0(23474); 

        while(BusyXLCD());
        sprintf(displaypulse, "HR: %d",tpulse);
        putsXLCD(displaypulse);
        while(BusyXLCD());
        
        /*if (tpulse < 60 || tpulse > 120)
            {
            PORTCbits.RC2 = 1;
            CCP1CONbits.CCP1M3 = 1;                 //enables PWM mode
            CCP1CONbits.CCP1M2 = 1;
            CCP1CONbits.CCP1M1 = 1;
            CCP1CONbits.CCP1M0 = 1;
            Delay10KTCYx(200);                      //delay of 2s
            CCP1CONbits.CCP1M3 = 0;                 //disables PWM mode
            CCP1CONbits.CCP1M2 = 0;
            CCP1CONbits.CCP1M1 = 0;
            CCP1CONbits.CCP1M0 = 0;
            PORTCbits.RC2 = 0;
            }
        pulse = 0;
        tpulse = 0;*/
    }

if (INTCON3bits.INT2IF == 1)                //checks if RB2 interrupt flag
    {                                       //is set
        INTCON3bits.INT2IF = 0;             //clears RB2 interrupt flag
        pulse++;                            //increment pulse count by 1;
    }  
}

/*void pnn50 (void)
{
    T1CONbits.TMR1ON = 0;
    PIE1bits.TMR1IE = 1;                    //enables the Timer 1 interrupt
    PIE1bits.CCP1IE = 1;                    //enables the capture interrupt
    IPR1bits.TMR1IP = 1;                    //TMR1 int is a high priority    
    OpenTimer1( TIMER_INT_ON    &
                T1_16BIT_RW     &           //16 bit mode
                T1_SOURCE_INT   &           //internal clock source
                T1_PS_1_8       &           //pre-scaler of 8
                T1_OSC1EN_OFF   &           //disable Timer 1 oscillator
                T1_SOURCE_CCP   );          //Timer 1 as a ccp source
    TMR1L = 0;                              //clears Timer 1
    TMR1H = 0;
}*/

void main(void) 
{
    LCDinit();
    interrupt_setup();
    TMR0_setup(); 
    TRISDbits.RD1 = 0;
    PORTDbits.RD1 = 1;                      //led light to indicate timing started
    PORTBbits.RB2 = 1;                      //enables RB2 to detect pulses
    //pnn50();
    
    pulse = 0;
    tpulse = 0;
    pnn = 0;
    
    //T1CONbits.TMR1ON = 1;                   //switches on Timer 1
    while(1);
    return;
}

void interrupt_setup(void)
{
    TRISBbits.RB2 = 1;                      //set RB2 as an input
    PORTBbits.RB2 = 0;                      //disable pin until needed
    RCONbits.IPEN = 1;                      //enable priority for interrupts
    INTCONbits.GIE = 1;
    INTCONbits.GIEH = 1;                    //enable high priority interrupts
    INTCONbits.PEIE = 1;
    INTCONbits.TMR0IF = 0;                  //clears TMR0 overflow flag
    INTCON3bits.INT2IF = 0;                 //clears RB2 interrupt flag
    INTCONbits.TMR0IE = 1;                  //enable Timer 0 interrupt
    INTCON3bits.INT2IE = 1;                 //enable RB2 interrupt
    INTCON2bits.RBPU = 0;                   //disable pull ups
    INTCON2bits.INTEDG2 = 1;                //RB0 interrupts on rising edge
    INTCON2bits.TMR0IP = 1;                 //high priority interrupt
    
}

void TMR0_setup (void)                      //configuring Timer 0 as a counter
{
    OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_256);
    WriteTimer0(23474);                     //10s delay
    T0CONbits.TMR0ON = 1;
}   

void PWM_setup (void)                       //configuring Timer 2 for PWM mode
{
    PR2 = 124;                              //set PWM frequency to 500Hz
    CCPR1L = 63;                            //50% Duty Cycle
    CCP1CONbits.DC1B1 = 1;
    CCP1CONbits.DC1B0 = 1;
    TRISCbits.RC2 = 0;                      //set RC2 as an output
    T2CONbits.TMR2ON = 1;                   //turns on Timer 2
    T2CONbits.T2CKPS1 = 1;                  //Pre-scalar of 16
    PORTCbits.RC2 = 0;                      //disable pin until needed
}

/*void pnn50 (void)
{
    T1CONbits.TMR1ON = 0;
    PIE1bits.TMR1IE = 1;                    //enables the Timer 1 interrupt
    PIE1bits.CCP1IE = 1;                    //enables the capture interrupt
    IPR1bits.TMR1IP = 1;                    //TMR1 int is a high priority    
    OpenTimer1( TIMER_INT_ON    &
                T1_16BIT_RW     &           //16 bit mode
                T1_SOURCE_INT   &           //internal clock source
                T1_PS_1_8       &           //pre-scaler of 8
                T1_OSC1EN_OFF   &           //disable Timer 1 oscillator
                T1_SOURCE_CCP   );          //Timer 1 as a ccp source
    TMR1L = 0;                              //clears Timer 1
    TMR1H = 0;        
}*/