
#include "Types.h"
#include "stdlib.h"

#include "Timer0_Interface.h"
#include "GIE_Interface.h"

#include "RTOS_Priv.h"
#include "RTOS_Config.h"
#include "RTOS_Interface.h"

#include <stdio.h>


Task_t* HeadNode=NULL;


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
	
	Task_t * NewTask=( Task_t *)malloc(sizeof(Task_t));
	
/*assign of the Task code func and periodicity of every task in the System_Tasks depends on it's periority   */

	NewTask -> Priority        = Copy_u8Periority;

	NewTask -> periodicity      = Copy_u16Periodicity;

	NewTask -> TaskFunc	        = Copy_pvTaskFunc;

	NewTask -> TaskState        = TASK_READY;

	NewTask -> FirstDelay       = Copy_u16FirstDelay;
	
	NewTask -> Next             = NULL;
	// If the list is empty
	if(HeadNode==NULL)    
		{
			// Circularly linked list
			HeadNode=NewTask; 
			HeadNode->Next = HeadNode;
		}
	else
		{
			// reconnect the links
			NewTask->Next = HeadNode->Next;
			HeadNode->Next = NewTask;
		}

}



static void vidSchedular(void)
{
	
	u8 HighPri;	
	Task_t *pstEnd;
	Task_t *pstNextTask;

	// Set highest priority to idle at first.
	HighPri = 0;

	//-----------------------------------------------------------------------
	// Set the next task level to run as that of the highest of the ready or 
	// running tasks.
	//-----------------------------------------------------------------------
	pstEnd 		= HeadNode->Next;
	pstNextTask = HeadNode->Next;
	do 
	{
		// If the task is ready to run, or it's currently running...
		if ( (pstNextTask->TaskState == TASK_READY ) )	
		{
			if(pstNextTask->FirstDelay==0)
			{
			// and the priority is > highest priority
			if (pstNextTask->Priority > HighPri)
			{
				// Assign the priority level to run
				HighPri = pstNextTask->Priority;

			}
			}
			

		}

		// Next in the list...
		pstNextTask = pstNextTask->Next;

	} while (pstEnd != pstNextTask);	// Haven't gone through the entire list.
	
	
	
	
	
	pstEnd 		= HeadNode->Next;
	pstNextTask = HeadNode->Next;
	do 
	{
		// If the task is ready to run, or it's currently running...
		if  (pstNextTask->TaskState == TASK_READY ) 
		{
			if (pstNextTask->FirstDelay==0) 
			{
			// and the priority is > highest priority
			if (pstNextTask->Priority == HighPri)
			{
				// Assign the priority level to run
				HighPri = pstNextTask->Priority;
				pstNextTask->TaskFunc();
				pstNextTask->FirstDelay=pstNextTask->periodicity;
				break;
			}
			}
		}

		// Next in the list...
		pstNextTask = pstNextTask->Next;

	} while (pstEnd != pstNextTask);	// Haven't gone through the entire list.
	


	pstEnd = HeadNode->Next;
	pstNextTask = HeadNode->Next;
	do 
	{
		// If the task is ready to run, or it's currently running...
		if  (pstNextTask->TaskState == TASK_READY ) 
		{
			if (pstNextTask->FirstDelay!=0) 
			{
			pstNextTask->FirstDelay--;
			
			}
		}

		// Next in the list...
		pstNextTask = pstNextTask->Next;

	} while (pstEnd != pstNextTask);	// Haven't gone through the entire list.
	
	}

