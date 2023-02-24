/**
 * @file LCD_conf.h .
 * @author Hisham Montaser. 
 * @brief This is the LCD_conf.h for file configraution.
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 * @details This file gives the ability for the user to feel some sort of felxibilty with the chocies the developer made .
 */

/**************************************************************************************************************/
/*                     HeaderGuard : Prevent Multiple calls of Config.h header file                           */
/**************************************************************************************************************/

#ifndef LCD_CONF_H_
#define LCD_CONF_H_

/***********************************************************************************************/
/*                                       DATA PORT                                              /
/***********************************************************************************************/
#define LCD_DATA_PORT     PORTD

/***********************************************************************************************/
/*                                      Control PORT                                           */
/***********************************************************************************************/
#define LCD_CONTROL_PORT  PORTC

/***********************************************************************************************/
/*                                      Control PINs                                           */
/***********************************************************************************************/

/*RS PIN*/
#define LCD_RS_PIN         PIN6

/*RW PIN*/
#define LCD_RW_PIN         PIN5

/*E PIN*/
#define LCD_E_PIN          PIN4


#endif /* LCD_CONF_H_ */
