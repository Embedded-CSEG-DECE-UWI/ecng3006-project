#include <p18f452.h> 
#include <delays.h>
#include "xlcd.h"

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

void low_isr(void);
void keypress(void);
char key[1];                        //variable for key pressed


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
  if (!PORTBbits.RB7 && !PORTBbits.RB6 && !PORTBbits.RB5 && !PORTBbits.RB4 )
    {
        key[0] = '1';
    }
  if (PORTBbits.RB7 && PORTBbits.RB6 && !PORTBbits.RB5 && !PORTBbits.RB4 )
    {
        key[0] = '2';
    } 
  if (!PORTBbits.RB7 && PORTBbits.RB6 && !PORTBbits.RB5 && !PORTBbits.RB4)
    {
        key[0] = '3';
    } 
  if (!PORTBbits.RB7 && !PORTBbits.RB6 && PORTBbits.RB5 && !PORTBbits.RB4)
    {
        key[0] = '4';
    }
  if (PORTBbits.RB7 && PORTBbits.RB6 && PORTBbits.RB5 && !PORTBbits.RB4 )
    {
        key[0] = '5';
    }
  if (!PORTBbits.RB7 && PORTBbits.RB6 && PORTBbits.RB5 && !PORTBbits.RB4 )
    {
        key[0] = '6';
    }
  if (!PORTBbits.RB7 && !PORTBbits.RB6 && !PORTBbits.RB5 && PORTBbits.RB4 )
    {
        key[0] = '7';
    }
  if (PORTBbits.RB7 && PORTBbits.RB6 && !PORTBbits.RB5 && PORTBbits.RB4 )
    {
        key[0] = '8';
    }
  if (!PORTBbits.RB7 && PORTBbits.RB6 && !PORTBbits.RB5 && PORTBbits.RB4 )
    {
        key[0] = '9';
    }
  if (!PORTBbits.RB7 && !PORTBbits.RB6 && PORTBbits.RB5 && PORTBbits.RB4 )
    {
        key[0] = '0';
    }
  if (PORTBbits.RB7 && !PORTBbits.RB6 && !PORTBbits.RB5 && !PORTBbits.RB4 )
    {
        key[0] = 'A';
    }
  if (PORTBbits.RB7 && !PORTBbits.RB6 && PORTBbits.RB5 && !PORTBbits.RB4 )
    {
        key[0] = 'B';
    }
  if (PORTBbits.RB7 && !PORTBbits.RB6 && !PORTBbits.RB5 && PORTBbits.RB4 )
    {
        key[0] = 'C';
    }
  if (PORTBbits.RB7 && !PORTBbits.RB6 && PORTBbits.RB5 && PORTBbits.RB4 )
    {
        key[0] = 'D';
    }
  if (!PORTBbits.RB7 && PORTBbits.RB6 && PORTBbits.RB5 && PORTBbits.RB4 )
    {
        key[0] = 'E';
    }
  if (PORTBbits.RB7 && PORTBbits.RB6 && PORTBbits.RB5 && PORTBbits.RB4 )
    {
        key[0] = 'F';
    }
}
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
    OpenXLCD(FOUR_BIT & LINES_5X7);     //open the LCD and sets it to 4 bit and multiple line mode
    while(BusyXLCD());
    SetDDRamAddr(0x00);                 //sets the cursor to the top left
    while(BusyXLCD()); 
    WriteCmdXLCD(BLINK_ON);             //allow the cursor to blink
    while(BusyXLCD());          
    WriteCmdXLCD(SHIFT_DISP_LEFT);      //shift the display to the left
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
    TRISBbits.RB7 = 1; //A
    TRISBbits.RB6 = 1; //B
    TRISBbits.RB5 = 1; //C
    TRISBbits.RB4 = 1; //D
}
void main(void)         //main function
{
    interruptinit();        //call interrupt setup function
    keypadsetup();          //call keypad setup function
    LCDinit();              //call lcd setup function
    while(BusyXLCD());      //command to stall when the lcd is busy
    putrsXLCD("KEYPAD TEST");    //writes to the screen
    Delay10KTCYx(200);           //Delay to stop flickering on the screen
    WriteCmdXLCD(0b00000001);    //clears the screen
    while(BusyXLCD());
    key[0] = 'N';               //Assign default value to key
    key[1] = '\0';              //null
    putsXLCD(key);              //write to the screen
    while(1){        
        putsXLCD(key);                  //write from data memory to screen
        Delay10KTCYx(50);               //delay
        WriteCmdXLCD(0b00000001);       //clears the screen
    }                        
}