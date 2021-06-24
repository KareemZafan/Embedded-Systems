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
			|| (xoSuqare[0][0] == 'X' && xoSuqare[0][1] == 'X'
					&& xoSuqare[0][2] == 'X')
			|| (xoSuqare[0][0] == 'X' && xoSuqare[1][0] == 'X'
					&& xoSuqare[1][0] == 'X')
			|| (xoSuqare[0][1] == 'X' && xoSuqare[1][1] == 'X'
					&& xoSuqare[2][1] == 'X')
			|| (xoSuqare[0][2] == 'X' && xoSuqare[1][2] == 'X'
					&& xoSuqare[2][2] == 'X')
			|| (xoSuqare[2][0] == 'X' && xoSuqare[1][1] == 'X'
					&& xoSuqare[0][2] == 'X')) {
		return FIR_PLAYER;
	}

	else if ((xoSuqare[0][0] == 'O' && xoSuqare[0][1] == 'O'
			&& xoSuqare[0][2] == 'O')
			|| (xoSuqare[1][0] == 'O' && xoSuqare[1][1] == 'O'
					&& xoSuqare[1][2] == 'O')
			|| (xoSuqare[0][0] == 'O' && xoSuqare[0][1] == 'O'
					&& xoSuqare[0][2] == 'O')
			|| (xoSuqare[0][0] == 'O' && xoSuqare[1][0] == 'O'
					&& xoSuqare[1][0] == 'O')
			|| (xoSuqare[0][1] == 'O' && xoSuqare[1][1] == 'O'
					&& xoSuqare[2][1] == 'O')
			|| (xoSuqare[0][2] == 'O' && xoSuqare[1][2] == 'O'
					&& xoSuqare[2][2] == 'O')
			|| (xoSuqare[2][0] == 'O' && xoSuqare[1][1] == 'O'
					&& xoSuqare[0][2] == 'O')) {
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
