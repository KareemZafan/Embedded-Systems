/*
 * Keypad.c
 *
 *  Created on: Sep 27, 2020
 *      Author: Kareem
 */
#include "../APP/BIT_MATH.h"
#include "../APP/STD_TYPES.h"
#include "../MCAL/DIO_Interface.h"
#include "../HAL/KPD_Interface.h"
#include <avr/delay.h>

static const u8 KPD_u8SwitcValues[KPD_MAX_ROWS][KPD_MAX_COLS] = {
		{ 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };

static KPD_config_t Config_Struct;
u8 Keypad_u8Init(KPD_config_t *Copy_KPDConfig) {
  Config_Struct.KPD_PORT = Copy_KPDConfig->KPD_PORT ;
  Config_Struct.ROWS_NUM = Copy_KPDConfig->ROWS_NUM ;
  Config_Struct.COLS_NUM = Copy_KPDConfig->COLS_NUM ;

	u8 API_Status = EXIT_FAILED;
	DIO_u8SetPortDirection(Config_Struct.KPD_PORT, 0x0F);
	DIO_u8SetPortValue(Config_Struct.KPD_PORT, 0xFF);
	API_Status = EXIT_SUCCEED;
	return API_Status;
}

u8 Keypad_u8GetPressedKey(void) {
	u8 localPressedKey = 0xFF;
	u8 loc_u8Row = KPD_ROWS_INIT;
	u8 loc_u8Col = KPD_COLS_INIT;

	for (loc_u8Row = 0 + KPD_ROWS_INIT;
			loc_u8Row < (KPD_ROWS_INIT + Config_Struct.ROWS_NUM); loc_u8Row++) { /* Activate the current Row */
		DIO_u8SetPinValue(Config_Struct.KPD_PORT, loc_u8Row, DIO_PIN_LOW);

		for (loc_u8Col = 0 + KPD_COLS_INIT;
				loc_u8Col < (KPD_COLS_INIT + Config_Struct.COLS_NUM); loc_u8Col++) {
			if (!DIO_u8GetPinValue(Config_Struct.KPD_PORT, loc_u8Col)) {
				localPressedKey =
						KPD_u8SwitcValues[loc_u8Row - KPD_ROWS_INIT][loc_u8Col
								- KPD_COLS_INIT];
			}
			while (!DIO_u8GetPinValue(Config_Struct.KPD_PORT, loc_u8Col))
				;

		}

		DIO_u8SetPinValue(Config_Struct.KPD_PORT, loc_u8Row, DIO_PIN_HIGH);
		/* Wait for Button Debouncing */
		_delay_ms(10);
	}

	return localPressedKey; /* Return Key Value */
}
