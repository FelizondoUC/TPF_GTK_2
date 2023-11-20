/*
 * humano.c
 *
 *  Created on: 22 oct. 2023
 *      Author: lp1-2023
 */

#include <stdio.h>
#include "variables.h"
#include "jugabilidad.h"

// JUEGA HUMANO. Elegir fila y columna
void juegaHumano(int player) {
	int i = 0, j = 0;


	if (player == PLAYER1) // Player1, dados 1-6
		board[i][j] = 1;
	else
		// Player2, dados 7-12
		board[i][j] = 7;
	// Si se puede, comer
	comeAdyacente(i, j, MAINBOARD, player);
}
