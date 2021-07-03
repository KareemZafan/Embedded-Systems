#include "../APP/STD_TYPES.h"
#include "../APP/BIT_MATH.h"
#include "../MCAL/DIO_Interface.h"
#include "../HAL/LCD.h"
#include <avr/delay.h>

/*************************************************************************************************************
 * LCD Initialization
 * Input:  Nothing
 * Output: Nothing
 **************************************************************************************************************/
static LCD_Config_t Config_Struct;

u8 LCD_u8Init(LCD_Config_t *Copy_ConfigPtr) {
	u8 API_Status = EXIT_FAILED;
	Config_Struct.LCD_Control_port_Reg = Copy_ConfigPtr->LCD_Control_port_Reg;
	Config_Struct.LCD_Data_Port_Reg = Copy_ConfigPtr->LCD_Data_Port_Reg;
	Config_Struct.LCD_Mode = Copy_ConfigPtr->LCD_Mode;
	Config_Struct.LCD_RS = Copy_ConfigPtr->LCD_RS;
	Config_Struct.LCD_RW = Copy_ConfigPtr->LCD_RW;
	Config_Struct.LCD_E = Copy_ConfigPtr->LCD_E;
	/* Make Control and Data ports Output */
	DIO_u8SetPortDirection(Config_Struct.LCD_Data_Port_Reg, DIO_PORT_OUTPUT);
	DIO_u8SetPortDirection(Config_Struct.LCD_Control_port_Reg,
	DIO_PORT_OUTPUT);
//  /* Use the default port values */
//	DIO_u8SetPortValue(Config_Struct.LCD_Control_port_Reg , DIO_DEFAULT_PORT_VALUE) ;
//	DIO_u8SetPortValue(Config_Struct.LCD_Data_Port_Reg , DIO_DEFAULT_PORT_VALUE) ;


	switch (Config_Struct.LCD_Mode) {
	case LCD_4Bit_Mode:
		_delay_ms(50);
		LCD_u8SendCommand(LCD_FUN_SET_4BIT_2LINE);
		LCD_u8SendCommand(LCD_DISPLAY_ON_CURSOR_OFF);
		LCD_u8SendCommand(LCD_CLEAR);
		LCD_u8SendCommand(LCD_ENTRY_MODE_SET);
		API_Status = EXIT_SUCCEED;
		break;

	case LCD_8Bit_Mode:
		_delay_ms(50);
		LCD_u8SendCommand( LCD_FUN_SET_8BIT_2LINE);
		LCD_u8SendCommand( LCD_DISPLAY_ON_CURSOR_OFF);
		LCD_u8SendCommand(LCD_CLEAR);
		LCD_u8SendCommand(LCD_ENTRY_MODE_SET);
		API_Status = EXIT_SUCCEED;
		break;
	default:
		API_Status = EXIT_FAILED;
		break;
	}
	return API_Status;
}

/**************************************************************************************************************
 * LCD Send Command : To send a command to LCD like LCD Clear ...
 * Input : Required Command
 * Output: Nothing
 *
 */

u8 LCD_u8SendCommand(u8 Copy_u8Command) {

	u8 API_Status = EXIT_FAILED;
	u8 Command = 0x00;

	DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg, Config_Struct.LCD_RS,
	DIO_PIN_LOW);
	DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg, Config_Struct.LCD_RW,
	DIO_PIN_LOW);

	switch (Config_Struct.LCD_Mode) {
	case LCD_4Bit_Mode:
		Command = (Config_Struct.LCD_Data_Port_Reg & 0x0F) | (Copy_u8Command & 0xF0);
		/* E is HIGH */
		DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg,
				Config_Struct.LCD_E, DIO_PIN_HIGH);
		DIO_u8SetPortValue(Config_Struct.LCD_Data_Port_Reg, Command);

		/* E is LOW */
		DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg,
				Config_Struct.LCD_E, DIO_PIN_LOW);
		_delay_us(200);
		Command = (Config_Struct.LCD_Data_Port_Reg & 0x0F) | (Copy_u8Command << 4);
		DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg,
				Config_Struct.LCD_E, DIO_PIN_HIGH);
		DIO_u8SetPortValue(Config_Struct.LCD_Data_Port_Reg, Command);

		DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg,
				Config_Struct.LCD_E, DIO_PIN_LOW);
		_delay_ms(2);
		DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg,
				Config_Struct.LCD_E, DIO_PIN_HIGH);

		API_Status = EXIT_SUCCEED;
		break;
	case LCD_8Bit_Mode:

		/* Set 1 on E (E is HIGH) */
		DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg,
				Config_Struct.LCD_E, DIO_PIN_HIGH);
		DIO_u8SetPortValue(Config_Struct.LCD_Data_Port_Reg, Copy_u8Command);
		DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg,
				Config_Struct.LCD_E, DIO_PIN_LOW);
		_delay_ms(2);
		DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg,
				Config_Struct.LCD_E, DIO_PIN_HIGH);
		API_Status = EXIT_SUCCEED;
		break;

	default:
		API_Status = EXIT_FAILED;
		break;
	}

	return API_Status;
}

