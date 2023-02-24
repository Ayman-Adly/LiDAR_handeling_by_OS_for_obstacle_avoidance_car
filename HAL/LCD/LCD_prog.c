/**
 * @file LCD_Program.c
 * @author Hisham Montaser 
 * @brief This is the LCD_Program.c file for function Implementation . 
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 * @details This file has seven functions each function give you access to a feature on the LCD .
 */
/****************************************************************************************************************/
/*Date                : 12 - 2 - 2023   (Date of implemeting)                                                   */
/* 01- LCD_vidInit                                                                                              */
/* 02- LCD_vidSendCommand                                                                                       */
/* 03- LCD_vidSendChar                                                                                          */
/* 04- LCD_vidSendString                                                                                        */
/* 05- LCD_vidGetPosition                                                                                       */
/* 06- LCD_vidCustomChar                                                                                        */
/* 07- LCD_vidDisplayCustomChar                                                                                 */
/* 08- LCD_vidSendNum                                                                                           */
/****************************************************************************************************************/

/**************************************************************************************************************/
/*                          HeaderGuard : Prevent Multiple calls of Interface.h header file                   */
/**************************************************************************************************************/

/****************************************************************************************************************/

/****************************************************************************************************************/
/*                                   Standard Types LIB                                                         */
/****************************************************************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Manipulation.h"
#include <util/delay.h>
/****************************************************************************************************************/
/*                                   Lower Layer                                                                */
/****************************************************************************************************************/
#include"../../MCAL/DIO/DIO_INTERFACE.h"
/****************************************************************************************************************/
/*                                   Own Header                                                                 */
/****************************************************************************************************************/
#include"LCD_interface.h"
#include"LCD_conf.h"
/*************************************************************************************************************/
/*                                               01- LCD_vidInit                                             */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For LCD initialization . 
 * @param  No_Input_Parameters : void  
 * @return void  
 */
/*************************************************************************************************************/
void LCD_vidInit(void)
{
	/*Waiting 40ms delay*/
	_delay_ms(40);
	/*sending command of 8-bit mode*/
	LCD_vidSendCommand(LCD_FUNCSET_8BIT);
	/*waiting 2ms delay*/
	_delay_ms(2);
	/*sending command for Display curson on*/
	LCD_vidSendCommand(LCD_DISPON_CURSON);
	/*waiting 2ms delay*/
	_delay_ms(2);
	/*sending command LCD clear*/
	LCD_vidSendCommand(LCD_CLR);
	/*waiting 2ms delay*/
	_delay_ms(2);
	/*Sending command LCD entry mode*/
	LCD_vidSendCommand(LCD_ENTRYMODE);
}
/*************************************************************************************************************/
/*                                               02- LCD_vidSendCommand                                      */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for sending command on LCD . 
 * @param  Copy_u8Cmd : Input parameter for sending a specific command on LCD   
 * @return void  
 */
/*************************************************************************************************************/

void LCD_vidSendCommand(u8 Copy_u8Cmd)
{
	//RS low
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, LOW);
	//RW low
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, LOW);
	//command
	DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Cmd);

	//enable
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, LOW);

}
/*************************************************************************************************************/
/*                                               03- LCD_vidSendChar                                         */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for sending character on LCD . 
 * @param  Copy_u8Char : Input parameter for sending a character on LCD   
 * @return void  
 */
/*************************************************************************************************************/
void LCD_vidSendChar(u8 Copy_u8Char)
{
	//RS high
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, HIGH);
	//RW low
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, LOW);
	//command
	DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Char);

	//enable
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, LOW);

}
/*************************************************************************************************************/
/*                                               04- LCD_vidSendString                                       */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for sending string on LCD . 
 * @param  Ptr : Pointer holding the first address of a character in a string .
 * @return void  
 */
