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
 * \brief Muestra un menu con opciones.
 * \param VOID
 * \return VOID
**/
void elegirNacionalidad(){

	printf("\nSeleccione la nacionalidad que desea\n"
			"1-ALEMANIA\n"
			"2-ARABIA SAUDITA\n"
			"3-ARGENTINA\n"
			"4-AUSTRALIA\n"
			"5-BELGICA\n"
			"6-BRASIL\n"
			"7-CAMERUN\n"
			"8-CANADA\n"
			"9-COREA DEL SUR\n"
			"10-COSTA RICA\n"
			"11-CROACIA\n"
			"12-DINAMARCA\n"
			"13-ECUADOR\n"
			"14-ESPANA\n"
			"15-ESTADOS UNIDOS\n"
			"16-FRACIA\n"
			"17-GALES\n"
			"18-GHANA\n"
			"19-HOLANDA\n"
			"20-INGLATERRA\n"
			"21-IRAN\n"
			"22-JAPON\n"
			"23-MARRUECOS\n"
			"24-MEXICO\n"
			"25-POLONIA\n"
			"26-PORTUGAL\n"
			"27-QATAR\n"
			"28-SENEGAL\n"
			"29-SERBIA\n"
			"30-SUIZA\n"
			"31-TUNEZ\n"
			"32-URUGUAY\n");
}

/**
 * \brief Muestra un menu con opciones.
 * \param VOID
 * \return VOID
**/
void elegirPosicion(){

	printf("\nSeleccione la nacionalidad que desea\n"
			"1- Portero\n"
			"2- Defensa central\n"
			"3- Lateral izquierdo\n"
			"4- Lateral derecho\n"
			"5- Pivote\n"
			"6- Mediocentro\n"
			"7- Mediocentro ofensivo\n"
			"8- Mediapunta\n"
			"9- Extremo derecho\n"
			"10- Extremo izquierdo\n"
			"11- Interior izquierdo\n"
			"12- Interior derecho\n"
			"13- Delantero centro\n");
}
/**
 * \brief Muestra un menu con opciones que se pueden elegir para ordenar y listar.
 * \param LinkedList* listaJugadores, LinkedList* listaSelecciones
 * \return int 1 bien, 0 ERROR.
**/
int menuOrdenarListar(LinkedList* listaJugadores, LinkedList* listaSelecciones){

	int retorno = 0;
	int opcionOrdenamiento;

	if(listaJugadores != NULL && listaSelecciones != NULL){

		retorno = 1;

		do{

			menuOrdenar();
			if(getNumber(&opcionOrdenamiento,"\nOpcion: " ,"Error ingrese las opciones que se muestran en el menu\n"
										, 1,3)){

				switch(opcionOrdenamiento){

				case 1:

					if(!controller_ordenarJugadores(listaJugadores)){

						printf("Falla al entrar al menu\n");
						retorno = 0;
						break;

					}
					break;
				case 2:
					if(!controller_ordenarSelecciones(listaSelecciones)){

						printf("Falla al entrar al menu\n");
						retorno = 0;
						break;
					}
					break;
				case 3:
					printf("Sera redirigido al menu principal\n");
					system("pause");
					break;
				}
			}else{

				printf("ERROR Menu no disponible\n");
				retorno = 0;
				break;
			}
		}while(opcionOrdenamiento != 3);
	}
	return retorno;
}

/**
 * \brief Muestra un menu con opciones que se pueden elegir para listar.
 * \param LinkedList* listaJugadores, LinkedList* listaSelecciones
 * \return int 1 bien, 0 ERROR.
**/
int menuListar(LinkedList* listaJugadores, LinkedList* listaSelecciones){

	int retorno = 0;
	int opcionListar;

	if(listaJugadores != NULL && listaSelecciones != NULL){

		retorno = 1;

		do{
			menuListados();

			if(getNumber(&opcionListar, "\nOpcion: ", "Opcion no valida\nREINGRESE: ", 1, 4)){

				switch(opcionListar){

				case 1:
					if(!controller_listarJugadoresConSeleccion(listaJugadores, listaSelecciones)){

						printf("ERROR al listar los jugadores\n");
						retorno = 0;
						break;
					}
					break;

				case 2:
					if(!controller_listarSelecciones(listaSelecciones)){

						printf("ERROR al listar las selecciones\n");
						retorno = 0;
						break;
					}
					break;

				case 3:
					if(!controller_ListarConvocados(listaJugadores, listaSelecciones)){

						printf("ERROR al listar los convocados\n");
						retorno = 0;
						break;
					}
					break;

				case 4:
					printf("Sera redirigido al menu principal\n");
					system("pause");
					break;
				}
			}else{

				printf("ERROR Menu no disponible\n");
				retorno = 0;
				break;
			}

		}while(opcionListar != 4);
	}
	return retorno;
}

