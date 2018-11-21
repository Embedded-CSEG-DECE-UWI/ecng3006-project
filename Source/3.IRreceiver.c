#include <p18cxxx.h>

/* Set configuration bits for use with PICKit3 */
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

//The system has to measure a persons heart/pulse rate (in beats per minute), and estimate a person’s glucose level (in mg/dL).

void main(void)
{
    //Insert Your Peripheral Specific Code here for testing
    //SLEEP();
    Sleep();
}