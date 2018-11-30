#include <p18f452.h>
#include <delays.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwm.h>
#include <timers.h>

void Speaker_Off_Task(void)
{
    ClosePWM1();
    return;
}

