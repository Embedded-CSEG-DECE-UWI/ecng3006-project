#include    <p18f452.h>
#include    <pwm.h>
#include    <delays.h>
#include    <timers.h>
#include    "Modules.h"

void initSpeakerModule(void) {
    OpenTimer2(TIMER_INT_OFF & T2_PS_1_16 & T2_POST_1_1);
}

void bpmAlert(void) {                   //Alarm that sounds if HR > 200bpm or HR< 60 bpm
    static int i;
    for (i = 0; i < 10; i++) {
        OpenPWM1(0xFF);
        SetDCPWM1(0x1FF);
        Delay10KTCYx(10);
        SetDCPWM1(0x0F1);
        Delay10KTCYx(10);
    }
    ClosePWM1();
}

void TestBeep(void) {
    static int i;
    for (i = 0; i < 10; i++) {
        OpenPWM1(0xFF);
        SetDCPWM1(0x1FF);
        Delay10KTCYx(10);
        ClosePWM1();
        Delay10KTCYx(10);
    }
}