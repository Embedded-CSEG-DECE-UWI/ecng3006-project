
/**********libraries**********/

#include <p18f452.h>
#include <delays.h>
#include "xlcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <timers.h>
#include <math.h> 
#include <string.h>
#include "ow.h"


/**********DEFINES**********/

#pragma config WDT = OFF
#pragma config OSC = HS
#pragma config LVP = OFF

#define valid   0x56
#define invalid 0x49

#define mmstate 0
#define meastate 1
#define savstate 2
#define rmstate 3
#define readstate 4
#define delstate 5

#define OUTPUT 0
#define INPUT 1

#define _XTAL_FREQ 4000000UL

/********** KEYPAD **********/
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

/********** RAM **********/
#define Clock      LATAbits.LATA2   //SRClock
#define Clock_Tris TRISAbits.TRISA2

#define Latch      LATAbits.LATA1   // Rclock
#define Latch_Tris TRISAbits.TRISA1

#define Data        LATCbits.LATC3
#define Data_Tris   TRISCbits.TRISC3

#define OE         PORTBbits.RB3
#define OE_Tris    TRISBbits.TRISB3

#define WE         PORTBbits.RB5 
#define WE_Tris    TRISBbits.TRISB5

#define Heartbeat  PORTCbits.RC2
#define Heartbeat_Tris    TRISCbits.TRISC2

#define D0         PORTAbits.RA3
#define D0_Tris    TRISAbits.TRISA3

#define D1         PORTBbits.RB4
#define D1_Tris    TRISBbits.TRISB4


#define D2         PORTAbits.RA5 
#define D2_Tris    TRISAbits.TRISA5

#define D3         PORTBbits.RB2
#define D3_Tris   TRISBbits.TRISB2

#define D4         PORTEbits.RE0
#define D4_Tris    TRISEbits.TRISE0

#define D5        PORTEbits.RE1
#define D5_Tris    TRISEbits.TRISE1

#define D6         PORTEbits.RE2
#define D6_Tris   TRISEbits.TRISE2

#define D7         PORTCbits.RC0
#define D7_Tris    TRISCbits.TRISC0

/********** LCD LINES **********/
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

/*typedef enum
{
    invalid,            //0
    valid               //1
}validity;*/

typedef struct
{
    char vald;
    state nextState;
    TPT action;
}stateElement;

/**********global variables**********/
state curState;
event key;
int dataWrite;
int data_HR;
int data_HRV;
int data_Temp;
int data_Gluc;
int dataRead_1;
int dataRead_2;
int dataRead_3;
int dataRead_4;
long i;
long j;
char d1[4];
char d2[4];
char d3[4];
char d4[4];
char tempDisply[20];
char tempDisplay[3];
float tempRecord =0.0;
int ste = 0;
int sts = 0;
stateElement StateTable[EVENTSX][STATESX];
//TPT todo;


/**********LCD Functions**********/
void DelayFor18TCY(void)
{
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop(); Nop(); Nop(); 
     Nop(); Nop();
     return;
}

void DelayXLCD(void)
{
    Delay1KTCYx(5);	
    return;
}

