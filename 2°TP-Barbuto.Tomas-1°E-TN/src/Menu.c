#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"


/**
*\brief: Despliega un menu con opciones.
*\param: void
*\return: void
**/
void mostrarMenuPrincipal(){

	printf("\n\tBienvenido al menu de la FIFA \n\n"
			"¿Que accion desea realizar?\n\n"
			"1-ALTA DE JUGADOR\n"
			"2-BAJA DE JUGADOR\n"
			"3-MODIFICACIÓN DE JUGADOR\n"
			"4-INFORMES\n"
			"5-SALIR\n");
}

/**
*\brief: Despliega un menu con opciones.
*\param: void
*\return: void
**/
void mostrarPosiciones(){

	printf("Seleccione la posicion del nuevo jugador\n"
		   "1-Arquero\n"
		   "2-Defensor\n"
		   "3-Mediocentro\n"
		   "4-Delantero\n");
}

/**
*\brief: Despliega un menu con opciones.
*\param: void
*\return: void
**/
void mostrarMenuModificarJugador(){

	printf("\n¿Que opcion desea modificar?\n"
			"1-Nombre\n"
			"2-Posicion\n"
			"3-Numero de camiseta\n"
			"4-Confederacion\n"
			"5-Salario\n"
			"6-Anios de contrato\n"
			"7-Volver\n");

}

/**
*\brief: Despliega un menu con opciones.
*\param: void
*\return: void
**/
void mostrarMenuInformes(){

	printf("\n\t Bienvenido al menu de informes\n"
		   "\n1-Listado de los jugadores ordenados por nombre de confederación y nombre de jugador."
		   "\n2-Listado de confederaciones con sus jugadores."
		   "\n3-Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio."
		   "\n4-Informar la confederación con mayor cantidad de años de contratos total."
		   "\n5.Informar porcentaje de jugadores por cada confederación."
		   "\n6.Informar cual es la región con más jugadores y el listado de los mismos."
		   "\n7-Salir");
}

/**
*\brief: Despliega un menu con opciones.
*\param: void
*\return: void
**/
void mostrarMenuModificarConfederacion(){

	printf("\n¿Que opcion desea modificar?\n"
		   "1-Nombre\n"
		   "2-Region\n"
		   "3-Anio de creacion\n"
		   "4-Volver\n");
}


