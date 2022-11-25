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
	int opcionListar;
	int opcionConvocar;
	int opcionGuardarBinario;
	int opcionCargarBinario;
	int opcionOrdenamiento;
	int ultimoId;
	char confederacionGuardarBinario[30];
	char confederacionCargarBinario[30];
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

						do{
							menuListados();

							if(utn_getNumero(&opcionListar, "\nOpcion: ", "Opcion no valida\nREINGRESE: ", 1, 4,5)){

								switch(opcionListar){

								case 1:
									if(!controller_listarJugadoresConSeleccion(listaJugadores, listaSelecciones)){

										printf("ERROR al listar los jugadores\n");
										break;
									}
									break;

								case 2:
									if(!controller_listarSelecciones(listaSelecciones)){

										printf("ERROR al listar las selecciones\n");
										break;
									}
									break;

								case 3:
									if(!controller_ListarConvocados(listaJugadores, listaSelecciones)){

										printf("ERROR al listar los convocados\n");
										break;
									}
									break;

								case 4:
									printf("Sera redirigido al menu principal\n");
									break;
								}
							}else{

								printf("Supero la cantidad de reintentos...\n sera redirigido al menu principal\n");
								break;
							}

						}while(opcionListar != 4);
					}else{

						printf("No hay nada para mostrar, debe cargar los archivos previamente\n");
					}
					break;

				case 6:
					if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

						do{
							menuConvocados();
							if(utn_getNumero(&opcionConvocar, "\nOpcion: ", "Opcion no valida\nREINGRESE: ", 1, 3, 5)){

								switch(opcionConvocar){

								case 1:
									if(controller_ConvocarJugadores(listaSelecciones, listaJugadores)){

										printf("Se convoco exitosamente\n");

									}else{

										break;
									}
									break;

								case 2:
									if(controller_removerJugadorDeSeleccion(listaSelecciones, listaJugadores)){

										printf("Se removio exitosamente\n");

									}else{

										printf("ERROR, reintente nuevamente\n");
										break;
									}
									break;

								case 3:
									printf("Sera redirigido al menu principal\n");
									break;
								}
							}else{

								printf("Supero la cantidad de reintentos...\n sera redirigido al menu principal\n");
								break;
							}
						}while(opcionConvocar != 3);

						flagCambios = 1;
					}else{

						printf("No hay jugadores para convocar, debe cargar los archivos previamente\n");
					}
					break;

				case 7:
					if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

						do{

							menuOrdenar();
							if(utn_getNumero(&opcionOrdenamiento,"\nOpcion: " ,
							"Error ingrese las opciones que se muestran en el menu\n", 1,3,5)){

								switch(opcionOrdenamiento){

								case 1:
									if(!controller_ordenarJugadores(listaJugadores)){

										printf("Falla al entrar al menu\n");
										break;

									}
									break;
								case 2:
									if(!controller_ordenarSelecciones(listaSelecciones)){

										printf("Falla al entrar al menu\n");
										break;
									}
									break;
								case 3:
									printf("Sera redirigido al menu principal\n");
									break;
								}
							}else{

								printf("Supero la cantidad de reintentos...\n sera redirigido al menu principal\n");
								break;
							}
						}while(opcionOrdenamiento != 3);
						flagCambios = 1;
					}else{

						printf("No hay datos para realizar ordenamientos\n");
					}
					break;

				case 8:
					if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

						do{

							menuArchivoBinario();
							if(utn_getNumero(&opcionGuardarBinario, "\nOpcion: ", "Opcion no valida\nREINGRESE: ", 1, 6, 5)){

								switch(opcionGuardarBinario){

								case 1:
									strncpy(confederacionGuardarBinario, "AFC", 30);
									if(controller_guardarJugadorPorConfederacionBinario("AFC.bin", listaJugadores,
																				listaSelecciones, confederacionGuardarBinario)){
										printf("Se guardo el archivo correctamente 'AFC.bin' \n");

									}else{

										printf("No hay jugadores convocados de la confederacion elegida\n");
									}
									break;

								case 2:
									strncpy(confederacionGuardarBinario, "CAF", 30);
									if(controller_guardarJugadorPorConfederacionBinario("CAF.bin", listaJugadores,
																					listaSelecciones, confederacionGuardarBinario)){
										printf("Se guardo el archivo correctamente 'CAF.bin' \n");

									}else{

										printf("No hay jugadores convocados de la confederacion elegida\n");
									}
									break;

								case 3:
									strncpy(confederacionGuardarBinario, "CONCACAF", 30);
									if(controller_guardarJugadorPorConfederacionBinario("CONCACAF.bin", listaJugadores,
																					listaSelecciones, confederacionGuardarBinario)){
										printf("Se guardo el archivo correctamente 'CONCACAF.bin' \n");

									}else{

										printf("No hay jugadores convocados de la confederacion elegida\n");
									}
									break;

								case 4:
									strncpy(confederacionGuardarBinario, "CONMEBOL", 30);
									if(controller_guardarJugadorPorConfederacionBinario("CONMEBOL.bin", listaJugadores,
																				listaSelecciones, confederacionGuardarBinario)){
										printf("Se guardo el archivo correctamente 'CONMEBOL.bin' \n");

									}else{

										printf("No hay jugadores convocados de la confederacion elegida\n");
									}
									break;

								case 5:
									strncpy(confederacionGuardarBinario, "UEFA", 30);
									if(controller_guardarJugadorPorConfederacionBinario("UEFA.bin", listaJugadores,
																					listaSelecciones, confederacionGuardarBinario)){
										printf("Se guardo el archivo correctamente 'UEFA.bin' \n");

									}else{

										printf("No hay jugadores convocados de la confederacion elegida\n");
									}
									break;

								case 6:
									printf("Sera redirigido al menu principal\n");
									break;
								}
							}else{

								printf("Supero la cantidad de reintentos...\n sera redirigido al menu principal\n");
								break;
							}
						}while(opcionGuardarBinario != 6);

					}else{

						printf("Debe cargar los archivos previamente para poder generar un archivo binario\n");
					}
					break;

				case 9:
					if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

						do{

							menuArchivoBinario();
							if(utn_getNumero(&opcionCargarBinario, "\nOpcion: ", "Opcion no valida\nREINGRESE: ", 1, 6, 5)){

								switch(opcionCargarBinario){

								case 1:
									strncpy(confederacionCargarBinario, "AFC", 30);
									if(controller_cargarJugadoresPorConfederacionBinario("AFC.bin", listaJugadores,
																					listaSelecciones, confederacionCargarBinario)){

										printf("\tLista de jugadores convocados por 'AFC' \n\n");

									}else{

										printf("No hay jugadores convocados de la confederacion elegida\n");

									}
									break;

								case 2:
									strncpy(confederacionCargarBinario, "CAF", 30);
									if(controller_cargarJugadoresPorConfederacionBinario("CAF.bin", listaJugadores,
																					listaSelecciones, confederacionCargarBinario)){

										printf("\tLista de jugadores convocados por 'CAF' \n\n");
									}else{

										printf("No hay jugadores convocados de la confederacion elegida\n");

									}
									break;

								case 3:
									strncpy(confederacionCargarBinario, "CONCACAF", 30);
									if(controller_cargarJugadoresPorConfederacionBinario("CONCACAF.bin", listaJugadores,
																					listaSelecciones, confederacionCargarBinario)){

										printf("\tLista de jugadores convocados por 'CONCACAF' \n\n");
									}else{

										printf("No hay jugadores convocados de la confederacion elegida\n");

									}
									break;

								case 4:
									strncpy(confederacionCargarBinario, "CONMEBOL", 30);
									if(controller_cargarJugadoresPorConfederacionBinario("CONMEBOL.bin", listaJugadores,
																				listaSelecciones, confederacionCargarBinario)){

										printf("\tLista de jugadores convocados por 'CONMEBOL' \n\n");
									}else{

										printf("No hay jugadores convocados de la confederacion elegida\n");

									}
									break;

								case 5:
									strncpy(confederacionCargarBinario, "UEFA", 30);
									if(controller_cargarJugadoresPorConfederacionBinario("UEFA.bin", listaJugadores,
																					listaSelecciones, confederacionCargarBinario)){

										printf("\tLista de jugadores convocados por 'UEFA' \n\n");
									}else{

										printf("No hay jugadores convocados de la confederacion elegida\n");

									}
									break;

								case 6:
									printf("Sera redirigido al menu principal\n");
									break;
								}
							}else{

								printf("Supero la cantidad de reintentos, sera redirigido al menu principal\n");
								break;
							}
						}while(opcionCargarBinario != 6);
					}else{

						printf("Debera de guardar una archivo binario previamente\n");
					}
					break;

				case 10:
					if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

						if(controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones)
						&& controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores)){

							ultimoId = idAutoincremental()-1;

							if(controller_guardarIdAutoincremental("ID.csv", ultimoId)){

								flagGuardarArchivos = 1;
								flagCambios = 0;

								if(ll_clear(listaJugadores) == 0
								&& ll_clear(listaSelecciones) == 0){

								}

								printf("Se Guardaron todos los archivos correctamente\n"
								"Si desea volver a manipular datos, debera volver a cargar los archivos\n");
							}
						}
					}else{

						printf("No cargo ningun archivo Previamente, no hay nada que guardar\n");
					}
					break;
				case 11:
						if(flagGuardarArchivos == 1 && flagCambios == 0){

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

