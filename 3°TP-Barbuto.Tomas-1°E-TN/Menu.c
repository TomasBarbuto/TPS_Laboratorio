#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Jugador.h"
#include "Validaciones.h"
#include "LinkedList.h"
#include "Seleccion.h"
#include "Controller.h"

/**
 * \brief Muestra un menu con opciones.
 * \param VOID
 * \return VOID
**/
void menuPrincipal(){

	printf("\t\tBienvenido al Menu FIFA WORLD\n"
		   "\tSeleccione la opcion que desee:\n"
		   "1-CARGA DE ARCHIVOS\n"
		   "2-ALTA DE JUGADOR\n"
		   "3-MODIFICACIÓN DE JUGADOR\n"
		   "4-BAJA DE JUGADOR\n"
		   "5-LISTADOS\n"
		   "6-CONVOCAR JUGADORES\n"
		   "7-ORDENAR Y LISTAR:\n"
		   "8-GENERAR ARCHIVO BINARIO\n"
		   "9-CARGAR ARCHIVO BINARIO\n"
		   "10-GUARDAR ARCHIVOS .CSV\n"
		   "11-SALIR\n");
}

/**
 * \brief Muestra un menu con opciones.
 * \param VOID
 * \return VOID
**/
void menuModificar(){

	printf("Seleccione el campo a modificar\n"
		   "1-Nombre\n"
		   "2-Edad\n"
		   "3-Posicion\n"
		   "4-Nacionalidad\n"
		   "5-Salir\n");

}

/**
 * \brief Muestra un menu con opciones.
 * \param VOID
 * \return VOID
**/
void menuListados(){

	printf("Seleccione el Listado\n"
			   "1-TODOS LOS JUGADORES\n"
			   "2-TODAS LAS SELECCIONES\n"
			   "3-JUGADORES CONVOCADOS\n"
			   "4-SALIR\n");

}

/**
 * \brief Muestra un menu con opciones.
 * \param VOID
 * \return VOID
**/
void menuConvocados(){

	printf("Seleccione la accion que desea realizar\n"
		   "1-CONVOCAR JUGADOR\n"
		   "2-QUITAR DE CONVOCADOS\n"
		   "3-SALIR\n");
}

/**
 * \brief Muestra un menu con opciones.
 * \param VOID
 * \return VOID
**/
void menuArchivoBinario(){

	printf("Seleccione que archivo binario desea generar\n"
		   "1-AFC\n"
		   "2-CAF\n"
		   "3-CONCACAF\n"
		   "4-CONMEBOL\n"
		   "5-UEFA\n"
		   "6-SALIR\n");
}
void menuOrdenar(){

	printf("Menu de ordenar y listar\n"
		   "1-Jugadores por Nacionalidad\n"
		   "2-Jugador por Nombre\n"
		   "3-Jugadores por edad\n"
		   "4-Selecciones por confederacion\n"
		   "5-Salir");
}
int menuOrdenarListar(LinkedList* listaJugadores, LinkedList* listaSelecciones){

	int retorno = 0;
	int orden;
	int opcionOrdenamiento;

	if(listaJugadores != NULL && listaSelecciones != NULL){


		do{

			menuOrdenar();
			if(getNumber(&opcionOrdenamiento,"\nOpcion: " ,"Error ingrese las opciones que se muestran en el menu\n"
										, 1,6)){

				switch(opcionOrdenamiento){

				case 1:
					if(getNumber(&orden, "Ingrese el orden que desea listar\n"
									  "1-Ascendente\n"
									  "0-Descendente\n"
									  "opcion: ","ERROR, VALOR NO VALIDO\n", 0, 1)){

						if(!ll_sort(listaJugadores, jug_ordenarPorNacionalidad, orden)){

							controller_listarJugadoresConSeleccion(listaJugadores, listaSelecciones);
						}else{

							printf("\nERROR al Ordenar\n");
						}
					}else{

						printf("ERROR, sera redirigido al menu principal\n");
					}

					break;
				case 2:
					if(getNumber(&orden, "Ingrese el orden que desea listar "
									  "1-Ascendente\n"
									  "0-Descendente\n"
									  "opcion: ", "ERROR, VALOR NO VALIDO\n", 0, 1)){

						if(!ll_sort(listaJugadores, jug_ordenarPorNombre, orden)){

							controller_listarJugadoresConSeleccion(listaJugadores, listaSelecciones);

						}else{

							printf("\nERROR al Ordenar\n");
						}
					}else{
						printf("ERROR, sera redirigido al menu principal\n");
					}
					break;
				case 3:
					if(getNumber(&orden, "Ingrese el orden que desea listar "
									  "1-Ascendente\n"
									  "0-Descendente\n"
									  "opcion: ", "ERROR, VALOR NO VALIDO\n", 0, 1)){

						if(!ll_sort(listaJugadores, jug_ordenarPorEdad, orden)){

							controller_listarJugadoresConSeleccion(listaJugadores, listaSelecciones);

						}else{
							printf("\nERROR al Ordenar\n");
						}
					}else{

						printf("ERROR, sera redirigido al menu principal\n");
					}
					break;
				case 4:
					if(getNumber(&orden, "Ingrese el orden que desea listar "
									  "1-Ascendente\n"
									  "0-Descendente\n"
									  "opcion: ", "ERROR, VALOR NO VALIDO\n", 0, 1)){
						if(!ll_sort(listaSelecciones, selec_ordenarPorConfederacion, orden)){

							controller_listarSelecciones(listaSelecciones);

						}else{
							printf("\nERROR al Ordenar\n");
						}
					}else{

						printf("ERROR, sera redirigido al menu principal\n");
					}
					break;
				case 5:
					printf("Sera redirigido al menu principal\n");
					system("pause");
					break;
			}
		}
	}while(opcionOrdenamiento != 5);
	retorno = 1;
}

	return retorno;
}



