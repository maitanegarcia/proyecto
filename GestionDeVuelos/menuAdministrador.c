/*
 * menuAdministrador.c
 *
 *  Created on: 12 abr. 2022
 *      Author: BSILV
 */


#include "menuAdministrador.h"
#include <stdio.h>

char mostrarMenuAdministrador(){
	char opcion;
	printf("MENU ADMINISTRADOR\n");
	printf("-------------------------------------\n\n");
	printf("Introduzca una opcion:\n\n");
	printf("1.Historial de viajes\n");
	printf("2.Editar reservas\n");
	printf("3.Visualizar reservas\n");
	printf("4.Visualizar base de datos\n");
	printf("5.Visualizar fichero de configuración\n");
	printf("7.Cerrar Sesión\n");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&opcion);
	return opcion;


}
