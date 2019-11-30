
/**********libraries**********/

#include <p18f452.h>
#include <delays.h>
#include "xlcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <timers.h>


/**********DEFINES**********/

#pragma config WDT = OFF
#pragma config OSC = HS
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000UL

//#define TRIS_INT0   TRISBbits.RB0
#define RB0        PORTBbits.RB0

#define TRIS_DATA0  TRISCbits.RC6
#define DATA0       PORTCbits.RC6

#define TRIS_DATA1  TRISCbits.RC5
#define DATA1       PORTCbits.RC5

#define TRIS_DATA2  TRISCbits.RC4
#define DATA2       PORTCbits.RC4

#define TRIS_DATA3  TRISDbits.RD3
#define DATA3       PORTDbits.RD3

#define l1  0x00
#define l2  0x40
#define l3  0x10
#define l4  0x50

#define STATESX     6
#define EVENTSX     8

typedef void (*TPT) (void);

typedef enum
{
    state_0,        //main menu
    state_1,        //disp measured
    state_2,        //stored screen
    state_3,        //ram menu
    state_4,        //read from ram
    state_5         //delete screen
}state;

typedef enum
{
    event_0,        //KEY 1 - main menu
    event_1,        //KEY 2 - begin HR
    event_2,        //KEY 3 - save reading to ram
    event_3,        //KEY 4 - ram menu
    event_4,        //KEY 5 - read ram
    event_5,        //KEY 6 - clear ram
    event_6,        //KEY 7 - in read ram, go to next set of stored values
    event_7         //KEY 8 - in read ram, go back to previous set of stored values
}event;

typedef struct
{
    int valid;
    state nextState;
    TPT action;
}stateElement;

/**********global variables**********/
state cstate;
event key;
int ste = 0;
int sts = 0;
stateElement StateTable[EVENTSX][STATESX];
//TPT todo;


/**********LCD Functions**********/
void DelayFor18TCY(void){
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop();
     return;
}

void DelayXLCD(void){
    Delay1KTCYx(5);	
    return;
}

void DelayPORXLCD(void){
    Delay1KTCYx(15);
    return;
}

void LCDsetup(void)
{    
    PORTD = 0x00;
    TRISD = 0x00;
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    SetDDRamAddr(0x00);
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    while(BusyXLCD());
    WriteCmdXLCD( BLINK_ON );
    while(BusyXLCD());
    return;
 }

void xlcdClr(void){
 
    DelayPORXLCD();
    //while(BusyXLCD());
    //WriteCmdXLCD(0x01);
    while (BusyXLCD());
    SetDDRamAddr(l1);
    while (BusyXLCD());
    putrsXLCD("                ");
    while (BusyXLCD());
    DelayPORXLCD();
    SetDDRamAddr(l2);
    while (BusyXLCD());
    putrsXLCD("                ");
    while (BusyXLCD());
    DelayPORXLCD();
    SetDDRamAddr(l3);
    while (BusyXLCD());
    putrsXLCD("                ");
    DelayPORXLCD();
    SetDDRamAddr(l4);
    while (BusyXLCD());
    putrsXLCD("                ");
 }


