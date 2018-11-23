#include <p18f452.h> 
#include <delays.h>
#include "xlcd.h"

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

void low_isr (void);
void menu (void);
void configKeyPorts (void);
void configLCD (void);

void DelayFor18TCY(void){
     Nop();
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop();
     Nop(); 
     Nop(); 
     Nop(); 
     Nop(); 
     Nop();
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

void conifgLCD ()
{
    while(BusyXLCD());
    OpenXLCD( FOUR_BIT & LINES_5X7  );
    SetDDRamAddr(0x00);
    WriteCmdXLCD(BLINK_ON);
    WriteCmdXLCD(SHIFT_DISP_LEFT);
}

void configKeyPorts (void)
{
    /*------------Configure Ports for Keypad-------------------*/
    /*------------------Pins used---------------------------*/
    /*External Interrupt INT1 - RB1; D - RC4; C - RC5; B - RC6; A - RC7*/
    TRISCbits.RC4 = 1;          //Output D from encoder
    TRISCbits.RC5 = 1;          //Output C from encoder
    TRISCbits.RC6 = 1;          //Output B from encoder
    TRISCbits.RC7 = 1;          //Output A from encoder
    TRISBbits.RB1 = 1;          //External Interrupt INT1
    
    INTCON3bits.INT1IE = 1;     //Enable the INT1 external interrupt
    INTCON3bits.INT1IF = 0;     //Clear external interrupt INT1 flag
    INTCON2bits.INTEDG1 = 1;    //Set interrupt INT1 on rising edge
    RCONbits.IPEN = 1;          //Enable Interrupt Priority
    INTCONbits.PEIE = 1;        //Enable Peripheral Interrupt Enable bit
    INTCONbits.GIEH = 1;        //Enable global interrupt bit
    INTCON3bits.INT1IP = 0;     //Set INT1 Priority bit to low priority   
}

void menu ()
{
    if((!PORTCbits.RC4) && (!PORTCbits.RC5) && (!PORTCbits.RC6) && (!PORTCbits.RC7))
    {
        configLCD();
        
    }
}

#pragma code low_vector=0x18
void interrupt_at_low_vector (void)
{
    _asm
    GOTO low_isr
    _endasm
}
#pragma

#pragma interruptlow low_isr
void low_isr (void)
{
    INTCONbits.GIEH = 0;            //Disable all interrupts
    
    menu();
    
    INTCON3bits.INT1IF = 0;         //Clears external interrupt flag
    INTCONbits.GIEH = 1;            //Enable all interrupts
    INTCON3bits.INT1IE = 1;         //Enable external interrupt INT1    
}


void main ()
{
    configLCD();
}
