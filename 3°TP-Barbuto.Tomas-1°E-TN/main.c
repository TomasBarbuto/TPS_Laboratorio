#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Menu.h"
#include "Validaciones.h"

int main(){
	setbuf(stdout,NULL);

	int opcion;
	int ultimoId;
	char confirmar[2];
	int flagGuardarArchivos = 0;
	int flagCambios = 0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    do{
    		menuPrincipal();
    		if(utn_getNumero(&opcion, "\nOpcion: ","\nOpcion no valida, REINGRESE: ", 1, 11, 5)){


				switch(opcion){

				case 1:
					if(ll_isEmpty(listaJugadores) && ll_isEmpty(listaSelecciones)){

						if(controller_cargarJugadoresDesdeTexto("jugadores.csv", listaJugadores)
						&& controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones)){

							printf("Se cargaron los datos correctamente\n");

						}else{

							printf("ERROR al cargar los archivos\n");
						}
					}else{

						printf("Los archivos ya se encuentran cargados...\n");
					}
					break;

				case 2:
					if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

						if(controller_agregarJugador(listaJugadores)){
							flagCambios = 1;
							printf("Se agrego un jugador correctamente\n");
						}
					}else{

						printf("Se debe cargar el archivo de jugadores antes de realizar un ALTA\n");
					}
					break;

				case 3:
					if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

						if(controller_editarJugador(listaJugadores)){
							flagCambios = 1;
							printf("Se modifico un jugador correctamente\n");

						}else{

							printf("No se generaron cambios en el jugador\n");
						}
					}else{

						printf("Se debe cargar el archivo de jugadores antes de realizar una Modificacion\n");
					}
					break;

				case 4:
					if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

						if(controller_removerJugador(listaJugadores,listaSelecciones)){
							flagCambios = 1;
							printf("Se elimino un jugador\n");
						}
					}else{

						printf("Se deben cargar los archivos antes de remover un jugador\n");
					}
					break;

				case 5:
					if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

						if(!menuListar(listaJugadores, listaSelecciones)){

							printf("ERROR al mostrar el menu\n");
						}
					}else{

						printf("No hay nada para mostrar, debe cargar los archivos previamente\n");
					}
					break;

				case 6:
					if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

						if(!menuConvocarJugadores(listaJugadores, listaSelecciones)){

							printf("El jugador ya esta convocado\n");
						}
						flagCambios = 1;
					}else{

						printf("No hay jugadores para convocar, debe cargar los archivos previamente\n");
					}
					break;

				case 7:
					if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

						if(!menuOrdenarListar(listaJugadores, listaSelecciones)){

							printf("ERROR al mostrar el menu\n");
						}
						flagCambios = 1;
					}else{

						printf("No hay datos para realizar ordenamientos\n");
					}
					break;

				case 8:
					if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

						if(!menuGuardarBinario(listaJugadores, listaSelecciones)){

							printf("ERROR al mostrar el menu\n");
						}

					}else{

						printf("Debe cargar los archivos previamente para poder generar un archivo binario\n");
					}
					break;

				case 9:
					if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){
						if(!menuCargarBinario(listaJugadores, listaSelecciones)){

							printf("ERROR al mostrar el menu\n");
						}
					}else{

						printf("Debera de guardar una archivo binario previamente\n");
					}
					break;

				case 10:
					if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

						if(controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones)
						&& controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores)){

							flagGuardarArchivos = 1;
							ll_clear(listaJugadores);
							ll_clear(listaSelecciones);
						}

						ultimoId = idAutoincremental()-1;

						if(controller_guardarIdAutoincremental("ID.csv", ultimoId)){

							printf("Se Guardaron todos los archivos correctamente\n"
								   "Si desea volver a manipular datos, debera volver a cargar los archivos\n");
						}
					}else{

						printf("No cargo ningun archivo Previamente, no hay nada que guardar\n");
					}
					break;
				case 11:
						if(flagGuardarArchivos == 0 && flagCambios == 0){

							if(!utn_getNombre(confirmar, 3, "\nIngrese 'Si' si desea finalizar el programa: ",
								"No ingreso algo correcto\nReintente....\n", 3)){

								printf("Demasiados intentos...\nSera redirigido al menu principal...\n");
								break;
							}
						}else{

							printf("No Guardo los archivos, los cambios realizados se perderan\n");
							if(!utn_getNombre(confirmar, 3, "\nIngrese 'Si' si desea finalizar el programa de todos modos: ",
								"No ingreso algo correcto\nReintente....\n", 3)){

								printf("Demasiados intentos...\nSera redirigido al menu principal...\n");
								break;
							}
						}
					break;
				}
    		}else{

    			printf("Supero la cantidad de reintentos\nPor favor seleccione un opcion valida\n");
    		}
	}while(!stricmp(confirmar, "Si") == 0);

    printf("PROGRAMA FINALIZADO\n");

    return 0;
}

