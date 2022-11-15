/*
 * Timer_prv.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Samier
 */

#ifndef MCAL_TIMER_PRV_H_
#define MCAL_TIMER_PRV_H_
/***********************************************/
#define TCCR0  *((volatile  u8 *)0x53)
#define TCNT0  *((volatile  u8 *)0x52)
#define OCR0   *((volatile u8 *)0x5C)
#define TIMSK  *((volatile u8 *)0x59)
#define TIFR   *((volatile u8 *)0x58)

#define WGM01 (3)
#define WGM00 (6)
#define FOC0  (7)
/*******************TIMSK************************/

#define OCIE0 (1)
#define TOIE0 (0)

/********************TIFR***********************/

#define OCF0 (1)
#define TOV0 (0)

/*********************************************/

#define ok             (1)
#define NotOk          (0)
#define Enable         (1)
#define Disable        (0)

#define Normal_Mode    (10)
#define PWM_Mode       (1)
#define CTC_Mode       (2)
#define FPWM_Mode      (3)

#define PRE_Mask       (0b11111000)
#define N0_CLK         (0b000)
#define Prescaler1     (0b001)
#define Prescaler8     (0b010)

#endif /* MCAL_TIMER_PRV_H_ */
