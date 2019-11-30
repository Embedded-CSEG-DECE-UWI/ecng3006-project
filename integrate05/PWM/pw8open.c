#include <p18Cxxx.h>
#include <pwm.h>

/********************************************************************
*    Function Name:  OpenPWM8                                       *
*    Return Value:   void                                           *
*    Parameters:     period: PWM period                             *
*    Description:    This routine first resets the PWM registers    *
*                    to the POR state.  It then configures clock    *
*                    source.                                        *
********************************************************************/
#if defined (PWM_V14) || defined (PWM_V14_1) ||defined (PWM_V14_3) || defined (PWM_V14_4)
void OpenPWM8 ( unsigned char period, unsigned char timer_source )
{
  unsigned char TBLPTR_U, TBLPTR_L;

_asm
movff TBLPTRU, TBLPTR_U
movff TBLPTRL, TBLPTR_L
_endasm

  CCP8CON=0b00001100;    //ccpxm3:ccpxm0 11xx=pwm mode

  //configure timer source for CCP
  CCPTMRS2 &= 0b11111100;
  CCPTMRS2 |= ((timer_source&0b00110000)>>4);
 
#if defined (PWM_V14_IO_V1) || defined (PWM_V15_IO_V1) || defined (PWM_V15_2_IO_V1)
  if (((*(unsigned char far rom *)__CONFIG3H) & 0b00000010))
     TRISEbits.TRISE4 = 0;
  #ifndef PWM_V15_2_IO_V1
  else
     TRISHbits.TRISH5 = 0;
  #endif	 
#else
	PWM8_TRIS = 0;
#endif
 
  if( (CCPTMRS2&0x03)==0x00)
  {
  T2CONbits.TMR2ON = 0;  // STOP TIMERx registers to POR state
  PR2 = period;          // Set period
  T2CONbits.TMR2ON = 1;  // Turn on PWMx
  }
  
  else if( (CCPTMRS2&0x03)==0x01)
  {
  T4CONbits.TMR4ON = 0;  // STOP TIMERx registers to POR state
  PR4 = period;          // Set period
  T4CONbits.TMR4ON = 1;  // Turn on PWMx
  }
  
  else if( (CCPTMRS2&0x03)==0x02)
  {
  T6CONbits.TMR6ON = 0;  // STOP TIMERx registers to POR state
  PR6 = period;          // Set period
  T6CONbits.TMR6ON = 1;  // Turn on PWMx  
  }
  
    
}

#endif
