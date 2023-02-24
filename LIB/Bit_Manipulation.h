/**
 * @file Bit_Manipulation.h
 * @author Hisham Montaser 
 * @brief This is the Bit_Manipulation.h file for each bit being set , clear , get or toggle .
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 * @details This file has four macros each macro is being replaced with a logic to set , clear , get or toggle a certain bit .
 */
/*************************************************************************************/
/*Author:           Hisham_Montaser                                                  */
/*Version:          V0.0.0                                                           */
/*Date:             1 - 25 - 2023                                                    */
/*Description:      Bit_Manipulation.h -> Data types                                 */
/*************************************************************************************/

/*************************************************************************************/
/*                   Header Gurad : Prevent Multiple calls of Bit_Manipulation.h     */
/*************************************************************************************/
#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H
/* Setting a certain bit */
#define SET_BIT(reg,n)  	(reg |= (1<<n))
/*Clearing a certain bit */
#define CLR_BIT(reg,n)		(reg &= ~(1<<n))
/* Toggle a certain bit */
#define TOGGLE_BIT(reg,n)	(reg ^= (1<<n))
/* Getting a certain bit */
#define GET_BIT(reg,n)		(((reg)>>(n))&(1))

#endif 
/**************************************************************************************/
