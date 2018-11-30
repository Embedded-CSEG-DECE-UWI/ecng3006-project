#include<p18f452.h>
#include<delays.h>
#include"xlcd.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<timers.h>
#include<capture.h>
#include<string.h>
#include<math.h>
#include<float.h>

unsigned int first_read=0,
            next_read=0,
            risingEdges=0,
            interval=0,
            overFlow=0,
            t=0,
            y=0,
            final=0,
            nn=0,
            nn_50=0;
float temp=0;
float current_hrv=0;

void init_timer(void);
void high_isr(void);
void init_lcd(void);

void init_timer()
{
    OpenTimer1 (TIMER_INT_ON & T1_16BIT_RW & T1_PS_1_1 & T1_OSC1EN_OFF & T1_SYNC_EXT_OFF & T1_SOURCE_INT & T1_SOURCE_CCP );  
    OpenCapture2 (CAPTURE_INT_ON & C2_EVERY_RISE_EDGE);    
}

void disp_hrv(void)
{
    int temp_var = 0;
    char hrvv[20];
    temp_var = current_hrv;

    sprintf(hrvv,"HRV: %d%",temp_var);
    
    while( BusyXLCD() );
    SetDDRamAddr( 0x40 );
    putrsXLCD("                ");
    
    while( BusyXLCD() );
    SetDDRamAddr( 0x40 );
    putsXLCD(hrvv);
    Delay10KTCYx(0x64);
    
    if(temp_var > 20)    
    {Speaker_On_Task();}   
    else                    
    {};
}


void hrvMain(void)
{
    if(risingEdges == 0)
    {
        if (y==0)
        { 
            while(BusyXLCD());
            SetDDRamAddr(0x40);
            while(BusyXLCD());
            putrsXLCD("Calculating..."); 
            while(BusyXLCD());
            
            first_read = ReadCapture2();  
        }
        else
        {
            next_read = ReadCapture2();   
        }
    } 
    else if ( (risingEdges == 1) && (y ==0 ))
    {
        next_read = ReadCapture2();   
    }
    
    risingEdges++;
    
    if( (risingEdges > 1) || (y == 1))
    {
        y=1;
        interval = 65535*overFlow + next_read-first_read;
        nn++;
        t = next_read;                                      // prev was here, if there are errors, switch back t to prev
        first_read = t;                                     // prev was here, if there are errors, switch back t to prev
        temp = (float)interval/(float)1000;
        
        if((float)temp > (float)50)
        {  
            nn_50++;
            PORTDbits.RD3 = !PORTDbits.RD3;//Heartbeat LED on RD3 
        }
        
        risingEdges = 0;
    
        if(nn>10)
        {
            current_hrv = (float)nn_50/(float)10;
            current_hrv = current_hrv*100;
            final = 1;       
            CloseCapture2();
            CloseTimer1();
        }
    
        if (final == 1)
        {
            disp_hrv();
            PORTDbits.RD3 = 0;//HeartBeat LED On RD3
        }
    }
}


void overflow_inc(void)
{
    overFlow++;
    return;
}

void init_vars(void)
{
    first_read=0;
    next_read=0;
    risingEdges=0;
    interval=0;
    overFlow=0;
    t=0;
    y=0;
    final=0;
    nn=0;
    nn_50=0;
    temp=0;
    current_hrv=0; 
    
    return;
}

void HRV_Task(void)
{      
    init_vars();
    init_timer();                    //Initialize Timer3 and Capture mode
    
    
    return; 
}




