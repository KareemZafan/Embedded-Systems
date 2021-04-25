/*
 * _7Seg_Porg.c
 *
 *  Created on: Sep 28, 2020
 *      Author: Kareem
 */

#include "../APP/BIT_MATH.h"
#include "../APP/STD_TYPES.h"
#include "../MCAL/DIO_Interface.h"
#include "_7Seg_Interface.h"

static const u8 _7Seg_CC_Vals[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D,
		0x07, 0x7F, 0x6F };

static const u8 _7Seg_CA_Vals[] = { ~0x3F, ~0x06, ~0x5B, ~0x4F, ~0x66, ~0x6D,
		~0x7D, ~0x07, ~0x7F, ~0x6F };

static  _7Seg_Congif_t _7Seg_Config_Struct;
u8 _7Seg_u8Init(_7Seg_Congif_t const *Copy_Config) {
	u8 API_Status = EXIT_FAILED;
	/* Initialization of the Seven Segment according to the passed table */
	_7Seg_Config_Struct._7Seg_Data_Port = Copy_Config->_7Seg_Data_Port;
	_7Seg_Config_Struct._7Seg_Type = Copy_Config->_7Seg_Type;

	DIO_u8SetPortDirection(_7Seg_Config_Struct._7Seg_Data_Port,
	DIO_PORT_OUTPUT);
	API_Status = DIO_u8SetPortValue(_7Seg_Config_Struct._7Seg_Data_Port,0x00);

	return API_Status;
}
u8 _7Seg_u8WriteByte(u8 Copy_u8Data) {
	u8 API_Status = EXIT_FAILED;

	switch (_7Seg_Config_Struct._7Seg_Type) {
	case _7Seg_CA_MODE:
		DIO_u8SetPortValue(_7Seg_Config_Struct._7Seg_Data_Port,
				_7Seg_CA_Vals[Copy_u8Data]);
		API_Status = EXIT_SUCCEED;
		break;
	case _7Seg_CC_MODE:
		DIO_u8SetPortValue(_7Seg_Config_Struct._7Seg_Data_Port,
				_7Seg_CC_Vals[Copy_u8Data]);
		API_Status = EXIT_SUCCEED;
		break;

	default:
		API_Status = EXIT_FAILED;
		break;
	}

	return API_Status;
}
