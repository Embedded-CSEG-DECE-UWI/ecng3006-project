/* 
 * File:   main.c
 * Author: Yehu Carrington
 *
 * Created on November 25, 2019, 11:25 AM
 */

/*HEADER FILES*/
#include    "FreeRTOS.h"
#include    "task.h"
#include    "queue.h"
#include    "xlcd_GpE.h"
#include    "timers.h"
#include    "Modules.h"
#include    <p18f452.h>

/*PIC18 CONFIGURATION SETTINGS*/
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#define XTAL_FREQ 4000000

void main(void) {
    initLCD();
    xlcdQueue = xQueueCreate(2, sizeof(struct lcdMessage));


    if ((xTaskCreate(tempTask, "TempTask", (configMINIMAL_STACK_SIZE), NULL, 1, NULL)) != pdPASS) {
        while (BusyXLCD());
        SetDDRamAddr(0x00);
        while (BusyXLCD());
        putrsXLCD("TempFailed");
        while (BusyXLCD());
    }

    if ((xTaskCreate(lcdTask, "LCDTask", (configMINIMAL_STACK_SIZE), NULL, 3, NULL)) != pdPASS) {
        while (BusyXLCD());
        SetDDRamAddr(0x40);
        while (BusyXLCD());
        putrsXLCD("LCDTaskFailed");
        while (BusyXLCD());
    }
    vTaskStartScheduler();
}

