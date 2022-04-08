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
	char *email;
	char *contrasena;
}Administrador;

typedef struct
{
	Administrador *a;
	int numAdministrador;
}ListaAdmins;


void registrarAdministrador();
void anadirAdministrador(Administrador *a,char *email, char *cont);
void borrarAdministrador(Administrador *a,char *email);
void editarAdministrador(Administrador *a,char *email,char *cont);

#endif /* ADMINISTRADOR_ADMINISTRADOR_H_ */
