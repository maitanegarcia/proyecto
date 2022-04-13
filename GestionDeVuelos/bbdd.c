#include "bbdd.h"
#include <stdio.h>
#include <string.h>
/*
 * BUSCAR USUARIO
 */
int buscarUsuario(sqlite3 *db, char *correoElectronico){
	sqlite3_stmt *stmt;
	char sql[100];
	int esAdmin;

	sqlite3_open("gestorvuelos",db);
	sprintf(sql, "SELECT esAdmin FROM USuario WHERE email = '%s'",correoElectronico);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	esAdmin = sqlite3_column_int(stmt, 1);

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return esAdmin;
}
//------------------------------------------------------------------------------------------
/*
 * 1. AÑADIR ADMINISTRADOR
 * 2.MOSTRAR ADMINISTRADOR
 * 3.BORRAR ADMINISTRADOR
 *
 */
//crear tabla administrador
void crearTablaAdministrador(sqlite3 *db)
{
	sqlite3_stmt *stmt;

	sqlite3_open("gestorvuelos",db);
	//Como poner los valores si tenemos *nombre, *apellidos, *correoElectronico
	char sql1[] = "CREATE TABLA ADMINISTRADOR(dni varchar2(10), nombre varchar2(20), apellidos varchar2(40), correoElectronico varchar2(30), contrasenia varchar2(30))";
	sqlite3_prepare_v2(db, sql1, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}


//INSERTAR ADMINITRADOR
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

//MOSTRAR ADMINISTRADOR
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
//BORRAR ADMINISTRADOR
void borrarAdministradorBBDD(sqlite3 *db, char *dni){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "DELETE FROM ADMINISTRADOR WHERE DNI = '%s'",dni);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

//------------------------------------------------------------------------------------------
/*
 * 1. AÑADIR VUELOS
 * 2.MOSTRAR VUELOS
 * 3.BORRAR VUELOS
 */


void aniadirVuelo(sqlite3 *db, int id, int fecha, int hora, int plazas, char *cOrigen, char *cDestino) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "insert into vuelo values(%i,%i,%i,%i,%s,%s)", id, fecha, hora, plazas, cOrigen, cDestino);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void mostrarVuelo(sqlite3 *db) {
	int resul,id, fecha, hora, plazas;
	sqlite3_stmt *stmt;
	char sql[100], *cOrigen, *cDestino;

	sprintf(sql,"select * from vuelo");
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	do {
		resul = sqlite3_step(stmt);
		id = sqlite3_column_int(stmt, 0);
		fecha = sqlite3_column_int(stmt, 1);
		hora = sqlite3_column_int(stmt, 2);
		plazas = sqlite3_column_int(stmt, 3);
		strcpy(cOrigen, (char*)sqlite3_column_text(stmt, 4));
		strcpy(cDestino, (char*)sqlite3_column_text(stmt,5));
		printf("%i %i %i %i %s %s\n",id,fecha,hora,plazas,cOrigen,cDestino);
	} while (resul == SQLITE_ROW);
	sqlite3_finalize(stmt);
}

void borrarVuelo(sqlite3 *db, int id) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "delete from persona where cod_vu = %d", id);
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
//------------------------------------------------------------------------------------------
/*
 * 1. AÑADIR COMPAÑIA
 * 2.MOSTRAR COMPAÑIA
 * 3.BORRAR COMPAÑIA
 */
void aniadirCompania(sqlite3 *db, int cod, char *nom) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "insert into compania values(%i,%s)", cod, nom);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
void mostrarCompania(sqlite3 *db) {
	int resul, cod;
	sqlite3_stmt *stmt;
	char sql[100], *nom;

	sprintf(sql,"select * from compania");
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
		do {
			resul = sqlite3_step(stmt);
			cod = sqlite3_column_int(stmt, 0);
			strcpy(nom, (char*)sqlite3_column_text(stmt, 1));
			printf("%i %s\n",cod, nom);
		} while (resul == SQLITE_ROW);
		sqlite3_finalize(stmt);
}
void borrarCompania(sqlite3 * db, int cod) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "delete from compania where cod_comp = %d",cod);
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
//------------------------------------------------------------------------------------------
/*
 * 1. AÑADIR BILLETE
 * 2.MOSTRAR BILLETE
 * 3.BORRAR BILLETE
 */
void aniadirBillete(sqlite3 *db, int codBillete, char *asiento, int clase, int cliente, int vuelo) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "insert into billete values(%i,%s,%i,%i,%i)", codBillete, asiento, clase, cliente, vuelo);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
void mostrarBitelle(sqlite3 *db) {
	int resul, codBillete,cliente,clase,vuelo;
	sqlite3_stmt *stmt;
	char sql[100], *asiento;

	sprintf(sql,"select * from billete");
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	do {
		resul = sqlite3_step(stmt);
		codBillete = sqlite3_column_int(stmt, 0);
		strcpy(asiento, (char*)sqlite3_column_text(stmt, 1));
		clase = sqlite3_column_int(stmt, 2);
		cliente = sqlite3_column_int(stmt, 3);
		vuelo = sqlite3_column_int(stmt, 4);
		printf("%i %s %i %i %i\n",codBillete, asiento, clase, cliente, vuelo);
	} while (resul == SQLITE_ROW);
	sqlite3_finalize(stmt);
	}
}
void borrarBillete(sqlite3 * db, int codBillete) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "delete from billete where cod_b = %d",codBillete);
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
//------------------------------------------------------------------------------------------
/*
 * 1. AÑADIR CUIDAD
 * 2.MOSTRAR CUIDAD
 * 3.BORRAR CUIDAD
 */
void aniadirCiudad(sqlite3 *db, int cod, char *nombreCiudad) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "insert into ciudad values(%i,%s)", cod, nombreCiudad);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
void mostrarCiudad(sqlite3 *db) {
	int resul, cod;
	sqlite3_stmt *stmt;
	char sql[100], *nombreCiudad;

	sprintf(sql,"select * from ciudad");
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	do {
		resul = sqlite3_step(stmt);
		cod = sqlite3_column_int(stmt, 0);
		strcpy(nombreCiudad, (char*)sqlite3_column_text(stmt, 1));
		printf("%i %s\n",cod, nombreCiudad);
	} while (resul == SQLITE_ROW);
	sqlite3_finalize(stmt);
}
void borrarCiudad(sqlite3 * db, int cod) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "delete from ciudad where cod_ciud = %d",cod);
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
//------------------------------------------------------------------------------------------
/*
 * 1. AÑADIR CLASE
 * 2.MOSTRAR CLASE
 * 3.BORRAR CLASE
 */
void aniadirClase(sqlite3 *db, int cod, char *nomClase) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "insert into clase values(%i,%s)", cod, nomClase);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
void mostrarClase(sqlite3 *db) {
	int resul, cod;
	sqlite3_stmt *stmt;
	char sql[100], *nomClase;

	sprintf(sql,"select * from clase");
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	do {
		resul = sqlite3_step(stmt);
		cod = sqlite3_column_int(stmt, 0);
		strcpy(nomClase, (char*)sqlite3_column_text(stmt, 1));
		printf("%i %s\n",cod, nomClase);
	} while (resul == SQLITE_ROW);
	sqlite3_finalize(stmt);
}
void borrarClase(sqlite3 * db, int cod) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "delete from clase where cod_clase = %d",cod);
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
