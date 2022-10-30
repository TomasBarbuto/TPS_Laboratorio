#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Confederaciones.h"
#include "Jugadores.h"
#include "Informes.h"
#include "Validaciones.h"

/**
*\brief: Muestra el menu principal del programa
*\param: array de tipo eConfederacion, array de tipo eJugador, longitud de primer array, longitud de segundo array.
*\return: Retorna 1 si salio bien, retorna 0 si ocurrio algun error.
**/
int mostrarMenu(eConfederacion arrayConfederaciones[], eJugador arrayJugadores[],
		         int longitudConfederacion, int longitudJugadores){

	int retorno = 0;
	int opcion;
	int confirmar;
	int cantidadJugadores = 0;

	if(arrayConfederaciones != NULL && arrayJugadores != NULL && longitudConfederacion > 0 && longitudJugadores > 0){

		do{

		 if(getNumber(&opcion, "\n\tBienvenido al menu de la FIFA \n\n"
							"¿Que accion desea realizar?\n\n"
							"1-ALTA DE JUGADOR\n"
							"2-BAJA DE JUGADOR\n"
							"3-MODIFICACIÓN DE JUGADOR\n"
							"4-INFORMES\n"
							"5-SALIR\n"
							"\n\nIngrese una opcion: ", "Opcion no valida\n", 1, 5)){

				switch(opcion){

				case 1:
					if(cantidadJugadores < 3000){

						if(darAltaJugador(arrayJugadores, arrayConfederaciones,longitudJugadores,
								longitudConfederacion)){

							cantidadJugadores++;
							printf("\nEl jugador se dio de ALTA correctamente!!\n");
						}else{

							printf("\nOcurrio un error, llame al departamento de sistemas\n");
						}
					}else{

						printf("Ya no hay espacio para cargar mas jugadores\n");
					}
					system("pause");
					break;

				case 2:
					if(cantidadJugadores > 0){
						if(!darBajaJugador(arrayJugadores, longitudJugadores,arrayConfederaciones,longitudConfederacion)){

							cantidadJugadores--;
							printf("\nEl jugador se dio de BAJA correctamente!!\n");

						}else{

							printf("\nOcurrio un error, llame al departamento de sistemas\n");
						}

					}else{
						printf("Aun no hay jugadores cargados\n");
					}
					system("pause");
					break;

				case 3:
					if(cantidadJugadores > 0){

						if(modificarJugador(arrayJugadores, arrayConfederaciones, longitudJugadores,
								longitudConfederacion)){

							printf("La modificacion, concluyo con exito\n");

						}else{

							printf("Ocurrio un error, llame al departamento de sistemas\n");
						}

					}else{

						printf("Aun no hay jugadores cargados\n");

					}
					system("pause");
					break;

				case 4:
					if(cantidadJugadores > 0){

						if(!menuInformes(arrayJugadores, arrayConfederaciones, longitudJugadores,
						   longitudConfederacion)){

							printf("Ocurrio un error, llame al departamento de sistemas\n");
						}
					}else{
						printf("Aun no hay jugadores cargados\n");
					}
					system("pause");
					break;

				case 5:

					if(!getNumber(&confirmar, "\nReingrese 5 si desea finalizar el programa o 6 para continuar\nOpcion: ",
							  "\nIngreso un valor no valido\n", 5, 6)){

						printf("Ocurrio un error, llame al departamento de sistemas\n");
						break;
					}

				}
			}else{

				printf("Ocurrio un error, llame al departamento de sistemas\n");
				break;

			}
		}while(opcion != 5 || confirmar != 5);

		printf("\nEl PROGRAMA A FINALIZADO");
		retorno = 1;
	}

	return retorno;
}

/**
*\brief: Muestra el menu de informes para llevar a cabo el programa.
*\param: array de tipo eConfederacion, array de tipo eJugador, longitud de primer array, longitud de segundo array.
*\return: Retorna 1 si salio bien, retorna 0 si ocurrio algun error.
**/
int menuInformes(eJugador arrayJugadores[], eConfederacion arrayConfederaciones[], int longitudJugadores,
				int longitudConfederaciones){

	int retorno = 0;
	int opcion;


	if(arrayJugadores != NULL && arrayConfederaciones != NULL && longitudJugadores > 0 &&
			longitudConfederaciones > 0){

		do{
			if(getNumber(&opcion,
					"\n\t Bienvenido al menu de informes\n"
					"\n1-Listado de los jugadores ordenados por nombre de confederación y nombre de jugador."
					"\n2-Listado de confederaciones con sus jugadores."
					"\n3-Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio."
					"\n4-Informar la confederación con mayor cantidad de años de contratos total."
					"\n5.Informar porcentaje de jugadores por cada confederación."
					"\n6.Informar cual es la región con más jugadores y el listado de los mismos."
					"\n7-Salir", "\nError, solo puede ingresar del 1 al 5",1, 7)){

				switch (opcion){
				case 1:
					if(ordenarPorConfederacionyNombreJugador(arrayConfederaciones, arrayJugadores,
							longitudConfederaciones, longitudJugadores) &&
							listarJugadores(arrayJugadores, longitudJugadores,arrayConfederaciones,
									longitudConfederaciones)){

					}else{

						printf("Ocurrio un error, llame al departamento de sistemas\n");
					}
					system("pause");
					break;
				case 2:
					if(imprimirListadoDeJugadoresConSuConfederacion(arrayJugadores, longitudJugadores,
							arrayConfederaciones, longitudConfederaciones)){

					}else{
						printf("Ocurrio un error, llame al departamento de sistemas\n");
					}
					system("pause");

					break;
				case 3:
					if(totalYPromediosDeSalarios(arrayJugadores, longitudJugadores)){

					}else{

						printf("Ocurrio un error, llame al departamento de sistemas\n");
					}
					system("pause");
					break;
				case 4:
					if(confederacionConMayorAniosDeContratos(arrayJugadores, arrayConfederaciones,
							longitudConfederaciones, longitudJugadores)){

					}else{

						printf("Ocurrio un error, llame al departamento de sistemas\n");
					}
					system("pause");
					break;
				case 5:
					if(porcentajeDeJugadoresPorConfederacion(arrayJugadores, arrayConfederaciones,
							longitudJugadores)){

					}else{

						printf("Ocurrio un error, llame al departamento de sistemas\n");
					}
					system("pause");

					break;
				case 6:
					if(regionMasJugadores(arrayJugadores, arrayConfederaciones, longitudConfederaciones,
							longitudJugadores)){

					}else{

						printf("Ocurrio un error, llame al departamento de sistemas\n");
					}
					system("pause");

					break;

				case 7:
					printf("Sera redirigido al menu principal\n");
					break;
				}

			}else{

				printf("Ocurrio un error, llame al departamento de sistemas\n");
				break;
			}

		} while (opcion != 7);

		retorno = 1;
	}
	return retorno;
}

