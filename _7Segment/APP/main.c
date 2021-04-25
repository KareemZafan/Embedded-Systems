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
#include <avr/delay.h>

int main(void) {
  const _7Seg_Congif_t Copy_Config  = {DIO_PORTA , _7Seg_CC_MODE} ;
   _7Seg_u8Init(&Copy_Config) ;

	while (1) {

		for(u8 i = 0 ; i < 10 ; i++){
          _7Seg_u8WriteByte(i) ;
          _delay_ms(1000) ;
		}

	}

	return 0;
}

