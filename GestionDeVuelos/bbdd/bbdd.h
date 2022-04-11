
#ifndef BBDD_H_
#define BBDD_H_
#include "sqlite3.h"

void crearTablaAdministrador(sqlite3 *db);
void insertarAdministrador(sqlite3 *db, char *dni, char *nombre, char *apellidos, char *correoElectronico, char *contrasenia);
void borrarAdministrador(sqlite3 *db, char *dni);
void mostrarAdministradores(sqlite3 *db);
//void modificarNombre(sqlite3 *db, int id, char *nom);
//void borrarTodasLasPersonas(sqlite3 *db);
#endif /* BBDD_H_ */
