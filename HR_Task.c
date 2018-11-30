#include <p18f452.h>
#include <delays.h>
#include "xlcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <timers.h>

#pragma config WDT = OFF //Disable watchdog timer
#pragma config LVP = OFF //Disable low voltage programming

#define _XTAL_FREQ 4000000UL

/*************Global Variable Declarations*********************/

int hbCount =0;
int hbStatus=0;
char output[20];

/*********************Function Declarations*************************/
void DelayFor18TCY(void)
{
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop();
     return;
}

void DelayXLCD(void)
{
    Delay1KTCYx(5);	
    return;
}

void DelayPORXLCD(void)
{
    Delay1KTCYx(15);
    return;
}

void init_LCD(void)
{ 
    PORTD = 0x00;
    TRISD = 0x00;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    while(BusyXLCD());
    WriteCmdXLCD( BLINK_ON );
    while(BusyXLCD());
    return;
 }

void HB_Timer0(void)
{
    OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_256);
    //T0CON = 0b11000111;
}

void HB_Interrupts(void)
{
     RCONbits.IPEN = 1;              //Enable Priority Levels
     INTCONbits.GIE = 1;             //bit 7	GIE/GIEH: Global Interrupt Enable bit, 
     INTCON2bits.INTEDG1 = 0;        //bit 5	INTEDG1: External Interrupt1 Edge Select bit, Interrupt on falling edge  
     INTCON3bits.INT1IP = 1;         //bit 6	INT1IP: INT1 External Interrupt Priority bit  
     INTCON3bits.INT1IE = 1;         //bit 3	INT1IE: INT1 External Interrupt Enable bit   
}


void startHBs(void)
{
    INTCONbits.TMR0IE = 1;          //Enable Timer0 Interrupt
    INTCONbits.TMR0IF = 0;          //Clear Timer0 Interrupt Flag
    INTCON2bits.TMR0IP = 1;          //Timer0 High Priority
    WriteTimer0(0x676A);            //Timer interrupts at 10s w/256 prescaler 
    TRISDbits.RD3 = 0;
    PORTDbits.RD3 =1;               //Configure RD3 as output, heartbeat led basically. 
    hbStatus = 0;
}

void stopHeartBeatSample(void)
{
    hbStatus=1;
    PORTDbits.RD3 =0;
    INTCON3bits.INT1IE = 0;
    CloseTimer0();
    
    if(hbStatus==1)
    { 
        while(BusyXLCD());
        SetDDRamAddr(0x00); //Start at first line
        while(BusyXLCD());
        Delay1KTCYx(110); //LCD Refresh Time
        while(BusyXLCD());
        
        hbCount = (6*hbCount);
        sprintf(output,"Heart Rate:%d BPM",hbCount);
        putsXLCD(output);
    }
}

void heartBeatCount(void)
{
    if(hbStatus==0){
    hbCount++;
    
    while(BusyXLCD());
    SetDDRamAddr(0x00); //Start at first line
    while(BusyXLCD());
    Delay1KTCYx(110); //LCD Refresh Time
    while(BusyXLCD());
    
    sprintf(output,"Calculating...: %d",hbCount);
    putsXLCD(output); 
    }    
 } 
    
 
/******************HIGH ISR******************/
void high_ISR(void);
 
#pragma code high_vector = 0x08
 void high_interrupt_vector(void){
     _asm 
     GOTO high_ISR
     _endasm
 }
#pragma code 
 
#pragma interrupt high_ISR
void high_ISR(void){
    INTCONbits.GIE = 0;
    
    if(INTCON3bits.INT1IF==1)
    {
        INTCON3bits.INT1IE = 0;
        heartBeatCount();
        INTCON3bits.INT1IF = 0;
        INTCON3bits.INT1IE = 1;
    }
    
    if(INTCONbits.TMR0IF==1)
    {
        INTCONbits.TMR0IE= 0;
        stopHeartBeatSample();
        INTCONbits.TMR0IF==0;
    }
    
    INTCONbits.GIE = 1;
    return;
}

 
 void main()
 {
     init_LCD();
     
     //configure and start HB Counter
     HB_Timer0();
     HB_Interrupts();
     startHBs();
     
     while(1)
     {
         
     }
 }
