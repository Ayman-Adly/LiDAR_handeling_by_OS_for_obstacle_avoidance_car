/***************************************************************************************/
/* Author               : Moamen ehab / Ehap ashraf                                    */
/* Version              : V0.0.0                                                       */
/* Date                 : 2 - 2  -2023                                                 */
/* Description          : TIMER1_Interface.h -> Function Prototypes                    */
/* Module Features      :                                                              */
/*        01- void TIMER1_vidInit(void);                                               */
/*        02- void TIMER1_vidSetOCR1AComparMatchVal(u16 CompareMatchVal);              */
/*        03- static void TIMER1_vidSetMode(void);                                     */
/*        04- static void TIMER1_vidSetTimer1Prescaller(void);                         */

/***************************************************************************************/
#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

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



/***************************************************************************************/
/*                          01- void STK_vidInit ( void )                              */
/*-------------------------------------------------------------------------------------*/
/* @fu TIMER1_vidInit                                                                  */
/* @brief  This Function is used to initialize Systick                                 */
/* @param[out] : void                                                                  */
/* @param[in]  : void                                                                  */
/***************************************************************************************/
void STK_vidInit ( void );
/***************************************************************************************/
/*                          02-void STK_vidinit (u32 copy_u32Ticks)                           */
/*-------------------------------------------------------------------------------------*/
/* @fu TIMER1_vidInit                                                                  */
/* @brief  This Function is used to initialize Systick                                 */
/* @param[out] : void                                                                  */
/* @param[in]  : void                                                                  */
/***************************************************************************************/
void STK_vidinit (u32 copy_u32Ticks);

#endif /* TIMER0_INTERFACE_H_ */
