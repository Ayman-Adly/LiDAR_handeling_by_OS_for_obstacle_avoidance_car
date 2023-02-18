/*
 * Types.h
 *
 *  Created on: 18 Nov 2022
 *      Author: nour
 */

#ifndef TYPES_H_
#define TYPES_H_


/*this value represent the invalid value of task id*/
#define	 ID_INVALID (TASK_NUM)


/*this enum represent the state value*/
typedef enum
{
	STATE_FAIL,  	  //state failed
	STATE_SUCCESS     //state success
}State_t;



typedef unsigned char              u8;
typedef unsigned short int        u16;
typedef unsigned long int         u32;
typedef signed char                s8;
typedef signed short int          s16;
typedef float                     f32;
typedef double                    f64;
typedef signed long int           s32;

#endif /* TYPES_H_ */
