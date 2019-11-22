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


void configBPMTimer(void)           //This is in charge of providing a 10 second delay
{
    INTCONbits.TMR0IF = 0;
    OpenTimer0(TIMER_INT_ON &
                T0_16BIT &
                T0_SOURCE_INT &
                T0_EDGE_RISE &
                T0_PS_1_256);
    WriteTimer0(26472);             //Value changed from last version to be tested
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

void configBpmHrVarTmr (void)       //Timer1 used in calculation of heart rate variability designed to overflow every 50 ms
{
    OpenTimer1(TIMER_INT_OFF &
                T1_16BIT_RW &
                T1_SOURCE_INT &
                T1_PS_1_1);
    
    WriteTimer1(15535);
    PIR1bits.TMR1IF = 0;
        
}

void heartRateModule(void) {
    
    while (BusyXLCD());
    SetDDRamAddr(0x50);
    while (BusyXLCD());
    putrsXLCD("                ");
    while(BusyXLCD());
    SetDDRamAddr(0x50);
    while(BusyXLCD());
    putrsXLCD("Reading...");
    while(BusyXLCD());
    INTCON3bits.INT2IE = 0; //Disables the RB2(Keypad) interrupt
    configBPMTimer();
    configBpmCount();
    
}

#pragma interrupt timer10sIsr
void timer10sIsr(void)
{
    int hrVar = 0;
    int bpm = 0;
    char hrVarOutput[4];       //Maximum of 4 outputs
    char bpmOutput[4];         //Maximum of 3 characters

    while (BusyXLCD());
    SetDDRamAddr(0x50);
    while (BusyXLCD());
    putrsXLCD("                ");
    while (BusyXLCD());
    SetDDRamAddr(0x50);
    while (BusyXLCD());
    putrsXLCD("Done !");
    while (BusyXLCD());

    INTCONbits.TMR0IF = 0;
    INTCONbits.GIE = 0;
    INTCONbits.INT0IE = 0;      //Disable RB0 (BPM) interrupt pin 
    INTCONbits.GIE = 1;
    CloseTimer1();              //Disable Heart Rate Variability Timer
    CloseTimer0();              //Disable 10 second Timer
    
    //Perform BPM and Heart Rate variability calculations here !!!!!!!!!!!!
    if (NN50Count > 0)                              //Checks to see if HRVAR would throw an erronious value due to division be 0
    {
        hrVar = (NN50Count / NNCount) * 100;        //Calculating HR Var
        itoa(hrVar,hrVarOutput);
        while(BusyXLCD());
        SetDDRamAddr(0x0C);
        while(BusyXLCD());
        putrsXLCD("    ");
        while(BusyXLCD());                          //Outputting HR Var
        SetDDRamAddr(0x0C);    
        while(BusyXLCD());
        putsXLCD(hrVarOutput);
        while(BusyXLCD());
        SetDDRamAddr(0x0E);    
        while(BusyXLCD());
        putrsXLCD("%");
        while(BusyXLCD());
    }
    else
    {
        while(BusyXLCD());
        SetDDRamAddr(0x0C);
        while(BusyXLCD());
        putrsXLCD("    ");
        while (BusyXLCD());
        SetDDRamAddr(0x0C);
        while (BusyXLCD());
        putrsXLCD("Err");
    }


    //Calculating BPM
    bpm = NNCount * 6;
    itoa(bpm,bpmOutput);
    
    //Outputting BPM
    while(BusyXLCD());
    SetDDRamAddr(0x04);
    while(BusyXLCD());    
    putrsXLCD("   ");
    while(BusyXLCD());
    SetDDRamAddr(0x04);
    while(BusyXLCD());    
    putsXLCD(bpmOutput);
    
    if ((bpm >= 200) || (bpm <= 60))
    {
        bpmAlert();
        if(bpm>=200)
        {
            while (BusyXLCD());
            SetDDRamAddr(0x50);
            while (BusyXLCD());
            putrsXLCD("                ");
            while (BusyXLCD());
            SetDDRamAddr(0x50);
            while (BusyXLCD());
            putrsXLCD("BPM High!");
            while (BusyXLCD());
        }
        else
        {
            while (BusyXLCD());
            SetDDRamAddr(0x50);
            while (BusyXLCD());
            putrsXLCD("                ");
            while (BusyXLCD());
            SetDDRamAddr(0x50);
            while (BusyXLCD());
            putrsXLCD("BPM Low!");
            while (BusyXLCD());            
        }

        
    }

    

    NNCount = 0;        //Reinitialized NNcount
    NN50Count = 0.0;    //Reinitialized NN50count
    state = 0;          //Reset the state bit in order to re enable Timer1 to start back heart rate variability 
    configKeypad();     //Enables back the RB2(Keypad) interrupt
    

}

#pragma interrupt bpmCountIsr
void bpmCountIsr(void)
{
    INTCONbits.INT0F = 0;
    
    //PORTBbits.RB4 = !(PORTBbits.RB4);
    NNCount = NNCount + 1;
    if (state == 0)
    {
        configBpmHrVarTmr();
        state = 1;
    }
    
    WriteTimer1(15535);         //Resets Timer Count
    
    if (PIR1bits.TMR1IF == 1)
    {
        PIR1bits.TMR1IF = 0;
        NN50Count = NN50Count + 1;
    }
    
}
