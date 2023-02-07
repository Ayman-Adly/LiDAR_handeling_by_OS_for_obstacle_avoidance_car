/*
 * bitmath.h
 *
 *  Created on: 18 Nov 2022
 *      Author: nour
 */

#ifndef BITMATH_H_
#define BITMATH_H_

#define  SET_BIT(REG,BIT_NUM)     (REG|=(1<<BIT_NUM))
#define  CLR_BIT(REG,BIT_NUM)     (REG&=(~(1<<BIT_NUM)))
#define  TOG_BIT(REG,BIT_NUM)     (REG^=(1<<BIT_NUM))
//#define  GET_BIT(REG,BIT_NUM)     ((REG&=(1<<BIT_NUM))>>BIT_NUM)
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)

#endif /* BITMATH_H_ */
