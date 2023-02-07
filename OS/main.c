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


extern Task_t SystemTasks[TASK_NUM];
Semaphore_t s1;
CountingSemaphore_t s2;
Mutex_t M;
void TASK1(void);
void TASK2(void);
void TASK3(void);



int main()
{
LCD_vidInit();
LCD_vidGoToXY(0, 0);
//LCD_vidSendString("T1:");
LCD_vidSendString("T pir BFR:");
LCD_vidGoToXY(0, 9);
//LCD_vidSendString("T2:");
LCD_vidGoToXY(1, 0);
//LCD_vidSendString("T3:");
LCD_vidSendString("T pir AFT:");

OS_vidSemaphoreCreateBinary(&s1);

OS_vidSemaphoreCreateCounting(&s2, 2, 0);

u8 arr[3]={0,1,2};
OS_vidMutexCreate(&M, 3,arr);

DIO_vidSetPinDir(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
DIO_vidSetPinDir(DIO_PORTA, DIO_PIN1, DIO_OUTPUT);
DIO_vidSetPinDir(DIO_PORTA, DIO_PIN2, DIO_OUTPUT);
//DIO_vidSetPinVal(DIO_PORTA, DIO_PIN0, 1);

OS_vidCreateTask(0, 1000, &TASK1,0);
OS_vidCreateTask(1, 2000, &TASK2,0);
OS_vidCreateTask(2, 3000, &TASK3,0);

OS_vidStart();
while(1)
{


}
return 0;
}


void TASK1(void)
{
static counter=0;
counter++;
//u8 x=OS_u8SemaphoreTake(&s1);



//static u8 x=0;
//
//if(x==0){x=OS_u8CountingSemaphoreTake(&s2);}
LCD_vidGoToXY(0, 13);
LCD_vidSendChar(SystemTasks[0].Periority+48);
u8 x=OS_u8MutexTake(&M, 0);
static u8 flag=0;
flag=flag^1;
DIO_vidSetPinVal(DIO_PORTA, DIO_PIN0, flag);
if(x==1)
{
	//LCD_vidPrintInit(counter, 0, 5);
//OS_vidCountingSemaphoreGive(&s2);
}
LCD_vidGoToXY(1, 13);
LCD_vidSendChar(SystemTasks[0].Periority+48);
}


void TASK2(void)
{
	static counter=0;
	counter++;
	static u8 flag=0;
	flag=flag^1;
	DIO_vidSetPinVal(DIO_PORTA, DIO_PIN1, flag);
	static u8 x=0;

	if(x==0){x=OS_u8CountingSemaphoreTake(&s2);}
//	if(x==1)
//	{
//		LCD_vidPrintInit(counter, 0, 13);

		//OS_vidCountingSemaphoreGive(&s2);
	//}

}
void TASK3(void)
{
	static counter=0;
	counter++;
	static u8 flag=0;
	flag=flag^1;
	DIO_vidSetPinVal(DIO_PORTA, DIO_PIN2, flag);
	static u8 x=0;

	if(x==0){x=OS_u8CountingSemaphoreTake(&s2);}
//	if(x==1)
//	{
//	LCD_vidPrintInit(counter, 1, 5);
//	OS_vidCountingSemaphoreGive(&s2);
//	}

}

