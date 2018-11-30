#include <p18f452.h>
#include <delays.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "xlcd.h"

#pragma config WDT = OFF //Disable watchdog timer
#pragma config LVP = OFF //Disable low voltage programming

#define _XTAL_FREQ 4000000UL

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
    TRISD = 0x00;
    PORTD = 0x00;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    while(BusyXLCD());
    WriteCmdXLCD( BLINK_ON );
    while(BusyXLCD());
    return;
 }


void Key_Check(void)
{
    int encoder;    
    char key[20];
    char display[20];
    
    // Read encoder
    encoder = 0;
    encoder = encoder | PORTCbits.RC7;
    encoder = encoder << 1;
    encoder = encoder | PORTCbits.RC6;
    encoder = encoder << 1;
    encoder = encoder | PORTCbits.RC5;
    encoder = encoder << 1;
    encoder = encoder | PORTCbits.RC4;
    
    // Switch case 
    switch (encoder)
    {
        case 0x00:
          sprintf(key,"1");
          break;
          
        case 0x01:
          sprintf(key,"4");
          break;
          
        case 0x03:
          sprintf(key,"7");
          break;
          
        case 0x02:
          sprintf(key,"*");
          break;
          
        case 0x04:
          sprintf(key,"2");
          break;
          
        case 0x05:
          sprintf(key,"5");
          break;
          
        case 0x07:
          sprintf(key,"8");
          break;
          
        case 0x06:
          sprintf(key,"0");
          break;
          
        case 0x08:
          sprintf(key,"3");
          break;
          
        case 0x09:
          sprintf(key,"6");
          break;
          
        case 0x0B:
          sprintf(key,"9");
          break;
          
        case 0x0A:
          sprintf(key,"E");
          break;
          
        case 0x0C:
          sprintf(key,"A");
          break;
          
        case 0x0D:
          sprintf(key,"B");
          break;
          
        case 0x0F:
          sprintf(key,"C");
          break;
          
        case 0x0E:
          sprintf(key,"D");
          break;
          
    }
        // Display 
        while(BusyXLCD());
        SetDDRamAddr(0x50);
        while(BusyXLCD());
        sprintf(display,"Key Pressed: %s",key);
        putsXLCD(display);   
 } 

    
 
// -------------------------------- INTERRUPT ----------------------------------
void high_ISR(void);
 
#pragma code high_vector = 0x08
 void high_interrupt_vector(void){
     _asm 
     GOTO high_ISR
     _endasm
 }
#pragma code 
 
#pragma interrupt high_ISR
void high_ISR(void)
{
    // Disable global interrupts
    INTCONbits.GIE = 0;
    
    // Keypad interrupt
    if(INTCONbits.INT0F==1)
    {
     Key_Check();
     INTCONbits.INT0E = 0;
     INTCONbits.INT0F = 0; 
    }

    // Re-enable interrupts
    INTCONbits.INT0E = 1;
    INTCONbits.GIE = 1;
    
    return;
}
// -----------------------------------------------------------------------------
 

 void main()
 {
     //Enable INTCON global interrupt bit
     INTCONbits.GIE = 1;    
     
   //Set inputs
    TRISCbits.RC7=1;      
    TRISCbits.RC6=1;
    TRISCbits.RC5=1;
    TRISCbits.RC4=1; 
    
    // External interrupt
    INTCONbits.INT0IE = 1;      //Enable INT0 
    INTCON2bits.INTEDG0 = 0;    //Falling Edge
    
    init_LCD();

     while(1)
     {
       
     }
    
 }
