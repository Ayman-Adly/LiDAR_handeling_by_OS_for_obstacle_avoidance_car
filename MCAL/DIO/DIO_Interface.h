/**
 * @file DIO_Interface.h
 * @author Hisham Montaser 
 * @brief This is the DIO_Interface.h file for function implementations . 
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 * @details This file has five function each function deal with each pin on ATMega32 either to be (Output, Input, High, Low).
 */
/****************************************************************************************************************/
/*Date                : 12 - 2 - 2023   (Date of implemeting)                                                   */
/* 01- DIO_voidSetPinDirection                                                                                  */
/* 02- DIO_voidSetPinValue                                                                                      */
/* 03- DIO_voidSetPortValue                                                                                     */
/* 04- DIO_voidSetPortDirection                                                                                 */
/* 05- DIO_u8GetPinValue                                                                                        */
/****************************************************************************************************************/

/**************************************************************************************************************/
/*                          HeaderGuard : Prevent Multiple calls of Interface.h header file                   */
/**************************************************************************************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*************************************************************************************************************/
/*                                              Function Prototypes                                          */
/*************************************************************************************************************/

/*************************************************************************************************************/
/*                                               01- DIO_voidSetPinDirection                                 */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for setting pin direction . 
 * @param  copy_u8Port --> Choosing Port (A,B,C,D) on ATMega32 .
 * @param  copy_u8Pin  --> Choosing Pin (0, 1, 2, 3, 4, 5, 6, 7) on ATMega32 .
 * @param  copy_u8Dir  --> Choosing Pin direction (OUTPUT, INPUT).
 * @return void  
 */
/*************************************************************************************************************/
void DIO_voidSetPinDirection 	(u8 copy_u8Port ,u8 copy_u8Pin , u8 copy_u8Dir );
/*************************************************************************************************************/
/*                                               02- DIO_voidSetPinValue                                     */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for setting pin value . 
 * @param  copy_u8Port --> Choosing Port (A,B,C,D) on ATMega32 .
 * @param  copy_u8Pin  --> Choosing Pin (0, 1, 2, 3, 4, 5, 6, 7) on ATMega32 .
 * @param  copy_u8value  --> Choosing Pin value (HIGH, LOW).
 * @return void  
 */
/*************************************************************************************************************/
void DIO_voidSetPinValue  	    (u8 copy_u8Port ,u8 copy_u8Pin , u8 copy_u8value );
/*************************************************************************************************************/
/*                                               03- DIO_voidSetPortValue                                    */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for setting Port value . 
 * @param  copy_u8Port --> Choosing Port (A,B,C,D) on ATMega32 .
 * @param  copy_u8value  --> Choosing Pin value (HIGH, LOW).
 * @return void  
 */
/*************************************************************************************************************/
void DIO_voidSetPortValue  	    (u8 copy_u8Port , u8 copy_u8value );
/*************************************************************************************************************/
/*                                               04- DIO_voidSetPortDirection                                */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for setting Port value . 
 * @param  copy_u8Port --> Choosing Port (A,B,C,D) on ATMega32 .
 * @param  copy_u8Dir  --> Choosing Port direction (OUTPUT, INPUT).
 * @return void  
 */
/*************************************************************************************************************/
void DIO_voidSetPortDirection  (u8 copy_u8Port , u8 copy_u8Dir );
/*************************************************************************************************************/
/*                                               05- DIO_u8GetPinValue                                       */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for getting pin value . 
 * @param  copy_u8Port --> Choosing Port (A,B,C,D) on ATMega32 .
 * @param  copy_u8pin  --> Choosing Pin (0, 1, 2, 3, 4, 5, 6, 7) on ATMega32 .
 * @return u8  
 */
/*************************************************************************************************************/
u8   DIO_u8GetPinValue          (u8 copy_u8Port ,u8 copy_u8Pin  );
/*************************************************************************************************************/
/*                              Public Macros                                                                */
/*************************************************************************************************************/

/***************************/
#define		PORTA 		0
#define		PORTB 		1
#define		PORTC		2
#define     PORTD		3
/**************************/
#define		PIN0        0
#define		PIN1        1
#define		PIN2        2
#define		PIN3        3
#define		PIN4        4
#define		PIN5        5
#define		PIN6        6
#define		PIN7        7
/**************************/
#define Input_1MA  PIN0
#define Input_2MA  PIN1
#define Input_3MB  PIN2
#define Input_4MB  PIN7
/*************************/
#define HIGH 		1
#define LOW  		0
#define OUTPUT      1
#define INPUT       0
#define PORT_OUT    0xff
#define PORT_HIGH   0xff
/*************************/



#endif /* DIO_INTERFACE_H_ */
