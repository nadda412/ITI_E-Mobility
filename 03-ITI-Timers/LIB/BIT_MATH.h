/*
 * BIT_MATH.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Samier
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define _BIT_MATH_H_
#define SET_BIT(Reg, bitnum)       (Reg |=1<<bitnum)
#define CLR_BIT(Reg, bitnum)       (Reg &=~(1<<bitnum))
#define TOGGLE_BIT(Reg, bitnum)    (Reg ^=(1<<bitnum))
#define GET_BIT(Reg, bitnum)       ((Reg>>bitnum)& 0x01)
#define SET_BYTE(Reg,value)         ( Reg = value )
#define WRT_BIT(REG, BIT, VAL) ( (REG) = ( ( (REG) & (~(1<<(BIT))) ) | ( (VAL) << (BIT)  ) ) )


#endif /* LIB_BIT_MATH_H_ */
