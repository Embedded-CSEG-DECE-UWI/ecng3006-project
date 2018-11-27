//#include <p18cxxx.h>
#include <p18f452.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "xlcd3.h"
#include <delays.h>
#include "meman_v0_4.h"
#include "SST39S_v1.h"

/*
 * 
 */


#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000

void DelayFor18TCY (void)
{
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
}

void DelayPORXLCD (void)
{
    Delay1KTCYx(15);
    return;
}

void DelayXLCD (void)
{
    Delay1KTCYx(5);
    return;
}

void init_XLCD (void)
{
    OpenXLCD (FOUR_BIT & LINES_5X7);
    while( BusyXLCD() );
    WriteCmdXLCD( FOUR_BIT & LINES_5X7 );
    while( BusyXLCD() );
    WriteCmdXLCD( BLINK_ON );
    while( BusyXLCD() );
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    
}




//
//#define HR_TRACK_STATUS 0x02
//#define HR_MAX_STORE 0x04
//#define HR_RCCNT 0x06
//
//#define HRV_TRACK_STATUS 0x08
//#define HRV_MAX_STORE 0x0A
//#define HRV_RCCNT 0x0C
//
//#define TEMP_TRACK_STATUS 0x0E
//#define TEMP_MAX_STORE 0x10
//#define TEMP_RCCNT 0x12
//
//#define GLUC_TRACK_STATUS 0x14
//#define GLUC_MAX_STORE 0x16
//#define GLUC_RCCNT 0x18
//
//#define TRACKING 0x0F
//#define NOT_TRACKING 0xF0

//float tempDisp[4] = {4.6, 5.5, 6.4, 5.5};
//float glucDisp[4] = {0.0, 0.0, 0.0, 0.0};
//float hrvDisp[4] = {0.0, 0.0, 0.0, 0.0};
//unsigned int hrDisp[4] = {28, 51, 55, 88};

/*// void HRrefreshLCD()
// {
//     while (BusyXLCD());
//     WriteCmdXLCD(0b00000001);
//     for(paintbrush = 0; paintbrush < 4; paintbrush++)
//     {
//         while(BusyXLCD());
//         if(paintbrush == 0)
//         { SetDDRamAddr(0x00);}
//         if(paintbrush == 1)
//         { SetDDRamAddr(0x40);}
//         if(paintbrush == 2)
//         { SetDDRamAddr(0x10);}
//         if(paintbrush == 3)
//         { SetDDRamAddr(0x50);}
//         itoa(hrDisp[paintbrush], numtodisp);
        
//         putsXLCD(numtodisp);
//     }
// }

// void HRVrefreshLCD(void)
// {
//     for (i=0; i < 4; i++)
//     {
//         while (BusyXLCD());
//         WriteCmdXLCD(0b00000001);
//         integers = hrvDisp[i];
//         //decimals = ((values[i] * 100)%100);
//         decimals = fmod((hrvDisp[i] * 10),10);
//         //itoa(values[i], output);
//         itoa(integers, integerchar);
//         itoa(decimals, decimalchar);       
//         while( BusyXLCD() );
//         if (i == 0) SetDDRamAddr(0x03);
//         if (i == 1) SetDDRamAddr(0x43);
//         if (i == 2) SetDDRamAddr(0x13);
//         if (i == 3) SetDDRamAddr(0x53);
//         putsXLCD(integerchar);
//         putrsXLCD(".");
//         putsXLCD(decimalchar);
//     }
// }*/

