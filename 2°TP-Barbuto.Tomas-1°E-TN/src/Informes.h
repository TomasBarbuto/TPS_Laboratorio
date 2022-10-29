/*
 * Informes.h
 *
 *  Created on: 24 oct. 2022
 *      Author: barbu
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int menuInformes(eJugador arrayJugadores[], eConfederacion arrayConfederaciones[], int longitudJugadores,
				int longitudConfederaciones);
int ordenarPorConfederacionyNombreJugador(eConfederacion arrayConfederaciones[], eJugador arrayJugadores[],
										  int longitudConfederaciones, int longitudJugadores);
int listadoJugadoresConSuConfederacion(eJugador unJugador, eConfederacion arrayConfederacion[],
							  	  	   int longitudConfederaciones);
int imprimirListadoDeJugadoresConSuConfederacion(eJugador arrayJugadores[], int longitudJugadores,
												eConfederacion arrayConfederaciones[], int longitudConfederaciones);
int totalYPromediosDeSalarios(eJugador arrayJugadores[], int longitudJugadores);
int confederacionConMayorAniosDeContratos(eJugador arrayJugadores[],eConfederacion arrayConfederaciones[],
										 int longitudConfederaciones, int longitudJugadores);
int porcentajeDeJugadoresPorConfederacion(eJugador arrayJugadores[],eConfederacion arrayConfederaciones[],
										  int longitudJugadores);
int regionMasJugadores(eJugador arrayJugadores[],eConfederacion arrayConfederaciones[], int longitudConfederacion,
					   int longitudJugadores);

#endif /* INFORMES_H_ */
