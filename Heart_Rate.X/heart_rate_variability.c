#include <p18f452.h>
#include "xlcd.h"
#include <delays.h>
#include <timers.h>
#include <stdlib.h>
#include <string.h>
#include <capture.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

int heartBeatCounter = 0;           //Counter used for HR calculation
char heartRateOutput [3];           //Char array used to store HR Output
char hrvOutput [3];
int heartRate = 0;                  //
int startTimer = 0;

int startHRV = 0;
int timer1Period = 0;               //Counter used to indicate period number
unsigned long HRVvar1 = 0;
unsigned long HRVvar2 = 0;
unsigned long HRVvar3 = 0;
int hrvInterval1 = 0;
int hrvInterval2 = 0;
int numNNInterval = 0;
int numNN50 = 0;
int pNN50 = 0;
int nnIntervalcounter = 0;

void high_isr (void);
void low_isr (void);
void heartRateCal();
void hrvCalculation();
void irPulseSetup();
void keypadSetup();
void captureSetup();
void timer0Setup();
void pulseCounting();
void timer1Setup();

void DelayFor18TCY (void)
{
     Nop();     Nop();      Nop();      Nop();      Nop();      Nop(); 
     Nop();     Nop();      Nop();      Nop();      Nop();      Nop(); 
     Nop();     Nop();      Nop();      Nop();
}

void DelayXLCD (void)
{
    Delay1KTCYx(5);
}

void DelayPORXLCD (void)
{
    Delay1KTCYx(15);   
}

void heartRateCal(){
    heartRate = (60*heartBeatCounter)/10;
    itoa(heartRate, heartRateOutput);

    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("P_Rate:");
    while(BusyXLCD());
    SetDDRamAddr(0x08);
    while(BusyXLCD());
    putsXLCD(heartRateOutput);
    while(BusyXLCD());
    SetDDRamAddr(0x0D);
    while(BusyXLCD());
    putrsXLCD("bpm");

    heartRate = 0;
    heartBeatCounter = 0;
    memset(heartRateOutput, 0, sizeof(heartRateOutput));    //Clears char[]
    WriteTimer0(0x676A);     
}

//Adapted from Aasif Edoo (cite better)
void hrvCalculation(){
    if(HRVvar1 == 0 && HRVvar2 == 0 && HRVvar3 ==0){
            HRVvar1 = ReadCapture2();
            HRVvar1 = HRVvar1 + (timer1Period * 500000);            
        }
        else if(HRVvar1 != 0 && HRVvar2 == 0 && HRVvar3 == 0){
            HRVvar2 = ReadCapture2();
            HRVvar2 = HRVvar2 + (timer1Period * 500000);
            hrvInterval1 = HRVvar2 - HRVvar1;
            nnIntervalcounter++;
            numNNInterval = numNNInterval++;
        }
        else if(HRVvar1 != 0 && HRVvar2 != 0 && HRVvar3 == 0){
            HRVvar3 = ReadCapture2();
            HRVvar3 = HRVvar3 + (timer1Period * 500000);
            hrvInterval2 = HRVvar3 - HRVvar2;
            nnIntervalcounter++;
            numNNInterval = numNNInterval++;
            if((hrvInterval2 - hrvInterval1) > 50000){
                numNN50 = numNN50++;
            }
            HRVvar3 = 0;
            HRVvar2 = 0;
            HRVvar1 = 0;
            hrvInterval1 = 0;
            hrvInterval2 = 0;  
        }       
    
    pNN50 = (numNN50/nnIntervalcounter)*100;
    itoa(pNN50, hrvOutput);
    
    while(BusyXLCD());
    SetDDRamAddr(0x40);
    putrsXLCD("HRV:");
    while(BusyXLCD());
    SetDDRamAddr(0x4A);
    while(BusyXLCD());
    putsXLCD(hrvOutput);
    while(BusyXLCD());
    SetDDRamAddr(0x4F);
    while(BusyXLCD());
    putrsXLCD("%");
}

void lcdSetup (void)
{ 
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x00); 
    while(BusyXLCD()); 
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
    putrsXLCD("Press A");
}

void keypadSetup(){
    INTCON3bits.INT1IE = 1;     //enable the INT1 external interrupt 
    INTCON3bits.INT1IP = 0;     //INT1 External Interrupt Priority bit LOW for Low priority
    INTCON3bits.INT1IF = 0;     //Clear INT1 flag bit
	INTCON2bits.INTEDG1= 1;     //set interrupt INT1 on rising edge    
    
    //Input pins for the keypad
    TRISDbits.RD7 = 1;          //A
    TRISDbits.RD6 = 1;          //B
    TRISDbits.RD5 = 1;          //C
    TRISDbits.RD4 = 1;          //D
}

