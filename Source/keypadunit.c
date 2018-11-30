#include <p18cxxx.h>
#include <delays.h>
#include <stdlib.h>
#include <stdio.h>
#include "xlcd.h"

/* Set configuration bits for use with PICKit3 */
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

#define k0 PORTCbits.RC4
#define k1 PORTCbits.RC5
#define k2 PORTCbits.RC6
#define k3 PORTCbits.RC7    

char option;
//the system should allow a user to specify intervals at which readings should be stored to external ?ash RAM, and the number of measurements to be stored.
char lcdVariable[20];

void DelayFor18TCY(void)
 {
         Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
         Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
         Nop(); Nop(); Nop(); Nop(); Nop(); Nop();         
 }
 
void DelayXLCD(void){                  //1000us = 1ms
     Delay1KTCYx(5);
     
 }
 
void DelayPORXLCD(void){
     Delay1KTCYx(15);
 }
 
void init_lcd(void)
{ 
     OpenXLCD(FOUR_BIT & LINES_5X7);
     while(BusyXLCD());
     WriteCmdXLCD(SHIFT_DISP_LEFT);
     while(BusyXLCD());
}
void highISR();

#pragma code HIGH_INTERRUPT_VECTOR = 0x08               //tells the compiler that the high interrupt vector is located at 0x08
void high_interrupt_vector(void){                   
    _asm                                                //allows asm code to be used into a C source file
    goto highISR                                        //goes to interrupt routine
    _endasm                                             //ends asm code insertion
}
#pragma code

#pragma interrupt highISR
void highISR (void){                                    //interrupt service routine for the high priority vector
    INTCONbits.GIE = 0;
    
    /*Routine for external interrupt on INT1*/
    if(INTCON3bits.INT2IF == 1){
        INTCON3bits.INT2IE = 0;
        INTCON3bits.INT2IF = 0;
        
        check();
        
        INTCON3bits.INT2IE = 1;
    }
    
    
    INTCONbits.GIE = 1;
}
void configInterrupts(void){
    RCONbits.IPEN = 1;                                  //allows the priority level interrupts to be used
    INTCONbits.GIE = 1;                                 //enables global interrupt sources
    
      

    INTCON2bits.INTEDG2 = 0;                            //sets the pin to interrupt on a low to high transition 
    
    INTCON3bits.INT2IP = 1;
    INTCON3bits.INT2IE = 1;                              //enables the INT1 interrupt source
}


int check(){
    if(k3==0 && k2==0 && k1==0 && k0==0){
        option = '1';
        return option;
    }
    
    if(k3==0 && k2==1 && k1==0 && k0==0){
        option = '2';
        return option;
    }
    
    if(k3==1 && k2==0 && k1==0 && k0==0){
        option = '3';
        return option;
    }
    
    if(k3==0 && k2==0 && k1==0 && k0==1){
        option = '4';
        return option;
    }
    
    if(k3==0 && k2==1 && k1==0 && k0==1){
        option = '5';
        return option;
    }
    
    if(k3==1 && k2==0 && k1==0 && k0==1){
        option = '6';
        return option;
    }
    
    if(k3==0 && k2==0 && k1==1 && k0==0){
        option = '7';
        return option;
    }
    
    if(k3==0 && k2==1 && k1==1 && k0==0){
        option = '8';
        return option;
    }
    
    if(k3==1 && k2==0 && k1==1 && k0==0){
        option = '9';
        return option;
    }
    
    if(k3==0 && k2==0 && k1==1 && k0==1){
        option = '0';
        return option;
    }
    
    if(k3==1 && k2==1 && k1==0 && k0==0){
        option = 'A';
        return option;
    }
    
    if(k3==1 && k2==1 && k1==0 && k0==1){
        option = 'B';
        return option;
    }
    
    if(k3==1 && k2==1 && k1==1 && k0==0){
        option = 'C';
        return option;
    }
    
    if(k3==1 && k2==1 && k1==1 && k0==1){
        option = 'D';
        return option;
    }
    
    if(k3==1 && k2==0 && k1==1 && k0==1){
        option = 'E';
        return option;
    }
    
    if(k3==0 && k2==1 && k1==1 && k0==1){
        option = 'F';
        return option;
    }
}

void printLCD (void){  
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    sprintf(lcdVariable, "Num: %c", option);
    while(BusyXLCD());
    putsXLCD(lcdVariable);
    while(BusyXLCD());
}


void main(void)
{
    init_lcd();
    configInterrupts();

    TRISC = 0xFF;
    TRISBbits.RB2 = 1;
    
    
    while(1)
    {    

        //check();
 
        printLCD();
        //show something on LCD
    }
    
  
    Sleep();
}