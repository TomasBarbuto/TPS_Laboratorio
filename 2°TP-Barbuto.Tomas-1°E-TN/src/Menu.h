/*
 * Menu.h
 *
 *  Created on: 17 oct. 2022
 *      Author: barbu
 */

#ifndef MENU_H_
#define MENU_H_

int mostrarMenu(eConfederacion arrayConfederaciones[], eJugador arrayJugadores[], int longitudConfederacion,
				int longitudJugadores);

int menuInformes(eJugador arrayJugadores[], eConfederacion arrayConfederaciones[], int longitudJugadores,
				int longitudConfederaciones);

int menuModificarJugador(eJugador arrayJugadores[], int indice);

int menuModificarConfederacion(eConfederacion arrayConfederaciones[], int indice);
#endif /* MENU_H_ */
