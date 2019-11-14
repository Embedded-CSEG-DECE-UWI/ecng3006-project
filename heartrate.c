#include    "Modules.h"
#include    "xlcd_GpE.h"
#include    <p18f452.h>
#include    <timers.h>
#include    <delays.h>
#include    <stdlib.h>

//Global BPM Variables
volatile int NNCount = 0;
volatile float NN50Count = 0.0;
volatile int BPM = 0;
volatile int state = 0;

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
    INTCONbits.TMR0IF = 0;
    OpenTimer0(TIMER_INT_ON &
                T0_16BIT &
                T0_SOURCE_INT &
                T0_EDGE_RISE &
                T0_PS_1_256);
    WriteTimer0(6776960);
}

void configBpmCount(void)
{
    //PORTBbits.RB0 = 1;
    INTCONbits.GIE = 0;
    INTCONbits.INT0F = 0;           //Clear flag
    INTCON2bits.INTEDG0 = 1;        //RB0 Interrupt triggered at Rising edge
    INTCONbits.INT0IE = 1;          //Enable RB0 interrupt
    INTCONbits.GIE = 1;             //Enable Global interrupt
}

void configBpmHrVarTmr (void)
{
    OpenTimer1(TIMER_INT_OFF &
                T1_16BIT_RW &
                T1_SOURCE_INT &
                T1_PS_1_1);
    
    WriteTimer1(15535);
    PIR1bits.TMR1IF = 0;
        
}

void heartRateModule(void) {
    
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    putrsXLCD("Hold still");
    while(BusyXLCD());
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

#pragma interrupt timer10sIsr
void timer10sIsr(void)
{
    int hrVar = 0;
    int bpm = 0;
    char hrVarOutput[16];
    char bpmOutput[16];



    INTCONbits.TMR0IF = 0;
    INTCONbits.GIE = 0;
    INTCONbits.INT0IE = 0;      //Disable RB0 (BPM) interrupt pin 
    INTCONbits.GIE = 1;
    CloseTimer1();              //Disable Heart Rate Variability Timer
    CloseTimer0();              //Disable 10 second Timer
    
    //Perform BPM and Heart Rate variability calculations here !!!!!!!!!!!!
    hrVar = (NN50Count / NNCount) * 100;
    itoa(hrVar,hrVarOutput);
    bpm = NNCount * 6;
    itoa(bpm,bpmOutput);
    
    //Outputting Values
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    while(BusyXLCD());    
    putsXLCD(bpmOutput);
    while(BusyXLCD());
    SetDDRamAddr(0x40);    
    while(BusyXLCD());
    putsXLCD(hrVarOutput);
    while(BusyXLCD());
    

    NNCount = 0;    //Reinitialized NNcount
    NN50Count = 0.0;  //Reinitialized NN50count
    configKeypad(); //Enables back the RB2(Keypad) interrupt
    

}

#pragma interrupt bpmCountIsr
void bpmCountIsr(void)
{
    INTCONbits.INT0F = 0;
    
    PORTBbits.RB4 = !(PORTBbits.RB4);
    NNCount = NNCount + 1;
    if (state == 0)
    {
        configBpmHrVarTmr();
        state = 1;
    }
    
    WriteTimer1(15535);         //Resets Timer Count
    
    if (PIR1bits.TMR1IF == 1)
    {
        NN50Count = NN50Count + 1;
    }
    
}
