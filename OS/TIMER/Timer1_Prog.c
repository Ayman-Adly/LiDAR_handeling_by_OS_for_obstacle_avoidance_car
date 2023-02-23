
#include "../../LIB/STD_Types.h"
#include "../../LIB/Bitmath.h"

#include "Timer1_Priv.h"
#include "Timer1_Interface.h"
#include "avr/interrupt.h"

extern u8 Scheduler_flag;

//static System_tick =  SYS_TICK;

static void (*Ptofunc_Timer1_CompareMatchISR)(void);

static void TIMER1_vidSetOCR1AComparMatchVal(u16 CompareMatchVal) {
	/*putting the compare match value in the OCR1A register*/
	OCR1A_REG = CompareMatchVal;
}

void TIMER1_vidStopTimer(void)
{

	CLR_BIT(TCCR1B_REG, CS10);
	CLR_BIT(TCCR1B_REG, CS11);
	CLR_BIT(TCCR1B_REG, CS12);

}

static void TIMER1_vidSetMode(void)
{

	/*selecting CTC mode*/
	CLR_BIT(TCCR1A_REG, WGM10);
	CLR_BIT(TCCR1A_REG, WGM11);
	SET_BIT(TCCR1B_REG, WGM12);
	CLR_BIT(TCCR1B_REG, WGM13);

}

static void TIMER1_vidSetTimer1Prescaller(void)
{
	/*selecting prescaller of 64 now we have MHZ clock freq*/
	SET_BIT(TCCR1B_REG, CS10);
	SET_BIT(TCCR1B_REG, CS11);
	CLR_BIT(TCCR1B_REG, CS12);

}
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

void TIMER1_vidSetOCompareMatchISR(void (*PtoCallbackfunc)(void))
{
	Ptofunc_Timer1_CompareMatchISR = PtoCallbackfunc;
}
ISR(TIMER1_COMPA_vect)
{
	Schedular_flag = 1;
	//Ptofunc_Timer1_CompareMatchISR();

}
