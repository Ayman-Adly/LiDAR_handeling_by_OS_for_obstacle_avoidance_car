/*
 * RTOS_Priv.h
 *
 *  Created on: 2 Feb 2023
 *      Author: nour
 */



#define TIMER_INITIAL_COUNT (0U)


typedef enum
{

TASK_SUSPENDE,
TASK_RESUMED

}TaskState_t;




typedef struct
{

	u8 ID				   ;
	u8 Periority		   ;
	u8 TempPeriority	   ;
	u16 periodicity        ;
	void (*TaskFunc)(void) ;
	TaskState_t TaskState  ;
	u16 FirstDelay	   	   ;

}Task_t;


typedef struct
{

	u8 SemaphoreState     	    ;

}Semaphore_t;


typedef struct
{

	u8 MaxCount     	    ;
	u8 InitialCount         ;

}CountingSemaphore_t;
typedef struct
{

	u8 MaxPeriority         ;
	u8 MutexState     	    ;

}Mutex_t;


typedef enum
{

TAKEN,
AVILALBLE

}SemaphoreState_t;

typedef enum
{
FAIL,
PASS

}ServiceState_t;
static void vidSchedular(void);

