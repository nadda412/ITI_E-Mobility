/*
 * ADC_cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Samier
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_
/*1- ADC Enable
 * Selection 1 :Enable
 * Selection 2:Disable
 * */
#define ADC_Status Enable

/*2- Reference Voltage selection
 * Selection 1: External_Ref_Voltage
 * Selection 2: AVCC_Ref_Voltage
 * Selection 3:Internal_Ref_Voltage
 * */
#define Ref_Voltage_Selection External_Ref_Voltage

/* 3- Data Adjustment Direction
 * Selection 1: Left Adjust
 * Selection 2: Right Adjust
 * */
#define Data_ADJ_DIR   Right_Adjust

/* 4- Prescaler Selection
 * Selection 1: Prescaler2
 * Selection 2: Prescaler4
 * Selection 3: Prescaler8
 * Selection 4: Prescaler16
 * Selection 5: Prescaler32
 * Selection 6: Prescaler64
 * Selection 7: Prescaler128

 * */
#define Perscaler Prescaler2

/*5- Auto Trigger Enable *
 * Selection 1: Enable
 * Selection 2:Disable
 * */
#define Auto_Trigger  Disable

/*5- Interrupt Enable *
 * Selection 1: Enable
 * Selection 2:Disable
 * */

#define Interrupt Disable

#endif /* MCAL_ADC_ADC_CFG_H_ */
