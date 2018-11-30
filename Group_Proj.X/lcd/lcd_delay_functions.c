void DelayFor18TCY(void)    //Delay for 18 instruction cycles
{
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
    Nop();
    Nop();
    Nop();
    Nop();
    return;
}

void DelayPORXLCD()     //Delay for 15ms
{
    Delay1KTCYx(15);
    return;
}

void DelayXLCD()        //Delay for 5ms
{
    Delay1KTCYx(5);
    return;
}
