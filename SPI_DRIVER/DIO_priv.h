/*
 * DIO_priv.h
 *
 *  Created on: 18 Nov 2022
 *      Author: Ayman El-Tanboly
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

/*******************************************************************************/
/**********************************Private Macros*******************************/
/*******************************************************************************/
#define PORTA_REG	*((volatile u8*) 0x3B)
#define PINA_REG	*((volatile u8*) 0x39)
#define DDRA_REG	*((volatile u8*) 0X3A)

#define PORTB_REG	*((volatile u8*)0x38)
#define PINB_REG	*((volatile u8*)0x36)
#define DDRB_REG	*((volatile u8*)0x37)

#define PORTC_REG	*((volatile u8*)0x35)
#define PINC_REG	*((volatile u8*)0x33)
#define DDRC_REG	*((volatile u8*)0x34)

#define PORTD_REG	*((volatile u8*)0x32)
#define PIND_REG	*((volatile u8*)0x30)
#define DDRD_REG	*((volatile u8*)0x31)

#endif /* DIO_PRIV_H_ */
