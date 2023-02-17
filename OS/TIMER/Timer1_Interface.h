/***************************************************************************************/
/* Author               : Moamen ehab                                                  */
/* Version              : V0.0.0                                                       */
/* Date                 : 2 - 2  -2023                                                 */
/* Description          : TIMER1_Interface.h -> Function Prototypes                    */
/* Module Features      :                                                              */
/*        01- void TIMER1_vidInit(void);                                               */
/*        02- void TIMER1_vidSetOCR1AComparMatchVal(u16 CompareMatchVal);              */
/*        03- static void TIMER1_vidSetMode(void);                                     */
/*        04- static void TIMER1_vidSetTimer1Prescaller(void);                         */

/***************************************************************************************/
#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

/******************************** public functions**************************************/
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
void TIMER1_vidInit(u8 system_tick);

/**********************************private functions************************************/
/***************************************************************************************/
/*                   02- void TIMER1_vidSetOCR1AComparMatchVal(u16 CompareMatchVal)    */
/*-------------------------------------------------------------------------------------*/
/* @fu TIMER1_vidSetOCR1AComparMatchVal                                                */
/* @brief  This Function is used to set the compare match value to OCRA register       */
/* @param[out] : void                                                                  */
/* @param[in]  : u16 CompareMatchVal                                                   */

/***************************************************************************************/
static void TIMER1_vidSetOCR1AComparMatchVal(u16 CompareMatchVal);

void TIMER1_vidSetOCompareMatchISR(void (*PtoCallbackfunc)(void));


/***************************************************************************************/
/*                          03- static void TIMER1_vidSetMode(void)                    */
/*-------------------------------------------------------------------------------------*/
/* @fu TIMER1_vidSetMode                                                               */
/* @brief  This Function is used to set Timer 1 to CTC mode                            */
/* @param[out] : void                                                                  */
/* @param[in]  : void                                                                  */

/***************************************************************************************/
static void TIMER1_vidSetMode(void);
/***************************************************************************************/
/*                          03- static void TIMER1_vidSetMode(void)                    */
/*-------------------------------------------------------------------------------------*/
/* @fu TIMER1_vidSetTimer1Prescaller                                                                  */
/* @brief  This Function is to set timer 1 prescaller                                  */
/* @param[out] : void                                                                  */
/* @param[in]  : void                                                                  */

/***************************************************************************************/
static void TIMER1_vidSetTimer1Prescaller(void);

#endif /* TIMER0_INTERFACE_H_ */
