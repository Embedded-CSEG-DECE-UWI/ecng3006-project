#include <p18cxxx.h>

/* Set configuration bits for use with PICKit3 */
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

//The system should allow a user to start storing a pre-de?ned set of measurements to external ?ash RAM, and to interrupt the ongoing storage of a set of measurements.

void main(void)
{
    //Insert Your Peripheral Specific Code here for testing
    //SLEEP();
    Sleep();
}