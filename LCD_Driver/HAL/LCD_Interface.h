/*
 * LCD_Interface.h
 *
 *  Created on: Oct 11, 2020
 *      Author: Kareem
 */

#ifndef HAL_LCD_INTERFACE_H_
#define HAL_LCD_INTERFACE_H_

#define LCD_DATA_PORT      DIO_PORTA
#define LCD_CONTROL_PORT   DIO_PORTD
#define LCD_E                1
#define LCD_RS               0
/*#define LCD_RW               2     will be connected to GND*/



extern void LCD_vidInit(void) ;
extern void LCD_vidSendCommand(u8 Copy_u8Command) ;
extern void LCD_vidwriteChar(u8 Copy_u8Char) ;
extern void LCD_vidwriteString(u8 *Copy_u8Str) ;

#endif /* HAL_LCD_INTERFACE_H_ */
