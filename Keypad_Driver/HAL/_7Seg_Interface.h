/*
 * _7Seg_Interface.h
 *
 *  Created on: Sep 28, 2020
 *      Author: Kareem
 */

#ifndef HAL__7SEG_INTERFACE_H_
#define HAL__7SEG_INTERFACE_H_

#define _7Seg_CC_MODE             0
#define _7Seg_CA_MODE             1

#define EXIT_FAILED               0
#define EXIT_SUCCEED              1

typedef struct {
	u8 _7Seg_Data_Port;
	u8 _7Seg_Type;

} _7Seg_Congif_t;

/* You have to Document this Driver isA */

extern u8 _7Seg_u8Init(_7Seg_Congif_t const *Copy_Config);
extern u8 _7Seg_u8WriteByte(u8 Copy_u8Data);

#endif /* HAL__7SEG_INTERFACE_H_ */
