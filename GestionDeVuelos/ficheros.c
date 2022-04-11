/*
 * Ficheros.c
 *
 *  Created on: 11 abr. 2022
 *      Author: BSILV
 */


#include <stdio.h>

#include "ficheros.h"

#include "usuario.h"
void guardarAdmin(Usuario u){
	FILE *pf;

	pf=fopen("Administradores.txt","a");
	if(pf!=NULL){
		fprintf(pf,"%s %s %s %s %s\n",u.dni,u.nombre,u.apellidos,u.correoElectronico,u.contrasenia);
		fclose(pf);
	}
}
