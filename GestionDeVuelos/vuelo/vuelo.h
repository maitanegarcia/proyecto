/*
 * vuelo.h
 *
 *  Created on: 9 abr 2022
 *      Author: marta
 */

#ifndef VUELO_VUELO_H_
#define VUELO_VUELO_H_

#include "../ciudad/ciudad.h"

typedef struct {
	int idVuelo[8];
	int fecha[8];
	int hora[4];
	int plazas;
	Ciudad cOrigen;
	Ciudad cDestino;
}Vuelo;


#endif /* VUELO_VUELO_H_ */
