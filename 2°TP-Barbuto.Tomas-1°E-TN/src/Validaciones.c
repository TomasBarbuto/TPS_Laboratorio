#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"

/**
*\brief: Verifica que lo que recibe por parametro sea un numero.
*\param: puntero a char.
*\return: 1 bien, 0 ERRO.
**/
int esUnNumero(char cadena[]){

	int retorno = 0;

	if (cadena != NULL && strlen(cadena) > 0) {

		if(cadena[strlen(cadena)] == '\n'){

			cadena[strlen(cadena)] = '\0';
		}

		for (int i = 0; i < strlen(cadena); i++) {

			if (cadena[i] < '0' || cadena[i] > '9') {

				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

/**
*\brief: Recibe un dato por consola y verificar si es numero.
*\param: puntero a int
*\return: 1 bien, 0 ERROR.
**/
int getNumero(int *pResultado) {

	int retorno = 0;
	char buffer[1024];

	fflush(stdin);
	fgets(buffer, sizeof(buffer), stdin);


	if (esUnNumero(buffer)) {

		*pResultado = atoi(buffer);
		retorno = 1;

	}
	return retorno;
}

/**
*\brief: retorna un numero por puntero a int si asi fuese, sino printea mensajes de error.
*\param: puntero a int, puntero a char, puntero a char, int, int, int.
*\return: retorna 1 bien, 0 ERROR.
**/
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {

	int retorno;
	int numero;

	while (reintentos > 0) {

		printf("%s", mensaje);

		if (getNumero(&numero)) {

			if (numero <= maximo && numero >= minimo){

				break;
			}
		}
		reintentos--;
		printf("%s", mensajeError);
	}

	if (reintentos == 0) {

		retorno = 0;

	}else{

		retorno = 1;
		*pResultado = numero;
	}
	return retorno;
}

/**
*\brief: obtiene un short por puntero y verificar que sea correcto.
*\param: puntero a short, puntero a char, puntero a char, int , int, int.
*\return: retorna 1 bien, 0 ERROR.
**/
int utn_getNumeroShort(short *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos){

	int retorno;
	int numero;
	while (reintentos > 0) {
		printf("%s", mensaje);

		if (getInt(&numero)) {

			if (numero <= maximo && numero >= minimo) {
				break;
			}
		}
		reintentos--;
		printf("%s", mensajeError);
	}
	if (reintentos == 0) {
		retorno = 0;
	} else {
		retorno = 1;
		*pResultado = numero;
	}
	return retorno;
}

/**
*\brief: recibe un float por paramentro y valida que sea correcto.
*\param: puntero a float.
*\return: retorna 0 para bien, -1 ERROR.
**/
int getFloat(float *pResultado) {
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL) {
		if (getStringg(buffer, sizeof(buffer)) && esFlotante(buffer)) {
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

/**
*\brief: recibe un puntero a char y verifica si lo ingresado es flotante
*\param: puntero a char
*\return: retorna 1 bien, 0 ERROR.
**/
int esFlotante(char *cadena) {

	int i = 0;
	int retorno = 1;
	int contadorPuntos = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		for (i = 0; cadena[i] != '\0'; i++) {
			if (i == 0 && (cadena[i] == '-' || cadena[i] == '+')) {
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				if (cadena[i] == '.' && contadorPuntos == 0) {
					contadorPuntos++;
				} else {
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/**
*\brief: valida que lo recibido por parametro coincida con un float.
*\param: puntero a float. puntero a char, puntero a char, float, float, int
*\return: retorna 1 bien, 0 ERROR.
**/
int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError,
							float minimo, float maximo, int reintentos) {
	float bufferFloat;
	int retorno = 0;
	while (reintentos >= 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getFloat(&bufferFloat) == 0) {

			if (bufferFloat >= minimo && bufferFloat <= maximo) {

				*pResultado = bufferFloat;
				retorno = 1;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

/**
*\brief: verificar que el espacio sea suficiente, y omite el enter.
*\param: puntero a char, int
*\return: retorna 1 bien, 0 ERR0R.
**/
int getStringg(char *cadena, int longitud) {
	int retorno = 0;
	char bufferString[4096];

	if (cadena != NULL && longitud > 0) {
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
					== '\n') {
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
						'\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= longitud) {
				strncpy(cadena, bufferString, longitud);
				retorno = 1;
			}
		}
	}
	return retorno;
}

/**
*\brief: verifica que lo recibido por parametro pueda escribirse dentro de la variable.
*\param: puntero a char, int
*\return: retorna 1 bien, 0 ERROR.
**/
int getString(char *cadena, int longitud) {
	int retorno = 0;
	char bufferString[4096];

	if (cadena != NULL && longitud > 0) {

			if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {

				if (strnlen(bufferString, sizeof(bufferString)) <= longitud) {
					strncpy(cadena, bufferString, longitud);
					retorno = 1;
				}
			}
	}
	return retorno;
}



/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 */
int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer)) &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud){

    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{

		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] >= 'A' && cadena[i] <= 'Z') && (cadena[i] >= 'a' && cadena[i] <= 'z' ))
			{
					retorno = 0;
					break;
			}

		}
	}
	return retorno;
}

/**
*\brief: verifica que lo ingresado tenga sentido para lo que es un nombre.
*\param: puntero a char, int, puntero a char, puntero a char, int.
*\return: retorna 1 bien, 0 ERR0R.
**/
int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = 0;

	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);

			if(getNombre(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud )
			{
				if(bufferString[0] != ' ' && bufferString[0] != '\n' ){

					if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]== '\n') {

						bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
						strncpy(pResultado, bufferString, longitud);
						retorno = 1;
						break;
					}
				}
			}

		printf("%s",mensajeError);
	}
	return retorno;
}

/**
*\brief: toma un int por parametro y verifica que sea un numero.
*\param: puntero a int
*\return: retorna 1 bien, 0 ERROR.
**/
int getInt(int *pResultado) {

	int retorno = 0;
	char buffer[1024];

	fgets(buffer, sizeof(buffer), stdin);

	buffer[strlen(buffer) - 1] = '\0';

	if (esNumerica(buffer)) {

		*pResultado = atoi(buffer);
		retorno = 1;
	}
	return retorno;
}

/**
*\brief: Verifica que lo que recibe por parametro sea un numero.
*\param: puntero a char.
*\return: retorna 1 bien, 0 ERROR.
**/
int esNumerica(char cadena[]){

	int retorno = 0;

	if (cadena != NULL && strlen(cadena) > 0) {

		for (int i = 0; i < strlen(cadena); i++) {

			if (cadena[i] >= '0' && cadena[i] <= '9'){

				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

