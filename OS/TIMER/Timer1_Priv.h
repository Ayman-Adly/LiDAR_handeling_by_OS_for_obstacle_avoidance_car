/****************************************************************************************
 * @file Timer1_Priv.h
 * @author Moamen ehab
 * @brief timer private files
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 ***************************************************************************************/

/****************************************************************************************
 * @brief Header guards
 * 
 ***************************************************************************************/
#ifndef TIMER1_PRIV_H_
#define TIMER1_PRIV_H_
/**
 * @brief private macros
 * 
 */
#define DESABLE (0)
#define ENABLE (1)

#define TCCR0_REG	*((volatile u8*)0X53)
#define OCR0_REG	*((volatile u8*)0X5C)
#define TIMSK_REG	*((volatile u8*)0X59)
#define TCNT0_REG	*((volatile u8*)0X52)

#define TCCR1A_REG  *((volatile u8*)0X4F)
#define WGM10  (0)
#define WGM11  (1)
#define FOC1B  (2)
#define FOC1A  (3)
#define COM1B0 (4)
#define COM1B1 (5)
#define COM1A0 (6)
#define COM1A1 (7)

#define TCCR1B_REG  *((volatile u8*)0X4E)
#define CS10  (0)
#define CS11  (1)
#define CS12  (2)
#define WGM12 (3)
#define WGM13 (4)
#define ICES1 (6)
#define ICNC1 (7)

#define ICR1_REG   *((volatile u16*)0X46)

#define OCR1A_REG  *((volatile u16*)0X4A)

#define OCR1B_REG  *((volatile u16*)0X48)


#define CS00  (0)
#define CS01  (1)
#define CS02  (2)
#define WGM01 (3)
#define COM00 (4)
#define COM01 (5)
#define WGM00 (6)
#define FOC0  (7)


#define TOIE0  (0)
#define OCIE0  (1)
/**
 * @brief end of header guards
 * 
 */
#endif /* TIMER0_PRIV_H_ */
