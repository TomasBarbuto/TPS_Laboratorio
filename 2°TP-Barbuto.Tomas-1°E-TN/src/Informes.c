#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Confederaciones.h"
#include "Calculos.h"
#include "Jugadores.h"
#include "Informes.h"

/**
*\brief: Ordena un array de tipo eJugador por los campos de confederacion y por nombre en segunda instancia.
*\param: array de tipo eConfederacion, array de tipo eJugador, longitud del primer array, longitud del segundo array.
*\return: retorna 1 si lo logro, retorna 0 si ocurrio algun ERROR.
**/
int ordenarPorConfederacionyNombreJugador(eConfederacion arrayConfederaciones[], eJugador arrayJugadores[],
										  int longitudConfederaciones, int longitudJugadores){
    int banderaSwap;
    int retorno = 0;
    eJugador auxJugador;
    char nombreConfederacioni[50];
    char nombreConfederacionj[50];

    if (arrayConfederaciones != NULL && longitudConfederaciones > 0 && arrayJugadores != NULL && longitudJugadores > 0){

    	retorno = 1;
        do {

        	banderaSwap = 0;

            for( int i = 0; i < longitudJugadores -1 ; i++){

                for (int j = i + 1; j < longitudJugadores ; j++){

                    if(arrayJugadores[i].isEmpty == 1 && arrayJugadores[j].isEmpty == 1 &&
                       buscarNombreDeConfederacion(arrayConfederaciones, longitudConfederaciones,
                    		   arrayJugadores[i].idConfederacion, nombreConfederacioni) &&
                       buscarNombreDeConfederacion(arrayConfederaciones, longitudConfederaciones,
                    		   arrayJugadores[j].idConfederacion, nombreConfederacionj)){

                        if(strncmp(nombreConfederacioni, nombreConfederacionj, 50) > 0){

                        	banderaSwap = 1;
                            auxJugador = arrayJugadores[i];
                            arrayJugadores[i] = arrayJugadores[j];
                            arrayJugadores[j] = auxJugador;

                        }else if(strncmp(nombreConfederacioni, nombreConfederacionj, 50) == 0){

							if(stricmp(arrayJugadores[i].nombre, arrayJugadores[j].nombre) > 0){

								banderaSwap = 1;
								auxJugador = arrayJugadores[i];
								arrayJugadores[i] = arrayJugadores[j];
								arrayJugadores[j]= auxJugador;
							}
                        }
                    }
                }//fin for j
            }//fin for i
        }while(banderaSwap == 1);
    }
    return retorno;
}


/**
*\brief: calcula el salario total de todos los jugadores y verifica cuantos superan el promedio.
*\param: array de tipo eJugador, longitud del array.
*\return: retorna 1 si lo logro, retorna 0 si ocurrio algun error.
**/
int totalYPromediosDeSalarios(eJugador arrayJugadores[], int longitudJugadores){

	int retorno = 0;
	float acumuladorSalarios = 0;
	int contadorJugadores = 0;
	int jugadoresConSalarioMayorAlPromedio = 0;
	float promedio;

	if(arrayJugadores != NULL && longitudJugadores > 9){

		if(totalDeSalarios(arrayJugadores, longitudJugadores, &acumuladorSalarios, &contadorJugadores)){

			if(acumuladorSalarios > 0){

				printf("\nEl total de salarios de Jugadores cargados es: $%.2f\n", acumuladorSalarios);
				promedio = acumuladorSalarios / contadorJugadores;

				if(promedio > 0){

					printf("\nEl salario promedio es: $%.2f\n", promedio);
				}

			}else{

				printf("No existe un total de salarios disponible hasta el momento\n");
			}

			if(cantidadDeJugadoresConSalarioMayorAlPromedio(arrayJugadores, longitudJugadores,
					&jugadoresConSalarioMayorAlPromedio, &promedio)){


				printf("\nLa cantidad de jugadores con un salario mayor al promedio son: %d\n\n",
						jugadoresConSalarioMayorAlPromedio);
				retorno = 1;
			}
		}
	}
	return retorno;
}

/**
*\brief: busca la cantidad maxima de jugadores junto con sus salarios acumulados y los retorna por puntero.
*\param:	array de ejugador, int longitudArray, puntero a float, puntero a int.
*\return: Retorna 1 para bien , Retorna 0 si no se logro.
**/
int totalDeSalarios(eJugador arrayJugadores[], int longitudJugadores, float* totalSalarios, int* cantidadJugadores){

	int retorno = 0;
	int acumuladorSalarios = 0;
	int contadorJugadores = 0;
	if(arrayJugadores != NULL && longitudJugadores > 0){

		retorno = 1;

		for(int i = 0; i < longitudJugadores; i++){

			if(arrayJugadores[i].isEmpty == 1){

				acumuladorSalarios += arrayJugadores[i].salario;
				contadorJugadores++;
			}
		}
		*cantidadJugadores = contadorJugadores;
		*totalSalarios = acumuladorSalarios;

		if(contadorJugadores == 0){

			retorno = 0;
		}
	}
	return retorno;
}

