#include    <p18f452.h>
#include    <portb.h>
#include    "Keypad.h"

void ConfigKeypad(void){
    //enable external interrupts on RB0
    OpenRB0INT(PORTB_CHANGE_INT_ON & RISING_EDGE_INT);
    
    //set the up upper nibble of TRISC to inputs
    TRISC = 0xF0;
    
    //Enable global interrupts and prioritize this interrupt
    RCONbits.IPEN       = 1;
    INTCONbits.GIE_GIEH = 1;
}