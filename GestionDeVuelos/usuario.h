/*
 * administrador.h
 *
 *  Created on: 5 abr. 2022
 *      Author: BSILV
 */

#ifndef USUARIO_USUARIO_H_
#define USUARIO_USUARIO_H_

typedef struct
{
	char dni[10];
	char nombre[20];
	char apellidos[40];
	char correoElectronico[30];
	char contrasenia[30];
	int esAdmin;
}Usuario; //Usuario

typedef struct
{
	Usuario *u;
	int numUsus;
	int tam;
}ListaUsuarios;


int encontrarAdministrador(ListaUsuarios us, char *correoElectronico);

ListaUsuarios reservaAdministradores(int tamanyo);

//void anadirAdministrador(ListaUsuarios *us);

void borrarAdministrador(ListaUsuarios*us,char *correoElectronico);

void editarAdministrador(ListaUsuarios *us, char *dni, char *nombre, char *apellidos, char *correoElectronico, char *cont);

void liberarMemoria(ListaUsuarios us);

#endif /* ADMINISTRADOR_ADMINISTRADOR_H_ */
