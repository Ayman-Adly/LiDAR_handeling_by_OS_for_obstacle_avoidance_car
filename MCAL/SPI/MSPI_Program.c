/************************************************************************************************************************************************
 * @file MSPI_Program.c
 * @author Ayman El Tanboly
 * @brief This file contains the implementation of the SPI APIs.
 * @version 0.1
 * @date 2023-01-29
 * 
 * @copyright Copyright (c) 2023
 * 
 ************************************************************************************************************************************************/

/************************************************************************************************************************************************
 * @brief The includes of this files.
 * 
 ***********************************************************************************************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Manipulation.h"
#include "MSPI_Config.h"
#include "MSPI_Private.h"
#include "MSPI_Interface.h"
#include "../DIO/DIO_INTERFACE.h"

/************************************************************************************************************************************************
 * @brief For master this contains the array of structs for each slave of the max number of slaves.
 * 
 ***********************************************************************************************************************************************/
#if MSPI_REL==MSPI_MASTER

/************************************************************************************************************************************************
 * @brief The array that contains the slaves slave select position to the max number of slaves.
 * 
 ***********************************************************************************************************************************************/
Slave_t	MSPI_Slave_Data[MSPI_MAX_NO_SLAVES];

//chosen slave for interrupt
/************************************************************************************************************************************************
 * @brief The array that contains the slaves slave select position to the max number of slaves.
 * 
 ***********************************************************************************************************************************************/
u8 MSPI_Copy_u8SlaveIndex;

/************************************************************************************************************************************************
 * @brief The end of the master's code additions.
 * 
 ***********************************************************************************************************************************************/
#endif

/************************************************************************************************************************************************
 * @brief pointer to returning variable when interrupt.
 * 
 ***********************************************************************************************************************************************/
u8 *MSPI_pu8ReturningVar;

/************************************************************************************************************************************************
 * @brief This function is used to intialize the communication by SPI.
 * 
 ************************************************************************************************************************************************/
void	MSPI_voidInit(void)
{
	//set configurations
	MSPI_SPCR	=	((MSPI_DATA_ORDER<<5) |	(MSPI_REL<<4)	|	(MSPI_LEAD_EDGE<<3)	|	(MSPI_LEAD_EDGE_FUNCTION<<2));
	//master init addition
#if MSPI_REL==MSPI_MASTER
	//configure the clock
	MSPI_SPCR	|=	(3U & MSPI_PRE);
	MSPI_SPSR	|=	MSPI_PRE>>2;
#endif
	//enable SPI
	SET_BIT(MSPI_SPCR,6);
}

/************************************************************************************************************************************************
 * @brief This function is used to enable the interrupt by the SPI.
 * 
 ************************************************************************************************************************************************/
void	MSPI_voidIntEnable(void)
{
	//set enable bit
	SET_BIT(MSPI_SPCR,7);
}

/************************************************************************************************************************************************
 * @brief This function is used to disable the interrupt by the SPI.
 * 
 ************************************************************************************************************************************************/
void	MSPI_voidIntDisable(void)
{
	//clear enable bit.
	CLR_BIT(MSPI_SPCR,7);
}

/************************************************************************************************************************************************
 * @brief Those are the functions to call for slave mode.
 * 
 ************************************************************************************************************************************************/
#if MSPI_REL==MSPI_SLAVE

/************************************************************************************************************************************************
 * @brief this API is used to send data and recieve by the slave with asynchronous functionality.
 * 
 * @param Copy_u8DataSending    --> a copy of the data to be sent.
 * @return u8 					--> error status.
 ************************************************************************************************************************************************/
u8 MSPI_u8SlaveSendReciveData(u8 Copy_u8DataSending)
{
	//intial it has no error
	u8 u8ErrorState = MSPI_NO_ERROR;
	//sending data in the data register
	MSPI_SPDR=Copy_u8DataSending;
	//check if error occurs
	if(GET_BIT(MSPI_SPSR,6)==1)
	{
		//return error as a state
		u8ErrorState=MSPI_COLL_ERROR;
	}
	else
	{

	}
	//returning the state
	return u8ErrorState;
}

/************************************************************************************************************************************************
 * @brief this API is used to send data and recieve by the slave by the means of pulling.
 * 
 * @param Copy_pu8DataReciving  --> a pointer to the variable that will recieve the data.
 * @param Copy_u8DataSending    --> a copy of the data to be sent.
 * @return u8                   --> error status.
 ************************************************************************************************************************************************/
u8 MSPI_u8SlaveDataPulling(u8 *Copy_pu8DataReciving, u8 Copy_u8DataSending)
{
	//intial it has no error
	u8 u8ErrorState = MSPI_NO_ERROR;
	//sending data in the data register
	MSPI_SPDR=Copy_u8DataSending;
	//pulling on the data until it is recieved
	while(GET_BIT(MSPI_SPSR,7)==0);
	//returning the recieved data
	*Copy_pu8DataReciving=MSPI_SPDR;
	//clearing the flag for further communication
	SET_BIT(MSPI_SPSR,7);
	//check if error occurs
	if(GET_BIT(MSPI_SPSR,6)==1)
	{
		//return error as a state
		u8ErrorState=MSPI_COLL_ERROR;
	}
	else
	{

	}
	//returning the state
	return u8ErrorState;

}

/************************************************************************************************************************************************
 * @brief the end of the APIs used by the slave mode.
 * 
 ************************************************************************************************************************************************/
#endif

/************************************************************************************************************************************************
 * @brief Those are the APIs to call for master mode.
 * 
 ************************************************************************************************************************************************/
#if MSPI_REL==MSPI_MASTER

