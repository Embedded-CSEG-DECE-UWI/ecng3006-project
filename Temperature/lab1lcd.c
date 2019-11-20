#include <p18f452.h> 
#include "delays.h"
#include "xlcd.h"
#include "ow.h"
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h> 


#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

void low_isr(void);
void keypress(void);

#pragma code low_vector=0x18 

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
    WriteCmdXLCD(0b00000001);
    keypress();
    INTCON3bits.INT1IF = 0; //clears the external interrupt flag
}


void keypress(void)
{
  if (!PORTCbits.RC7 && !PORTCbits.RC6 && !PORTCbits.RC5 && !PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("1");
    }
  if (PORTCbits.RC7 && PORTCbits.RC6 && !PORTCbits.RC5 && !PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("2");
    } 
  if (!PORTCbits.RC7 && PORTCbits.RC6 && !PORTCbits.RC5 && !PORTCbits.RC4)
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("3");
    } 
  if (!PORTCbits.RC7 && !PORTCbits.RC6 && PORTCbits.RC5 && !PORTCbits.RC4)
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("4");
    }
  if (PORTCbits.RC7 && PORTCbits.RC6 && PORTCbits.RC5 && !PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("5");
    }
  if (!PORTCbits.RC7 && PORTCbits.RC6 && PORTCbits.RC5 && !PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("6");
    }
  if (!PORTCbits.RC7 && !PORTCbits.RC6 && !PORTCbits.RC5 && PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("7");
    }
  if (PORTCbits.RC7 && PORTCbits.RC6 && !PORTCbits.RC5 && PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("8");
    }
  if (!PORTCbits.RC7 && PORTCbits.RC6 && !PORTCbits.RC5 && PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("9");
    }
  if (!PORTCbits.RC7 && !PORTCbits.RC6 && PORTCbits.RC5 && PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("0");
    }
  if (PORTCbits.RC7 && !PORTCbits.RC6 && !PORTCbits.RC5 && !PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("A");
    }
  if (PORTCbits.RC7 && !PORTCbits.RC6 && PORTCbits.RC5 && !PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("B");
    }
  if (PORTCbits.RC7 && !PORTCbits.RC6 && !PORTCbits.RC5 && PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("C");
    }
  if (PORTCbits.RC7 && !PORTCbits.RC6 && PORTCbits.RC5 && PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("D");
    }
  if (!PORTCbits.RC7 && PORTCbits.RC6 && PORTCbits.RC5 && PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("E");
    }
  if (PORTCbits.RC7 && PORTCbits.RC6 && PORTCbits.RC5 && PORTCbits.RC4 )
    {
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    putrsXLCD("F");
    }
}
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
void LCDSetup (void)
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
void InteruptSetup(void){

    INTCON3bits.INT1IE = 1; //enable the INT1 external interrupt 
    INTCON3bits.INT1IF = 0;//clear external interrupt INT1 flag
    INTCON2bits.INTEDG1= 1; //set interrupt INT1 on rising edge
    RCONbits.IPEN = 1;      // Enable Interrupt Priority 
    INTCONbits.PEIE =1;     //Enable Peripheral Interrupt Enable bit
    INTCONbits.GIEH = 1;    //Enable all high priority interrupts/ global interrupt bit
    INTCON3bits.INT1IP = 0; //Set INT1 Priority bit to high priority
}

//setup of the keypad module
void KeypadSetup(void)
{
    TRISCbits.RC7 = 1; //A
    TRISCbits.RC6 = 1; //B
    TRISCbits.RC5 = 1; //C
    TRISCbits.RC4 = 1; //D
}

//setup of the temperature module
void TemperatureSetup(void) {
 
  ow_reset(); 
  ow_write(0x0C); 
  ow_write(0x00);
  ow_reset(); 
  ow_write(0xAC); 
  ow_reset();
}

//Function used to measure the temperature 
float TemperatureMeasurement(void)
{
    int raw_reading = 0;                                //initialize variable for input data
    int total_temperature = 0;                      //initialize variable for total temperature 
    float average_temperature = 0.0;            //initialize variable for average temperature
    int count = 0;                                          //initialize variable for count
    while( count < 200){                                //while loop to sample data multiple times
	ow_write(0xEE); 
    	ow_write(0x22);                                                                                                                                                                                                                                                                                                                                                                      
    	ow_reset(); 
    	ow_write(0xAA); 
	raw_reading = ow_read();                //gets the reading and stores it in a variable
    	ow_reset();
    	total_temperature = total_temperature + raw_reading;            //adds all the temperature readings
        count++;                                            //increment count
    }
     average_temperature = (float) total_temperature / 200;             //finds the average of all the values taken
     return average_temperature;                                                       //return the value 
}

float whole_reading = 0.0;                      //initialize variable for the average temperature reading
int extract_integer;                                //initialize variable for the whole number part of the average temperature 
int extract_decimal;                                //initialize variable for the decimal part of the average temperature
char array[20];                                        //initialize variable to store the value as a string array

void main(void){
    
    TemperatureSetup();
    InteruptSetup();
    KeypadSetup();
    LCDSetup();
    
    while (1){
    whole_reading =TemperatureMeasurement();                                    //call the function to measure the temperature
    extract_integer = whole_reading;                                                    //extract the whole part of the average temperature
    extract_decimal = (whole_reading-extract_integer)*100;                 //extract the decimal part of the average temperature
    sprintf(array,"%3d.%04d",extract_integer,extract_decimal);          //convert the values to a string array
    SetDDRamAddr(0x00); 
    putrsXLCD("temperature ");
    putsXLCD(array);
    }
    while(BusyXLCD());
}