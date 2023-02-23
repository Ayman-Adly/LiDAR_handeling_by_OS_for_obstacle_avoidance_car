/********************************************************************************************
 * @file   OS_Config.h
 * @author Moamen Ehab Mohamed / Ehab Ashraf
 * @brief This is the OS_Config.h file for the user to configure the system number of tasks  .
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
**********************************************************************************************/
#ifndef OS_CONFIG_H_
#define OS_CONFIG_H_




/*here u can select the tasks number that u will create and run in the OS  */
#define TASK_NUM	(3)

/*write the system tick of the OS in ms*/
#define OS_TICK     (1)

/*select target*/
#define TARGET  AVR

#endif /* OS_CONFIG_H_ */
