#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "Validaciones.h"
#include "Menu.h"

/**
 * \brief Reserva espacio en memoria para el tipo de dato Jugador.
 * \param VOID
 * \return Puntero a Jugador.
**/
Jugador* jug_new(){

	Jugador *nuevoJugador = NULL;
	nuevoJugador = (Jugador *) malloc(sizeof(Jugador));

	if (nuevoJugador != NULL){

		jug_setId(nuevoJugador, 0);
		jug_setNombreCompleto(nuevoJugador, " ");
		jug_setEdad(nuevoJugador, 0);
		jug_setPosicion(nuevoJugador, " ");
		jug_setNacionalidad(nuevoJugador, " ");
		jug_setIdSeleccion(nuevoJugador, 0);
	}

	return nuevoJugador;
}

/**
 * \brief Reserva espacio en memoria para un tipo de datos Jugador, cargando los datos en los campos.
 * \param 6 punteros a char.
 * \return puntero a jugador.
**/
Jugador* jug_newParametros(char* idStr, char* nombreCompletoStr, char* edadStr, char* posicionStr,
						   char* nacionalidadStr, char* idSelccionStr){

	Jugador *nuevoJugador = jug_new();

	if(nuevoJugador != NULL){

		if (!(jug_setId (nuevoJugador, atoi(idStr))
			&& jug_setNombreCompleto(nuevoJugador, nombreCompletoStr)
			&& jug_setEdad(nuevoJugador, atoi(edadStr))
			&& jug_setPosicion(nuevoJugador, posicionStr)
			&& jug_setNacionalidad(nuevoJugador, nacionalidadStr)
			&& jug_setIdSeleccion(nuevoJugador, atoi(idSelccionStr)))){

	    	  jug_delete(nuevoJugador);
	    	  nuevoJugador = NULL;	//INDICA FUNCION NO ANDUVO BIEN.
	      }
	}

	  return nuevoJugador;
}

/**
 * \brief libera espacio en memoria de un tipo de dato Jugador.
 * \param puntero a jugador.
 * \return VOID
**/
void jug_delete(Jugador *this){

	free(this);
}

/**
 * \brief Carga un dato de tipo int en el campo id de jugador.
 * \param puntero a jugador, int
 * \return int 1 Bien, 0 ERROR.
**/
int jug_setId(Jugador* this, int id){

	int retorno = 0;

	if(this != NULL && id > 0){

		this->id = id;
		retorno = 1;
	}

	return retorno;
}