/*************************************************************************************************************/
void LCD_vidWriteStr(u8* pu8str)
{
	/*Dynamice variables */
	u8 i = 0;
	u8 flag = 0;
	/*For loop for sending character's till we meet the null character that will terminate the loop*/
	for(i=0;i<16;i++)
	{
		/*if equal to null character terminate the loop*/
		if(*(pu8str+i) == '\0')
		{
			flag = 1;
			break;
		}
		else
		{
			/*Sending string on LCD*/
			LCD_vidSendChar(*(pu8str+i));
		}
	}
}
/*************************************************************************************************************/
/*                                               05- LCD_vidGetPosition                                      */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for setting the x-axis and y-axis position of LCD to start writing . 
 * @param  Row : Input parameter specifys which row to start from .
 * @param  Column : Input parameter specifys which column to start from .
 * @return void  
 */
/*************************************************************************************************************/
void LCD_vidGetPosition(u8 Row , u8  Col)
{
	/*Address of the character will be written*/
	u8 Address ;
	if(Row < 2 && Col <16)
	{
		/*Multiplying entry address with our row and add it to the column to get desired position*/
		Address = (0x40 * Row) + Col;
		SET_BIT(Address,7);
		/*Sending our desired position*/
		LCD_vidSendCommand(Address);
	}

}
/*************************************************************************************************************/
/*                                               06- LCD_vidCustomChar                                       */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for sending custom character on LCD  . 
 * @param  location : Input parameter specifys which location .
 * @param  ptr : Pointer holding the first address of a character in a string .
 * @return void  
 */
/*************************************************************************************************************/
void LCD_vidCustomChar(u8 location , u8 * ptr)
{
	/*Dynamic variables */
	u8 Address = 0 ;
	u8 i =0 ;
	/*Checking if the address less than 8*/
	if(Address<8){
		Address = (location * 8) ;
		SET_BIT(Address,6);
		/*Sending the address*/
		LCD_vidSendCommand(Address);
		/*Looping till we reach the end value of the array of the custom character*/
		for (i=0 ;i<8 ; i++)
		{
			LCD_vidSendChar(*(ptr+i));
			// Enable
			DIO_voidSetPinValue(PORTC, PIN7, HIGH);
			_delay_ms(1);
			DIO_voidSetPinValue(PORTC, PIN7, LOW);

		}
	}
	/*Sending command to return home*/
	LCD_vidSendCommand(LCD_HOME);
}
/*************************************************************************************************************/
/*                                               07- LCD_vidDisplayCustomChar                                */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for displaying custom character  . 
 * @param  location : Input parameter specifys which location .
 * @param  Row : Input parameter specifys which row to start from .
 * @param  Column : Input parameter specifys which column to start from .
 * @return void  
 */
/*************************************************************************************************************/
void LCD_vidDisplayCustomChar( u8 location , u8 Row , u8 Column)
{
	/*Getting the position you want to write in*/
	LCD_vidGetPosition(Row,Column);
	/*Sending the custom character*/
	LCD_vidSendChar(location);

}
/*************************************************************************************************************/
/*                                               08- LCD_SendNum                                             */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for send number  .
 * @param  u8num : Sending your desired number .
 * @return void
 */
/*************************************************************************************************************/
void LCD_vidSendNum(u8 u8num)
{
	/*Checking if number equal to zero*/
	if(u8num == 0)
	{
		/*Sending character zero */
		LCD_vidSendChar('0');
	}
	/*if number greater than 0*/
	else if(u8num > 0)
	{
		/*Dyanmice variables*/
		s8 i = 0;
		u8 Rem  = 0;
		u8 arr[10] = {0};
		while(u8num != 0)
		{
			/*Calculating reminder*/
			Rem = u8num %10;
			arr[i] = Rem;
			i++;
			u8num /= 10;
		}
		i--;
		while(i >= 0)
		{
			/*Sending the number in the form of character to be displayed*/
			LCD_vidSendChar(arr[i] + 48);
			i--;
		}
	}
}














