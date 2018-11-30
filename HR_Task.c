#include <p18f452.h>
#include <delays.h>
#include "xlcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <timers.h>


/*************Global Variable Declarations*********************/

int hbCount =0;
int hbStatus=1;     // initalize 
char output[20];

/*********************Function Declarations*************************/

void HB_Timer0(void)
{
    OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_256);
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
    
    return;
}

void stopHBs(void)
{
    hbStatus=1;
    PORTDbits.RD3 =0;
    INTCON3bits.INT1IE = 0;
    CloseTimer0();
    
    if(hbStatus==1)
    { 
  
        hbCount = (6*hbCount);
        sprintf(output,"BPM: %d",hbCount);
        
        while(BusyXLCD());
        SetDDRamAddr(0x00); //Start at first line
        putrsXLCD("                ");
        
        while(BusyXLCD());
        SetDDRamAddr(0x00); //Start at first line
        putsXLCD(output);
        
        // --------------- speaker trigger -----------
        if(hbCount > 120)    
        {Speaker_On_Task();}   
        else                    
        {};
        
        if(hbCount < 40 && hbCount > 0)    
        {Speaker_On_Task();}   
        else                    
        {};
        
 
        
        hbCount =0;
    }
    
    return;
}

void countHBs(void)
{
    if(hbStatus==0)
    {
    hbCount++;
    
    while(BusyXLCD());
    SetDDRamAddr(0x00); //Start at first line
    while(BusyXLCD());
    Delay1KTCYx(110); //LCD Refresh Time
    while(BusyXLCD());
    
    sprintf(output,"Calculating: %d",hbCount);
    putsXLCD(output); 
    }   
    
    return;
 } 
 

 void HR_Task(void)
 {
    
     //configure and start HB Counter
     hbCount =0;
     HB_Timer0();
     startHBs();
     
     return;
 }

  