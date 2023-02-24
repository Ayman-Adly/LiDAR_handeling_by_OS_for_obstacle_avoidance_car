/**
 * @file HMD_L298N_Interface.h
 * @author Hisham Montaser 
 * @brief This is the HMD_L298N_Interface.h file for function prototype . 
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 * @details This file has five functions each one is responsible for controlling motors direction and the last one responsible for the stoppage of the motor .
 */
/****************************************************************************************************************/
/*Date : 13 - 2 - 2023     (Date of implementing )                                                              */
/* 01- HMD_L298N_DirectionForward                                                                               */
/* 02- HMD_L298N_DirectionBackward                                                                              */
/* 03- HMD_L298N_DirectionRight                                                                                 */
/* 04- HMD_L298N_DirectionLeft                                                                                  */
/* 05- HMD_L298N_MotorStop                                                                                      */
/****************************************************************************************************************/

/**************************************************************************************************************/
/*                        HeaderGuard : Prevent Multiple calls of Interface.h header file                     */
/**************************************************************************************************************/
#ifndef HMD_L298N_INTERFACE_H_
#define HMD_L298N_INTERFACE_H_
/**************************************************************************************************************/
/*                                Public Macros                                                               */
/**************************************************************************************************************/

/* Note That Both Motors Are Having The Same Speed Since They Are Connected On The Same PIN(OC0) That Controls Their Speed */
#define PWM_SET 100

/*************************************************************************************************************/
/*                                Function Prototypes                                                        */
/*************************************************************************************************************/

/*************************************************************************************************************/
/*                                01- HMD_L298N_DirectionForward                                             */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Directing The motors towards forward direction .
 * @param Copy_u8Port : The input parameter to the function which indicates which port you are using (A,B,C,D)
 * @return void  
 */
/*************************************************************************************************************/

void HMD_L298N_DirectionForward(u8 Copy_u8Port);

/*************************************************************************************************************/
/*                                02- HMD_L298N_DirectionBackward                                            */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Directing The motors towards Backward direction .
 * @param Copy_u8Port : The input parameter to the function which indicates which port you are using (A,B,C,D)
 * @return void  
 */
/*************************************************************************************************************/

void HMD_L298N_DirectionBackWard(u8 Copy_u8Port);

/*************************************************************************************************************/
/*                                 03- HMD_L298N_DirectionRight                                              */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Directing The motors towards right direction .
 * @param Copy_u8Port : The input parameter to the function which indicates which port you are using (A,B,C,D)
 * @return void  
 */
/*************************************************************************************************************/

void HMD_L298N_DirectionLeft(u8 Copy_u8Port);

/*************************************************************************************************************/
/*                                04- HMD_L298N_DirectionLeft                                                */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Directing The motors towards left direction .
 * @param Copy_u8Port : The input parameter to the function which indicates which port you are using (A,B,C,D)
 * @return void  
 */
/*************************************************************************************************************/

void HMD_L298N_DirectionRight(u8 Copy_u8Port);

/*************************************************************************************************************/
/*                                 05- HMD_L298N_MotorStop                                                   */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Stoppage of motors
 * @param Copy_u8Port : The input parameter to the function which indicates which port you are using (A,B,C,D)
 * @return void  
 */
/*************************************************************************************************************/

void HMD_L298N_MotorStop(u8 Copy_u8Port);

#endif /* HMD_L298N_INTERFACE_H_ */
