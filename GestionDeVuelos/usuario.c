#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usuario.h"


int encontrarUsuario(ListaUsuarios us, char *correoElectronico)
{
	int enc, x;
	enc=0;
	x=0;
	int esAdm=0;
	while(enc==0 && x<us.numUsus)
	{
		if(strcmp(us.u[x].correoElectronico,correoElectronico)==0)
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


ListaUsuarios reservaUsuario(int tamanyo)
{
	ListaUsuarios us;

	us.tam = tamanyo;
	us.numUsus = 0;

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

void borrarUsuario(ListaUsuarios *us,char *correoElectronico)
{
	int i, x;

	x = encontrarAdministrador(*us, correoElectronico);

	if(x!=-1)
	{
		for(i=x;i<us->numUsus;i++)
		{
			us[x] = us[x+1];
		}
		us->numUsus--;
	}

}

void editarUsuario(ListaUsuarios *us, char *dni, char *nombre, char *apellidos, char *correoElectronico, char *cont)
{
	int x;

		x = encontrarAdministrador(*us, dni);

		if(x!=-1)
		{
			strcpy(us->u[x].dni, dni);
			strcpy(us->u[x].nombre, nombre);
			strcpy(us->u[x].apellidos, apellidos);
			strcpy(us->u[x].correoElectronico, correoElectronico);
			strcpy(us->u[x].contrasenia, cont);
		}

}

void liberarMemoria(ListaUsuarios ads)
{
	free(ads.u);
}
