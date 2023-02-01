/*
 * DIO_interface.h
 *
 *  Created on: 18 Nov 2022
 *      Author: Ayman El-Tanboly
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*****************************************************************************************/
/***********************************Public Function***************************************/
/*****************************************************************************************/
/*****************************************************************************************
 * Description: This function is used to set pin value
 * Scope:       public
 * Inputs:      u8 PortId ------ port number is given, range [DIO_PORTA~DIO_PORTD]
 *              u8 PinId ------- pin number is given, Range [DIO_PIN0~DIO_PIN7]
 *              u8 val --------- DIO_HIGH/DIO_LOW
 * Return:      void
 *****************************************************************************************/

void DIO_vidSetPinVal(u8 PortId, u8 PinId, u8 val);

/*****************************************************************************************
 * Description: This function is used to set pin direction
 * Scope:       public
 * Inputs:      u8 PortId ------ port number is given, range [DIO_PORTA~DIO_PORTD]
 *              u8 PinId ------- pin number is given, Range [DIO_PIN0~DIO_PIN7]
 *              u8 dir --------- DIO_INPUT/DIO_OUTPUT
 * Return:      void
 *****************************************************************************************/

void DIO_vidSetPinDir(u8 PortId, u8 PinId, u8 dir);

/*****************************************************************************************
 * Description: This function is used to set port value
 * Scope:       public
 * Inputs:      u8 PortId ------ port number is given, range [DIO_PORTA~DIO_PORTD]
 *              u8 val --------- DIO_HIGH/DIO_LOW
 * Return:      void
 *****************************************************************************************/

void DIO_vidSetPortVal(u8 PortId, u8 val);

/*****************************************************************************************
 * Description: This function is used to set port direction
 * Scope:       public
 * Inputs:      u8 PortId ------ port number is given, range [DIO_PORTA~DIO_PORTD]
 *              u8 dir --------- DIO_INPUT/DIO_OUTPUT
 * Return:      void
 *****************************************************************************************/

void DIO_vidSetPortDir(u8 PortId, u8 dir);

/*****************************************************************************************
 * Description: This function is used to get the pin value
 * Scope:       public
 * Inputs:      u8 PortId ------ port number is given, range [DIO_PORTA~DIO_PORTD]
 *              u8 PinId ------- pin number is given, Range [DIO_PIN0~DIO_PIN7]
 * Return:      returns u8 value of the pin
 *****************************************************************************************/

u8 DIO_u8GetPinVal(u8 PortId, u8 PinId);

/*****************************************************************************************/
/*********************************Public Macros*******************************************/
/*****************************************************************************************/

//Port definitions
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3
//Pin definitions
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7
//Digital Values
#define DIO_HIGH 1
#define DIO_LOW 0
#define DIO_PORT_HIGH 0xFF
#define DIO_PORT_LOW 0
//Directions
#define DIO_OUTPUT 1
#define DIO_INPUT 0
#define DIO_PORT_OUTPUT 0xFF
#define DIO_PORT_INPUT 0

#endif /* DIO_INTERFACE_H_ */
