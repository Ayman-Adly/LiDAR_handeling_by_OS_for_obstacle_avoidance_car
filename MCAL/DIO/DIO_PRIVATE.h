/**
 * @file DIO_Private.h .
 * @author Hisham Montaser. 
 * @brief This is the DIO_Private.h for defining DIO registers .
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 * @details This file defining everything that is private to the periphral either registers or private definition of macros . 
 */
/**************************************************************************************************************/
/*                          HeaderGuard : Prevent Multiple calls of Private.h header file                     */
/**************************************************************************************************************/
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_
/**************************************************************************************************************/
/*@brief                    Macros of DIO Registers                                                           */
/**************************************************************************************************************/

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


#endif /* DIO_PRIVATE_H_ */
