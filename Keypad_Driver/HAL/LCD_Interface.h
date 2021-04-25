/*
 * LCD_Interface.h
 *
 *  Created on: Sep 30, 2020
 *      Author: Kareem
 */

#ifndef HAL_LCD_INTERFACE_H_
#define HAL_LCD_INTERFACE_H_

#define LCD_PORT DIO_PORTD
#define LCD_CNPORT DIO_PORTC
#define LCD_RS     0
#define LCD_RW     1
#define LCD_EN     2


void LCD_vidInit(void) ;

void LCD_vidSendCommand(u8 Copy_u8Command) ;

void LCD_vidWriteChar(u8 Copy_u8CharData) ;

void LCD_vidWriteString(u8 *Copy_u8StrCharData) ;









#endif /* HAL_LCD_INTERFACE_H_ */