/**************************************************************************************************************
 * LCD Send Character to send the required character to be displayed in the current position
 * Input: Required Character
 * Output:Nothing
 *
 */
u8 LCD_u8SendCharCp(u8 Copy_u8Char) {
	u8 API_Status = EXIT_FAILED;
	u8 localByte = 0x00;
	DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg, Config_Struct.LCD_RS,
	DIO_PIN_HIGH);
	DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg, Config_Struct.LCD_RW,
	DIO_PIN_LOW);
	switch (Config_Struct.LCD_Mode) {

	case LCD_4Bit_Mode:
		localByte = (Config_Struct.LCD_Data_Port_Reg & 0x0F) | (Copy_u8Char & 0xF0);
		/* E is High */
		DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg,
				Config_Struct.LCD_E, DIO_PIN_HIGH);
		DIO_u8SetPortValue(Config_Struct.LCD_Data_Port_Reg, localByte);
		/* E is LOW */
		DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg,
				Config_Struct.LCD_E, DIO_PIN_LOW);

		localByte = (Config_Struct.LCD_Data_Port_Reg & 0x0F) | (Copy_u8Char << 4);
		/* E is High */

		DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg,
				Config_Struct.LCD_E, DIO_PIN_HIGH);
		DIO_u8SetPortValue(Config_Struct.LCD_Data_Port_Reg, localByte);
		/* E is LOW */
		DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg,
				Config_Struct.LCD_E, DIO_PIN_LOW);

		_delay_ms(2);
		/* E is High */
		DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg,
				Config_Struct.LCD_E, DIO_PIN_HIGH);
		API_Status = EXIT_SUCCEED;
		break;
	case LCD_8Bit_Mode:

		/*  (E is HIGH) */
		DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg,
				Config_Struct.LCD_E, DIO_PIN_HIGH);
		DIO_u8SetPortValue(Config_Struct.LCD_Data_Port_Reg, Copy_u8Char);
		/* E is LOW */
		DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg,
				Config_Struct.LCD_E, DIO_PIN_LOW);
		_delay_ms(2);
		/* E is High */
		DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg,
				Config_Struct.LCD_E, DIO_PIN_HIGH);
		API_Status = EXIT_SUCCEED;
		break;
	default:
		API_Status = EXIT_FAILED;
		break;
	}

	return API_Status;
}

/**************************************************************************************************************
 * LCD Send Text to send the required String to be displayed in the current position
 * Input: Array Of Character
 * Output:Nothing
 *
 */
u8 LCD_u8SendTextCp(u8 *Copy_u8Str) {

	u8 API_Status = EXIT_FAILED;
	u8 local_u8Counter = 0 ;
	while(Copy_u8Str[local_u8Counter] != 0) /* 0 Represents NULL Character  */
	{
		LCD_u8SendCharCp(Copy_u8Str[local_u8Counter]) ;
		++local_u8Counter ;
	}

	return API_Status;
}

/**************************************************************************************************************
 * LCD Goto X , Y : This function make the cursor to be placed in a specified location
 * Input: X Row , Y Column
 * Output:Nothing
 *
 */
u8 LCD_u8GotoX_Y(u8 Copy_u8Row, u8 Copy_u8Column) {
	u8 API_Status = EXIT_FAILED;

	if ((Copy_u8Row >= 1 && Copy_u8Row <= 4)
			&& (Copy_u8Column >= 1 && Copy_u8Column <= 16))
		switch (Copy_u8Row) {
		case 1:
			LCD_u8SendCommand(LCD_1ST_LINE_BEGGING + Copy_u8Column - 1);
			API_Status = EXIT_SUCCEED;

			break;
		case 2:
			LCD_u8SendCommand(LCD_2ND_LINE_BEGGING + Copy_u8Column - 1);
			API_Status = EXIT_SUCCEED;

			break;
		case 3:
			LCD_u8SendCommand(LCD_3RD_LINE_BEGGING + Copy_u8Column - 1);
			API_Status = EXIT_SUCCEED;

			break;
		case 4:
			LCD_u8SendCommand(LCD_4TH_LINE_BEGGING + Copy_u8Column - 1);
			API_Status = EXIT_SUCCEED;
			break;
		default:
			API_Status = EXIT_FAILED;
			break;
		}
	else {
		API_Status = EXIT_FAILED;
	}

	return API_Status;
}

