/*********************************************************************************************
 * @file 	OS_Interface.h
 * @author 	Ehap Ashraf / Moamen Ehap 
 * @brief 	This is the OS_Interface.h file for defining function implementations . 
 * @version 0.0.0
 * @date 	2-17-2023 (Date of documenting)
 *
 *********************************************************************************************/
#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_


/*****************************************************************************************************************************************/
/************************************************ Public Functions ***********************************************************************/
/*****************************************************************************************************************************************/

/*****************************************************************************************************************************************
* @brief Start the scheduler
*
*****************************************************************************************************************************************/
void OS_vidStart(void);

/*****************************************************************************************************************************************
* @brief Add a task to the scheduler list
*
* @param Copy_u8Periority			--> Copy_u8Priority priority of the task (0-255)
* @param Copy_u16Periodicity		--> Copy_u16Periodicity periodicity of the task
* @param (*Copy_pvTaskFunc)(void)	--> Copy_pvTaskFunc pointer to the task's entry function
* @param Copy_u16FirstDelay			--> Copy_u16FirstDelay first delay of the task
* @return u8 ID on success, FAIL on failure
*****************************************************************************************************************************************/
u8 OS_u8CreateTask(u8 Copy_u8Periority , u16 Copy_u16Periodicity ,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay);

/*****************************************************************************************************************************************
* @brief Suspend a task from running
*
* @param Copy_u8task_ID	--> Copy_u8task_ID Unique ID of the task
* @return state_t SUCCESS on success, FAIL on failure
*****************************************************************************************************************************************/

State_t OS_sttSuspendTask(u8 Copy_u8task_ID);


/*****************************************************************************************************************************************
* @brief Set a task as ready to run
*
* @param Copy_u8task_ID	--> Copy_u8task_ID Unique ID of the task
* @return state_t SUCCESS on success, FAIL on failure
*****************************************************************************************************************************************/

State_t OS_sttResumeTask(u8 Copy_u8task_ID);

/*****************************************************************************************************************************************
* @brief Remove a task from the scheduler list
*
* @param Copy_u8task_ID	--> Copy_u8task_ID Unique ID of the task
* @return state_t TRUE on success, FAIL on failure
*****************************************************************************************************************************************/
State_t OS_sttDeleteTask(u8 Copy_u8task_ID);

#endif /* RTOS_INTERFACE_H_ */
