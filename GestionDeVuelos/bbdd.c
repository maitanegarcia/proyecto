#include "bbdd.h"
#include "sqlite3.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//------------------------------------------------------------------------------------------
/*
 * 1. BUSCAR USUARIO
 * 2. CREAR TABLA USUARIO
 * 2. A�ADIR USUARIO
 * 3. MOSTRAR USUARIO
 * 4. BORRAR USUARIO
 *
 */
int buscarUsuario(sqlite3 *db, char *correoElectronico)
{
	sqlite3_stmt *stmt;
	char sql[100];
	int esAdmin;


	sprintf(sql, "SELECT esAdmin FROM USuario WHERE email = '%s'",correoElectronico);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	esAdmin = sqlite3_column_int(stmt, 5);

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return esAdmin;
}


/*
 *
 *
 * como metemos el esAdmi
 *
 *
 *
 *
 */
//crear tabla administrador
void crearTablaUsuario(sqlite3 *db)
{
	sqlite3_stmt *stmt;
	sqlite3_open("gestorvuelos",db);

	//Como poner los valores si tenemos *nombre, *apellidos, *correoElectronico
	char sql1[] = "CREATE TABLA USUARIO(dni varchar2(10), nombre varchar2(20), apellidos varchar2(40), correoElectronico varchar2(30), contrasenia varchar2(30),esAdmin int";
	sqlite3_prepare_v2(db, sql1, -1, &stmt, NULL) ;
	sqlite3_step(stmt);

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}


//INSERTAR ADMINITRADOR
void insertarUSUARIOAdministrador(sqlite3 *db, char *dni, char *nombre, char *apellidos, char *correoElectronico, char *contrasenia,int esAdmin)
{
	sqlite3_stmt *stmt;
	char sql1[100];
	//No estoy seguro si tiene que ser 100, osea, constante


	sprintf(sql1, "INSERT INTO USUARIO VALUES('%s', '%s', '%s', '%s', '%s',%d)", dni, nombre, apellidos, correoElectronico, contrasenia,esAdmin);
	sqlite3_prepare_v2(db, sql1, -1, &stmt, NULL) ;
	//ASI LO TIENE PUESTO ASIER       sqlite3_prepare_v2(db, sql1, strlen(sql1) + 1, &stmt, NULL)
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

//MOSTRAR ADMINISTRADOR
void mostrarUsuario(sqlite3 *db)
{
	sqlite3_stmt *stmt;
	int step,*esAdmin;
	char sql[100], *dni,*nombre, *apellidos, *correoElectronico, *contrasenia;

	sprintf(sql,"SELECT * FROM ADMINISTRADOR");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;

	do
	{
		step = sqlite3_step(stmt);
		dni = sqlite3_column_text(stmt, 0);
		strcpy(nombre, (char*)sqlite3_column_text(stmt, 1));
		strcpy(apellidos, (char*)sqlite3_column_text(stmt, 2));
		strcpy(correoElectronico, (char*)sqlite3_column_text(stmt, 3));
		strcpy(contrasenia, (char*)sqlite3_column_text(stmt, 4));
		strcpy(esAdmin,(int)sqlite3_column_int(stmt, 5));
		printf("%s %s %s %s %s\n", dni, nombre, apellidos, correoElectronico, contrasenia,esAdmin);

	}
	while(step == SQLITE_ROW);

	sqlite3_finalize(stmt);
	sqlite3_close(db);

}

void borrarAdministradorBBDD(sqlite3 *db, char *correoElectronico, char *esAdmin)
{

	sqlite3_stmt *stmt;
	char sql[100];
	printf("Si desea borrar el adminitrador , introduzca el 1");
	fflush(stdout);
	fflush(stdin);
	sprintf(sql, "DELETE FROM USUARIO WHERE DNI = '%s' AND ESADMIN=%d",correoElectronico,esAdmin);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

//------------------------------------------------------------------------------------------
/*
 * 1. A�ADIR VUELOS
 * 2. MOSTRAR VUELOS
 * 3. BORRAR VUELOS
 */


void aniadirVuelo(sqlite3 *db, char idVuelo, int fecha, int hora, int plazas, char *codC)
{
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "INSERT INTO VUELO VALUES (%i,%i,%i,%i,%s,%s)", idVuelo, fecha, hora, plazas, codC);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void mostrarVuelo(sqlite3 *db) {
	int resul,id, fecha, hora, plazas;
	sqlite3_stmt *stmt;
	char sql[100], *cOrigen, *cDestino;

	sprintf(sql,"SELECT *FROM VUELO");
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

void borrarVuelo(sqlite3 *db, int idVuelo) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "DELETE FROM VUELO WHERE IDVUELO = %d", idVuelo);
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
//------------------------------------------------------------------------------------------
/*
 * 1. A�ADIR COMPA�IA
 * 2.MOSTRAR COMPA�IA
 * 3.BORRAR COMPA�IA
 */
void aniadirCompania(sqlite3 *db, int cod, char *nombre) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "INSERT INTO COMPANIA VALUES(%i,%s)", cod, nombre);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
void mostrarCompania(sqlite3 *db) {
	int resul, cod;
	sqlite3_stmt *stmt;
	char sql[100], *nom;

	sprintf(sql,"SELECT *FROM COMPANIA");
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
	sprintf(sql, "DELETE FROM COMPANIA WHERE COD_COMP = %d",cod);
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
//------------------------------------------------------------------------------------------
/*
 * 1. A�ADIR BILLETE
 * 2.MOSTRAR BILLETE
 * 3.BORRAR BILLETE
 */
void aniadirBillete(sqlite3 *db, int codBillete, char *asiento, char codClase, char dni, char idVuelo) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "INSERT INTO BILLETE VALUES(%s,%s,%s,%s,%s)", codBillete, asiento, asiento, codClase, dni, idVuelo);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
void mostrarBillete(sqlite3 *db) {
	int resul;
	sqlite3_stmt *stmt;
	char sql[100], *asiento,*codBillete,*cliente,*clase,*vuelo;

	sprintf(sql,"SELECT *FROM BILLETE");
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	do {
		resul = sqlite3_step(stmt);
		strcpy(codBillete, (char*)sqlite3_column_text(stmt, 0));
		strcpy(asiento, (char*)sqlite3_column_text(stmt, 1));
		strcpy(clase, (char*)sqlite3_column_text(stmt, 2));
		strcpy(cliente, (char*)sqlite3_column_text(stmt, 3));
		strcpy(vuelo, (char*)sqlite3_column_text(stmt, 4));
		printf("%s %s %s %s %s\n",codBillete, asiento, clase, cliente, vuelo);
	} while (resul == SQLITE_ROW);
	sqlite3_finalize(stmt);
	}
}
void borrarBillete(sqlite3 * db, char* codBillete) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "DELETE FROM BILLETE WHERE COD_B = %s",codBillete);
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
//------------------------------------------------------------------------------------------
/*
 * 1. A�ADIR CUIDAD
 * 2.MOSTRAR CUIDAD
 * 3.BORRAR CUIDAD
 */
