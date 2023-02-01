/*
 * MSPI_Config.h
 *
 *  Created on: 29 Jan 2023
 *      Author: Ayman El-Tanboly
 */

#ifndef MSPI_CONFIG_H_
#define MSPI_CONFIG_H_


/*Macros Choices*/
#define		MSPI_SAMPLE					0U
#define		MSPI_SETUP					1U

#define		MSPI_RISING					0U
#define		MSPI_FALLING				1U

#define		MSPI_PRE_4					0U
#define		MSPI_PRE_16					1U
#define		MSPI_PRE_64					2U
#define		MSPI_PRE_128				3U
#define		MSPI_PRE_2					4U
#define		MSPI_PRE_8					5U
#define		MSPI_PRE_32					6U
#define		MSPI_PRE_64D				7U

#define		MSPI_SLAVE					0U
#define		MSPI_MASTER					1U

#define		MSPI_LSB					1U
#define		MSPI_MSB					0U


/*configure choices*/
#define		MSPI_DATA_ORDER				MSPI_LSB
#define		MSPI_LEAD_EDGE_FUNCTION		MSPI_SAMPLE
#define		MSPI_LEAD_EDGE				MSPI_RISING
#define		MSPI_PRE					MSPI_PRE_4
#define		MSPI_REL					MSPI_SLAVE
#define		MSPI_MAX_NO_SLAVES			1

#endif /* MSPI_CONFIG_H_ */
