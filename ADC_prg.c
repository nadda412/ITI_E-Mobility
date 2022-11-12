/*
 * ADC_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Samier
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


#include "ADC_int.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"


volatile u16 ADC_Result=0;
//void (*ADC_END)(void);
void (*ADC_CallBack)(void);
void MADC_VInt(void)
{
	//1- Select voltage source
#if Ref_Voltage_Selection== AVCC_Ref_Voltage
	CLR_BIT(ADC_ADMUX,REFS1);
	SET_BIT(ADC_ADMUX,REFS0);
#elif Ref_Voltage_Selection == External_Ref_Voltage
	CLR_BIT(ADC_ADMUX,REFS1);
	CLR_BIT(ADC_ADMUX,REFS0);
#elif  Ref_Voltage_Selection == Internal_Ref_Voltage
	SET_BIT(ADC_ADMUX,REFS1);
	SET_BIT(ADC_ADMUX,REFS0);
#endif
	//2-Select adjustment

        #if Data_ADJ_DIR==Right_Adjust
	        CLR_BIT(ADC_ADMUX,ADLAR);

        #elif  Data_ADJ_DIR==Left_Adjust
	        SET_BIT(ADC_ADMUX,ADLAR);
        #endif

	//3- Select Prescaler
        #if   Perscaler == Prescaler2
	        ADC_ADCSRA = (ADC_ADCSRA &(AND_Mask));
	        ADC_ADCSRA = (ADC_ADCSRA | Prescaler2);
        #elif   Perscaler == Prescaler4
	        ADC_ADCSRA = (ADC_ADCSRA &(AND_Mask));
	        ADC_ADCSRA = (ADC_ADCSRA | Prescaler4);
        #endif

	//4- Auto Trigger Enable/Disable
       #if Auto_Trigger==Disable
	        CLR_BIT(ADC_ADCSRA,ADATE);
       #elif Auto_Trigger==Enable
	        SET_BIT(ADC_ADCSRA,ADATE);
       #endif
    //5 - Interrupt Enable
       #if Interrupt == Enable
	        SET_BIT(ADC_ADCSRA,ADIE);
       #elif Interrupt == Disable
            CLR_BIT(ADC_ADCSRA,ADIE);
      #endif
	//5- ADC Enable
        #if ADC_Status==Enable
         	SET_BIT(ADC_ADCSRA,ADEN);
        #elif ADC_Status==Disable
         	CLR_BIT(ADC_ADCSRA,ADEN);
        #endif

}

u16 MADC_U16SynchConvertion(u8 No_channel,u16 *result)
{
	u8 Time_Counter=0;
   //1-Select Channel //
	ADC_ADMUX = (ADC_ADMUX & (0b11100000));
	ADC_ADMUX = (ADC_ADMUX | No_channel );
   //2-Start Conversion
	SET_BIT(ADC_ADCSRA,ADSC);
   //3- Poll on the flag
	while ( (GET_BIT(ADC_ADCSRA,ADIF)==0 )  && (Time_Counter == 1000) )
	{
		Time_Counter++;
	}
   //4-Clear Flag
	CLR_BIT(ADC_ADCSRA,ADIF);
	if(Time_Counter == 1000)
	{
		return Not_Ok;
	}
	else
	{
		return ok;

	}
   //5-Save Result
	*result =ADC_ADCL;
}

u16 MADC_U16ASynchConvertion(u8 No_channel, u16 *result)
{

	//1-Select Channel //
	ADC_ADMUX = (ADC_ADMUX & (0b11100000));
	ADC_ADMUX = (ADC_ADMUX | No_channel );
   //2-Start Conversion
	SET_BIT(ADC_ADCSRA,ADSC);
}

void MADC_VSetCallback(void (*A_Ptr0)(void) )
{
	ADC_CallBack= A_Ptr0;
}
void __vector_16(void)  __attribute((signal));

void __vector_16(void)
{
	ADC_Result=ADC_ADCL;
	ADC_CallBack();
}
