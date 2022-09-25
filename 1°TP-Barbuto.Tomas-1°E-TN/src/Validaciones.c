#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

/**
*\brief: contiene un subMenu el cual modificara el acumulador seleccionado.
*
*\param: seis punteros a flotantes que tomaran un valor segun la opcion indicada.
*
*\return: VOID
*
*/

void cargarCostos(float *pCostoUno, float *pAcumuladorUno, float *pCostoDos,
				float *pAcumuladorDos, float *pCostoTres, float *pAcumuladorTres){

	int subMenuCostos;

	if(pCostoUno != NULL && pCostoDos != NULL && pCostoTres != NULL &&
	   pAcumuladorUno != NULL && pAcumuladorDos != NULL && pAcumuladorTres != NULL){
		printf("Ingreso de los costos de mantenimiento\n"
				"1- Costo de Hospedaje\n"
				"2- Costo de Comida\n"
				"3- Costo de Transporte\n"
				"Valor: ");

		getNumber(&subMenuCostos,"Opcion: " , "No ingreso un valor valido\n", 1, 3);

		//mostrar submenu

		switch (subMenuCostos){ //cargarCostos..

		case 1:

			printf("Ingrese el costo de hospedaje: ");
			getFloat(pCostoUno,"$" , "No ingreso un valor valido \n", 1, 9999999);

			*pAcumuladorUno += *pCostoUno;

			break;

		case 2:

			printf("Ingrese el costo de Comida: ");
			getFloat(pCostoDos,"$" , "No ingreso un valor valido \n", 1, 9999999);

			*pAcumuladorDos += *pCostoDos;

			break;


		case 3:

			printf("Ingrese el costo de Transportes: ");
			getFloat(pCostoTres,"$" , "No ingreso un valor valido \n", 1, 9999999);

			*pAcumuladorTres += *pCostoTres;

			break;

		}
	}

}

/**
*\brief: Contiene una llave la cual segun se elija sumara 1 al puntero seleccionado.
*
*\param: 4 punteros a enteros, para modificar contadores.
*\
*\return: Retorna 1 si cargo con exito y 0 si hubo algun error.
*
*/

int cargarJugador(int *pPosicionUno, int *pPosicionDos, int *pPosicionTres, int *pPosicionCuatro){

	int retorno = 0;
	int numero;
	int llave;

	if(pPosicionUno != NULL && pPosicionDos != NULL && pPosicionTres != NULL && pPosicionCuatro != NULL){

		printf("Ingrese lo datos correspondientes para cada jugador\n");

		getNumber(&numero,"Numero de camiseta:  " , "Ingrese un numero de 1 a 22\n", 1, 22);

		printf("Ingrese posicion del jugador\n"
				"1- Arquero\n"
				"2- Defensor\n"
				"3- Mediocentro\n"
				"4- Delantero\n");

		getNumber(&llave ,"Opcion: " , "No ingreso un valor valido\n", 1, 4);

		switch(llave){

		case 1:

			if(*pPosicionUno == 2){

				printf("Ya no hay lugares para arqueros\n");
				system("pause");

			}else{

				(*pPosicionUno)++;
				retorno = 1;

			}

			break;

		case 2:

			if(*pPosicionDos == 8){

				printf("Ya no hay lugares para defensores\n");
				system("pause");

			}else{

				(*pPosicionDos)++;
				retorno = 1;

			}
			break;

		case 3:

			if(*pPosicionTres == 8){

				printf("Ya no hay lugares para mediocampistas\n");
				system("pause");

			}else{

				(*pPosicionTres)++;
				retorno = 1;

			}

			break;

		case 4:

			if(*pPosicionCuatro == 4){

				printf("Ya no hay lugares para delanteros\n");
				system("pause");

			}else{

				(*pPosicionCuatro)++;
				retorno = 1;
			}

			break;
		}
	}
	return retorno;
}

/**
*\brief: 6 contadores declarados como puntero a int, segun el valor elegido aumentara su valor en 1.
*\
*\param: 6 punteros a int para 6 opciones.
*\
*\return: Retorna 1 si cargo con exito y 0 si hubo algun error.
*
*/

int cargarConfederacion(int *pContadorUno, int *pContadorDos, int *pContadorTres,
						int *pContadorCuatro, int *pContadorCinco, int *pContadorSeis, int *pCantidadTotal){
	int retorno = 0;
	int confederacion;

	if(pContadorUno != NULL && pContadorDos != NULL && pContadorTres != NULL && pContadorCuatro != NULL &&
	   pContadorCinco != NULL && pContadorSeis != NULL && pCantidadTotal != NULL){

		printf("Ingrese la confederacion correspondiente\n"
				"1- UEFA\n"
				"2- CONMEBOL\n"
				"3- CONCACAF\n"
				"4- AFC\n"
				"5- OFC\n"
				"6- CAF\n");

		getNumber(&confederacion,"Opcion: " , "No ingreso un valor valido\n", 1, 6);

			switch(confederacion){

			case 1:

				(*pContadorUno)++;
				retorno = 1;
				break;

			case 2:

				(*pContadorDos)++;
				retorno = 1;
				break;

			case 3:

				(*pContadorTres)++;
				retorno = 1;
				break;

			case 4:

				(*pContadorCuatro)++;
				retorno = 1;
				break;

			case 5:

				(*pContadorCinco)++;
				retorno = 1;
				break;

			case 6:

				(*pContadorSeis)++;
				retorno = 1;
				break;

			}

			*pCantidadTotal = *pContadorUno + *pContadorDos + *pContadorTres +
							*pContadorCuatro + *pContadorCinco + *pContadorSeis;

	}
	return retorno;
}

/**
*\brief: Pide un numero y valida que este dentro de un rango y que sea un numero.
*\
*\param: valor ingresado puntero a int, mensaje , error, rango minimo, rango maximo.
*\
*\return: Retorna 1 si cargo con exito y 0 si hubo algun error.
*
*/


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

			}

		} while (retorno == 0);
	}

	return retorno;
}

/**
*\brief: Pide un numero flotante y valida que este dentro de un rango y que sea un numero.
*\
*\param: valor ingresado puntero a float, mensaje , error, rango minimo, rango maximo.
*\
*\return: Retorna 1 si cargo con exito y 0 si hubo algun error.
*
*/

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


