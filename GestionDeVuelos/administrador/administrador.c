
#include "../administrador/administrador.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void registarAdministrador(Administrador a)
{
	printf("Introduce tu dni: ");
	fflush(stdout);
	fflush(stdin);
	gets(a.dni);
	printf("Introduce tu nombre: ");
	fflush(stdout);
	fflush(stdin);
	gets(a.nombre);
	printf("Introduce tus apellidos: ");
	fflush(stdout);
	fflush(stdin);
	gets(a.apellidos);
	printf("Introduce tu email: ");
	fflush(stdout);
	fflush(stdin);
	gets(a.correoElectronico);
	printf("Introduce tu contraseña: ");
	fflush(stdout);
	fflush(stdin);
	gets(a.contrasenia);

}

int encontrarAdministrador(Administradores ads, char *dni)
{
	int esta, x;
	esta=0;
	x=0;
	while(esta==0 && x<ads.numAdmins)
	{
		if(strcmp(ads.a[x].correoElectronico, dni) == 0)
		{
			esta=1;
		}
		else
		{
			x++;
		}
	}
	if(esta == 0)
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

	x = encontrarAdministrador(*ads, crear.dni);

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

void borrarAdministrador(Administradores *ads,char *dni)
{
	int i, x;

	x = encontrarAdministrador(*ads, dni);

	if(x!=-1)
	{
		for(i=x;i<ads->numAdmins;i++)
		{
			ads[x] = ads[x+1];
		}
		ads->numAdmins--;
	}

}

void editarAdministrador(Administradores *ads, char *dni, char *nombre, char *apellidos, char *correoElectronico, char *cont)
{
	int x;

	x = encontrarAdministrador(*ads, dni);

	if(x!=-1)
	{
		strcpy(ads->a[x].dni, dni);
		strcpy(ads->a[x].nombre, nombre);
		strcpy(ads->a[x].apellidos, apellidos);
		strcpy(ads->a[x].correoElectronico, correoElectronico);
		strcpy(ads->a[x].contrasenia, cont);
	}

}

void liberarMemoria(Administradores ads)
{
	free(ads.a);
}
