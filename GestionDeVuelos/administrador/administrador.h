/*
 * administrador.h
 *
 *  Created on: 5 abr. 2022
 *      Author: BSILV
 */

#ifndef ADMINISTRADOR_ADMINISTRADOR_H_
#define ADMINISTRADOR_ADMINISTRADOR_H_

typedef struct
{
	char dni[10];
	char *nombre;
	char *apellidos;
	char *correoElectronico;
	char contrasenia[30];
}Administrador;

typedef struct
{
	Administrador *a;
	int numAdmins;
	int tam;
}Administradores;


Administrador registrarAdministrador();

int encontrarAdministrador(Administradores ads, char *dni);

Administradores reservaAdministradores(int tamanyo);

void anadirAdministrador(Administradores *ads);

void borrarAdministrador(Administradores *ads,char *dni);

void editarAdministrador(Administradores *ads, char *dni, char *nombre, char *apellidos, char *correoElectronico, char *cont);

void liberarMemoria(Administradores ads);

#endif /* ADMINISTRADOR_ADMINISTRADOR_H_ */
