/*
 * main.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Kareem
 */

#include "..\APP\STD_TYPES.h"
#include "..\APP\BIT_MATH.h"
#include "..\MCAL\DIO_Interface.h"
#include "../HAL/_7Seg_Interface.h"
#include "../HAL/LCD_Interface.h"
#include "../HAL/KPD_Interface.h"
#include <avr/delay.h>

int main(void) {
	KPD_config_t KPDConfig = { DIO_PORTD, 4, 4 };
	_7Seg_Congif_t _7SegConfig = { DIO_PORTA, _7Seg_CC_MODE };

	Keypad_u8Init(&KPDConfig);
	_7Seg_u8Init(&_7SegConfig);

	u8 key = 0x00;
	while (1) {
		key = Keypad_u8GetPressedKey();
		if (key != 0xFF) {
			_7Seg_u8WriteByte(key) ;
			_delay_ms(100) ;
		} else {

		}

	}

	return 0;
}

