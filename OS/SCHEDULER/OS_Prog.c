/********************************************************************************************
 * @file   OS_Prog.c
 * @author Moamen Ehab Mohamed / Ehab Ashraf
 * @brief This is the OS_Prog.c file for the OS_Interface.h function impelementation .
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 **********************************************************************************************/
#include <stdlib.h>
#include "../../LIB/STD_Types.h"

#include "../TIMER/Timer1_Interface.h"
#include "../GIE/GIE_Interface.h"

#include "OS_Priv.h"
#include "OS_Config.h"
#include "OS_Interface.h"
/*intial value of tasks id that incremented every time the user create new task*/
static u8 ID = 0;

/*this flag is set by timer interrupt and indicates of the the schedular algorithm time to run */
u8 Scheduler_flag;

/* create objects from Task type depends on the user selection of number of tasks in the
 RTOS_Config.h and initialize all Tasks with 0 to detect then if there are functions not created */
Task_t SystemTasks[TASK_NUM] = { { NULL } };

/*********************************************************************************************************************************************/
/*@brief		 this function is used to start the opertaing system.
 *this is Detailed Disc
 *@param		 void
 *@return	     void
 *********************************************************************************************************************************************/
void OS_vidStart(void)
{

#if(TARGET==AVR)

	/*Global interrupt enable*/
	GIE_vidEnable();
	/*Timer init -> CTC MODE - Prescaller - Enable compare match  interrupt */
	TIMER1_vidInit(OS_TICK);

#elif(TARGET==ARM)


#endif
	while (1)
	{
		/*check if this the schedular time to run or not*/
		if (Scheduler_flag == 1)
		{
			/*clear schedular flag*/
			Scheduler_flag = 0;
			/*run the schedular algorithm */
			vidScheduler();
		}
		else
		{
			/*if there is no task that is run in the system , run the ideal task*/
		}
	}

}

/*********************************************************************************************************************************************/
/*@brief		 this function is used to create task to be run in the system.
 *this is Detailed Disc
 *@param		 Copy_u8Periority               --> periority of the task in the system
 *@param		 Copy_u16Periodicity 	        --> periodicity os the task in (ms)
 *@param		 void (*Copy_pvTaskFunc)(void) 	--> this is pointer to task function
 *@param		 Copy_u16FirstDelay 	        --> this is the time that task will be in waiting state at the start of the system in (ms)
 *@return	 u8                             -->
 *********************************************************************************************************************************************/
u8 OS_sttCreateTask(u8 Copy_u8Periority, u16 Copy_u16Periodicity,void (*Copy_pvTaskFunc)(void), u16 Copy_u16FirstDelay)
{
	/*assign of the Task code func and periodicity of every task in the System_Tasks depends on it's periority   */
	u8 returnID = ID_INVALID;
	/*check if the user number of creation of task call equal to the number of tasks that he select in the OS_config or less*/
	/*if equal or less*/
	if (ID < TASK_NUM) {

		/*then create new task and start to assign the tasks info from that the user give  */
		SystemTasks[ID].Periority = Copy_u8Periority;

		SystemTasks[ID].TempPeriority = Copy_u8Periority;

		SystemTasks[ID].periodicity = Copy_u16Periodicity;

		SystemTasks[ID].TaskFunc = Copy_pvTaskFunc;

		SystemTasks[ID].TaskState = TASK_RESUMED;

		SystemTasks[ID].FirstDelay = Copy_u16FirstDelay;

		SystemTasks[ID].task_ID = ID;

		/*increase the number of tasks that user create by one */
		ID++;

		/*return the task id to the user */
		returnID = SystemTasks[ID].task_ID;

	}

	/*sorting system tasks against every task priority for one time only */
	OS_vidSystemTasksSort();

	return returnID;
}

