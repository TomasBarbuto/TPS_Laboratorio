/*
 * Validaciones.h
 *
 *  Created on: 18 sep. 2022
 *      Author: barbu
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_


void cargarCostos(float *pCostoUno, float *pAcumuladorUno, float *pCostoDos,
				float *pAcumuladorDos, float *pCostoTres, float *pAcumuladorTres);

int cargarJugador(int *posicionUno, int *posicionDos, int *posicionTres, int *posicionCuatro);

int cargarConfederacion(int *pContadorUno, int *pContadorDos, int *pContadorTres,
						int *pContadorCuatro, int *pContadorCinco, int *pContadorSeis, int *pCantidadTotal);

int getNumber(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo);

int getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo,
		float maximo);

#endif /* VALIDACIONES_H_ */