/**
 * \brief obtiene un dato cargado en el campo jugador.
 * \param puntero a jugador, puntero a int
 * \return int 1 Bien, 0 ERROR.
**/
int jug_getId(Jugador* this, int* id){

	int retorno = 0;

	if (this != NULL && id != NULL){

		*id = this->id;
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}


/**
 * \brief carga un campo puntero a jugador.
 * \param puntero a jugador, puntero a char.
 * \return int 1 Bien, 0 ERROR.
**/
int jug_setNombreCompleto(Jugador* this, char* nombreCompleto){

	int retorno = 0;

	if(this != NULL && nombreCompleto != NULL){

		strncpy(this->nombreCompleto, nombreCompleto, 100);
		retorno = 1;
	}

	return retorno;
}

/**
 * \brief obtiene un dato de puntero a jugador
 * \param puntero a jugador, puntero a char.
 * \return int 1 Bien, 0 ERROR.
**/
int jug_getNombreCompleto(Jugador* this, char* nombreCompleto){

	int retorno = 0;

	if (this != NULL && nombreCompleto != NULL){

		strncpy(nombreCompleto, this->nombreCompleto, 100);
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}


/**
 * \brief carga un campo puntero a jugador.
 * \param puntero a jugador, puntero a char.
 * \return int 1 Bien, 0 ERROR.
**/
int jug_setPosicion(Jugador* this, char* posicion){

	int retorno = 0;

	if(this != NULL && posicion != NULL){

		strncpy(this->posicion, posicion, 30);
		retorno = 1;
	}

	return retorno;
}

/**
 * \brief obtiene un dato de puntero a jugador
 * \param puntero a jugador, puntero a char.
 * \return int 1 Bien, 0 ERROR.
**/
int jug_getPosicion(Jugador* this, char* posicion){

	int retorno = 0;

	if (this != NULL && posicion != NULL){

		strncpy(posicion, this->posicion, 30);
		retorno = 1;
		//LA FLECHA ES UN PUNTERO A UNA ESTRUCTURA.
	}

	return retorno;
}


/**
 * \brief carga un campo puntero a jugador.
 * \param puntero a jugador, puntero a char.
 * \return int 1 Bien, 0 ERROR.
**/
int jug_setNacionalidad(Jugador* this, char* nacionalidad){

	int retorno = 0;

	if(this != NULL && nacionalidad != NULL){

		strncpy(this->nacionalidad, nacionalidad, 30);
		retorno = 1;
	}

	return retorno;
}

/**
 * \brief obtiene un dato de puntero a jugador
 * \param puntero a jugador, puntero a char.
 * \return int 1 Bien, 0 ERROR.
**/
int jug_getNacionalidad(Jugador* this, char* nacionalidad){

	int retorno = 0;

	if(this != NULL && nacionalidad != NULL){

		strncpy(nacionalidad, this->nacionalidad, 30);
		retorno = 1;
	}

	return retorno;
}


/**
 * \brief carga un campo puntero a jugador.
 * \param puntero a jugador, int.
 * \return int 1 Bien, 0 ERROR.
**/
int jug_setEdad(Jugador* this, int edad){

	int retorno = 0;

	if(this != NULL && edad >= 16){

		this->edad = edad;
		retorno = 1;
	}

	return retorno;
}


/**
 * \brief obtiene un dato de puntero a jugador
 * \param puntero a jugador, puntero a int.
 * \return int 1 Bien, 0 ERROR.
**/
int jug_getEdad(Jugador* this, int* edad){

	int retorno = 0;

	if(this != NULL && edad != NULL){

		*edad = this->edad ;
		retorno = 1;
	}

	return retorno;
}


/**
 * \brief carga un campo puntero a jugador.
 * \param puntero a jugador, int.
 * \return int 1 Bien, 0 ERROR.
**/
int jug_setIdSeleccion(Jugador* this, int idSeleccion){

	int retorno = 0;

	if(this != NULL && idSeleccion >= 0){

		this->idSeleccion = idSeleccion;
		retorno = 1;
	}

	return retorno;
}


/**
 * \brief obtiene un dato de puntero a jugador
 * \param puntero a jugador, puntero a int.
 * \return int 1 Bien, 0 ERROR.
**/
int jug_getIdSeleccion(Jugador* this, int* idSeleccion){

	int retorno = 0;

	if(this != NULL && idSeleccion != NULL){

		*idSeleccion = this->idSeleccion;
		retorno = 1;
	}
	return retorno;
}

/**
 * \brief otorga un id autoincremental.
 * \param VOID
 * \return int 1 Bien, 0 ERROR.
**/
int idAutoincremental(){ // Atomizar esta funcion y poner mas lindo todo es un asco PA!!!.

	static int idJugador;
	char auxId[1000];
	static int flag = 0;

	if(flag == 0){

		if(controller_cargarIdAutoincremental("ID.csv", auxId)){

			flag = 1;
			idJugador = atoi(auxId);
		}
	}

	idJugador++;

	return idJugador;
}

/**
 * \brief imprime un jugador extraido de un puntero a linkedList.
 * \param puntero a linkedList, int.
 * \return int 1 Bien, 0 ERROR.
**/
int imprimirJugador(LinkedList* pArrayListaJugadores, int index){

	int retorno = 0;
	int auxId;
	char auxNombreCompleto[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];
	Jugador* unJugador = NULL;

	if(pArrayListaJugadores != NULL && index >= 0 && index < ll_len(pArrayListaJugadores)){

		unJugador = (Jugador*)ll_get(pArrayListaJugadores, index);

		if(unJugador != NULL){

			if(jug_getId(unJugador, &auxId)
			&& jug_getNombreCompleto(unJugador, auxNombreCompleto)
			&& jug_getEdad(unJugador, &auxEdad)
			&& jug_getPosicion(unJugador, auxPosicion)
			&& jug_getNacionalidad(unJugador, auxNacionalidad)){

				printf("|%10d | %25s | %10d | %20s | %15s |\n", auxId, auxNombreCompleto, auxEdad,
																auxPosicion,auxNacionalidad);
				retorno = 1;
			}
		}
	}
	return retorno;
}

/**
 * \brief valida existencia de un dato de tipo jugador en puntero a linkedList.
 * \param puntero a linkedList, int
 * \return int, -1 ERROR, >= 0 indice.
**/
int validarExistenciaDeJugador(LinkedList* pArrayJugadores, int idParam){

	int retorno = -1;
	int idDeJugador;
	Jugador* unJugador = NULL;

	if(pArrayJugadores != NULL){

		for(int i = 0; i < ll_len(pArrayJugadores); i++){

			unJugador = (Jugador*) ll_get(pArrayJugadores, i);

			if(unJugador != NULL){

				if(jug_getId(unJugador, &idDeJugador)){

					if(idDeJugador == idParam){

						retorno = ll_indexOf(pArrayJugadores, unJugador);
						break; //Retorno el index.
					}
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief imprime un dato de tipo jugador, con su correspondiente seleccion.
 * \param puntero a linkedlist, puntero a linkedlist, int
 * \return int, 1 bien, 0 ERROR.
**/
int imprimirJugadorSeleccion(LinkedList* pArrayListaJugadores, LinkedList* pArrayListaSeleccion, int index){

	int retorno = 0;
	int auxId;
	char auxNombreCompleto[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];
	char auxSeleccion[30];
	char pAuxSeleccion[30];
	int auxIntSeleccion;
	Jugador* unJugador = NULL;

	if(pArrayListaJugadores != NULL && index >= 0 && index < ll_len(pArrayListaJugadores)
	&& pArrayListaSeleccion != NULL){

		unJugador = (Jugador*) ll_get(pArrayListaJugadores, index);

		if(unJugador != NULL){

			if(jug_getId(unJugador, &auxId)
			&& jug_getNombreCompleto(unJugador, auxNombreCompleto)
			&& jug_getEdad(unJugador, &auxEdad)
			&& jug_getPosicion(unJugador, auxPosicion)
			&& jug_getNacionalidad(unJugador, auxNacionalidad)
			&& jug_getIdSeleccion(unJugador, &auxIntSeleccion)){

				if(auxIntSeleccion > 0
				&& buscarNombreDeSeleccion(pArrayListaSeleccion, auxIntSeleccion, pAuxSeleccion)){

					strncpy(auxSeleccion, pAuxSeleccion, 30);

				}else{

					strncpy(auxSeleccion, "NO CONVOCADO", 30);
				}

					printf("|%10d | %25s | %10d | %20s | %15s | %20s |\n", auxId, auxNombreCompleto, auxEdad,
																	auxPosicion, auxNacionalidad, auxSeleccion);
					retorno = 1;
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
int jug_ordenarPorNacionalidad(void* jugadorA, void* jugadorB){

	int retorno = 0;
	char nacionalidadA[40];
	char nacionalidadB[40];
	Jugador* auxJugadorA;
	Jugador* auxJugadorB;

	auxJugadorA = (Jugador*)jugadorA;
	auxJugadorB = (Jugador*)jugadorB;

	if(jugadorA != NULL && jugadorB != NULL){

		if(jug_getNacionalidad(auxJugadorA, nacionalidadA)
		&& jug_getNacionalidad(auxJugadorB, nacionalidadB)){

			if(stricmp(nacionalidadA, nacionalidadB) > 0 ){

				retorno = 1;

			}else if(stricmp(nacionalidadA, nacionalidadB) < 0){

				retorno = -1;
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
int jug_ordenarPorNombre(void* jugadorA, void* jugadorB){

	int retorno = 0;
	char auxNombreA[100];
	char auxNombreB[100];
	Jugador* auxJugadorA;
	Jugador* auxJugadorB;

	auxJugadorA = (Jugador*)jugadorA;
	auxJugadorB = (Jugador*)jugadorB;

	if(jugadorA != NULL && jugadorB != NULL){

		if(jug_getNombreCompleto(auxJugadorA, auxNombreA)
		&& jug_getNombreCompleto(auxJugadorB, auxNombreB)){

			if(stricmp(auxNombreA, auxNombreB) > 0 ){

				retorno = 1;
			}
			else if(stricmp(auxNombreA, auxNombreB) < 0){

				retorno = -1;
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
int jug_ordenarPorEdad(void* jugadorA, void* jugadorB){

	int retorno = 0;
	int edadA;
	int edadB;
	Jugador* auxJugadorA;
	Jugador* auxJugadorB;

	auxJugadorA = (Jugador*)jugadorA;
	auxJugadorB = (Jugador*)jugadorB;

	if(jugadorA != NULL && jugadorB != NULL){

		if(jug_getEdad(auxJugadorA, &edadA)
		&& jug_getEdad(auxJugadorB, &edadB)){

			if(edadA > edadB){

				retorno = 1;
			}
			else if(edadA < edadB){

				retorno = -1;
			}
		}
	}
	 return retorno;
}

/**
 * \brief despliega opciones y se debera elegir la opcion que se desee ingresando un entero
 * \param puntero a char.
 * \return int, 1 bien, 0 ERROR.
**/
int jug_elegirNacionalidad(char pSeleccionElegida[]){

	int retorno = 0;
	int opcion;

	if(pSeleccionElegida != NULL){

		elegirNacionalidad();

		if(utn_getNumero(&opcion, "Opcion: ", "\nERROR opcion no validar\nReingrese\n", 1, 32, 3)){

			switch(opcion){

			case 1:
				strncpy(pSeleccionElegida,"Aleman",  30);
				break;

			case 2:
				strncpy(pSeleccionElegida, "Arabe",  30);
				break;

			case 3:
				strncpy(pSeleccionElegida, "Argentino", 30);
				break;

			case 4:
				strncpy(pSeleccionElegida, "Australiano", 30);
				break;

			case 5:
				strncpy(pSeleccionElegida, "Belga", 30);
				break;

			case 6:
				strncpy(pSeleccionElegida, "Brasilero", 30);
				break;

			case 7:
				strncpy(pSeleccionElegida, "Camerunes", 30);
				break;

			case 8:
				strncpy(pSeleccionElegida, "Canadiense", 30);
				break;

			case 9:
				strncpy(pSeleccionElegida, "Coreano", 30);
				break;

			case 10:
				strncpy(pSeleccionElegida, "Costa Riqueño", 30);
				break;

			case 11:
				strncpy(pSeleccionElegida, "Croata", 30);
				break;

			case 12:
				strncpy(pSeleccionElegida, "Danes", 30);
				break;

			case 13:
				strncpy(pSeleccionElegida, "Ecuatoriano", 30);
				break;

			case 14:
				strncpy(pSeleccionElegida, "Espanol", 30);
				break;

			case 15:
				strncpy(pSeleccionElegida, "Estado Unidense", 30);
				break;

			case 16:
				strncpy(pSeleccionElegida, "Frances", 30);
				break;

			case 17:
				strncpy(pSeleccionElegida, "Gales", 30);
				break;

			case 18:
				strncpy(pSeleccionElegida, "Ghanes", 30);
				break;

			case 19:
				strncpy(pSeleccionElegida, "Holandes", 30);
				break;

			case 20:
				strncpy(pSeleccionElegida, "Ingles", 30);
				break;

			case 21:
				strncpy(pSeleccionElegida, "Irani", 30);
				break;

			case 22:
				strncpy(pSeleccionElegida, "Japones", 30);
				break;

			case 23:
				strncpy(pSeleccionElegida, "Marroqui", 30);
				break;

			case 24:
				strncpy(pSeleccionElegida, "Mexicano", 30);
				break;

			case 25:
				strncpy(pSeleccionElegida, "Polaco", 30);
				break;

			case 26:
				strncpy(pSeleccionElegida, "Portugues", 30);
				break;

			case 27:
				strncpy(pSeleccionElegida, "Qatari", 30);
				break;

			case 28:
				strncpy(pSeleccionElegida, "Senegales", 30);
				break;

			case 29:
				strncpy(pSeleccionElegida, "Serbio", 30);
				break;

			case 30:
				strncpy(pSeleccionElegida, "Suizo", 30);
				break;

			case 31:
				strncpy(pSeleccionElegida, "Tunecino", 30);
				break;

			case 32:
				strncpy(pSeleccionElegida, "Uruguayo", 30);
				break;
			}
			retorno = 1;
		}
		printf("Usted selecciono %s\n", pSeleccionElegida);
	}
	return retorno;
}



/**
 * \brief despliega opciones y se debera elegir la opcion que se desee ingresando un entero
 * \param puntero a char.
 * \return int, 1 bien, 0 ERROR.
**/
int jug_elegirPosicion(char pPosicionElegida[]){

	int retorno = 0;
	int opcion;

	if(pPosicionElegida != NULL){

		elegirPosicion();
		if(utn_getNumero(&opcion, "Opcion: ", "\nERROR opcion no validar\nReingrese\n", 1, 13, 5)){

			switch(opcion){

			case 1:
				strncpy(pPosicionElegida, "Portero",  30);
				break;

			case 2:
				strncpy(pPosicionElegida, "Defensa central",  30);
				break;

			case 3:
				strncpy(pPosicionElegida, "Lateral izquierdo", 30);
				break;

			case 4:
				strncpy(pPosicionElegida, "Lateral derecho", 30);
				break;

			case 5:
				strncpy(pPosicionElegida, "Pivote", 30);
				break;

			case 6:
				strncpy(pPosicionElegida, "Mediocentro", 30);
				break;

			case 7:
				strncpy(pPosicionElegida, "Mediocentro ofensivo", 30);
				break;

			case 8:
				strncpy(pPosicionElegida, "Mediapunta", 30);
				break;

			case 9:
				strncpy(pPosicionElegida, "Extremo derecho", 30);
				break;

			case 10:
				strncpy(pPosicionElegida, "Extremo izquierdo", 30);
				break;

			case 11:
				strncpy(pPosicionElegida, "Interior izquierdo", 30);
				break;

			case 12:
				strncpy(pPosicionElegida, "Interior derecho", 30);
				break;

			case 13:
				strncpy(pPosicionElegida, "Delantero centro", 30);
				break;
			}
			retorno = 1;
		}
		printf("Usted selecciono %s\n", pPosicionElegida);
	}
	return retorno;
}

