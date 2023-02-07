/*
 * RTOS_Prog.c
 *
 *  Created on: 2 Feb 2023
 *      Author: nour
 */
#include "Types.h"
#include "stdlib.h"

#include "Timer0_Interface.h"
#include "GIE_Interface.h"

#include "RTOS_Priv.h"
#include "RTOS_Config.h"
#include "RTOS_Interface.h"




/*create objects from Task type depends on the user selection of number of tasks in the
 *  RTOS_Config.h and initialize all Tasks with 0 to detect then if there are functions not created*/
Task_t SystemTasks[TASK_NUM]={{NULL}};




void OS_vidStart(void)
{

	/*set the schedular function to be run inside the ISR*/
	TIMER1_vidSetOCompareMatchISR(&vidSchedular);
	/*Global interrupt enable*/
	GIE_vidEnable();
	/*Timer init -> CTC MODE - Prescaller - Enable compare match  interrupt */
	TIMER1_vidInit();

}



void OS_vidCreateTask(u8 Copy_u8Periority , u16 Copy_u16Periodicity ,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay)
{

/*assign of the Task code func and periodicity of every task in the System_Tasks depends on it's periority   */
SystemTasks[Copy_u8Periority].ID=Copy_u8Periority;

SystemTasks[Copy_u8Periority].Periority=Copy_u8Periority;

SystemTasks[Copy_u8Periority].TempPeriority=Copy_u8Periority;


SystemTasks[Copy_u8Periority].periodicity=Copy_u16Periodicity;

SystemTasks[Copy_u8Periority].TaskFunc=Copy_pvTaskFunc;

SystemTasks[Copy_u8Periority].TaskState=TASK_RESUMED;

SystemTasks[Copy_u8Periority].FirstDelay=Copy_u16FirstDelay;

}


static void vidSchedular(void)
{



/*task counter to check all the tasks wants to run at this tick*/
static u8 TaskCounter;



/*check which task wants to run at the current timer tick depends on the task periodicity  */
for(TaskCounter=0 ;TaskCounter<TASK_NUM ;TaskCounter++)
{
	/*check if the Task has First delay value to wait*/
	if( SystemTasks[TaskCounter].FirstDelay==0)
	{

		/*check if the task is already created or not and another check of the task state to make sure that the task is resumed*/
		if(SystemTasks[TaskCounter].TaskFunc != NULL && SystemTasks[TaskCounter].TaskState==TASK_RESUMED)
		{
			SystemTasks[TaskCounter].TaskFunc();
			/*assign the Periodicity -1 to the first delay because the Task now ready to run periodically after completing its first delay of waiting*/
			SystemTasks[TaskCounter].FirstDelay = SystemTasks[TaskCounter].periodicity-1;
		}
		else
		{
			/*do nothing*/
		}

	}
	else
	{
		/*decrease the first delay value by 1 */
		SystemTasks[TaskCounter].FirstDelay--;
	}


}

}

void OS_vidSuspendTask(u8 Copy_u8Periority)
{

/*changing the task state to TASK_SUSPENDE*/
SystemTasks[Copy_u8Periority].TaskState=TASK_SUSPENDE;

}
void OS_vidResumeTask(u8 Copy_u8Periority)
{

/*changing the task state to TASK_RESUMED*/
SystemTasks[Copy_u8Periority].TaskState=TASK_RESUMED;

}

void OS_vidDeleteTask(u8 Copy_u8Periority)
{
	/*making the task FUNC equal to NULL*/
SystemTasks[Copy_u8Periority].TaskFunc=NULL;

}

void OS_vidSemaphoreCreateBinary(Semaphore_t * Semaphore)
{

	Semaphore->SemaphoreState=AVILALBLE;
}


ServiceState_t OS_u8SemaphoreTake(Semaphore_t * Semaphore)
{

	ServiceState_t ServiceState=FAIL;
	if(Semaphore->SemaphoreState==AVILALBLE)
	{
	Semaphore->SemaphoreState=TAKEN;
	ServiceState=PASS;
	}
	return ServiceState;
}

void OS_vidSemaphoreGive(Semaphore_t * Semaphore)
{

		Semaphore->SemaphoreState=AVILALBLE;

}


void OS_vidSemaphoreCreateCounting(CountingSemaphore_t* Semaphore , u8 MaxCount , u8 InitialCount)
{

	Semaphore->MaxCount=MaxCount;
	Semaphore->InitialCount=InitialCount;

}


/*u must check the return of this function once only if  u will will not give the semaphore in ur logic*/
u8 OS_u8CountingSemaphoreTake(CountingSemaphore_t *Semaphore)
{
	u8 CountingSemaphore_State=FAIL;
	Semaphore->InitialCount++;
	if(Semaphore->MaxCount  >=  Semaphore->InitialCount)
	{
		CountingSemaphore_State=PASS;
	}
	else
	{
		Semaphore->InitialCount--;
	}
	return CountingSemaphore_State;

}

void OS_vidCountingSemaphoreGive(CountingSemaphore_t* Semaphore)
{

	Semaphore->InitialCount--;

}


void OS_vidMutexCreate( Mutex_t* Mutex , u8 Num_of_Tasks , u8 * ptr_to_tasks_periorities )
{

Mutex->MutexState=AVILALBLE;

u8 MaxPeriority=ptr_to_tasks_periorities[0];
for(u8 i =0 ; i < Num_of_Tasks-1 ; i++)
{

	if(ptr_to_tasks_periorities[i]>ptr_to_tasks_periorities[i+1])
	{
		MaxPeriority=ptr_to_tasks_periorities[i];
	}
	else
	{
		MaxPeriority=ptr_to_tasks_periorities[i+1];
	}
	Mutex->MaxPeriority=MaxPeriority;

}


}

u8 OS_u8MutexTake(Mutex_t* Mutex ,u8 Task_ID )
{


	ServiceState_t ServiceState=FAIL;
	if(Mutex->MutexState==AVILALBLE)
	{
		SystemTasks[Task_ID].Periority=Mutex->MaxPeriority;

		Mutex->MutexState=TAKEN;

		ServiceState=PASS;
	}
	return ServiceState;


}

void OS_vidMutexGive(Mutex_t* Mutex ,u8 Task_ID )
{

SystemTasks[Task_ID].Periority=SystemTasks[Task_ID].TempPeriority;
Mutex->MutexState=AVILALBLE;

}



