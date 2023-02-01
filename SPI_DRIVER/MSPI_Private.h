/*
 * MSPI_Private.h
 *
 *  Created on: 29 Jan 2023
 *      Author: Ayman El-Tanboly
 */

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_

#define		MSPI_SPCR		*((volatile u8*)(0x2D))
#define		MSPI_SPSR		*((volatile u8*)(0x2E))
#define		MSPI_SPDR		*((volatile u8*)(0x2F))

#endif /* MSPI_PRIVATE_H_ */
