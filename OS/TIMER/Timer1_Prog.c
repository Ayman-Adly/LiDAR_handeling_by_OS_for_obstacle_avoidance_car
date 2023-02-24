
#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Manipulation.h"

#include "Timer1_Priv.h"
#include "Timer1_Interface.h"
#include "avr/interrupt.h"
#include "../SCHEDULER/OS_Config.h"
extern u8 Scheduler_flag;

#if(TARGET==AVR)




/***************************************************************************************/
/*                          01- void TIMER1_vidInit(void)                              */
/*-------------------------------------------------------------------------------------*/
/* @fu TIMER1_vidInit                                                                  */
/* @brief  This Function is used to initialize timer 1                                 */
/*             - set timer1 Mode                                                       */
/*             - set timer 1 Prescaller                                                */
/*             - Enable Timer1 interrupt                                               */
/* @param[out] : void                                                                  */
/* @param[in]  : void                                                                  */
/***************************************************************************************/
void TIMER1_vidInit(u8 system_tick)
{
	/*select timer mode*/
	TIMER1_vidSetMode();

	/*select clock or prescaler */
	TIMER1_vidSetTimer1Prescaller();

	/*set compare match val */
	TIMER1_vidSetOCR1AComparMatchVal(system_tick * 125);

	/*Enable Timer1 Interrupt*/
	SET_BIT(TIMSK_REG, OCIE1A);
}
/***************************************************************************************/
/*              static void TIMER1_vidSetOCR1AComparMatchVal(u16 CompareMatchVal)      */
/*-------------------------------------------------------------------------------------*/
/* @fu TIMER1_vidInit                                                                  */
/* @brief  This Function is used to set compare match val of timer 1                   */
/* @param[out] : void                                                                  */
/* @param[in]  : u16 CompareMatchVal                                                   */
/***************************************************************************************/
static void TIMER1_vidSetOCR1AComparMatchVal(u16 CompareMatchVal)
{
	/*putting the compare match value in the OCR1A register*/
	OCR1A_REG = CompareMatchVal;
}

/***************************************************************************************/
/*              static void TIMER1_vidSetOCR1AComparMatchVal(u16 CompareMatchVal)      */
/*-------------------------------------------------------------------------------------*/
/* @fu TIMER1_vidInit                                                                  */
/* @brief  This Function is used to set   timer 1  mode                                */
/* @param[out] : void                                                                  */
/* @param[in]  : void                                                                  */
/***************************************************************************************/

static void TIMER1_vidSetMode(void)
{

	/*selecting CTC mode*/
	CLR_BIT(TCCR1A_REG, WGM10);
	CLR_BIT(TCCR1A_REG, WGM11);
	SET_BIT(TCCR1B_REG, WGM12);
	CLR_BIT(TCCR1B_REG, WGM13);

}
/***************************************************************************************/
/*              static void TIMER1_vidSetTimer1Prescaller(void)                        */
/*-------------------------------------------------------------------------------------*/
/* @fu TIMER1_vidInit                                                                  */
/* @brief  This Function is used to set   timer 1  prescaller                          */
/* @param[out] : void                                                                  */
/* @param[in]  : void                                                                  */
/***************************************************************************************/
static void TIMER1_vidSetTimer1Prescaller(void)
{
	/*selecting prescaller of 64 now we have MHZ clock freq*/
	SET_BIT(TCCR1B_REG, CS10);
	SET_BIT(TCCR1B_REG, CS11);
	CLR_BIT(TCCR1B_REG, CS12);

}
/***************************************************************************************/
/*              static void TIMER1_vidSetTimer1Prescaller(void)                        */
/*-------------------------------------------------------------------------------------*/
/* @fu TIMER1_vidInit                                                                  */
/* @brief  This Function is used to set   timer 1  prescaller                          */
/* @param[out] : void                                                                  */
/* @param[in]  : void                                                                  */
/***************************************************************************************/



#elif(TARGET==ARM)

/* MSTK_voidInit : select the systick clock source , Disable the STK and Disable the STK interrupt */

/***************************************************************************************/
/*              void MSTK_voidInit(void)                                               */
/*-------------------------------------------------------------------------------------*/
/* @fu TIMER1_vidInit                                                                  */
/* @brief  This Function is used to set   STK prescaller                               */
/* @param[out] : void                                                                  */
/* @param[in]  : void                                                                  */
/***************************************************************************************/
void MSTK_voidInit ( void )
{
	#if STK_CLOCK_SELECTION == STK_AHB_OVER_8_CLOCK
			STK->CTRL = 0X00000000 ;

	#elif STK_CLOCK_SELECTION == STK_AHB_CLOCK
			STK->CTRL = 0X00000004 ;
	#else
			#error " STK clock selection is not true "
	#endif

}

/***************************************************************************************/
/*             void STK_vidinit (u32 copy_u32Ticks)                                    */
/*-------------------------------------------------------------------------------------*/
/* @fu TIMER1_vidInit                                                                  */
/* @brief  This Function is used to set   STK compare value                            */
/* @param[out] : void                                                                  */
/* @param[in]  : void                                                                  */
void STK_vidinit (u32 copy_u32Ticks)
{
	MSTK_voidInit();
	STK->LOAD = (copy_u32Ticks - 1)*2000  ;
	STK->VAL  = 0 ;
	SET_BIT(STK->CTRL,0); /* Enable STK */
	SET_BIT(STK->CTRL,1); /* Enable STK interrupt */
}

void SysTick_Handler (void)
{
	Scheduler_flag=1;


}

#endif

