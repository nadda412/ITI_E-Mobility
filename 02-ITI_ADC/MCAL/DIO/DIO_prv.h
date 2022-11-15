/*
 * DIO_prv.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Samier
 */

#ifndef MCAL_DIO_DIO_PRV_H_
#define MCAL_DIO_DIO_PRV_H_

#define PIND   *((volatile u8 *)(0x30))
#define DDRD   *(( u8 *)(0x31))
#define PORTD  *(( u8 *)(0x32))

#define PINC    *((volatile u8 *)(0x33))
#define DDRC    *(( u8 *)(0x34))
#define PORTC   *(( u8 *)(0x35))

#define PINB    *((volatile u8 *)(0x36))
#define DDRB    *(( u8 *)(0x37))
#define PORTB   *(( u8 *)(0x38))

#define PINA    *((volatile u8 *)(0x39))
#define DDRA    *(( u8 *)(0x3A))
#define PORTA   *(( u8 *)(0x3B))




#endif /* MCAL_DIO_DIO_PRV_H_ */
