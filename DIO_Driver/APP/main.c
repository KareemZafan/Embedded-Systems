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

int main(void) {

	DIO_u8SetPintDirection(DIO_PORTA, PIN0, DIO_PIN_OUTPUT);
	DIO_u8SetPintDirection(DIO_PORTB, PIN0, DIO_PIN_OUTPUT);
	DIO_u8SetPintDirection(DIO_PORTC, PIN0, DIO_PIN_OUTPUT);
	DIO_u8SetPintDirection(DIO_PORTD, PIN0, DIO_PIN_OUTPUT);

	while (1) {
		/*DIO_u8SetPinValue(DIO_PORTA, PIN0, DIO_PIN_HIGH);*/
		DIO_u8SetPinValue(DIO_PORTB, PIN0, DIO_PIN_HIGH);
		DIO_u8SetPinValue(DIO_PORTC, PIN0, DIO_PIN_HIGH);
		DIO_u8SetPinValue(DIO_PORTD, PIN0, DIO_PIN_HIGH);

		_delay_ms(1000);

		/*DIO_u8SetPinValue(DIO_PORTA, PIN0, DIO_PIN_LOW);*/
		DIO_u8SetPinValue(DIO_PORTB, PIN0, DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTC, PIN0, DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTD, PIN0, DIO_PIN_LOW);
		_delay_ms(1000);


	}

	return 0;
}

