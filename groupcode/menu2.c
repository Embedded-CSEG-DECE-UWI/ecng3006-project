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
void menuinit(void);
void menu(void);
void checkkey(void);

char key[1];                        //variable for key pressed
char ivl[1];                      //variable for interval choice
char changekey[1];                  //variable for when the key is changed

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
    changekey[0]='1';
    INTCON3bits.INT1IF = 0;     //clears the external interrupt flag
}


void keypress(void)  //function used to determine which key is pressed
{
    if (key[0]=='B')
    {
        if (PORTBbits.RB7 && !PORTBbits.RB6 && !PORTBbits.RB5 && !PORTBbits.RB4)
            {
                ivl[0]='1';       //5 second interval;
            }
        if (PORTBbits.RB7 && !PORTBbits.RB6 && PORTBbits.RB5 && !PORTBbits.RB4)
            {
                ivl[0]='2';       //10 second interval function
            }
        key[0]='n';
        menu();
    }
    else
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

void menuinit(void){        //menu initialisation 
    while(BusyXLCD());      //command to stall when the lcd is busy
    putrsXLCD("MENU TEST");    //writes to the screen
    while(BusyXLCD());
    Delay10KTCYx(200);
    while(BusyXLCD());
    WriteCmdXLCD(0b00000001);
}
void menu(void)                 //first half of menu for initial setup
{
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("START(A)      >E");
    SetDDRamAddr(0x10);
    putrsXLCD("# OF READINGS(B) ");
    while(BusyXLCD());
}

void checkkey(void){            //function used to check which key is pressed and display the appropriate options to the screen
         if (key[0] == 'A'){
            while(BusyXLCD());
            SetDDRamAddr(0x00);
            start();
            putrsXLCD("INSERT PROCESS 1");
            Delay10KTCYx(200);
            WriteCmdXLCD(0b00000001);
            menu();
        }
        if (key[0]== 'B'){
            while(BusyXLCD());
            SetDDRamAddr(0x00);
            putrsXLCD("5 SECONDS (A)");
            SetDDRamAddr(0x10);
            putrsXLCD("10 SECONDS (B)");
            while(BusyXLCD());
            while(1);
        }
        if (key[0]== 'C'){
            while(BusyXLCD());
            SetDDRamAddr(0x00);
            intervals();
            putrsXLCD("INSERT PROCESS 3");
            Delay10KTCYx(200);
            WriteCmdXLCD(0b00000001);
            menu();
        }
        if (key[0]== 'D'){
            while(BusyXLCD());
            SetDDRamAddr(0x00);
            storage();
            putrsXLCD("INSERT PROCESS 4");
            Delay10KTCYx(200);
            WriteCmdXLCD(0b00000001);
            menu();
        }
        if (key[0]== 'E'){
            while(BusyXLCD());
            SetDDRamAddr(0x00);
            putrsXLCD("# OF READINGS(C)  <F");
            SetDDRamAddr(0x10);
            putrsXLCD("STORAGE(D)       ");
            while(BusyXLCD());
        }
        if (key[0]== 'F'){
            while(BusyXLCD());
            SetDDRamAddr(0x00);
            putrsXLCD("START(A)      >E");
            SetDDRamAddr(0x10);
            putrsXLCD("INTERVALS(B) ");
            while(BusyXLCD());  
        }
                 changekey[0]='0';
}
void main(void)         //main function
{
    interruptinit();        //call interrupt setup function
    keypadsetup();          //call keypad setup function
    LCDinit();              //call lcd setup function
    menuinit();
    menu();
    while(1){
        if (changekey[0]=='1')
        {
            checkkey();
        }
        Delay10KTCYx(50);
    }
    
}