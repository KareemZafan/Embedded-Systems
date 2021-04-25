/*
 * main.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Kareem
 */

#include "..\APP\STD_TYPES.h"
#include "..\APP\BIT_MATH.h"
#include "..\MCAL\DIO_Interface.h"
#include <avr/delay.h>
#include "../HAL/LCD_Interface.h"


int main(void) {


	LCD_vidInit() ;
	LCD_vidwriteChar('K') ;
	DIO_u8SetPortDirection(DIO_PORTC , 0xFF) ;
	DIO_u8SetPinValue(DIO_PORTC , PIN0 , DIO_PIN_HIGH) ;

   while(1) ;

	return 0;
}

