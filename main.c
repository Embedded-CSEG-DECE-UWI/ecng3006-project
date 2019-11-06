/*
 * Author: Yehu Carrington
 * Group: E - Plus Ultra
 * Date: 05/11/2019
 */

/*HEADER FILES*/
#include    "FreeRTOS.h"
#include    "task.h"
#include    "xlcd_GpE.h"
#include    "Keypad.h"
#include    <p18f452.h>

/*PIC18 CONFIGURATION SETTINGS*/
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define XTAL_FREQ 4000000

/*VARIABLES*/

/*FUNCTION PROTOTYPES*/
void keypadTask (void *pvParameter);
void keypadISR (void);

void main (void)
{
    INTCONbits.GIE = 0;
    xTaskCreate( keypadTask, "keypadTask", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    configKeypad();
    InitLCD();
    vTaskStartScheduler();
}