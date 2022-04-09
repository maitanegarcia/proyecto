/*
 * cliente.h
 *
 *  Created on: 9 abr 2022
 *      Author: marta
 */

#ifndef CLIENTE_CLIENTE_H_
#define CLIENTE_CLIENTE_H_

typedef struct {
	char dni[9];
	char* nomCliente;
	char email[40];
	char clave[40];
}Cliente;

#endif /* CLIENTE_CLIENTE_H_ */
