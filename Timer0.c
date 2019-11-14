void high_interrupt(void) 
{
    if (INTCONbits.TMR0IF == 1)
    {
    _asm
            goto timer10sIsr
    _endasm
    }



void main (void)
{
    
}
