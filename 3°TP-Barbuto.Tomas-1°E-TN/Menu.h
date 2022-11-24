/*
 * Menu.h
 *
 *  Created on: 5 nov. 2022
 *      Author: barbu
 */

#ifndef MENU_H_
#define MENU_H_

void menuPrincipal();
void menuModificar();
void menuListados();
void menuConvocados();
void menuArchivoBinario();
void menuOrdenar();
void menuOrdenarJugadores();
void menuOrdenarSelecciones();
void elegirNacionalidad();
void elegirPosicion();
int menuOrdenarListar(LinkedList* listaJugadores, LinkedList* listaSelecciones);
int menuListar(LinkedList* listaJugadores, LinkedList* listaSelecciones);
int menuConvocarJugadores(LinkedList* listaJugadores, LinkedList* listaSelecciones);
int menuGuardarBinario(LinkedList* listaJugadores, LinkedList* listaSelecciones);
int menuCargarBinario(LinkedList* listaJugadores, LinkedList* listaSelecciones);

#endif /* MENU_H_ */
