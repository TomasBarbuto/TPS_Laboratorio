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

	int retorno;
	FILE* pArchivo = NULL;

	if(path != NULL && pArrayListJugador != NULL){

		pArchivo = fopen(path,"r");

		if(pArchivo != NULL){

			if(parser_JugadorFromText(pArchivo, pArrayListJugador)){

				retorno = 1;
			}else{

				retorno = 0;
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

	int retorno;
	FILE* pArchivo = NULL;

	if(path != NULL && pArrayListJugador != NULL){

		pArchivo = fopen(path, "rb");

		if(pArchivo != NULL){

			if(parser_JugadorFromBinary(pArchivo, pArrayListJugador)){

				retorno = 1;

			}else{

				retorno = 0;
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

		if(getString(auxNombreCompleto,"\nIngrese Nombre: ", "\nError reingrese: ", 100) &&
		   getNumber(&auxEdad, "\nIngrese Edad: ", "\nError reingrese: ", 16, 45) &&
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
					}else{

						retorno = 0;
					}
				}
			 }else{

				 jug_delete(NuevoJugador);
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

			if(getNumber(&idBuscar, "\nSeleccione el ID: ", "\nError Reingrese el ID: ", 1,
					ll_len(pArrayListJugador))){

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
							if(getNumber(&opcion,"\nOpcion: ", "\nOpcion no valida\nReingrese: ", 1, 5)){

								switch(opcion){

								case 1:
									if(getString(nuevoNombre, "\nIngrese el nuevo nombre: ",
											"\nSupero la cantidad de caracteres maximos\nReingrese: ", 100)){

										if(!jug_setNombreCompleto(auxJugador, nuevoNombre)){

											printf("ERROR\n");
											retorno = 0;
											break;
										}
									}

									break;

								case 2:
									if(getNumber(&nuevaEdad, "\nIngrese la nueva edad: ",
											"\nSu edad debe ser mayor a 16 y menor a 40", 16, 40)){

										if(!jug_setEdad(auxJugador, nuevaEdad)){

											printf("ERROR\n");
											retorno = 0;
											break;
										}

									}
									break;
								case 3:
									if(jug_elegirPosicion(nuevaPosicion)){

										if(!jug_setPosicion(auxJugador, nuevaPosicion)){

											printf("ERROR\n");
											retorno = 0;
											break;
										}

									}
									break;
								case 4:
									if(jug_elegirNacionalidad(nuevaNacionalidad)){

										if(!jug_setNacionalidad(auxJugador, nuevaNacionalidad)){

											printf("ERROR\n");
											retorno = 0;
											break;
										}

									}
									break;

								case 5:
									printf("Salio del menu modificar\n");
									break;
								}
							}
						}while(opcion != 5);
					}
				}
			}
		}
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
	int idBuscar;
	int confirmar;
	int indiceSeleccion;
	int convocados;
	int idSeleccion;
	Jugador* auxJugador = NULL;
	Seleccion* auxSeleccion = NULL;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){

		if(controller_listarJugadores(pArrayListJugador)){

			if(getNumber(&idBuscar, "\nSeleccione el ID: ", "\nError Reingrese el ID: ", 1,
					ll_len(pArrayListJugador))){


				indice = validarExistenciaDeJugador(pArrayListJugador, idBuscar);

				if(indice != -1){

					auxJugador = (Jugador*) ll_get(pArrayListJugador, indice);

					if(imprimirJugador(pArrayListJugador, indice)&&
							getNumber(&confirmar, "Ingrese 1 para BORRAR o 0 para volver al menu principal\n",
									"\nOpcion no Valida\nReingrese: ", 0, 1) && auxJugador != NULL){

						if(confirmar == 1){

							if(jug_getIdSeleccion(auxJugador, &idSeleccion) && idSeleccion != 0){

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
							}

							jug_delete(auxJugador);

							if(ll_remove(pArrayListJugador, indice) == 0){

								retorno = 1;
							}
						}else{

							retorno = 1;
							printf("Sera redirigido al menu principal\n");
						}
					}
				}
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

			if(getNumber(&opcionOrdenamientoJugador,"\nOpcion: " ,
					"Error ingrese las opciones que se muestran en el menu\n", 1,4)){

				switch(opcionOrdenamientoJugador){

				case 1:
					if(getNumber(&orden, "Ingrese el orden que desea listar\n"
									  "1-Ascendente\n"
									  "0-Descendente\n"
									  "Opcion: ","ERROR, VALOR NO VALIDO\n", 0, 1)){

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
					if(getNumber(&orden, "Ingrese el orden que desea listar\n"
									  "1-Ascendente\n"
									  "0-Descendente\n"
									  "Opcion: ", "ERROR, VALOR NO VALIDO\n", 0, 1)){

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
					if(getNumber(&orden, "Ingrese el orden que desea listar\n"
									  "1-Ascendente\n"
									  "0-Descendente\n"
									  "Opcion: ", "ERROR, VALOR NO VALIDO\n", 0, 1)){

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

				printf("ERROR Menu no disponible\n");
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
	int longitud; //longitud de linkedList
	Jugador *auxJugador;
	//Campos de struct Jugador.
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

						//retorna numero de bytes escritos.
						retornoFprintf = fprintf(pArchivo, "%d,%s,%d,%s,%s,%d\n" , auxId, auxNombreCompleto, auxEdad, auxPosicion,
													auxNacionalidad, auxIdSeleccion);//Escribe el archivo.

						if(retornoFprintf == 7){

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

					//Retorna el número de elementos completos que escribe la función
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

			if(getNumber(&idSeleccion, "\nSeleccione el ID: ", "\nError Reingrese el ID: ", 1,
				ll_len(pArrayListSeleccion))){

				indice = validarExistenciaDeSeleccion(pArrayListSeleccion, idSeleccion);

				if(indice != -1){

					auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indice);

					if(auxSeleccion != NULL){

						do{
							printf("|%10s | %25s | %10s | %20s |\n", "ID", "CONFEDERACION", "CONVOCADOS", "PAIS");

							if(getNumber(&opcion,"\nOpcion: ", "\nOpcion no valida\nReingrese: ", 1, 5)
							&& imprimirSeleccion(pArrayListSeleccion, indice)){


								switch(opcion){

								case 1:
									if(!selec_setConvocados(auxSeleccion, convocados) &&
									!getNumber(&convocados, "\nIngrese nueva cantidad de convocados: ",
									"\nNo puede ser mayor a 22", 1, 22)){

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
	int opcionOrdenamientoJugador;

	if(pArrayListSeleccion != NULL){

		retorno = 1;

		do{

			menuOrdenarSelecciones();

			if(getNumber(&opcionOrdenamientoJugador,"\nOpcion: " ,
					"Error ingrese las opciones que se muestran en el menu\n", 1,2)){

				switch(opcionOrdenamientoJugador){

				case 1:
					if(getNumber(&orden, "Ingrese el orden que desea listar\n"
									  "1-Ascendente\n"
									  "0-Descendente\n"
									  "Opcion: ", "ERROR, VALOR NO VALIDO\n", 0, 1)){

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
		}while(opcionOrdenamientoJugador != 2);
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
	int longitud; //longitud de linkedList
	Seleccion *auxSelecion;
	//Campos de struct Jugador.
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

						if(retornoFprintf == 4){

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
	int buscarId;
	int indice;
	int indiceSeleccion;
	int convocados = 0;
	Jugador* auxJugador = NULL;
	Seleccion* auxSeleccion = NULL;

	if(pArrayListSeleccion != NULL && pArrayListJugador != NULL){

		if(controller_listarJugadoresNoConvocados(pArrayListJugador)){

			if(getNumber(&buscarId, "\nSeleccione el Jugador a convocar por su ID: ",
					"\nError Reingrese el ID: ", 1, ll_len(pArrayListJugador))){

				indice = validarExistenciaDeJugador(pArrayListJugador, buscarId);

				if(indice != -1){

					auxJugador = (Jugador*) ll_get(pArrayListJugador, indice);

					if(auxJugador != NULL){

						if(controller_listarSelecciones(pArrayListSeleccion)
						&& getNumber(&idSeleccion, "\nIngrese a que seleccion sera convocado: ",
									"\nNo existe una seleccion con ese ID\nReingrese: ", 1, 32)){

							indiceSeleccion = validarExistenciaDeSeleccion(pArrayListSeleccion, idSeleccion);

							auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indiceSeleccion);

							if(auxSeleccion != NULL){

								if(selec_getConvocados(auxSeleccion, &convocados)){

									if(jug_setIdSeleccion(auxJugador, idSeleccion)){

										convocados++;

										if(selec_setConvocados(auxSeleccion, convocados)){

											retorno = 1;

										}
									}
								}
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
			system("Pause");
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
int controller_cargarIdAutoincremental(char* path, char* auxid){

	FILE* pArchivo = NULL;
	int retornoFscanf;
	int retorno = 0;

	if(path != NULL && auxid != NULL){

		pArchivo = fopen(path, "r");

		if(pArchivo != NULL){

			retornoFscanf = fscanf(pArchivo, "%[^\n]\n", auxid);

			if(retornoFscanf == 1){

				retorno = 1;
			}else{

				printf("ERROR\n");
			}
		}
		fclose(pArchivo);
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

			if(retornoFprintf == sizeof(ultimoId)){

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
    int seleccion;
    int indiceSelecccion;
    int convocados;
    Jugador* auxJugador = NULL;
    Seleccion* auxSeleccion = NULL;

    if(pArrayListSeleccion != NULL  && pArrayListJugador != NULL){

		if(controller_ListarConvocados(pArrayListJugador, pArrayListSeleccion)
		&& getNumber(&idJugador, "\nIngrese ID del jugador para quitar de la seleccion",
				"\nError al ingresar ID", 1, ll_len(pArrayListJugador))){

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
		if(ll_clear(nuevaLista) && ll_deleteLinkedList(nuevaLista)){

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
			if(ll_clear(nuevaLista) && ll_deleteLinkedList(nuevaLista)){

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

