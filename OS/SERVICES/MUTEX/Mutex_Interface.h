/********************************************************************************************
 * @file   Mutex_Interface.h
 * @author Moamen Ehab Mohamed
 * @brief This is the Mutex_Interface.h file for the supported function on Mutex  .
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
**********************************************************************************************/

#ifndef MUTEX_INTERFACE_H_
#define MUTEX_INTERFACE_H_


/*this private struct used to save and define the mutex  of container of info
* 1-MaxPeriority			: max priority of all tasks periority that share this mutex in the system
* 2-MutexState				: this is mutex state if is taken or avillable
*/
typedef struct
{

	u8 MaxPeriority         ;
	u8 MutexState     	    ;

}Mutex_t;

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
void OS_vidMutexCreate(Mutex_t* Mutex , u8 Num_of_Tasks , u8 * ptr_to_tasks_periorities );
/*********************************************************************************************************************************************/
/*@brief		 this function is used to take the mutex and u must check the return of this function to know if the task has the ability
* 				 to take the mutex successfully or not (if not this mean mutex is already taken by another task  )
*this is Detailed Disc
*@param		 Mutex_t* Mutex               --> this is pointer to mutex object u should pass this mutex by address to the function
*@param		 Task_ID					  --> this is the id of the task that want to take this mutex
*@return	 u8                           --> check if the counting mutex is taken successfully or not if 1 this means the task successed to take
*           								  the mutex if 0 this means task failed to take the mutex
*********************************************************************************************************************************************/
u8 OS_u8MutexTake(Mutex_t* Mutex ,u8 Task_ID );
/*********************************************************************************************************************************************/
/*@brief		 this function is used to free mutex object and give the ability to another task to take
*this is Detailed Disc
*@param		 Mutex_t* Mutex               --> this is pointer to mutex object u should pass this mutex by address to the function
*@param		 Task_ID					  --> this is the id of the task that want to take this mutex *@return	 void
*@return	 void
*********************************************************************************************************************************************/
void OS_vidMutexGive(Mutex_t* Mutex ,u8 Task_ID );

#endif