/**
 * \brief Muestra un menu con opciones que se pueden elegir para convocar o revocar.
 * \param LinkedList* listaJugadores, LinkedList* listaSelecciones
 * \return int 1 bien, 0 ERROR.
**/
int menuConvocarJugadores(LinkedList* listaJugadores, LinkedList* listaSelecciones){

	int retorno = 0;
	int opcionConvocar;

	if(listaJugadores != NULL && listaSelecciones != NULL){

		retorno = 1;

		do{
			menuConvocados();
			if(getNumber(&opcionConvocar, "\nOpcion: ", "Opcion no valida\nREINGRESE: ", 1, 3)){

				switch(opcionConvocar){

				case 1:
					if(controller_ConvocarJugadores(listaSelecciones, listaJugadores)){

						printf("Se convoco exitosamente\n");
					}else{

						retorno = 0;
						printf("ERROR, reintente nuevamente\n");
						break;
					}
					system("pause");
					break;

				case 2:
					if(controller_removerJugadorDeSeleccion(listaSelecciones, listaJugadores)){

						printf("Se removio exitosamente\n");
					}else{
						retorno = 0;
						printf("ERROR, reintente nuevamente\n");
						break;
					}
					system("pause");
					break;

				case 3:
					printf("Sera redirigido al menu principal\n");
					system("pause");
					break;
				}
			}else{

				printf("ERROR Menu no disponible\n");
				retorno = 0;
				break;
			}
		}while(opcionConvocar != 3);

	}
		return retorno;
}

/**
 * \brief Muestra un menu con opciones que se pueden elegir para guardar un archivo binario
 * \param LinkedList* listaJugadores, LinkedList* listaSelecciones, int
 * \return int 1 bien, 0 ERROR.
**/
int menuGuardarBinario(LinkedList* listaJugadores, LinkedList* listaSelecciones, int* FlagBinario){

	int retorno = 0;
	int opcionGuardarBinario;
	char confederacion[30];

	if(listaJugadores != NULL && listaSelecciones != NULL){

		retorno = 1;

		do{

			menuArchivoBinario();
			if(getNumber(&opcionGuardarBinario, "\nOpcion: ", "Opcion no valida\nREINGRESE: ", 1, 6)){

				switch(opcionGuardarBinario){

				case 1:
					strncpy(confederacion, "AFC", 30);
					if(controller_guardarJugadorPorConfederacionBinario("AFC.bin", listaJugadores,
																listaSelecciones, confederacion)){
						printf("Se guardo el archivo correctamente 'AFC.bin' \n");
						*FlagBinario = 1;
					}else{

						printf("No hay jugadores convocados de la confederacion elegida\n");
					}
					system("pause");
					break;

				case 2:
					strncpy(confederacion, "CAF", 30);
					if(controller_guardarJugadorPorConfederacionBinario("CAF.bin", listaJugadores,
																	listaSelecciones, confederacion)){
						printf("Se guardo el archivo correctamente 'CAF.bin' \n");
						*FlagBinario = 1;
					}else{

						printf("No hay jugadores convocados de la confederacion elegida\n");
					}
					system("pause");
					break;

				case 3:
					strncpy(confederacion, "CONCACAF", 30);
					if(controller_guardarJugadorPorConfederacionBinario("CONCACAF.bin", listaJugadores,
																	listaSelecciones, confederacion)){
						printf("Se guardo el archivo correctamente 'CONCACAF.bin' \n");
						*FlagBinario = 1;
					}else{

						printf("No hay jugadores convocados de la confederacion elegida\n");
					}
					system("pause");
					break;

				case 4:
					strncpy(confederacion, "CONMEBOL", 30);
					if(controller_guardarJugadorPorConfederacionBinario("CONMEBOL.bin", listaJugadores,
																listaSelecciones, confederacion)){
						printf("Se guardo el archivo correctamente 'CONMEBOL.bin' \n");
						*FlagBinario = 1;
					}else{

						printf("No hay jugadores convocados de la confederacion elegida\n");
					}
					system("pause");
					break;

				case 5:
					strncpy(confederacion, "UEFA", 30);
					if(controller_guardarJugadorPorConfederacionBinario("UEFA.bin", listaJugadores,
																	listaSelecciones, confederacion)){
						printf("Se guardo el archivo correctamente 'UEFA.bin' \n");
						*FlagBinario = 1;
					}else{

						printf("No hay jugadores convocados de la confederacion elegida\n");
					}
					system("pause");
					break;

				case 6:
					printf("Sera redirigido al menu principal\n");
					system("pause");
					break;
				}
			}else{

				printf("ERROR Menu no disponible\n");
				retorno = 0;
				break;
			}
		}while(opcionGuardarBinario != 6);
	}
	return retorno;
}

