#include <p18f452.h>
#include <delays.h>
#include <stdlib.h>
#include <stdio.h>
#include "LCD stuff/xlcd.h"

/* Set configuration bits for use with PICKit3 */
#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

#define k0 PORTCbits.RC4
#define k1 PORTCbits.RC5
#define k2 PORTCbits.RC6
#define k3 PORTCbits.RC7 

char option;

int press = 0;

char lcdVariable[20];


/*Delays for 18 instruction cycles*/
void DelayFor18TCY(void){
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();
    Nop(); Nop(); Nop(); Nop(); Nop(); Nop();         
}
 
/*Delays for 5ms*/
void DelayXLCD(void){                                   //1000us = 1ms
    Delay1KTCYx(5);  
 }
 
/*Delays for 15ms*/
void DelayPORXLCD(void){
    Delay1KTCYx(15);
 }
 
/*Initializes LCD screen for use*/
void initLCD(void){
     OpenXLCD(FOUR_BIT & LINES_5X7);
     while(BusyXLCD());
     WriteCmdXLCD(SHIFT_DISP_LEFT);
     while(BusyXLCD());
     WriteCmdXLCD(DON & BLINK_OFF);
     while(BusyXLCD());
}

/*Function Prototypes*/
void highISR (void);
void lowISR (void);
void configInterrupts (void);
int checkPressedKey (void);
void printLCD (void);

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
        
        checkPressedKey();
        press = 1;
        INTCON3bits.INT2IE = 1;
    }  
    INTCONbits.GIE = 1;
}

#pragma code LOW_INTERRUPT_VECTOR = 0x18               //tells the compiler that the high interrupt vector is located at 0x08
void low_interrupt_vector(void){                   
    _asm                                                //allows asm code to be used into a C source file
    goto lowISR                                        //goes to interrupt routine
    _endasm                                             //ends asm code insertion
}
#pragma code

#pragma interrupt lowISR
void lowISR (void){                                    //interrupt service routine for the high priority vector
    INTCONbits.GIE = 0;
    
    INTCONbits.GIE = 1;
}

void configInterrupts(void){
    RCONbits.IPEN = 1;                                  //allows the priority level interrupts to be used
    INTCONbits.GIE = 1;                                 //enables global interrupt sources
    
    INTCON2bits.INTEDG2 = 1;                            //sets the pin to interrupt on a low to high transition 
    
    INTCON3bits.INT2IP = 1;
    INTCON3bits.INT2IE = 1;                              //enables the INT1 interrupt source
}

int checkPressedKey(){
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
    putsXLCD(lcdVariable);
    while(BusyXLCD());
}

void home (void){
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    putrsXLCD("Please choose: ");
    while(BusyXLCD());
    SetDDRamAddr(0x40);
    while(BusyXLCD());
    putrsXLCD("1.Measurement");
    while(BusyXLCD());
    SetDDRamAddr(0x10);
    while(BusyXLCD());
    putrsXLCD("2.Storage");
    while(BusyXLCD());
}

void menu (char key){        
    switch(key){
        case '1':
            WriteCmdXLCD(0x01);
            while(BusyXLCD());
            putrsXLCD("Measuring...");
            while(BusyXLCD());
            break;
        
        case '2':
            WriteCmdXLCD(0x01);
            while(BusyXLCD());
            putrsXLCD("Storing...");
            while(BusyXLCD());
            break;  
        
        case '0':
            home();
        break;
        
        default:
            break;                
    }
}

void main (void){
    initLCD();
    configInterrupts();

    TRISC = 0xFF;
    
    home();
    
    while(1){    
        if (press == 1){
            menu(option);
            press = 0;
        }
    }
    
    Sleep();
}