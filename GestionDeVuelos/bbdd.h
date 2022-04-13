
#ifndef BBDD_H_
#define BBDD_H_
#include "sqlite3.h"

void crearTablaAdministrador(sqlite3 *db);
void insertarAdministrador(sqlite3 *db, char *dni, char *nombre, char *apellidos, char *correoElectronico, char *contrasenia);
void borrarAdministradorBBDD(sqlite3 *db, char *dni);
void mostrarAdministradores(sqlite3 *db);
int buscarUsuario(sqlite3 *db, char *email); //Devuelve un 0 si es un usuario normal y un 1 si es un admin
//void modificarNombre(sqlite3 *db, int id, char *nom);
//void borrarTodasLasPersonas(sqlite3 *db);
void aniadirVuelo(sqlite3 *db, int id, int fecha, int hora, int plazas, char *cOrigen, char *cDestino);
void mostrarVuelo(sqlite3 *db);
void borrarVuelo(sqlite3 *db, int id);

void aniadirCompania(sqlite3 *db, int cod, char *nom);
void mostrarCompania(sqlite3 *db);
void borrarCompania(sqlite3 * db, int cod);

void aniadirBillete(sqlite3 *db, int codBillete, char *asiento, int clase, int cliente, int vuelo) {
void mostrarBitelle(sqlite3 *db);
void borrarBillete(sqlite3 * db, int codBillete);

void aniadirCiudad(sqlite3 *db, int cod, char *nombreCiudad);
void mostrarCiudad(sqlite3 *db);
void borrarCiudad(sqlite3 * db, int cod);

void aniadirClase(sqlite3 *db, int cod, char *nomClase);
void mostrarClase(sqlite3 *db);
void borrarClase(sqlite3 * db, int cod);
#endif /* BBDD_H_ */
