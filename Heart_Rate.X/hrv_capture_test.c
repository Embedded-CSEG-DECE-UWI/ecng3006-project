#include <p18f452.h>
#include "xlcd.h"
#include <delays.h>
#include <timers.h>
#include <stdlib.h>
#include <string.h>
#include <capture.h>
#include "xlcd.h"

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

void high_isr (void);
void low_isr (void);
void heartRateCal();
void timer1Setup();
unsigned long var = 0;
unsigned long var2 = 0;

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

unsigned double var1 = 0;
char ans1[2];
char ans2[3];
char ans3[10];

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
    timer1Setup();
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
    if(PIR2bits.CCP2IF == 1){
        
        PIR2bits.CCP2IF = 0;
        
        //Adapted from Asif Edoo
        if(HRVvar1 == 0 && HRVvar2 == 0 && HRVvar3 ==0){
            //HRVvar1 = ReadCapture2(); 
            testvar1 = (long)ReadCapture2();
            testtimer1 = timer1Period;
            ////HRVvar1 = HRVvar1 + (timer1Period * 500000);   
            //HRVvar1 = HRVvar1*timer1Period;
            HRVvar1 = testvar1*timer1Period;
            Nop();
        }
        else if(HRVvar1 != 0 && HRVvar2 == 0 && HRVvar3 == 0){
            //HRVvar2 = ReadCapture2();
            testvar2 = (long)ReadCapture2();
            testtimer2 = timer1Period;
            //HRVvar2 = HRVvar2 + (timer1Period * 500000);
            //HRVvar2 = HRVvar2 *timer1Period;
            HRVvar2 = testvar2 *timer1Period;
            if(HRVvar2 < HRVvar1){
                hrvInterval1 = HRVvar1 - HRVvar2;
            }
            if(HRVvar1 < HRVvar2){
                hrvInterval1 = HRVvar2 - HRVvar1; 
            }            
            numNNInterval = numNNInterval + 1.0;           
        }
        else if(HRVvar1 != 0 && HRVvar2 != 0 && HRVvar3 == 0){
            //HRVvar3 = ReadCapture2();
            testvar3 = (long)ReadCapture2();
            testtimer3 = timer1Period;
            //HRVvar3 = HRVvar3 + (timer1Period * 500000);
            //HRVvar3 = HRVvar3*timer1Period;
            HRVvar3 = testvar3*timer1Period;
            if(HRVvar3 < HRVvar2){
                hrvInterval2 = HRVvar2 - HRVvar3;
            }
            if(HRVvar2 < HRVvar3){
                hrvInterval2 = HRVvar3 - HRVvar2; 
            }
            numNNInterval = (long) numNNInterval+ 1.0;            
           if(hrvInterval2 < hrvInterval1 ){
                if(hrvInterval1 - hrvInterval2 > 50000){ numNN50++; }
            }
            else if(hrvInterval2 > hrvInterval1){
                if(hrvInterval2 - hrvInterval1 > 50000){ numNN50++; }
                
            }

            Nop();
            HRVvar3 = 0;
            HRVvar2 = 0;
            HRVvar1 = 0;
            hrvInterval1 = 0;
            hrvInterval2 = 0;
        }                                
    
    }         
        
    //PIR2bits.CCP2IF = 0;
    PIR2bits.CCP2IF = 0;  

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
    //Restarts the timer and checks current period
    if(PIR1bits.TMR1IF == 1){
        if(timer1Period%19 == 0 && numNN50>0){       
            pNN50 = (numNN50/numNNInterval)*100.0;
            displayVal = (int) pNN50;
            itoa(displayVal, ans1);
            while(BusyXLCD());
            SetDDRamAddr(0x40);
            while(BusyXLCD());
            putsXLCD(ans1);
            while(BusyXLCD());
            SetDDRamAddr(0x44);
            while(BusyXLCD());
            putrsXLCD("*");
            numNNInterval = 0;
            numNN50 = 0;
            pNN50 = 0;
                        
        }        
        timer1Period = timer1Period++;
        WriteTimer1(0x0BDC);
    }
  
    PIR1bits.TMR1IF = 0;
}

void lcdSetup (void)
{ 
    //while(BusyXLCD());
    OpenXLCD(FOUR_BIT & LINES_5X7); //four bit mode and multiple line display
    while( BusyXLCD() );
    WriteCmdXLCD( FOUR_BIT & LINES_5X7 );
    while( BusyXLCD() );
    WriteCmdXLCD(BLINK_ON );
    while( BusyXLCD() );
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    while (BusyXLCD());
    SetDDRamAddr(0x00);
    while (BusyXLCD());
    putrsXLCD("Testing HRV");
    while(BusyXLCD());
    SetDDRamAddr(0x40);
    while(BusyXLCD());
    putrsXLCD("00 %");
    
}

void main()
{
    //SETUP 
    lcdSetup();
    captureSetup();
    INTCONbits.GIEH = 1;        //Global Interrupt Enable bit
    RCONbits.IPEN = 1;          //Enable Interrupt Priority 
    INTCONbits.PEIE =1;         //Enable Peripheral Interrupt Enable bit
    while(1);
}


