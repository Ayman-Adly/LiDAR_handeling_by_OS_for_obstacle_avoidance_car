/**
 * @file Timer0_Interface.h
 * @author Hisham Montaser 
 * @brief This is the Timer0_Interface.h file for function implementations . 
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 * @details This file has eight functions each function deal with timer peripheral and two functions handle timer peripheral interrupt .
 */
/****************************************************************************************************************/
/*Date                : 12 - 2 - 2023   (Date of implemeting)                                                   */
/* 01- MTimer0_voidInit                                                                                         */
/* 02- MTimer0_voidSetPreLoadValue                                                                              */
/* 03- MTimer0_voidSetCompareMatchValue                                                                         */
/* 04- MTimer0_voidStopTimer                                                                                    */
/* 05- MTimer0_voidInterputHandlingOVF                                                                          */
/* 06- MTimer0_voidInterputHanldingOC                                                                           */
/* 07- MTimer0_voidSetOVFISR                                                                                    */
/* 08- MTimer0_voidSetCompareMatchISR                                                                           */
/****************************************************************************************************************/

/**************************************************************************************************************/
/*                          HeaderGuard : Prevent Multiple calls of Interface.h header file                   */
/**************************************************************************************************************/
#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

/*************************************************************************************************************/
/*                                              Function Prototypes                                          */
/*************************************************************************************************************/


/*************************************************************************************************************/
/*                                               01- MTimer0_voidInit                                        */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Timer Initialization 
 * @param  No_Input_Parameters : void  
 * @return void  
 */
/*************************************************************************************************************/

void MTimer0_voidInit();

/*************************************************************************************************************/
/*                                               02- MTimer0_voidSetPreLoadValue                             */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Set PreLoadValue 
 * @param  Pre_u8Load : Value of the Pre-Load Must having a value from 0 to 255 . 
 * @return void  
 */
/*************************************************************************************************************/

void MTimer0_voidSetPreLoadValue(u8 Pre_u8Load);


/*************************************************************************************************************/
/*                                               03- MTimer0_voidSetCompareMatchValue                        */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Set PreLoadValue 
 * @param  CompareMatch_u8Value : Value of the CompareMatch_value Must be having a value from 0 to 255
 * @return void  
 */
/*************************************************************************************************************/

void MTimer0_voidSetCompareMatchValue(u8 CompareMatch_u8Value);

/*************************************************************************************************************/
/*                                               04- MTimer0_voidStopTimer                                   */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Stopping the timer from counting 
 * @param  No_Input_Parameters : void 
 * @return void  
 */
/*************************************************************************************************************/

void MTimer0_voidStopTimer();


/*************************************************************************************************************/
/*                                               05- MTimer0_voidInterputHanldingOVF                         */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Enabling/Disabling Timer OverFlow interrupt .
 * @param  No_Input_Parameters : void 
 * @return void  
 */
/*************************************************************************************************************/

void MTimer0_voidInterputHandlingOVF();

/*************************************************************************************************************/
/*                                               06- MTimer0_voidInterputHanldingOC                          */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Enabling/Disabling Timer Ouput Compare interrupt .
 * @param  No_Input_Parameters : void 
 * @return void  
 */
/*************************************************************************************************************/

void MTimer0_voidInterputHandlingOC();

/****************************************************************************************************************/
/*                                   Specific Purpose Functions Implementation                                  */
/****************************************************************************************************************/

/*************************************************************************************************************/
/*                                (void MTimer0_SetMode)                                                     */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Set Timer Mode (Normal, CTC, FAST_PWM, PWM_PHASE_CORRECT )
 * @param  No_Input_Parameters : void  
 * @return void  
 */
/*************************************************************************************************************/
void MTimer0_SetMode();
/*************************************************************************************************************/
/*                                (void MTimer0_SetCompareOutputMode_NON_PWM)                                */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Set Compare Output Mode NON_PWM (OC0_Disconnected_NON_PWM_MODE, Toggle_OC0_ON_COMPARE_MATCH_NON_PWM_MODE, Clear_OC0_ON_COMPARE_MATCH_NON_PWM_MODE, Set_OC0_ON_COMPARE_MATCH_NON_PWM_MODE)
 * @param  No_Input_Parameters : void  
 * @return void  
 */
/*************************************************************************************************************/
void MTimer0_SetCompareOutputMode_NON_PWM();
/*************************************************************************************************************/
/*                                (void MTimer0_SetCompareOutputMode_FAST_PWM)                               */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Set Compare Output Mode FAST_PWM (OC0_Disconnected_FAST_PWM_MODE, Clear_OC0_ON_COMPARE_MATCH_FAST_PWM_MODE, Set_OC0_ON_COMPARE_MATCH_FAST_PWM_MODE)
 * @param  No_Input_Parameters : void  
 * @return void  
 */
/*************************************************************************************************************/
void MTimer0_SetCompareOutPutMode_FAST_PWM();
/*************************************************************************************************************/
/*                                (void MTimer0_SetCompareOutputMode_PHASE_CORRECT_PWM)                      */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Set Compare Output Mode PHASE_CORRECT_PWM (OC0_Disconnected_PHASE_CORRECT_PWM_MODE, Clear_OC0_ON_COMPARE_MATCH_PHASE_CORRECT_PWM_MODE, Set_OC0_ON_COMPARE_MATCH_PHASE_CORRECT_PWM_MODE)
 * @param  No_Input_Parameters : void  
 * @return void  
 */
/*************************************************************************************************************/
void MTimer0_SetCompareOutPutMode_PHASE_CORRECT_PWM();
/*************************************************************************************************************/
/*                                (MTimer0_SetCLKSource)                                                     */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Set Timer Mode (NO_CLK_SOURCE, CLK_NO_PRE_SCALING, CLK_PRE_SCALING_8, CLK_PRE_SCALING_64, CLK_PRE_SCALING_256, CLK_PRE_SCALING_1024, EXTERNAL_CLK_SOURCE_ON_FALLING_EDGE, EXTERNAL_CLK_SOURCE_ON_RISING_EDGE)
 * @param No_Input_Parameters : void
 * @return void  
 */
/*************************************************************************************************************/
void MTimer0_SetCLKSource();

#endif /* TIMER0_INTERFACE_H_ */