/**********prototypes for actions**********/
void mainmenu()
{
    xlcdClr();
    //DelayPORXLCD();
    while(BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while(BusyXLCD());
    putrsXLCD("Main Menu");
    DelayPORXLCD();
    cstate = 0;
}

void measure()
{
    xlcdClr();
    while(BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while(BusyXLCD());
    putrsXLCD("HR Complete");
    DelayPORXLCD();
    cstate = 1;
}

void svtRAM()
{
    xlcdClr();
    while(BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while(BusyXLCD());
    putrsXLCD("Reading Stored");
    DelayPORXLCD();
    cstate = 2;
}

void rammenu()
{
    xlcdClr();
    while(BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while(BusyXLCD());
    putrsXLCD("RAM Menu");
    DelayPORXLCD();
    cstate = 3;
}

void rdRAM()
{
    xlcdClr();
    while(BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while(BusyXLCD());
    putrsXLCD("Initial value");
    DelayPORXLCD();
    cstate = 4;
}

void delRAM()
{
    xlcdClr();
    while(BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while(BusyXLCD());
    putrsXLCD("RAM cleared");
    DelayPORXLCD();
    cstate = 5;
}

void incRAM()
{
    xlcdClr();
    while(BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while(BusyXLCD());
    putrsXLCD("NEXT");
    DelayPORXLCD();
    cstate = 4;
}

void decRAM()
{
    xlcdClr();
    while(BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while(BusyXLCD());
    putrsXLCD("BACK");
    DelayPORXLCD();
    cstate = 4;
}

void null()
{}

stateElement STable[EVENTSX][STATESX] = 
{
        //state_0                   state_1                     state_2                     state_3                     state_4                     state_5
    {   {1,state_0,mainmenu},       {1,state_0,mainmenu},       {1,state_0,mainmenu},       {1,state_0,mainmenu},       {1,state_0,mainmenu},       {1,state_0,mainmenu}  },    //main menu
    {   {1,state_1,measure},        {1,state_1,measure},        {1,state_1,measure},        {0,state_3,null},           {0,state_3,null},           {0,state_3,null}  },        //HR
    {   {0,state_0,null},           {1,state_2,svtRAM},         {0,state_2,null},           {0,state_3,null},           {0,state_4,null},           {0,state_5,null}  },        //save reading
    {   {1,state_3,rammenu},        {0,state_1,null},           {0,state_2,null},           {1,state_3,rammenu},        {1,state_3,rammenu},        {1,state_3,rammenu}  },        //ram menu
    {   {0,state_0,null},           {0,state_1,null},           {0,state_2,null},           {1,state_4,rdRAM},          {1,state_4,rdRAM},          {0,state_5,null}  },        //read ram
    {   {0,state_0,null},           {0,state_1,null},           {0,state_2,null},           {1,state_5,delRAM},         {0,state_4,null},           {0,state_5,null}  },        //delete ram
    {   {0,state_0,null},           {0,state_1,null},           {0,state_2,null},           {0,state_3,null},           {1,state_4,incRAM},         {0,state_5,null}  },        //inc ram
    {   {0,state_0,null},           {0,state_1,null},           {0,state_2,null},           {0,state_3,null},           {1,state_4,decRAM},         {0,state_5,null}  }         //dec ram
};



int keyass(int keyvar)
{
    switch (keyvar)
    {
        case(0): 
            keyvar=0;
            break;
        case(1): 
            keyvar=1;
            break;
        case(2): 
            keyvar=2;
            break;
        case(4):
            keyvar = 3;
            break;
        case(5):
            keyvar = 4;
            break;
        case(6):
            keyvar = 5;
            break;
        case(8):
            keyvar = 6;
            break;
        case(9):
            keyvar = 7;
            break;
        case(3):
            keyvar = 10;
            break;
        case(7):
            keyvar = 11;
            break;    
        case(10):
            keyvar = 9;
            break;    
        case(11):
            keyvar = 12;
            break;
        case(12):
            keyvar = 16;
            break;
        case(13):
            keyvar = 15;
            break;
        case(14):
            keyvar = 14;
            break;
        case(15):
            keyvar = 13;
            break;
    }
    return keyvar;
}


 void main(void)
 {
    LCDsetup();
    //TRISBbits.RB0 = 1;       
    TRIS_DATA0 =1;
    TRIS_DATA1 =1;
    TRIS_DATA2 =1;
    TRIS_DATA3 =1;
    INTCONbits.GIE = 0;
    mainmenu();
    
    while(1)
    {
        while(ste<=8)
        {
            sts=0;
            while(sts<=6)
            {
                StateTable[ste][sts].action = STable[ste][sts].action;
                StateTable[ste][sts].valid = STable[ste][sts].valid;
                StateTable[ste][sts].nextState = STable[ste][sts].nextState;
                sts++;
            }
            ste++;
        }
        while(RB0 == 1)     //a key is pressed
        {
            key = keyass( (DATA0*4) + (DATA1*2) + (DATA2*1) + (DATA3*8) ) ;
            if (key<8)
            {
                if (StateTable[key][cstate].valid == 1)
                {
                    (*(StateTable[key][cstate].action))();
                    cstate = StateTable[key][cstate].nextState;
                    //(*(STable[key][cstate].action))();
                    break;
                }//finds the next state and action
                else
                {
                    Nop();
                }
                break;
            }//check for a valid keyc
            else 
            {
                Nop();
            } //an invalid key
            break;
        }//end polling of keypad data pin
    }//end infinite while
}