/********************************************************************************************
 * @file   Semaphore_Interface.h
 * @author Moamen Ehab Mohamed
 * @brief This is the Semaphore_Interface.h file for the supported function on semaphores  .
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
**********************************************************************************************/

#ifndef SEMAPHORE_INTERFACE_H_
#define SEMAPHORE_INTERFACE_H_

/*this private struct used to save and define the binary semahore  of container of info
* 1-SemaphoreState				: this is refer to binary semphore state taken or avillable
*/
typedef struct
{

	u8 SemaphoreState     	    ;

}Semaphore_t;

/*this private struct used to save and define the counting semahore  of container of info
* 1-MaxCount				: this is maximum number of tasks that can share the resource or the counting semaphore
* 2-InitialCount			: this is number is represent number of tasks that intially taking the semaphore
*/
typedef struct
{

	u8 MaxCount     	    ;
	u8 InitialCount         ;

}CountingSemaphore_t;

/*********************************************************************************************************************************************/
/*@brief		 this function is used to intialize binary semphore object and make it ready to use in your system
*this is Detailed Disc
*@param		 Semaphore_t*                 --> this is pointer to binary semphore object u should create object of type Semaphore_t and pass this semphore
*	 					           			  by address to the function
*@return	 u8                           -->
*********************************************************************************************************************************************/
void OS_vidSemaphoreCreateBinary(Semaphore_t* Semaphore);
/*********************************************************************************************************************************************/
/*@brief		 this function is used to aquire the semaphore and u must check the return of this function to know if the task has the ability
* 				 to take the semaphore successfully or not (if not this mean semaphore is already taken by another task  )
*this is Detailed Disc
*@param		 Semaphore_t*                 --> this is pointer to semphore object u should pass this semphore by address to the function
*@return	 u8                           --> check if the semphore is taken successfully or not if 1 this means the task successed to take
*           								  the semaphore if 0 this means task failed to take the semaphore
*********************************************************************************************************************************************/
u8 OS_u8BinarySemaphoreTake(Semaphore_t *Semaphore);
/*********************************************************************************************************************************************/
/*@brief		 this function is used to free binary semphore object and give the ability to another task to take
*this is Detailed Disc
*@param		 Semaphore_t*                 --> this is pointer to semphore object u should pass this semphore by address to the function
*@return	 void
*********************************************************************************************************************************************/
void OS_vidBinarySemaphoreGive(Semaphore_t* Semaphore);
/*********************************************************************************************************************************************/
/*@brief		 this function is used to intialize counting semphore object and make it ready to use in your system
*this is Detailed Disc
*@param		 Semaphore_t*                 --> this is pointer to counting semphore object u should create object of type CountingSemaphore_t and pass this semphore
*	 					           			  by address to the function
*@param		 MaxCount                     -->this is maximum number of tasks that can share the resource or the counting semaphore
*@param		 Semaphore_t*                 -->this is number is represent number of tasks that intially taking the semaphore
*@return	 void
*********************************************************************************************************************************************/
void OS_vidSemaphoreCreateCounting(CountingSemaphore_t* Semaphore , u8 MaxCount , u8 InitialCount);
/*********************************************************************************************************************************************/
/*@brief		 this function is used to aquire the semaphore and u must check the return of this function to know if the task has the ability
* 				 to take the semaphore successfully or not (if not this mean semaphore is already taken by another task  )
*this is Detailed Disc
*@param		 Semaphore_t*                 --> this is pointer to counting semphore object u should pass this semphore by address to the function
*@return	 u8                           --> check if the counting semphore is taken successfully or not if 1 this means the task successed to take
*           								  the semaphore if 0 this means task failed to take the semaphore
*********************************************************************************************************************************************/
u8 OS_u8CountingSemaphoreTake(CountingSemaphore_t *Semaphore);
/*********************************************************************************************************************************************/
/*@brief		 this function is used to free binary place at the counting semphore object and give the ability to another task to take
*this is Detailed Disc
*@param		 Semaphore_t*                 --> this is pointer to counting semphore object u should pass this semphore by address to the function
*@return	 void
*********************************************************************************************************************************************/
void OS_vidCountingSemaphoreGive(CountingSemaphore_t* Semaphore);




#endif
