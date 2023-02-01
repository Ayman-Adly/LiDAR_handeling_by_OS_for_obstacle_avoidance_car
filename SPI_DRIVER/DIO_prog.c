/*
 * DIO_prog.c
 *
 *  Created on: 18 Nov 2022
 *      Author: Ayman El-Tanboly
 */

#include "types.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_priv.h"

void DIO_vidSetPinVal(u8 PortId, u8 PinId, u8 val)
{
	//check the entered value is within valid range
	if(PortId <= DIO_PORTD && PinId <= DIO_PIN7)
	{
		if (val == DIO_LOW)
		{
			switch(PortId)
			{
			case DIO_PORTA: CLR_BIT(PORTA_REG,PinId); break;
			case DIO_PORTB: CLR_BIT(PORTB_REG,PinId); break;
			case DIO_PORTC: CLR_BIT(PORTC_REG,PinId); break;
			case DIO_PORTD: CLR_BIT(PORTD_REG,PinId); break;
			}
		}
		else if(val == DIO_HIGH)
		{
			switch(PortId)
			{
			case DIO_PORTA: SET_BIT(PORTA_REG,PinId); break;
			case DIO_PORTB: SET_BIT(PORTB_REG,PinId); break;
			case DIO_PORTC: SET_BIT(PORTC_REG,PinId); break;
			case DIO_PORTD: SET_BIT(PORTD_REG,PinId); break;
			}
		}
		else
		{
			//report error
		}
	}
	else
	{
		//report error
	}
}


void DIO_vidSetPinDir(u8 PortId, u8 PinId, u8 dir)
{

	//check the entered value is within valid range
	if(PortId <= DIO_PORTD && PinId <= DIO_PIN7)
	{
		if (dir == DIO_INPUT)
		{
			switch(PortId)
			{
			case DIO_PORTA: CLR_BIT(DDRA_REG,PinId); break;
			case DIO_PORTB: CLR_BIT(DDRB_REG,PinId); break;
			case DIO_PORTC: CLR_BIT(DDRC_REG,PinId); break;
			case DIO_PORTD: CLR_BIT(DDRD_REG,PinId); break;
			}
		}
		else if(dir == DIO_OUTPUT)
		{
			switch(PortId)
			{
			case DIO_PORTA: SET_BIT(DDRA_REG,PinId); break;
			case DIO_PORTB: SET_BIT(DDRB_REG,PinId); break;
			case DIO_PORTC: SET_BIT(DDRC_REG,PinId); break;
			case DIO_PORTD: SET_BIT(DDRD_REG,PinId); break;
			}
		}
		else
		{
			//report error
		}
	}
	else
	{
		//report error
	}
}

void DIO_vidSetPortVal(u8 PortId, u8 val)
{
	if(PortId <= DIO_PORTD)
	{
		switch(PortId)
		{
		case DIO_PORTA: PORTA_REG=val; break;
		case DIO_PORTB: PORTB_REG=val; break;
		case DIO_PORTC: PORTC_REG=val; break;
		case DIO_PORTD: PORTD_REG=val; break;
		}
	}
	else
	{
		//report error
	}
}

void DIO_vidSetPortDir(u8 PortId, u8 dir)
{
	if(PortId <= DIO_PORTD)
		{
			switch(PortId)
			{
			case DIO_PORTA: DDRA_REG=dir; break;
			case DIO_PORTB: DDRB_REG=dir; break;
			case DIO_PORTC: DDRC_REG=dir; break;
			case DIO_PORTD: DDRD_REG=dir; break;
			}
		}
		else
		{
			//report error
		}
}

u8 DIO_u8GetPinVal(u8 PortId, u8 PinId)
{
	u8 ret_val;
	if(PortId <= DIO_PORTD && PinId <= DIO_PIN7)
	{
		switch(PortId)
		{
		case DIO_PORTA: ret_val=GET_BIT(PINA_REG, PinId); break;
		case DIO_PORTB: ret_val=GET_BIT(PINB_REG, PinId); break;
		case DIO_PORTC: ret_val=GET_BIT(PINC_REG, PinId); break;
		case DIO_PORTD: ret_val=GET_BIT(PIND_REG, PinId); break;
		}
	}
	else
	{
		//report error
	}
	return ret_val;
}
