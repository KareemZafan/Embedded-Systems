/*
 ============================================================================
 Name        : X-O.c
 Author      : Kareem Mohamed
 Version     : 1.0V
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


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

typedef unsigned       char     u8   ;
typedef unsigned short int      u16  ;
typedef unsigned long int       u32  ;

typedef signed        char      s8   ;
typedef signed  short int       s16  ;
typedef signed  long  int       s32  ;

typedef float                   f32  ;
typedef double                  f64  ;
typedef long double             f128 ;

typedef long                    l32  ;
typedef long long               ll64  ;





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


int main(void) {
	int cellNumber = 0;
	u8 whoWin = 0;
    char firPlayr[20] ;
    char secPlayer[20] ;

	printf("Please enter the name of the first player\n");
    gets(firPlayr) ;

	printf("Please enter the name of the first player\n");
	gets(secPlayer) ;

	do {

        printGame() ;
		printf("%s choose a cell: ",firPlayr );
		scanf("%d", &cellNumber);
		play(FR_PLAYER, cellNumber);

		printGame();
		whoWin = getWinner();
		if (whoWin == FIR_PLAYER) {
			printf("Congratulations %s !!!", firPlayr);
			break;
		} else if (whoWin == SEC_PLAYER) {

			printf("Congratulations %s !!!", secPlayer);
			break;
		}

		printf("%s choose a cell: ", secPlayer);
		scanf("%d", &cellNumber);
		play(SC_PLAYER, cellNumber);
		printGame();


	} while (whoWin == NONE ); // No one wins

return 0 ;
}


/***************************************************************************
 * @Title : X-O Game                                                        *
 * @Filename : xo_Source.c                                                  *
 * @Author : Kareem Mohamed                                                 *
 * @Origin Date : Jun 24, 2021                                              *
 * @Version : 1.0.0                                                         *
 *
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "xo.h"
#include "STD_TYPES.h"

/**
 * Print the square of the X-O Game after each play
 */
u8 xoSuqare[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
u8* playerNames[2];

void printGame(void) {

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%c   |   ", (u8) xoSuqare[i][j]);
		}
		printf("\n---------------------\n");
	}
	printf("\n\n\n");
}

/**
 * This method represents the round of playing of each player
 * @param cellNum
 * @param playerNum player1 will be play using X  and the second will use O
 */
void play(player playerNum, u8 cellNum) {

	if (cellNum < 0 || cellNum > 9) {
		printf("Invalid cells of the game!!!");
		exit(0);
	} else {

		switch (cellNum) {
		case 1:
			switch (playerNum) {
			case FR_PLAYER:
				xoSuqare[0][0] = 'X';
				break;
			case SEC_PLAYER:
				xoSuqare[0][0] = 'O';
				break;
			default:
				break;
			}
			break;
		case 2:
			switch (playerNum) {
			case FR_PLAYER:
				xoSuqare[0][1] = 'X';
				break;
			case SEC_PLAYER:
				xoSuqare[0][1] = 'O';
				break;
			default:
				break;
			}
			break;
		case 3:
			switch (playerNum) {
			case FR_PLAYER:
				xoSuqare[0][2] = 'X';
				break;
			case SEC_PLAYER:
				xoSuqare[0][2] = 'O';
				break;
			default:
				break;
			}
			break;
		case 4:
			switch (playerNum) {
			case FR_PLAYER:
				xoSuqare[1][0] = 'X';
				break;
			case SEC_PLAYER:
				xoSuqare[1][0] = 'O';
				break;
			default:
				break;
			}
			break;
		case 5:
			switch (playerNum) {
			case FR_PLAYER:
				xoSuqare[1][1] = 'X';
				break;
			case SEC_PLAYER:
				xoSuqare[1][1] = 'O';
				break;
			default:
				break;
			}
			break;
		case 6:
			switch (playerNum) {
			case FR_PLAYER:
				xoSuqare[1][2] = 'X';
				break;
			case SEC_PLAYER:
				xoSuqare[1][2] = 'O';
				break;
			default:
				break;
			}
			break;
		case 7:
			switch (playerNum) {
			case FR_PLAYER:
				xoSuqare[2][0] = 'X';
				break;
			case SEC_PLAYER:
				xoSuqare[2][0] = 'O';
				break;
			default:
				break;
			}
			break;
		case 8:
			switch (playerNum) {
			case FR_PLAYER:
				xoSuqare[2][1] = 'X';
				break;
			case SEC_PLAYER:
				xoSuqare[2][1] = 'O';
				break;
			default:
				break;
			}
			break;
		case 9:
			switch (playerNum) {
			case FR_PLAYER:
				xoSuqare[2][2] = 'X';
				break;
			case SEC_PLAYER:
				xoSuqare[2][2] = 'O';
				break;
			default:
				break;
			}

			break;
		default:
			break;
		}

	}

}

/**
 * This method decides the winner of the both players
 * @return the winner player Number
 */
winner getWinner(void) {
	if ((xoSuqare[1][0] == 'X' && xoSuqare[1][1] == 'X' && xoSuqare[1][2] == 'X')
			|| (xoSuqare[2][0] == 'X' && xoSuqare[2][1] == 'X'
					&& xoSuqare[2][2] == 'X')
			|| (xoSuqare[0][0] == 'X' && xoSuqare[1][0] == 'X'
					&& xoSuqare[2][0] == 'X')
			|| (xoSuqare[0][1] == 'X' && xoSuqare[1][1] == 'X'
					&& xoSuqare[2][1] == 'X')
			|| (xoSuqare[0][2] == 'X' && xoSuqare[1][2] == 'X'
					&& xoSuqare[2][2] == 'X')
			|| (xoSuqare[2][0] == 'X' && xoSuqare[1][1] == 'X'
					&& xoSuqare[0][2] == 'X')
     || (xoSuqare[2][2] == 'X' && xoSuqare[1][1] == 'X'
					&& xoSuqare[0][0] == 'X')) {
		return FIR_PLAYER;
	}

	else if ((xoSuqare[1][0] == 'O' && xoSuqare[1][1] == 'O' && xoSuqare[1][2] == 'O')
			|| (xoSuqare[2][0] == 'O' && xoSuqare[2][1] == 'O'
					&& xoSuqare[2][2] == 'O')
			|| (xoSuqare[0][0] == 'O' && xoSuqare[1][0] == 'O'
					&& xoSuqare[2][0] == 'O')
			|| (xoSuqare[0][1] == 'O' && xoSuqare[1][1] == 'O'
					&& xoSuqare[2][1] == 'O')
			|| (xoSuqare[0][0] == 'O' && xoSuqare[0][1] == 'O'
					&& xoSuqare[0][2] == 'O')
			|| (xoSuqare[2][0] == 'O' && xoSuqare[1][1] == 'O'
					&& xoSuqare[0][2] == 'O')
     || (xoSuqare[2][2] == 'O' && xoSuqare[1][1] == 'O'
					&& xoSuqare[0][0] == 'O')) {
		return SEC_PLAYER;
	}
	return NONE;
}

void setPlayerNamse(u8 *pl1Name, u8 *pl2Name) {
	playerNames[0] = pl1Name;
	playerNames[1] = pl2Name;
}

void getPlayerNames(u8* pl1Name, u8* pl2Name) {
	pl1Name = playerNames[0];
	pl2Name = playerNames[1];

}

