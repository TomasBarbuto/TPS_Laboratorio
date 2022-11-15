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
    			if(ll_isEmpty(listaJugadores) == 0){
					if(controller_agregarJugador(listaJugadores)){

						printf("Se agrego un jugador correctamente\n");
					}
    			}else{

    				printf("Se debe cargar el archivo de jugadores antes de realizar un ALTA\n");
    			}
    			system("pause");
    			break;

    		case 3:
    			if(ll_isEmpty(listaJugadores) == 0){
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
    			if(ll_isEmpty(listaJugadores) == 0){

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
    			if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

    				if(!menuListar(listaJugadores, listaSelecciones)){

    					printf("ERROR al mostrar el menu\n");
    				}
    			}else{

    				printf("No hay nada para mostrar, debe cargar los archivos previamente\n");
    			}
    			system("pause");
    			break;

    		case 6:
    			if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

    				if(!menuConvocarJugadores(listaJugadores, listaSelecciones)){

    					printf("ERROR al mostrar el menu\n");
    				}
    			}else{

    				printf("No hay jugadores para convocar, debe cargar los archivos previamente\n");
    			}
    			system("pause");
    			break;

    		case 7:
    			if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

    				if(!menuOrdenarListar(listaJugadores, listaSelecciones)){

    					printf("ERROR al mostrar el menu\n");
    				}
    			}else{

    				printf("No hay datos para realizar ordenamientos\n");
    			}
    			system("pause");
    			break;

    		case 8:
    			if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

					if(!menuGuardarBinario(listaJugadores, listaSelecciones, &flagArchivosBinarios)){

						printf("ERROR al mostrar el menu\n");
					}

    			}else{

    				printf("Debe cargar los archivos previamente para poder generar un archivo binario\n");
    			}
    			system("pause");
    			break;

    		case 9:
    			if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0 && flagArchivosBinarios == 1){

    				if(!menuCargarBinario(listaJugadores, listaSelecciones)){

    					printf("ERROR al mostrar el menu\n");
    				}
    			}else{

    				printf("Debera de guardar una archivo binario previamente\n");
    			}
    			system("pause");
    			break;

    		case 10:
    			if(flagCargarArchivos == 1 && ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){

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
    			system("pause");
    			break;
    		case 11:
    			if(flagGuardarArchivos == 0){

    				getNumber(&opcion, "No se guardaron archivos\nSi desea salir confirme ingresando '11'"
    						"de lo contrario ingrese '12' para continuar en el programa\n",
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

    printf("PROGRAMA FINALIZADO\n");

    return 0;
}

