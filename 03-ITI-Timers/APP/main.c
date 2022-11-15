/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Samier
 */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/TIMERS/Timer_int.h"

void func(void)
{
	DIO_vWrtPinVal(DIO_PORTA,DIO_PIN0,DIO_HIGH);
	DIO_vWrtPinVal(DIO_PORTA,DIO_PIN1,DIO_HIGH);

}

void main (void)
{

	DIO_vWrtPinDir(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	DIO_vWrtPinDir(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
	MTIMERS_VInt();
	//MTIMERS_VSetInterval(2000,func);
	MTIMERS_VSetInterval_CTC(2000,func,250);
	MGIE_vEnableGlobalInterrupt();

	while(1)
	{

	}
}

