#include    "Modules.h"
#include    <p18f452.h>

void configKeypad(void) {
    //Set the upper nibble of TRISC to inputs
    TRISC = 0xF0;

    //Set up RB2 as an external interrupt LOW INTERRUPT NEEDS TO BE CHANGED
    
    INTCONbits.GIE = 0;
    INTCON3bits.INT2IF = 0; //Clear the interrupt flag
    INTCON2bits.INTEDG2 = 1; //RB2 Interrupt triggered at Rising edge
    INTCON3bits.INT2IE = 1; //Enable the RB2 interrupt
    //INTCON3bits.INT2IP = 0; //Sets RB2 interrupt as low priority
    INTCONbits.GIE = 1; //Enable Global interrupt
    return;
}