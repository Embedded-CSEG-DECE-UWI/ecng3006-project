// Adapted keypad code from Amar Pustam 2018 
#include <p18f452.h> 
#include "delays.h"
#include "xlcd.h"
#include "Prototypes.h"
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <timers.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

//Function Prototypes
void high_isr (void);
void low_isr(void); 
void keypress(void);
void LcdSetup(void);
void heartRateCal();
int press();
void pulseCounting();
void TemperatureSetup(void);
void timer0Setup();
void irPulseSetup();
void MenuMain(void);
void ReadTemperature();
void HRV();
void Glucose();
void speaker(void);


int keyvalue = 13;
char keyvaluechar[3];
int startTimer = 1;





/*------------------------HIGH INTERRUPT SERVICE ROUTINE----------------------*/
#pragma code high_vector = 0x08
void interrupt_at_high_vector(void)
{
    _asm GOTO high_isr _endasm
}
#pragma code

#pragma interrupt high_isr
void high_isr (void)
{    
    if(INTCONbits.TMR0IF == 1 && keyvalue == 10){
        heartRateCal();
        INTCONbits.TMR0IF = 0;
    }
}

/*------------------------LOW INTERRUPT SERVICE ROUTINE----------------------*/
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
    if(INTCON3bits.INT1IF){
    WriteCmdXLCD(0b00000001);                         
    keyvalue = press();                             //Calls the key press function inside the ISR
    itoa(keyvalue, keyvaluechar);
    }
    INTCON3bits.INT1IF = 0;                 //clears the external interrupt flag
    
    if(INTCON3bits.INT2IF){
        pulseCounting();
    }
     INTCON3bits.INT2IF = 0;
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
    timer0Setup();
    irPulseSetup();
    
    while(keyvalue == 13){
        MenuMain();
        if(startTimer ==0){
            startTimer = 1;
            CloseTimer0();
        }
        //CloseTimer0();
    }
    while(keyvalue == 10){                  //Start live readings
        ReadTemperature();
        //TimerStart();
        if(startTimer == 1){
        WriteTimer0(0xF0BD);
        startTimer = 0;
        }
        HRV();
        Glucose();
        //startTimer = 0;
    }
}