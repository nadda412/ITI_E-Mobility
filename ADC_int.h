/*
 * ADC_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Samier
 */

#ifndef MCAL_DIO_ADC_INT_H
#define MCAL_DIO_ADC_INT_H

#include "../../LIB/STD_TYPES.h"

#define ok (1)
#define Not_Ok (0)
///////////////////////////
#define Time_OUT  (100)

void MADC_VInt(void);
u16 MADC_U16SynchConvertion(u8 No_channel,u16 *result);

//Interrupt Based APIs
u16 MADC_U16ASynchConvertion(u8 No_channel, u16 *result);
void MADC_VSetCallback(void (*A_Ptr0)(void) );





#endif /* MCAL_DIO_ADC_INT_H_ */