/**
 * \brief Muestra un menu con opciones que se pueden elegir para cargar un archivo binario.
 * \param LinkedList* listaJugadores, LinkedList* listaSelecciones
 * \return int 1 bien, 0 ERROR.
**/
int menuCargarBinario(LinkedList* listaJugadores, LinkedList* listaSelecciones){

	int retorno = 0;
	int opcionGuardarBinario;
	char confederacion[30];

	if(listaJugadores != NULL && listaSelecciones != NULL){

		retorno = 1;

		do{

			menuArchivoBinario();
			if(getNumber(&opcionGuardarBinario, "\nOpcion: ", "Opcion no valida\nREINGRESE: ", 1, 6)){

				switch(opcionGuardarBinario){

				case 1:
					strncpy(confederacion, "AFC", 30);
					if(controller_cargarJugadoresPorConfederacionBinario("AFC.bin", listaJugadores,
																	listaSelecciones, confederacion)){

						printf("\tLista de jugadores convocados por 'AFC' \n\n");

					}else{

						printf("No hay jugadores convocados de la confederacion elegida\n");

					}
					system("pause");
					break;

				case 2:
					strncpy(confederacion, "CAF", 30);
					if(controller_cargarJugadoresPorConfederacionBinario("CAF.bin", listaJugadores,
																	listaSelecciones, confederacion)){

						printf("\tLista de jugadores convocados por 'CAF' \n\n");
					}else{

						printf("No hay jugadores convocados de la confederacion elegida\n");


					}
					system("pause");
					break;

				case 3:
					strncpy(confederacion, "CONCACAF", 30);
					if(controller_cargarJugadoresPorConfederacionBinario("CONCACAF.bin", listaJugadores,
																	listaSelecciones, confederacion)){

						printf("\tLista de jugadores convocados por 'CONCACAF' \n\n");
					}else{

						printf("No hay jugadores convocados de la confederacion elegida\n");

					}
					system("pause");
					break;

				case 4:
					strncpy(confederacion, "CONMEBOL", 30);
					if(controller_cargarJugadoresPorConfederacionBinario("CONMEBOL.bin", listaJugadores,
																listaSelecciones, confederacion)){

						printf("\tLista de jugadores convocados por 'CONMEBOL' \n\n");
					}else{

						printf("No hay jugadores convocados de la confederacion elegida\n");

					}
					system("pause");
					break;

				case 5:
					strncpy(confederacion, "UEFA", 30);
					if(controller_cargarJugadoresPorConfederacionBinario("UEFA.bin", listaJugadores,
																	listaSelecciones, confederacion)){

						printf("\tLista de jugadores convocados por 'UEFA' \n\n");
					}else{

						printf("No hay jugadores convocados de la confederacion elegida\n");

					}
					system("pause");
					break;

				case 6:
					printf("Sera redirigido al menu principal\n");
					system("pause");
					break;
				}
			}
		}while(opcionGuardarBinario != 6);
	}
	return retorno;
}

