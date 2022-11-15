/*
 * Timer_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Samier
 */

#ifndef MCAL_TIMER_INT_H_
#define MCAL_TIMER_INT_H_

#define Timer0ID    (1)
#define Timer1ID    (2)
#define Timer2ID    (3)

void MTIMERS_VInt(void);
void MTIMERS_VSetPreLoad(u16 A_u16PerLoadValue);
u8 MTIMERS_VStart(/*TimerID*/ u8 A_u8TimerID);
u8 MTIMERS_VStop(/*TimerID*/u8 A_u8TimerID);
u8 MTIMERS_VSetInterval(u16 A_u16Counts, void (*A_ptr)(void));
u8 MTIMERS_VSetInterval_CTC(u16 A_u16Counts, void (*A_ptr)(void), u16 A_CompareValue);


#endif /* MCAL_TIMER_INT_H_ */
