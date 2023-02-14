/***************************************************************************************/
/* Author               : Moamen ehab                                                  */
/* Version              : V0.0.0                                                       */
/* Date                 : 1 - 2 -2023                                                  */
/* Description          : TIMER1_Priv.h -> Register Definitions                        */
/***************************************************************************************/
#ifndef TIMER0_PRIV_H_
#define TIMER0_PRIV_H_

#define TIMSK_REG	*((volatile u8*)0X59)

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

#endif /* TIMER0_PRIV_H_ */
