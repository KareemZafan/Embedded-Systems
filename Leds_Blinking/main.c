/*
 * main.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Kareem
 */

#include <avr/io.h>
#include<avr/delay.h>
#include "STD_TYPES.h"

#define SHIFT_RIGHT_CODE   0x80
#define SHIFT_LEFT_CODE    0x01
#define RIGHT_DIVERGE      0x08
#define LEFT_DIVERGE       0x10
#define SNAKE_CODE         0x07


int main(void) {

	DDRA = 0xFF;
	PORTA = 0x00;
	_delay_ms(1000);

	while (1) {

		PORTA = 0xFF;
		_delay_ms(500);
		PORTA = 0x00;
		_delay_ms(500);

		_delay_ms(1000);
		/* Shifting Left */
		for (u8 i = 0; i < 8; i++) {
			PORTA = SHIFT_LEFT_CODE << i;
			_delay_ms(250);
		}
		_delay_ms(1000);

		/* Shifting Right */
		for (u8 i = 0; i < 8; i++) {
			PORTA = SHIFT_RIGHT_CODE >> i;
		_delay_ms(250);
		}

		_delay_ms(1000);
		for (u8 i = 0; i < 8; i++) {
			PORTA = ((SHIFT_LEFT_CODE << i) | (SHIFT_RIGHT_CODE >> i));
			_delay_ms(300);
		}
        	_delay_ms(100);
		for (u8 i = 0; i < 8; i++) {
			PORTA = ((LEFT_DIVERGE << i) | (RIGHT_DIVERGE >> i));
			_delay_ms(300);
		}
		_delay_ms(1000);
		for (u8 i = 0; i < 7; i++) {
			PORTA = (SNAKE_CODE << i);
			_delay_ms(300);
		}
     _delay_ms(1000) ;
	}
	return 0;
}