/**
*\brief: Encuentra la confederacion con mas años de contrato y te la imprime.
*\param: array de tipo eJugador, array de tipo eConfederacion, longitud del segundo array, longitud del primer array.
*\return: retorna 1 si lo logro, retorna 0 si ocurrio algun error.
**/
int confederacionConMayorAniosDeContratos(eJugador arrayJugadores[],eConfederacion arrayConfederaciones[],
										 int longitudConfederaciones, int longitudJugadores){

	int retorno = 0;
	int aniosDeContratoId100 = 0;
	int aniosDeContratoId101 = 0;
	int aniosDeContratoId102 = 0;
	int aniosDeContratoId103 = 0;
	int aniosDeContratoId104 = 0;
	int aniosDeContratoId105 = 0;
	int resultado;
	char nombreConfederacion[50];
	int idConMaximaniosDeContrato;

	if(arrayJugadores != NULL && arrayConfederaciones != NULL && longitudConfederaciones > 0 &&
			longitudJugadores > 0){


		retorno = 1;

		for(int i = 0; i < longitudJugadores; i++){

			if(arrayJugadores[i].isEmpty == 1){

				switch(arrayJugadores[i].idConfederacion){

				case 100:
					aniosDeContratoId100 += arrayJugadores[i].aniosContrato;
					break;

				case 101:
					aniosDeContratoId101 += arrayJugadores[i].aniosContrato;
					break;

				case 102:
					aniosDeContratoId102 += arrayJugadores[i].aniosContrato;
					break;

				case 103:
					aniosDeContratoId103 += arrayJugadores[i].aniosContrato;
					break;

				case 104:
					aniosDeContratoId104 += arrayJugadores[i].aniosContrato;
					break;

				case 105:
					aniosDeContratoId105 += arrayJugadores[i].aniosContrato;
					break;
				}

			}
		}//FIN DEL FOR

		if(obtenerMaximoPorId(aniosDeContratoId100, aniosDeContratoId101, aniosDeContratoId102, aniosDeContratoId103,
						   aniosDeContratoId104, aniosDeContratoId105, &resultado, &idConMaximaniosDeContrato)){

			if(buscarNombreDeConfederacion(arrayConfederaciones, longitudConfederaciones, idConMaximaniosDeContrato,
										nombreConfederacion)){

				printf("\nLa confederacion con mayor anios de contrato es: %s  y con %d años de contrato\n\n",
						nombreConfederacion , resultado);
			}else{

				retorno = 0;
			}

		}else{

			retorno = 0;
		}
	}
	return retorno;
}



/**
*\brief: calculo el porcentaje de jugadores por cantidad de tipo de econfederaciones.
*\param: array de tipo eJugador, array de tipo eConfederacion, longitud de primer array.
*\return: retorna 1 bien, retorna 0 error
**/
int porcentajeDeJugadoresPorConfederacion(eJugador arrayJugadores[],eConfederacion arrayConfederaciones[],
										  int longitudJugadores){

	int retorno = 0;
	int contadorJugadores = 0;
	int contadoriD100 = 0;
	int contadoriD101 = 0;
	int contadoriD102 = 0;
	int contadoriD103 = 0;
	int contadoriD104 = 0;
	int contadoriD105 = 0;

	float porcentajeConmebol;
	float porcentajeUefa;
	float porcentajeAfc;
	float porcentajeCaf;
	float porcentajeConcacaf;
	float porcentajeOfc;


	if(arrayJugadores != NULL && longitudJugadores > 0 && arrayConfederaciones != NULL){

		retorno = 1;

		for(int i = 0; i < longitudJugadores; i++){

			if(arrayJugadores[i].isEmpty == 1){

				contadorJugadores++;

				switch(arrayJugadores[i].idConfederacion){

				case 100:
					contadoriD100++;
					break;

				case 101:
					contadoriD101++;
					break;

				case 102:
					contadoriD102++;
					break;

				case 103:
					contadoriD103++;
					break;

				case 104:
					contadoriD104++;
					break;

				case 105:
					contadoriD105++;
					break;
				}
			}
		}//Fin del for.

		if(calcularPorcentaje(&porcentajeConmebol,contadoriD100, contadorJugadores)&&
			calcularPorcentaje(&porcentajeUefa,contadoriD101, contadorJugadores)&&
			calcularPorcentaje(&porcentajeAfc,contadoriD102, contadorJugadores)&&
			calcularPorcentaje(&porcentajeCaf,contadoriD103, contadorJugadores)&&
			calcularPorcentaje(&porcentajeConcacaf,contadoriD104, contadorJugadores)&&
		    calcularPorcentaje(&porcentajeOfc,contadoriD105, contadorJugadores)){


			printf("\nCONMEBOL: %.2f %s",porcentajeConmebol,"%");
			printf("\nUEFA: %.2f %s",porcentajeUefa,"%");
			printf("\nAFC: %.2f %s",porcentajeAfc,"%");
			printf("\nCAF: %.2f %s",porcentajeCaf,"%");
			printf("\nCONCACAF: %.2f %s",porcentajeConcacaf,"%");
			printf("\nOFC: %.2f %s \n\n",porcentajeOfc,"%");

		}else{

			retorno = 0;
		}
	}
	return retorno;
}


