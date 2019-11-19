#include    "Modules.h"
#include    "xlcd_GpE.h"
#include    <p18f452.h>
#include    <delays.h>
#include    <stdio.h>
#include    <stdlib.h>

unsigned char initSequence(void) {
    short dsFound = 0;
    OW_TRIS = INPUT;                                //Line High
    OW_LAT = 0;                                     //Line Low
    OW_TRIS = OUTPUT;
    Delay10TCYx(48);                                //Hold line low for 480us
    OW_TRIS = INPUT;                                //Line High
    Delay10TCYx(24);                                //Wait for presense pulse from ds1822
    dsFound = !OW_PIN;
    return dsFound;
}

void writeByte(unsigned char data) {
    char i;
    for (i = 0; i < 8; i++) {
        OW_LAT = 0;                                 //Line Low
        OW_TRIS = OUTPUT;
        Delay10TCYx(1);                             //Start a write slot
        OW_TRIS = data & 0x01;                      //if a WRITE0 keep low, if a WRITE1 make input
        Delay10TCYx(5);
        OW_TRIS = INPUT;                            //Line High
        Nop();                                      //Wait 2us between writes
        Nop();
        data = data >> 1;                           //right shift the data and continue
    }
}

char readByte(void) {
    char data = 0;
    char i;
    for (i = 0; i < 8; i++) {
        OW_LAT = 0;
        OW_TRIS = OUTPUT;                           //Line low to start Read Slot
        Nop();                                      //Keep low for at least 2us
        Nop();
        OW_TRIS = INPUT;                            //Line high
        Nop();                                      //wait for response
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        data = (OW_PIN << i) | data;                //Read the bit and keep shifting it left
        Delay10TCYx(5);                             //Complete the READ cycle
    }
    return data;
}
