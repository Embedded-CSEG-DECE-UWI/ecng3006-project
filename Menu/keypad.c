#include <p18f452.h> 

int value;

//Function Prototypes
void KeypadSetup(void);
int press();

void KeypadSetup(void)                          //Setup for keypad
{
    TRISCbits.RC7 = 1; //A                      //Defining ports for each input
    TRISCbits.RC6 = 1; //B
    TRISCbits.RC5 = 1; //C
    TRISCbits.RC4 = 1; //D
}

int press()
{
if (!PORTCbits.RC7 && !PORTCbits.RC6 && !PORTCbits.RC5 && !PORTCbits.RC4 )
    {
      value = 1;
    }
 if (PORTCbits.RC7 && PORTCbits.RC6 && !PORTCbits.RC5 && !PORTCbits.RC4 )
    {
      value = 2;
    } 
 if (!PORTCbits.RC7 && PORTCbits.RC6 && !PORTCbits.RC5 && !PORTCbits.RC4)
    {
      value = 3;
    } 
  if (!PORTCbits.RC7 && !PORTCbits.RC6 && PORTCbits.RC5 && !PORTCbits.RC4)
    {
      value = 4;
    }
  if (PORTCbits.RC7 && PORTCbits.RC6 && PORTCbits.RC5 && !PORTCbits.RC4 )
    {
      value = 5;
    }
  if (!PORTCbits.RC7 && PORTCbits.RC6 && PORTCbits.RC5 && !PORTCbits.RC4 )
    {
      value = 6;
    }
  if (!PORTCbits.RC7 && !PORTCbits.RC6 && !PORTCbits.RC5 && PORTCbits.RC4 )
    {
      value = 7;
    }
  if (PORTCbits.RC7 && PORTCbits.RC6 && !PORTCbits.RC5 && PORTCbits.RC4 )
    {
      value = 8;
    }
  if (!PORTCbits.RC7 && PORTCbits.RC6 && !PORTCbits.RC5 && PORTCbits.RC4 )
    {
      value = 9;
    }
  if (!PORTCbits.RC7 && !PORTCbits.RC6 && PORTCbits.RC5 && PORTCbits.RC4 )
    {
      value = 0;
    }
if (PORTCbits.RC7 && !PORTCbits.RC6 && !PORTCbits.RC5 && !PORTCbits.RC4 )
    {
      value = 10;
    }
  if (PORTCbits.RC7 && !PORTCbits.RC6 && PORTCbits.RC5 && !PORTCbits.RC4 )
    {
      value = 11;
    }
  if (PORTCbits.RC7 && !PORTCbits.RC6 && !PORTCbits.RC5 && PORTCbits.RC4 )
    {
      value = 12;
    }
  if (PORTCbits.RC7 && !PORTCbits.RC6 && PORTCbits.RC5 && PORTCbits.RC4 )
    {
      value = 13;
    }
  if (!PORTCbits.RC7 && PORTCbits.RC6 && PORTCbits.RC5 && PORTCbits.RC4 )
    {
      value = 14;
    }
  if (PORTCbits.RC7 && PORTCbits.RC6 && PORTCbits.RC5 && PORTCbits.RC4 )
    {
      value = 15;
    }
return value;
}
