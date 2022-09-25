#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"


/**
*\brief: muestra un menu de datos de cargar de jugadores de la seleccion argentina.
*\
*\param: 1 puntero a itn (key), 3 acumuladores printeados en un menu, contadores printeados a un menu
*\
*\return: VOID
*
*/
void mostrarMenu(int *pMenu, float acumuladorUno, float acumuladorDos, float acumuladorTres,
				int posicionUno, int posicionDos, int posicionTres, int posicionCuatro){

	if(pMenu != NULL){


		printf("\nBievenido al menu de la seleccion Argentina\n"
						"1-Ingreso de costos de mantenimiento\n"
						"\tCosto de hospedaje -> $ %.2f\n"
						"\tCosto de Comida -> $ %.2f\n"
						"\tCosto de Transporte -> $ %.2f\n"
						"2-Carga de Jugadores\n"
						"\tArqueros -> %d\n"
						"\tDefensores -> %d\n"
						"\tMediocentro -> %d\n"
						"\tDelanteros -> %d\n"
						"3-Realizar todos los calculos\n"
						"4-Informar todos los resultados\n"
						"5-Salir\n",acumuladorUno, acumuladorDos, acumuladorTres,
						posicionUno, posicionDos, posicionTres, posicionCuatro);

		getNumber(pMenu,"Opcion: " , "No ingreso un valor valido\n", 1, 5);


	}
}


/**
*\brief: Hace un print informando resultados obtenidos de atraves de distintos valores.
*\
*\param: 6 punteros a float de promedio, 1 puntero a un total, 1 puntero a recargo y un puntero a la suma de los ultimos dos.
*\
*\return: VOID
*
*/

void mostrarResultados(float *pPromedioUno, float *pPromedioDos, float *pPromedioTres, float *pPromedioCuatro,
					float *pPromedioCinco, float *pPromedioSeis, float *pCostoTotal, float *pRecargo, float *pCostoRecargo){

	if(pPromedioUno != NULL && pPromedioDos != NULL && pPromedioTres != NULL && pPromedioCuatro != NULL &&
	   pPromedioCinco != NULL && pPromedioSeis != NULL && pCostoTotal != NULL &&
	   pRecargo != NULL && pCostoRecargo != NULL){

		printf("Porcentaje Uefa: %.2f\n"
				"Porcentaje Conmebol: %.2f\n"
				"Porcentaje Concacaf: %.2f\n"
				"Porcentaje Afc: %.2f\n"
				"Porcentaje Ofc: %.2f\n"
				"Porcentaje Caf: %.2f\n", *pPromedioUno, *pPromedioDos
				, *pPromedioTres, *pPromedioCuatro, *pPromedioCinco, *pPromedioSeis);

		if(*pPromedioUno >= 50){

			printf("El costo de mantenimiento era de $%.2f y recibio un aumento de $%.2f,"
					" su nuevo valor es de: $%.2f\n", *pCostoTotal, *pRecargo, *pCostoRecargo);

		}else{

			printf("El costo de mantenimiento es: $%.2f\n", *pCostoTotal);

		}

			system("pause"); // pulse un tecla para continuar...
	}
}