/*void HRtest2(void)
{
    openRecordsINT(HR_STORAGE_SECTOR, hrDisp, &HRreadAdd, &HRreccnt, &HRscrollCnt, &HRScrollSTATE);
    HRrefreshLCD();
    for(v = 0; v < 11; v++)
    {
        Delay10KTCYx(50);
        scrollRecordsHR(HR_STORAGE_SECTOR, SCROLL_DOWN,&HRScrollSTATE, INTSIZE);
        HRrefreshLCD();
    }
        for(v = 0; v < 11; v++)
    {
        Delay10KTCYx(50);
        scrollRecordsHR(HR_STORAGE_SECTOR, SCROLL_UP,&HRScrollSTATE, INTSIZE);
        HRrefreshLCD();
    }
        for(v = 0; v < 11; v++)
    {
        Delay10KTCYx(50);
        scrollRecordsHR(HR_STORAGE_SECTOR, SCROLL_DOWN,&HRScrollSTATE, INTSIZE);
        HRrefreshLCD();
    }
}
void HRVtest2(void)
{
        openRecordsFLOAT(HRV_STORAGE_SECTOR, hrvDisp, &HRVreadAdd, &HRVreccnt, &HRVscrollCnt, &HRVScrollSTATE);
        for(v = 0; v < 11; v++)
    {
        Delay10KTCYx(200);
        scrollRecordsHRV(HRV_STORAGE_SECTOR, SCROLL_DOWN,&HRVScrollSTATE, FLOATSIZE);
        HRVrefreshLCD();
    }
        for(v = 0; v < 11; v++)
    {
        Delay10KTCYx(200);
        scrollRecordsHRV(HRV_STORAGE_SECTOR, SCROLL_UP,&HRVScrollSTATE, FLOATSIZE);
        HRVrefreshLCD();
    }
        for(v = 0; v < 11; v++)
    {
        Delay10KTCYx(200);
        scrollRecordsHRV(HRV_STORAGE_SECTOR, SCROLL_DOWN,&HRVScrollSTATE, FLOATSIZE);
        HRVrefreshLCD();
    }
}*/



float TestFloats[10] = {0x01100110,0x02200220,0x03300330,0x04400440,0x05500550,0x06600660,0x07700770,0x08800880,0x09900990,0x0AA00AA0};
unsigned int TestInts[10] = {0x0110,0x2002,0x0330,0x0440,0x5005,0x0660,0x7007,0x8008,0x0990,0xA00A};
unsigned int a;
int b;
int c;
int d;

union uFLOAT load;
union uINT look;
union uINT showme; 

unsigned int tints[10] = {5,7,9,11,13,15,17,19,21,23};
float toats[10] = {78.5,0.2,19.6,22.8,112.9,0.7,1.2,79.6,49.8,813.4};
float taots2[10] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.1};
float toats2[10] = {101.1,202.2,303.3,404.4,505.5,606.6,707.7,808.8,909.9,10010.1};
union uINT HRrx;
char ID;
char numtodisp[20];
char integerchar[20];
char decimalchar[20];
int v;
int i;
int integers;
int decimals;
int paintbrush;
char bpm[] = "bpm ";
char slash[] = "/";


void scrollLite(void)
{
    openRecordsLite();
    for(v = 0; v < 11; v++)
    {
        Delay10KTCYx(50);
        pageScrollLite(SCROLL_DOWN);
        HRrefreshLCD();
    }
    for(v = 0; v < 11; v++)
    {
        Delay10KTCYx(50);
        pageScrollLite(SCROLL_UP);
        HRrefreshLCD();
    }
    for(v = 0; v < 11; v++)
    {
        Delay10KTCYx(50);
        pageScrollLite(SCROLL_DOWN);
        HRrefreshLCD();
    }

}

