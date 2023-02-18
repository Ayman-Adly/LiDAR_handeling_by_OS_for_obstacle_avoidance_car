/*
 * LCD_prog.c
 *
 *  Created on: 25 Nov 2022
 *      Author: nour
 */
/*      LIB           */
#include "../../LIB/STD_Types.h"
#include "../../LIB/Bitmath.h"

/*        DIO        */
#include "../../MCAL/DIO/DIO_Interface.h"


/*        LCD         */
#include "LCD_config.h"
#include "LCD_Priv.h"
#include "LCD_Interface.h"


#include "avr/delay.h"

void LCD_vidInit(void)
{

	DIO_vidSetPortDir(LCD_DATA_PORT,PORT_OUTPUT); //in main
	DIO_vidSetPinDir(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_OUTPUT); //RS   //in main
	DIO_vidSetPinDir(LCD_CONTROL_PORT,LCD_E_PIN,DIO_OUTPUT); //ENABLE   //in main

	_delay_ms(100);
	LCD_vidSendCmd(LCD_FUNCSET_8BIT);
	_delay_ms(2);
	LCD_vidSendCmd(LCD_DISPLAY_ON_CURSOR_OFF);
	_delay_ms(2);
	LCD_vidSendCmd(LCD_CLR);
	_delay_ms(2);
	LCD_vidSendCmd(LCD_ENTRY_MODE);




}
void LCD_vidSendCmd(u8 command)
{
	 DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);   //RS low
	 DIO_vidSetPortVal(LCD_DATA_PORT,command); //COMMAND

	 //ENABLE
	 DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
		_delay_ms(1);
	 DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
}
void LCD_vidSendChar(u8 character)
{
	 DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);   //RS low
		 DIO_vidSetPortVal(LCD_DATA_PORT,character); //COMMAND

		 //ENABLE
		 DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
			_delay_ms(1);
		 DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);
}
void LCD_vidSendString(u8 * ptr_to_arr_ofchar)
{

	u8 counter=0;
	while(ptr_to_arr_ofchar[counter]!='\0')
		{
		LCD_vidSendChar(ptr_to_arr_ofchar[counter]);
		counter++;
		}

}
void LCD_vidGoToXY(u8 x , u8 y)
{
	u8 DDRAM_Address;
	switch(x)
	{
	case 0:
		DDRAM_Address=0X80;                        //0b10000000   the bit number 8 is always 1 and followed by address
		break;
	case 1:
		DDRAM_Address= 0XC0;                       //0b11000000
		break;
	}
	DDRAM_Address=DDRAM_Address+y;
	LCD_vidSendCmd(DDRAM_Address);
}
void LCD_vidCGRAMAccess()
{
	LCD_vidSendCmd(0b01000000);
	//printing m
			LCD_vidSendChar(0b00111);
			LCD_vidSendChar(0b00101);
			LCD_vidSendChar(0b11111);
			LCD_vidSendChar(0b00000);
			LCD_vidSendChar(0b00000);
			LCD_vidSendChar(0b00000);
			LCD_vidSendChar(0b00000);
			LCD_vidSendChar(0b00000);
		//printing o
			LCD_vidSendChar(0b00111);
			LCD_vidSendChar(0b00101);
			LCD_vidSendChar(0b00111);
			LCD_vidSendChar(0b00001);
			LCD_vidSendChar(0b00001);
			LCD_vidSendChar(0b00111);
			LCD_vidSendChar(0b00000);
			LCD_vidSendChar(0b00000);
//printing n
			LCD_vidSendChar(0b00100);
			LCD_vidSendChar(0b10001);
			LCD_vidSendChar(0b10001);
			LCD_vidSendChar(0b01110);
			LCD_vidSendChar(0b00000);
			LCD_vidSendChar(0b00000);
			LCD_vidSendChar(0b00000);
			LCD_vidSendChar(0b00000);

//printing a
			LCD_vidSendChar(0b00100);
			LCD_vidSendChar(0b01000);
			LCD_vidSendChar(0b11100);
			LCD_vidSendChar(0b00000);
			LCD_vidSendChar(0b00000);
			LCD_vidSendChar(0b00000);
			LCD_vidSendChar(0b00000);
			LCD_vidSendChar(0b00000);
}


void LCD_vidPrintInit(u16 integer_value , u8 x ,u8 y)
{


	if(integer_value<0){LCD_vidGoToXY(x, y); LCD_vidSendChar('-'); integer_value=(-1*integer_value); y++;}

	if (integer_value > 9	&& integer_value<99)
	{
		u8 result[2];
		result[0]=integer_value/10;
		integer_value=integer_value-(result[0]*10);
		result[1]=integer_value;
		//turn into ASCII
		for(int j=0;j<2;j++)
		{
		result[j]=result[j]+48;

		}

		LCD_vidGoToXY(x, y);
		LCD_vidSendString(result);

	}
	else if(integer_value > 99	&& integer_value<1000)
	{
			LCD_vidGoToXY(x, y);
			u8 result[3];
			result[0]=integer_value/100;
			integer_value=integer_value-(result[0]*100);
			result[1]=integer_value/10;
			integer_value=integer_value-(result[1]*10);
			result[2]=integer_value;
			//turn into ASCII
			for(int j=0;j<3;j++)
			{
			result[j]=result[j]+48;

			}


			LCD_vidGoToXY(x, y);
			LCD_vidSendString(result);

	}
	else if(integer_value<=9)
	{

		LCD_vidGoToXY(x, y);
		LCD_vidSendChar(integer_value+48);
	}

}





void LCD_vidClearDisplay(void)
{
	LCD_vidSendCmd(LCD_CLR);
}



