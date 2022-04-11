/*
 * configuracion.h
 *
 *  Created on: 11 abr. 2022
 *      Author: BSILV
 */

#ifndef CONFIGURACION_H_
#define CONFIGURACION_H_

typedef struct{
	char ip[16];
	int puerto;
	char ruta[100];
}tConfig;

void cargarConfig(tConfig *c);

#endif /* CONFIGURACION_H_ */
