#include    <p18f452.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    "Modules.h"
#include    "xlcd_GpE.h"
#include    <delays.h>

//extern volatile int bpm;
//extern volatile int hrVar;
//short int bpmBOR = 0;
//short int hrVarBOR = 0;


void configBOR (void)
{
    INTCONbits.GIE = 0;
    INTCON2bits.INTEDG1 = 1;
    INTCON3bits.INT1E = 1;
    INTCONbits.GIE = 1;
}


#pragma interrupt LVDisr 
void LVDisr (void)
{
    /*PIR2bits.LVDIF = 0;
    
    //Saving By writing to EEPROM
    bpmBOR = bpm;
    hrVarBOR = hrVar;
    
    EEADR = 0x00;
    EEDATA = bpmBOR;
    
    STATUSbits.RP0 = 0;
            
    
    _asm
           BSF STATUS, RP0 
           BCF INTCON, GIE 
           BSF EECON1, WREN 
           MOVLW 0x55 
           MOVWF EECON2 
           MOVLW AAh 
           MOVWF EECON2 
           BSF EECON1,WR 
           BSF INTCON, GIE 
    _endasm
                   
                  
    EEADR = 0X01;
    EEDATA = hrVarBOR;

    _asm
           BSF STATUS, RP0 
           BCF INTCON, GIE 
           BSF EECON1, WREN 
           MOVLW 0x55 
           MOVWF EECON2 
           MOVLW AAh 
           MOVWF EECON2 
           BSF EECON1,WR 
           BSF INTCON, GIE 
    _endasm */
                   
    INTCON3bits.INT1F = 0;
    while (BusyXLCD());
    SetDDRamAddr(0x50);
    while (BusyXLCD());
    putrsXLCD("               ");
    while(BusyXLCD());
    SetDDRamAddr(0x50);
    while(BusyXLCD());
    putrsXLCD("Low Voltage!");
    return;
}

/*void BORrestoreLCD (void)
{
    char hrVarOutput[4];       //Maximum of 4 outputs
    char bpmOutput[4];         //Maximum of 3 characters
    
    RCONbits.BOR = 1;
    //Main screen
    
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    while(BusyXLCD());
    putrsXLCD("BPM:");
    
    while(BusyXLCD());
    SetDDRamAddr(0x08);
    while(BusyXLCD());
    putrsXLCD("RRR:");
    
    while(BusyXLCD());
    SetDDRamAddr(0x40);
    while(BusyXLCD());
    putrsXLCD("Glucose:");
    
    while(BusyXLCD());
    SetDDRamAddr(0x10);
    while(BusyXLCD());
    putrsXLCD("TEMP:");
    
    
    //Restoring HR Var
    itoa(hrVar,hrVarOutput);
    while(BusyXLCD());
    SetDDRamAddr(0x0C);
    while(BusyXLCD());
    putrsXLCD("    ");
    while(BusyXLCD());                          //Outputting HR Var
    SetDDRamAddr(0x0C);    
    while(BusyXLCD());
    putsXLCD(hrVarOutput);
    while(BusyXLCD());
    
    //Restoring BPM
    itoa(bpm,bpmOutput);
    
    //Outputting BPM
    while(BusyXLCD());
    SetDDRamAddr(0x04);
    while(BusyXLCD());    
    putrsXLCD("   ");
    while(BusyXLCD());
    SetDDRamAddr(0x04);
    while(BusyXLCD());    
    putsXLCD(bpmOutput);
}*/
