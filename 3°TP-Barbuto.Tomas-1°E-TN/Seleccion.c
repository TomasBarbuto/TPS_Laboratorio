#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"


/**
 * \brief Reserva espacio en memoria para el tipo de dato Seleccion.
 * \param VOID
 * \return direccion de memoria de un dato seleccion.
**/
Seleccion* selec_new(){

	Seleccion *nuevaSeleccion = NULL;
	nuevaSeleccion = (Seleccion*) malloc(sizeof(Seleccion));

	if (nuevaSeleccion != NULL){

		if(selec_setConvocados(nuevaSeleccion, 0)){

			nuevaSeleccion->id = 0;
			strncpy(nuevaSeleccion->pais, " ", 30);
			strncpy(nuevaSeleccion->confederacion, " ", 30);
		}

	}

	return nuevaSeleccion;
}


/**
 * \brief Reserva espacio en memoria para el tipo de dato Seleccion.
 * \param 4 punteros a char.
 * \return direccion de memoria de un dato seleccion.
**/
Seleccion* selec_newParametros(char* idStr, char* paisStr, char* confederacionStr, char* convocadosStr){

	Seleccion* nuevaSeleccion = selec_new();

	if(idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL){

		if(nuevaSeleccion != NULL){

			if (!(selec_setConvocados(nuevaSeleccion, atoi(convocadosStr)))){

				selec_delete(nuevaSeleccion);
				nuevaSeleccion = NULL;	//INDICA FUNCION NO ANDUVO BIEN.

			}else{

				nuevaSeleccion->id = atoi(idStr);
				strncpy(nuevaSeleccion->pais, paisStr, 30);
				strncpy(nuevaSeleccion->confederacion, confederacionStr, 30);

			}
		}
	}
	return nuevaSeleccion;
}

/**
 * \brief Libera espacio de memoria.
 * \param puntero a seleccion.
 * \return VOID
**/
void selec_delete(Seleccion *this){

	free(this);
}


