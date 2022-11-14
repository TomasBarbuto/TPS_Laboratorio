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
	int flagCargarArchivos = 0;
	int flagArchivosBinarios = 0;
	int flagGuardarArchivos = 0;
	int opcionListar;
	int opcionConvocar;
	int opcionGuardarBinario;
	int opcionCargarBinario;
	char confederacion[30];
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    do{
    		menuPrincipal();
    		if(!getNumber(&opcion, "\nOpcion: ","\nOpcion no valida, REINGRESE: ", 1, 11)){

    			printf("ERROR AL SELECCIONAR UNA OPCION\n");
    			system("pause");
    			break;
    		}

    		switch(opcion){

    		case 1:
    				if(controller_cargarJugadoresDesdeTexto("jugadores.csv", listaJugadores)
    				&& controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones)){

    					printf("Se cargaron los datos correctamente\n");

    				}else{

    					printf("ERROR al cargar los archivos\n");
    				}
    				flagCargarArchivos = 1;
    				system("pause");
    			break;

    		case 2:
    			if(flagCargarArchivos == 1 && ll_isEmpty(listaJugadores) == 0){
					if(controller_agregarJugador(listaJugadores)){

						printf("Se agrego un jugador correctamente\n");
					}
    			}else{

    				printf("Se debe cargar el archivo de jugadores antes de realizar un ALTA\n");
    			}
    			break;

    		case 3:
    			if(flagCargarArchivos == 1 && ll_isEmpty(listaJugadores) == 0){
					if(controller_editarJugador(listaJugadores)){

						printf("Se modifico un jugador correctamente\n");

					}else{

						printf("No ingreso un ID existente\nSera redirigido al menu principal\n\n");

					}
    			}else{

    				printf("Se debe cargar el archivo de jugadores antes de realizar una Modificacion\n");
    			}
    			system("pause");
    			break;

    		case 4:
    			if(flagCargarArchivos == 1 && ll_isEmpty(listaJugadores) == 0){
					if(controller_removerJugador(listaJugadores,listaSelecciones)){

						printf("Se elimino un jugador\n");
					}else{

						printf("ERROR al eliminar el Jugador, Reintente\n");
					}
    			}else{

    				printf("Se debe cargar el archivo de jugadores antes de remover un jugador\n");
    			}
    			system("pause");
    			break;

    		case 5:
    			if(flagCargarArchivos == 1 && ll_isEmpty(listaJugadores) == 0){
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
    			}else{

    				printf("No hay nada para mostrar, debe cargar los archivos previamente\n");
    			}
    			system("pause");
    			break;

    		case 6:
    			if(flagCargarArchivos == 1 && ll_isEmpty(listaJugadores) == 0){
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
							break;
						}
					}
    			}else{

    				printf("No hay jugadores para convocar, debe cargar los archivos previamente\n");
    			}
    			break;

    		case 7:
    			if(flagCargarArchivos == 1 && ll_isEmpty(listaJugadores) == 0){

    				if(menuOrdenarListar(listaJugadores, listaSelecciones)){

    				}
    			}else{

    				printf("No hay datos para realizar ordenamientos\n");
    			}

    			break;

    		case 8:
    			if(flagCargarArchivos == 1 && ll_isEmpty(listaJugadores) == 0){
					menuArchivoBinario();
					if(getNumber(&opcionGuardarBinario, "\nOpcion: ", "Opcion no valida\nREINGRESE: ", 1, 6)){

						switch(opcionGuardarBinario){

						case 1:
							strncpy(confederacion, "AFC", 30);
							if(controller_guardarJugadorPorConfederacionBinario("AFC.bin", listaJugadores,
																		listaSelecciones, confederacion)){
								printf("Se guardo el archivo correctamente\n");
								flagArchivosBinarios = 1;
							}
							break;

						case 2:
							strncpy(confederacion, "CAF", 30);
							controller_guardarJugadorPorConfederacionBinario("CAF.bin", listaJugadores,
																			listaSelecciones, confederacion);
							flagArchivosBinarios = 1;
							break;

						case 3:
							strncpy(confederacion, "CONCACAF", 30);
							controller_guardarJugadorPorConfederacionBinario("CONCACAF.bin", listaJugadores,
																			listaSelecciones, confederacion);
							flagArchivosBinarios = 1;
							break;

						case 4:
							strncpy(confederacion, "CONMEBOL", 30);
							controller_guardarJugadorPorConfederacionBinario("CONMEBOL.bin", listaJugadores,
																		listaSelecciones, confederacion);
							flagArchivosBinarios = 1;
							break;

						case 5:
							strncpy(confederacion, "UEFA", 30);
							controller_guardarJugadorPorConfederacionBinario("UEFA.bin", listaJugadores,
																			listaSelecciones, confederacion);
							flagArchivosBinarios = 1;
							break;

						case 6:
							break;
						}
					}
    			}else{

    				printf("Debe cargar los archivos previamente para poder generar un archivo binario\n");
    			}
    			break;

    		case 9:
    			if(flagArchivosBinarios == 1 && flagCargarArchivos == 1 && ll_isEmpty(listaJugadores) == 0){
					menuArchivoBinario();
					if(getNumber(&opcionCargarBinario, "\nOpcion: ", "Opcion no valida\nREINGRESE: ", 1, 6)){

						switch(opcionCargarBinario){

						case 1:
							strncpy(confederacion, "AFC", 30);
							controller_cargarJugadoresPorConfederacionBinario("AFC.bin", listaJugadores,
																		listaSelecciones, confederacion);
							break;

						case 2:
							strncpy(confederacion, "CAF", 30);
							controller_cargarJugadoresPorConfederacionBinario("CAF.bin", listaJugadores,
																			listaSelecciones, confederacion);
							break;

						case 3:
							strncpy(confederacion, "CONCACAF", 30);
							controller_cargarJugadoresPorConfederacionBinario("CONCACAF.bin", listaJugadores,
																			listaSelecciones, confederacion);
							break;

						case 4:
							strncpy(confederacion, "CONMEBOL", 30);
							controller_cargarJugadoresPorConfederacionBinario("CONMEBOL.bin", listaJugadores,
																		listaSelecciones, confederacion);
							break;

						case 5:
							strncpy(confederacion, "UEFA", 30);
							controller_cargarJugadoresPorConfederacionBinario("UEFA.bin", listaJugadores,
																			listaSelecciones, confederacion);
							break;

						case 6:
							break;
						}
					}
    			}else{

    				printf("Debera de guardar una archivo binario previamente\n");
    			}
    			break;

    		case 10:
    			if(flagCargarArchivos == 1 && ll_isEmpty(listaJugadores) == 0){
					if(controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones)
					&& controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores)){

						flagGuardarArchivos = 1;
						flagCargarArchivos = 0;
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
    			if(flagGuardarArchivos == 0){

    				getNumber(&opcion, "No se guardaron archivos\nSi desea salir confirme ingresando '11'"
    						"de lo contrario ingrese 12 para continuar en el programa\n",
    						"ERROR\nReingrese una opcion valida", 11, 12);

    			}else{

    				printf("Programa Finalizado, sus archivos se guardaron correctamente\n");
    			}
    			if(opcion == 11){

					ll_deleteLinkedList(listaJugadores);
					ll_deleteLinkedList(listaSelecciones);
				}
    			break;
    		}

    	}while(opcion != 11);

    return 0;
}

