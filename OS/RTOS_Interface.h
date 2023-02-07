/*
 * RTOS_Interface.h
 *
 *  Created on: 2 Feb 2023
 *      Author: nour
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_



void OS_vidStart(void);

void OS_vidCreateTask(u8 Copy_u8Periority , u16 Copy_u16Periodicity ,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay);

void OS_vidSuspendTask(u8 Copy_u8Periority);

void OS_vidResumeTask(u8 Copy_u8Periority);

void OS_vidDeleteTask(u8 Copy_u8Periority);


void OS_vidSemaphoreCreateBinary(Semaphore_t* Semaphore);

u8 OS_u8SemaphoreTake(Semaphore_t *Semaphore);

void OS_vidSemaphoreGive(Semaphore_t* Semaphore);

void OS_vidSemaphoreCreateCounting(CountingSemaphore_t* Semaphore , u8 MaxCount , u8 InitialCount);

u8 OS_u8CountingSemaphoreTake(CountingSemaphore_t *Semaphore);

void OS_vidCountingSemaphoreGive(CountingSemaphore_t* Semaphore);

void OS_vidMutexCreate(Mutex_t* Mutex , u8 Num_of_Tasks , u8 * ptr_to_tasks_periorities );

u8 OS_u8MutexTake(Mutex_t* Mutex ,u8 Task_ID );

void OS_vidMutexGive(Mutex_t* Mutex ,u8 Task_ID );

#endif /* RTOS_INTERFACE_H_ */
