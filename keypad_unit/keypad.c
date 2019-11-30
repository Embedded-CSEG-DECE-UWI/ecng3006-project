#include <p18f452.h>
#include <delays.h>
#include "xlcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <timers.h>



#pragma config WDT = OFF
#pragma config OSC = HS
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000UL

#define TRIS_INT0   TRISBbits.RB0
#define INT0        PORTBbits.RB0

#define TRIS_DATA0  TRISCbits.RC6
#define DATA0       PORTCbits.RC6

#define TRIS_DATA1  TRISCbits.RC5
#define DATA1       PORTCbits.RC5

#define TRIS_DATA2  TRISCbits.RC4
#define DATA2       PORTCbits.RC4

#define TRIS_DATA3  TRISDbits.RD3
#define DATA3       PORTDbits.RD3

/*************Global Variable Declarations*********************/
char display;
char datavalue[2];
int data;



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

void setup(void)
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
    
    if(INTCONbits.INT0IF==1)
    {
        INTCONbits.INT0IE = 0;
        
        data =( (DATA0*4) + (DATA1*2) + (DATA2*1) + (DATA3*8) );
        Nop();
        switch (data)
        {
            case (0): //case0
                display ='1';
                break;
            
            case(1): //case1
                display ='2';
                break;
                
            case(2)://case2
                display ='3';
                break;
                
            
            case (3): //case3
                display ='A';
                break;
            
            case (4): //case4
                display ='4';
                break;
                
            case(5): //case5
                display ='5';
                break;       
       
            
            case(6)://case6
                display ='6';
                break;
                
            case(7)://case7
                display ='B';
                break;
                 
            case(8)://case8
                display ='7';
                break;
                
            case(9)://case9
                display ='8';
                break; 
              
              
            case(10)://case10
                display ='9';
                break;
                
            case(11)://case11
                display ='C';
                break;    
            
            case(12)://case12
                display ='0';
                break;
                
            case(13)://case13
                display ='F';
                break;
      
            
            case(14)://case14
                display ='E';
                break;
                
            case(15):
                display ='D';       
                break;
                
            default:
                display ='?';
                break;
              
        }

    while (BusyXLCD());
    putcXLCD(display);
    DelayPORXLCD();
    
    /*while (BusyXLCD());
    SetDDRamAddr(0x10);
    
    itoa(data, datavalue);
    while (BusyXLCD());
    putrsXLCD("data value: ");
    while (BusyXLCD());
    putsXLCD(datavalue);
    DelayPORXLCD();*/
    
    while (BusyXLCD());
    SetDDRamAddr(0x00);
  
    INTCONbits.INT0IF = 0;
    INTCONbits.INT0IE = 1;
    
    INTCONbits.GIE = 1;
    return;
}

}
/******************MAIN CODE******************/
 
 void main(void){
     
     setup();
     RCONbits.IPEN = 1;              //Enable Priority Levels
     INTCON2bits.INTEDG0 = 1;       
     INTCONbits.INT0IE  =1; 
     INTCONbits.PEIE= 1;///
     INTCONbits.GIE = 1;
     TRIS_INT0 =1;
     TRIS_DATA0 =1;
     TRIS_DATA1 =1;
     TRIS_DATA2 =1;
     TRIS_DATA3 =1;
     
     //startHeartBeatSample();
     
     while(1){}
     
 }