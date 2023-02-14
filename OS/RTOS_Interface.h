

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_



void OS_vidStart(void);

void OS_vidCreateTask(u8 Copy_u8Periority , u16 Copy_u16Periodicity ,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay);

#endif /* RTOS_INTERFACE_H_ */
