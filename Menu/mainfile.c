// Adapted keypad code from Amar Pustam 2018 
#include <p18f452.h> 
#include "delays.h"
#include "xlcd.h"
//#include "ow.h"
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
int keyvalue = 13;
char keyvaluechar[3];

//Function Prototypes
void LcdSetup(void);

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
    keyvalue = press();                             //Calls the key press function inside the ISR
    itoa(keyvalue, keyvaluechar);
    INTCON3bits.INT1IF = 0;                 //clears the external interrupt flag
}


void InterruptSetup(void){

    INTCON3bits.INT1IE = 1;                 //enable the INT1 external interrupt 
    INTCON3bits.INT1IF = 0;                 //clear external interrupt INT1 flag
    INTCON2bits.INTEDG1= 1;                //set interrupt INT1 on rising edge
    RCONbits.IPEN = 1;                              // Enable Interrupt Priority 
    INTCONbits.PEIE =1;                         //Enable Peripheral Interrupt Enable bit
    INTCONbits.GIEH = 1;                        //Enable all high priority interrupts/ global interrupt bit
    INTCON3bits.INT1IP = 0;                 //Set INT1 Priority bit to high priority
}

void main(void){
    //Call setups for all modules
    InterruptSetup();
    KeypadSetup();
    LcdSetup();
    TemperatureSetup(); 
    
    while(keyvalue == 13){
        MenuMain();
    }
    while(keyvalue == 10){
        //Call heart rate function
        //Call HRV function
        //Call Glucose function
        ReadTemperature();
    }
}