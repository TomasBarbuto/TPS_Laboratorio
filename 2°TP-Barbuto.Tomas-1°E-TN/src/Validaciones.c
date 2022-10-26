#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"


/**
*\brief: Pide un numero y valida que sea int y que este dentro de un rango
*\param: puntero a int , array de char , array de char, rango minimo, rango maximo.
*\return: Retorna 1 si cargo con exito y 0 si hubo algun error.
**/

int getNumber(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo) {

	int retorno = 0;
	int bufferInt; //Con esto interactuamos con el usuario.

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo < maximo) {

		do {

			printf("%s", mensaje);
			fflush(stdin);
			scanf("%d", &bufferInt);

			if (bufferInt >= minimo && bufferInt <= maximo) {

				*pResultado = bufferInt;
				retorno = 1;
				break;

			} else {

				printf("%s", mensajeError);
				system("pause");

			}

		} while (retorno == 0);
	}

	return retorno;
}

/**
*\brief: Pide un numero flotante y valida que este dentro de un rango y que sea del tipo float.
*\param: puntero a float,  array de char , array de char, rango minimo, rango maximo.
*\return: Retorna 1 si cargo con exito y 0 si hubo algun error.
**/

int getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo,
		float maximo) {

	int retorno = 0;
	float buffer; //Con esto interactuamos con el usuario.

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo < maximo) {

		do {

			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &buffer);

			if (buffer >= minimo && buffer <= maximo) {

				*pResultado = buffer;
				retorno = 1;
				break;

			} else {

				printf("%s", mensajeError);

			}

		} while (retorno == 0);
	}

	return retorno;
}

/**
*\brief: Pide un array de char y valida que haya espacio para copiarlo.
*\param: Array de char, array de char, array de char, entero indicando espacio.
*\return: Retorna 1 si cargo con exito y 0 si hubo algun error.
**/
int getString(char pResultado[], char *mensaje, char *mensajeError, int EspacioChar) {

	int retorno = 0;
	char buffer[EspacioChar]; //Con esto interactuamos con el usuario.

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL) {

		do {

			printf("%s", mensaje);
			fflush(stdin);
			fgets(buffer, sizeof(buffer)-1, stdin);

			if(strlen(buffer) <= sizeof(buffer)-1) {

				for(int i = 0; i < sizeof(buffer); i++){

					if(buffer[i] == '\n'){

						buffer[i] = '\0';
					}
				}
				strcpy(pResultado,buffer);
				retorno = 1;
				break;

			} else {

				printf("%s", mensajeError);

			}

		} while (retorno == 0);
	}

	return retorno;
}

int getShort(short *pResultado, char *mensaje, char *mensajeError, short minimo,
		short maximo) {

	int retorno = 0;
	short buffer; //Con esto interactuamos con el usuario.

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo < maximo) {

		do {

			printf("%s", mensaje);
			fflush(stdin);
			scanf("%hd", &buffer);

			if (buffer >= minimo && buffer <= maximo) {

				*pResultado = buffer;
				retorno = 1;
				break;

			} else {

				printf("%s", mensajeError);
				system("pause");

			}

		} while (retorno == 0);
	}

	return retorno;
}

int getFloatSinLimite(float *pResultado, char *mensaje, char *mensajeError) {

	int retorno = 0;
	float buffer; //Con esto interactuamos con el usuario.
	int confirmar;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL) {

		do {

			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &buffer);
			printf("$%.2f Ingrese 1 si el valor ingresado es valido y quiere seguir\nOpcion: ",buffer);
			scanf("%d",&confirmar);

			if (confirmar == 1) {

				*pResultado = buffer;
				retorno = 1;
				break;

			} else {

				printf("%s", mensajeError);

			}

		} while (retorno == 0);
	}

	return retorno;
}
