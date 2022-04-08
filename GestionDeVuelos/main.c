#include <stdio.h>
#include "administrador/administrador.h"
#define MAX_LINE 10


void clearIfNeeded(char *str, int max_line)
{
	// Limpia los caracteres de más introducidos
	if ((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
		while (getchar() != '\n');
}
char mostrarMenuPrincipal()
{
	printf(" Gestión de vuelos:\n\n");
	printf(" Introducir una de las siguientes opciones:\n");
	printf("1. Inicio de sesion\n");
	printf("2. Registrarse\n");
	printf("3. Salir\n");
	printf("\n");
	fflush(stdout);
	char linea[MAX_LINE];
	fgets(linea, MAX_LINE, stdin);
	clearIfNeeded(linea, MAX_LINE);
	return *linea;
}

int main ( void){
//Administrador ad;

//printf("Administrador...\n");
//fflush(stdout);
//printf("Nombre:");
//fflush(stdout);
//scanf("%c",ad.nombre);
//printf("Contraseña:");
//fflush(stdout);
//scanf("%c",ad.contrasena);
	char opcion;
	opcion=mostrarMenuPrincipal();
	switch (opcion){
				case '1':
					inicioSesion();
					break;
				case '2':
					registrarse();
					break;
				case'3':
					salir();
					break;
			while(opcion != '3');
				liberarMemoria();

			return 0;

}
