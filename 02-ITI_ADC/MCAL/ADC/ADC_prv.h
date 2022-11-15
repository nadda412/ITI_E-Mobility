/*
 * ADC_prv.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Samier
 */

#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_

/************ADMUX*****************************/
#define REFS1  (7)
#define REFS0  (6)
#define ADLAR  (5)
/*************ADCSRA**************************/
#define ADEN   (7)
#define ADSC   (6)
#define ADATE  (5)
#define ADIF   (4)
#define ADIE   (3)
/****The ADC Data Register – ADCL and ADCH**/

/*************SFIOR********/

/*********************************/
#define ADC_ADMUX   *((volatile u8 *)(0x27))
#define ADC_ADCSRA  *((volatile u8 *)(0x26))
#define ADC_ADCH    *((volatile u8 *)(0x25))
#define ADC_ADCL    *((volatile u8 *)(0x24))
#define ADC_SFIOR   *((volatile u8 *)(0x50))

/****************************************/
#define Disable              (0)
#define Enable                  (1)

#define  AVCC_Ref_Voltage        (0)
#define  External_Ref_Voltage    (1)
#define  Internal_Ref_Voltage    (2)

#define Right_Adjust  (0)
#define Left_Adjust   (1)

#define Prescaler2    (0b001)
#define Prescaler4    (0b010)
#define Prescaler8    (0b011)
#define Prescaler16   (0b100)
#define Prescaler32   (0b101)
#define Prescaler64   (0b110)
#define Prescaler128  (0b111)

#define AND_Mask (0b11111000)

#endif /* MCAL_ADC_ADC_PRV_H_ */
