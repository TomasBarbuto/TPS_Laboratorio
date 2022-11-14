/*
 * Validaciones.h
 *
 *  Created on: 18 sep. 2022
 *      Author: barbu
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int getNumber(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo);
int getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo,
		float maximo);
int getString(char *pResultado, char *mensaje, char *mensajeError, int EspacioChar);
int getShort(short *pResultado, char *mensaje, char *mensajeError, short minimo,short maximo);
int getFloatSinLimite(float *pResultado, char *mensaje, char *mensajeError);


#endif /* VALIDACIONES_H_ */
