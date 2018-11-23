#include <p18cxxx.h>
//#include <stdio.h>
//#include <stdlib.h>
#include "meman_v0_3.h"
#include "SST39S_v1.h"
#include "xlcd2.h"
/*
 * 
 */

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000



float TestFloats[10] = {0x01100110,0x02200220,0x03300330,0x04400440,0x05500550,0x06600660,0x07700770,0x08800880,0x09900990,0x0AA00AA0};
unsigned int TestInts[10] = {0x0110,0x2002,0x0330,0x0440,0x5005,0x0660,0x7007,0x8008,0x0990,0xA00A};
unsigned int a;
int b;
int c;
int d;

union uFLOAT load;
union uINT look;
union uINT showme; 



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

unsigned char h;
void main (void)
{
    TRISB = 0x00;

    ram_init();
 //   init_XLCD();
 //   chipErase();
//
 //       eeprom_init();
//    writeEEPROM(HR_TRACK_STATUS,TRACKING);
//    writeEEPROM(HR_MAX_STORE, 0x0A);
//    writeEEPROM(HR_RCCNT,0x08);  
//    writeEEPROM(HRV_TRACK_STATUS,TRACKING);
//    writeEEPROM(HRV_MAX_STORE, 0x0A);
//    writeEEPROM(HRV_RCCNT,0x08);   
//    h =readEEPROM(0x05);
//    //meman_init();
//    RecordTrackInit(HR_TRACK_STATUS,HR_MAX_STORE,HR_RCCNT,INTSIZE,&HRreccnt,&HRMaxRecords,&HRwriteAdd, &HRreadAddX);
//    openRecordsINT(HR_STORAGE_SECTOR, hrDisp, &HRreadAdd, &HRreccnt, &HRscrollCnt);
//    scrollRecordsHR(HR_STORAGE_SECTOR, SCROLL_DOWN, INTSIZE);
//    
//    RecordTrackInit(HRV_TRACK_STATUS,HRV_MAX_STORE,HRV_RCCNT,FLOATSIZE,&HRVreccnt,&HRVMaxRecords,&HRVwriteAdd, &HRVreadAddX);
//    openRecordsFLOAT(HRV_STORAGE_SECTOR, hrvDisp, &HRVreadAdd, &HRVreccnt, &HRVscrollCnt);
//    scrollRecordsHRV(HRV_STORAGE_SECTOR, SCROLL_DOWN, FLOATSIZE);
//    MakeRecordHRV(HRV_STORAGE_SECTOR,HRV_RCCNT,HRV);
//    MakeRecordHR(HR_STORAGE_SECTOR,HR_RCCNT,HR);
    ///   h = softwareID();
        //Delay10KTCYx(500);
//        softwareIDExit();
//        while(BusyXLCD());                                                      // Wait if LCD busy
//        SetDDRamAddr(0x00);                                                     // Set Display data ram address to 0
//        while(BusyXLCD());
//        WriteCmdXLCD(0x01);
//        while(BusyXLCD());
//        SetDDRamAddr(0x42);                                                     
//        while(BusyXLCD());
  //      pushAddressCMD(0b00000101,0b1010101010101010);
       // putsXLCD(h);
    PORTB = softwareID();
    
    //while(1){
        pushAddressCMD(0b00000101,0b1010101010101010);
   // }
    while(1);
}