void DelayPORXLCD(void)
{
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

void xlcdClr(void)
{
 
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

 /********** TEMP **********/
void tempConfig(void) {
 
  ow_reset(); //initialize the temp sensor
  ow_write_byte(0x0C); // master issues write to status command
  ow_write_byte(0x00); // writes to the status for continuous, one wire mode
  ow_reset(); //reset the device
  ow_write_byte(0xAC); // writes to the status for continuous, one wire mode
  ow_reset();

}

//measures the temperature value
float measureTemp(void)

{
  int loop = 0;
  float tempAvg = 0.0;
  int tempRead, tempTotal = 0;

  while (loop < 150) {
   
    ow_write_byte(0xEE); // begin temperature conversion
    ow_write_byte(0x22); //stop temperature                                                                                                                                                                                                                                                                                                                                                                     
    ow_reset(); //reset the device
    ow_write_byte(0xAA); //master issuses read temperature command
    tempRead = ow_read_byte(); // master reads temp value
    ow_reset();
    tempTotal = tempTotal + tempRead;
    loop++;

  }
  tempAvg = (float) tempTotal / 150;

  return tempAvg;
}
// reverses a string 'str' of length 'len' 
void reverse(char * str, int len) {
  int i = 0, j = len - 1, temp;
  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}

// Converts a given integer x to string str[].  d is the number 
// of digits required in output. If d is more than the number 
// of digits in x, then 0s are added at the beginning. 
int intToStr(int x, char str[], int d) {
  int i = 0;
  while (x) {
    str[i++] = (x % 10) + '0';
    x = x / 10;
  }

  // If number of digits required is more, then 
  // add 0s at the beginning 
  while (i < d)
    str[i++] = '0';

  reverse(str, i);
  str[i] = '\0';
  return i;
}

// Converts a floating point number to string. 
void ftoa(float n, char * res, int afterpoint) {
  // Extract integer part 
  int ipart = (int) n;

  // Extract floating part 
  float fpart = n - (float) ipart;

  // convert integer part to string 
  int i = intToStr(ipart, res, 0);

  // check for display option after point 
  if (afterpoint != 0) {
    res[i] = '.'; // add dot 

    // Get the value of fraction part upto given no. 
    // of points after dot. The third parameter is needed 
    // to handle cases like 233.007 
    fpart = fpart * pow(10, afterpoint);

    intToStr((int) fpart, res + i + 1, afterpoint);
  }
}

float tempRecord;

/********** RAM **********/
void ramPinConfig(void)
{
   // ADCON1 = (0b00000111);
    ADCON1bits.PCFG = 0b1110;
    TRISEbits.PSPMODE =0;
    Clock_Tris = 0;
    Latch_Tris = 0;
    Data_Tris = 0;
    //CE_Tris   = OUTPUT;
    OE_Tris   = OUTPUT;
    WE_Tris = OUTPUT;
    Heartbeat_Tris =0;
   // Direction_Tris = 0;
}

void dataPinConfig( short int a)
{
    D7_Tris =a;
    D6_Tris =a;
    D5_Tris =a;
    D4_Tris =a;
    D3_Tris =a;
    D2_Tris =a;
    D1_Tris =a;
    D0_Tris =a;
    //Direction =a;
}

void clearAddress(void)
{
    int i = 0;
    ramPinConfig();
    Latch=0;
    
    Nop();
    Nop();
    Nop();
    Clock=0;
    while ( i <19)
    {
        Data =0;
        Nop();
        Nop();
        Clock = 1;
        //Delay1KTCYx(20);
        //Delay10KTCYx(100);
        Nop();
        Nop();
        Nop();
        Clock =0;
       // Delay1KTCYx(20);
       // Delay10KTCYx(100);
        Nop();
        Nop();
        Nop();
       i++;
    }
    Latch = 1;
    // Delay1KTCYx(20);
   // Delay10KTCYx(100);  
    Nop();
    Nop();
    Nop();
    Latch =0;
}

void setAddress(long x)
{    
    int i=0;
    //int mulTwo;
    ramPinConfig();
    clearAddress();
    // Clear all address pins
    //   mulTwo =1;
    Latch=0;
    Clock=0;
    
    // Delay10KTCYx(100);
    while (i<19)
    {
        Data = (x >>i) & 0x01;
        Nop();
        Nop();
        Clock = 1;
        //Delay1KTCYx(20);
        //Delay10KTCYx(100);
        Nop();
        Nop();
        Nop();
        Clock =0;
        // Delay1KTCYx(20);
        // Delay10KTCYx(100);
        Nop();
        Nop();
        Nop();
        i++;
        //mulTwo = mulTwo*2;

        Latch = 1;
        // Delay1KTCYx(20);
        // Delay10KTCYx(100);  
        Nop();
        Nop();
        Nop();

        Latch =0;
    
        //Delay10KTCYx(100);
    }
}

void sectorDelete(long address)
{    
    dataPinConfig(0);
    // CE=0; //set Chip enable low
    OE=1; 
    WE = 1;
    
    //Set data to AAH
    D7 =1;
    D6 =0;
    D5 =1;
    D4 =0;
    D3 =1;
    D2 =0;
    D1 =1;
    D0 =0;
    
    setAddress(0X5555);
    
    WE =0;
    Nop();
    WE=1;
    Nop();
    
    //set data to 55H
    D7 =0;
    D6 =1;
    D5 =0;
    D4 =1;
    D3 =0;
    D2 =1;
    D1 =0;
    D0 =1;
    setAddress(0X2AAA);
    
    WE =0;
    Nop();
    WE =1;
    
     //set data to 80H
    D7 =1;
    D6 =0;
    D5 =0;
    D4 =0;
    D3 =0;
    D2 =0;
    D1 =0;
    D0 =0;
    setAddress(0X5555);
    
    //set data to 80H    
    WE =0;
    Nop();
    WE =1;

    //Set data to AAH
    D7 =1;
    D6 =0;
    D5 =1;
    D4 =0;
    D3 =1;
    D2 =0;
    D1 =1;
    D0 =0;
    setAddress(0X5555);

    WE =0;
    Nop();
    WE =1;

    //set data to 55H
    D7 =0;
    D6 =1;
    D5 =0;
    D4 =1;
    D3 =0;
    D2 =1;
    D1 =0;
    D0 =1;
    setAddress(0X2AAA);
    
    
    WE =0;
    Nop();
    WE =1;
    
    
    //set data to 30H
    D7 =0;
    D6 =0;
    D5 =1;
    D4 =1;
    D3 =0;
    D2 =0;
    D1 =0;
    D0 =0;
    setAddress(address);

    WE =0;
    Nop();
    WE =1;
    
    Delay1KTCYx(25); //wait for 25 ms for sector delete to complete
    
   // CE=1;
    
    return;
}

void chipDelete(void)
{

    dataPinConfig(0);
   // CE=0; //set Chip enable low
    OE=1; 
    WE = 1;

    //Set data to AAH
    D7 =1;
    D6 =0;
    D5 =1;
    D4 =0;
    D3 =1;
    D2 =0;
    D1 =1;
    D0 =0;

    setAddress(0X5555);

 

    WE =0;
    Nop();
    WE=1;
    Nop();

    //set data to 55H
    D7 =0;
    D6 =1;
    D5 =0;
    D4 =1;
    D3 =0;
    D2 =1;
    D1 =0;
    D0 =1;
    setAddress(0X2AAA);



    WE =0;
    Nop();
    WE =1;

     //set data to 80H
    D7 =1;
    D6 =0;
    D5 =0;
    D4 =0;
    D3 =0;
    D2 =0;
    D1 =0;
    D0 =0;
    setAddress(0X5555);

    //set data to 80H


    WE =0;
    Nop();
    WE =1;




    //Set data to AAH
    D7 =1;
    D6 =0;
    D5 =1;
    D4 =0;
    D3 =1;
    D2 =0;
    D1 =1;
    D0 =0;
    setAddress(0X5555);




    WE =0;
    Nop();
    WE =1;



    //set data to 55H
    D7 =0;
    D6 =1;
    D5 =0;
    D4 =1;
    D3 =0;
    D2 =1;
    D1 =0;
    D0 =1;
    setAddress(0X2AAA);


    WE =0;
    Nop();
    WE =1;


    //set data to 10H
    D7 =0;
    D6 =0;
    D5 =0;
    D4 =1;
    D3 =0;
    D2 =0;
    D1 =0;
    D0 =0;
    setAddress(0X5555);



    WE =0;
    Nop();
    WE =1;

    Delay1KTCYx(100); //wait for 25 ms for sector delete to complete

   // CE=1;

    return;

}

int readFromRam (long readAddress )
{
    int dataRead =0;
    //CE =0;
    WE=1;
    OE=1;
   
    dataPinConfig(1);
   
    setAddress(readAddress);
   
    OE=0;
   
    Nop();
   
    dataRead = (D0*1)+(D1*2)+(D2*4)+(D3*8)+(D4*16)+(D5*32)+(D6*64)+(D7*128);
   
   
    return dataRead;

}

void wirteToRam(long writeAddress, int writeData)
{
    dataPinConfig(0);
    
    // sectorDelete(writeAddress);
    
    WE=1;
    OE=1;
    //CE =0;
    
    setAddress(0X5555);
    
      //Set data to AAH
    D7 =1;
    D6 =0;
    D5 =1;
    D4 =0;
    D3 =1;
    D2 =0;
    D1 =1;
    D0 =0;
    
    
  
    
    WE =0;
    Nop();
    WE =1;
    
    
    setAddress(0X2AAA);
    D7 =0;
    D6 =1;
    D5 =0;
    D4 =1;
    D3 =0;
    D2 =1;
    D1 =0;
    D0 =1;
    
    //set data to 55H
    
    
    WE =0;
    Nop();
    WE =1;
    
    //Set data to A0H
    D7 =1;
    D6 =0;
    D5 =1;
    D4 =0;
    D3 =0;
    D2 =0;
    D1 =0;
    D0 =0;
    setAddress(0X5555);
    
    
    WE =0;
    Nop();
    WE =1;
    
    
   
     //Set data to the data to be written
    D7 = (writeData & 128) && 128;
    D6 = (writeData & 64) && 64;
    D5 = (writeData & 32) && 32;
    D4 = (writeData & 16) && 16;
    D3 = (writeData & 8) && 8;
    D2 = (writeData & 4) && 4;
    D1 = (writeData & 2)&& 2;
    D0 = writeData & 1;
    setAddress(writeAddress);
    
   
    
    WE =0;
    Nop();
    WE =1;
    
   Delay10KTCYx(2);  

   
   return;

}

/**********prototypes for actions**********/
void mainmenu()
{
    curState = mmstate;
    xlcdClr();
    while(BusyXLCD());
    SetDDRamAddr(l1);
    while(BusyXLCD());
    putrsXLCD("Main Menu");
    while(BusyXLCD());
    SetDDRamAddr(l2);
    while(BusyXLCD());
    putrsXLCD("KEY2: mesasure");
    while(BusyXLCD());
    SetDDRamAddr(l3);
    while(BusyXLCD());
    putrsXLCD("KEY4: RAM Menu");
    DelayPORXLCD();
    
}

void measure()
{
    curState =meastate;
    xlcdClr();
    tempRecord = measureTemp();
    ftoa(tempRecord, tempDisplay, 1);// converts the floating point temperature value to a string/character array
    while(BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while(BusyXLCD());
    putrsXLCD(tempDisplay);
    //tempdisp(tempRecord);
    DelayPORXLCD();
    
}

void svtRAM()
{
    curState = savstate;
    xlcdClr();
    dataWrite =2;
    i=100;
    while (i<=1000)
    {
        wirteToRam(i,dataWrite);
        //dataWrite++;
        i++;
    }
    while(BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while(BusyXLCD());
    putrsXLCD("Reading Stored");
    DelayPORXLCD();
    
}

void rammenu()
{
    curState = rmstate;
    xlcdClr();
    while(BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while(BusyXLCD());
    putrsXLCD("RAM Menu");
    while(BusyXLCD());
    SetDDRamAddr(l2);
    while(BusyXLCD());
    putrsXLCD("KEY5: View Saved");
    while(BusyXLCD());
    SetDDRamAddr(l3);
    while(BusyXLCD());
    putrsXLCD("KEY6: Clear RAM");
    DelayPORXLCD();
    DelayPORXLCD();
    
}

void rdRAM()
{
    curState = readstate;   
    xlcdClr();
    //dataWrite =100;
    dataRead_1 =0;
    dataRead_2 =0;
    dataRead_3 =0;
    dataRead_4 =0;
    //i =1 ;
    j=100;
    //char d1[4];
    //char d2[4];
    //char d3[4];
    //char d4[4];    
   
        
    /*while (i<=16)
    {
        wirteToRam(i,dataWrite);
        dataWrite++;
        i++;
    }*/
    
    //output initial value
    dataRead_1 =readFromRam(j);
    dataRead_2 =readFromRam(j+1);
    dataRead_3 =readFromRam(j+2);
    dataRead_4 =readFromRam(j+3);

    itoa(dataRead_1 ,d1);
    itoa(dataRead_2 ,d2);
    itoa(dataRead_3 ,d3);
    itoa(dataRead_4 ,d4);

    DelayPORXLCD();
    while (BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while (BusyXLCD());
    putsXLCD(d1);
    DelayPORXLCD();

    while (BusyXLCD());
    SetDDRamAddr(l2);
    DelayPORXLCD();
    putsXLCD(d2);
    DelayPORXLCD();

    while (BusyXLCD());
    SetDDRamAddr(l3);
    DelayPORXLCD();
    putsXLCD(d3);
    DelayPORXLCD();

    while (BusyXLCD());
    SetDDRamAddr(l4);
    DelayPORXLCD();
    putsXLCD(d4);
    DelayPORXLCD();

    //Delay10KTCYx(200);
    
}

void delRAM()
{
    curState = delstate;
    xlcdClr();
    chipDelete();
    while(BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while(BusyXLCD());
    putrsXLCD("RAM cleared");
    DelayPORXLCD();
    
}

void incRAM()
{
    curState = readstate;
    xlcdClr();
    j+=4;
    /*while(BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while(BusyXLCD());
    putrsXLCD("NEXT");
    DelayPORXLCD();*/
    dataRead_1 =readFromRam(j);
    dataRead_2 =readFromRam(j+1);
    dataRead_3 =readFromRam(j+2);
    dataRead_4 =readFromRam(j+3);

    itoa(dataRead_1 ,d1);
    itoa(dataRead_2 ,d2);
    itoa(dataRead_3 ,d3);
    itoa(dataRead_4 ,d4);

    DelayPORXLCD();
    while (BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while (BusyXLCD());
    putsXLCD(d1);
    DelayPORXLCD();

    while (BusyXLCD());
    SetDDRamAddr(l2);
    DelayPORXLCD();
    putsXLCD(d2);
    DelayPORXLCD();

    while (BusyXLCD());
    SetDDRamAddr(l3);
    DelayPORXLCD();
    putsXLCD(d3);
    DelayPORXLCD();

    while (BusyXLCD());
    SetDDRamAddr(l4);
    DelayPORXLCD();
    putsXLCD(d4);
    DelayPORXLCD();

  //  Delay10KTCYx(200);
    
}

void decRAM()
{
    curState = readstate;
    xlcdClr();
    /*while(BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while(BusyXLCD());
    putrsXLCD("BACK");
    DelayPORXLCD();*/
    j-=4;
    dataRead_1 =readFromRam(j);
    dataRead_2 =readFromRam(j+1);
    dataRead_3 =readFromRam(j+2);
    dataRead_4 =readFromRam(j+3);

    itoa(dataRead_1 ,d1);
    itoa(dataRead_2 ,d2);
    itoa(dataRead_3 ,d3);
    itoa(dataRead_4 ,d4);

    DelayPORXLCD();
    while (BusyXLCD());
    SetDDRamAddr(l1);
    DelayPORXLCD();
    while (BusyXLCD());
    putsXLCD(d1);
    DelayPORXLCD();

    while (BusyXLCD());
    SetDDRamAddr(l2);
    DelayPORXLCD();
    putsXLCD(d2);
    DelayPORXLCD();

    while (BusyXLCD());
    SetDDRamAddr(l3);
    DelayPORXLCD();
    putsXLCD(d3);
    DelayPORXLCD();

    while (BusyXLCD());
    SetDDRamAddr(l4);
    DelayPORXLCD();
    putsXLCD(d4);
    DelayPORXLCD();

    //Delay10KTCYx(200);
}

void null()
{}

stateElement STable[EVENTSX][STATESX] = 
{
        //state_0                       state_1                         state_2                         state_3                         state_4                         state_5
    {   {valid,state_0,mainmenu},       {valid,state_0,mainmenu},       {valid,state_0,mainmenu},       {valid,state_0,mainmenu},       {valid,state_0,mainmenu},       {valid,state_0,mainmenu}  },    //main menu
    {   {valid,state_1,measure},        {valid,state_1,measure},        {valid,state_1,measure},        {invalid,state_3,null},         {invalid,state_3,null},         {invalid,state_3,null}  },        //HR
    {   {invalid,state_0,null},         {valid,state_2,svtRAM},         {invalid,state_2,null},         {invalid,state_3,null},         {invalid,state_4,null},         {invalid,state_5,null}  },        //save reading
    {   {valid,state_3,rammenu},        {invalid,state_1,null},         {invalid,state_2,null},         {valid,state_3,rammenu},        {valid,state_3,rammenu},        {valid,state_3,rammenu}  },        //ram menu
    {   {invalid,state_0,null},         {invalid,state_1,null},         {invalid,state_2,null},         {valid,state_4,rdRAM},          {valid,state_4,rdRAM},          {invalid,state_5,null}  },        //read ram
    {   {invalid,state_0,null},         {invalid,state_1,null},         {invalid,state_2,null},         {valid,state_5,delRAM},         {invalid,state_4,null},         {invalid,state_5,null}  },        //delete ram
    {   {invalid,state_0,null},         {invalid,state_1,null},         {invalid,state_2,null},         {invalid,state_3,null},         {valid,state_4,incRAM},         {invalid,state_5,null}  },        //inc ram
    {   {invalid,state_0,null},         {invalid,state_1,null},         {invalid,state_2,null},         {invalid,state_3,null},         {valid,state_4,decRAM},         {invalid,state_5,null}  }         //dec ram
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

void mainmenu(void);

 void main(void)
 {
    LCDsetup();
    ramPinConfig();
    tempConfig();
    key =0;
    //TRISBbits.RB0 = 1;       
    TRIS_DATA0 =1;
    TRIS_DATA1 =1;
    TRIS_DATA2 =1;
    TRIS_DATA3 =1;
    INTCONbits.GIE = 0;
    mainmenu();
    
    while(ste<=8)
    {
        sts=0;
        while(sts<=6)
        {
            StateTable[ste][sts].action = STable[ste][sts].action;
            StateTable[ste][sts].vald = STable[ste][sts].vald;
            StateTable[ste][sts].nextState = STable[ste][sts].nextState;
            sts++;
        }
        ste++;
    }
    while(1)
    {
        while(RB0 == 1)     //a key is pressed
        {
            key = keyass( (DATA0*4) + (DATA1*2) + (DATA2*1) + (DATA3*8) ) ;
            if (key<8)
            {
                if (StateTable[key][curState].vald == valid)
                {
                    (*(StateTable[key][curState].action))();
                    curState = StateTable[key][curState].nextState;
                    Nop();
                    //(*(STable[key][curState].action))();
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
