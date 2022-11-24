#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"


/**
 * \brief : verifica que lo ingresado por parametro corresponda a un numero.
 * \param : puntero a char.
 * \return: retorna 1 bien 0 error.
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
 * \brief : toma un dato y verifica que sea un numero.
 * \param : puntero a int.
 * \return: retorna 1 bien 0 ERROR.
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
 * \brief : Toma un valor y lo devuelve por puntero a int.
 * \param : puntero a int, puntero a char, puntero a char, int min, int max, int.
 * \return: retorna 1 bien, 0 ERROR.
**/
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {

	int retorno = 0;
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

	if (reintentos != 0) {

		retorno = 1;
		*pResultado = numero;
	}
	return retorno;
}


/**
 * \brief : toma un valor y devuelve un short por puntero.
 * \param : puntero a short, puntero a char, puntero a char, int min, int max, int.
 * \return: retorna 1 bien, 0 ERROR.
**/
int utn_getNumeroShort(short *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos){

	int retorno = 0;
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

	if (reintentos != 0) {

		retorno = 1;
		*pResultado = numero;
	}
	return retorno;
}

/**
 * \brief : verifica que el lo ingresado sea valido y lo convierte a numero flotante.
 * \param : puntero a float.
 * \return: retorna 1 bien, 0 ERROR.
**/
int getFloat(float *pResultado) {

	int retorno = 0;
	char buffer[64];

	if (pResultado != NULL) {

		if (getString(buffer, sizeof(buffer)) && esFlotante(buffer)) {

			*pResultado = atof(buffer);
			retorno = 1;
		}
	}
	return retorno;
}

/**
 * \brief : verifica que el dato ingresado sea un numero flotante.
 * \param : puntero a char.
 * \return: retorna 1 bien, 0 ERROR.
**/
int esFlotante(char *cadena) {

	int retorno = 1;
	int contadorPuntos = 0;

	if (cadena != NULL && strlen(cadena) > 0) {

		for (int i = 0; cadena[i] != '\0'; i++) {

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
 * \brief : Verifica que lo ingresado corresponda a un numero flotante.
 * \param : puntero a float, puntero a char, puntero a char, float min, float max, int.
 * \return: retorna 1 bien, 0 ERROR.
**/
int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError,
							float minimo, float maximo, int reintentos) {
	float bufferFloat;
	int retorno = 0;

	while (reintentos >= 0) {

		reintentos--;
		printf("%s", mensaje);

		if (getFloat(&bufferFloat)) {

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
 * \brief : toma un dato como entrada y valida que sea un string y que no es pase de cierto espacio de memoria.
 * \param : puntero a char, int.
 * \return: 1 bien, 0 ERROR.
**/
int getString(char *cadena, int longitud) {

	int retorno = 0;
	char bufferString[4096];

	if (cadena != NULL && longitud > 0) {

		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {

			if(bufferString[0] != '\n'){

				if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n') {
					bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
							'\0';
				}
				if (strnlen(bufferString, sizeof(bufferString)) <= longitud) {
					strncpy(cadena, bufferString, longitud);
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief : Valida que lo ingresado corresponda a la caracteristicas de un nombre.
 * \param : puntero a char, int.
 * \return: retorna 1 bien, 0 ERROR.
**/
int getNombre(char* pResultado, int longitud){

    int retorno = 0;
    char buffer[4096];

    if(pResultado != NULL){

    	if(getString(buffer,sizeof(buffer)) && esNombre(buffer,sizeof(buffer))
    	&& strnlen(buffer,sizeof(buffer)) < longitud){

    		strncpy(pResultado,buffer,longitud);
			retorno = 1;
		}
    }
    return retorno;
}

/**
 * \brief : valida que lo ingresado esten dentro de un rango solicitados.
 * \param : puntero a char, int.
 * \return: retorna 1 bien, 0 ERROR.
**/
int esNombre(char* cadena,int longitud){

	int retorno = 1;

	if(cadena != NULL && longitud > 0){

		for(int i = 0 ; cadena[i] != '\0' && i < longitud; i++){

				if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' )){

					retorno = 0;
					break;
			}
		}
	}
	return retorno;
}

/**
 * \brief : Valida que lo ingresado sea un nombre.
 * \param : puntero a char, int, puntero a char, puntero a char, int.
 * \return: 1 bien, 0 ERROR.
**/
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos){

	char bufferString[4096];
	int retorno = 0;

	while(reintentos >= 0){

		reintentos--;
		printf("%s",mensaje);

		if(bufferString[0] != '\n'){
			if(getNombre(bufferString,sizeof(bufferString))
			&& strnlen(bufferString,sizeof(bufferString)) < longitud ){

				strncpy(pResultado,bufferString,longitud);
				retorno = 1;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief : toma un valor como entrada y analiza si es numerica, si lo es la transforma a int.
 * \param : puntero a int.
 * \return: retorna 1 bien, 0 ERROR.
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
 * \brief :la funcion verifica que los valores ingresados sean numericos.
 * \param : puntero a char.
 * \return: retorna 1 bien, retorna 0 ERROR.
**/
int esNumerica(char cadena[]){

	int retorno = 0;

	if (cadena != NULL && strlen(cadena) > 0) {

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
 * \brief :la funcion verifica que todos los valores ingresados sean numericos.
 * \param : puntero a char.
 * \return: retorna 1 bien, retorna 0 ERROR.
**/
int isValidTarjeta(char* stringRecibido){

    int retorno = 1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error

    for(int i = 0; stringRecibido[i] != '\0'; i++){

        if((stringRecibido[i] < '0' || stringRecibido[i] > '9')){

            retorno = 0;
            break;
        }
    }
    return retorno;
}

/**
 * \brief :Verifica que el valor que pasemos por parametro este dentro de un rango de espacios.
 * \param : puntero a char, puntero a char, int min, int max, puntero a int, puntero a char.
 * \return:retorna 1 bien, 0 ERROR.
**/
int getStringTarjeta(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado){

    int retorno = 0;
    char bufferStr[max+10];

    if(msg != NULL && msgError != NULL && min <= max && reintentos >= 0 && resultado != NULL){

        do{

            printf("%s",msg);   //no poner salto de linea, se va a pasar en el mensaje por valor
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr) >= min && strlen(bufferStr) < max){    // tamaño (max) =cantidad de elementos (strlen) + 1(\0)

            	strncpy(resultado,bufferStr,max);
                retorno=1;
                break;
            }

            printf("%s",msgError);
            (*reintentos)--;


        }while((*reintentos)>=0);
    }
    return retorno;
}


/**
 * \brief : toma datos de una tarjeta de credito entre dos rangos de espacios.
 * \param : puntero a char, puntero a char, int, int, int, puntero a char.
 * \return: retorna 1 bien, 0 ERRROR.
**/
int utn_getTarjetaDeCredito(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input){

    int retorno = 0;
    char bufferStr[maxSize];

    if(msg != NULL && msgError != NULL && minSize<maxSize && reintentos >= 0 && input != NULL){

        do{

            if(getStringTarjeta(msg,msgError,minSize,maxSize,&reintentos,bufferStr) && isValidTarjeta(bufferStr)){

                strncpy(input,bufferStr,maxSize);
                retorno = 1;
                break;
            }
            else{

                printf("%s",msgError);
                reintentos--;
            }

        }while(reintentos>=0);
    }
    return retorno;
}