/**************************************************************************************************************
 * LCD Send Character to send the required character to be displayed in the specified position
 * Input: Required Character
 * Output:Nothing
 *
 */
u8 LCD_u8SendChar(u8 Copy_u8Row, u8 Copy_u8Column, u8 Copy_u8Data) {
	u8 API_Status = EXIT_FAILED;
	LCD_u8GotoX_Y(Copy_u8Row, Copy_u8Column);
	API_Status = LCD_u8SendCharCp(Copy_u8Data);
	return API_Status;
}

/**************************************************************************************************************
 * LCD Send Text to send the required String to be displayed in the specified position
 * Input: Array Of Character
 * Output:Nothing
 *
 */
u8 LCD_u8SendText(u8 Copy_u8Row, u8 Copy_u8Column, u8 *Copy_u8data) {
	u8 API_Status = EXIT_FAILED;
	LCD_u8GotoX_Y(Copy_u8Row, Copy_u8Column);
	API_Status = LCD_u8SendTextCp(Copy_u8data);
	return API_Status;
}

/***************************************************************************************************************
 * CheckIfBusy: This function check if the current data can be written or read from LCD at this moment
 * Input: Nothing
 * Output: 0 when it is not busy 1 when it is busy
 */
u8 LCD_u8CheckIfBusy(void) {
	u8 API_Status = EXIT_FAILED;
	DIO_u8SetPinDirection(Config_Struct.LCD_Data_Port_Reg, PIN7,
	DIO_PIN_INPUT);
	DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg, Config_Struct.LCD_RW,
	DIO_PIN_HIGH);
	DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg, Config_Struct.LCD_RS,
	DIO_PIN_LOW);

	API_Status = DIO_u8GetPinValue(Config_Struct.LCD_Data_Port_Reg, PIN7);
	/* Reset RW  before Exit */
	DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg, Config_Struct.LCD_RW,
	DIO_PIN_LOW);
	return API_Status;
}

/***************************************************************************************************************
 * Generate_Character: This function enable the user to generate a custome character
 * Input: Array of character which contain the 7 rows of character pattern and address to where to store this character
 * output: Nothing
 */
u8 LCD_u8GenerateCharacter(u8 Copy_u8Address ,  u8 *Copy_u8CharRows) {
	u8 API_Status = EXIT_FAILED;
	/* Notice that CGRAM is 64 * 8 */
	LCD_u8SendCommand((LCD_CGRAM_START_ADDRESS + (8 * Copy_u8Address)));

	/* Set the Eight bytes of  that character */
	for (u8 i = 0; i < 8; i++) {
		LCD_u8SendCharCp(Copy_u8CharRows[i]);
	}
	return API_Status;
}

/***************************************************************************************************************************
 * LCD Read: This Function Return a 8bit character from DDRAM or CGRAM
 * Input: Address of the byte you want to read
 * Output: The required character
 * Additional Info: This function is helpful while working with multiple MCUs *
 * Only with 8 Bit Mode
 */
/*u8 LCD_u8ReadByte(u8 Copy_u8Row , u8 Copy_u8Column) {
	u8 API_Status = EXIT_FAILED;
	LCD_u8GotoX_Y(Copy_u8Row , Copy_u8Column) ;
	DIO_u8SetPortDirection(Config_Struct.LCD_Data_Port_Reg,
	DIO_PORT_INPUT);
	DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg, Config_Struct.LCD_RS,
	DIO_PIN_HIGH);
	DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg, Config_Struct.LCD_RW,
	DIO_PIN_HIGH);
	/* API_Status will hold the value of that DDRAM or CGRAM character */

	/*DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg, Config_Struct.LCD_E,DIO_PIN_HIGH);
	DIO_u8GetPortValue(Config_Struct.LCD_Data_Port_Reg, &API_Status);
	DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg, Config_Struct.LCD_E,DIO_PIN_LOW);
	_delay_ms(1);
	DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg, Config_Struct.LCD_RW,
	DIO_PIN_LOW);
	DIO_u8SetPinValue(Config_Struct.LCD_Control_port_Reg, Config_Struct.LCD_RS,
	DIO_PIN_LOW);

	_delay_ms(2);

	return API_Status;
}*/

