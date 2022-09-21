/*
 * Validaciones.h
 *
 *  Created on: 18 sep. 2022
 *      Author: barbu
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

float calcularPromedio(float *pResultado, int multiplicador, int divisor);

void mostrarMenu(int *menu, float acumuladorUno, float acumuladorDos, float acumuladorTres,
				int posicionUno, int posicionDos, int posicionTres, int posicionCuatro);

void cargarCostos(float *pCostoUno, float *pAcumuladorUno, float *pCostoDos,
				float *pAcumuladorDos, float *pCostoTres, float *pAcumuladorTres);

int validarRango(int numero, int maximo, int minimo);

int cargarJugador(int *posicionUno, int *posicionDos, int *posicionTres, int *posicionCuatro);

void cargarConfederacion(int *pContadorUno, int *pContadorDos, int *pContadorTres,
						int *pContadorCuatro, int *pContadorCinco, int *pContadorSeis, int *pCantidadTotal);

void mostrarResultados(float *promedioUno, float *promedioDos, float *promedioTres, float *promedioCuatro,
						float *promedioCinco, float *promedioSeis, float *costoTotal, float *recargo, float *costoRecargo);

#endif /* VALIDACIONES_H_ */


