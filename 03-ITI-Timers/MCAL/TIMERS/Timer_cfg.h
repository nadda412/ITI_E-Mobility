/*
 * Timer_cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Samier
 */

#ifndef MCAL_TIMER_CFG_H_
#define MCAL_TIMER_CFG_H_
/////////////////////////Timer0_Configuration/////////////////////////
#define Timer0_operation Enable

/////////////////////////Timer1_Configuration/////////////////////////
#define Timer1_operation Disable

/////////////////////////Timer2_Configuration/////////////////////////
#define Timer2_operation Disable


/*1-Timer0 Mode Selection
 * Selection 1: Normal_Mode
 * Selection 2: PWM_Mode
 * Selection 3: CTC_Mode
 * Selection 4: FPWM_Mode
 * */
#define Timer0_Mode_Selection  CTC_Mode

#endif /* MCAL_TIMER_CFG_H_ */