void main (void)
{
    init_XLCD();
    //while( BusyXLCD() );
    //SetDDRamAddr(0x00);
    //putrsXLCD("Testing Flash");
    //TRISB = 0x00;
    Delay10KTCYx(100);
    ram_init();
    eeprom_init();
    
    writeEEPROM(HR_TRACK_STATUS,TRACKING);
    writeEEPROM(HR_MAX_STORE, 0x0B);
    writeEEPROM(HR_RCCNT,0x00);  
    
    writeEEPROM(HRV_TRACK_STATUS,TRACKING);
    writeEEPROM(HRV_MAX_STORE, 0x0B);
    writeEEPROM(HRV_RCCNT,0x00); 
    
    writeEEPROM(TTEMP_TRACK_STATUS,TRACKING);
    writeEEPROM(TTEMP_MAX_STORE, 0x0B);
    writeEEPROM(TTEMP_RCCNT,0x00); 
    
    writeEEPROM(TEMP_TRACK_STATUS,TRACKING);
    writeEEPROM(TEMP_MAX_STORE, 0x0B);
    writeEEPROM(TEMP_RCCNT,0x00); 
    //sectorErase(HR_STORAGE_SECTOR);
    //sectorErase(HRV_STORAGE_SECTOR);
    chipErase();
    
    //meman_init();
    RecordTrackInit(HR_TRACK_STATUS,HR_MAX_STORE,HR_RCCNT,INTSIZE,&HRreccnt,&HRMaxRecords,&HRwriteAdd, &HRreadAddX);
    RecordTrackInit(HRV_TRACK_STATUS,HRV_MAX_STORE,HRV_RCCNT,FLOATSIZE,&HRVreccnt,&HRVMaxRecords,&HRVwriteAdd, &HRVreadAddX);
    RecordTrackInit(TEMP_TRACK_STATUS,TEMP_MAX_STORE,TEMP_RCCNT,FLOATSIZE,&TEMPreccnt,&TEMPMaxRecords,&TEMPwriteAdd, &TEMPreadAddX);
    RecordTrackInit(GLUC_TRACK_STATUS,GLUC_MAX_STORE,GLUC_RCCNT,FLOATSIZE,&GLUCreccnt,&GLUCMaxRecords,&GLUCwriteAdd, &GLUCreadAddX);

    for (v = 0; v < 10; v++)
    {
        HR.intVAL = tints[v];
        MakeRecordHR(HR_STORAGE_SECTOR,HR_RCCNT,HR);
    }
    for (v = 0; v < 10; v++)
    {
        HRV.floatVAL = toats[v];
        MakeRecordHRV(HRV_STORAGE_SECTOR,HRV_RCCNT,HRV);
    }
    for (v = 0; v < 10; v++)
    {
        TEMP.floatVAL = toats2[v];
        MakeRecordHRV(TEMP_STORAGE_SECTOR,TEMP_RCCNT,TEMP);
    }
    for (v = 0; v < 10; v++)
    {
        GLUC.floatVAL = toats3[v];
        MakeRecordHRV(GLUC_STORAGE_SECTOR,GLUC_RCCNT,GLUC);
    }
    
//    numtodisp[0] = 'r';
//    numtodisp[1] = '\0';
//    ID = softwareID();
//    numtodisp[0] = ID;
//    SetDDRamAddr(0x00);
//    putsXLCD(numtodisp);
    

    
//    Delay10KTCYx(200);
//    scrollRecordsHR(HR_STORAGE_SECTOR, SCROLL_DOWN,&HRScrollSTATE, INTSIZE);
//    HRrefreshLCD();
//    Delay10KTCYx(200);
//    
//    readDATA(HR_STORAGE_SECTOR, 0x08);
//    HRrx.intCHAR[0] = RXbits.CHARBITS;
//    readDATA(HR_STORAGE_SECTOR, 0x09);
//    HRrx.intCHAR[1] = RXbits.CHARBITS;
//    itoa(HRrx.intVAL, numtodisp);
//    while(BusyXLCD());
//    WriteCmdXLCD(0b00000001);
//    SetDDRamAddr(0x00);
//    putsXLCD(numtodisp);
    
    //HRVtest2();
    //HRtest2();
    scrollLite();

    //writeDATA(0x03,0x555,0xde);
    
//    while(1){
    //ID = softwareID();
    
    //putsXLCD(ID);
    
    //pushAddressCMD(0x5,0x5555);
    //Delay10KTCYx(100);
    //pushAddressCMD(0x5,0xFF00);
    Delay10KTCYx(100);
    while(1);
 //   }

    
}