void irPulseSetup(){
    INTCON3bits.INT2IE = 1;     //Enable INT2 interrupt
    INTCON3bits.INT2IF = 0;     //Clear INT2 interrupt flag
    INTCON3bits.INT2IP = 0;     //Set INT2 priority to low
    INTCON2bits.INTEDG2 = 1;    //Set to interrupt on rising edge
    
    TRISBbits.RB2 = 1;          //Configure RB2 as an input for output from IR module
}

void timer0Setup(){
    //Timer 0 Setup 
    OpenTimer0(TIMER_INT_ON &
        T0_16BIT & T0_SOURCE_INT &
        T0_EDGE_RISE & T0_PS_1_256);
    INTCON2bits.T0IP = 1;       //Set TMR0 Interrupt as high priority
    INTCONbits.T0IE = 1;        //Enable TMR0 overflow interrupt bit 
    INTCONbits.T0IF = 0;        //Clearing TMR0 Interrupt Flag
}

void timer1Setup(){
    //Timer 1 Setup
    OpenTimer1(TIMER_INT_ON & 
        T1_16BIT_RW & T1_SOURCE_INT &
        T1_PS_1_8 & T1_SOURCE_CCP);
    IPR1bits.TMR1IP = 0;        //Set TMR1 interrupt LOW priority 
    PIE1bits.TMR1IE = 1;        //Enable TMR1 interrupt
    PIR2bits.CCP2IF = 0;        //Set the capture to 0
    IPR2bits.CCP2IP = 1;        //Set capture to high priority
    WriteTimer1(0x0BDC);        //Write TMR1 to start for 0.5s
    
}
  
void captureSetup(){
    //Timer 1 Setup for counting time between NN intervals and CCP2
    TRISCbits.CCP2 = 1;         //Set CCP2 as an input
    OpenCapture2(               //Configure to Capture every rising edge
        CAPTURE_INT_ON & 
        C2_EVERY_RISE_EDGE); 
}

void pulseCounting(){
    heartBeatCounter = heartBeatCounter++;
}


/*------------------------HIGH INTERRUPT SERVICE ROUTINE----------------------*/
#pragma code high_vector = 0x08
void interrupt_at_high_vector(void)
{
    _asm GOTO high_isr _endasm
}
#pragma code

#pragma interrupt high_isr
void high_isr (void)
{
    
    if(INTCONbits.TMR0IF == 1 && startTimer == 1){
        heartRateCal();
        INTCONbits.TMR0IF = 0;
    }
    
    if(PIR2bits.CCP2IF == 1 && startHRV == 1){
        hrvCalculation();
        PIR2bits.CCP2IF = 0;
    }
}

/*------------------------LOW INTERRUPT SERVICE ROUTINE-----------------------*/
#pragma code low_vector = 0x18
void interrupt_at_low_vector(void)
{
    _asm GOTO low_isr _endasm
}
#pragma code

#pragma interrupt low_isr
void low_isr (void)
{
    //Pulse counting interrupt
    if(INTCON3bits.INT2IF){
        pulseCounting();
    }
    
    //Restarts the timer and checks current period
    if(PIR1bits.TMR1IF == 1){
        if(timer1Period > 19){
            timer1Period = 0;
        }
        else if(timer1Period < 19){
            timer1Period = timer1Period++;
        }
        WriteTimer1(0x0BDC);
    }
    
    if(INTCON3bits.INT1IF){
        //Keypad A to start Heart Rate
        if (PORTCbits.RC7 && !PORTCbits.RC6 && !PORTCbits.RC5 && !PORTCbits.RC4)
        {
            startTimer = 1;
            timer0Setup();
            WriteCmdXLCD(0b00000001);
            WriteTimer0(0xF0BD);
            //startHRV = 1;
            //captureSetup();
            //timer1Setup();
        }
        
        //Keypad B Start Heart Rate Variability
        if (PORTCbits.RC7 && !PORTCbits.RC6 && PORTCbits.RC5 && !PORTCbits.RC4 ){
            //startHRV = 1;
            //WriteCmdXLCD(0b00000001);
            //captureSetup();
        }
        
        if (PORTCbits.RC7 && !PORTCbits.RC6 && PORTCbits.RC5 && PORTCbits.RC4)
        {
            CloseTimer0();    
            CloseCapture2();
            CloseTimer1();
        }
        
        
    }
    PIR1bits.TMR1IF = 0;
    INTCON3bits.INT2IF = 0;
    INTCON3bits.INT1IF = 0;
}

void main()
{
    //SETUP 
    lcdSetup();
    keypadSetup();
    irPulseSetup();   
    INTCONbits.GIEH = 1;        //Global Interrupt Enable bit
    RCONbits.IPEN = 1;          //Enable Interrupt Priority 
    INTCONbits.PEIE = 1;         //Enable Peripheral Interrupt Enable bit
    while(1);
}

