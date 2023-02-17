/*
 * GIE_Prog.c
 *
 *  Created on: 6 Dec 2022
 *      Author: nour
 */
#include "avr/interrupt.h"
#include "../../LIB/STD_Types.h"
#include "GIE_Priv.h"
#include "GIE_Interface.h"
void GIE_vidEnable(void)
{

SREG_REG |= (1<<7);

}
void GIE_vidDisable(void)
{

SREG_REG &= ( ~(1<<7) );

}
