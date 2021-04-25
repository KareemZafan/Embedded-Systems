/*
 * LCD.c
 *
 *  Created on: Oct 11, 2020
 *      Author: Kareem
 */
#include "../APP/BIT_MATH.h"
#include "../APP/STD_TYPES.h"
#include "../MCAL/DIO_Interface.h"
#include "../HAL/LCD_Interface.h"
#include <util/delay.h>

void LCD_vidInit(void) {
	_delay_ms(100);
	DIO_u8SetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);
	DIO_u8SetPortDirection(LCD_CONTROL_PORT, DIO_PORT_OUTPUT);

	DIO_u8SetPortValue(LCD_DATA_PORT , DIO_DEFAULT_PORT_VALUE) ;
	DIO_u8SetPortValue(LCD_CONTROL_PORT , DIO_DEFAULT_PORT_VALUE) ;

	LCD_vidSendCommand(0x38);
	_delay_ms(1);
	LCD_vidSendCommand(0x0C);
	_delay_ms(1);
	LCD_vidSendCommand(0x01);
	_delay_ms(2);
	LCD_vidSendCommand(0x06);
	_delay_ms(1);
return ;
}
void LCD_vidSendCommand(u8 Copy_u8Command) {
	DIO_u8SetPinValue(LCD_CONTROL_PORT , LCD_RS , DIO_PIN_LOW) ;
	DIO_u8SetPinValue(LCD_CONTROL_PORT , LCD_E ,  DIO_PIN_LOW) ;


	DIO_u8SetPinValue(LCD_CONTROL_PORT , LCD_E , DIO_PIN_HIGH) ;
	DIO_u8SetPortValue(LCD_DATA_PORT , Copy_u8Command) ;
	DIO_u8SetPinValue(LCD_CONTROL_PORT , LCD_E , DIO_PIN_LOW) ;

    _delay_ms(5) ;
	return;
}
void LCD_vidwriteChar(u8 Copy_u8Char)
{
	    DIO_u8SetPinValue(LCD_CONTROL_PORT , LCD_RS , DIO_PIN_HIGH) ;
		DIO_u8SetPinValue(LCD_CONTROL_PORT , LCD_E ,  DIO_PIN_LOW) ;

		DIO_u8SetPinValue(LCD_CONTROL_PORT , LCD_E , DIO_PIN_HIGH) ;
		DIO_u8SetPortValue(LCD_DATA_PORT , Copy_u8Char) ;
		DIO_u8SetPinValue(LCD_CONTROL_PORT , LCD_E , DIO_PIN_LOW) ;
		 _delay_ms(1) ;

}
void LCD_vidwriteString(u8 *Copy_u8Str){

	while(*Copy_u8Str != '\0'){
		LCD_vidwriteChar(*Copy_u8Str++) ;
	}

return ;
}
