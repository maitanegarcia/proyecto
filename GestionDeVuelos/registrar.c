/*
 * registrar.c
 *
 *  Created on: 9 abr. 2022
 *      Author: BSILV
 */
#include <stdio.h>
#include "registrar.h"

char mostrarMenuRegistrar(){
	char opcion;
	printf("Opcion:\n");
	printf("1.Registrar Administrador\n");
	printf("2.Registrar Cliente\n");
	printf("3.Volver\n");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;
}
