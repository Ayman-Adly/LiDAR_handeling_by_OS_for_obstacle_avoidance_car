/********************************************************************************************
 * @file   Semaphore_Priv.h
 * @author Moamen Ehab Mohamed
 * @brief This is the Semaphore_Priv.h file for the private semaphore enums  .
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
**********************************************************************************************/


#ifndef SEMAPHORE_PRIV_H_
#define SEMAPHORE_PRIV_H_



/*this enum represents the semphore state if the semaphore is taken or available*/
typedef enum
{

SEMAPHORE_MUTEX_TAKEN,
SEMAPHORE_MUTEX_AVILABLE

}SemaphoreState_t;



#endif
