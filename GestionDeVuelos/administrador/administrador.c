/*
 * administrador.c
 *
 *  Created on: 5 abr. 2022
 *      Author: BSILV
 */

#include "../administrador/administrador.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Administrador registarAdministrador()
{
	Administrador a;

	printf("Intrdouce tu email: ");
	fflush(stdout);
	fflush(stdin);
	gets(a.email);
	printf("Intrdouce tu contraseña: ");
	fflush(stdout);
	fflush(stdin);
	gets(a.contrasenia);


	return a;


}

int encontrarAdministrador(Administradores ads, char *email)
{
	int enc, x;
	enc=0;
	x=0;
	while(enc==0 && x<ads.numAdmins)
	{
		if(strcmp(ads.a[x].email, email) == 0)
		{
			enc=1;
		}
		else
		{
			x++;
		}
	}
	if(enc == 0)
	{
		x=-1;
	}

	return x;
}

Administradores reservaAdministradores(int tamanyo)
{
	Administradores ads;

	ads.tam = tamanyo;
	ads.numAdmins = 0;

	ads.a = (Administrador*)malloc(tamanyo*sizeof(Administrador));

	return ads;
}

void anadirAdministrador(Administradores *ads)
{
	Administrador crear;
	int x;

	//crear = registrarAdministrador();

	x = encontrarAdministrador(*ads, crear.email);

	if(x!=-1)
	{
		printf("Administrador ya registrado");
		fflush(stdout);
	}
	else
	{
		ads->a[ads->numAdmins] = crear;
		printf("Administrador registrado");
		ads->numAdmins++;

	}

}

void borrarAdministrador(Administradores *ads,char *email)
{
	int i, x;

	x = encontrarAdministrador(*ads, email);

	if(x!=-1)
	{
		for(i=x;i<ads->numAdmins;i++)
		{
			ads[x] = ads[x+1];
		}
		ads->numAdmins--;
	}

}

void editarAdministrador(Administradores *ads, char *email, char *cont)
{
	int x;

		x = encontrarAdministrador(*ads, email);

		if(x!=-1)
		{
			strcpy(ads->a[x].email, email);
			strcpy(ads->a[x].contrasenia, cont);
		}

}

void liberarMemoria(Administradores ads)
{
	free(ads.a);
}
