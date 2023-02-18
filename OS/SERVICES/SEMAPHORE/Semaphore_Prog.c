/********************************************************************************************
 * @file   Semaphore_Prog.c
 * @author Moamen Ehab Mohamed
 * @brief This is the Semaphore_Prog.c file for the Semaphore_Interface.h impelmentation of the semaphore functions  .
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 **********************************************************************************************/





#include "../../../LIB/STD_Types.h"

#include "Semaphore_Priv.h"

#include "Semaphore_Interface.h"


/*********************************************************************************************************************************************/
/*@brief		 this function is used to intialize binary semphore object and make it ready to use in your system
 *this is Detailed Disc
 *@param     Semaphore_t*                 --> this is pointer to binary semphore object u should create object of type Semaphore_t and pass this semphore
 *	 					           			  by address to the function
 *@return	 u8                           -->
 *********************************************************************************************************************************************/
void OS_vidSemaphoreCreateBinary(Semaphore_t * Semaphore) {
	/*intialize the state of semaphore to be avillable  */
	Semaphore->SemaphoreState = SEMAPHORE_MUTEX_AVILABLE;
}

/*********************************************************************************************************************************************/
/*@brief		 this function is used to aquire the semaphore and u must check the return of this function to know if the task has the ability
 * 				 to take the semaphore successfully or not (if not this mean semaphore is already taken by another task  )
 *this is Detailed Disc
 *@param		 Semaphore_t*             --> this is pointer to semphore object u should pass this semphore by address to the function
 *@return	 u8                           --> check if the semphore is taken successfully or not if 1 this means the task successed to take
 *           								  the semaphore if 0 this means task failed to take the semaphore
 *********************************************************************************************************************************************/
State_t OS_u8BinarySemaphoreTake(Semaphore_t * Semaphore) {

	/*create service_state var and intialize it to be fail */
	State_t ServiceState = STATE_FAIL;

	/*check the semphore is avillable or not*/
	if (Semaphore->SemaphoreState == SEMAPHORE_MUTEX_AVILABLE) {
		/*the task succussesd to take the semaphor then change the semaphore state to be taken  */
		Semaphore->SemaphoreState = SEMAPHORE_MUTEX_TAKEN;
		/*change service_state var to be pass */
		ServiceState = STATE_SUCCESS;
	}
	/*return the ServiceState*/
	return ServiceState;
}
/*********************************************************************************************************************************************/
/*@brief		 this function is used to free binary semphore object and give the ability to another task to take
 *this is Detailed Disc
 *@param		 Semaphore_t*                 --> this is pointer to semphore object u should pass this semphore by address to the function
 *@return	 void
 *********************************************************************************************************************************************/
void OS_vidBinarySemaphoreGive(Semaphore_t * Semaphore) {

	/*change the semaphore state to be avillable */
	Semaphore->SemaphoreState = SEMAPHORE_MUTEX_AVILABLE;

}
/*********************************************************************************************************************************************/
/*@brief		 this function is used to intialize counting semphore object and make it ready to use in your system
 *this is Detailed Disc
 *@param		 Semaphore_t*             --> this is pointer to counting semphore object u should create object of type CountingSemaphore_t and pass this semphore
 *	 					           			  by address to the function
 *@param		 MaxCount                 -->this is maximum number of tasks that can share the resource or the counting semaphore
 *@param		 Semaphore_t*             -->this is number is represent number of tasks that intially taking the semaphore
 *@return	     void
 *********************************************************************************************************************************************/

void OS_vidSemaphoreCreateCounting(CountingSemaphore_t* Semaphore, u8 MaxCount,
		u8 InitialCount) {

	/*intialize the max num of tasks the can share this semaphore */
	Semaphore->MaxCount = MaxCount;
	/*this is number is represent number of tasks that intially taking the semaphore*/
	Semaphore->InitialCount = InitialCount;

}

/*********************************************************************************************************************************************/
/*@brief		 this function is used to aquire the semaphore and u must check the return of this function to know if the task has the ability
 * 				 to take the semaphore successfully or not (if not this mean semaphore is already taken by another task  )
 *this is Detailed Disc
 *@param	 Semaphore_t*             --> this is pointer to counting semphore object u should pass this semphore by address to the function
 *@return	 u8                       --> check if the counting semphore is taken successfully or not if 1 this means the task successed to take
 *           							  the semaphore if 0 this means task failed to take the semaphore
 *********************************************************************************************************************************************/
u8 OS_u8CountingSemaphoreTake(CountingSemaphore_t *Semaphore) {
	/*create countingservice_state var and intialize it to be fail */
	u8 CountingSemaphore_State = STATE_FAIL;
	/*increase the the num of task that currentlly shared the resource by one*/
	Semaphore->InitialCount++;
	/*check if there is a place for another function to share the semphore or the resource or not*/
	if (Semaphore->MaxCount >= Semaphore->InitialCount) {
		/*change service_state var to be pass */
		CountingSemaphore_State = STATE_SUCCESS;
	} else {
		/*if the count val increased by one make the the intaila val more than maxcount then decrease the intiial count */
		Semaphore->InitialCount--;
	}
	/*return the counting semaphore state */
	return CountingSemaphore_State;

}
/*********************************************************************************************************************************************/
/*@brief		 this function is used to free binary place at the counting semphore object and give the ability to another task to take
 *this is Detailed Disc
 *@param	 Semaphore_t*                 --> this is pointer to counting semphore object u should pass this semphore by address to the function
 *@return	 void
 *********************************************************************************************************************************************/
void OS_vidCountingSemaphoreGive(CountingSemaphore_t* Semaphore) {

	/*decrease the sum of tasks that shared that currently shared the counting semaphore by one*/
	Semaphore->InitialCount--;

}

