/**
 * @file HMD_L298N_Program.c
 * @author Hisham Montaser 
 * @brief This is the HMD_L298N_Program.c file for function implementations . 
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

/****************************************************************************************************************/
/*                                Standard Types LIB                                                            */
/****************************************************************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Manipulation.h"
/****************************************************************************************************************/
/*                                Lower Layer -------> (MCAL)                                                   */
/****************************************************************************************************************/
#include "../../MCAL/DIO/DIO_PRIVATE.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
/****************************************************************************************************************/
/*                                Own Header -------> (HAL)                                                     */
/****************************************************************************************************************/
#include "HMD_L298N_Config.h"
#include "HMD_L298N_Interface.h"
/*****************************************************************************************************************/
/*                                Function Implementation                                                        */
/*****************************************************************************************************************/

/*************************************************************************************************************/
/*                                01- HMD_L298N_DirectionForward                                             */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Directing The motors towards forward direction .
 * @param Copy_u8Port : The input parameter to the function which indicates which port you are using (A,B,C,D)
 * @return void  
 */
/*************************************************************************************************************/
void HMD_L298N_DirectionForward(u8 Copy_u8Port)
{
	/*Checking on the ports sent if its greater than D and less than A*/
	if( (Copy_u8Port <= PORTD) && (Copy_u8Port >= PORTA) )
	{
	/*Switch on the giver port*/
	switch(Copy_u8Port)
	{
				 /*Set Pin of Input_1MA as high*/
	case PORTA : DIO_voidSetPinValue(PORTA , Input_1MA , HIGH);
				 /*Set Pin of Input_2MA as low*/
				 DIO_voidSetPinValue(PORTA , Input_2MA , LOW);
				 /*Set Pin of Input_3MB as high*/
				 DIO_voidSetPinValue(PORTA , Input_3MB , HIGH);
				 /*Set pin of Input_4MB as low*/
				 DIO_voidSetPinValue(PORTA , Input_4MB , LOW);
				 break;

				 /*Set Pin of Input_1MA as high*/
	case PORTB : DIO_voidSetPinValue(PORTB , Input_1MA , HIGH);
				 /*Set Pin of Input_2MA as low*/
				 DIO_voidSetPinValue(PORTB , Input_2MA , LOW);
				 /*Set Pin of Input_3MB as high*/
				 DIO_voidSetPinValue(PORTB , Input_3MB , HIGH);
				 /*Set pin of Input_4MB as low*/
				 DIO_voidSetPinValue(PORTB , Input_4MB , LOW);
				 break;

				/*Set Pin of Input_1MA as high*/
	case PORTC : DIO_voidSetPinValue(PORTC , Input_1MA , HIGH);
				/*Set Pin of Input_2MA as low*/
				 DIO_voidSetPinValue(PORTC , Input_2MA , LOW);
				 /*Set Pin of Input_3MB as high*/
				 DIO_voidSetPinValue(PORTC , Input_3MB , HIGH);
				 /*Set pin of Input_4MB as low*/
				 DIO_voidSetPinValue(PORTC , Input_4MB , LOW);
				 break;

				 /*Set Pin of Input_1MA as high*/
	case PORTD : DIO_voidSetPinValue(PORTD , Input_1MA , HIGH);
				 /*Set Pin of Input_2MA as low*/
				 DIO_voidSetPinValue(PORTD , Input_2MA , LOW);
				 /*Set Pin of Input_3MB as high*/
				 DIO_voidSetPinValue(PORTD , Input_3MB , HIGH);
				/*Set pin of Input_4MB as low*/
				 DIO_voidSetPinValue(PORTD , Input_4MB , LOW);
				 break;
	}

	}
}

/*************************************************************************************************************/
/*                                 02- HMD_L298N_DirectionBackward                                           */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Directing The motors towards Backward direction .
 * @param Copy_u8Port : The input parameter to the function which indicates which port you are using (A,B,C,D)
 * @return void  
 */
/*************************************************************************************************************/

