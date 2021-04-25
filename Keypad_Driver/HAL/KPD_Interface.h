/*
 * KPD_Interface.h
 *
 *  Created on: Sep 27, 2020
 *      Author: Kareem
 */

#ifndef HAL_KPD_INTERFACE_H_
#define HAL_KPD_INTERFACE_H_
#define KPD_MAX_ROWS       4
#define KPD_MAX_COLS       4

#define KPD_ROWS_INIT      0
#define KPD_COLS_INIT      4


#define EXIT_FAILED        0
#define EXIT_SUCCEED       1

typedef struct {
	u8 KPD_PORT ;
    u8 ROWS_NUM ;
    u8 COLS_NUM ;
}KPD_config_t;

extern u8 Keypad_u8Init(KPD_config_t *Copy_KPDConfig) ;
extern u8 Keypad_u8GetPressedKey(void) ;

#endif /* HAL_KPD_INTERFACE_H_ */
