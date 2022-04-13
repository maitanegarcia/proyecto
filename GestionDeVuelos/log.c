#include "log.h"

void log(char * mensaje){
	fprintf (stderr, "%s\n",mensaje);
}

void warning(char * mensaje){
	char cadena[200];
	sprintf(cadena,"/!\\ %s /!\\", mensaje);
	log(cadena);
}

void error(char * mensaje){
	char cadena[200];
	sprintf(cadena,"(X) %s (X)", mensaje);
	log(cadena);

}
