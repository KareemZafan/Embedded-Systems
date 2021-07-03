/*
 * main.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Kareem
 */
#include <math.h>
#include <stdlib.h>
#include "..\APP\STD_TYPES.h"
#include "..\APP\BIT_MATH.h"
#include "..\MCAL\DIO_Interface.h"
#include <util/delay.h>
#include "../HAL/LCD.h"

int main(void) {

	LCD_Config_t LCD_Config;
	LCD_Config.LCD_Control_port_Reg = DIO_PORTA;
	LCD_Config.LCD_Data_Port_Reg = DIO_PORTC;
	LCD_Config.LCD_RS = PIN0;
	LCD_Config.LCD_E = PIN1;
	LCD_Config.LCD_RW = PIN2;
	LCD_Config.LCD_Mode = LCD_8Bit_Mode;

	LCD_u8Init(&LCD_Config);
	LCD_u8SendCommand(LCD_RETURN_HOME);

	u8 num = 0;
	while (1) {


		LCD_u8SendText(1, 1, "Guess the number");
		LCD_u8SendText(2, 2, "Num [0-9]");

		if (0 == DIO_u8GetPinValue(DIO_PORTB, PIN4)) { // If the button is closed
			num = 0 + rand() % 9; /* Get a random number from 0 to 9 */
			LCD_u8SendCommand(LCD_CLEAR);
			LCD_u8SendText(2, 2, "Number = ");
			LCD_u8SendCharCp(num + '0');
			_delay_ms(3000);
			LCD_u8SendCommand(LCD_CLEAR) ;

		}

	}

	return 0;
}

