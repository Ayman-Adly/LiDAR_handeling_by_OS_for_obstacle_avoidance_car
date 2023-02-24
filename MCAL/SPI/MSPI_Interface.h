/****************************************************************************************************************
 * @file MSPI_Interface.h
 * @author Ayman El Tanboly
 * @brief This file contains the interface of the driver for the user.
 * @version 0.1
 * @date 2023-01-29
 * 
 * @copyright Copyright (c) 2023
 * 
 ****************************************************************************************************************/

/****************************************************************************************************************
 * @brief Header guard.
 * 
 ****************************************************************************************************************/
#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

/****************************************************************************************************************
 * @brief SPI leading edge mode choices.
 * 
 ****************************************************************************************************************/
#define		MSPI_SAMPLE					0U
#define		MSPI_SETUP					1U

/****************************************************************************************************************
 * @brief SPI leading edge choices.
 * 
 ****************************************************************************************************************/
#define		MSPI_RISING					0U
#define		MSPI_FALLING				1U

/****************************************************************************************************************
 * @brief SPI clock prescalar choices.
 * 
 ****************************************************************************************************************/
#define		MSPI_PRE_4					0U
#define		MSPI_PRE_16					1U
#define		MSPI_PRE_64					2U
#define		MSPI_PRE_128				3U
#define		MSPI_PRE_2					4U
#define		MSPI_PRE_8					5U
#define		MSPI_PRE_32					6U
#define		MSPI_PRE_64D				7U

/****************************************************************************************************************
 * @brief SPI node relation choices.
 * 
 ****************************************************************************************************************/
#define		MSPI_SLAVE					0U
#define		MSPI_MASTER					1U

/****************************************************************************************************************
 * @brief SPI first sent bit configuration choices.
 * 
 ****************************************************************************************************************/
#define		MSPI_LSB					1U
#define		MSPI_MSB					0U

/****************************************************************************************************************
 * @brief SPI error macros.
 * 
 ****************************************************************************************************************/
#define		MSPI_NO_ERROR		0U
#define		MSPI_COLL_ERROR		1U

/****************************************************************************************************************
 * @brief slave struct to define its hardware connection only used in master mode.
 * 
 ****************************************************************************************************************/
typedef struct
{
	u8 MSPI_SLAVE_PORT;
	u8 MSPI_SLAVE_PIN;
}Slave_t;

/****************************************************************************************************************
 * @brief did not recieve data macros.
 * 
 ****************************************************************************************************************/
#define MSPI_NO_DATA	0U


/****************************************************************************************************************
 * @brief This function is used to intialize the communication by SPI.
 * 
 ****************************************************************************************************************/
void	MSPI_voidInit(void);

/****************************************************************************************************************
 * @brief This function is used to enable the interrupt by the SPI.
 * 
 ****************************************************************************************************************/
void	MSPI_voidIntEnable(void);

/****************************************************************************************************************
 * @brief This function is used to disable the interrupt by the SPI.
 * 
 ****************************************************************************************************************/
void	MSPI_voidIntDisable(void);

/****************************************************************************************************************
 * @brief Those are the functions to call for slave mode.
 * 
 ****************************************************************************************************************/
#if MSPI_REL==MSPI_SLAVE

/****************************************************************************************************************
 * @brief this API is used to send data and recieve by the slave with asynchronous functionality.
 * 
 * @param Copy_u8DataSending    --> a copy of the data to be sent.
 * @return u8 					--> error status.
 ****************************************************************************************************************/
u8 MSPI_u8SlaveSendReciveData(u8 Copy_u8DataSending);

/****************************************************************************************************************
 * @brief this API is used to send data and recieve by the slave by the means of pulling.
 * 
 * @param Copy_pu8DataReciving  --> a pointer to the variable that will recieve the data.
 * @param Copy_u8DataSending    --> a copy of the data to be sent.
 * @return u8                   --> error status.
 ****************************************************************************************************************/
u8 MSPI_u8SlaveDataPulling(u8 *Copy_pu8DataReciving, u8 Copy_u8DataSending);

/****************************************************************************************************************
 * @brief the end of the APIs used by the slave mode.
 * 
 ****************************************************************************************************************/
#endif

/****************************************************************************************************************
 * @brief Those are the APIs to call for master mode.
 * 
 ****************************************************************************************************************/
#if MSPI_REL==MSPI_MASTER

/****************************************************************************************************************
 * @brief This API is used by the master to add slave in its slave index.
 * 
 * @param Copy_u8PortNo    --> the port on which the slave select of the slave is connected to.
 * @param Copy_u8PinNo     --> the pin on which the slave select of the slave is connected to.
 ****************************************************************************************************************/
void	MSPI_AddSlave(u8 Copy_u8PortNo, u8 Copy_u8PinNo);

/****************************************************************************************************************
 * @brief this API is used to send data and recieve by the master by the means of pulling.
 * 
 * @param Copy_pu8DataReciving  --> a pointer to the variable that will recieve the data.
 * @param Copy_u8DataSending    --> a copy of the data to be sent.
 * @param Copy_u8SlaveIndex     --> the index of the slave that you will communicate with as a master.
 * @return u8                   --> error status.
 ****************************************************************************************************************/
u8 MSPI_u8MasterDataPulling(u8 *Copy_pu8DataReciving, u8 Copy_u8DataSending, u8 Copy_u8SlaveIndex);

/****************************************************************************************************************
 * @brief this API is used to send data and recieve by the master with asynchronous functionality.
 * 
 * @param Copy_u8DataSending  --> a copy of the data to be sent.
 * @param Copy_u8SlaveIndex   --> the index of the slave that you will communicate with as a master.
 * @return u8                 --> error status.
 ****************************************************************************************************************/
u8 MSPI_u8MasterSendReciveData(u8 Copy_u8DataSending, u8 Copy_u8SlaveIndex);

/****************************************************************************************************************
 * @brief the end of the APIs used by the master mode.
 * 
 ****************************************************************************************************************/
#endif

/****************************************************************************************************************
 * @brief This API is used to send a variable on which the output data by interrupt sends its data to.
 * 
 * @param Copy_pu8DataVariable  --> a pointer to the variable that will recieve the data when interrupt occur.
 ****************************************************************************************************************/
void	MSPI_voidDataReturn(u8 *Copy_pu8DataVariable);

/****************************************************************************************************************
 * @brief end of header guard.
 * 
 ****************************************************************************************************************/
#endif /* MSPI_INTERFACE_H_ */