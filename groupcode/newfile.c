
#include <p18f452.h> 
#include <delays.h>
#include "xlcd.h"
//#include <portb.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

void low_isr (void);
//void dummy (void);
//void keyPad (void);
//int cnt = 0;

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
void LETTHISWORK (void)
{ 
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x00); 
    while(BusyXLCD()); 
    WriteCmdXLCD(BLINK_ON);
    while(BusyXLCD());
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    while(BusyXLCD());
}



//Needs working on
#pragma code low_vector=0x18
void interrupt_at_low_vector(void)
{
    _asm 
    GOTO  low_isr 
    _endasm
}
#pragma code

#pragma interruptlow low_isr
void low_isr(void)
{
    INTCON3bits.INT1IF = 0; //clears the external interrupt flag
}

void main(void)
{
    
    //set port pins that are used
    //pins used RB0, D  - RA4, C - RA5, B - RE0, A - RE1
    //PORTAbits.RA4 = 0;
    //PORTAbits.RA5 = 0;
    //PORTEbits.RE0 = 0;
    //PORTEbits.RE1 = 0;
    TRISAbits.RA4 = 1; //A
    TRISAbits.RA5 = 1; //B
    TRISEbits.RE0 = 1; //C
    TRISEbits.RE1 = 1; //D
    
    //OpenRB0INT (PORTB_CHANGE_INT_ON & RISING_EDGE_INT);
    //PORTBbits.INT0=0;
    TRISBbits.RB1= 1;
   
    INTCON3bits.INT1IE = 1; //enable the INT1 external interrupt 
    INTCON3bits.INT1IF = 0;//clear external interrupt INT1 flag
	INTCON2bits.INTEDG1= 1; //set interrupt INT1 on rising edge
    RCONbits.IPEN = 1;      // Enable Interrupt Priority 
    INTCONbits.PEIE =1;     //Enable Peripheral Interrupt Enable bit
	INTCONbits.GIEH = 1;    //Enable all high priority interrupts/ global interrupt bit
    INTCON3bits.INT1IP = 0; //Set INT1 Priority bit to high priority
    
    
    LETTHISWORK();
        while(BusyXLCD());
       // putrsXLCD(""); 
        SetDDRamAddr(0x00);
        //putrsXLCD("0_0");
        //SetDDRamAddr(0x54);
        putrsXLCD("Test One");
        while(BusyXLCD());
        //dummy();
        //Delay1KTCYx(1);
        INTCONbits.INT0IF = 1;
        while(1);
       
}