/*
 * configuracion.c
 *
 *  Created on: 11 abr. 2022
 *      Author: BSILV
 */


#include "configuracion.h"
#include <stdio.h>

void cargarConfig(tConfig *c){
	FILE *pf;

	pf = fopen("Config.txt","r");
	if(pf!=(FILE*)NULL){
		fscanf(pf,"%s %d %s",c->ip,&c->puerto,c->ruta);
	}
}
