
#ifndef BBDD_H_
#define BBDD_H_
#include "sqlite3.h"

void crearTablas(sqlite3 *db);
void anadirPersona(sqlite3 *db, int id, char *nom);
void borrarPersona(sqlite3 *db, int id);
void mostrarPersonas(sqlite3 *db);
//void modificarNombre(sqlite3 *db, int id, char *nom);
//void borrarTodasLasPersonas(sqlite3 *db);
#endif /* BBDD_H_ */