void HMD_L298N_DirectionBackWard(u8 Copy_u8Port)
{
	/*Checking on the ports sent if its greater than D and less than A*/
	if( (Copy_u8Port <= PORTD) && (Copy_u8Port >= PORTA) )
	{
	/*Switch on the giver port*/
	switch(Copy_u8Port)
	{
				 /*Sending pin value of Input_1MA as low*/
	case PORTA : DIO_voidSetPinValue(PORTA , Input_1MA , LOW);
				 /*Sending pin value of Input_2MA as high*/
				 DIO_voidSetPinValue(PORTA , Input_2MA , HIGH);
				 /*Sending pin value of Input_3MB as low*/
				 DIO_voidSetPinValue(PORTA , Input_3MB , LOW);
				 /*Sending pin value of Input_4MB as high*/
				 DIO_voidSetPinValue(PORTA , Input_4MB , HIGH);
				 break;
				 /*Sending pin value of Input_1MA as low*/
	case PORTB : DIO_voidSetPinValue(PORTB , Input_1MA , LOW);
				 /*Sending pin value of Input_2MA as high*/
				 DIO_voidSetPinValue(PORTB , Input_2MA , HIGH);
				 /*Sending pin value of Input_3MB as low*/
				 DIO_voidSetPinValue(PORTB , Input_3MB , LOW);
				 /*Sending pin value of Input_4MB as high*/
				 DIO_voidSetPinValue(PORTB , Input_4MB , HIGH);
				 break;

				 /*Sending pin value of Input_1MA as low*/
	case PORTC : DIO_voidSetPinValue(PORTC , Input_1MA , LOW);
				 /*Sending pin value of Input_2MA as high*/
				 DIO_voidSetPinValue(PORTC , Input_2MA , HIGH);
				 /*Sending pin value of Input_3MB as low*/
				 DIO_voidSetPinValue(PORTC , Input_3MB , LOW);
				 /*Sending pin value of Input_4MB as high*/
				 DIO_voidSetPinValue(PORTC , Input_4MB , HIGH);
				 break;

				 /*Sending pin value of Input_1MA as low*/
	case PORTD : DIO_voidSetPinValue(PORTD , Input_1MA , LOW);
	             /*Sending pin value of Input_2MA as high*/
				 DIO_voidSetPinValue(PORTD , Input_2MA , HIGH);
				 /*Sending pin value of Input_3MB as low*/
				 DIO_voidSetPinValue(PORTD , Input_3MB , LOW);
				 /*Sending pin value of Input_4MB as high*/
				 DIO_voidSetPinValue(PORTD , Input_4MB , HIGH);
				 break;
	}

	}

}

/*************************************************************************************************************/
/*                                 03- HMD_L298N_DirectionRight                                              */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Directing The motors towards right direction .
 * @param Copy_u8Port : The input parameter to the function which indicates which port you are using (A,B,C,D)
 * @return void  
 */
/*************************************************************************************************************/

void HMD_L298N_DirectionLeft(u8 Copy_u8Port)
{
    /*Checking on the ports sent if its greater than D and less than A*/
	if( (Copy_u8Port <= PORTD) && (Copy_u8Port >= PORTA) )
	{
	/*Switch on the giver port*/
	switch(Copy_u8Port)
	{
				 /*Sending pin value of Input_1MA as high*/
	case PORTA : DIO_voidSetPinValue(PORTA , Input_1MA , HIGH);
				 /*Sending pin value of Input_2MA as low */
				 DIO_voidSetPinValue(PORTA , Input_2MA , LOW);
				 /*Sending pin value of Input_3MB as low */
				 DIO_voidSetPinValue(PORTA , Input_3MB , LOW);
				 /*Sending pin value of Input_4MA as low */
				 DIO_voidSetPinValue(PORTA , Input_4MB , LOW);
				 break;

				/*Sending pin value of Input_1MA as high*/
	case PORTB : DIO_voidSetPinValue(PORTB , Input_1MA , HIGH);
	            /*Sending pin value of Input_2MA as low */
				 DIO_voidSetPinValue(PORTB , Input_2MA , LOW);
				/*Sending pin value of Input_3MB as low */
				 DIO_voidSetPinValue(PORTB , Input_3MB , LOW);
				/*Sending pin value of Input_4MA as low */
				 DIO_voidSetPinValue(PORTB , Input_4MB , LOW);
				 break;

				/*Sending pin value of Input_1MA as high*/
	case PORTC : DIO_voidSetPinValue(PORTC , Input_1MA , HIGH);
				/*Sending pin value of Input_2MA as low */
				 DIO_voidSetPinValue(PORTC , Input_2MA , LOW);
				 /*Sending pin value of Input_3MB as low */
				 DIO_voidSetPinValue(PORTC , Input_3MB , LOW);
				 /*Sending pin value of Input_4MA as low */
				 DIO_voidSetPinValue(PORTC , Input_4MB , LOW);
				 break;

				/*Sending pin value of Input_1MA as high*/
	case PORTD : DIO_voidSetPinValue(PORTD , Input_1MA , HIGH);
				/*Sending pin value of Input_2MA as low */
				 DIO_voidSetPinValue(PORTD , Input_2MA , LOW);
				/*Sending pin value of Input_3MB as low */
				 DIO_voidSetPinValue(PORTD , Input_3MB , LOW);
				/*Sending pin value of Input_4MA as low */
				 DIO_voidSetPinValue(PORTD , Input_4MB , LOW);
				 break;
	}

	}

}

/*************************************************************************************************************/
/*                                04- HMD_L298N_DirectionLeft                                                */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Directing The motors towards left direction .
 * @param Copy_u8Port : The input parameter to the function which indicates which port you are using (A,B,C,D)
 * @return void  
 */
/*************************************************************************************************************/

