
/***************************************************************************
* @Title : X-O Game                                                 *
* @Filename : xo.h                                                 *
* @Author : Kareem Mohamed                                                 *
* @Origin Date : Jun 24, 2021                                                   * 
* @Version : 1.0.0                                                         *
* @Compiler : GCC AVR                                                      *  
* @Target : Atmega32                                                       *
* @Notes : None                                                            *
***************************************************************************/ 

#ifndef XO_H_
#define XO_H_

#include "STD_TYPES.h"

/* First and Second player*/
typedef enum {
	FR_PLAYER,
	SC_PLAYER
}player;

/* Who wins */
typedef enum{
	FIR_PLAYER,
	SEC_PLAYER,
	NONE
}winner;

/**
 * Print the square of the X-O Game after each play
 */
void printGame(void) ;

/**
 * This method represents the round of playing of each player
 * @param cellNum
 * @param playerNum
 */
void play(player playerNum,u8 cellNum ) ;

/**
 * This method decides the winner of the both players
 * @return the winner player Number
 */
winner getWinner(void) ;














#endif /* XO_H_ */
