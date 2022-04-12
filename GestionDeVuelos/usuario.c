#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usuario.h"


int encontrarAdministrador(ListaUsuarios us, char *correo)
{
	int enc, x;
	enc=0;
	x=0;
	int esAdm=0;
	while(enc==0 && x<us.numAdmins)
	{
		if(strcmp(us.u[x].correoElectronico,correo)==0)//isma??
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


ListaUsuarios reservaAdministradores(int tamanyo)
{
	ListaUsuarios us;

	us.tam = tamanyo;
	us.numAdmins = 0;

	us.u = (ListaUsuarios*)malloc(tamanyo*sizeof(ListaUsuarios));

	return us;
}
//no se porque da error_mirar ismael
//void anadirAdministrador(ListaUsuarios *us)
//{
//	ListaUsuarios crear;
//	int x;
//
//	//crear = registrarAdministrador();
//
////	x = encontrarAdministrador(*us, crear.dni);
//
//	if(x!=-1)
//	{
//		printf("ListaUsuarios ya registrado");
//		fflush(stdout);
//	}
//	else
//	{
//		us->u[us->numAdmins] = crear;
//		printf("ListaUsuarios registrado");
//		us->numAdmins++;
//
//	}
//
//}

void borrarAdministrador(ListaUsuarios *ads,char *dni)
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

void editarAdministrador(ListaUsuarios *ads, char *dni, char *nombre, char *apellidos, char *correoElectronico, char *cont)
{
	int x;

		x = encontrarAdministrador(*ads, dni);

		if(x!=-1)
		{
			strcpy(ads->u[x].dni, dni);
			strcpy(ads->u[x].nombre, nombre);
			strcpy(ads->u[x].apellidos, apellidos);
			strcpy(ads->u[x].correoElectronico, correoElectronico);
			strcpy(ads->u[x].contrasenia, cont);
		}

}

void liberarMemoria(ListaUsuarios ads)
{
	free(ads.u);
}
