#include <p18f452.h>

int keyPos (void)
{
    int posLower = PORTA & 0xFF; //11111111
    int pos = PORTE & 0x07;
    int posUpper = pos ^ 0xC3;
    int keyValue = posLower + posUpper;
      
    return keyValue;
}

void main()
{
    PORTA = 0xFF;
    PORTE = 0x7;
    
    keyPad();
    
}