static void vidScheduler(void) {

	/*task counter to check all the tasks wants to run at this tick*/
	static u8 TaskCounter;

	/*check which task wants to run at the current timer tick depends on the task periodicity  */
	for (TaskCounter = 0; TaskCounter < TASK_NUM; TaskCounter++) {
		/*check if the Task has First delay value to wait*/
		if (SystemTasks[TaskCounter].FirstDelay == 0) {

			/*check if the task is already created or not and another check of the task state to make sure that the task is resumed*/
			if (SystemTasks[TaskCounter].TaskFunc != NULL
					&& SystemTasks[TaskCounter].TaskState == TASK_RESUMED) {
				SystemTasks[TaskCounter].TaskFunc();
				/*assign the Periodicity -1 to the first delay because the Task now ready to run periodically after completing its first delay of waiting*/
				SystemTasks[TaskCounter].FirstDelay =
						SystemTasks[TaskCounter].periodicity - 1;
			} else {
				/*do nothing*/
			}

		} else {
			/*decrease the first delay value by 1 */
			SystemTasks[TaskCounter].FirstDelay--;
		}

	}

}
/*********************************************************************************************************************************************/
/*@brief		 this function is used to suspend task ( pushing the task to the waiting state)
 *this is Detailed Disc
 *@param	 Copy_u8task_ID                 --> task id and this id is returned from the task creation function (OS_vidCreateTask)
 *@return	 u8                             -->
 *********************************************************************************************************************************************/
State_t OS_sttSuspendTask(u8 Copy_u8task_ID) {

	State_t state = STATE_SUCCESS;
	/*loop to the all tasks of the system to find which task has the same task id that user give*/
	for (u8 counter = 0; counter <= ID; counter++) {
		if (SystemTasks[counter].task_ID == Copy_u8task_ID) {
			/*changing the task state to TASK_SUSPENDE*/
			SystemTasks[counter].TaskState = TASK_SUSPENDE;
		} else {
			state = STATE_FAIL;
		}

	}
	return state;
}
/*********************************************************************************************************************************************/
/*@brief		 this function is used to resume task ( make the task in the ready queue again )
 *this is Detailed Disc
 *@param	 Copy_u8task_ID                 --> task id and this id is returned from the task creation function (OS_vidCreateTask)
 *@return	 State_t
 *********************************************************************************************************************************************/
State_t OS_sttResumeTask(u8 Copy_u8task_ID) {
	State_t state = STATE_SUCCESS;
	/*loop to the all tasks of the system to find which task has the same task id that user give*/
	for (u8 counter = 0; counter <= ID; counter++) {
		if (SystemTasks[counter].task_ID == Copy_u8task_ID) {
			/*changing the task state to TASK_RESUMED*/
			SystemTasks[counter].TaskState = TASK_RESUMED;
		} else {
			state = STATE_FAIL;
		}
	}
	return state;
}

State_t OS_sttDeleteTask(u8 Copy_u8task_ID) {
	State_t state = STATE_SUCCESS;
	/*loop to the all tasks of the system to find which task has the same task id that user give*/
	for (u8 counter = 0; counter <= ID; counter++) {
		if (SystemTasks[counter].task_ID == Copy_u8task_ID) {
			/*making the task FUNC equal to NULL*/
			SystemTasks[counter].TaskFunc = NULL;
		} else {
			state = STATE_FAIL;
		}
	}
	return state;
}

/*********************************************************************************************************************************************/
/*@brief		 this function is used to delete task ( note that : deleting task means this task will not seen in ur system again (dormant state)
 *this is Detailed Disc
 *@param     Copy_u8task_ID                 --> task id and this id is returned from the task creation function (OS_vidCreateTask)
 *@return	 u8                             -->
 *********************************************************************************************************************************************/
static void OS_vidSystemTasksSort(void) {
	/*create temp of type task*/
	Task_t temp_task;

	/*apply sorting algorithm to the tasks the user created to sort the tasks priority*/
	for (u8 counter1 = 0; counter1 <= ID; counter1++) {
		for (u8 counter2 = counter1 + 1; counter2 <= ID - 1; counter2++) {

			if (SystemTasks[counter1].Periority
					> SystemTasks[counter2].Periority) {
				temp_task = SystemTasks[counter1];
				SystemTasks[counter1] = SystemTasks[counter2];
				SystemTasks[counter2] = temp_task;
			}
		}

	}

}

