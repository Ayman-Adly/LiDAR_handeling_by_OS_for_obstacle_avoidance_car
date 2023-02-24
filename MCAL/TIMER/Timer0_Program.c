/**
 * @file Timer0_Program.c
 * @author Hisham Montaser 
 * @brief This is the Timer0_Program.c file for function implementations . 
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 * @details This file has eight functions each function deal with timer peripheral and two functions handle timer peripheral interrupt .
 */
/****************************************************************************************************************/
/*Date                : 12 - 2 - 2023   (Date of implemeting)                                                   */
/* 01- MTimer0_voidInit                                                                                         */
/* 02- MTimer0_voidSetPreLoadValue                                                                              */
/* 03- MTimer0_voidSetCompareMatchValue                                                                         */
/* 04- MTimer0_voidStopTimer                                                                                    */
/* 05- MTimer0_voidInterputHandlingOVF                                                                          */
/* 06- MTimer0_voidInterputHanldingOC                                                                           */
/* 07- MTimer0_voidSetOVFISR                                                                                    */
/* 08- MTimer0_voidSetCompareMatchISR                                                                           */
/****************************************************************************************************************/

/****************************************************************************************************************/
/*                                   Standard Types LIB                                                         */
/****************************************************************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Manipulation.h"
/****************************************************************************************************************/
/*                                   Lower Layer                                                                */
/****************************************************************************************************************/

/****************************************************************************************************************/
/*                                   Own Header                                                                 */
/****************************************************************************************************************/
#include"Timer0_Private.h"
#include"Timer0_Config.h"
#include"Timer0_Interface.h"
/****************************************************************************************************************/
/*                                   Specific Purpose Functions Implementation                                  */
/****************************************************************************************************************/

/*************************************************************************************************************/
/*                                (void MTimer0_SetMode)                                                     */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Set Timer Mode (Normal, CTC, FAST_PWM, PWM_PHASE_CORRECT )
 * @param  No_Input_Parameters : void  
 * @return void  
 */
/*************************************************************************************************************/
void MTimer0_SetMode()
{
/*Checking if timer mode is normal*/
#if(MODE == Normal)
	{
		/*Clear bit for TCCR0 pin WGM00*/
		CLR_BIT(TCCR0,WGM00);
		/*Clear bit for TCCR0 pin WGM01*/
		CLR_BIT(TCCR0,WGM01);
	}
/*Checking if timer mode is CTC*/
#elif(MODE == CTC)
	{
		/*Set bit for TCCR0 pin WGM01*/
		SET_BIT(TCCR0,WGM01);
		/*Clear bit for TCCR0 pin WGM00*/
		CLR_BIT(TCCR0,WGM00);
	}
/*Checking if timer mode is FAST_PWM*/
#elif(MODE == FAST_PWM)
	{
		/*Set bit for TCCR0 pin WGM01*/
		SET_BIT(TCCR0,WGM01);
		/*Set bit for TCCR0 pin WGM00*/
		SET_BIT(TCCR0,WGM00);
	}
/*Checking if timer mode is PWM_PHASE_CORRECT*/
#elif(MODE == PWM_PHASE_CORRECT)
	{	
		/*clear bit for TCCR0 pin WGM01*/
		CLR_BIT(TCCR0,WGM01);
		/*Set bit for TCCR0 pin WGM00*/
		SET_BIT(TCCR0,WGM00);
	}
#endif
}
/*************************************************************************************************************/
/*                                (void MTimer0_SetCompareOutputMode_NON_PWM)                                */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Set Compare Output Mode NON_PWM (OC0_Disconnected_NON_PWM_MODE, Toggle_OC0_ON_COMPARE_MATCH_NON_PWM_MODE, Clear_OC0_ON_COMPARE_MATCH_NON_PWM_MODE, Set_OC0_ON_COMPARE_MATCH_NON_PWM_MODE)
 * @param  No_Input_Parameters : void  
 * @return void  
 */
