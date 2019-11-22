#include <p18f452.h>
#include <pwm.h>
#include <timers.h>
#include <delays.h>
#include "Prototypes.h"


void bpmAlarm(void){
    
 int count = 0;
TRISCbits.RC2 = 0;//Configure RC2 as an output
SetDCPWM1(60);
OpenTimer2( TIMER_INT_OFF & T2_PS_1_16 & T2_POST_1_1);//Configure and enable timer2


    for(count = 3; count > 0; count--){
        
        OpenPWM1(0xEE); //opening PWM
        Delay10KTCYx(16);//Delay
        ClosePWM1();
        Delay10KTCYx(16);//Delay

        OpenPWM1(0xEE); //opening PWM
        Delay10KTCYx(16);//Delay
        ClosePWM1();
        Delay10KTCYx(16);//Delay
        
        OpenPWM1(0xEE); //opening PWM
        Delay10KTCYx(16);//Delay
        ClosePWM1();
        Delay10KTCYx(16);//Delay
        
        Delay10KTCYx(100);//wait to repeat
}
}

void hrvAlarm(void){
    int count = 0;
	TRISCbits.RC2 = 0;//Configure RC2 as an output
	SetDCPWM1(60);
	//Configure and enable timer2
	OpenTimer2( TIMER_INT_OFF & T2_PS_1_16 & T2_POST_1_1);

    for(count = 3; count > 0; count--){
        //C4
        OpenPWM1(0xEE); //opening PWM
        Delay10KTCYx(16);//Delay
        ClosePWM1();
        Delay10KTCYx(16);//Delay
	//E4
        OpenPWM1(0xBD); //opening PWM
        Delay10KTCYx(16);//Delay
        ClosePWM1();
        Delay10KTCYx(16);//Delay
        //G4
        OpenPWM1(0x9F); //opening PWM
        Delay10KTCYx(16);//Delay
        ClosePWM1();
        Delay10KTCYx(16);//Delay
        
        Delay10KTCYx(100);//wait to repeat
    }
}    
    

