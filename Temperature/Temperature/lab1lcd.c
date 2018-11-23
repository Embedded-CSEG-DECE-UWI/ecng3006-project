#include <p18f452.h> 
#include <delays.h>
#include "xlcd.h"
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h> 
#include "ow.h"



#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

#define OW_LAT LATBbits.LATB5
#define OW_PIN PORTBbits.RB5
#define OW_TRIS TRISBbits.TRISB5

#define OUTPUT 0
#define INPUT 1

// configures the temperature sensor

void tempSetup(void) {
 
  ow_reset(); 
  ow_write_byte(0x0C); 
  ow_write_byte(0x00);
  ow_reset(); 
  ow_write_byte(0xAC); 
  ow_reset();
}


//measures the temperature value
float measureTemp(void)
{
    int tempVal = 0;
    int tempSum = 0;
    float tempAvg = 0.0;
    int count = 0;
    while( count < 200){
	ow_write_byte(0xEE); 
    	ow_write_byte(0x22);                                                                                                                                                                                                                                                                                                                                                                      
    	ow_reset(); 
    	ow_write_byte(0xAA); 
	tempVal = ow_read_byte();
    	ow_reset();
    	tempSum = tempSum + tempVal;
        count++;
    }
     tempAvg = (float) tempSum / 200;
     return tempAvg;
} 



void low_isr (void);
void keyPad (void);
char keyval;


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
        keyval = 'F';
    }
    
    //KEY "1"
    else if((!PORTCbits.RC4) && (!PORTCbits.RC5) && (!PORTCbits.RC6) && (!PORTCbits.RC7))
    {
        keyval = '1';
    }
    
    //KEY "A"
    else if((!PORTCbits.RC4) && (!PORTCbits.RC5) && (!PORTCbits.RC6) && (PORTCbits.RC7))
    {
        keyval = 'A';
    }
    
    //KEY "2"
    else if((!PORTCbits.RC4) && (!PORTCbits.RC5) && (PORTCbits.RC6) && (PORTCbits.RC7))
    {
        keyval = '2';
    }
    
    //KEY "3"
    else if(!(PORTCbits.RC4) && !(PORTCbits.RC5) && (PORTCbits.RC6) && (!PORTCbits.RC7))
    {
        keyval = '3';
    }
    
    //KEY "4"
    else if(!(PORTCbits.RC4) && (PORTCbits.RC5) && !(PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        keyval = '4';
    }
    
    //KEY "B"
    else if(!(PORTCbits.RC4) && (PORTCbits.RC5) && !(PORTCbits.RC6) && (PORTCbits.RC7))
    {
        keyval = 'B';
    }
    
    //KEY "6"
    else if(!(PORTCbits.RC4) && (PORTCbits.RC5) && (PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        keyval = '6';
    }
    
    //KEY "5"
    else if(!(PORTCbits.RC4) && (PORTCbits.RC5) && (PORTCbits.RC6) && (PORTCbits.RC7))
    {
        keyval = '5';
    }
    
    //KEY "7"
    else if((PORTCbits.RC4) && !(PORTCbits.RC5) && !(PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        keyval = '7';
    }
    
    //KEY "C"
    else if((PORTCbits.RC4) && !(PORTCbits.RC5) && !(PORTCbits.RC6) && (PORTCbits.RC7))
    {
        keyval = 'C';
    }
    
    //KEY "9"
    else if((PORTCbits.RC4) && !(PORTCbits.RC5) && (PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        keyval = '9';
    }
    
    //KEY "8"
    else if((PORTCbits.RC4) && !(PORTCbits.RC5) && (PORTCbits.RC6) && (PORTCbits.RC7))
    {
        keyval = '8';
    }
    
    //KEY "0"
    else if((PORTCbits.RC4) && (PORTCbits.RC5) && !(PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        keyval = '0';
    }
    
    //KEY "D"
    else if((PORTCbits.RC4) && (PORTCbits.RC5) && !(PORTCbits.RC6) && (PORTCbits.RC7))
    {
        keyval = 'D';
    }
    
    //KEY "E"
    else if((PORTCbits.RC4) && (PORTCbits.RC5) && (PORTCbits.RC6) && !(PORTCbits.RC7))
    {
        keyval = 'E';
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
    //dummy();
    //LETTHISWORK();
    //while(BusyXLCD());
    //SetDDRamAddr(0x40);
    //putrsXLCD("Test Two:");
    keyPad();
    INTCON3bits.INT1IF = 0; //clears the external interrupt flag
    INTCONbits.GIEH =1;
    INTCON3bits.INT1IE = 1;
}




float a = 0.0;
int whole,decimal;
char array[20];



void main(void)
{
    
    tempSetup();
    a=measureTemp(); //measureTemp();
    whole=a; //whole part
    decimal=(a-whole)*100; //decimal part
    sprintf(array,"%3d.%04d",whole,decimal); //Convert to string
  
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
    putrsXLCD("GROUP D: DAEMON");
    SetDDRamAddr(0x40);
    putrsXLCD("Temperature:");
    SetDDRamAddr(0x14);
    putsXLCD(array);
    while(BusyXLCD());
    
    while(1);
       
    
}