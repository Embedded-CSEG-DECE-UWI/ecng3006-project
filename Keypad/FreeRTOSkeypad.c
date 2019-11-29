#include    <p18f452.h>
#include    "Modules.h"
#include    "xlcd_GpE.h"
#include    <queue.h>

/*
 * Configures RB0 to interrupt on a rising edge
 */
void configKeypad(void) {
    TRISC = 0x0F;   //Configuring upper nibble of TRISC as inputs

    TRISB = 0x01; //Configuring interrupt pins as input

    INTCONbits.INT0IE = 1; //Enabling INT0 interrupt
    INTCONbits.INT0IF = 0; //clearing INT0 interrupt flag
}

/*
 * Semaphore responsible for releasing the keypad task.
 */
SemaphoreHandle_t keypadSem;

/* 
 * The keypad task responsible for releasing all
 * Asynchronous task
 */
void keypadTask(void *pvParameter) {
    while(1) {
        if (xSemaphoreTake(keypadSem, portMAX_DELAY) == pdTRUE) { //Wait forever for a signaling semaphore
            int key = (BIT0 * 1 + BIT1 * 2 + BIT2 * 4);     //Once the semaphote has been aquired, determine the pressed key
            switch (key) {
                case 0:
                    xSemaphoreGive(tempSem);        //This is an example of how this switch case would have
                                                    //implemented the keypad as it would release semaphores
                                                    //That would signal to the task that it was their turn to
                                                    //run, the beauty here is that the scheduler would be
                                                    //responsible for which task would run, taking the burden off
                                                    //of the developer, provided that the priorites are properly aligned.
                    break;
                case 1:
                      while (BusyXLCD());
                    SetDDRamAddr(0x00);
                    while (BusyXLCD());
                    putrsXLCD("2");                 //This is just a placeholder example to be sent to the LCD
                                                    //to show that the task runs as expected and that it responds
                                                    //to the input of the keypad
                    while (BusyXLCD());
                    break;
                case 2:
                    while (BusyXLCD());
                    SetDDRamAddr(0x00);
                    while (BusyXLCD());
                    putrsXLCD("3");
                    while (BusyXLCD());
                    break;
                case 3:
                    while (BusyXLCD());
                    SetDDRamAddr(0x00);
                    while (BusyXLCD());
                    putrsXLCD("A");
                    break;
                case (4):
                    while (BusyXLCD());
                    SetDDRamAddr(0x00);
                    while (BusyXLCD());
                    putrsXLCD("4");
                    break;
                case (5):
                    while (BusyXLCD());
                    SetDDRamAddr(0x00);
                    while (BusyXLCD());
                    putrsXLCD("5");
                    break;
                case (6):
                    while (BusyXLCD());
                    SetDDRamAddr(0x00);
                    while (BusyXLCD());
                    putrsXLCD("6");
                    break;
                case (7):
                    while (BusyXLCD());
                    SetDDRamAddr(0x00);
                    while (BusyXLCD());
                    putrsXLCD("B");             //The code would essentially continue on in the same format
                    break;
                case (8):
                    break;
                case (9):
                    break;
                case (10):
                    break;
                case (11):;
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
                    while (BusyXLCD());         //This default case should never run, but it is here since it runs
                                                //In accordance with http://caxapa.ru/thumbs/468328/misra-c-2004.pdf
                                                //Rule 15.3 of the MISRAC guidelines
                    SetDDRamAddr(0x00);
                    while (BusyXLCD());
                    putrsXLCD("An Error!");
                    while (BusyXLCD());
                    break;
            }
        }
    }
}


#pragma interruptlow keypadISR                  //This is the ISR of the external interrupt that releases the keypad semaphore
void keypadISR(void) {
    portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;
    INTCONbits.INT0F = 0;                       //Clear the interrupt flag.
    xSemaphoreGiveFromISR(keypadSem, &xHigherPriorityTaskWoken);        //Give the semaphore from the ISR and if it awakens a higher
                                                                        //priority task, context switch to that task.
    if (xHigherPriorityTaskWoken) {
        taskYIELD();
    }
}