/**
*\brief: Calcula la region con mas jugadores.
*\param: array de tipo eJugadores, array de tipo eConfederacion, longitud del segundo array, longitud del primer array.
*\return: retorna 1 si lo logro, retorna 0 si ocurrio algun error.
**/
int regionMasJugadores(eJugador arrayJugadores[], eConfederacion arrayConfederaciones[], int longitudConfederacion,
					   int longitudJugadores){

	int retorno = 0;
	int maximoDeJugadoresEnRegion = 0;
	int contadorJugadores;
	int auxId;
	char regionConMasJugadores[50];

	if(arrayJugadores != NULL && arrayConfederaciones != NULL && longitudConfederacion > 0 && longitudJugadores > 0){

		retorno = 1;

		for(int i = 0; i < longitudConfederacion; i++){

			contadorJugadores = 0;

			for(int j = 0; j < longitudJugadores; j++){

				if(arrayJugadores[j].isEmpty == 1 && arrayConfederaciones[i].id == arrayJugadores[j].idConfederacion){

					contadorJugadores++;
				}
			}

			if(maximoDeJugadoresEnRegion < contadorJugadores){

				maximoDeJugadoresEnRegion = contadorJugadores;
				auxId = arrayConfederaciones[i].id;
				strncpy(regionConMasJugadores, arrayConfederaciones[i].region, 50);

			}
		}//fin del for confederacion.

		printf("\nRegion: %s\n", regionConMasJugadores);

		if(!listarJugadoresPorRegion(arrayJugadores, longitudJugadores, arrayConfederaciones, longitudConfederacion,
				auxId)){

			retorno = 0;
		}
	}
	return retorno;
}

/**
*\brief: Busca jugadores con salario mas altos al promedio.
*\param: Array de tipo eJugador, int longitud del array, puntero a int, puntero a float.
*\return: Retorna 1 para bien , Retorna 0 si no se logro.
**/
int cantidadDeJugadoresConSalarioMayorAlPromedio(eJugador arrayJugadores[], int longitudJugadores,
													int* contadorJugadores, float* sueldoPromedio){

	int retorno = 0;
	int jugadoresConSalarioMayorAlPromedio = 0;

	if(arrayJugadores != NULL && longitudJugadores > 0 && sueldoPromedio != NULL && sueldoPromedio != NULL){

		retorno = 1;

		for(int j = 0; j < longitudJugadores; j++){

			if(arrayJugadores[j].isEmpty == 1 && arrayJugadores[j].salario > *sueldoPromedio){

				jugadoresConSalarioMayorAlPromedio++;

			}
		}//FIN FOR MAYORES AL SALARIO PROMEDIO.

		*contadorJugadores = jugadoresConSalarioMayorAlPromedio;
	}
	return retorno;
}

/**
*\brief: imprime las confederaciones con los jugadores participes.
*\param: array de tipo eJugador, array de tipo eConfederacion, int longitudJugadores, int longitudConfederaciones.
*\return: Retorna 1 para bien , Retorna 0 si no se logro.
**/
int jugadoresPorConfederacion(eJugador arrayJugadores[], eConfederacion arrayConfederaciones[],
								int longitudConfederacion, int longitudJugadores){

	int retorno = 0;
	int contador = 0;
	int flagPrint = 0;
	char confederacion[50];

	if(arrayJugadores != NULL && arrayConfederaciones != NULL && longitudConfederacion > 0 && longitudJugadores > 0){

		retorno = 1;

		for(int i = 0; i < longitudConfederacion; i++){

			contador = 0;
			flagPrint = 0;

			for(int j = 0; j < longitudJugadores; j++){

				if(arrayJugadores[j].isEmpty == 1 && arrayConfederaciones[i].id == arrayJugadores[j].idConfederacion){
					contador++;

					if(contador > 0 && flagPrint == 0){
						strncpy(confederacion, arrayConfederaciones[i].nombre, 50);
						printf("\n%s\n", confederacion);
						printf("| %5s | %25s | %15s | %5s | %10s | %12s | %15s |\n", "ID", "NOMBRE JUGADOR", "POSICION",
												"N°CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS DE CONTRATO");
						flagPrint = 1;
					}

					if(!mostrarDatoJugador(arrayJugadores[j], arrayConfederaciones, longitudConfederacion)){

						retorno = 0;
						break;
					}
				}
			}//fin for jugadores.

		}//fin del for confederacion.
	}
	return retorno;
}
