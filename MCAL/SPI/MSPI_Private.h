/***************************************************************
 * @file MSPI_Private.h
 * @author Ayman El Tanboly
 * @brief The private file.
 * @version 0.1
 * @date 2023-01-29
 * @details This file contains the private macros of the SPI.
 * @copyright Copyright (c) 2023
 * 
 ***************************************************************/

/****************************************************************
 * @brief Header guards.
****************************************************************/
#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_

/****************************************************************
 * @brief definition of private registers of SPI.
 * 
 ****************************************************************/
#define		MSPI_SPCR		*((volatile u8*)(0x2D))
#define		MSPI_SPSR		*((volatile u8*)(0x2E))
#define		MSPI_SPDR		*((volatile u8*)(0x2F))

/****************************************************************
 * @brief end of header guards.
 * 
 ****************************************************************/
#endif /* MSPI_PRIVATE_H_ */