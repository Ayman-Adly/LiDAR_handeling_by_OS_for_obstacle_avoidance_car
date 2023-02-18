/********************************************************************************************
 * @file   Mutex_Prog.c
 * @author Moamen Ehab Mohamed
 * @brief This is the Mutex_Prog file for Mutex_Interface.h functions implemantation .
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 **********************************************************************************************/





#include "../../../LIB/STD_Types.h"
#include "../../SCHEDULER/OS_Priv.h"
#include  "../../SCHEDULER/OS_Config.h"
#include "Mutex_Priv.h"
#include "Mutex_Interface.h"

/*extern the array of tasks */
extern Task_t SystemTasks[TASK_NUM];

/*********************************************************************************************************************************************/
/*@brief		 this function is used to intialize mutex object and make it ready to use in your system
 *this is Detailed Disc
 *@param		 Semaphore_t*                 --> this is pointer to counting mutex object u should create object of type Mutex_t and pass this semphore
 *	 					           			  by address to the function
 *@param		 Num_of_Tasks                 -->this is the number of tasks that can take this mutex in the system
 *@param		u8 * ptr_to_tasks_periorities -->this is pointer to array of tasks priority u must create  array of size refer to num of task that
 *@param										 can share the mutex and fill this array by the tasks priority
 *@return	 void
 *********************************************************************************************************************************************/
void OS_vidMutexCreate(Mutex_t* Mutex, u8 Num_of_Tasks,
		u8 * ptr_to_tasks_periorities) {
	/*change the semphore state to be avaliable*/
	Mutex->MutexState = MUTEX_AVILABLE;

	/*intialize the maximum priority to be equal to the first periority value in the array of priority that user pass*/
	u8 MaxPeriority = ptr_to_tasks_periorities[0];

	/*linear search of the array max priority element to be assigned to max periority of the system */
	for (u8 counter = 0; counter < Num_of_Tasks - 1; counter++) {

		if (ptr_to_tasks_periorities[counter]
				> ptr_to_tasks_periorities[counter + 1]) {
			MaxPeriority = ptr_to_tasks_periorities[counter];
		} else {
			MaxPeriority = ptr_to_tasks_periorities[counter + 1];
		}
		Mutex->MaxPeriority = MaxPeriority;

	}

}
/*********************************************************************************************************************************************/
/*@brief		 this function is used to take the mutex and u must check the return of this function to know if the task has the ability
 * 				 to take the mutex successfully or not (if not this mean mutex is already taken by another task  )
 *this is Detailed Disc
 *@param		 Mutex_t* Mutex               --> this is pointer to mutex object u should pass this mutex by address to the function
 *@param		 Task_ID					  --> this is the id of the task that want to take this mutex
 *@return	 u8                           --> check if the counting mutex is taken successfully or not if 1 this means the task successed to take
 *           								  the mutex if 0 this means task failed to take the mutex
 *********************************************************************************************************************************************/
State_t OS_u8MutexTake(Mutex_t* Mutex, u8 Task_ID) {

	/*create ServiceState var and intialize it to be fail*/
	State_t ServiceState = STATE_FAIL;
	/*check if the mutex is avillable or not*/
	if (Mutex->MutexState == MUTEX_AVILABLE) {
		/*make the task priority to be equal to the maximum task priority that share this resource */
		SystemTasks[Task_ID].Periority = Mutex->MaxPeriority;

		/*change mutex state to be taken*/
		Mutex->MutexState = MUTEX_TAKEN;
		/*change the srevice state to be pass*/
		ServiceState = STATE_SUCCESS;
	}
	/*return service state*/
	return ServiceState;

}
/*********************************************************************************************************************************************/
/*@brief		 this function is used to free mutex object and give the ability to another task to take
 *this is Detailed Disc
 *@param		 Mutex_t* Mutex               --> this is pointer to mutex object u should pass this mutex by address to the function
 *@param		 Task_ID					  --> this is the id of the task that want to take this mutex
 *@return	 void
 *********************************************************************************************************************************************/
void OS_vidMutexGive(Mutex_t* Mutex, u8 Task_ID) {
	/*return the task periority to  be equal to the task own priority */
	SystemTasks[Task_ID].Periority = SystemTasks[Task_ID].TempPeriority;
	/*change the mutex state to be avilablle */
	Mutex->MutexState = MUTEX_AVILABLE;

}
