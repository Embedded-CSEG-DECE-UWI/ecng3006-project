/*
 * Name     -   Application
 * Input    -   
 * Process  -   
 * Output   -   
 * Version 0.0.5
 */

#include    <p18f452.h>
#include    <portb.h>
#include    "Keypad.h"
#include    "Modules.h"
#include    "xlcd.h"

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

//Global Variable
int key;

//Setting up the interrupts
void KeyPressInterrupt(void);

#pragma code HIGH_INTERRUPT_VECTOR = 0x08
void high_ISR (void){
    _asm
    goto KeyPressInterrupt 
    _endasm
}
#pragma code

#pragma interrupt KeyPressInterrupt
void KeyPressInterrupt(void);

void KeyPressInterrupt(void){
    if(INTCONbits.INT0IF == 1){
        //Disable Global Interrupts
        INTCONbits.GIE = 0;
        
        //Convert the number on PORTC to a decimal number
        key = (PCB4*1 + PCB5*2 + PCB6*4 + PCB7*8);
        switch(key){
            case (0):
                //Call the function that switches the RAM left
                RamLeftStub();
                break;
            case (1):
                //Call the function that switches the RAM right
                RamRightStub();
                break;
            case (2):
                //Call the function that sets the RAM storage rate low
                RamRateLowStub();
                break;
            case (3):
                //Call the function that sets the RAM storage rate High
                RamRateHighStub();
                break;
            case (4):
                //Call the function that activates the temperature module
                TemperatureStub();
                break;
            case (5):
                //Call the function that activates the heart-rate module
                HeartRateStub();
                break;
            case (6):
                //Call the function that activates the glucose module
                GlucoseStub();
                break;
            case (7):
                //Call the function that activates the SPO2 module
                SPO2Stub();
                break;
            case (8):
                //Call the function that tests the Speaker
                SpeakerTestStub();
                break;
            case (9):
                //Call the function that refreshes the LCD
                LCDRefreshStub();
                break;
            case (10):
                //Call the function that Blinks an LED
                RamLeftStub();
                break;
            default:
                //The Default behaviour is to blink an LED and Pulse the Speaker
                DefaultStub();
                break;
        }
        
        //Re-enable interrupts and Clear the external interrupt flag.
        INTCONbits.GIE      = 1;
        INTCONbits.INT0IF   = 0;
        return;
    }
}

void main(void){
    ConfigKeypad();
    while(1);
}