#include <p18f452.h> 
#include <delays.h>
#include "xlcd.h"

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

void low_isr(void);
void keypress(void);
void start(void);
void number(void);
void intervals(void);
void storage(void);
void menu(void);

#pragma code low_vector=0x18        //taken from C18 users guide page 29

void interrupt_at_low_vector(void)  
{
    _asm 
    GOTO low_isr 
    _endasm 
} 

#pragma code 

#pragma interruptlow low_isr
void low_isr(void)
{
    WriteCmdXLCD(0b00000001);   //clears the LCD display
    keypress();                 //call the keypad function
    INTCON3bits.INT1IF = 0;     //clears the external interrupt flag
}


void keypress(void)  //function used to determine which key is pressed
{
  if (PORTDbits.RD7 && !PORTDbits.RD6 && !PORTDbits.RD5 && !PORTDbits.RD4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    start();
    putrsXLCD("INSERT PROCESS 1");
    Delay10KTCYx(200);
    menu();
    }
  if (PORTDbits.RD7 && !PORTDbits.RD6 && PORTDbits.RD5 && !PORTDbits.RD4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    number();
    putrsXLCD("INSERT PROCESS 2");
    Delay10KTCYx(200);
    menu();
    }
  if (PORTDbits.RD7 && !PORTDbits.RD6 && !PORTDbits.RD5 && PORTDbits.RD4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    intervals();
    putrsXLCD("INSERT PROCESS 3");
    Delay10KTCYx(200);
    menu();
    }
  if (PORTDbits.RD7 && !PORTDbits.RD6 && PORTDbits.RD5 && PORTDbits.RD4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    storage();
    putrsXLCD("INSERT PROCESS 4");
    Delay10KTCYx(200);
    menu();
    }
    if (!PORTDbits.RD7 && PORTDbits.RD6 && PORTDbits.RD5 && PORTDbits.RD4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("INTERVALS(C)  <F");
    SetDDRamAddr(0x10);
    putrsXLCD("STORAGE(D)       ");
    while(BusyXLCD());
    }
  if (PORTDbits.RD7 && PORTDbits.RD6 && PORTDbits.RD5 && PORTDbits.RD4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("START(A)      >E");
    SetDDRamAddr(0x10);
    putrsXLCD("# OF READINGS(B) ");
    while(BusyXLCD());
    }
}

void start(void){}
void number(void){}
void intervals(void){}
void storage(void){}
void DelayFor18TCY(void) //delay
{
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

void DelayXLCD(void) //delay
{
    Delay1KTCYx(5);	
    return;
}

void DelayPORXLCD(void) //delay
{
    Delay1KTCYx(15);
    return;
}
void LCDinit(void)                  //function to initialize the LCD
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

void interruptinit(void)          //function to initialize the interrupt
{
    INTCONbits.PEIE =1;     //enable peripheral interrupt enable bit
	INTCONbits.GIEH = 1;    //enable all high priority interrupts global interrupt bit
    INTCON2bits.INTEDG1= 1; //set interrupt on rising edge
    INTCON3bits.INT1IE = 1; //enable the external interrupt in RB1
    INTCON3bits.INT1IF = 0; //clear external interrupt INT1 flag
    RCONbits.IPEN = 1;      //enable interrupt priority 
    INTCON3bits.INT1IP = 0; //Set INT1 Priority bit to low priority
}

void keypadsetup(void)
{
    TRISDbits.RD7 = 1; //A
    TRISDbits.RD6 = 1; //B
    TRISDbits.RD5 = 1; //C
    TRISDbits.RD4 = 1; //D
}

void menu(void)
{
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("START(A)      >E");
    SetDDRamAddr(0x10);
    putrsXLCD("# OF READINGS(B) ");
    while(BusyXLCD());
}
void main(void)         //main function
{
    interruptinit();        //call interrupt setup function
    keypadsetup();          //call keypad setup function
    LCDinit();              //call lcd setup function
    while(BusyXLCD());      //command to stall when the lcd is busy
    putrsXLCD("MENU TEST");    //writes to the screen
    while(BusyXLCD());
    Delay10KTCYx(200);
    while(BusyXLCD());
    WriteCmdXLCD(0b00000001);
    menu();
    while(1);               //waits
}