/*************************************************************************************************************/
void MTimer0_SetCompareOutputMode_NON_PWM()
{
/*Check if Compare out non pwm mode is set to OC0 disconnect*/
#if(COMPARE_OUTPUT_MODE_NON_PWM_MODE == OC0_Disconnected_NON_PWM_MODE)
	{
		/*Clear TCCR0 pin COM00*/
		CLR_BIT(TCCR0,COM00);
		/*Clear TCCR0 pin COM01*/
		CLR_BIT(TCCR0,COM01);
	}
/*Check if Comper out non pwm mode is set to toggle OC0*/
#elif(COMPARE_OUTPUT_MODE_NON_PWM_MODE == Toggle_OC0_ON_COMPARE_MATCH_NON_PWM_MODE )
	{
		/*Clear TCCR0 pin COM01*/
		CLR_BIT(TCCR0,COM01);
		/*Clear TCCR0 pin COM00*/
		SET_BIT(TCCR0,COM00);
	}
/*Check if Compare out non pwm mode is set to clear OC0*/
#elif(COMPARE_OUTPUT_MODE_NON_PWM_MODE == Clear_OC0_ON_COMPARE_MATCH_NON_PWM_MODE)
	{
		/*Set TCCR0 pin COM01*/
		SET_BIT(TCCR0,COM01);
		/*Set TCCR0 pin COM00*/
		CLR_BIT(TCCR0,COM00);
	}
/*Check if Compare out non pwm mode is set to set OC0*/
#elif(COMPARE_OUTPUT_MODE_NON_PWM_MODE == Set_OC0_ON_COMPARE_MATCH_NON_PWM_MODE)
	{
		/*Set TCCR0 pin COM00*/
		SET_BIT(TCCR0,COM00);
		/*Set TCCR0 pin COM01*/
		SET_BIT(TCCR0,COM01);
	}
#endif
}
/*************************************************************************************************************/
/*                                (void MTimer0_SetCompareOutputMode_FAST_PWM)                               */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Set Compare Output Mode FAST_PWM (OC0_Disconnected_FAST_PWM_MODE, Clear_OC0_ON_COMPARE_MATCH_FAST_PWM_MODE, Set_OC0_ON_COMPARE_MATCH_FAST_PWM_MODE)
 * @param  No_Input_Parameters : void  
 * @return void  
 */
/*************************************************************************************************************/
void MTimer0_SetCompareOutPutMode_FAST_PWM()
{
/*Check if Compare out mode is fast pwm OC0 disconnected*/
#if(COMPARE_OUTPUT_MODE_FAST_PWM_MODE == OC0_Disconnected_FAST_PWM_MODE)
	{
		/*Clear TCCR0 pin COM00*/
		CLR_BIT(TCCR0,COM00);
		/*Clear TCRR0 pin COM01*/
		CLR_BIT(TCCR0,COM01);
	}
/*Check if Compare out mode is fast pwm OC0 clear*/
#elif(COMPARE_OUTPUT_MODE_FAST_PWM_MODE == Clear_OC0_ON_COMPARE_MATCH_FAST_PWM_MODE)
	{
		/*Set TCCR0 bit COM01*/
		SET_BIT(TCCR0,COM01);
		/*Clear TCCR0 pin COM00*/
		CLR_BIT(TCCR0,COM00);
	}
/*Check if Compare out mode is fast pwm OC0 set*/
#elif(COMPARE_OUTPUT_MODE_FAST_PWM_MODE == Set_OC0_ON_COMPARE_MATCH_FAST_PWM_MODE)
	{
		/*Set TCCR0 pin COM01*/
		SET_BIT(TCCR0,COM01);
		/*Set TCCR0 pin COM00*/
		SET_BIT(TCCR0,COM00);
	}
#endif
}
/*************************************************************************************************************/
/*                                (void MTimer0_SetCompareOutputMode_PHASE_CORRECT_PWM)                      */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Set Compare Output Mode PHASE_CORRECT_PWM (OC0_Disconnected_PHASE_CORRECT_PWM_MODE, Clear_OC0_ON_COMPARE_MATCH_PHASE_CORRECT_PWM_MODE, Set_OC0_ON_COMPARE_MATCH_PHASE_CORRECT_PWM_MODE)
 * @param  No_Input_Parameters : void  
 * @return void  
 */
/*************************************************************************************************************/
void MTimer0_SetCompareOutPutMode_PHASE_CORRECT_PWM()
{
/*Check if Compare out mode is phase correct pwm mode OC0 disconneted*/
#if(COMPARE_OUTPUT_MODE_PHASE_CORRECT_PWM_MODE == OC0_Disconnected_PHASE_CORRECT_PWM_MODE)
	{
		/*Clear TCCR0 pin COM00*/
		CLR_BIT(TCCR0,COM00);
		/*Clear TCCR0 pin COM01*/
		CLR_BIT(TCCR0,COM01);
	}
#elif(COMPARE_OUTPUT_MODE_PHASE_CORRECT_PWM_MODE == Clear_OC0_ON_COMPARE_MATCH_PHASE_CORRECT_PWM_MODE)
	{
		/*Set TCCR0 pin COM01*/
		SET_BIT(TCCR0,COM01);
		/*Clear TCCR0 pin COM00*/
		CLR_BIT(TCCR0,COM00);
	}

#elif(COMPARE_OUTPUT_MODE_PHASE_CORRECT_PWM_MODE == Set_OC0_ON_COMPARE_MATCH_PHASE_CORRECT_PWM_MODE)
	{
		/*Set TCCR0 set COM01*/
		SET_BIT(TCCR0,COM01);
		/*Set TCCR0 set COM00*/
		SET_BIT(TCCR0,COM00);
	}
#endif
}

