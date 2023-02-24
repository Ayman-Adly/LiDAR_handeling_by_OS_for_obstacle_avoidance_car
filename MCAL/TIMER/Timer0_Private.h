/**
 * @file Timer0_Private.h .
 * @author Hisham Montaser. 
 * @brief This is the Timer0_Private.h for defining Timer registers .
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 * @details This file defining everything that is private to the periphral either registers or private definition for macros . 
 */
/**************************************************************************************************************/
/*                          HeaderGuard : Prevent Multiple calls of Private.h header file                     */
/**************************************************************************************************************/
#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_
/**************************************************************************************************************/
/*                          Macros of Timer0 Registers                                                        */
/**************************************************************************************************************/

#define OCR0              *((volatile u8 *)0x5C)
#define TIMSK             *((volatile u8 *)0x59)
#define TIFR              *((volatile u8 *)0x58)
#define TCCR0             *((volatile u8 *)0x53)
#define TCNT0             *((volatile u8 *)0x52)

/***************************************************************************************************************/
/*                          Macros of TIMSK Register                                                           */
/***************************************************************************************************************/

#define  OCIE2           7
#define  TOIE2           6
#define  TICIE1          5
#define  OCIE1A          4
#define  OCIE1B          3
#define  TOIE1           2
#define  OCIE0           1
#define  TOIE0           0

/****************************************************************************************************************/
/*                          Macros of TIFR Register                                                             */
/****************************************************************************************************************/

#define  OCF2            7
#define  TOV2            6
#define  ICF1            5
#define  OCF1A           4
#define  OCF1B           3
#define  TOV1            2
#define  OCF0            1
#define  TOV0            0

/****************************************************************************************************************/
/*                          Macros of TCCR0                                                                     */
/****************************************************************************************************************/

#define FOC0             7
#define WGM00            6
#define COM01            5
#define COM00            4
#define WGM01            3
#define CS02             2
#define CS01             1
#define CS00             0

/****************************************************************************************************************/
/*                          USER CONFIGRAUTIONS                                                                 */
/****************************************************************************************************************/

/* TIMER0_MODES */

/******************************/
#define Normal               0
#define PWM_PHASE_CORRECT    1
#define CTC                  2
#define FAST_PWM             3
/******************************/

/* Compare OutPut Mode , Non PWM Mode */

/*****************************************************/
#define OC0_Disconnected_NON_PWM_MODE               0
#define Toggle_OC0_ON_COMPARE_MATCH_NON_PWM_MODE    1
#define Clear_OC0_ON_COMPARE_MATCH_NON_PWM_MODE     2
#define Set_OC0_ON_COMPARE_MATCH_NON_PWM_MODE       3
/*****************************************************/

/* Compare OutPut Mode , Fast PWM Mode */

/******************************************************/
#define OC0_Disconnected_FAST_PWM_MODE              0
#define Clear_OC0_ON_COMPARE_MATCH_FAST_PWM_MODE    1
#define Set_OC0_ON_COMPARE_MATCH_FAST_PWM_MODE      2
/******************************************************/

/* Compare OutPut Mode , Phase Correct PWM Mode */

/**************************************************************/
#define OC0_Disconnected_PHASE_CORRECT_PWM_MODE             0
#define Clear_OC0_ON_COMPARE_MATCH_PHASE_CORRECT_PWM_MODE   1
#define Set_OC0_ON_COMPARE_MATCH_PHASE_CORRECT_PWM_MODE     2
/**************************************************************/

/* Clock Select Description */

/**********************************************/
#define NO_CLK_SOURCE                       0
#define CLK_NO_PRE_SCALING                  1
#define CLK_PRE_SCALING_8                   2
#define CLK_PRE_SCALING_64                  3
#define CLK_PRE_SCALING_256                 4
#define CLK_PRE_SCALING_1024                5
#define EXTERNAL_CLK_SOURCE_ON_FALLING_EDGE 6
#define EXTERNAL_CLK_SOURCE_ON_RISING_EDGE  7
/**********************************************/

/* Interrupt Enable/Disable */

/*********************************************/
#define Enable  1
#define Disable 0



#endif /* TIMER0_PRIVATE_H_ */
