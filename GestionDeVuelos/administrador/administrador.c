/*
 * administrador.c
 *
 *  Created on: 5 abr. 2022
 *      Author: BSILV
 */

#include "../administrador/administrador.h"

#include<stdio.h>

void registarAdministrador(){
	Administrador a;

	printf("Intrdouce tu email: ");
	fflush(stdout);
	fflush(stdin);
	gets(a.email);
	printf("Intrdouce tu contraseña: ");
	fflush(stdout);
	fflush(stdin);
	gets(a.contrasena);


}

void anadirAdministrador(Administrador *,char *email, char *cont){

}
//void borrarAdministrador(Administrador *ad,char *nombre){
//
//}
//void editarAdministrador(Administrador *ad,char *nombre,char *cont){
//
//}
