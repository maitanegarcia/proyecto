#include <stdio.h>
#include "administrador/administrador.h"




/*main.c*/

#include "menuPrincipal/menuPrincipal.h"


int main ( void){

	char opcion;
	opcion=mostrarMenu();
	switch (opcion){
				case '1':
					//inicioSesion();
					break;
				case '2':
					//registrarse();
					break;
				case'3':
					//salir();
					break;
			while(opcion != '3');
				//liberarMemoria();

			return 0;
	}
}
