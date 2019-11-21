#include <p18f452.h>
#include <pwm.h>
#include <timers.h>
#include <delays.h>


void speaker(int count){
TRISCbits.RC2 = 0;//Configure RC2 as an output
SetDCPWM1(50);
OpenTimer2( TIMER_INT_OFF & T2_PS_1_16 & T2_POST_1_1);//Configure and enable timer2


    while(count>0){
        
        OpenPWM1(0xEE); //opening PWM
        Delay10KTCYx(16);//Delay
        OpenPWM1(1);
        Delay10KTCYx(16);//Delay

        OpenPWM1(0xEE); //opening PWM
        Delay10KTCYx(16);//Delay
        OpenPWM1(1);
        Delay10KTCYx(16);//Delay
        
        OpenPWM1(0xEE); //opening PWM
        Delay10KTCYx(16);//Delay
        OpenPWM1(1);
        Delay10KTCYx(16);//Delay
        
        Delay10KTCYx(200);//wait to repeat
        
        count = count -1;
        ClosePWM1();
    }
    return;
}

    

