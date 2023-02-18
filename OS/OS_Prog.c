/*********************************************************************************************
 * @file 	OS_Prog.c
 * @author 	Ehap Ashraf / Moamen Ehap 
 * @brief 	This is the OS_Prog.c file for defining function implementations . 
 * @version 0.0.0
 * @date 	2-17-2023 (Date of documenting)
 *
 *********************************************************************************************/
#include <stdio.h>
#include "../../LIB/STD_Types.h"
#include "../TIMER/Timer1_Interface.h"
#include "../GIE/GIE_Interface.h"
#include "OS_Priv.h"
#include "OS_Config.h"
#include "OS_Interface.h"


/* Initialize the pointer that will point to the first task */
Task_t* HeadNode=NULL;

/* Initialize the flag that will help me know when the interrupt is fired */
u8 flag =FAIL;

/* Initialize the max ID for tasks */
/* the id starts from 1 to 255 */
static u8 MaxID=0;


/*****************************************************************************************************************************************
* @brief Start the scheduler
*
*****************************************************************************************************************************************/
void OS_vidStart(void)
{

	/*Global interrupt enable*/
	GIE_vidEnable();
	/*Timer init -> CTC MODE - Prescaller - Enable compare match interrupt */
	TIMER1_vidInit();

	while(1)
	{
		if (flag == SUCCESS)
		{

			flag=FAIL;
			vidSchedular();

		}
		else
		{
			/*ideal task*/
		}
	}

}
/*****************************************************************************************************************************************
* @brief Add a task to the scheduler list
*
* @param Copy_u8Periority			--> Copy_u8Priority priority of the task (0-255)
* @param Copy_u16Periodicity		--> Copy_u16Periodicity periodicity of the task
* @param (*Copy_pvTaskFunc)(void)	--> Copy_pvTaskFunc pointer to the task's entry function
* @param Copy_u16FirstDelay			--> Copy_u16FirstDelay first delay of the task
* @return u8 ID on success, FAIL on failure
*****************************************************************************************************************************************/

u8 OS_u8CreateTask(u8 Copy_u8Priority , u16 Copy_u16Periodicity ,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay)
{
	u8 returnState = FAIL;
	
	/* allocate memory of size struct */
	Task_t * NewTask=( Task_t *)malloc(sizeof(Task_t));
	
	if (NewTask != NULL)
	{

	/*assign of the priority,Task code func, periodicity , first delay
     ,state of task and the ID of every task in list */

		NewTask -> Task . Priority         = Copy_u8Priority;

		NewTask -> Task . periodicity      = Copy_u16Periodicity;

		NewTask -> Task . TaskFunc	       = Copy_pvTaskFunc;

		NewTask -> Task . TaskState        = TASK_READY;

		NewTask -> Task . FirstDelay       = Copy_u16FirstDelay;

		NewTask -> Task . task_ID		   = MaxID;

		/* If the list is empty */
		if(HeadNode==NULL)
			{
				/* Circularly linked list */
				HeadNode=NewTask;
				HeadNode->Next = HeadNode;
			}
		else
			{
				/* reconnect the links */
				NewTask->Next = HeadNode->Next;
				HeadNode->Next = NewTask;
			}

			MaxID++;
			returnState =  NewTask -> Task . task_ID ;
	}
	else
	{
		/* no memory available */
		returnState = FAIL;
	}

	return returnState ;
}


/*****************************************************************************************************************************************
* @brief The scheduler is priority-based . Where there are multiple tasks
*        sharing the same priority, the scheduler will run the last task
*		 created then the one before it
* @return static void
*****************************************************************************************************************************************/

static void vidSchedular(void)
{
	
	u8 HighPri;	
	Task_t *pstEnd;
	Task_t *pstNextTask;

	/* initialize the var with lowest priority .*/
	HighPri = 0;

	/* Set the next task level to run as that of the highest of the ready or
	   running tasks. */

	pstEnd 		= HeadNode->Next;
	pstNextTask = HeadNode->Next;
	do 
	{
		/* If the task is ready to run */
		if ( (pstNextTask-> Task .TaskState == TASK_READY) )
		{
			if(pstNextTask-> Task .FirstDelay == 0)
			{
			/* and the priority is > highest priority */
			if (pstNextTask-> Task .Priority > HighPri)
			{
				/* Assign the priority level to run */
				HighPri = pstNextTask-> Task .Priority;
			}

			}
			

		}

		/* Next in the list */
		pstNextTask = pstNextTask->Next;

	} while (pstEnd != pstNextTask);	/* Haven't gone through the entire list */
	
	
	
	
	
	
	pstEnd 		= HeadNode->Next;
	pstNextTask = HeadNode->Next;
	do 
	{
		/* If the task is ready to run */
		if  (pstNextTask->Task .TaskState == TASK_READY)
		{
			if (pstNextTask-> Task . FirstDelay==0) 
			{
			/* and the priority is > highest priority */
			if (pstNextTask-> Task .Priority == HighPri)
			{
				/* Assign the priority level to run */
				HighPri = pstNextTask-> Task . Priority;
				pstNextTask-> Task . TaskFunc();
				pstNextTask-> Task . FirstDelay=pstNextTask-> Task . periodicity;
				break;
			}
			}
		}

		/* Next in the list */
		pstNextTask = pstNextTask->Next;

	} while (pstEnd != pstNextTask);	/* Haven't gone through the entire list */
	


	pstEnd = HeadNode->Next;
	pstNextTask = HeadNode->Next;
	do 
	{
		/* If the task is ready to run */
		if  (pstNextTask-> Task . TaskState == TASK_READY)
		{
			if (pstNextTask-> Task . FirstDelay!=0)
			{
			pstNextTask-> Task . FirstDelay--;
			
			}
		}

		/* Next in the list */
		pstNextTask = pstNextTask->Next;

	} while (pstEnd != pstNextTask);	/* Haven't gone through the entire list */
	
	}



