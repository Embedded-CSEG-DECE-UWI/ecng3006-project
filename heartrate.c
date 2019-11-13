#include    "Modules.h"
#include    "xlcd_GpE.h"
#include    <p18f452.h>
#include    <timers.h>
#include    <delays.h>
#include    <stdlib.h>
#include    <string.h>

void configBPMTimer(void) {
    OpenTimer0(TIMER_INT_OFF &
            T0_8BIT &
            T0_SOURCE_EXT &
            T0_EDGE_RISE &
            T0_PS_1_1);
    WriteTimer0(0x00);
}

void heartRateModule(void) {
    static int i;
    volatile int bpmCount = 0;
    char bpmDisplay[4] = "";
    char xlcdBPM[16] = "HR: ";
    char xlcdBPMUnit[4] = "bpm";
    configBPMTimer();
    InitLCD();
    while (BusyXLCD());
    SetDDRamAddr(0x00);
    while (BusyXLCD());
    putrsXLCD("READING BPM.");
    while (BusyXLCD());
    SetDDRamAddr(0x40);
    while (BusyXLCD());
    putrsXLCD("HOLD STILL.");
    WriteTimer0(0x00);
    for (i = 0; i < 10; i++) {
        Delay10KTCYx(100);
    }
    bpmCount = TMR0L;
    bpmCount = bpmCount * 6;

    itoa(bpmCount, bpmDisplay);
    strncat(xlcdBPM, bpmDisplay, 4);
    strncat(xlcdBPM, xlcdBPMUnit, 4);

    while (BusyXLCD());
    SetDDRamAddr(0x40);
    while (BusyXLCD());
    putsXLCD(xlcdBPM);
    while (BusyXLCD());

    if (bpmCount > 110 || bpmCount < 50) {
        while (BusyXLCD());
        SetDDRamAddr(0x10);
        while (BusyXLCD());
        putrsXLCD("HR-ALERT!");
        while (BusyXLCD());
        bpmAlert();
    }
    ClosePWM1();
}