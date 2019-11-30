#include <p18f452.h>
#include "xlcd.h"
#include <delays.h>
#include <timers.h>
#include <stdlib.h>
#include <string.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

int heartBeatCounter = 0;
char heartRateOutput [3];
int heartRate = 0;
int startTimer = 0;
int startHRV = 0;

void high_isr (void);
void low_isr (void);
void heartRateCal();

int heartBeatcounter = 0;
unsigned int timer1Period = 0;
unsigned long double testvar1 = 0;
unsigned long double testvar2 = 0;
unsigned long double testvar3 = 0;
int testtimer1 = 0;
int testtimer2 = 0;
int testtimer3 = 0;
long double HRVvar1 = 0;
long double HRVvar2 = 0;
long double HRVvar3 = 0;
long double hrvInterval1 = 0;
long double hrvInterval2 = 0;
long double numNNInterval =0;
long double numNN50 = 0;
long double pNN50 = 0;
int displayVal = 0;
int test = 25;
int nnIntervalcounter;
char ans1[2];

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
    heartRate = (60*heartBeatCounter)/10; //Change from 10s to 5s
    itoa(heartRate, heartRateOutput);

    WriteCmdXLCD(0b00000001);
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

void hrvCal(){
    pNN50 = (numNN50/numNNInterval)*100.0;
    displayVal = (int) pNN50;
    itoa(displayVal, ans1);
    while(BusyXLCD());
    SetDDRamAddr(0x40);
    while(BusyXLCD());
    putrsXLCD("HRV Rate:");
    while(BusyXLCD());
    SetDDRamAddr(0x48);
    while(BusyXLCD());
    putsXLCD(ans1);
    while(BusyXLCD());
    putrsXLCD("%");
    
    numNNInterval = 0;
    numNN50 = 0;
    pNN50 = 0;
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
    putrsXLCD("Press A Test");
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
    if(PIR1bits.TMR1IF == 1){
        if(timer1Period%19 == 0 && numNN50>0){
            PIR1bits.TMR1IF = 0;
            heartRateCal(); 
            hrvCal();
                        
        }        
        timer1Period = timer1Period++;
        WriteTimer1(0x0BDC);
    }    
    
    if(INTCON3bits.INT2IF){
        pulseCounting();
    }
    if(INTCON3bits.INT1IF){
        if (PORTCbits.RC7 && !PORTCbits.RC6 && !PORTCbits.RC5 && !PORTCbits.RC4)
        {
            startTimer = 1;
            timer1Setup();
            WriteCmdXLCD(0b00000001);
        }
        if (PORTCbits.RC7 && !PORTCbits.RC6 && PORTCbits.RC5 && PORTCbits.RC4)
        {
            CloseTimer1();          
        }
    }
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
    INTCONbits.PEIE =1;         //Enable Peripheral Interrupt Enable bit
 
    while(1);
}

