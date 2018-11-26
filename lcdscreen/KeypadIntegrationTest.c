#include <p18f452.h> 
#include <delays.h>
#include "xlcd.h"

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

void low_isr (void);
void keyPad (void);


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


void keyPad (void)
{
/* -------------------------------KEYPAD KEYS---------------------------------*/
/*---The if statements are to determine the key pressed. The conditions are---*/
/*--------in the form of D output, C output B output and A output.------------*/

    //KEY "F"
    if ((PORTCbits.RC4) && (PORTCbits.RC5) && (PORTCbits.RC6) && (PORTCbits.RC7))
    {
        SetDDRamAddr(0x40);
        putrsXLCD("F");
    }
    
    //KEY "1"
    else if((!PORTCbits.RC4) && (!PORTCbits.RC5) && (!PORTCbits.RC6) && (!PORTCbits.RC7))
    {
        SetDDRamAddr(0x40);
        putrsXLCD("1");
    }
    
    //KEY "A"
    else if((!PORTCbits.RC4) && (!PORTCbits.RC5) && (!PORTCbits.RC6) && (PORTCbits.RC7))
    {
        SetDDRamAddr(0x40);
        putrsXLCD("A");
    }
    
    //KEY "2"
    else if((!PORTCbits.RC4) && (!PORTCbits.RC5) && (PORTCbits.RC6) && (PORTCbits.RC7))
    {
        SetDDRamAddr(0x40);
        putrsXLCD("2");
    }
    
    //KEY "3"
    else if(!(PORTCbits.RC4) && !(PORTCbits.RC5) && (PORTCbits.RC6) && (!PORTCbits.RC7))
    {
        SetDDRamAddr(0x40);
        putrsXLCD("3");
    }
    
    //KEY "4"
    else if(!(PORTCbits.RC4) && (PORTCbits.RC5) && !(PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        SetDDRamAddr(0x40);
        putrsXLCD("4");
    }
    
    //KEY "B"
    else if(!(PORTCbits.RC4) && (PORTCbits.RC5) && !(PORTCbits.RC6) && (PORTCbits.RC7))
    {
        SetDDRamAddr(0x40);
        putrsXLCD("B");
    }
    
    //KEY "6"
    else if(!(PORTCbits.RC4) && (PORTCbits.RC5) && (PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        SetDDRamAddr(0x40);
        putrsXLCD("6");
    }
    
    //KEY "5"
    else if(!(PORTCbits.RC4) && (PORTCbits.RC5) && (PORTCbits.RC6) && (PORTCbits.RC7))
    {
        SetDDRamAddr(0x40);
        putrsXLCD("5");
    }
    
    //KEY "7"
    else if((PORTCbits.RC4) && !(PORTCbits.RC5) && !(PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        SetDDRamAddr(0x40);
        putrsXLCD("7");
    }
    
    //KEY "C"
    else if((PORTCbits.RC4) && !(PORTCbits.RC5) && !(PORTCbits.RC6) && (PORTCbits.RC7))
    {
        SetDDRamAddr(0x40);
        putrsXLCD("C");
    }
    
    //KEY "9"
    else if((PORTCbits.RC4) && !(PORTCbits.RC5) && (PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        SetDDRamAddr(0x40);
        putrsXLCD("9");
    }
    
    //KEY "8"
    else if((PORTCbits.RC4) && !(PORTCbits.RC5) && (PORTCbits.RC6) && (PORTCbits.RC7))
    {
        SetDDRamAddr(0x40);
        putrsXLCD("8");
    }
    
    //KEY "0"
    else if((PORTCbits.RC4) && (PORTCbits.RC5) && !(PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        SetDDRamAddr(0x40);
        putrsXLCD("0");
    }
    
    //KEY "D"
    else if((PORTCbits.RC4) && (PORTCbits.RC5) && !(PORTCbits.RC6) && (PORTCbits.RC7))
    {
        SetDDRamAddr(0x40);
        putrsXLCD("D");
    }
    
    //KEY "E"
    else if((PORTCbits.RC4) && (PORTCbits.RC5) && (PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        SetDDRamAddr(0x40);
        putrsXLCD("E");
    }
    
    
    
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

    INTCONbits.GIEH =0;
    keyPad();
    INTCON3bits.INT1IF = 0; //clears the external interrupt flag
    INTCONbits.GIEH =1;
    INTCON3bits.INT1IE = 1;
}



void main(void)
{
    
    //set port pins that are used
    //pins used RB1, D  - RC4, C - RC5, B - RC6, A - RC7
    TRISCbits.RC7 = 1; //Output A from the encoder
    TRISCbits.RC6 = 1; //Output B from the encoder
    TRISCbits.RC5 = 1; //Output C from the encoder
    TRISCbits.RC4 = 1; //Output D from the encoder
   
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
    SetDDRamAddr(0x00);
    putrsXLCD("Test One");
    while(BusyXLCD());

    while(1);
       
}