/*************************************************************************************************************/
/*                                (MTimer0_SetCLKSource)                                                     */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Set Timer Mode (NO_CLK_SOURCE, CLK_NO_PRE_SCALING, CLK_PRE_SCALING_8, CLK_PRE_SCALING_64, CLK_PRE_SCALING_256, CLK_PRE_SCALING_1024, EXTERNAL_CLK_SOURCE_ON_FALLING_EDGE, EXTERNAL_CLK_SOURCE_ON_RISING_EDGE)
 * @param No_Input_Parameters : void
 * @return void  
 */
/*************************************************************************************************************/
void MTimer0_SetCLKSource()
{
/*Checking if clock source is being set to no clock source*/
#if(CLOCK_SOURCE == NO_CLK_SOURCE)
	{
		/*Clear bit of TCCR0 pin CS00*/
		CLR_BIT(TCCR0,CS00);
		/*Clear bit of TCCR0 pin CS01*/
		CLR_BIT(TCCR0,CS01);
		/*Clear bit of TCCR0 pin CS02*/
		CLR_BIT(TCCR0,CS02);
	}
/*Check if clock source is set to no pre scaling*/
#elif(CLOCK_SOURCE == CLK_NO_PRE_SCALING)
	{
		/*Set bit of TCCR0 pin CS00*/
		SET_BIT(TCCR0,CS00);
		/*Clear bit of TCCR0 pin CS01*/
		CLR_BIT(TCCR0,CS01);
		/*Clear bit of TCCR0 pin CS02*/
		CLR_BIT(TCCR0,CS02);
	}
/*Check if clock source is set to pre scaler of 8*/
#elif(CLOCK_SOURCE == CLK_PRE_SCALING_8 )
	{
		/*Clear bit of TCCR0 pin CS00*/
		CLR_BIT(TCCR0,CS00);
		/*Set bit of TCCR0 pin CS01*/
		SET_BIT(TCCR0,CS01);
		/*Clear bit of TCCR0 pin CS02*/
		CLR_BIT(TCCR0,CS02);
	}
/*Check if clock source is set to pre scaler of 64*/
#elif(CLOCK_SOURCE == CLK_PRE_SCALING_64)
	{
		/*Set bit of TCCR0 pin CS00*/
		SET_BIT(TCCR0,CS00);
		/*Set bit of TCCR0 pin CS01*/
		SET_BIT(TCCR0,CS01);
		/*Clear bit of TCCR0 pin CS02*/
		CLR_BIT(TCCR0,CS02);
	}
/*Check if clock source is set to pre scaler of 256*/
#elif(CLOCK_SOURCE == CLK_PRE_SCALING_256)
	{
		/*Clear bit of TCCR0 pin CS00*/
		CLR_BIT(TCCR0,CS00);
		/*Clear bit of TCCR0 pin CS01*/
		CLR_BIT(TCCR0,CS01);
		/*Set bit of TCCR0 pin CS02*/
		SET_BIT(TCCR0,CS02);
	}
/*Check if clock source is set to pre scaler of 1024*/
#elif(CLOCK_SOURCE == CLK_PRE_SCALING_1024)
	{
		/*Set bit of TCCR0 pin CS01*/
		SET_BIT(TCCR0,CS00);
		/*Clear bit of TCCR0 pin CS01*/
		CLR_BIT(TCCR0,CS01);
		/*Set bit of TCCR0 pin CS02*/
		SET_BIT(TCCR0,CS02);
	}
/*Check if clock source is set to external clock on falling edge*/
#elif(CLOCK_SOURCE == EXTERNAL_CLK_SOURCE_ON_FALLING_EDGE)
	{
		/*Clear bit of TCCR0 pin CS00*/
		CLR_BIT(TCCR0,CS00);
		/*Set bit of TCCR0 pin CS01*/
		SET_BIT(TCCR0,CS01);
		/*Set bit of TCCR0 pin CS02*/
		SET_BIT(TCCR0,CS02);
	}
/*Check if clock source is set to external clock on rising edge*/
#elif(CLOCK_SOURCE == EXTERNAL_CLK_SOURCE_ON_RISING_EDGE)
	{
		/*Set bit of TCCR0 pin CS00*/
		SET_BIT(TCCR0,CS00);
		/*Set bit of TCCR0 pin CS01*/
		SET_BIT(TCCR0,CS01);
		/*Set bit of TCCR0 pin CS02*/
		SET_BIT(TCCR0,CS02);
	}

#endif
}
/*************************************************************************************************************/
/*                                    Function Implementation                                                */
/*************************************************************************************************************/

