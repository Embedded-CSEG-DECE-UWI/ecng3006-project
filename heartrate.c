#include    "Modules.h"
#include    "xlcd_GpE.h"
#include    <p18f452.h>
#include    <timers.h>
#include    <delays.h>
#include    <stdlib.h>
#include    <string.h>

//Global BPM Variables
volatile int NNCount = 0;
volatile int NN50Count = 0;
volatile int BPM = 0;

/*void configBPMTimer(void) {
    OpenTimer0(TIMER_INT_OFF &
            T0_8BIT &
            T0_SOURCE_EXT &
            T0_EDGE_RISE &
            T0_PS_1_1);
    WriteTimer0(0x00);
}*/

void configBPMTimer(void)       //This is in charge of providing a 10 second delay
{
    OpenTimer0(TIMER_INT_ON &
                T0_16BIT &
                T0_SOURCE_INT &
                T0_PS_1_256);
    
    INTCONbits.GIE = 0;
    INTCON2bits.TMR0IP = 1;     //Sets TMR0 interrupt to be high priority
    INTCONbits.GIE = 1;
    
    WriteTimer0(6776960);
}

void configBpmCount(void)
{
    INTCONbits.GIE = 0;
    INTCONbits.INT0F = 0;           //Clear flag
    INTCONbits.INT0IE = 1;          //Enable RB0 high priority interrupt
    INTCON2bits.INTEDG0 = 1;        //RB2 Interrupt triggered at Rising edge
    

    INTCONbits.GIE = 1;             //Enable Global interrupt
}

void heartRateModule(void) {
    
    INTCON3bits.INT2IE = 0; //Disables the RB2(Keypad) interrupt
    configBPMTimer();
    configBpmCount();
    
    /*static int i;
    volatile int bpmCount = 0;
    char bpmDisplay[4] = "";
    char xlcdBPM[16] = "HR: ";
    char xlcdBPMUnit[4] = "bpm";
    configBPMTimer();
    //InitLCD();        Why are we initializing the LCD here a second time ??
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
    ClosePWM1();*/
    
    
}

void timer10sIsr(void)
{
    INTCONbits.GIE = 0;
    INTCONbits.INT0IE = 0; 
    INTCONbits.GIE = 1;
    CloseTimer0();
    //Perform BPM and Heart Rate variability calculations here !!!!!!!!!!!!
}

void bpmCountIsr(void)
{
    NNCount = NNCount + 1;
    
}