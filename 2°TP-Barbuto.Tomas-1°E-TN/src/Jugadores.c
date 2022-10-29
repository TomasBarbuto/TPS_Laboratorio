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

		printf("|%*d|%*s|%*s|%*d|%*.2f|%*s|%*d|\n", 4,arrayJugadores.id,10,
				arrayJugadores.nombre, 10, arrayJugadores.posicion, 10, arrayJugadores.numeroCamiseta, 10,
				arrayJugadores.salario, 10, nombreConfederacion,20, arrayJugadores.aniosContrato);

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
	int confirmar;
	eJugador auxJugador;

	if (arrayJugadores != NULL && arrayConfederaciones != NULL && longitudJugadores > 0  && longitudConfederaciones > 0) {

		do{

			indice = buscarVacioJugadores(arrayJugadores, longitudJugadores);

			if(indice != -1){

				auxJugador.id = idJugador();

				if(getString(auxJugador.nombre, "\nIngrese Nombre: ",
						"\nSupero los caracteres aceptados\n", 50) &&
				   getString(auxJugador.posicion, "\nIngrese Posicion: ",
						"\nSupero los caracteres aceptados\n", 50) &&
				   getShort(&auxJugador.numeroCamiseta, "\nIngrese Numero de camiseta entre 1-30: ",
						   "\nNo es posible ese numero\n", 1, 30) &&
				   listarConfederaciones(arrayConfederaciones, longitudConfederaciones) &&
				   getNumber(&auxJugador.idConfederacion, "\nSeleccione confederacion por ID: ",
						   "\nID No valido\n", 100, 105) &&
				   getFloatSinLimite(&auxJugador.salario, "\nIngrese Salario: $",
						   "\nA ocurrido un error Inesperado\n") &&
				   getShort(&auxJugador.aniosContrato, "\nIngrese los anios de contrato: ",
						  "\nNo es posible tener tantos años de contrato\n",
						1, 5)){

					auxJugador.isEmpty = 1;

				}else{

					printf("Ocurrio un error, llame al departamento de sistemas\n");
					break;
				}

			}
			printf("\n+----------------------------------------------------------------------------------+\n");
			printf("| %2s |%8s | %5s | %1s | %2s | %4s | %1s |\n","ID","NOMBRE","POSICION","N°CAMISETA","SUELDO","CONFEDERACION","AÑOS DE CONTRATO");
			printf("+----------------------------------------------------------------------------------+\n");
			mostrarDatoJugador(auxJugador,arrayConfederaciones,longitudConfederaciones);

			if(getNumber(&confirmar, "\nIngrese 1 si los datos ingresados son correctos o 0 si desea volver a cargar\n"
					"Opcion: ", "\nNo ingreso algo valido\n", 0, 1)){

				printf("Usted Confirmo los Datos Ingresados...\n");
			}

		}while(confirmar != 1);

		arrayJugadores[indice] = auxJugador;
		retorno = 1;
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

		printf("\n+----------------------------------------------------------------------------------+\n");
		printf("|%2s|%8s | %5s | %1s | %2s | %4s | %1s |\n","ID","NOMBRE","POSICION","N°CAMISETA","SUELDO","CONFEDERACION","AÑOS DE CONTRATO");
		printf("+----------------------------------------------------------------------------------+\n");
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

	int retorno = -1;
	int id;
	int indice;
	int confirmar;

	if (arrayJugadores != NULL && longitudJugadores > 0) {

		listarJugadores(arrayJugadores, longitudJugadores, arrayConfederaciones ,longitudConfederaciones);

		do{
			if(!getNumber(&id, "Que id quiere dar de baja?\nNumero: ", "Numero no valido\nReingrese El ID", 1, 3000)){

				printf("Ocurrio un error, llame al departamento de sistemas\n");
				break;

			}else{

				indice = validarExistenciaDeJugador(arrayJugadores, longitudJugadores, id);

			}
			if (indice != -1) {

				arrayJugadores[indice].isEmpty = 0;

				mostrarDatoJugador(arrayJugadores[indice],arrayConfederaciones,longitudConfederaciones);

				if(!getNumber(&confirmar, "\nConfirme si desea dar de baja\n"
						"0-ELEGIR OTRO ID\n1- CONFIRMAR\nOPCION:", "\nNo es una opcion valida\n", 0,1)){

					printf("Ocurrio un error, llame al departamento de sistemas\n");
					break;
				}

			}

		}while(confirmar != 1);

		retorno = 0;
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

	if (arrayJugadores != NULL && longitudJugadores > 0) {


		if(!listarJugadores(arrayJugadores, longitudJugadores,arrayConfederaciones,longitudConfederaciones)){

			printf("Ocurrio un error, llame al departamento de sistemas\n");
		}

		if(getNumber(&id, "Que id quiere modificar?\nNumero: ", "Numero no valido\nReingrese El ID", 1, 3000)){

			indice = validarExistenciaDeJugador(arrayJugadores, longitudJugadores, id);

		}

		if (indice == -1) {

			printf("No se encontro el ID seleccionado\n");
			system("pause");

		}else{

			if(!menuModificarJugador(arrayJugadores, indice)){

				printf("Ocurrio un error, llame al departamento de sistemas\n");
			}
		}
		retorno = 1;
	}


	return retorno;
}
