/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Samier
 */
#include "../MCAL/ADC/ADC_int.h"
#include "../MCAL/DIO/DIO_int.h"
# define F_CPU 8000000UL

void ADC_End_Job (void)
{
  DIO_vWrtPinDir(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);
  DIO_vWrtPinVal(DIO_PORTB,DIO_PIN0,DIO_HIGH);
}
extern volatile u16 ADC_Result;

int main(void){
	/*
	DIO_vWrtPinDir(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);
	DIO_vWrtPinDir(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);
	//MADC_VSetCallback(ADC_End_Job);
	MADC_VInt();
	while(1)
	{
	MADC_U16SynchConvertion(1,&ADC_Result);
	if(ADC_Result <= 500)
	{
		  DIO_vWrtPinVal(DIO_PORTB,DIO_PIN0,DIO_HIGH);
	}
	else
	{
		 DIO_vWrtPinVal(DIO_PORTB,DIO_PIN0,DIO_LOW);
	}

	}
	*/
}
