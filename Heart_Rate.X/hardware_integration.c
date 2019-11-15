#include <p18f452.h>
#include "xlcd.h"
#include <delays.h>
#include <timers.h>
#include <stdlib.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000 //4Mhz clock

void main (void)
{
    TRISBbits.RB2 = 1;
}
