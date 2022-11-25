#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Validaciones.h"
#include "Menu.h"
#include "Controller.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_cargarJugadoresDesdeTexto(char* path, LinkedList* pArrayListJugador){

	int retorno = 0;
	FILE* pArchivo = NULL;

	if(path != NULL && pArrayListJugador != NULL){

		pArchivo = fopen(path,"r");

		if(pArchivo != NULL){

			if(parser_JugadorFromText(pArchivo, pArrayListJugador)){

				retorno = 1;
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador){

	int retorno = 0;
	FILE* pArchivo = NULL;

	if(path != NULL && pArrayListJugador != NULL){

		pArchivo = fopen(path, "rb");

		if(pArchivo != NULL){

			if(parser_JugadorFromBinary(pArchivo, pArrayListJugador)){

				retorno = 1;
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}

/** \brief Alta de jugadores
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_agregarJugador(LinkedList* pArrayListJugador){

	Jugador* NuevoJugador;
	int retorno = 0;
	int auxId;
	char auxNombreCompleto[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];
	int auxIdSeleccion = 0;

	if(pArrayListJugador != NULL){


		if(utn_getNombre(auxNombreCompleto, 100, "\nIngrese Nombre: ", "\nError reingrese...\n", 5) &&
		   utn_getNumero(&auxEdad, "\nIngrese Edad: ", "\nError reingrese...\n", 16, 45, 5) &&
		   jug_elegirNacionalidad(auxNacionalidad) &&
		   jug_elegirPosicion(auxPosicion)){

			 auxId = idAutoincremental();

			 NuevoJugador = jug_new();

			 if(NuevoJugador != NULL){

				if(jug_setId(NuevoJugador, auxId)
				&& jug_setNombreCompleto(NuevoJugador, auxNombreCompleto)
				&& jug_setEdad(NuevoJugador, auxEdad)
				&& jug_setPosicion(NuevoJugador, auxPosicion)
				&& jug_setNacionalidad(NuevoJugador, auxNacionalidad)
				&& jug_setIdSeleccion(NuevoJugador, auxIdSeleccion)){


					if(ll_add(pArrayListJugador, NuevoJugador) == 0){

						retorno = 1;
					}
				}
			 }else{

				 jug_delete(NuevoJugador);
				 retorno = 0;
			 }
		}
	}
	return retorno;
}


/** \brief Modificar datos del jugador
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_editarJugador(LinkedList* pArrayListJugador){

	int retorno = 0;
	int idBuscar;
	int indiceMaximo;
	int contador = 0;
	int indice;
	int opcion;
	char nuevoNombre[100];
	char nuevaPosicion[30];
	char nuevaNacionalidad[30];
	int nuevaEdad;
	Jugador* auxJugador = NULL;

	if(pArrayListJugador != NULL){

		retorno = 1;
		if(controller_listarJugadores(pArrayListJugador)){

			indiceMaximo = buscarIdMaximo(pArrayListJugador);// con esto saco el id maximo generado que sera el ultimo cargado.

			if(utn_getNumero(&idBuscar, "\nSeleccione el ID: ", "\nError Reingrese el ID: ", 1,
					indiceMaximo, 5)){

				indice = validarExistenciaDeJugador(pArrayListJugador, idBuscar);

				if(indice != -1){

					auxJugador = (Jugador*) ll_get(pArrayListJugador, indice);

					if(auxJugador != NULL){

						do{
							printf("|%10s | %25s | %10s | %20s | %15s  |\n", "ID", "NOMBRE JUGADOR", "EDAD",
																				   "POSICION", "NACIONALIDAD");
							if(!imprimirJugador(pArrayListJugador, indice)){

								retorno = 0;
								break;
							}
							menuModificar();
							if(utn_getNumero(&opcion,"\nOpcion: ", "\nOpcion no valida\nReingrese: ", 1, 5, 5)){

								switch(opcion){

								case 1:
									if(utn_getNombre(nuevoNombre, 100, "\nIngrese el nuevo nombre: ",
											"\nSupero la cantidad de caracteres maximos\nReingrese...\n", 5)){

										if(!jug_setNombreCompleto(auxJugador, nuevoNombre)){

											printf("ERROR\n");
											retorno = 0;
											break;
										}
										contador++;
									}
									break;

								case 2:
									if(utn_getNumero(&nuevaEdad, "\nIngrese la nueva edad: ",
											"\nSu edad debe ser mayor a 16 y menor a 40", 16, 40, 5)){

										if(!jug_setEdad(auxJugador, nuevaEdad)){

											printf("ERROR\n");
											retorno = 0;
											break;
										}
										contador++;
									}
									break;
								case 3:
									if(jug_elegirPosicion(nuevaPosicion)){

										if(!jug_setPosicion(auxJugador, nuevaPosicion)){

											printf("ERROR\n");
											retorno = 0;
											break;
										}
										contador++;
									}
									break;
								case 4:
									if(jug_elegirNacionalidad(nuevaNacionalidad)){

										if(!jug_setNacionalidad(auxJugador, nuevaNacionalidad)){

											printf("ERROR\n");
											retorno = 0;
											break;
										}
										contador++;
									}
									break;

								case 5:
									printf("Salio del menu modificar\n");
									break;
								}
							}else{

								printf("Se acabaron los reintentos, sera redirigido al menu principal\n");
								break;
							}
						}while(opcion != 5);
					}
				}
			}
		}
	}
	if(contador == 0){

		retorno = 0;
	}
    return retorno;
}

/** \brief Baja del jugador
*
* \param path char*
* \param pArrayListJugador LinkedList* pArrayLisSeleccion LinkedList*
* \return int
*
*/
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){

	int retorno = 0;
	int indice;
	int indiceMaximo;
	int idBuscar;
	int confirmar;
	int indiceSeleccion;
	int convocados;
	int idSeleccion;
	Jugador* auxJugador = NULL;
	Seleccion* auxSeleccion = NULL;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){

		if(controller_listarJugadores(pArrayListJugador)){

			indiceMaximo = buscarIdMaximo(pArrayListJugador);

			if(utn_getNumero(&idBuscar, "\nSeleccione el ID: ", "\nError Reingrese el ID: ", 1,
					indiceMaximo, 5)){

				indice = validarExistenciaDeJugador(pArrayListJugador, idBuscar);

				if(indice != -1){

					auxJugador = (Jugador*) ll_get(pArrayListJugador, indice);

					if(imprimirJugador(pArrayListJugador, indice) && auxJugador != NULL){


						if(jug_getIdSeleccion(auxJugador, &idSeleccion) && idSeleccion != 0){

							printf("El jugador que esta por borrar esta convocado a una selecccion\n");

							if(utn_getNumero(&confirmar, "Ingrese 1 para BORRAR o 0 para volver al menu principal\n",
								"\nOpcion no Valida\nReingrese..\n", 0, 1, 3)){

								if(confirmar == 1){

									indiceSeleccion = validarExistenciaDeSeleccion(pArrayListSeleccion, idSeleccion);

									if(indiceSeleccion != -1){

										auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indiceSeleccion);

										if(auxSeleccion != NULL){

											if(selec_getConvocados(auxSeleccion, &convocados)){

												convocados--;

												if(selec_setConvocados(auxSeleccion, convocados)){

												}
											}
										}
									}

								}else{

									retorno = 0;
									printf("Sera redirigido al menu principal\n");
								}
							}
						}
						if(ll_remove(pArrayListJugador, indice) == 0){

							jug_delete(auxJugador);
							retorno = 1;
						}
					}
				}else{

					retorno = 0;
					printf("No existe tal ID\nSera redirigido al menu principal\n");
				}
			}else{
				 retorno = 0;
			}
		}
	}
	return retorno;
}

/** \brief Listar jugadores
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_listarJugadores(LinkedList* pArrayListJugador){

	int retorno = 0;
	Jugador* Jugadores = NULL;

	if(pArrayListJugador != NULL){
		retorno = 1;

		printf("|%10s | %25s | %10s | %20s | %15s |\n", "ID", "NOMBRE JUGADOR", "EDAD",
															"POSICION", "NACIONALIDAD");

		for(int i = 0; i < ll_len(pArrayListJugador); i++){

			Jugadores = (Jugador*) ll_get(pArrayListJugador, i);

			if(Jugadores != NULL){

				if(!imprimirJugador(pArrayListJugador, i)){

					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/** \brief Ordenar jugadores
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_ordenarJugadores(LinkedList* pArrayListJugador){

	int retorno = 0;
	int orden;
	int opcionOrdenamientoJugador;

	if(pArrayListJugador != NULL){

		retorno = 1;

		do{

			menuOrdenarJugadores();

			if(utn_getNumero(&opcionOrdenamientoJugador,"\nOpcion: " ,
					"Error ingrese las opciones que se muestran en el menu\n", 1, 4, 5)){

				switch(opcionOrdenamientoJugador){

				case 1:
					if(utn_getNumero(&orden, "Ingrese el orden que desea listar\n"
									  "1-Ascendente\n"
									  "0-Descendente\n"
									  "Opcion: ","ERROR, VALOR NO VALIDO\n", 0, 1, 3)){

						if(!ll_sort(pArrayListJugador, jug_ordenarPorNacionalidad, orden)){

							if(!controller_listarJugadores(pArrayListJugador)){

								printf("ERROR al listar jugadores\n");
							}
						}else{

							printf("\nERROR al Ordenar\n");
							retorno = 0;
							break;
						}
					}else{

						retorno = 0;
						printf("ERROR, sera redirigido al menu principal\n");
						break;
					}
					break;

				case 2:
					if(utn_getNumero(&orden, "Ingrese el orden que desea listar\n"
									  "1-Ascendente\n"
									  "0-Descendente\n"
									  "Opcion: ", "ERROR, VALOR NO VALIDO\n", 0, 1, 3)){

						if(!ll_sort(pArrayListJugador, jug_ordenarPorNombre, orden)){

							if(!controller_listarJugadores(pArrayListJugador)){

								printf("ERROR al listar jugadores\n");
							}

						}else{

							printf("\nERROR al Ordenar\n");
							retorno = 0;
							break;
						}
					}else{
						retorno = 0;
						printf("ERROR, sera redirigido al menu principal\n");
						break;
					}
					break;

				case 3:
					if(utn_getNumero(&orden, "Ingrese el orden que desea listar\n"
									  "1-Ascendente\n"
									  "0-Descendente\n"
									  "Opcion: ", "ERROR, VALOR NO VALIDO\n", 0, 1, 3)){

						if(!ll_sort(pArrayListJugador, jug_ordenarPorEdad, orden)){

							if(!controller_listarJugadores(pArrayListJugador)){

								printf("ERROR al listar jugadores\n");

							}

						}else{
							printf("\nERROR al Ordenar\n");
							retorno = 0;
							break;
						}
					}else{
						retorno = 0;
						printf("ERROR, sera redirigido al menu principal\n");
						break;
					}
					break;

				case 4:
					printf("Seras redirigido al menu anterior\n");
					break;
				}

			}else{

				printf("Se acabaron los reintentos, sera redirigido al menu principal\n");
				retorno = 0;
				break;
			}
		}while(opcionOrdenamientoJugador != 4);
	}
    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
*
* \param path char*
* \param pArrayListSeleccion LinkedList*
* \return int
*
*/
int controller_guardarJugadoresModoTexto(char* path, LinkedList* pArrayListJugador){

	int retorno = 0;
	FILE* pArchivo;
	int longitud;
	Jugador *auxJugador;
	int auxId;
	char auxNombreCompleto[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];
	int auxIdSeleccion;
	int retornoFprintf;

	if(path != NULL && pArrayListJugador != NULL){

		pArchivo = fopen(path, "w");

		if(pArchivo != NULL){

			longitud = ll_len(pArrayListJugador);
			fprintf(pArchivo, "id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");

			for(int i = 0; i < longitud ; i++){

				auxJugador = ll_get(pArrayListJugador, i);

				if(auxJugador != NULL){

					if(jug_getId(auxJugador, &auxId)
					&& jug_getNombreCompleto(auxJugador, auxNombreCompleto)
					&& jug_getEdad(auxJugador, &auxEdad)
					&& jug_getPosicion(auxJugador, auxPosicion)
					&& jug_getNacionalidad(auxJugador, auxNacionalidad)
					&& jug_getIdSeleccion(auxJugador, &auxIdSeleccion)){

						retornoFprintf = fprintf(pArchivo, "%d,%s,%d,%s,%s,%d\n" , auxId, auxNombreCompleto, auxEdad, auxPosicion,
													auxNacionalidad, auxIdSeleccion);

						if(retornoFprintf > 0){

							retorno = 1;
						}
					}
				}
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
*
* \param path char*
* \param pArrayListJugador LinkedList*
* \return int
*
*/
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador){

	int retorno = 0;
	FILE* pArchivo;
	Jugador* auxJugador;
	int retornoFwrite;

	if(path != NULL && pArrayListJugador != NULL){

		pArchivo = fopen(path, "wb");

		if(pArchivo != NULL){

			for(int i = 0; i < ll_len(pArrayListJugador) ; i++){

				auxJugador = (Jugador*) ll_get(pArrayListJugador, i);

				if(auxJugador != NULL){

					retornoFwrite = fwrite(auxJugador, sizeof(Jugador), 1, pArchivo);

					if(retornoFwrite == 1){

						retorno = 1;

					}else{

						break;
					}
				}
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
*
* \param path char*
* \param pArrayListSeleccion LinkedList*
* \return int
*
*/
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion){

	int retorno;
	FILE* pArchivo;

	if(path != NULL && pArrayListSeleccion != NULL){

		pArchivo = fopen(path,"r");

		if(pArchivo != NULL){

			if(parser_SeleccionFromText(pArchivo, pArrayListSeleccion)){

				retorno = 1;

			}else{

				retorno = 0;
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}


/** \brief Modificar datos de empleado
*
* \param path char*
* \param pArrayListSeleccion LinkedList*
* \return int
*
*/
int controller_editarSeleccion(LinkedList* pArrayListSeleccion){

	int retorno = 0;
	int convocados;
	int idSeleccion;
	int indice;
	int opcion;
	Seleccion* auxSeleccion;

	if(pArrayListSeleccion != NULL){
		retorno = 1;

		if(controller_listarSelecciones(pArrayListSeleccion)){

			if(utn_getNumero(&idSeleccion, "\nSeleccione el ID: ", "\nError Reingrese el ID: ", 1,
				32, 5)){

				indice = validarExistenciaDeSeleccion(pArrayListSeleccion, idSeleccion);

				if(indice != -1){

					auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indice);

					if(auxSeleccion != NULL){

						do{
							printf("|%10s | %25s | %10s | %20s |\n", "ID", "CONFEDERACION", "CONVOCADOS", "PAIS");

							if(utn_getNumero(&opcion,"\nOpcion: ", "\nOpcion no valida\nReingrese..\n", 1, 2, 5)
							&& imprimirSeleccion(pArrayListSeleccion, indice)){


								switch(opcion){

								case 1:
									if(!selec_setConvocados(auxSeleccion, convocados) &&
									!utn_getNumero(&convocados, "\nIngrese nueva cantidad de convocados: ",
									"\nNo puede ser mayor a 22", 1, 22, 5)){

										printf("ERROR\n");
										retorno = 0;
										break;
									}
									break;

								case 2:
									printf("Salio del menu modificar\n");
									break;
								}
							}else{

								retorno = 0;
								break;
							}

						}while(opcion != 2);
					}
				}
			}
		}
	}
    return retorno;
}


/** \brief Listar selecciones
*
* \param path char*
* \param pArrayListSeleccion LinkedList*
* \return int
*
*/
int controller_listarSelecciones(LinkedList* pArrayListSeleccion){

	int retorno = 0;
	Seleccion* selecciones = NULL;

	if(pArrayListSeleccion != NULL){

		retorno = 1;

		printf("|%10s | %25s | %10s | %20s |\n", "ID", "CONFEDERACION", "CONVOCADOS", "PAIS");
		for(int i = 0; i < ll_len(pArrayListSeleccion); i++){

			selecciones = (Seleccion*) ll_get(pArrayListSeleccion, i);

			if(selecciones != NULL){

				if(!imprimirSeleccion(pArrayListSeleccion, i)){

					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/** \brief Ordenar selecciones
*
* \param path char*
* \param pArrayListSeleccion LinkedList*
* \return int
*
*/
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion){

	int retorno = 0;
	int orden;
	int opcionOrdenamientoSeleccion;

	if(pArrayListSeleccion != NULL){

		retorno = 1;

		do{

			menuOrdenarSelecciones();

			if(utn_getNumero(&opcionOrdenamientoSeleccion,"\nOpcion: " ,
					"Error ingrese las opciones que se muestran en el menu\n", 1,2, 5)){

				switch(opcionOrdenamientoSeleccion){

				case 1:
					if(utn_getNumero(&orden, "Ingrese el orden que desea listar\n"
									  "1-Ascendente\n"
									  "0-Descendente\n"
									  "Opcion: ", "ERROR, VALOR NO VALIDO\n", 0, 1, 3)){

						if(!ll_sort(pArrayListSeleccion, selec_ordenarPorConfederacion, orden)){

							if(!controller_listarSelecciones(pArrayListSeleccion)){

								printf("ERROR al listar las selecciones\n");
							}

						}else{
							retorno = 0;
							printf("\nERROR al Ordenar\n");
						}
					}else{

						printf("ERROR, sera redirigido al menu principal\n");
					}

					break;
				case 2:
					printf("Seras redirigido al menu anterior\n");
					break;
				}
			}
		}while(opcionOrdenamientoSeleccion != 2);
	}
    return retorno;
}

/**
* \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
* \param path char*
* \param pArrayListSeleccion LinkedList*
* \return int
**/
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion){

	int retorno = 0;
	FILE* pArchivo;
	int longitud;
	Seleccion *auxSelecion;
	int auxId;
	char auxPais[30];
	char auxConfederacion[30];
	int auxConvocados;
	int retornoFprintf;

	if(path != NULL && pArrayListSeleccion != NULL){

		pArchivo = fopen(path, "w");

		if(pArchivo != NULL){

			longitud = ll_len(pArrayListSeleccion);
			fprintf(pArchivo,"id,pais,confederacion,convocados\n");

			for(int i = 0; i < longitud ; i++){

				auxSelecion = (Seleccion*) ll_get(pArrayListSeleccion, i);

				if(auxSelecion != NULL){

					if(selec_getId(auxSelecion, &auxId)
					&& selec_getPais(auxSelecion, auxPais)
					&& selec_getConfederacion(auxSelecion, auxConfederacion)
					&& selec_getConvocados(auxSelecion, &auxConvocados)){

						//retorna numero de bytes escritos.
						retornoFprintf = fprintf(pArchivo, "%d,%s,%s,%d,\n" , auxId, auxPais, auxConfederacion,
													auxConvocados);//Escribe el archivo.

						if(retornoFprintf > 0){

							retorno = 1;
						}
					}
				}
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}

/**
* \brief Convoca jugadores a la seleccion que elija el usuario.
* \param pArrayListSeleccion LinkedList*
* \param pArrayListJugador LinkedList*
* \return int
**/
int controller_ConvocarJugadores(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador){

	int retorno = 0;
	int idSeleccion;
	int idJugadorSeleccion;
	int buscarId;
	int indiceMaximo;
	int indice;
	int indiceSeleccion;
	int convocados = 0;
	Jugador* auxJugador = NULL;
	Seleccion* auxSeleccion = NULL;

	if(pArrayListSeleccion != NULL && pArrayListJugador != NULL){

		if(controller_listarJugadoresNoConvocados(pArrayListJugador)){

			indiceMaximo = buscarIdMaximo(pArrayListJugador);

			if(utn_getNumero(&buscarId, "\nSeleccione el Jugador a convocar por su ID: ",
					"\nError Reingrese el ID: ", 1, indiceMaximo, 3)){

				indice = validarExistenciaDeJugador(pArrayListJugador, buscarId);

				if(indice != -1){

					auxJugador = (Jugador*) ll_get(pArrayListJugador, indice);

					if(jug_getIdSeleccion(auxJugador, &idJugadorSeleccion)){

						if(auxJugador != NULL && idJugadorSeleccion == 0){

							if(controller_listarSelecciones(pArrayListSeleccion)
							&& utn_getNumero(&idSeleccion, "\nIngrese a que seleccion sera convocado: ",
										"\nNo existe una seleccion con ese ID\nReingrese...\n", 1, 32, 3)){

								indiceSeleccion = validarExistenciaDeSeleccion(pArrayListSeleccion, idSeleccion);

								auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indiceSeleccion);

								if(auxSeleccion != NULL){

									if(selec_getConvocados(auxSeleccion, &convocados)){

										if(convocados < 22){

											if(jug_setIdSeleccion(auxJugador, idSeleccion)){

												convocados++;

												if(selec_setConvocados(auxSeleccion, convocados)){

													retorno = 1;

												}
											}
										}else{

											printf("La seleccion elegida, llego a la capacidad maxima de convocados\n");
										}
									}
								}
							}
						}else{

							printf("El jugador ya fue convocado previamente\n");
						}
					}
				}
			}
		}
	}
	return retorno;
}

/**
* \brief Lista los jugadores que esten convocados a una seleccion.
* \param pArrayListJugador LinkedList*
* \param pArrayListSeleccion LinkedList*
* \return int
**/
int controller_ListarConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){

	int retorno = 0;
	Jugador* Jugadores = NULL;
	int convocado;
	int contador = 0;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		retorno = 1;

		printf("|%10s | %25s | %10s | %20s | %15s | %20s |\n", "ID", "NOMBRE JUGADOR", "EDAD",
																"POSICION", "NACIONALIDAD", "SELECCION");

		for(int i = 0; i < ll_len(pArrayListJugador); i++){

			Jugadores = (Jugador*)ll_get(pArrayListJugador, i);

			if(Jugadores != NULL){

				if(jug_getIdSeleccion(Jugadores, &convocado) && convocado != 0){
					contador++;
					if(!imprimirJugadorSeleccion(pArrayListJugador, pArrayListSeleccion, i)){

							retorno = 0;
							break;
					}
				}
			}
		}
		if(contador == 0){

			printf("NO HAY JUGADORES CONVOCADOS HASTA EL MOMENTO\n");
		}
	}

	return retorno;
}

/**
* \brief carga los datos del ultimo id generado en el archivo ID.csv (modo texto).
* \param path char*
* \param auxId char*
* \return int
**/
int controller_cargarIdAutoincremental(char* path, char* auxiliarID){

    int retorno = 0;
    FILE* pArchivo = NULL;

    pArchivo = fopen(path,"r");

    if(pArchivo != NULL){

        if(parser_ArchivoIdFromText(pArchivo, auxiliarID)){

            retorno = 1;
        }
    }
    return retorno;
}

/**
* \brief Guarda los datos del ultimo id en el archivo ID.csv (modo texto).
* \param path char*
* \param ultimoId int
* \return int
**/
int controller_guardarIdAutoincremental(char* path, int ultimoId){

	FILE* pArchivo = NULL;
	int retornoFprintf;
	int retorno = 0;

	if(path != NULL){

		pArchivo = fopen(path, "w");

		if (pArchivo != NULL){

			retornoFprintf = fprintf(pArchivo, "%d\n", ultimoId);

			if(retornoFprintf > 0){

				retorno = 1;
			}
		}
		fclose(pArchivo);
	}

	return retorno;
}

/**
* \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
* \param pArrayListJugador LinkedList*
* \param pArrayListSeleccion LinkedList*
* \return int
**/
int controller_removerJugadorDeSeleccion(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador){

    int retorno = 0;
    int idJugador;
    int indiceJugador;
    int indiceMaximo;
    int seleccion;
    int indiceSelecccion;
    int convocados;
    Jugador* auxJugador = NULL;
    Seleccion* auxSeleccion = NULL;

    if(pArrayListSeleccion != NULL  && pArrayListJugador != NULL){

    	indiceMaximo = buscarIdMaximo(pArrayListJugador);

		if(controller_ListarConvocados(pArrayListJugador, pArrayListSeleccion)
		&& utn_getNumero(&idJugador, "\nIngrese ID del jugador para quitar de la seleccion",
				"\nError al ingresar ID\n", 1, indiceMaximo, 5)){

			indiceJugador = validarExistenciaDeJugador(pArrayListJugador, idJugador);

			if(indiceJugador != -1){

				auxJugador = (Jugador*) ll_get(pArrayListJugador, indiceJugador);

				if(auxJugador != NULL && jug_getIdSeleccion(auxJugador, &seleccion)){

					indiceSelecccion = validarExistenciaDeSeleccion(pArrayListSeleccion, seleccion);

					auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indiceSelecccion);

					if(auxSeleccion != NULL && jug_setIdSeleccion(auxJugador, 0)){

						if(selec_getConvocados(auxSeleccion, &convocados)){

							convocados--;

							if(selec_setConvocados(auxSeleccion, convocados)){

								retorno = 1;
							}
						}
					}
				}
			}
		}
    }
    return retorno;
}

/**
* \brief Lista los jugadores con su respectiva seleccion en vez del id de la misma.
* \param pArrayListJugador LinkedList*
* \param pArrayListSeleccion LinkedList*
* \return int
**/
int controller_listarJugadoresConSeleccion(LinkedList* pArrayListJugador, LinkedList* pArraylistSeleccion){

	int retorno = 0;
	Jugador* Jugadores = NULL;

	if(pArrayListJugador != NULL && pArraylistSeleccion != NULL){

		retorno = 1;
		printf("|%10s | %25s | %10s | %20s | %15s | %20s |\n", "ID", "NOMBRE JUGADOR", "EDAD",
															"POSICION", "NACIONALIDAD", "SELECCION");

		for(int i = 0; i < ll_len(pArrayListJugador); i++){

			Jugadores = (Jugador*) ll_get(pArrayListJugador, i);

			if(Jugadores != NULL){

				if(!imprimirJugadorSeleccion(pArrayListJugador, pArraylistSeleccion, i)){

					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}


/**
* \brief Guarda los datos de los jugadores convocados por confederacion en un archivo .bin
* \param path char* , pArrayListJugador LinkedList*
* \param pArrayListSeleccion LinkedList*,  char Confederacion[]
* \return int
**/

int controller_guardarJugadorPorConfederacionBinario(char *path, LinkedList* pArrayListJugador,
											  LinkedList* pArrayListSeleccion, char Confederacion[]){

	int retorno = 0;
	int auxIdSelecciondeJugador;
	char auxConfederacion[30];
	Jugador* auxJugador = NULL;
	LinkedList* nuevaLista = ll_newLinkedList();

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL && Confederacion != NULL){

		for (int i = 0; i < ll_len(pArrayListJugador); i++){

			auxJugador = (Jugador*) ll_get(pArrayListJugador, i);

			if(jug_getIdSeleccion(auxJugador, &auxIdSelecciondeJugador)){

				if(auxIdSelecciondeJugador > 0
				&& buscarNombreDeConfederacion(pArrayListSeleccion, auxIdSelecciondeJugador, auxConfederacion)){

					if (strncmp(auxConfederacion, Confederacion, 30) == 0){

						if(ll_add(nuevaLista, auxJugador) == 0
						&& controller_guardarJugadoresModoBinario(path, nuevaLista)){

							retorno = 1;
						}
					}
				}
			}
		}
		if(ll_clear(nuevaLista) != 0 && ll_deleteLinkedList(nuevaLista) != 0){

			retorno = 0;
		}
	}
	return retorno;
}

/**
* \brief carga los datos de los jugadores convocados por confederacion en un archivo .bin
* \param path char* , pArrayListJugador LinkedList*
* \param pArrayListSeleccion LinkedList*,  char Confederacion[]
* \return int
**/
int controller_cargarJugadoresPorConfederacionBinario(char *path, LinkedList* pArrayListJugador,
											LinkedList* pArrayListSeleccion, char Confederacion[]){
	int retorno = 0;
	int auxIdJugador;
	char auxConfederacion[30];
	int contador = 0;
	LinkedList* nuevaLista = ll_newLinkedList();
	Jugador* auxJugador;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL && Confederacion != NULL){

		if (controller_cargarJugadoresDesdeBinario(path, pArrayListJugador)){

			for (int i = 0; i < ll_len(pArrayListJugador); i++){

				auxJugador = (Jugador*) ll_get(pArrayListJugador, i);

				if(jug_getIdSeleccion(auxJugador, &auxIdJugador)){

					if (auxIdJugador > 0
					&& buscarNombreDeConfederacion(pArrayListSeleccion, auxIdJugador, auxConfederacion)){

						if (strncmp(auxConfederacion, Confederacion, 30) == 0){

							if(ll_add(nuevaLista, auxJugador)==0){

								contador++;
								retorno = 1;
							}
						}
					}
				}
			}
			if(contador > 0){

				if(!controller_listarJugadoresConSeleccion(nuevaLista, pArrayListSeleccion)){

					retorno = 0;
					printf("ERROR al listar jugadores\n");
				}
			}
			if(ll_clear(nuevaLista) != 0 && ll_deleteLinkedList(nuevaLista) != 0){

				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Crea una lista de jugadores ingresados, mostrando si fueron o no convocados.
 * \param pArrayListJugador LinkedList*
 * \return int, 1 bien, 0 ERROR.
**/
int controller_listarJugadoresNoConvocados(LinkedList* pArrayListJugador){

	int retorno = 0;
	Jugador* auxJugador = NULL;
	int idSeleccion;

	if(pArrayListJugador != NULL){

		retorno = 1;
		for(int i = 0; i < ll_len(pArrayListJugador); i++){

			auxJugador = (Jugador*) ll_get(pArrayListJugador, i);

			if(auxJugador != NULL){

				if(jug_getIdSeleccion(auxJugador, &idSeleccion) && idSeleccion == 0){

					if(!imprimirJugador(pArrayListJugador, i)){

						printf("ERROR al imprimir un jugador\n");
						retorno = 0;
						break;
					}
				}
			}
		}
	}
	return retorno;
}

int buscarIdMaximo(LinkedList* pArrayListJugador){

	int retorno = 0;
	int idMayor;
	int auxId;
	int flag = 0;
	int retornoId;
	Jugador* auxJugador;

	if(pArrayListJugador != NULL){

		for(int i = 0; i < ll_len(pArrayListJugador); i++){

			auxJugador = ll_get(pArrayListJugador, i);

			if(auxJugador != NULL){

				if(jug_getId(auxJugador, &auxId)){

					retorno = 1;

					if(flag == 0){

						idMayor = auxId;
						flag = 1;

					}else if(idMayor < auxId){

						idMayor = auxId;
					}
				}
			}
		}
	}
	if(retorno == 1){

		retornoId = idMayor;
	}

	return retornoId;
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
