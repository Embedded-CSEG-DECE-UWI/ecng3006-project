#include <p18cxxx.h>

/* Set configuration bits for use with PICKit3 */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

//Flash + LCD :  the system should allow the user to scroll through ALL measurements stored on external ?ash RAM.

void main(void)
{
    //Insert Your Peripheral Specific Code here for testing
    //SLEEP();
    Sleep();
}