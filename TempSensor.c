#include    "FreeRTOS.h"
#include    "Modules.h"
#include    "xlcd_GpE.h"
#include    <p18f452.h>
#include    <delays.h>
#include    <stdio.h>
#include    <stdlib.h>

unsigned char tempLSB;
unsigned char tempMSB;
unsigned int tempVarMSB = 0;
unsigned int tempVarLSB = 0;
unsigned int intTemp = 0;
unsigned char charTemp;
unsigned char fractChar;
unsigned int fractInt = 0;
unsigned char dispVal[16];
unsigned char degChar = 0xDF;
float fractFloat = 0.0000;
int x;
int valueInt = 0;
int sign = 0;
struct lcdMessage tempLCDMessage;

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

void tempTask(void *pvParameter) {
    TRISBbits.RB3 = 0;
    while (1) {
        taskENTER_CRITICAL();                       //Tick of the kernel corrupts the data
                                                    //Configuration Sequence
        initSequence();                             //Initialization Step
        writeByte(0xCC);                            //Command: Skip the ROM Check; since we're using 1 sensor
        writeByte(0x44);                            //Command: Start a temp conversion
        PORTBbits.RB3 = 1;                          //Strong pull up to provide current that internal capacitor can't provide
#if(USEC18DELAY == 1)
        Delay10KTCYx(80);                           //800ms (750ms is recommended conversion time))
#else
        vTaskDelay(80);
#endif
        PORTBbits.RB3 = 0; //Turn off strong pull-up

                                                    //Data Collection Sequence
        initSequence();
        writeByte(0xCC);                            //Command: Skip ROM Check
        writeByte(0xBE);                            //Command: Read Scratch-pad
        tempLSB = readByte();                       //Read in the temp data
        tempMSB = readByte();
                                                    //The integer value is the 4 lsb of the high reg
                                                    //and the 4 msb of the low reg
        tempVarLSB = tempLSB >> 4;
        tempVarMSB = tempMSB << 4;
        intTemp = tempVarMSB | tempVarLSB;
        intTemp = intTemp + 1;
        
                                                    //The 4 lsb of the low reg contain the fraction
                                                    //temperature reading
        if (tempLSB & 0x01) {fractFloat += 0.0625;}
        if (tempLSB & 0x02) {fractFloat += 0.125;}
        if (tempLSB & 0x04) {fractFloat += 0.25;}
        if (tempLSB & 0x08) {fractFloat += 0.5;}
        fractInt = ((fractFloat) * 1000);

        sign = ((tempMSB >> 3)& 0x3F);
        if (sign == 0) {
            sprintf(dispVal,"+%d.%03d%cC",intTemp,fractInt,degChar);
            intTemp = 0;
            fractFloat = 0.0000;
            fractInt = 0;
        } else {
            sprintf(dispVal,"-%d.%03d%cC",intTemp,fractInt,degChar);
            intTemp = 0;
            fractFloat = 0.0000;
            fractInt = 0;
        }
        
        taskEXIT_CRITICAL();                        //Exit the critical Section
#if(USEFREERTOSQUEUE == 1)
        tempLCDMessage.srcID = 'T';
        strcpy(tempLCDMessage.srcMessage, dispVal);
        xQueueSend(xlcdQueue, (void *) &tempLCDMessage, 10);
#else
        while (BusyXLCD());
        SetDDRamAddr(0x50);
        while (BusyXLCD());
        putsXLCD(dispVal);
        while (BusyXLCD());
#endif
    }
}
