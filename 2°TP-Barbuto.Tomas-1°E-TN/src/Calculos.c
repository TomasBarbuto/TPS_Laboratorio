#include <stdio.h>

/**
*\brief: Calcula el porcentaje de una variable.
*\param: puntero a float, float , entero.
*\return: Retorna 1 si pudo lograr el calculo, retorna 0 si algo fallo.
**/
int calcularPorcentaje(float *pResultado, float multiplicador, int divisor){

    float porcentaje;
    int retorno = 0;

    if(pResultado != NULL && divisor != 0){

        porcentaje = (float)(multiplicador * 100) / divisor;
        *pResultado = porcentaje;
        retorno = 1;

    }

    return retorno;
}

/**
*\brief: Obtiene el valor maximo de 6 numeros distintos, y devuelve por puntero el mayor y el resultado.
*\param: 5 entero, dos punteros a enteros.
*\return: retorna 1 si lo logra con exito, 0 si ocurre algun error.
**/
int obtenerMaximoPorId(int num1, int num2, int num3, int num4, int num5, int num6, int *pResultado, int *pIdMayor){

    int retorno = 0;
    int idMayor;
    int resultado;

    if(pResultado != NULL && pIdMayor != NULL){

        if (num1 > num2 && num1 > num3 && num1 > num4 && num1 > num5 && num1 > num6){

        	idMayor = 100;
            resultado = num1;

        } else if (num2 > num3 && num2 > num4 && num2 > num5 && num2 > num6 ){

        	idMayor = 101;
            resultado = num2;

        } else if (num3 > num4 && num3 > num5 && num3> num6){

        	idMayor = 102;
            resultado = num3;

        } else if(num4 > num5 && num4 > num6){

        	idMayor = 103;
            resultado = num4;

        }else if( num5 > num6){

        	idMayor = 104;
            resultado = num5;

        }else{

        	idMayor = 105;
            resultado = num6;

        }

        retorno = 1;
    }// FIN VALIDACIONES de punteros NULL.

    if(retorno == 1){

        *pResultado = resultado;
        *pIdMayor = idMayor;

    }else{

    	printf("Ocurrio un ERROR, llame al departarmento de sistemas\n");
    }


    return retorno;
}
