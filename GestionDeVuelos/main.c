/*llamar a todas las funciones*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuPrincipal/menuPrincipal.h"
#include "administrador/administrador.h"


#include "registrar/registrar.h"



int main(void){
	char opcion;

	//Cliente cl;
	do{
			opcion = mostrarMenu();
			switch(opcion){
			case '1':
				//iniciarSesion();
				break;
			case '2':
				mostrarMenuRegistrar();

				break;
			case '3':
				printf("Cerrando sesión...\n");
				fflush(stdout);
				break;
			default: printf("ERROR! La opción seleccionada no es correcta \n");
			fflush(stdin);
			}
	}while(opcion=='3');
		return EXIT_SUCCESS;
}
//int mostrarMenuRegistrar(){
//	Administrador ad;
//
//	char opcion;
//	printf("Opcion:\n");
//	printf("1.Registrar Administrador\n");
//	printf("2.Registrar Cliente\n");
//	fflush(stdout);
//	fflush(stdin);
//	scanf("%c",&opcion);
//	switch(opcion){
//			case '1':
//				registarAdministrador();
//				break;
//			case '2':
//				// registrar usuario
//				break;
//			case '3':
//			printf("Cerrando sesión...\n");
//			fflush(stdout);
//	}while(opcion !='3');
//	return EXIT_SUCCESS;
//
//}