/**
*\brief: Muestra el menu para modificar un indice del arrayJugadores de tipo eJugador.
*\param: array de tipo eJugador, entero
*\return: Retorna 1 si salio bien, retorna 0 si ocurrio algun error.
**/

int menuModificarJugador(eJugador arrayJugadores[], int indice){

	int retorno = 0;
	int opcion;

	if(arrayJugadores != NULL && indice >= 0){


		do{

			if(getNumber(&opcion, "\n¿Que opcion desea modificar?\n"
								"1-Nombre\n"
								"2-Posicion\n"
								"3-Numero de camiseta\n"
								"4-Confederacion\n"
								"5-Salario\n"
								"6-Anios de contrato\n"
								"7-Volver\n"
								"opcion: ", "Opcion no valida", 1, 7)){


				switch (opcion) {

				case 1:
					if(!getString(arrayJugadores[indice].nombre, "\nIngrese un nuevo nombre(max 50): ",
							"Usted ingreso mas de 50 caracteres. REINTENTE\n", 50)){

						printf("Ocurrio un error, llame al departamento de sistemas\n");
						break;
					}
					break;

				case 2:
					if(!getString(arrayJugadores[indice].posicion, "\nIngrese la nueva Posicion: ",
						"\nSupero los caracteres aceptados\n", 50)){

						printf("Ocurrio un error, llame al departamento de sistemas\n");
						break;
					}
					break;

				case 3:
					if(!getShort(&arrayJugadores[indice].numeroCamiseta, "\nIngrese un nuevo numero de camiseta entre 1-30: ",
						"\nNo es posible ese numero\n", 1, 30)){

						printf("Ocurrio un error, llame al departamento de sistemas\n");
						break;
					}
					break;

				case 4:
					if(!getNumber(&arrayJugadores[indice].idConfederacion, "\nSeleccione nueva confederacion por ID: ",
							"\nID No valido\n", 100, 105)){

						printf("Ocurrio un error, llame al departamento de sistemas\n");
						break;
					}
					break;

				case 5:
					if(!getFloatSinLimite(&arrayJugadores[indice].salario, "\nIngrese nuevo Salario: $",
						"\nA ocurrido un error Inesperado\n")){

						printf("Ocurrio un error, llame al departamento de sistemas\n");
						break;
					}
					break;

				case 6:
					if(!getShort(&arrayJugadores[indice].aniosContrato, "\nIngrese los nuevos anios de contrato: ",
					   "\nNo es posible tener tantos años de contrato\n", 1, 5)){

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
				opcion = 7;
				break;

			}

			}while(opcion != 7);

		retorno = 1;
	}

	return retorno;
}

/**
*\brief: Muestra el menu para modificar un indice del arrayConfederaciones de tipo eConfederacion.
*\param: array de tipo eConfederacion, entero.
*\return: Retorna 1 si salio bien, retorna 0 si ocurrio algun error.
**/
int menuModificarConfederacion(eConfederacion arrayConfederaciones[], int indice){

	int retorno = 0;
	int opcion;

	do{

		if(getNumber(&opcion, "\n¿Que opcion desea modificar?\n"
							"1-Nombre\n"
							"2-Region\n"
							"3-Anio de creacion\n"
							"4-Volver\n"
							"opcion: ", "Opcion no valida", 1, 4)){

			switch (opcion) {

			case 1:
				getString(arrayConfederaciones[indice].nombre, "\nIngrese nuevo nombre(max 50): ",
						"Usted ingreso mas de 50 caracteres. REINTENTE\n", 50);
				break;

			case 2:
				getString(arrayConfederaciones[indice].region, "\nIngrese la nueva region: ",
						  "\nSupero los caracteres aceptados\n", 50);
				break;

			case 3:
				getNumber(&arrayConfederaciones[indice].anioCreacion, "\nIngrese nuevo anio de creacion: ",
						"\nAño No valido\n", 1916, 2022);
				break;

			case 4:
				break;
			}
			system("pause");


		}else{

			printf("Ocurrio un error, Sera redirigido\n");
			break;

		}

		retorno = 1;

	}while(opcion != 4);

	return retorno;
}


