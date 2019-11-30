#include <p18f452.h>
#include <stdio.h>
#include <stdlib.h>



void Init_Speaker(){
    PR2 = 240;              //1. Set PWM period by writing to the PR2 register; Period = 0.00256s => Freq. = 3906HZ 
    CCPR1L = 100;           //2.  Set PWM suty cycle to 50%
    TRISCbits.TRISC2 = 0;   //3. Make CCP1 an output by clearing the TRISC<2> bit
    T2CON = 0b0000110;       //4. Set TMR2 prescale value and enable Timer2
    CCP1CON = 0b00001100;     //5. Configure CCP1 module for PWM operation
}

void Speaker_Off(){
    T2CON = 0;
    TRISCbits.TRISC2 = 1;
}
