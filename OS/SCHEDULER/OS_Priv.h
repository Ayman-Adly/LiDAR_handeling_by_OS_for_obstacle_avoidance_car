/********************************************************************************************
 * @file   OS_Priv.h
 * @author Moamen Ehab Mohamed / Ehab Ashraf
 * @brief This is the OS_Priv.c file for the OS private enums , structs and schedular functions .
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
**********************************************************************************************/
#ifndef OS_PRIV_H_
#define OS_PRIV_H_



/*Target selections*/
#define AVR (0U)
#define ARM (1U)

/*this private enum used to define the state of task (suspended - resumed) */
typedef enum
{

TASK_SUSPENDE,
TASK_RESUMED

}TaskState_t;



/*this private struct used to save and define the task  of container of info
* 1-Periority				: periority of the task in the system
* 2-TempPeriority			: this temp variable is to save task priority for the tasks that will shre mutex with other tasks
* 3-periodicity				: periodicity os the task in (ms)
* 4-void (*TaskFunc)(void)	: this is pointer to task function
* 5-TaskState				: this var is to save the task state resumed or suspended
* 6-FirstDelay				: this is the time that task will be in waiting state at the start of the system in (ms)
* 7-task_ID					: this task id is unique for every task
*/
typedef struct
{

	u8 Periority		   ;
	u8 TempPeriority	   ;
	u16 periodicity        ;
	void (*TaskFunc)(void) ;
	TaskState_t TaskState  ;
	u16 FirstDelay	   	   ;
	u8 task_ID             ;
}Task_t;






/*********************************************************************************************************************************************/
/*@brief		 this private schedular function used to start schedular algorithm  to detect which task ready to run in the system depends on task
* 				 priority and periodicity
*this is Detailed Disc
*@param		 void
*@return	 void
/*********************************************************************************************************************************************/
static void vidSchedular(void);
/*********************************************************************************************************************************************/
/*@brief		this private function is used to sort the system tasks after creation against tasks priority
*this is Detailed Disc
*@param		 void
*@return	 void
/*********************************************************************************************************************************************/
static void OS_vidSystemTasksSort(void);

#endif
