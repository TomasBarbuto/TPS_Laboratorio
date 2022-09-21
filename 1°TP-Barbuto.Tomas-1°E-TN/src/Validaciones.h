/*
 * Validaciones.h
 *
 *  Created on: 18 sep. 2022
 *      Author: barbu
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

float calcularPromedio(int confederacion, int totalJugadores);
void mostrarMenu(int *menu, float acumuladorHospedaje, float acumuladorComida, float acumuladorTransporte, int arqueros, int defensores, int mediocampistas, int delanteros);
void cargarCostos(float *costoHospedaje, float *acumuladorHospedaje, float *costoComida, float *acumuladorComida, float *costoTransporte, float *acumuladorTransporte);
int validarRango(int numero, int maximo, int minimo);
int cargarJugador(int *numeroDeCamiseta, int *posicionJugador, int *arqueros, int *defensores, int *mediocampistas, int *delanteros);
void cargarConfederacion(int *uefa, int *conmebol, int *concacaf,int *afc, int *ofc, int *caf, int *totalJugadores);

#endif /* VALIDACIONES_H_ */


