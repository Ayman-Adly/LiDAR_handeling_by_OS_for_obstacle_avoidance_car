/*
 * main.c
 *
 *  Created on: 14 Dec 2022
 *      Author: nour
 */
#include "Types.h"
#include "bitmath.h"
#include "Timer0_Config.h"
#include "Timer0_Interface.h"
#include "DIO_Interface.h"
#include "DIO_Priv.h"
#include "GIE_Interface.h"
#include "avr/interrupt.h"
#include "avr/delay.h"
#include "LCD_config.h"
#include "LCD_Interface.h"
#include "RTOS_Priv.h"
#include "RTOS_Config.h"
#include "RTOS_Interface.h"
#include "MailBox_Interface.h"

extern Task_t SystemTasks[TASK_NUM];
Semaphore_t s1;
CountingSemaphore_t s2;
Mutex_t M;
void TASK1(void);
void TASK2(void);
void TASK3(void);

Mailbox M1;
int main()
{


	OS_enuMailbox_Create(&M1,1);

LCD_vidInit();


OS_vidCreateTask(0, 1000, &TASK1,0);
OS_vidCreateTask(0, 1000, &TASK2,1000);
//OS_vidCreateTask(2, 1000, &TASK3,0);

OS_vidStart();

while(1)
{


}
return 0;
}


void TASK1(void)
{
	LCD_vidGoToXY(0,0);
LCD_vidSendString("IAM TASK 1");
_delay_ms(1000);
}


void TASK2(void)
{
	LCD_vidGoToXY(1,0);
	LCD_vidSendString("IAM TASK 2");
	_delay_ms(1000);
}

//void TASK3(void)
//{
//
//	u8 send=6;
//	OS_enuMailbox_Send(&M1,&send,1);
//
//}
