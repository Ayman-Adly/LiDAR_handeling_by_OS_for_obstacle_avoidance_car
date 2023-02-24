/**
 * @file DIO_Program.c
 * @author Hisham Montaser 
 * @brief This is the DIO_Program.c file for function implementations . 
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 * @details This file has six function each function deal with each pin on ATMega32 either to be (Output, Input, High, Low).
 */
/****************************************************************************************************************/
/*Date                : 12 - 2 - 2023   (Date of implemeting)                                                   */
/* 01- DIO_voidSetPinDirection                                                                                  */
/* 02- DIO_voidSetPinValue                                                                                      */
/* 03- DIO_voidSetPortValue                                                                                     */
/* 04- DIO_voidSetPortDirection                                                                                 */
/* 05- DIO_u8GetPinValue                                                                                        */
/* 06- DIO_voidTogPinValue                                                                                      */
/****************************************************************************************************************/

/****************************************************************************************************************/
/*                                   Standard Types LIB                                                         */
/****************************************************************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Manipulation.h"
/****************************************************************************************************************/
/*                                   Lower Layer                                                                */
/****************************************************************************************************************/

/****************************************************************************************************************/
/*                                   Own Header                                                                 */
/****************************************************************************************************************/
#include "DIO_INTERFACE.h"
#include "DIO_PRIVATE.h"
/*************************************************************************************************************/
/*                                    Function Implementation                                                */
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
void DIO_voidSetPinDirection 	(u8 copy_u8Port ,u8 copy_u8Pin , u8 copy_u8Dir )
{
/*Checking on Port and Pins*/
	if((copy_u8Port <=PORTD)&&(copy_u8Pin<=7))
	{
		/*Checking if the direction is output*/
		if (copy_u8Dir==HIGH)
		{
			/*Swithc on the port*/
			switch (copy_u8Port)
			{
			/* Setting bit of choosen pin to determine direction according to each choosen port */
			case PORTA: SET_BIT( DDRA_REG , copy_u8Pin );break;
			case PORTB: SET_BIT( DDRB_REG , copy_u8Pin );break;
			case PORTC: SET_BIT( DDRC_REG , copy_u8Pin );break;
			case PORTD: SET_BIT( DDRD_REG , copy_u8Pin );break;
			}
		}
		/*if direction is Input*/
		else if (copy_u8Dir==LOW)
		{
			switch (copy_u8Port)
			{
			/* Setting bit of choosen pin to determine direction according to each choosen port */
			case PORTA: CLR_BIT( DDRA_REG , copy_u8Pin );break;
			case PORTB: CLR_BIT( DDRB_REG , copy_u8Pin );break;
			case PORTC: CLR_BIT( DDRC_REG , copy_u8Pin );break;
			case PORTD: CLR_BIT( DDRD_REG , copy_u8Pin );break;
			}
		}
		else
		{
			//return error
		}
	}
}
/*************************************************************************************************************/
/*                                               02- DIO_voidSetPinValue                                     */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for setting pin value . 
 * @param  copy_u8Port 		--> Choosing Port (A,B,C,D) on ATMega32 .
 * @param  copy_u8Pin  		--> Choosing Pin (0, 1, 2, 3, 4, 5, 6, 7) on ATMega32 .
 * @param  copy_u8value 	--> Choosing Pin value (HIGH, LOW).
 * @return void  
 */
/*************************************************************************************************************/
void DIO_voidSetPinValue  (u8 copy_u8Port ,u8 copy_u8Pin , u8 copy_u8value )
{
/*Checking on Port and Pins*/
	if((copy_u8Port <=PORTD)&&(copy_u8Pin<=7))
	{
		/*Checking if the value is high*/
		if (copy_u8value==HIGH)
		{
			/*switch on the choosen on board*/
			switch (copy_u8Port)
			{
			/*Setting bit on register and choose the pin to determine it's value as high*/
			case PORTA: SET_BIT( PORTA_REG , copy_u8Pin );break;
			case PORTB: SET_BIT( PORTB_REG , copy_u8Pin );break;
			case PORTC: SET_BIT( PORTC_REG , copy_u8Pin );break;
			case PORTD: SET_BIT( PORTD_REG , copy_u8Pin );break;
			}
		}
		/*Check if value is low*/
		else if (copy_u8value==LOW)
		{
			switch (copy_u8Port)
			{
			/*Setting bit on register and choose the pin to determine it's value as low*/
			case PORTA: CLR_BIT( PORTA_REG , copy_u8Pin );break;
			case PORTB: CLR_BIT( PORTB_REG , copy_u8Pin );break;
			case PORTC: CLR_BIT( PORTC_REG , copy_u8Pin );break;
			case PORTD: CLR_BIT( PORTD_REG , copy_u8Pin );break;
			}
		}
		else
		{
			//return error
		}
	}
}
/*************************************************************************************************************/
/*                                               03- DIO_voidSetPortValue                                    */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for setting Port value . 
 * @param  copy_u8Port 		--> Choosing Port (A,B,C,D) on ATMega32 .
 * @param  copy_u8value  	--> Choosing Pin value (HIGH, LOW).
 * @return void  
 */
/*************************************************************************************************************/
void DIO_voidSetPortValue  	(u8 copy_u8Port , u8 copy_u8value )
{

/*Checking on Port*/
	if(copy_u8Port <=PORTD)
	{
				/*Switching on choosen port*/
				switch (copy_u8Port)
				{
				/*Set the whole port value according to your choice*/
				case PORTA: PORTA_REG=copy_u8value;break;
				case PORTB: PORTB_REG=copy_u8value;break;
				case PORTC: PORTC_REG=copy_u8value;break;
				case PORTD: PORTD_REG=copy_u8value;break;
				}
		}
		else
		{
			//return error
		}

}
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
void DIO_voidSetPortDirection  (u8 copy_u8Port , u8 copy_u8Dir )
{
/*Checking on Port*/
	if(copy_u8Port <=PORTD)
	{
			/*Switching on choosen port*/
			switch (copy_u8Port)
			{
			/*Set the whole port direction according to your choice*/
			case PORTA: DDRA_REG=copy_u8Dir;break;
			case PORTB: DDRB_REG=copy_u8Dir;break;
			case PORTC: DDRC_REG=copy_u8Dir;break;
			case PORTD: DDRD_REG=PORT_OUT;break;

			}
		}
	else
	{
		//return error
	}

}
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
u8   DIO_u8GetPinValue   (u8 copy_u8Port ,u8 copy_u8Pin  )
{
/*Dyanmice variable*/
	u8 loc_u8Value ;
/*Checking on Port and Pins*/
	if((copy_u8Port <=PORTD)&&(copy_u8Pin<=7))
	{
		/*Switching on choosen port*/
		switch (copy_u8Port)
		{
		/*Get the pin value according to each port given*/
		case PORTA: loc_u8Value=GET_BIT(PINA_REG,copy_u8Pin);break;
		case PORTB: loc_u8Value=GET_BIT(PINB_REG,copy_u8Pin);break;
		case PORTC: loc_u8Value=GET_BIT(PINC_REG,copy_u8Pin);break;
		case PORTD: loc_u8Value=GET_BIT(PIND_REG,copy_u8Pin);break;
		}
	}
return loc_u8Value;
}


