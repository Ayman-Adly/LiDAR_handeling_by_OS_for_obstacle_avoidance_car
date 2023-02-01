/*
 * GIE_prog.c
 *
 *  Created on: 4 Dec 2022
 *      Author: Ayman El-Tanboly
 */
#include "types.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <avr/delay.h>
#include "DIO_interface.h"
#include "GIE_priv.h"
#include "GIE_interface.h"
#include "GIE_conf.h"


void GIE_vidEnable(void)
{
	SET_BIT(SREG,7);
}

void GIE_vidDisable(void)
{
	CLR_BIT(SREG,7);
}
