/*
 * LCD_Interface.h
 *
 *  Created on: 25 Nov 2022
 *      Author: nour
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



/**********************************************/
/********public functions prototypes***********/
/**********************************************/

void LCD_vidInit(void);
void LCD_vidSendCmd(u8 command);
void LCD_vidSendChar(u8 character);
void LCD_vidSendString(u8 * ptr_to_arr_ofchar);
void LCD_vidGoToXY(u8 x , u8 y);
void LCD_vidCGRAMAccess();
void LCD_vidClearDisplay(void);
void LCD_vidPrintInit(u16 integer_value , u8 x ,u8 y);



/**********************************************/
/***************public Macros******************/
/**********************************************/
#define LCD_CLR                                 0X01 //replace all char with ASCII 'space'
#define LCD_HOME                                0X02 //return cursor to first position on first line
#define LCD_ENTRY_MODE                          0X06 //shift cursor from left to right on read/write
#define LCD_DISPLAY_OFF                         0X08 //turn display off
#define LCD_DISPLAY_ON_CURSOR_ON                0X0E //display on , cursor off , don't blink charachter
#define LCD_FUNCRESET                           0X30 //reset the lcd
#define LCD_FUNCSET_8BIT                        0X38 //8-bit data ,2-line display , 5 x 7 font
#define LCD_SETCURSOR                           0X80 //set cursor position
#define LCD_DISPLAY_ON_CURSOR_BLIK              0X0F //display on , cursor blinking
#define LCD_DISPLAY_ON_CURSOR_OFF               0X0C //display on , cursor off





#endif /* LCD_INTERFACE_H_ */
