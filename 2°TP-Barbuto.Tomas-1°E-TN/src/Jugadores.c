#include <stdio.h>
#include <stdlib.h>
#include "Confederaciones.h"
#include "Validaciones.h"
#include "Jugadores.h"



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

int idJugador() {

	static int idJugadores = 0;
	idJugadores++;

	return idJugadores;
}

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

void mostrarDato(eJugador arrayJugadores){

	printf("\nID Jugador: %d\n", arrayJugadores.id);
	printf("Nombre: %s\n", arrayJugadores.nombre);
	printf("Posicion: %s\n", arrayJugadores.posicion);
	printf("Numero de camiseta: %hd\n", arrayJugadores.numeroCamiseta);
	printf("ID Confederacion: %d\n", arrayJugadores.idConfederacion);
	printf("Salario: $%.2f\n", arrayJugadores.salario);
	printf("Anios de contrato: %hd\n", arrayJugadores.aniosContrato);
}


int darAltaJugador(eJugador arrayJugadores[], eConfederacion arrayConfederaciones[], int longitudJugadores, int longitudConfederaciones) {

	int retorno = 0;
	int indice;
	int confirmar;
	eJugador auxJugador;

	if (arrayJugadores != NULL && arrayConfederaciones != NULL && longitudJugadores > 0  && longitudConfederaciones > 0) {

		do{
			indice = buscarVacioJugadores(arrayJugadores, longitudJugadores);

			if(indice != -1){

				auxJugador.id = idJugador();

				getString(auxJugador.nombre, "\nIngrese Nombre: ",
						"\nSupero los caracteres aceptados\n", 50);

				getString(auxJugador.posicion, "\nIngrese Posicion: ",
						"\nSupero los caracteres aceptados\n", 50);

				getShort(&auxJugador.numeroCamiseta, "\nIngrese Numero de camiseta entre 1-30: ", "\nNo es posible ese numero\n", 1, 30);

				listarConfederaciones(arrayConfederaciones, longitudConfederaciones);

				getNumber(&auxJugador.idConfederacion, "\nSeleccione confederacion por ID: ", "\nID No valido\n", 100, 105);

				getFloatSinLimite(&auxJugador.salario, "\nIngrese Salario: $", "\nA ocurrido un error Inesperado\n");

				getShort(&auxJugador.aniosContrato, "\nIngrese los anion de contrato: ", "\nNo es posible tener tantos años de contrato\n",
						1, 5);

				auxJugador.isEmpty = 1;

			}
			mostrarDato(auxJugador);

			getNumber(&confirmar, "\nIngrese 1 si los datos ingresados son correctos o 0 si desea volver a cargar\n"
					"Opcion: ", "\nNo ingreso algo valido\n", 0, 1);

		}while(confirmar != 1);

		arrayJugadores[indice] = auxJugador;
		retorno = 1;
	}

	return retorno;
}

int validarExistenciaDeJugador(eJugador arrayJugadores[], int longitud, int id) {

	int retorno = -1;

	if (arrayJugadores != NULL && longitud > 0 && id > 0) {

		for (int i = 0; i < longitud; i++) {

			if (arrayJugadores[i].id == id) {

				retorno = i; //ya encontre el id, break.
				break;
			}
		}
	}

	return retorno;
}

int listarJugadores(eJugador arrayJugadores[], int longitud) {

	int retorno = 0;

	if (arrayJugadores != NULL && longitud > 0) {

		printf("Los Transportes actuales son: \n");

		for (int i = 0; i < longitud; i++) {

			if (arrayJugadores[i].isEmpty == 1) {

				mostrarDato(arrayJugadores[i]);
			}
		}
		retorno = 1;
	}

	return retorno;
}

int darBajaJugador(eJugador arrayJugadores[], int longitud) {

	int retorno = -1;
	int id;
	int indice;
	int confirmar;

	if (arrayJugadores != NULL && longitud > 0) {

		listarJugadores(arrayJugadores, longitud);

		do{
			getNumber(&id, "Que id quiere dar de baja?\nNumero: ", "Numero no valido\nReingrese El ID", 1, 3000);

			indice = validarExistenciaDeJugador(arrayJugadores, longitud, id);

			if (indice != -1) {

				arrayJugadores[indice].isEmpty = 0;

				mostrarDato(arrayJugadores[indice]);

				getNumber(&confirmar, "\nConfirme si desea dar de baja\n"

						"0-ELEGIR OTRO ID\n1- CONFIRMAR\nOPCION:", "\nNo es una opcion valida\n", 0,1);

			}

		}while(confirmar != 1);

		retorno = 0;
	}

	return retorno;
}

int modificarJugador(eJugador arrayJugadores[], int longitud) {

	int retorno = 0;
	int id;
	int indice;
	int opcion;

	if (arrayJugadores != NULL && longitud > 0) {

		listarJugadores(arrayJugadores, longitud);

		getNumber(&id, "Que id quiere dar de baja?\nNumero: ", "Numero no valido\nReingrese El ID", 1, 3000);

		indice = validarExistenciaDeJugador(arrayJugadores, longitud, id);

		if (indice == -1) {

			printf("No se encontro el ID seleccionado\n");
			system("pause");

		} else {

			//ENCAPSULAR TODO EN UN MENUMODIFICAR.
			getNumber(&opcion, "\n¿Que opcion desea modificar?\n"
					"1-Nombrea\n"
					"2-Posicion\n"
					"3-Numero de camiseta\n"
					"4-Confederacion\n"
					"5-Salario\n"
					"6-Anios de contrato\n"
					"7-Volver\n"
					"opcion: ", "Opcion no valida", 1, 7);

			switch (opcion) {

			case 1:

				break;

			case 2:

				break;

			case 3:
				break;

			case 4:
				break;

			case 5:
				break;

			case 6:
				break;

			case 7:
				break;

			}

		}
		retorno = 1;
	}

	return retorno;
}
