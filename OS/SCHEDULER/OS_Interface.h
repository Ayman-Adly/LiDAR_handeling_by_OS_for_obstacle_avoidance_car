/********************************************************************************************
 * @file   OS_Interface.h
 * @author Moamen Ehab Mohamed / Ehab Ashraf
 * @brief This is the OS_Interface.h file for the functions that OS support .
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
**********************************************************************************************/
#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_
/*********************************************************************************************************************************************/
/*@brief		 this function is used to start the opertaing system.
*this is Detailed Disc
*@param		 void
*@return	 void
*********************************************************************************************************************************************/
void OS_vidStart(void);
/*********************************************************************************************************************************************/
/*@brief		 this function is used to create task to be run in the system.
*this is Detailed Disc
*@param		 Copy_u8Periority               --> periority of the task in the system
*@param		 Copy_u16Periodicity 	        --> periodicity of the task in (ms)
*@param		 void (*Copy_pvTaskFunc)(void) 	--> this is pointer to task function
*@param		 Copy_u16FirstDelay 	        --> this is the time that task will be in waiting state at the start of the system in (ms)
*@return	 state_t                        --> this return must checked to know if the task created successfully or not
*********************************************************************************************************************************************/
State_t OS_sttCreateTask(u8 Copy_u8Periority , u16 Copy_u16Periodicity ,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay);
/*********************************************************************************************************************************************/
/*@brief		 this function is used to suspend task ( pushing the task to the waiting state)
*this is Detailed Disc
*@param		 Copy_u8task_ID                 --> task id and this id is returned from the task creation function (OS_vidCreateTask)
*@return	 state_t                        --> this return must checked to know if the task suspended successfully or not
*********************************************************************************************************************************************/
State_t OS_sttSuspendTask(u8 Copy_u8task_ID);
/*********************************************************************************************************************************************/
/*@brief		 this function is used to resume task ( make the task in the ready queue again )
*this is Detailed Disc
*@param		 Copy_u8task_ID                 --> task id and this id is returned from the task creation function (OS_vidCreateTask)
*@return	 state_t                        --> this return must checked to know if the task resumed successfully or not
*********************************************************************************************************************************************/
State_t OS_sttResumeTask(u8 Copy_u8task_ID);
/*********************************************************************************************************************************************/
/*@brief		 this function is used to delete task ( note that : deleting task means this task will not seen in ur system again (dormant state)
*this is Detailed Disc
*@param		 Copy_u8task_ID                 --> task id and this id is returned from the task creation function (OS_vidCreateTask)
*@return	 state_t                        --> this return must checked to know if the task deleted successfully or not
*********************************************************************************************************************************************/
State_t OS_sttDeleteTask(u8 Copy_u8task_ID);



#endif