/**
 * \brief obtiene un dato cargado en el campo seleccion.
 * \param puntero a seleccion, puntero a int
 * \return int 1 Bien, 0 ERROR.
**/
int selec_getId(Seleccion* this, int* id){

	int retorno = 0;

	if (this != NULL && id != NULL){

		*id = this->id;
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}


/**
 * \brief obtiene un dato cargado en el campo seleccion.
 * \param puntero a seleccion, puntero a char.
 * \return int 1 Bien, 0 ERROR.
**/
int selec_getPais(Seleccion* this, char* pais){

	int retorno = 0;

	if (this != NULL && pais != NULL){

		strncpy(pais, this->pais, 30);
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}

/**
 * \brief obtiene un dato cargado en el campo seleccion.
 * \param puntero a seleccion, puntero a char.
 * \return int 1 Bien, 0 ERROR.
**/
int selec_getConfederacion(Seleccion* this, char* confederacion){

	int retorno = 0;

	if (this != NULL && confederacion != NULL){

		strncpy(confederacion, this->confederacion, 30);
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}

/**
 * \brief Carga un dato de tipo int en el campo convocado de seleccion.
 * \param puntero a seleccio, int.
 * \return int 1 Bien, 0 ERROR.
**/
int selec_setConvocados(Seleccion* this, int convocados){

	int retorno = 0;

	if(this != NULL && convocados >= 0 && convocados < 23){

		this->convocados = convocados;
		retorno = 1;
	}

	return retorno;
}


/**
 * \brief obtiene un dato cargado en el campo seleccion.
 * \param puntero a seleccion, puntero a int.
 * \return int 1 Bien, 0 ERROR.
**/
int selec_getConvocados(Seleccion* this, int* convocados){

	int retorno = 0;

	if(this != NULL && convocados != NULL){

		*convocados = this->convocados;
		retorno = 1;
	}
	return retorno;
}

/**
 * \brief imprime una seleccion extraida de un puntero a linkedList.
 * \param puntero a linkedList, int.
 * \return int 1 Bien, 0 ERROR.
**/
int imprimirSeleccion(LinkedList* pArrayListaSelecciones, int index){

	int retorno = 0;
	int auxId;
	char auxPais[30];
	char auxConfederacion[30];
	int auxConvocados;

	Seleccion* unaSeleccion = NULL;

	if(pArrayListaSelecciones != NULL && index >= 0 && index < ll_len(pArrayListaSelecciones)){

		unaSeleccion = (Seleccion*) ll_get(pArrayListaSelecciones, index);

		if(unaSeleccion != NULL){

			if(selec_getId(unaSeleccion, &auxId)
			&& selec_getConvocados(unaSeleccion, &auxConvocados)
			&& selec_getConfederacion(unaSeleccion, auxConfederacion)
			&& selec_getPais(unaSeleccion, auxPais)){

				printf("|%10d | %25s | %10d | %20s |\n", auxId, auxConfederacion, auxConvocados, auxPais);
				retorno = 1;
			}
		}
	}
	return retorno;
}

/**
 * \brief valida existencia de un dato de tipo seleccion en puntero a linkedList.
 * \param puntero a linkedList, int
 * \return int, -1 ERROR, >= 0 indice.
**/
int validarExistenciaDeSeleccion(LinkedList* pArrayListaSelecciones, int idParam){

	int retorno = -1;
	int idDeSeleccion;
	Seleccion* unaSeleccion = NULL;

	if(pArrayListaSelecciones != NULL){

		for(int i = 0; i < ll_len(pArrayListaSelecciones); i++){

			unaSeleccion = (Seleccion*)ll_get(pArrayListaSelecciones, i);

			if(unaSeleccion != NULL){

				if(selec_getId(unaSeleccion, &idDeSeleccion)){

					if(idDeSeleccion == idParam){

						retorno = ll_indexOf(pArrayListaSelecciones, unaSeleccion);
						break; //Retorno el index.
					}
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief obtiene el string del nombre de la confederacion a la que pertenece cada seleccion.
 * \param linkedList* pArrayListSeleccion, int, puntero a char.
 * \return int 1 Bien, 0 ERROR.
**/
int buscarNombreDeConfederacion(LinkedList *pArrayListSeleccion, int idSeleccion, char pConfederacion[]){

	int retorno = 0;
	int auxIdSeleccion;
	char auxConfederacion[30];
	Seleccion* auxSeleccion = NULL;

	if (pArrayListSeleccion != NULL && pConfederacion != NULL && idSeleccion > 0){

		for (int i = 0; i < ll_len(pArrayListSeleccion); i++){

			auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);

			if (auxSeleccion != NULL){

				if (selec_getId(auxSeleccion, &auxIdSeleccion)){

					if (auxIdSeleccion == idSeleccion
					&& selec_getConfederacion(auxSeleccion, auxConfederacion)){

						strncpy(pConfederacion, auxConfederacion, 30);
						retorno = 1;
					}
				}
			}
		}
	}
	return retorno;
}


/**
 * \brief obtiene el string del nombre de la seleccion segun el id.
 * \param linkedList* pArrayListSeleccion, int, puntero a char.
 * \return int 1 Bien, 0 ERROR.
**/
int buscarNombreDeSeleccion(LinkedList *pArrayListSeleccion, int idSeleccion, char pSeleccion[]){

	int retorno = 0;
	int auxIdSeleccion;
	char auxNombreSeleccion[30];
	Seleccion* auxSeleccion = NULL;

	if (pArrayListSeleccion != NULL && idSeleccion > 0 && pSeleccion != NULL ){

		for (int i = 0; i < ll_len(pArrayListSeleccion); i++){

			auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);

			if (auxSeleccion != NULL){

				if (selec_getId(auxSeleccion, &auxIdSeleccion)){

					if (auxIdSeleccion == idSeleccion
					&& selec_getPais(auxSeleccion, auxNombreSeleccion)){

						strncpy(pSeleccion, auxNombreSeleccion, 30);
						retorno = 1;
					}
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief selecciona dos punteros y evalua cual es mayor.
 * \param puntero a void, puntero a void
 * \return int, 1 bien, 0 ERROR.
**/
int selec_ordenarPorConfederacion(void* elementoA, void* elementoB){

	int retorno = 0;
	char confederacionA[30];
	char confederacionB[30];
	Seleccion* auxSeleccionA;
	Seleccion* auxSeleccionB;

	auxSeleccionA = (Seleccion*)elementoA;
	auxSeleccionB = (Seleccion*)elementoB;

	if(selec_getConfederacion(auxSeleccionA, confederacionA)
	&& selec_getConfederacion(auxSeleccionB, confederacionB)){

		if(stricmp(confederacionA, confederacionB) > 0 ){

			retorno = 1;

		}else if(stricmp(confederacionA, confederacionB) < 0){

			retorno = -1;
		}
	}
	 return retorno;
}

