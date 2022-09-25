#include <stdio.h>


/**
*\brief: Solicita dos numeros al usuario, para realizar el calculo promedio
		 y pasarlo por puntero.
*\param: Direccion de memeoria, dividendo, divisor
*
*\return: retorna 1 si la funcion se cumplio, y 0 si hubo algun error.
*
*/

int calcularPromedio(float *pResultado, int multiplicador, int divisor){

	float promedio;
	int retorno = 0;

	if(pResultado != NULL && divisor != 0){
		promedio = (float)(multiplicador * 100) / divisor;

		*pResultado = promedio;
		retorno = 1;

	}

	return retorno;
}

