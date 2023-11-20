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
	int i, j;

	if ( i==-1 || j ==-1) {
		printf("\n¡Lo sentimos has perdido! Elegiste rendirte.");
		exit(0);
	}

	if (player == PLAYER1) // Player1, dados 1-6
		board[i][j] = 1;
	else
		// Player2, dados 7-12
		board[i][j] = 7;
	// Si se puede, comer
	comeAdyacente(i, j, MAINBOARD, player);
}
