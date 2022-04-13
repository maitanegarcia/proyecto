
#ifndef BBDD_H_
#define BBDD_H_
#include "sqlite3.h"

int buscarUsuario(sqlite3 *db, char *correoElectronico); //Devuelve un 0 si es un usuario normal y un 1 si es un admin
void crearTablaUsuario(sqlite3 *db);
void insertarUsuario(sqlite3 *db, char *dni, char *nombre, char *apellidos, char *correoElectronico, char *contrasenia, int esAdmin);
void mostrarUsuario(sqlite3 *db);
void borrarUsuarioBBDD(sqlite3 *db, char *correoElectronico, char *esAdmin);

//void modificarNombre(sqlite3 *db, int id, char *nom);
//void borrarTodasLasPersonas(sqlite3 *db);

void aniadirVuelo(sqlite3 *db, char idVuelo, int fecha, int hora, int plazas, char *codC);
void mostrarVuelo(sqlite3 *db);
void borrarVuelo(sqlite3 *db, char idVuelo);

void aniadirCompania(sqlite3 *db, char cod, char *nombre);
void mostrarCompania(sqlite3 *db);
void borrarCompania(sqlite3 * db, char cod);

void aniadirBillete(sqlite3 *db, int codBillete, char *asiento, char codClase, char dni, char idVuelo);
void mostrarBitelle(sqlite3 *db);
void borrarBillete(sqlite3 * db, int codBillete);

void aniadirCiudad(sqlite3 *db, char *codC, char *nombreCiudad);
void mostrarCiudad(sqlite3 *db);
void borrarCiudad(sqlite3 * db, char *codC);

void aniadirClase(sqlite3 *db, char codClase, char *nomClase);
void mostrarClase(sqlite3 *db);
void borrarClase(sqlite3 * db, char codClase);
#endif /* BBDD_H_ */
