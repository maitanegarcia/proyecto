#include "bbdd.h"
#include <stdio.h>
#include <string.h>


int buscarUsuario(sqlite3 *db, char *correoElectronico){
	sqlite3_stmt *stmt;
	char sql[100];
	int esAdmin;

	sprintf(sql, "SELECT esAdmin FROM USuario WHERE email = '%s'",correoElectronico);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	esAdmin = sqlite3_column_int(stmt, 1);
	sqlite3_finalize(stmt);

	return esAdmin;
}


void crearTablaAdministrador(sqlite3 *db)
{
	sqlite3_stmt *stmt;


	//Como poner los valores si tenemos *nombre, *apellidos, *correoElectronico
	char sql1[] = "CREATE TABLA ADMINISTRADOR(dni varchar2(10), nombre varchar2(20), apellidos varchar2(40), correoElectronico varchar2(30), contrasenia varchar2(30))";
	sqlite3_prepare_v2(db, sql1, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void insertarAdministrador(sqlite3 *db, char *dni, char *nombre, char *apellidos, char *correoElectronico, char *contrasenia)
{
	sqlite3_stmt *stmt;
	char sql1[100];
	//No estoy seguro si tiene que ser 100, osea, constante

	sprintf(sql1, "INSERT INTO ADMINISTRADOR VALUES('%s', '%s', '%s', '%s', '%s')", dni, nombre, apellidos, correoElectronico, contrasenia);
	sqlite3_prepare_v2(db, sql1, -1, &stmt, NULL) ;
	//ASI LO TIENE PUESTO ASIER       sqlite3_prepare_v2(db, sql1, strlen(sql1) + 1, &stmt, NULL)
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}


void mostrarAdministradores(sqlite3 *db)
{
	sqlite3_stmt *stmt;
	int step, *dni;
	char sql[100], *nombre, *apellidos, *correoElectronico, *contrasenia;

	sprintf(sql,"SELECT * FROM ADMINISTRADOR");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;

	do
	{
		step = sqlite3_step(stmt);
		dni = sqlite3_column_int(stmt, 0);
		strcpy(nombre, (char*)sqlite3_column_text(stmt, 1));
		strcpy(apellidos, (char*)sqlite3_column_text(stmt, 2));
		strcpy(correoElectronico, (char*)sqlite3_column_text(stmt, 3));
		strcpy(contrasenia, (char*)sqlite3_column_text(stmt, 4));
		printf("%s %s %s %s %s\n", dni, nombre, apellidos, correoElectronico, contrasenia);

	}
	while(step == SQLITE_ROW);

	sqlite3_finalize(stmt);

}

void borrarAdministradorBBDD(sqlite3 *db, char *dni){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "DELETE FROM ADMINISTRADOR WHERE DNI = '%s'",dni);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
