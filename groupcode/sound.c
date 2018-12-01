#include <stdio.h>
#include <stdlib.h>
#include <p18f452.h>
#include <timers.h>
#include <pwm.h>
#include <delays.h>

/* Set configuration bits for use with PICKit3 */
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

void PWM_setup (void)                       //configuring Timer 2 for PWM mode
{
    PR2 = 124;                              //set PWM frequency to 500Hz
    CCPR1L = 63;                            //50% Duty Cycle
    CCP1CONbits.DC1B1 = 1;
    CCP1CONbits.DC1B0 = 1;
    TRISCbits.RC2 = 0;                      //set RC2 as an output
    T2CONbits.TMR2ON = 1;                   //turns on Timer 2
    T2CONbits.T2CKPS1 = 1;                  //Pre-scalar of 16
    CCP1CONbits.CCP1M3 = 1;                 //enables PWM mode
    CCP1CONbits.CCP1M2 = 1;
    PORTCbits.RC2 = 0;                      //disable pin until needed
}

void main(void)
{
    PWM_setup();
    PORTCbits.RC2 = 1;                      //enable PWM
    Delay10KTCYx(200);                      //delay of 2s
    PORTCbits.RC2 = 0;
    CCP1CONbits.CCP1M3 = 0;                 //disables PWM
    CCP1CONbits.CCP1M2 = 0;
    CCP1CONbits.CCP1M1 = 0;
    CCP1CONbits.CCP1M0 = 0;    
}