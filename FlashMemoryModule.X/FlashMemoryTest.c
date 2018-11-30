#include <p18f452.h>
#include <delays.h>
#include <flash.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000      //4Mhz Clock

#define WriteEnable PORTAbits.RA0
#define ChipEnable PORTAbits.RA2
#define OutputEnable PORTAbits.RA1

#define DataPin LATB.RB3
#define OEPin LATB.RB5
#define LatchPin LATB.RB6
#define ClockPin LATB.RB7

void initFlash();
void eraseSec(int);
void wrtFlashMem();

void initFlash()
{
    /*Inputs to the PIC*/
    TRISAbits.RA0 = 1;          //Write enable WE#
    TRISAbits.RA1 = 1;          //Output enable OE#
    TRISAbits.RA2 = 1;          //Chip enable CE#
    
    /*Outputs to shift registers*/
    TRISAbits.RA3 = 0;
    TRISAbits.RA4 = 0;
    TRISBbits.RB0 = 0;
    TRISBbits.RB3 = 0;          //Shift Register SER (DATA) pin
    TRISBbits.RB5 = 0;          //Shift Register OE (Output Enable) pin
    TRISBbits.RB6 = 0;          //Shift Register RCLK (Latch) pin
    TRISBbits.RB7 = 0;          //Shift Register SRCLK (Clock) pin
    
    
    /*Configure Shift registers*/
    PORTBbits.RB5 = 0;          //Set OE low
}

void eraseSec(int address)
{
    /*Execute commands to erase sector*/
    int addr = 0b101010101010101000;
    int i;
    int tempAddr;
    int addrVal[18];
    for(i = 0; i<18; i++)
    {
        tempAddr = addr >> i;
        addrVal[i] = tempAddr & 1;
        DataPin = addrVal[i];
        ClockPin = 1;
    }
    LatchPin = 1;
    
    Delay1KTCYx(20);             //Delay for 20ms
}

void wrtFlashMem()
{
    /*To write to the Flash Memory*/
    WriteEnable = 0;
    ChipEnable = 0;
    OutputEnable = 1;
    
    eraseSec(0b001010101010101010);
    
    /*To select program mode*/
    WriteEnable = 0;
    OutputEnable = 1;
    ChipEnable = 0;
        
    /*Executing three byte load sequence for Software Data Protection*/
    
    /*Load program Byte Address and Byte data*/
}

void main()
{
   
    initFlash();
    wrtFlashMem();
    
    
}