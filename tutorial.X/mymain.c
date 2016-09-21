#include <p18cxxx.h>

/* Set configuration bits for use with PICKit3 */
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

void main(void)
{
    int a;
    
    a=5;
    //SLEEP();
    Sleep();
}