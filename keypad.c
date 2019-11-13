#include    "Modules.h"
#include    <p18f452.h>

void configKeypad(void) {
    //Set the upper nibble of TRISC to inputs
    TRISC = 0xF0;

    //Set up RB0 as an external interrupt
    INTCONbits.INT0F = 0; //Clear the interrupt flag
    INTCON2bits.INTEDG0 = 1; //Rising edge
    INTCONbits.INT0IE = 1; //Enable the RBO interrupt
    INTCONbits.GIE = 1; //Enable Global interrupt
    return;
}