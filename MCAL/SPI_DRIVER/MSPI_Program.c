/*
 * MSPI_Program.c
 *
 *  Created on: 29 Jan 2023
 *      Author: Ayman El-Tanboly
 */

#include "types.h"
#include "BIT_MATH.h"
#include "MSPI_Config.h"
#include "MSPI_Private.h"
#include "MSPI_Interface.h"
#include "DIO_interface.h"

//slaves data management
Slave_t	MSPI_Slave_Data[MSPI_MAX_NO_SLAVES];

//pointer to returning variable when interrupt
u8 *MSPI_pu8ReturningVar;




void	MSPI_voidInit(void)
{
	//set configurations
	MSPI_SPCR	=	((MSPI_DATA_ORDER<<5) |	(MSPI_REL<<4)	|	(MSPI_LEAD_EDGE<<3)	|	(MSPI_LEAD_EDGE_FUNCTION<<2));
#if MSPI_REL==MSPI_MASTER
	MSPI_SPCR	|=	(3U & MSPI_PRE);
	MSPI_SPSR	|=	MSPI_PRE>>2;
#endif
	//enable SPI
	SET_BIT(MSPI_SPCR,6);
}

void	MSPI_voidIntEnable(void)
{
	SET_BIT(MSPI_SPCR,7);
}

void	MSPI_voidIntDisable(void)
{
	CLR_BIT(MSPI_SPCR,7);
}


u8 MSPI_u8SendReciveData(u8 Copy_u8DataSending, u8 Copy_u8SlaveIndex)
{
#if MSPI_REL==MSPI_MASTER
	DIO_vidSetPinVal(MSPI_Slave_Data[Copy_u8SlaveIndex].MSPI_SLAVE_PORT, MSPI_Slave_Data[Copy_u8SlaveIndex].MSPI_SLAVE_PIN, DIO_LOW);
#endif
	u8 u8ErrorState = MSPI_NO_ERROR;

	MSPI_SPDR=Copy_u8DataSending;

	if(GET_BIT(MSPI_SPSR,6)==1)
	{
		u8ErrorState=MSPI_COLL_ERROR;
	}
	else
	{

	}
	return u8ErrorState;
}


u8 MSPI_u8DataPulling(u8 *Copy_pu8DataReciving, u8 Copy_u8DataSending, u8 Copy_u8SlaveIndex)
{
#if MSPI_REL==MSPI_MASTER
	DIO_vidSetPinVal(MSPI_Slave_Data[Copy_u8SlaveIndex].MSPI_SLAVE_PORT, MSPI_Slave_Data[Copy_u8SlaveIndex].MSPI_SLAVE_PIN, DIO_LOW);
#endif
	u8 u8ErrorState = MSPI_NO_ERROR;
	MSPI_SPDR=Copy_u8DataSending;
	while(GET_BIT(MSPI_SPSR,7)==0);
	SET_BIT(MSPI_SPSR,7);
	*Copy_pu8DataReciving=MSPI_SPDR;
	if(GET_BIT(MSPI_SPSR,6)==1)
	{
		u8ErrorState=MSPI_COLL_ERROR;
	}
	else
	{

	}
	return u8ErrorState;

}

void	MSPI_AddSlave(u8 Copy_u8PortNo, u8 Copy_u8PinNo)
{
	static u8 u8Slave_index = 0;
	MSPI_Slave_Data[u8Slave_index].MSPI_SLAVE_PORT=Copy_u8PortNo;
	MSPI_Slave_Data[u8Slave_index].MSPI_SLAVE_PIN=Copy_u8PinNo;
	u8Slave_index++;
}

void	MSPI_voidDataReturn(u8 *Copy_pu8DataVariable)
{
	*Copy_pu8DataVariable=MSPI_NO_DATA;
	MSPI_pu8ReturningVar=Copy_pu8DataVariable;
}

void __vector_12 (void) __attribute__((signal));
void __vector_12 (void)
{
	*MSPI_pu8ReturningVar=MSPI_SPDR;
}