/*************************************************************************************************************/
/*                                               01- MTimer0_voidInit                                        */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Timer Initialization 
 * @param  No_Input_Parameters : void  
 * @return void  
 */
/*************************************************************************************************************/

void MTimer0_voidInit()
{
	/*Set timer mode*/
	MTimer0_SetMode();
/*Check if mode is in CTC*/
#if(MODE == CTC)
	{
		/*Choose NON PWM*/
		 MTimer0_SetCompareOutputMode_NON_PWM();
	}
/*Check if mode is in FAST PWM*/
#elif(MODE == FAST_PWM)
	{
		/*Choose FAST PWM*/
		 MTimer0_SetCompareOutPutMode_FAST_PWM();
	}
/*Check if mode is in PWM phase correct*/
#elif(MODE == PWM_PHASE_CORRECT)
	{
		/*Choose PHASE CORRECT PWM*/
		 MTimer0_SetCompareOutPutMode_PHASE_CORRECT_PWM();
	}
#endif


/*Function of enable interrupt OVF*/
void MTimer0_voidInterputHandlingOVF() ;
/*FUnction for enable timer Output compare*/
void MTimer0_voidInterputHandlingOC();
/*Start Counting by enabling clock*/
MTimer0_SetCLKSource();

}

/*************************************************************************************************************/
/*                                               02- MTimer0_voidSetPreLoadValue                             */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Set PreLoadValue 
 * @param  Pre_u8Load : Value of the Pre-Load Must having a value from 0 to 255 . 
 * @return void  
 */
/*************************************************************************************************************/

void MTimer0_voidSetPreLoadValue(u8 Pre_u8Load)
{
	/*Set TCNT0 value to pre-load value*/
	TCNT0 = Pre_u8Load ;
}

/*************************************************************************************************************/
/*                                               03- MTimer0_voidSetCompareMatchValue                        */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Set PreLoadValue 
 * @param  CompareMatch_u8Value : Value of the CompareMatch_value Must be having a value from 0 to 255
 * @return void  
 */
/*************************************************************************************************************/

void MTimer0_voidSetCompareMatchValue(u8 CompareMatch_u8Value)
{
	/*Set OCR0 value to the compare match value*/
	OCR0 = CompareMatch_u8Value;
}

/*************************************************************************************************************/
/*                                               04- MTimer0_voidStopTimer                                   */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Stopping the timer from counting 
 * @param  No_Input_Parameters : void 
 * @return void  
 */
/*************************************************************************************************************/

void MTimer0_voidStopTimer()
{
	/*Clear TCCR0 pin CS00*/
	CLR_BIT(TCCR0,CS00);
	/*Clear TCCR0 pin CS01*/
	CLR_BIT(TCCR0,CS01);
	/*Clear TCCR0 pin CS02*/
	CLR_BIT(TCCR0,CS02);

}

/*************************************************************************************************************/
/*                                               05- MTimer0_voidInterputHanldingOVF                         */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Enabling/Disabling Timer OverFlow interrupt .
 * @param  No_Input_Parameters : void 
 * @return void  
 */
/*************************************************************************************************************/

void MTimer0_voidInterputHandlingOVF()
{
/*Check if Over flow interrupt is enabled*/
#if(Interrupt_StateOVF == Enable )
	{
		/*Set TIMSK pin TOIE0*/
		SET_BIT(TIMSK,TOIE0);
	}
#endif
}


/*************************************************************************************************************/
/*                                               06- MTimer0_voidInterputHanldingOC                          */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For Enabling/Disabling Timer Ouput Compare interrupt .
 * @param  No_Input_Parameters : void 
 * @return void  
 */
/*************************************************************************************************************/

void MTimer0_voidInterputHandlingOC()
{
/*Check if Output compare interrupt is enable */
#if(Interrupt_StateOC == Enable )
	{
		/*Set TIMSK pin OCIE0*/
		SET_BIT(TIMSK,OCIE0);
	}
#endif
}




