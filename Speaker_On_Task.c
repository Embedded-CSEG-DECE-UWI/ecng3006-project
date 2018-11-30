#include <p18f452.h>
#include <delays.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwm.h>
#include <timers.h>


void Speaker_On_Task(void)
{
    // Set RC2 as output for CCP1 
    TRISCbits.TRISC2 = 0;
    
    // Set duty cycle
    // aka volume of speaker
    // 10 bit , 2^10 = 1024 
    SetDCPWM1(500);  // 50%
    
    OpenTimer2(TIMER_INT_OFF & T2_PS_1_4 & T2_POST_1_1);
    
    // Period of PWM
    // Sets frequency or tone
    OpenPWM1(0xF9);  // 1ms
    
    return;
}

