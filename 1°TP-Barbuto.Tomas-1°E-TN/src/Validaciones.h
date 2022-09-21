/*
 * Validaciones.h
 *
 *  Created on: 18 sep. 2022
 *      Author: barbu
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

float calcularPromedio(float *pResultado, int multiplicador, int divisor);

void mostrarMenu(int *menu, float acumuladorHospedaje, float acumuladorComida, float acumuladorTransporte,
				int arqueros, int defensores, int mediocampistas, int delanteros);

void cargarCostos(float *costoHospedaje, float *acumuladorHospedaje, float *costoComida, float *acumuladorComida,
				float *costoTransporte, float *acumuladorTransporte);

int validarRango(int numero, int maximo, int minimo);

int cargarJugador(int *posicionUno, int *posicionDos, int *posicionTres, int *posicionCuatro);

void cargarConfederacion(int *uefa, int *conmebol, int *concacaf,int *afc, int *ofc, int *caf, int *totalJugadores);

void mostrarResultados(float *promedioUno, float *promedioDos, float *promedioTres, float *promedioCuatro,
						float *promedioCinco, float *promedioSeis, float *costoTotal, float *recargo, float *costoRecargo);

#endif /* VALIDACIONES_H_ */


