#include    "FreeRTOS.h"
#include    <queue.h>
#include    "xlcd_GpE.h"
#include    "Modules.h"
#include    <p18f452.h>
#include    <string.h>

QueueHandle_t xlcdQueue;

void lcdTask(void *pvParameter) {
    struct lcdMessage displayBuffer;
    char tmpID;
    char bpmID;
    tmpID = 'T';
    bpmID = 'B';
    while (1) {
        xQueueReceive(xlcdQueue, &displayBuffer, portMAX_DELAY);
        if (displayBuffer.srcID == tmpID){
            while (BusyXLCD());
            SetDDRamAddr(0x00);
            while (BusyXLCD());
            putrsXLCD("               ");
            while (BusyXLCD());
            SetDDRamAddr(0x00);
            while (BusyXLCD());
            putsXLCD(displayBuffer.srcMessage);
            while (BusyXLCD());
        }
        
        else if (displayBuffer.srcID == bpmID){
            while (BusyXLCD());
            SetDDRamAddr(0x40);
            while (BusyXLCD());
            putsXLCD(displayBuffer.srcMessage);
            while (BusyXLCD());
        }
    }
}