/************************************************************************************************************************************************
 * @brief This API is used by the master to add slave in its slave index.
 * 
 * @param Copy_u8PortNo    --> the port on which the slave select of the slave is connected to.
 * @param Copy_u8PinNo     --> the pin on which the slave select of the slave is connected to.
 ************************************************************************************************************************************************/
void	MSPI_AddSlave(u8 Copy_u8PortNo, u8 Copy_u8PinNo)
{
	//setting the slaves first index
	static u8 u8Slave_index = 0;
	//saving the port in its struct
	MSPI_Slave_Data[u8Slave_index].MSPI_SLAVE_PORT=Copy_u8PortNo;
	//saving the pin in its struct
	MSPI_Slave_Data[u8Slave_index].MSPI_SLAVE_PIN=Copy_u8PinNo;
	//initially setting slave as inactive
	DIO_voidSetPinValue(MSPI_Slave_Data[u8Slave_index].MSPI_SLAVE_PORT, MSPI_Slave_Data[u8Slave_index].MSPI_SLAVE_PIN, HIGH);
	//incrementing the slave's ID
	u8Slave_index++;
}

/************************************************************************************************************************************************
 * @brief this API is used to send data and recieve by the master with asynchronous functionality.
 * 
 * @param Copy_u8DataSending  --> a copy of the data to be sent.
 * @param Copy_u8SlaveIndex   --> the index of the slave that you will communicate with as a master.
 * @return u8                 --> error status.
 ************************************************************************************************************************************************/
u8 MSPI_u8MasterSendReciveData(u8 Copy_u8DataSending, u8 Copy_u8SlaveIndex)
{
	//activating slave's slave select
	DIO_voidSetPinValue(MSPI_Slave_Data[Copy_u8SlaveIndex].MSPI_SLAVE_PORT, MSPI_Slave_Data[Copy_u8SlaveIndex].MSPI_SLAVE_PIN,LOW);
	//setting the slave's index as a global variable for when interrupt occurs the slave is automatically deactivated
	MSPI_Copy_u8SlaveIndex = Copy_u8SlaveIndex;
	//intial it has no error
	u8 u8ErrorState = MSPI_NO_ERROR;
	//sending data in the data register
	MSPI_SPDR=Copy_u8DataSending;
	//check if error occurs
	if(GET_BIT(MSPI_SPSR,6)==1)
	{
		//return error as a state
		u8ErrorState=MSPI_COLL_ERROR;
	}
	else
	{

	}
	//returning the state
	return u8ErrorState;
}

/************************************************************************************************************************************************
 * @brief this API is used to send data and recieve by the master by the means of pulling.
 * 
 * @param Copy_pu8DataReciving  --> a pointer to the variable that will recieve the data.
 * @param Copy_u8DataSending    --> a copy of the data to be sent.
 * @param Copy_u8SlaveIndex     --> the index of the slave that you will communicate with as a master.
 * @return u8                   --> error status.
 ************************************************************************************************************************************************/
u8 MSPI_u8MasterDataPulling(u8 *Copy_pu8DataReciving, u8 Copy_u8DataSending, u8 Copy_u8SlaveIndex)
{
	//activating slave's slave select
	DIO_voidSetPinValue(MSPI_Slave_Data[Copy_u8SlaveIndex].MSPI_SLAVE_PORT, MSPI_Slave_Data[Copy_u8SlaveIndex].MSPI_SLAVE_PIN, LOW);
	//intial it has no error
	u8 u8ErrorState = MSPI_NO_ERROR;
	//sending data in the data register
	MSPI_SPDR=Copy_u8DataSending;
	//pulling on the data until it is recieved
	while(GET_BIT(MSPI_SPSR,7)==0);
	//returning the recieved data
	*Copy_pu8DataReciving=MSPI_SPDR;
	//clearing the flag for further communication
	SET_BIT(MSPI_SPSR,7);
	//deactivating slave's slave select
	DIO_voidSetPinValue(MSPI_Slave_Data[Copy_u8SlaveIndex].MSPI_SLAVE_PORT, MSPI_Slave_Data[Copy_u8SlaveIndex].MSPI_SLAVE_PIN, HIGH);
	//check if error occurs
	if(GET_BIT(MSPI_SPSR,6)==1)
	{
		//return error as a state
		u8ErrorState=MSPI_COLL_ERROR;
	}
	else
	{

	}
	//returning the state
	return u8ErrorState;

}

/************************************************************************************************************************************************
 * @brief the end of the APIs used by the master mode.
 * 
 ************************************************************************************************************************************************/
#endif

/************************************************************************************************************************************************
 * @brief This API is used to send a variable on which the output data by interrupt sends its data to.
 * 
 * @param Copy_pu8DataVariable  --> a pointer to the variable that will recieve the data when interrupt occur.
 ************************************************************************************************************************************************/
void	MSPI_voidDataReturn(u8 *Copy_pu8DataVariable)
{
	//intially setting it has no data
	*Copy_pu8DataVariable=MSPI_NO_DATA;
	//sending the address of the variable to a global variable to recieve data when interrupt occur
	MSPI_pu8ReturningVar=Copy_pu8DataVariable;
}

/************************************************************************************************************************************************
 * @brief The ISR function of the SPI
 * 
 ************************************************************************************************************************************************/
void __vector_12 (void) __attribute__((signal));
void __vector_12 (void)
{
	//setting the value of the global variable by the data in the data register
	*MSPI_pu8ReturningVar=MSPI_SPDR;
	//addition to the functionality for the master
#if MSPI_REL==MSPI_MASTER
	//deactivating slave's slave select
	DIO_voidSetPinValue(MSPI_Slave_Data[MSPI_Copy_u8SlaveIndex].MSPI_SLAVE_PORT, MSPI_Slave_Data[MSPI_Copy_u8SlaveIndex].MSPI_SLAVE_PIN, HIGH);
	//ending of the master's addition
#endif

}
