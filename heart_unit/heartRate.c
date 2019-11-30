#include <p18f452.h>
#include <delays.h>
#include "xlcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <timers.h>
#include<PWM.h>


#pragma config WDT = OFF //Disable watchdog timer
#pragma config LVP = OFF //Disable low voltage programming

#define _XTAL_FREQ 4000000UL

//speaker defines 
#define Bf 0x85 //prescaler of 16

/*************Global Variable Declarations*********************/

int heartBeats =0;
int allowCount=0;
char out[20];

/*********************Function Declarations*************************/
void DelayFor18TCY(void){
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop();
     return;
}

void DelayXLCD(void){
    Delay1KTCYx(5);	
    return;
}

void DelayPORXLCD(void){
    Delay1KTCYx(15);
    return;
}

void init_LCD(void){
     
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

 void speaker(void){
    
    
    
    TRISCbits.TRISC2 = 0;
    SetDCPWM1(5);
    OpenTimer2(TIMER_INT_OFF & T2_PS_1_16 & T2_POST_1_1);
    while(1)
    {
     //for (i=0; i<x; i++) {     //play x notes inside song array
      
      OpenPWM1(Bf); 
                               //set PWM frequency according to entries in song array
      Delay1KTCYx(400); //each note is played for 400ms*relative length

      //OpenPWM1(1); 		//the PWM frequency set beyond audible range
                                //in order to create a short silence between notes
      //Delay10KTCYx(25); 	//play nothing for 50 ms                  
      //}
    }
}

void init_Timer0(void){
 
    OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_256);
}

void startHeartBeatSample(void){
    
    INTCONbits.TMR0IE = 1;          //Enable Timer0 Interrupt
    INTCONbits.TMR0IF = 0;          //Clear Timer0 Interrupt Flag
    INTCON2bits.TMR0IP = 1;          //Timer0 High Priority
    WriteTimer0(0x676A);            //Timer interrupts at 10s w/256 prescaler
    //WriteTimer0(57224); 
  //  TRISDbits.RD3 = 0;
  //  PORTDbits.RD3 =1;
    allowCount = 0;

}

void stopHeartBeatSample(void){
    allowCount=1;
 //   PORTDbits.RD3 =0;
    INTCON3bits.INT1IE = 0;
    CloseTimer0();
    
    if(allowCount==1){
    while(BusyXLCD());
    SetDDRamAddr(0x00); //Set cursor to top line
    while(BusyXLCD());
    Delay1KTCYx(110); //Give time for LCD to refresh, writing to it too quickly causes flicker issues
    while(BusyXLCD());
    heartBeats = (6*heartBeats);
    sprintf(out,"HR:%d BPM",heartBeats);
    putsXLCD(out); 
    if(heartBeats>=120 || heartBeats<=40){
        speaker(); }
    heartBeats =0;
    
    }
}

void heartBeatCount(void){

    if(allowCount==0){
    heartBeats++;
    while(BusyXLCD());
    SetDDRamAddr(0x00); //Set cursor to top line
    while(BusyXLCD());
    Delay1KTCYx(110); //Give time for LCD to refresh, writing to it too quickly causes flicker issues
    while(BusyXLCD());
    sprintf(out,"HRC: %d",heartBeats);
    putsXLCD(out); 
    }    
 } 
    
 
/******************INTERRUPT THINGS******************/
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
    
    if(INTCON3bits.INT1IF==1){
        INTCON3bits.INT1IE = 0;
        heartBeatCount();
        INTCON3bits.INT1IF = 0;
        INTCON3bits.INT1IE = 1;
    }
    
    if(INTCONbits.TMR0IF==1){
        INTCONbits.TMR0IE= 0;
        
        stopHeartBeatSample();
        INTCONbits.TMR0IF==0;
        
    }
    INTCONbits.GIE = 1;
    return;
}

/******************MAIN CODE******************/
 
 void main(){
     
     init_LCD();
     init_Timer0();
     RCONbits.IPEN = 1;              //Enable Priority Levels
     INTCON3bits.INT1IP = 1;
     INTCON2bits.INTEDG1 = 0;
     INTCON3bits.INT1IE = 1;
     INTCONbits.GIE = 1;
     TRISBbits.RB1 = 1;

     startHeartBeatSample();
     
  
     
     while(1){}
     
 }