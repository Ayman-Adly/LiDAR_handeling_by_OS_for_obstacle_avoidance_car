/**
 * @file Timer0_Config.h.
 * @author Hisham Montaser. 
 * @brief This is the Timer0Config.h for file configraution.
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 * @details This file gives the ability for the user to feel some sort of felxibilty with the chocies the developer made .
 */

/**************************************************************************************************************/
/*                     HeaderGuard : Prevent Multiple calls of Config.h header file                           */
/**************************************************************************************************************/

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

/* Select The Mode Where The Timer Is Going To Work On :
 * Options : 1-Normal
 * 			 2-CTC
 * 			 3-FAST_PWM
 * 			 4-PWM_PHASE_CORRECT  */

#define MODE FAST_PWM

/* Select Compare OutPut Mode , NON-PWM MODE
 * Options : 1-OC0_Disconnected_NON_PWM_MODE
 * 		     2-Toggle_OC0_ON_COMPARE_MATCH_NON_PWM_MODE
 * 		     3-Clear_OC0_ON_COMPARE_MATCH_NON_PWM_MODE
 * 		     4-Set_OC0_ON_COMPARE_MATCH_NON_PWM_MODE  */

#define  COMPARE_OUTPUT_MODE_NON_PWM_MODE  OC0_Disconnected_NON_PWM_MODE

/* Select Compare OutPut Mode , FAST-PWM MODE
 * Options : 1-OC0_Disconnected_FAST_PWM_MODE
 * 			 2-Clear_OC0_ON_COMPARE_MATCH_FAST_PWM_MODE
 * 			 3-Set_OC0_ON_COMPARE_MATCH_FAST_PWM_MODE */

#define COMPARE_OUTPUT_MODE_FAST_PWM_MODE   Clear_OC0_ON_COMPARE_MATCH_FAST_PWM_MODE

/* Select Compare OutPut Mode , PHASE_CORRECT_PWM_MODE
 * Options : 1-OC0_Disconnected_PHASE_CORRECT_PWM_MODE
 *   		 2-Clear_OC0_ON_COMPARE_MATCH_PHASE_CORRECT_PWM_MODE
 *   		 3-Set_OC0_ON_COMPARE_MATCH_PHASE_CORRECT_PWM_MODE */

#define COMPARE_OUTPUT_MODE_PHASE_CORRECT_PWM_MODE	 OC0_Disconnected_PHASE_CORRECT_PWM_MODE

/*Select CLK Source
 * Options : 1-NO_CLK_SOURCE
 * 			 2-CLK_NO_PRE_SCALING
 * 			 3-CLK_PRE_SCALING_8
 * 			 4-CLK_PRE_SCALING_64
 * 			 5-CLK_PRE_SCALING_256
 * 			 6-CLK_PRE_SCALING_1024
 * 			 7-EXTERNAL_CLK_SOURCE_ON_FALLING_EDGE
 * 			 8-EXTERNAL_CLK_SOURCE_ON_RISING_EDGE  */

#define CLOCK_SOURCE  CLK_PRE_SCALING_64

/*Select Interrupt StateOVF
 * Options : 1-Enable
 * 			 2-Disable */

#define Interrupt_StateOVF Disable

/*Select Interrupt StateOC
 * Options : 1-Enable
 * 			 2-Disable */

#define Interrupt_StateOC Disable

#endif /* TIMER0_CONFIG_H_ */
