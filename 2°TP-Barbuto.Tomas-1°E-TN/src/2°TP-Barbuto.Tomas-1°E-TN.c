/*
 ============================================================================
 Name        : Tomas-1�E-TN.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Confederaciones.h"
#include "Jugadores.h"
#include "Menu.h"
#include "Validaciones.h"
#include "Informes.h"


#define CANT_CONFEDERACIONES 6
#define CANT_JUGADORES 3000
#define OK 1

int main(void) {
	setbuf(stdout, NULL);

	eConfederacion arrayConfederaciones[CANT_CONFEDERACIONES];
	eJugador arrayJugadores[CANT_JUGADORES];

	if(iniciarConfederacionHarcodeada(arrayConfederaciones) && inicializarJugadores(arrayJugadores, CANT_JUGADORES)){
		printf("\t\t********* Se crearon las herramientas correspondientes para ejecutar el programa **********\n\n"
						"\t\t     _____________________________________________________________________________\n");
	}else{

		printf("\nOcurrio un error, llame al departamento de sistemas\n");

	}

	int opcion;
	int opcionInformes;
	int confirmar;
	int cantidadJugadores = 0;


	do{

		mostrarMenuPrincipal();
		if(utn_getNumero(&opcion, "\n\nIngrese una opcion: ", "Opcion no valida\n", 1, 5, 5)){

			switch(opcion){

			case 1:
				if(cantidadJugadores < 3000){

					if(darAltaJugador(arrayJugadores, arrayConfederaciones, CANT_JUGADORES, CANT_CONFEDERACIONES)){

						cantidadJugadores++;
						printf("\nEl jugador se dio de ALTA correctamente!!\n");

					}else{

						printf("\nOcurrio un error, llame al departamento de sistemas\n");
					}
				}else{

					printf("Ya no hay espacio para cargar mas jugadores\n");
				}
				break;

			case 2:
				if(cantidadJugadores > 0){

					if(darBajaJugador(arrayJugadores, CANT_JUGADORES, arrayConfederaciones, CANT_CONFEDERACIONES)){

						cantidadJugadores--;
						printf("\nEl jugador se dio de BAJA correctamente!!\n");

					}else{

						printf("No se encontro el ID seleccionado\n");
					}

				}else{
					printf("Aun no hay jugadores cargados\n");
				}
				break;

			case 3:
				if(cantidadJugadores > 0){

					if(modificarJugador(arrayJugadores, arrayConfederaciones, CANT_JUGADORES, CANT_CONFEDERACIONES)){

						printf("La modificacion, concluyo con exito\n");

					}else{

						printf("No se encontro el ID seleccionado\n");
					}

				}else{

					printf("Aun no hay jugadores cargados\n");

				}
				break;

			case 4:
				if(cantidadJugadores > 0){

					do{

						mostrarMenuInformes();
						if(utn_getNumero(&opcionInformes, "\nOpcion: ",
								"\nError, solo puede ingresar del 1 al 5",1, 7, 5)){

							switch (opcionInformes){
							case 1:
								if(ordenarPorConfederacionyNombreJugador(arrayConfederaciones, arrayJugadores,
									CANT_CONFEDERACIONES, CANT_JUGADORES) &&
									listarJugadores(arrayJugadores, CANT_JUGADORES, arrayConfederaciones,
									CANT_CONFEDERACIONES)){

								}else{

									printf("Ocurrio un error, llame al departamento de sistemas\n");
								}
								break;
							case 2:
								if(jugadoresPorConfederacion(arrayJugadores, arrayConfederaciones,
										CANT_CONFEDERACIONES, CANT_JUGADORES)){

								}else{
									printf("Ocurrio un error, llame al departamento de sistemas\n");
								}

								break;
							case 3:
								if(totalYPromediosDeSalarios(arrayJugadores, CANT_JUGADORES)){

								}else{

									printf("Ocurrio un error, llame al departamento de sistemas\n");
								}
								break;
							case 4:
								if(confederacionConMayorAniosDeContratos(arrayJugadores, arrayConfederaciones,
										CANT_CONFEDERACIONES, CANT_JUGADORES)){

								}else{

									printf("Ocurrio un error, llame al departamento de sistemas\n");
								}

								break;
							case 5:
								if(porcentajeDeJugadoresPorConfederacion(arrayJugadores, arrayConfederaciones,
										CANT_JUGADORES)){

								}else{

									printf("Ocurrio un error, llame al departamento de sistemas\n");
								}

								break;
							case 6:
								if(regionMasJugadores(arrayJugadores, arrayConfederaciones, CANT_CONFEDERACIONES,
										CANT_JUGADORES)){

								}else{

									printf("Ocurrio un error, llame al departamento de sistemas\n");
								}

								break;

							case 7:
								printf("Sera redirigido al menu principal\n");
								break;
							}
						}else{

							printf("Ocurrio un error, llame al departamento de sistemas\n");
							break;
						}

					}while(opcionInformes != 7);

				}else{

					printf("Aun no hay jugadores cargados\n");
				}

				break;

			case 5:

				if(!utn_getNumero(&confirmar,
					"\nReingrese 5 si desea finalizar el programa o 6 para continuar\nOpcion: ",
					"\nIngreso un valor no valido\n", 5, 6, 5)){

					printf("Sera redirigido al menu, se acabaron los intentos...\n");
				}
			}
		}else{

			printf("Ocurrio un ERROR, utilice una opcion valida para ejecutar el programa correctamente!!\n");

		}

	}while(opcion != 5 || confirmar != 5);

	printf("\nEl PROGRAMA A FINALIZADO");

	return 0;
}



