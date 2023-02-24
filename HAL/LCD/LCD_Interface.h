/**
 * @file LCD_interface.h
 * @author Hisham Montaser 
 * @brief This is the LCD_Interface.h file for function Prototype . 
 * @version 0.0.0
 * @date 2-17-2023 (Date of documenting)
 * @details This file has seven functions each function give you access to a feature on the LCD .
 */
/****************************************************************************************************************/
/*Date                : 12 - 2 - 2023   (Date of implemeting)                                                   */
/* 01- LCD_vidInit                                                                                              */
/* 02- LCD_vidSendCommand                                                                                       */
/* 03- LCD_vidSendChar                                                                                          */
/* 04- LCD_vidSendString                                                                                        */
/* 05- LCD_vidGetPosition                                                                                       */
/* 06- LCD_vidCustomChar                                                                                        */
/* 07- LCD_vidDisplayCustomChar                                                                                 */
/* 08- LCD_vidSendNum                                                                                           */
/****************************************************************************************************************/

/**************************************************************************************************************/
/*                          HeaderGuard : Prevent Multiple calls of Interface.h header file                   */
/**************************************************************************************************************/
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
/*************************************************************************************************************/
/*                                              Function Prototypes                                          */
/*************************************************************************************************************/

/*************************************************************************************************************/
/*                                               01- LCD_vidInit                                             */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function For LCD initialization . 
 * @param  No_Input_Parameters : void  
 * @return void  
 */
/*************************************************************************************************************/
void LCD_vidInit(void);
/*************************************************************************************************************/
/*                                               02- LCD_vidSendCommand                                      */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for sending command on LCD . 
 * @param  Copy_u8Cmd : Input parameter for sending a specific command on LCD   
 * @return void  
 */
/*************************************************************************************************************/
void LCD_vidSendCommand(u8 Copy_u8Cmd);
/*************************************************************************************************************/
/*                                               03- LCD_vidSendChar                                         */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for sending character on LCD . 
 * @param  Copy_u8Char : Input parameter for sending a character on LCD   
 * @return void  
 */
/*************************************************************************************************************/
void LCD_vidSendChar(u8 Copy_u8Char);
/*************************************************************************************************************/
/*                                               04- LCD_vidSendString                                       */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for sending string on LCD . 
 * @param  Ptr : Pointer holding the first address of a character in a string .
 * @return void  
 */
/*************************************************************************************************************/
void LCD_vidWriteStr(u8* pu8str);
/*************************************************************************************************************/
/*                                               05- LCD_vidSetPosition                                      */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for setting the x-axis and y-axis position of LCD to start writing . 
 * @param  Row : Input parameter specifys which row to start from .
 * @param  Column : Input parameter specifys which column to start from .
 * @return void  
 */
/*************************************************************************************************************/
void LCD_vidSetPosition(u8 Row , u8 Column);
/*************************************************************************************************************/
/*                                               06- LCD_vidCustomChar                                       */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for sending custom character on LCD  . 
 * @param  location : Input parameter specifys which location .
 * @param  ptr : Pointer holding the first address of a character in a string .
 * @return void  
 */
/*************************************************************************************************************/
void LCD_vidCustomChar(u8 location , u8 * ptr);
/*************************************************************************************************************/
/*                                               07- LCD_vidDisplayCustomChar                                */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for displaying custom character  . 
 * @param  location : Input parameter specifys which location .
 * @param  Row : Input parameter specifys which row to start from .
 * @param  Column : Input parameter specifys which column to start from .
 * @return void  
 */
/*************************************************************************************************************/
void LCD_vidDisplayCustomChar( u8 location , u8 Row , u8 Column);
/*************************************************************************************************************/
/*                                               08- LCD_SendNum                                             */
/*-----------------------------------------------------------------------------------------------------------*/
/**
 * @brief Function for send number  .
 * @param  u8num : Sending your desired number .
 * @return void
 */
/*************************************************************************************************************/
void LCD_vidSendNum(u8 u8num);
/************************************************************************************************************/
/*                                   Public Macros                                                          */
/************************************************************************************************************/
#define LCD_CLR                 0x01
#define LCD_HOME                0x02
#define LCD_ENTRYMODE           0x06
#define LCD_DISPOFF             0x08
#define LCD_DISPON_CURSON       0x0E
#define LCD_FUNCRESET           0x30
#define LCD_FUNCSET_8BIT        0x38
#define LCD_SETCURSON           0x80
#define LCD_DISPON_CURSBLINK    0x0F
#define LCD_DISPON_CURSOFF      0x0C

#define LCD_SETCURSLINE2        0xC0
#define LCD_CGRAM_F             0x40

#endif /* LCD_INTERFACE_H_ */
