/*
 * LCD.c
 *
 *  Created on: Sep 30, 2020
 *      Author: Kareem
 */

#include "../APP/STD_TYPES.h"
#include "../APP/BIT_MATH.h"
#include "../MCAL/DIO_Interface.h"
#include "../HAL/LCD_Interface.h"
#include <avr/delay.h>



void LCD_vidInit(void) {
DIO_u8SetPortDirection(LCD_PORT , DIO_PORT_OUTPUT) ;
DIO_u8SetPortDirection(LCD_CNPORT , DIO_PORT_OUTPUT) ;

	_delay_ms(35) ;
	LCD_vidSendCommand(0x38) ;
	_delay_ms(2) ;
	LCD_vidSendCommand(0x0C) ;
	_delay_ms(2) ;
    LCD_vidSendCommand(0x01) ;
    _delay_ms(2) ;
     LCD_vidSendCommand(0x06) ;
     _delay_ms(2) ;

}

void LCD_vidSendCommand(u8 Copy_u8Command)
{

	    DIO_u8SetPinValue(LCD_CNPORT , LCD_RS , DIO_PIN_LOW ) ;
	    DIO_u8SetPinValue(LCD_CNPORT , LCD_RW , DIO_PIN_LOW ) ;

	    DIO_u8SetPortValue(LCD_PORT , Copy_u8Command) ;
	    DIO_u8SetPinValue(LCD_CNPORT , LCD_EN , DIO_PIN_HIGH ) ;
	    _delay_ms(2) ;
	    DIO_u8SetPinValue(LCD_CNPORT , LCD_EN , DIO_PIN_LOW ) ;
	    _delay_ms(2) ;
}

void LCD_vidWriteChar(u8 Copy_u8CharData) {

	        DIO_u8SetPinValue(LCD_CNPORT , LCD_RS , DIO_PIN_HIGH ) ;
	        DIO_u8SetPinValue(LCD_CNPORT , LCD_RW , DIO_PIN_LOW ) ;
		    DIO_u8SetPortValue(LCD_PORT , Copy_u8CharData) ;
		    DIO_u8SetPinValue(LCD_CNPORT , LCD_EN , DIO_PIN_HIGH ) ;
		    _delay_ms(2) ;
		    DIO_u8SetPinValue(LCD_CNPORT , LCD_EN , DIO_PIN_LOW ) ;
		    _delay_ms(2) ;

}

void LCD_vidWriteString(u8 *Copy_u8StrCharData) {

	while(*Copy_u8StrCharData != '\0')
	{
		LCD_vidWriteChar(*Copy_u8StrCharData++) ;
		_delay_ms(2) ;
	}

}
