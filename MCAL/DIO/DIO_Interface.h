/*
 * DIO_Interface.h
 *
 *  Created on: 18 Nov 2022
 *      Author: nour
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/**********************************************/
/********public functions prototypes***********/
/**********************************************/


/**********************************************
 * Description : this function is used to set pin value to digital Low/high
 * Scope :public
 * Inputs : u8 ProtId -> index of port number ,Range:[PORTA~POTD]
 *        : u8 PinId  ->Index of pin number in port , Range[PIN0~PIN7]
 *        : u8 Val    ->High/LOW
 * Return :void
 */
void DIO_vidSetPinVal(u8 PortId , u8 PinId , u8 val);   //vid : return void
/**********************************************
 * Description : this function is used to set pin direction to digital INPUT/OUTPUT
 * Scope :public
 * Inputs : u8 ProtId -> index of port number ,Range:[PORTA~POTD]
 *        : u8 PinId  ->Index of pin number in port , Range[PIN0~PIN7]
 *        : u8 dir    ->INPUT/OUTPUT
 * Return :void
 */
void DIO_vidSetPinDir(u8 PortId , u8 PinId , u8 dir);   //vid : return void
/**********************************************
 * Description : this function is used to set port value to digital HIGH/LOW
 * Scope :public
 * Inputs : u8 ProtId -> index of port number ,Range:[PORTA~POTD]
 *        : u8 Val    ->High/LOW
 * Return :void
 */
void DIO_vidSetPortVal(u8 PortId , u8 val);   //vid : return void
/**********************************************
 * Description : this function is used to set port direction to digital INPUT/OUTPUT
 * Scope :public
 * Inputs : u8 ProtId -> index of port number ,Range:[PORTA~POTD]
 *        : u8 dir    ->INPUT/OUTPUT
 * Return :void
 */
void DIO_vidSetPortDir(u8 PortId , u8 dir);   //vid : return void
/**********************************************
 * Description : this function is used to get pin value Low/high
 * Scope :public
 * Inputs : u8 ProtId -> index of port number ,Range:[PORTA~POTD]
 *        : u8 PinId  ->Index of pin number in port , Range[PIN0~PIN7]
 * Return : u8  -> the state of pin either low or high
 */
u8 DIO_u8GetPinVal(u8 PortId , u8 PinId );   //vid : return void


/**********************************************/
/***************public Macros******************/
/**********************************************/

//port definitions
#define DIO_PORTA   (0)
#define DIO_PORTB   (1)
#define DIO_PORTC   (2)
#define DIO_PORTD   (3)
//pins definitions
#define DIO_PIN0    (0)
#define DIO_PIN1    (1)
#define DIO_PIN2    (2)
#define DIO_PIN3    (3)
#define DIO_PIN4    (4)
#define DIO_PIN5    (5)
#define DIO_PIN6    (6)
#define DIO_PIN7    (7)
//digital vals
#define DIO_HIGH    (1)
#define DIO_LOW     (0)
#define DIO_OUTPUT  (1)
#define DIO_INPUT   (0)
#define PORT_HIGH	(0XFF)
#define PORT_OUTPUT	(0XFF)

#endif /* DIO_INTERFACE_H_ */
