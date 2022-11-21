/*
 * Jugadores.h
 *
 *  Created on: 17 oct. 2022
 *      Author: barbu
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_

typedef struct{

	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;

}eJugador;

int inicializarJugadores(eJugador Jugadores[], int longitud);
int idJugador();
int buscarVacioJugadores(eJugador Jugadores[], int longitud);
int mostrarDatoJugador(eJugador arrayJugadores, eConfederacion arrayConfederacion[], int longitudConfederacion);
int darAltaJugador(eJugador arrayJugadores[], eConfederacion arrayConfederaciones[], int longitudJugadores,
					int longitudConfederaciones);
int validarExistenciaDeJugador(eJugador arrayJugadores[], int longitud, int id);
int listarJugadores(eJugador arrayJugadores[], int longitudJugadores, eConfederacion arrayConfederaciones[],
					int longitudConfederaciones);
int darBajaJugador(eJugador arrayJugadores[], int longitudJugadores, eConfederacion arrayConfederaciones[],
					int longitudConfederaciones);
int modificarJugador(eJugador arrayJugadores[], eConfederacion arrayConfederaciones[], int longitudJugadores,
					 int longitudConfederaciones);
int seleccionarPosicion(char pPosicionElegida[]);
int listarJugadoresPorRegion(eJugador arrayJugadores[], int longitudJugadores, eConfederacion arrayConfederaciones[],
					int longitudConfederacion, int idConfederacion);
#endif /* JUGADORES_H_ */
