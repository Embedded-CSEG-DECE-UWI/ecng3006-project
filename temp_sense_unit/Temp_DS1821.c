
#include <delays.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h> 
#include <p18f452.h> 
#include "xlcd_A.h"
#include "ow.h"

/* Write the appropriate code to set configuration bits: * - set HS oscillator * - disable watchdog timer * - disable low voltage programming */
#pragma config OSC = HS
#pragma config WDT = OFF //Disable watchdog timer
#pragma config LVP = OFF //Disable low voltage programming

#define _XTAL_FREQ 4000000

#define OW_LAT LATCbits.LATC7
#define OW_PIN PORTCbits.RC7
#define OW_TRIS TRISCbits.TRISC7

#define OUTPUT 0
#define INPUT 1

#define l1 0x00 //addresses of the beginning of line1
#define l2 0x40 //addresses of the beginning of line2
#define l3 0x10 //addresses of the beginning of line3
#define l4 0x50 //addresses of the beginning of line4

char tempDisplay[3];

//PreLab Q16a

void DelayFor18TCY(void) {
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
  Nop();
  Nop();
}

//PreLab Q16b

void DelayXLCD(void) {
  Delay1KTCYx(5);
  return;
}

//PreLab Q16c

void DelayPORXLCD(void) {
  Delay1KTCYx(15);
  return;
}
 

int setup(void) {
  DelayPORXLCD();
  while (BusyXLCD());
  OpenXLCD(FOUR_BIT & LINES_5X7);
  DelayPORXLCD();
  while (BusyXLCD());
  SetDDRamAddr(0x00);

}
// configures the temperature sensor
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


void main(void) {

  setup();
  tempConfig();
  while (1) {
    tempRecord = measureTemp();

    ftoa(tempRecord, tempDisplay, 1);// converts the floating point temperature value to a string/character array

    DelayPORXLCD();
    //while(BusyXLCD());
    //SetDDRamAddr(0x50);
    while (BusyXLCD());
    putrsXLCD(tempDisplay);
    DelayPORXLCD();
    //while (BusyXLCD());
    //SetDDRamAddr(0x40);
    //Delay1KTCYx(500);
    //while(1){}
  }
}