void HMD_L298N_DirectionRight(u8 Copy_u8Port)
{
/*Checking on the ports sent if its greater than D and less than A*/
	if( (Copy_u8Port <= PORTD) && (Copy_u8Port >= PORTA) )
	{
	/*Switch on the giver port*/
	switch(Copy_u8Port)
	{
		        /*Sending pin value of Input_1MA as low*/
	case PORTA : DIO_voidSetPinValue(PORTA , Input_1MA , LOW);
				/*Sending pin value of Input_2MA as low*/
				 DIO_voidSetPinValue(PORTA , Input_2MA , LOW);
				/*Sending pin value of Input_3MB as high*/
				 DIO_voidSetPinValue(PORTA , Input_3MB , HIGH);
				/*Sending pin value of Input_4MB as low*/
				 DIO_voidSetPinValue(PORTA , Input_4MB , LOW);
				 break;
				/*Sending pin value of Input_1MA as low*/
	case PORTB : DIO_voidSetPinValue(PORTB , Input_1MA , LOW);
				/*Sending pin value of Input_2MA as low*/
				 DIO_voidSetPinValue(PORTB , Input_2MA , LOW);
				/*Sending pin value of Input_3MB as high*/
				 DIO_voidSetPinValue(PORTB , Input_3MB , HIGH);
				/*Sending pin value of Input_4MB as low*/
				 DIO_voidSetPinValue(PORTB , Input_4MB , LOW);
				 break;
				/*Sending pin value of Input_1MA as low*/
	case PORTC : DIO_voidSetPinValue(PORTC , Input_1MA , LOW);
				/*Sending pin value of Input_2MA as low*/
				 DIO_voidSetPinValue(PORTC , Input_2MA , LOW);
				/*Sending pin value of Input_3MB as high*/
				 DIO_voidSetPinValue(PORTC , Input_3MB , HIGH);
				/*Sending pin value of Input_4MB as low*/
				 DIO_voidSetPinValue(PORTC , Input_4MB , LOW);
				 break;
				/*Sending pin value of Input_1MA as low*/
	case PORTD : DIO_voidSetPinValue(PORTD , Input_1MA , LOW);
				/*Sending pin value of Input_2MA as low*/
				 DIO_voidSetPinValue(PORTD , Input_2MA , LOW);
				/*Sending pin value of Input_3MB as high*/
				 DIO_voidSetPinValue(PORTD , Input_3MB , HIGH);
				/*Sending pin value of Input_4MB as low*/
				 DIO_voidSetPinValue(PORTD , Input_4MB , LOW);
				 break;
	}

	}

}

/*************************************************************************************************************/
/*                                 05- HMD_L298N_MotorStop                                                   */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Stoppage of motors
 * @param Copy_u8Port : The input parameter to the function which indicates which port you are using (A,B,C,D)
 * @return void  
 */
/*************************************************************************************************************/

void HMD_L298N_MotorStop(u8 Copy_u8Port)
{
/*Checking on the ports sent if its greater than D and less than A*/
	if( (Copy_u8Port <= PORTD) && (Copy_u8Port >= PORTA) )
	{
	/*Switch on the giver port*/
	switch(Copy_u8Port)
	{
		        
	case PORTA :/*Sending pin value of Input_1MA as low*/
			     DIO_voidSetPinValue(PORTA , Input_1MA , LOW);
				/*Sending pin value of Input_2MA as low*/
			     DIO_voidSetPinValue(PORTA , Input_2MA , LOW);
				/*Sending pin value of Input_3MA as low*/
			     DIO_voidSetPinValue(PORTA , Input_3MB , LOW);
				/*Sending pin value of Input_4MA as low*/
			     DIO_voidSetPinValue(PORTA , Input_4MB , LOW);
				 break;

	case PORTB :/*Sending pin value of Input_1MA as low*/
				 DIO_voidSetPinValue(PORTB , Input_1MA , LOW);
				/*Sending pin value of Input_2MA as low*/
				 DIO_voidSetPinValue(PORTB , Input_2MA , LOW);
				/*Sending pin value of Input_3MA as low*/
				 DIO_voidSetPinValue(PORTB , Input_3MB , LOW);
				/*Sending pin value of Input_4MA as low*/
				 DIO_voidSetPinValue(PORTB , Input_4MB , LOW);
				 break;

	case PORTC :/*Sending pin value of Input_1MA as low*/
				 DIO_voidSetPinValue(PORTC , Input_1MA , LOW);
				/*Sending pin value of Input_2MA as low*/
				 DIO_voidSetPinValue(PORTC , Input_2MA , LOW);
				/*Sending pin value of Input_3MA as low*/
				 DIO_voidSetPinValue(PORTC , Input_3MB , LOW);
				/*Sending pin value of Input_4MA as low*/
				 DIO_voidSetPinValue(PORTC , Input_4MB , LOW);
				 break;

	case PORTD :/*Sending pin value of Input_1MA as low*/
				 DIO_voidSetPinValue(PORTD , Input_1MA , LOW);
				/*Sending pin value of Input_2MA as low*/
				 DIO_voidSetPinValue(PORTD , Input_2MA , LOW);
				/*Sending pin value of Input_3MA as low*/
				 DIO_voidSetPinValue(PORTD , Input_3MB , LOW);
				/*Sending pin value of Input_4MA as low*/
				 DIO_voidSetPinValue(PORTD , Input_4MB , LOW);
				 break;
	}

	}

}


