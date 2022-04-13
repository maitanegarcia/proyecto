/*
 * billete.h
 *
 *  Created on: 9 abr 2022
 *      Author: marta
 */

#ifndef BILLETE_BILLETE_H_
#define BILLETE_BILLETE_H_

#include "cliente.h"
#include "clase.h"
#include "vuelo.h"

typedef struct {
	char codBillete[8];
	char asiento[2];
	Clase clase;
	Cliente cliente;
	Vuelo vuelo;
}Billete;

#endif /* BILLETE_BILLETE_H_ */
