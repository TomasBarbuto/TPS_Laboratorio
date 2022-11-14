#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Menu.h"
#include "Jugador.h"
#include "Validaciones.h"
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

/**
 * \brief Muestra un menu con opciones.
 * \param VOID
 * \return VOID
**/
void menuOrdenarJugadores(){

	printf("Menu de ordenar jugadores\n"
		   "1-Jugadores por Nacionalidad\n"
		   "2-Jugador por Nombre\n"
		   "3-Jugadores por edad\n"
		   "4-Salir\n");
}

/**
 * \brief Muestra un menu con opciones.
 * \param VOID
 * \return VOID
**/
void menuOrdenarSelecciones(){

	printf("Menu de ordenar de selecciones\n"
		   "1-Selecciones por confederacion\n"
		   "2-Salir");
}

/**
 * \brief Muestra un menu con opciones.
 * \param VOID
 * \return VOID
**/
void menuOrdenar(){

	printf("Menu de ordenar y listar\n"
		   "1-Ordenar Jugadores\n"
		   "2-Ordenar Selecciones\n"
		   "3-Salir\n");
}

/**
 * \brief Muestra un menu con opciones que se pueden elegir.
 * \param LinkedList* listaJugadores, LinkedList* listaSelecciones
 * \return int 1 bien, 0 ERROR.
**/
int menuOrdenarListar(LinkedList* listaJugadores, LinkedList* listaSelecciones){

	int retorno = 0;
	int opcionOrdenamiento;

	if(listaJugadores != NULL && listaSelecciones != NULL){

		do{

			menuOrdenar();
			if(getNumber(&opcionOrdenamiento,"\nOpcion: " ,"Error ingrese las opciones que se muestran en el menu\n"
										, 1,3)){

				switch(opcionOrdenamiento){

				case 1:

					if(!controller_ordenarJugadores(listaJugadores)){

						printf("Falla al entrar al menu\n");
					}
					break;
				case 2:
					if(!controller_ordenarSelecciones(listaSelecciones)){

						printf("Falla al entrar al menu\n");
					}
					break;
				case 3:
					printf("Sera redirigido al menu principal\n");
					system("pause");
					break;
				}
			}

		}while(opcionOrdenamiento != 3);
		retorno = 1;
	}

	return retorno;
}

int menuListar(LinkedList* listaJugadores, LinkedList* listaSelecciones){

	int retorno = 0;
	int opcionListar;

	if(listaJugadores != NULL && listaSelecciones != NULL){

		do{
			menuListados();

			if(getNumber(&opcionListar, "\nOpcion: ", "Opcion no valida\nREINGRESE: ", 1, 4)){

				switch(opcionListar){

				case 1:
					if(!controller_listarJugadoresConSeleccion(listaJugadores, listaSelecciones)){

						printf("ERROR al listar los jugadores\n");
					}
					break;

				case 2:
					if(!controller_listarSelecciones(listaSelecciones)){

						printf("ERROR al listar las selecciones\n");
					}
					break;

				case 3:
					if(!controller_ListarConvocados(listaJugadores, listaSelecciones)){

						printf("ERROR al listar los convocados\n");
					}
					break;

				case 4:
					printf("Sera redirigido al menu principal\n");
					system("pause");
					break;
				}
			}else{

				printf("ERROR Menu no disponible\n");
			}

		}while(opcionListar != 4);
		retorno = 1;
	}
	return retorno;
}

int menuConvocarJugadores(LinkedList* listaJugadores, LinkedList* listaSelecciones){

	int retorno = 0;
	int opcionConvocar;

	if(listaJugadores != NULL && listaSelecciones != NULL){

		do{
			menuConvocados();
			if(getNumber(&opcionConvocar, "\nOpcion: ", "Opcion no valida\nREINGRESE: ", 1, 3)){

				switch(opcionConvocar){

				case 1:
					if(controller_ConvocarJugadores(listaSelecciones, listaJugadores)){

						printf("Se convoco exitosamente\n");
					}else{

						printf("ERROR, reintente nuevamente\n");
					}
					system("pause");
					break;

				case 2:
					if(controller_removerJugadorDeSeleccion(listaSelecciones, listaJugadores)){

						printf("Se removio exitosamente\n");
					}else{

						printf("ERROR, reintente nuevamente\n");
					}
					system("pause");
					break;

				case 3:
					printf("Sera redirigido al menu principal\n");
					system("pause");
					break;
				}
			}
		}while(opcionConvocar != 3);
		retorno = 1;
	}
		return retorno;
}

