#include <p18f452.h>
#include "speaker.h"

#pragma config WDT = OFF
#pragma config OSC = HS
#pragma config LVP = OFF
#define _XTAL_FREQ 4000000

void main(void){
    
    
        speaker(3);
        Sleep();
}
