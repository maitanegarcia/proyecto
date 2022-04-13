/*
 * menuPrincipal.c
 *
 *  Created on: 8 abr. 2022
 *      Author: BSILV
 */

#include "menuPrincipal.h"
#include <stdio.h>
char mostrarMenu(){
	char opcion;

		printf("GESTION DE VUELOS:\n");
		printf("---------------------\n");
		printf("Introduce una opcion:\n");
		printf("1.Inicio de sesion\n");
		printf("2.Registrarse\n");
		printf("3.Salir\n");
		printf("---------------------\n\n");
		fflush(stdout);
		fflush(stdin);
		scanf("%c",&opcion);
		return opcion;
}