int menuGuardarBinario(LinkedList* listaJugadores, LinkedList* listaSelecciones, int* FlagBinario){

	int retorno = 0;
	int opcionGuardarBinario;
	char confederacion[30];

	if(listaJugadores != NULL && listaSelecciones != NULL){

		do{

			menuArchivoBinario();
			if(getNumber(&opcionGuardarBinario, "\nOpcion: ", "Opcion no valida\nREINGRESE: ", 1, 6)){

				switch(opcionGuardarBinario){

				case 1:
					strncpy(confederacion, "AFC", 30);
					if(controller_guardarJugadorPorConfederacionBinario("AFC.bin", listaJugadores,
																listaSelecciones, confederacion)){
						printf("Se guardo el archivo correctamente\n");
						*FlagBinario = 1;
					}
					break;

				case 2:
					strncpy(confederacion, "CAF", 30);
					if(controller_guardarJugadorPorConfederacionBinario("CAF.bin", listaJugadores,
																	listaSelecciones, confederacion)){
						printf("Se guardo el archivo correctamente\n");
						*FlagBinario = 1;
					}
					break;

				case 3:
					strncpy(confederacion, "CONCACAF", 30);
					if(controller_guardarJugadorPorConfederacionBinario("CONCACAF.bin", listaJugadores,
																	listaSelecciones, confederacion)){
						printf("Se guardo el archivo correctamente\n");
						*FlagBinario = 1;
					}
					break;

				case 4:
					strncpy(confederacion, "CONMEBOL", 30);
					if(controller_guardarJugadorPorConfederacionBinario("CONMEBOL.bin", listaJugadores,
																listaSelecciones, confederacion)){
						printf("Se guardo el archivo correctamente\n");
						*FlagBinario = 1;
					}
					break;

				case 5:
					strncpy(confederacion, "UEFA", 30);
					if(controller_guardarJugadorPorConfederacionBinario("UEFA.bin", listaJugadores,
																	listaSelecciones, confederacion)){
						printf("Se guardo el archivo correctamente\n");
						*FlagBinario = 1;
					}
					break;

				case 6:
					printf("Sera redirigido al menu principal\n");
					system("pause");
					break;
				}
			}
		}while(opcionGuardarBinario != 6);
		retorno = 1;
	}
	return retorno;
}

int menuCargarBinario(LinkedList* listaJugadores, LinkedList* listaSelecciones){

	int retorno = 0;
	int opcionGuardarBinario;
	char confederacion[30];

	if(listaJugadores != NULL && listaSelecciones != NULL){

		do{

			menuArchivoBinario();
			if(getNumber(&opcionGuardarBinario, "\nOpcion: ", "Opcion no valida\nREINGRESE: ", 1, 6)){

				switch(opcionGuardarBinario){

				case 1:
					strncpy(confederacion, "AFC", 30);
					if(!controller_cargarJugadoresPorConfederacionBinario("AFC.bin", listaJugadores,
																	listaSelecciones, confederacion)){
						retorno = 0;
						break;
					}
					break;

				case 2:
					strncpy(confederacion, "CAF", 30);
					if(!controller_cargarJugadoresPorConfederacionBinario("CAF.bin", listaJugadores,
																	listaSelecciones, confederacion)){
						retorno = 0;
						break;
					}
					break;

				case 3:
					strncpy(confederacion, "CONCACAF", 30);
					if(!controller_cargarJugadoresPorConfederacionBinario("CONCACAF.bin", listaJugadores,
																	listaSelecciones, confederacion)){

						retorno = 0;
						break;
					}
					break;

				case 4:
					strncpy(confederacion, "CONMEBOL", 30);
					if(!controller_cargarJugadoresPorConfederacionBinario("CONMEBOL.bin", listaJugadores,
																listaSelecciones, confederacion)){

						retorno = 0;
						break;
					}
					break;

				case 5:
					strncpy(confederacion, "UEFA", 30);
					if(!controller_cargarJugadoresPorConfederacionBinario("UEFA.bin", listaJugadores,
																	listaSelecciones, confederacion)){

						retorno = 0;
						break;
					}
					break;

				case 6:
					printf("Sera redirigido al menu principal\n");
					system("pause");
					break;
				}
			}
		}while(opcionGuardarBinario != 6);
		retorno = 1;
	}
	return retorno;
}