void aniadirCiudad(sqlite3 *db, char *codC, char *nombreCiudad) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "INSERT INTO CIUDAD VALUES('%s','%s','%s','%s')",codO,codD,nombreCiudadO , nombreCiudadD);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
void mostrarCiudad(sqlite3 *db) {
	int resul;
	sqlite3_stmt *stmt;
	char sql[100], *codO,*codD, *nombreCiudadO ,*nombreCiudadD;

	sprintf(sql,"SELECT * FROM CIUDAD");
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	do {
		resul = sqlite3_step(stmt);
		strcpy(codO, (char*)sqlite3_column_text(stmt, 0));
		strcpy(codD, (char*)sqlite3_column_text(stmt, 1));
		strcpy(nombreCiudadO, (char*)sqlite3_column_text(stmt, 2));
		strcpy(nombreCiudadD, (char*)sqlite3_column_text(stmt, 3));
		printf("%s %s %s %s\n",codO,codD, nombreCiudadO,nombreCiudadD);
	} while (resul == SQLITE_ROW);
	sqlite3_finalize(stmt);
}
void borrarCiudad(sqlite3 * db,char *codC) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "DELETE FROM CIUDAD WHERE COD_CIUD = %s",codC);
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
//------------------------------------------------------------------------------------------
/*
 * 1. A�ADIR CLASE
 * 2.MOSTRAR CLASE
 * 3.BORRAR CLASE
 */
void aniadirClase(sqlite3 *db, char codClase, char *nomClase) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "INSERT INTO CLASE VALUES (%s,'%s')", cod, nomClase);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
void mostrarClase(sqlite3 *db) {
	int resul ;
	sqlite3_stmt *stmt;
	char sql[100],*cod, *nomClase;

	sprintf(sql,"SELECT *FROM CLASE");
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	do {
		resul = sqlite3_step(stmt);
		strcpy(cod, (char*)sqlite3_column_text(stmt, 0));
		strcpy(nomClase, (char*)sqlite3_column_text(stmt, 1));
		printf("%s %s\n",cod, nomClase);
	} while (resul == SQLITE_ROW);
	sqlite3_finalize(stmt);
}
void borrarClase(sqlite3 * db, char codClase) {
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "DELETE FROM CLASE WHERE COD_CLASE = %s",cod);
	sqlite3_prepare_v2(db, sql,-1,&stmt,NULL);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
//------------------------------------------------------------------------------------------
/*
 * 1. A�ADIR RESERVAS
 * 2.MOSTRAR RESERVAS
 * 3.BORRAR RESERVAS
 * 4.MODIFICAR RESERVAS
 */
//void anadirReserva(sqlite3 *db, char *cod,char *codO,char *codD, int fecha, int hora,int nump, char *codClase){
//	sqlite3_stmt *stmt;
//
//	char sql[100];
//
//	sprintf(sql, "INSERT INTO RESERVAS VALUES('%s','%s','%s',%d,%d,%d,'%s')",cod,codO,codD,fecha,hora,nump,codClase);
//	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
//	sqlite3_step(stmt);
//	sqlite3_finalize(stmt);
//}
//void mostrarReservas(sqlite3 *db){
//	int resul,fecha,hora;
//		sqlite3_stmt *stmt;
//		char sql[100],*cod,*codO,*codD,*codClase;
//
//
//		sprintf(sql,"SELECT *FROM RESERVAS");
//		sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
//
//		do{
//			resul = sqlite3_step(stmt);
//			strcpy(cod ,(char*) sqlite3_column_int(stmt, 0));
//			strcpy(codO, (char*)sqlite3_column_text(stmt, 1));
//			strcpy(codD, (char*)sqlite3_column_text(stmt, 2));
//			fecha =sqlite3_column_int(stmt, 3);
//			hora =sqlite3_column_int(stmt, 4);
//			strcpy(codClase, (char*)sqlite3_column_text(stmt, 5));
//
//			printf("%s %s %s %d %d %s\n",cod,codO,codD,fecha,hora,codClase);
//		}while(resul == SQLITE_ROW);
//		sqlite3_finalize(stmt);
//
//}
