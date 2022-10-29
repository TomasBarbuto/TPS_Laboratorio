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


#define CANT_CONFEDERACIONES 6
#define CANT_JUGADORES 3000

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

	system("pause");

	if(!mostrarMenu(arrayConfederaciones, arrayJugadores, CANT_CONFEDERACIONES, CANT_JUGADORES)){

		printf("\nOcurrio un error, llame al departamento de sistemas\n");
	}


	return 0;
}
