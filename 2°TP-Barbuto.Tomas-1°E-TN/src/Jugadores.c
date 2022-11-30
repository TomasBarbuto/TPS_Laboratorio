#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Confederaciones.h"
#include "Jugadores.h"
#include "Validaciones.h"
#include "Menu.h"

/**
*\brief: Inicia el campo isempty del array de tipo eJugador en 0.
*\param: Array de tipo eJugador, longitud del Array.
*\return: Retorna 1 si funciono y 0 si ocurre algun error.
**/
int inicializarJugadores(eJugador arrayJugadores[], int longitud) {

	int retorno = 0;

	if (arrayJugadores != NULL && longitud > 0) {

		for (int i = 0; i < longitud; i++) {

			arrayJugadores[i].isEmpty = 0; // 0.VACIO 1.LLENO
		}
		retorno = 1;
	}
	return retorno;
}

/**
*\brief: Otorga un ID autoincremental.
*\param: ---
*\return: retorna el id autoincrementado.
**/
int idJugador() {

	static int idJugadores = 0;
	idJugadores++;

	return idJugadores;
}

/**
*\brief: Recorre un array de tipo eJugador buscando algun espacio vacio. (isempty = 0)
*\param: Array de tipo eJugador, longitud del array.
*\return: Retorna el indice vacio  y -1 si no encontro.
**/
int buscarVacioJugadores(eJugador arrayJugadores[], int longitud) {

	int retorno = -1;

	if (arrayJugadores != NULL && longitud > 0) {

		for (int i = 0; i < longitud; i++) {

			if (arrayJugadores[i].isEmpty == 0) {

				retorno = i; //ya encontre vacio, break.
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief: Retorna un grafico con los datos de un jugador.
*\param: array de tipo eJugador, array de tipo eConfederacion, longitud del segundo array,
*\return: return: retorna 1 si pudo mostrar, 0 si ocurrio algun error.
**/
int mostrarDatoJugador(eJugador arrayJugadores, eConfederacion arrayConfederacion[], int longitudConfederacion){

	char nombreConfederacion[50];
	int retorno = 0;

	if(arrayConfederacion != NULL && longitudConfederacion > 0){

		if(!buscarNombreDeConfederacion(arrayConfederacion, longitudConfederacion, arrayJugadores.idConfederacion,
				nombreConfederacion)){

			printf("Ocurrio un ERROR\n");
		}

		printf("| %5d | %25s | %15s | %10d | %11.2f| %13s | %16d |\n",arrayJugadores.id,
				arrayJugadores.nombre,arrayJugadores.posicion,arrayJugadores.numeroCamiseta,
				arrayJugadores.salario, nombreConfederacion,arrayJugadores.aniosContrato);

		retorno = 1;

	}
	return retorno;
}

/**
*\brief: Carga datos en el array de tipo eJugador.
*\param: Array de tipo eJugador, longitud del array.
*\return: Retorna 1 si cargo correctamente y 0 si no.
**/
int darAltaJugador(eJugador arrayJugadores[], eConfederacion arrayConfederaciones[], int longitudJugadores,
		           int longitudConfederaciones) {

	int retorno = 0;
	int indice;
	eJugador auxJugador;

	if (arrayJugadores != NULL && arrayConfederaciones != NULL && longitudJugadores > 0  && longitudConfederaciones > 0) {

		indice = buscarVacioJugadores(arrayJugadores, longitudJugadores);

		if(indice != -1){

			if(utn_getNombre(auxJugador.nombre, 50, "\nIngrese Nombre: ",
					"\nSupero los caracteres aceptados o no ingreso algo valido...\n", 5) &&
				seleccionarPosicion(auxJugador.posicion) &&
				utn_getNumeroShort(&auxJugador.numeroCamiseta, "\nIngrese Numero de camiseta entre 1-30: ",
					   "\nNo es posible ese numero\n", 1, 30, 5) &&
			   listarConfederaciones(arrayConfederaciones, longitudConfederaciones) &&
			   utn_getNumero(&auxJugador.idConfederacion, "\nSeleccione confederacion por ID: ",
					   "\nID No valido\n", 100, 105, 5) &&
			   utn_getNumeroFlotante(&auxJugador.salario, "\nIngrese Salario:($1000 - $1000000) $",
					   "No es posible que un jugador posea ese salario\n", 1000, 1000000, 5)&&
				utn_getNumeroShort(&auxJugador.aniosContrato, "\nIngrese los anios de contrato: ",
					  "\nNo es posible tener tantos años de contrato\n",
					1, 5, 5)){

				auxJugador.isEmpty = 1;
				auxJugador.id = idJugador();

				printf("| %5s | %25s | %15s | %5s | %10s | %12s | %15s |\n", "ID", "NOMBRE JUGADOR", "POSICION",
												"N°CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS DE CONTRATO");
				if(mostrarDatoJugador(auxJugador, arrayConfederaciones, longitudConfederaciones)){

					arrayJugadores[indice] = auxJugador;
					retorno = 1;
				}

			}else{

				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
*\brief: Busca una coincidencia entre id y el array eJugador.
*\param: Array de tipo eJugador, logitudn de tipo int, id de tipo int
*\return: retorna la posicion donde encontro la coincidencia, si no encuentra retorna -1.
**/
int validarExistenciaDeJugador(eJugador arrayJugadores[], int longitud, int id) {

	int retorno = -1;

	if (arrayJugadores != NULL && longitud > 0 && id > 0) {

		for (int i = 0; i < longitud; i++) {

			if (arrayJugadores[i].id == id && arrayJugadores[i].isEmpty == 1) {

				retorno = i; //ya encontre el id, break.
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief: Muestra una lista del array de tipo eJugador que esten activos.
*\param: Array de tipo eJugador, array de tipo eConfederacion, Longitud del primer array, longitud del segundo array.
*\return: Retorna 1 si pudo recorrer bien el array, Retorna 0 si hubo algun error.
**/
int listarJugadores(eJugador arrayJugadores[], int longitudJugadores, eConfederacion arrayConfederaciones[], int longitudConfederaciones){

	int retorno = 0;

	if (arrayJugadores != NULL && longitudJugadores > 0) {

		printf("| %5s | %25s | %15s | %5s | %10s | %12s | %15s |\n", "ID", "NOMBRE JUGADOR", "POSICION",
											"N°CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS DE CONTRATO");

		for (int i = 0; i < longitudJugadores; i++) {

			if (arrayJugadores[i].isEmpty == 1) {

				mostrarDatoJugador(arrayJugadores[i], arrayConfederaciones, longitudConfederaciones);
			}
		}
		retorno = 1;
	}

	return retorno;
}

/**
*\brief: Otorga la baja a un indice del array de tipo eJugador.
*\param: Array de tipo eJugador, array de tipo eConfederacion, Longitud del primer array, longitud del segundo array.
*\return: Retorna 0 si fue exitoso, Retorna -1 si ocurrio un error.
**/
int darBajaJugador(eJugador arrayJugadores[], int longitudJugadores, eConfederacion arrayConfederaciones[],
					int longitudConfederaciones) {

	int retorno;
	int id;
	int indice;

	if (arrayJugadores != NULL && longitudJugadores > 0) {

		retorno = 1;

		if(!listarJugadores(arrayJugadores, longitudJugadores, arrayConfederaciones ,longitudConfederaciones)){

			retorno = 0;
			printf("ERROR al listar jugadores\n");
		}


		if(utn_getNumero(&id, "Que id quiere dar de baja?\nNumero: ", "Numero no valido\nReingrese...\n",
				1, 3000, 5)){

			indice = validarExistenciaDeJugador(arrayJugadores, longitudJugadores, id);

			if (indice == -1) {

				retorno = 0;

			}else{

				arrayJugadores[indice].isEmpty = 0;

				printf("| %5s | %25s | %15s | %15s | %15s | %20s | %15s |\n", "ID", "NOMBRE JUGADOR", "POSICION",
													"N°CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS DE CONTRATO");
				mostrarDatoJugador(arrayJugadores[indice], arrayConfederaciones, longitudConfederaciones);

			}
		}else{

			retorno = 0;

		}
	}
	return retorno;
}

/**
*\brief: Modifica valores de una variable de tipo eJugador seleccionada.
*\param: Array de tipo eJugador, array de tipo eConfederacion, Longitud del primer array, longitud del segundo array.
*\return: Retorna 1 si se pudo modificar, Retorna 0 si no se logro.
**/
int modificarJugador(eJugador arrayJugadores[], eConfederacion arrayConfederaciones[], int longitudJugadores,
					 int longitudConfederaciones) {

	int retorno = 0;
	int id;
	int indice;
	int opcion;

	if (arrayJugadores != NULL && longitudJugadores > 0) {

		retorno = 1;

		if(!listarJugadores(arrayJugadores, longitudJugadores, arrayConfederaciones, longitudConfederaciones)){

			printf("Ocurrio un error, llame al departamento de sistemas\n");
		}

		if(utn_getNumero(&id, "Que id quiere modificar?\nNumero: ", "Numero no valido\nReingrese El ID",
							1, 3000, 5)){

			indice = validarExistenciaDeJugador(arrayJugadores, longitudJugadores, id);


			if (indice == -1) {

				retorno = 0;

			}else{

				do{

					mostrarMenuModificarJugador();
					if(utn_getNumero(&opcion,"\nOpcion: ", "Opcion no valida", 1, 7, 5)){

						printf("| %5s | %25s | %15s | %5s | %10s | %12s | %15s |\n", "ID", "NOMBRE JUGADOR", "POSICION",
															"N°CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS DE CONTRATO");

						mostrarDatoJugador(arrayJugadores[indice], arrayConfederaciones, longitudConfederaciones);
						switch (opcion) {

						case 1:
							if(!utn_getNombre(arrayJugadores[indice].nombre,50, "\nIngrese un nuevo nombre(max 50): ",
									"Usted ingreso mas de 50 caracteres. REINTENTE\n", 5)){

								retorno = 0;
								break;
							}
							break;

						case 2:
							if(!seleccionarPosicion(arrayJugadores[indice].posicion)){


								retorno = 0;
								break;
							}
							break;

						case 3:
							if(!utn_getNumeroShort(&arrayJugadores[indice].numeroCamiseta, "\nIngrese un nuevo numero de camiseta entre 1-30: ",
								"\nNo es posible ese numero\n", 1, 30, 5)){

								retorno = 0;
								break;
							}
							break;

						case 4:
							if(!utn_getNumero(&arrayJugadores[indice].idConfederacion,
									"\nSeleccione nueva confederacion por ID: ", "\nID No valido\n", 100, 105, 5)){

								retorno = 0;
								break;
							}
							break;

						case 5:
							if(!utn_getNumeroFlotante(&arrayJugadores[indice].salario,
								"\nIngrese nuevo Salario:(1000 - 1000000) $", "\nA ocurrido un error Inesperado\n",
								1000,1000000,5)){

								printf("Ocurrio un error, llame al departamento de sistemas\n");
								break;
							}
							break;

						case 6:
							if(!utn_getNumeroShort(&arrayJugadores[indice].aniosContrato,
								"\nIngrese los nuevos anios de contrato: ",
							   "\nNo es posible tener tantos años de contrato\n", 1, 5, 5)){

								printf("Ocurrio un error, llame al departamento de sistemas\n");
								break;
							}
							break;

						case 7:
							printf("Usted ha vuelto al menu principal\n");
							break;

						}
					}else{

						printf("\nOcurrio un ERROR, Sera redirigido\n");
						break;
					}

				}while(opcion != 7);
			}
		}else{

			retorno = 0;
		}
	}
	return retorno;
}


/**
*\brief: Despliega opciones a elegir para la posicion del jugador.
*\param: puntero a char.
*\return: Retorna 1 para bien , Retorna 0 si no se logro.
**/
int seleccionarPosicion(char pPosicionElegida[]){


	int retorno = 0;
	int opcion;

	if(pPosicionElegida != NULL){

		mostrarPosiciones();
		if(utn_getNumero(&opcion, "Opcion: ", "\nERROR opcion no validar\nReingrese\n", 1, 4, 5)){

			switch(opcion){

			case 1:
				strncpy(pPosicionElegida, "Arquero",  50);
				break;

			case 2:
				strncpy(pPosicionElegida, "Defensor",  50);
				break;

			case 3:
				strncpy(pPosicionElegida, "Mediocentro", 50);
				break;

			case 4:
				strncpy(pPosicionElegida, "Delantero", 50);
				break;

			}
			retorno = 1;
		}
	}
	return retorno;
}

/**
*\brief: filtra jugadores por confederacion.
*\param: array de tipo eJugador, int longitudArray, array de tipo eConfederacion, int logitudArray, int coincidencia
*\return: Retorna 1 para bien , Retorna 0 si no se logro.
**/
int listarJugadoresPorRegion(eJugador arrayJugadores[], int longitudJugadores, eConfederacion arrayConfederaciones[],
					int longitudConfederacion, int idConfederacion){

	int retorno = 0;

	if (arrayJugadores != NULL && longitudJugadores > 0) {

		retorno = 1;

		printf("| %5s | %25s | %15s | %5s | %10s | %12s | %15s |\n", "ID", "NOMBRE JUGADOR", "POSICION",
											"N°CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS DE CONTRATO");
		for(int i = 0; i < longitudJugadores; i++){

			if(arrayJugadores[i].isEmpty == 1 && arrayJugadores[i].idConfederacion == idConfederacion){

				if(!mostrarDatoJugador(arrayJugadores[i], arrayConfederaciones, longitudConfederacion)){

					retorno = 0;
					break;
				}
			}
		}
		retorno = 1;
	}
	return retorno;
}
