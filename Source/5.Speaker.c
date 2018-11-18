#include <p18f452.h>
#include <timers.h>
#include <pwm.h>
#include <delays.h>

/* Set configuration bits for use with PICKit3 */
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

void main(void)
{
    TRISCbits.RC1 = 0;
    SetDCPWM2(30);
    
    OpenTimer2(TIMER_INT_OFF & T2_PS_1_16 & T2_POST_1_1);
    
    while(1){
        OpenPWM2(0x65);
        Delay10KTCYx(100);
        OpenPWM2(1);
        Delay10KTCYx(100);
    }
    
    
    //Insert Your Peripheral Specific Code here for testing
    //SLEEP();

}