/*
 * Timer_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Samier
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "Timer_int.h"
#include "Timer_prv.h"
#include "Timer_cfg.h"

static volatile void (*TIM0_CallBack_Ptr)(void);
static volatile void (*TIM0_CTC_CallBack_Ptr)(void);
volatile u16 G_u16Counts;

void MTIMERS_VInt(void)
{
	//1- Timer Mode Selection
#if Timer0_operation==Enable
        #if Timer0_Mode_Selection == CTC_Mode
	      SET_BIT(TCCR0,WGM00);
	      CLR_BIT(TCCR0,WGM01);

	   	SET_BIT(TIMSK,OCIE0);
        #elif Timer0_Mode_Selection == Normal_Mode
	      CLR_BIT(TCCR0,WGM00);
	      CLR_BIT(TCCR0,WGM01);

	  	SET_BIT(TIMSK,TOIE0);
        #elif Timer0_Mode_Selection == PWM_Mode
	      CLR_BIT(TCCR0,WGM00);
	      SET_BIT(TCCR0,WGM01);
        #elif Timer0_Mode_Selection == FPWM_Mode
	      SET_BIT(TCCR0,WGM00);
	      SET_BIT(TCCR0,WGM01);
        #else
        #error  "Please select A valid timer mode"
        #endif
#endif

#if Timer1_operation==Enable

#endif

#if Timer2_operation==Enable

#endif

	//3- Compare Match
	CLR_BIT(TCCR0,FOC0);

	//3- Interuupt Enable

}


u8 MTIMERS_VSetInterval(u16 A_u16Counts, void (*A_ptr)(void))
{
	if(A_ptr != NULL)
	{
	//1- Assign wanted Values to the Global variables to be used in ISR
	    G_u16Counts=A_u16Counts;
     	TIM0_CallBack_Ptr=A_ptr;
	    //2-Start Timer
	    TCCR0 = TCCR0 & (PRE_Mask);
	    TCCR0 = TCCR0 | (Prescaler8);
       return ok;
	}
	else
	{
		return NotOk;
	}

}

u8 MTIMERS_VSetInterval_CTC(u16 A_u16Counts, void (*A_ptr)(void), u16 A_CompareValue)
{
	if(A_ptr != NULL)
	{
	//1- Assign wanted Values to the Global variables to be used in ISR
    G_u16Counts=A_u16Counts;
    TIM0_CTC_CallBack_Ptr=A_ptr;
     OCR0=A_CompareValue;
    //2-Start Timer
    TCCR0 = TCCR0 & (PRE_Mask);
    TCCR0 = TCCR0 | (Prescaler8);

    return ok;
	}
	else
	{
		return NotOk;
	}
}
void MTIMERS_VSetPreLoad(u16 A_u16PerLoadValue)
{
    TCNT0 = A_u16PerLoadValue;
}

u8 MTIMERS_VStart(u8 A_u8TimerID)
{
  if(A_u8TimerID <= 3)
  {
	switch(A_u8TimerID)
	{
	case Timer0ID :TCCR0 = TCCR0 & (PRE_Mask);
	               TCCR0 = TCCR0 | (Prescaler8);
	               break;
	case Timer1ID:  /**/ break;
	case Timer2ID:  /**/ break;
	}
	return ok;
   }
  else
  {
	  return NotOk;
  }
}


u8 MTIMERS_VStop(u8 A_u8TimerID)
{
	  if(A_u8TimerID <= 3)
	  {
		switch(A_u8TimerID)
		{
		case Timer0ID :	TCCR0 = TCCR0 & (PRE_Mask);
		                TCCR0 = TCCR0 | (N0_CLK);
		               break;
		case Timer1ID:  /**/ break;
		case Timer2ID:  /**/ break;
		}
		return ok;
	   }
	  else
	  {
		  return NotOk;
	  }


}

//Timer0 overflow ISR
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static u16 L_u16Counts=0; //Represent numbers of ovf. actually happened
	L_u16Counts++;

	if(L_u16Counts == G_u16Counts) // check if the actual ovf equal the required ones
	{
		if(TIM0_CallBack_Ptr != NULL)
		{
			TIM0_CallBack_Ptr();  //Take your action
			L_u16Counts=0;
		}

	}

}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u16 L_u16Counts=0; //Represent numbers of ovf. actually happened
		L_u16Counts++;

		if(L_u16Counts == G_u16Counts) // check if the actual ovf equal the required ones
		{
			if(TIM0_CTC_CallBack_Ptr != NULL)
			{
				TIM0_CTC_CallBack_Ptr(); //Take your action
				L_u16Counts=0;
			}

		}

}
