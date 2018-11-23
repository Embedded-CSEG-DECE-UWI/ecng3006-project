#include <p18cxxx.h>
#include <reset.h> 
#include <delays.h>

#pragma config OSC = XT
#pragma config WDT = ON
#pragma config LVP = OFF
#pragma config WDTPS = 64


//#define WDT_ENABLED
int count;
void Dummy_Stuck(void)
{
    while(1)
    {
        PORTBbits.RB3 = 1;
        Delay10KTCYx(5);      
        PORTBbits.RB3 = 0;
        Delay10KTCYx(5);
    }                   /* wait till watchdog timeout and then reset system */
}

void main(void) {
    
    //Delay10KTCYx(10);
    count = 0;
    TRISB = 0x00;
    
    if(!RCONbits.TO)
    {
        
        Delay10KTCYx(10);
        PORTBbits.RB0 = 1;
        Delay10KTCYx(10);
        PORTBbits.RB0 = 0;
        Delay10KTCYx(10);
        /* Clear Watchdog Timer */
        
        
    }
    
    //ClrWdt();
    while(1)
    {
        PORTBbits.RB4 = 1;
        Delay10KTCYx(5);      
        PORTBbits.RB4 = 0;
        Delay10KTCYx(5);
        ClrWdt();
        count++;
        if(count>10)
        {
            Dummy_Stuck();
        }/* Dummy Stuck loop function */
    }
    
    
    
    
    Sleep();
}
