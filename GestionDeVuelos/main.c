/*llamar a todas las funciones*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuPrincipal.h"
#include "ficheros.h"
#include "registrar.h"
#include "sqlite3.h"
#include "configuracion.h"
#include "usuario.h"
#include "menuAdministrador.h"
Usuario pedirDatosInicio();
void registrarA(Usuario *u);

int main(void){
	char opcion,opcion1;
	Usuario us;
	tConfig c;
	sqlite3 *db;
	int esAdmin;
	sqlite3_open("gestion.sqlite", &db);
	//Cliente cl;
	cargarConfig(&c);
	crearTablaAdministrador(&db);
	do{
			opcion = mostrarMenu();
			switch(opcion){
			case '1':
				us = pedirDatosInicio();
				printf("%s\n",us.correoElectronico);
				esAdmin = buscarUsuario(db, us.correoElectronico);
				if(esAdmin == 1){
					do{
						opcion1 = menuAdministrador();
						switch(opcion1){
							case '1': mostrarVuelos(db);// mostrar viajes
							break;
							case '2':modificarReservas(db);// editar las reservas
							break;
							case '3':visualizarReservas(db);// visulaizar las reservas
							break;
							case '4':
								mostrarAdministradores(db);// mostrarAdministradores
							break;
							case '5':
								// editar tablas de la base de datos
								//preguntar que tabla quiere editar.
							break;
							case '6':cargarConfig(&c);// visualizar el fichero de configuración
							break;
							case'7':
							printf("Cerrando sesion\n");
							fflush(stdout);
							break;

						}
					}while(opcion1!='7');

				}else{
					//menuUsuario();
				}
				break;
			case '2':
				opcion1=mostrarMenuRegistrar();
				switch(opcion1){
				case'1':
					registarA(&us);
					guardarAdmin(us);
					insertarAdministrador(db, us.dni, us.nombre, us.apellidos, us.correoElectronico, us.contrasenia);
					break;
				case'2':
					//registrar usuario
					break;
				}
				break;
			case '3':
				printf("Cerrando sesion...\n");
				fflush(stdout);
				break;
			default: printf("ERROR! La opcion seleccionada no es correcta \n");
			fflush(stdin);
			}
	}while(opcion=='3');
	sqlite3_close(db);
		return EXIT_SUCCESS;

}
Usuario pedirDatosInicio(){

	Usuario us;
	printf("Introduce el correo electronico:");
	fflush(stdout);
	fflush(stdin);
	gets(us.correoElectronico);
	printf("Introduce la contraseña:");
	fflush(stdout);
	fflush(stdin);
	gets(us.contrasenia);
	return us;

}

void registarA(Usuario *u)
{
		printf("Introduce tu dni: ");
		fflush(stdout);
		fflush(stdin);
		gets(u->dni);
		printf("Introduce tu nombre: ");
		fflush(stdout);
		fflush(stdin);
		gets(u->nombre);
		printf("Introduce tus apellidos: ");
		fflush(stdout);
		fflush(stdin);
		gets(u->apellidos);
		printf("Introduce tu email: ");
		fflush(stdout);
		fflush(stdin);
		gets(u->correoElectronico);
		printf("Introduce tu contraseÃ±a: ");
		fflush(stdout);
		fflush(stdin);
		gets(u->contrasenia);

}

