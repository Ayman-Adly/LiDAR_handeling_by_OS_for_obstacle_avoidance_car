/*
 * MSPI_Interface.h
 *
 *  Created on: 29 Jan 2023
 *      Author: Ayman El-Tanboly
 */

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

//macros
#define		MSPI_NO_ERROR		0U
#define		MSPI_COLL_ERROR		1U

//slave struct
typedef struct
{
	u8 MSPI_SLAVE_PORT;
	u8 MSPI_SLAVE_PIN;
}Slave_t;

//didn't recieve data macro
#define MSPI_NO_DATA	0U

//functions
void	MSPI_voidInit(void);
void	MSPI_voidIntEnable(void);
void	MSPI_voidIntDisable(void);
u8 MSPI_u8SendReciveData(u8 Copy_u8DataSending, u8 Copy_u8SlaveIndex);
u8 MSPI_u8DataPulling(u8 *Copy_pu8DataReciving, u8 Copy_u8DataSending, u8 Copy_u8SlaveIndex);
void	MSPI_AddSlave(u8 Copy_u8PortNo, u8 Copy_u8PinNo);
void	MSPI_voidDataReturn(u8 *Copy_pu8DataVariable);
#endif /* MSPI_INTERFACE_H_ */
