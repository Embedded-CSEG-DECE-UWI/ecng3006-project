#include <pwm.h>
#include <timers.h>
#include <delays.h>
#include <p18f452.h>     


void speaker_on(void){
    int i;
    TRISCbits.TRISC2 = 0;
    IPR1bits.TMR2IP = 1;
    SetDCPWM1(80);
    OpenTimer2(TIMER_INT_OFF & T2_PS_1_16 & T2_POST_1_1);
    for(i = 0; i < 5; i++){
      OpenPWM1(0x65);    
      Delay10KTCYx(50);
      OpenPWM1(1);
      Delay10KTCYx(50);
    }
    CloseTimer2();
    return;
}