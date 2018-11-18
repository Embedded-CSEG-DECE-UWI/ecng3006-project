#include <p18cxxx.h>

/* Set configuration bits for use with PICKit3 */
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

//1.The system has to estimate EITHER heart rate variability using pNN50 (as a %) OR a person’s oxygen saturation level (as a %)
//2. All sensors/system measurements should be calibrated and/or the error quanti?ed.

void main(void)
{
    //Insert Your Peripheral Specific Code here for testing
    //SLEEP();
    Sleep();
}