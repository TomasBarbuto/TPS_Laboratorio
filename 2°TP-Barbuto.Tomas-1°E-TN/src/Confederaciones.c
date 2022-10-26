#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Confederaciones.h"

int iniciarConfederacion(eConfederacion arrayConfederaciones[]){

	int retorno = 0;

	if(arrayConfederaciones != NULL){

		arrayConfederaciones[0].id = 100;
		strncpy(arrayConfederaciones[0].nombre,"CONMEBOL", 50);
		strncpy(arrayConfederaciones[0].region,"SUDAMERICA", 50);
		arrayConfederaciones[0].anioCreacion = 1916;

		arrayConfederaciones[1].id = 101;
		strncpy(arrayConfederaciones[1].nombre,"UEFA", 50);
		strncpy(arrayConfederaciones[1].region,"EUROPA", 50);
		arrayConfederaciones[1].anioCreacion = 1954;

		arrayConfederaciones[2].id = 102;
		strncpy(arrayConfederaciones[2].nombre,"AFC", 50);
		strncpy(arrayConfederaciones[2].region,"ASIA", 50);
		arrayConfederaciones[2].anioCreacion = 1954;

		arrayConfederaciones[3].id = 103;
		strncpy(arrayConfederaciones[3].nombre,"CAF", 50);
		strncpy(arrayConfederaciones[3].region,"AFRICA", 50);
		arrayConfederaciones[3].anioCreacion = 1957;

		arrayConfederaciones[4].id = 104;
		strncpy(arrayConfederaciones[4].nombre,"CONCACAF", 50);
		strncpy(arrayConfederaciones[4].region,"NORTE Y CENTRO AMERICA", 50);
		arrayConfederaciones[4].anioCreacion = 1961;

		arrayConfederaciones[5].id = 105;
		strncpy(arrayConfederaciones[5].nombre,"OFC", 50);
		strncpy(arrayConfederaciones[5].region,"OCEANIA", 50);
		arrayConfederaciones[5].anioCreacion = 1966;

		retorno = 1;
	}
	return retorno;
}

int listarConfederaciones(eConfederacion arrayConfederaciones[], int longitud) {

	int retorno = 0;

	if (arrayConfederaciones != NULL && longitud > 0) {

		printf("Los Tipos actuales son: \n\n");

		for (int i = 0; i < longitud; i++) {

			printf("ID: %d, %s, %s, %d\n", arrayConfederaciones[i].id, arrayConfederaciones[i].nombre,arrayConfederaciones[i].region,
					arrayConfederaciones[i].anioCreacion);

		}
		retorno = 1;
	}

	return retorno;
}
