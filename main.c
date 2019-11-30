#include    <p18f452.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    "Modules.h"
#include    "xlcd_GpE.h"
#include    <delays.h>


#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define XTAL_FREQ 4000000

//Global Variables
int key;                //KeyPad GV

// Brown Out configuration
#pragma config BOR = ON         // Brown-out Reset Enable bit (Brown-out Reset enabled)
#pragma config BORV = 42        // Brown-out Reset Voltage bits (VBOR set to 4.2V)

/************************GLOBAL VARIABLES FOR TEMPRATURE SENSOR***********************/
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

//Setting up interrupts High Interrupt
#pragma code high_vector = 0x08
void high_interrupt(void) 
{
    if (INTCON3bits.INT1F == 1)
    {
        _asm
                goto LVDisr
        _endasm
    }
    
    if (INTCONbits.TMR0IF == 1)
    {
    _asm
            goto timer10sIsr
    _endasm
    }
    if (INTCONbits.INT0IF == 1)
    {
        _asm
            goto bpmCountIsr
        _endasm
    }
    
    if (INTCON3bits.INT2IF == 1)
    {
    _asm
            goto KeyPressInterrupt
    _endasm
    }
}

#pragma code

#pragma interrupt KeyPressInterrupt
void KeyPressInterrupt(void) 
{
        key = (BIT0 * 1 + BIT1 * 2 + BIT2 * 4 + BIT3 * 8);
        switch (key) {
            case (0):                       //Key Press 1 to start taking BPM reading
                //heartRateModule();
                bpmAlert();
                break;
            case (1):
                //TestBeep();
                hrVarAlt();
                break;
            case (2):
                glucoseAlt();
                break;
            case (3):
                heartRateModule();
                break;
            case (4):

                break;
            case (5):

                break;
            case (6):

                break;
            case (7):

                break;
            case (8):

                break;
            case (9):

                break;
            case (10):

                break;
            case (11):

                break;
            case (12):

                break;
            case (13):

                break;
            case (14):

                break;
            case (15):

                break;
            default:
                while (BusyXLCD());
                SetDDRamAddr(0x00);
                while (BusyXLCD());
                putrsXLCD("An Error!");
                while (BusyXLCD());
                break;
        }

       
        INTCONbits.INT0IF = 0;   //Clear the external interrupt flag.
        return;
}

void main(void) {
    //---------------------CONFIGURATIONS----------------------------
    InitLCD();
    //TRISBbits.RB4 = 0;
    //PORTBbits.RB4 = 0;
    initSpeakerModule();
    configBOR();
    configKeypad();         //This Function also enables all interrupts
    TRISBbits.RB3 = 0;      //Temprature congiuration
    
    //---------------------------------------------------------------


    while (1)
    {
        initSequence();                             //Initialization Step
        writeByte(0xCC);                            //Command: Skip the ROM Check; since we're using 1 sensor
        writeByte(0x44);                            //Command: Start a temp conversion
        PORTBbits.RB3 = 1;                          //Strong pull up to provide current that internal capacitor can't provide
		
        Delay10KTCYx(80);                           //800ms (750ms is recommended conversion time))


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
        
                                                    //The 4 lsb of the low reg contain the fraction
                                                    //temperature reading
        if (tempLSB & 0x01) {fractFloat += 0.0625;}
        if (tempLSB & 0x02) {fractFloat += 0.125;}
        if (tempLSB & 0x04) {fractFloat += 0.25;}
        if (tempLSB & 0x08) {fractFloat += 0.5;}
        fractInt = fractFloat * 1000;

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
        


        while (BusyXLCD());
        SetDDRamAddr(0x15);
        while (BusyXLCD());
        putsXLCD(dispVal);
        while (BusyXLCD());

    }


}


//TEMPRATURE FUNCTIONS

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