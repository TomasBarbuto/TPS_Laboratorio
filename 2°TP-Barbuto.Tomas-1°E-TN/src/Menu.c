#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Confederaciones.h"
#include "Jugadores.h"
#include "Validaciones.h"

#define CANT_CONFEDERACIONES 6
#define CANT_JUGADORES 3000

int mostrarMenu(){

	int retorno = 0;
	int opcion;
	int confirmar;
	int cantidadJugadores = 0;
	eConfederacion arrayConfederaciones[CANT_CONFEDERACIONES];
	eJugador arrayJugadores[CANT_JUGADORES];

	if(iniciarConfederacion(arrayConfederaciones) && inicializarJugadores(arrayJugadores, CANT_JUGADORES)){
		printf("\t\t********* Se crearon las herramientas correspondientes para ejecutar el programa **********\n\n"
						"\t\t     _____________________________________________________________________________\n");
	}else{

		printf("\nOcurrio un error, llame al departamento de sistemas\n");

	}

	system("pause");

	do{

		getNumber(&opcion, "\n\tBienvenido al menu de la FIFA \n\n"
						"¿Que accion desea realizar?\n\n"
						"1-ALTA DE JUGADOR\n"
						"2-BAJA DE JUGADOR\n"
						"3-MODIFICACIÓN DE JUGADOR\n"
						"4-INFORMES\n"
						"5-SALIR\n"
						"\n\nIngrese una opcion: ", "Opcion no valida\n", 1, 5);

		switch(opcion){

		case 1:
			if(darAltaJugador(arrayJugadores, arrayConfederaciones, CANT_JUGADORES, CANT_CONFEDERACIONES)){

				cantidadJugadores++;
				printf("\nEl jugador se dio de ALTA correctamente!!\n");
			}else{

				printf("\nOcurrio un error, llame al departamento de sistemas\n");
			}

			system("pause");
			break;

		case 2:
			if(darBajaJugador(arrayJugadores, CANT_JUGADORES)){

				cantidadJugadores--;
				printf("\nEl jugador se dio de BAJA correctamente!!\n");
			}else{

				printf("\nOcurrio un error, llame al departamento de sistemas\n");
			}

			system("pause");
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:

			getNumber(&confirmar, "\nReingrese 5 si desea finalizar el programa o 6 para continuar\nOpcion: ",
					  "\nIngreso un valor no valido\n", 5, 6);

		}


	}while(opcion != 5 || confirmar != 5);

	printf("\nEl PROGRAMA A FINALIZADO");
	return retorno;
}

int menuModificar(){

	int retorno = 0;


	return retorno;
}
