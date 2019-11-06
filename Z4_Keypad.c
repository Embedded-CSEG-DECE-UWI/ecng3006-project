#include    <p18f452.h>
#include    "Keypad.h"
#include    "xlcd_GpE.h"

SemaphoreHandle_t keypadSem;

void configKeypad(void) {
    //Set the upper nibble of TRISC to inputs
    TRISC = 0xF0;

    //Set up RB0 as an external interrupt
    INTCONbits.INT0F = 0; //Clear the interrupt flag
    INTCON2bits.INTEDG0 = 1; //Rising edge
    INTCONbits.INT0IE = 1; //Enable the RBO interrupt
    return;
}

void keypadTask(void *pvParameter) {
    
    keypadSem = xSemaphoreCreateCounting( 1, 0);
    
    for (;;) {
        if (xSemaphoreTake(keypadSem, (TickType_t) 25000 ) == pdTRUE) {
            int key = (BIT0 * 1 + BIT1 * 2 + BIT2 * 4 + BIT3 * 8);
            SetDDRamAddr(0x00);
            while (BusyXLCD());
            putrsXLCD("                ");
            switch (key) {
                case 0:
                    while (BusyXLCD());
                    SetDDRamAddr(0x00);
                    while (BusyXLCD());
                    putrsXLCD("1");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
                case 1:
                    while (BusyXLCD());
                    SetDDRamAddr(0x01);
                    while (BusyXLCD());
                    putrsXLCD("2");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
                case 2:
                    while (BusyXLCD());
                    SetDDRamAddr(0x02);
                    while (BusyXLCD());
                    putrsXLCD("3");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
                case 3:
                    while (BusyXLCD());
                    SetDDRamAddr(0x03);
                    while (BusyXLCD());
                    putrsXLCD("A");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
                case (4):
                    while (BusyXLCD());
                    SetDDRamAddr(0x00);
                    while (BusyXLCD());
                    putrsXLCD("4");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
                case (5):
                    while (BusyXLCD());
                    SetDDRamAddr(0x01);
                    while (BusyXLCD());
                    putrsXLCD("5");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
                case (6):
                    while (BusyXLCD());
                    SetDDRamAddr(0x02);
                    while (BusyXLCD());
                    putrsXLCD("6");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
                case (7):
                    while (BusyXLCD());
                    SetDDRamAddr(0x03);
                    while (BusyXLCD());
                    putrsXLCD("B");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
                case (8):
                    while (BusyXLCD());
                    SetDDRamAddr(0x00);
                    while (BusyXLCD());
                    putrsXLCD("7");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
                case (9):
                    while (BusyXLCD());
                    SetDDRamAddr(0x01);
                    while (BusyXLCD());
                    putrsXLCD("8");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
                case (10):
                    while (BusyXLCD());
                    SetDDRamAddr(0x02);
                    while (BusyXLCD());
                    putrsXLCD("9");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
                case (11):
                    while (BusyXLCD());
                    SetDDRamAddr(0x03);
                    while (BusyXLCD());
                    putrsXLCD("C");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
                case (12):
                    while (BusyXLCD());
                    SetDDRamAddr(0x00);
                    while (BusyXLCD());
                    putrsXLCD("0");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
                case (13):
                    while (BusyXLCD());
                    SetDDRamAddr(0x01);
                    while (BusyXLCD());
                    putrsXLCD("F");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
                case (14):
                    while (BusyXLCD());
                    SetDDRamAddr(0x02);
                    while (BusyXLCD());
                    putrsXLCD("E");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
                case (15):
                    while (BusyXLCD());
                    SetDDRamAddr(0x03);
                    while (BusyXLCD());
                    putrsXLCD("D");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
                default:
                    while (BusyXLCD());
                    SetDDRamAddr(0x00);
                    while (BusyXLCD());
                    putrsXLCD("An Error!");
                    while (BusyXLCD());
                    INTCONbits.INT0F = 0;
                    break;
            }
        } else {
            while (BusyXLCD());
            SetDDRamAddr(0x00);
            while (BusyXLCD());
            putrsXLCD("DNG Keypad Sem!");
            while (BusyXLCD());
            INTCONbits.INT0F = 0;
        }
    }
}

#pragma interruptlow keypadISR
void keypadISR ( void )
{
    INTCONbits.INT0F = 0;
    xSemaphoreGiveFromISR(keypadSem, NULL);
}
