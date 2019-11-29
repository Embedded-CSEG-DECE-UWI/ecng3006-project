#include <p18f452.h>
#include <stdio.h>
#include <stdlib.h>
#include <delays.h>
#include<timers.h>
#include<pwm.h>

//Reference for Past Group Wiki for Speaker Code
//Group F - 2b||!2b. ?Group F - Speaker .? Github. Accessed November 15, 2019.
//https://github.com/Embedded-CSEG-DECE-UWI/ecng3006-project/blob/Group-F-Speaker/Source/5.Speaker.c.


void speakermain(void)
{
    TRISCbits.RC1 = 0;
    SetDCPWM2(40);
    
    OpenTimer2(TIMER_INT_OFF & T2_PS_1_16 & T2_POST_1_1);
    
    
        OpenPWM2(0x67);
        Delay10KTCYx(100);
        OpenPWM2(1);
        Delay10KTCYx(100);
   
}