/*****************************************************************************************************************************************
* @brief Suspend a task from running
*
* @param Copy_u8task_ID	--> Copy_u8task_ID Unique ID of the task
* @return state_t SUCCESS on success, FAIL on failure
*****************************************************************************************************************************************/

State_t OS_sttSuspendTask(u8 Copy_u8task_ID )
{
	u8 returnState = FAIL;

	 /* Valid Range */
	if ( (Copy_u8task_ID <= MaxID) && (Copy_u8task_ID > 0) )
	{
		Task_t *pstEnd;
		Task_t *pstNextTask;


		pstEnd = HeadNode->Next;
		pstNextTask = HeadNode->Next;
		do
		{
			/* If the task ID equal to the entered ID */
			if  (pstNextTask-> Task . task_ID == Copy_u8task_ID )
			{
				/* change the task state to suspended */
				pstNextTask-> Task . TaskState= TASK_SUSPENDED;
			}

			/* Next in the list */
			pstNextTask = pstNextTask->Next;

		} while (pstEnd != pstNextTask);	/* Haven't gone through the entire list */

		returnState = SUCCESS;
	}
	else
	{
		returnState = FAIL;
	}

	return returnState ;
}

/*****************************************************************************************************************************************
* @brief Set a task as ready to run
*
* @param Copy_u8task_ID	--> Copy_u8task_ID Unique ID of the task
* @return state_t SUCCESS on success, FAIL on failure
*****************************************************************************************************************************************/

State_t OS_sttResumeTask(u8 Copy_u8task_ID)
{
	u8 returnState = FAIL;

	 /* Valid Range */
	if ( (Copy_u8task_ID <= MaxID) && (Copy_u8task_ID > 0) )
	{
		Task_t *pstEnd;
		Task_t *pstNextTask;


		pstEnd = HeadNode->Next;
		pstNextTask = HeadNode->Next;
		do
		{
			/* If the task ID equal to the entered ID */
			if  (pstNextTask-> Task . task_ID == Copy_u8task_ID )
			{
				/* change the task state to resumed */
				pstNextTask-> Task . TaskState= TASK_READY;
			}

			/* Next in the list */
			pstNextTask = pstNextTask->Next;

		} while (pstEnd != pstNextTask);	/* Haven't gone through the entire list */

		returnState = SUCCESS;
	}
	else
	{
		returnState = FAIL;
	}

	return returnState ;
}

/*****************************************************************************************************************************************
* @brief Remove a task from the scheduler list
*
* @param Copy_u8task_ID	--> Copy_u8task_ID Unique ID of the task
* @return state_t TRUE on success, FAIL on failure
*****************************************************************************************************************************************/

State_t OS_sttDeleteTask(u8 Copy_u8task_ID)
{
	u8 returnState = FAIL;
	
	 /* Valid Range */
	if ( (Copy_u8task_ID <= MaxID) && (Copy_u8task_ID > 0) )
	{
		Task_t *pstEnd;
		Task_t *pstPrev;
		Task_t *pstCurr;


		pstPrev = HeadNode;
		pstCurr = HeadNode->Next;
		pstEnd  = HeadNode->Next;


		do
		{
			/* If the task ID equal to the entered ID */
			if  (pstCurr-> Task . task_ID == Copy_u8task_ID )
			{
				/* Remove the target from the circularly linked list */
				pstPrev -> Next = pstCurr -> Next;
				
				/*release the allocated memory*/
				free (pstCurr);
				
				returnState = SUCCESS;
				break;
			}
			else
			{
			/* Next in the list */
				pstPrev = pstCurr;
				pstCurr = pstCurr -> Next;
			}
		} while (pstEnd != pstCurr);	/* Haven't gone through the entire list */

		returnState = FAIL;
	}
	else
	{
		returnState = FAIL;
	}

	return returnState ;
}

