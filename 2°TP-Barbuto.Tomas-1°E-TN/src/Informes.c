#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Confederaciones.h"
#include "Calculos.h"
#include "Jugadores.h"

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
                        }

                    }else if(strncmp(nombreConfederacioni, nombreConfederacionj, 50) == 0){

						if(strncmp(arrayJugadores[i].nombre,arrayJugadores[j].nombre, 50) > 0){

							banderaSwap = 1;
							auxJugador = arrayJugadores[i];
							arrayJugadores[i] = arrayJugadores[j];
							arrayJugadores[j]=auxJugador;
						}

                    } //Igualdad en las confederaciones

                }//fin for j

            }//fin for i
        } while(banderaSwap);

        retorno = 1;
    }
    return retorno;
}

/**
*\brief: Lista una variable de tipo eJugador con su respectivo idConfederacion y nombre.
*\param: variable de tipo eJugador, array de tipo eConfederacion, longitud del segundo array.
*\return: retorna 1 si lo logro, retorna 0 si ocurrio algun error.
**/
int listadoJugadoresConSuConfederacion(eJugador unJugador, eConfederacion arrayConfederacion[],
							  	  	   int longitudConfederaciones){

	int retorno = 0;

	if (unJugador.isEmpty == 1 && arrayConfederacion != NULL && longitudConfederaciones > 0){

		printf("|%*s|%*s|\n", 10, "Nombre", 20, "Confederacion");

		for (int i = 0; i < longitudConfederaciones; i++){

			if(unJugador.idConfederacion == arrayConfederacion[i].id){

				printf("|%*s|%*s|\n", 10, unJugador.nombre, 20, arrayConfederacion[i].nombre);
			}
		}

		retorno = 1;
	}

	return retorno;
}

/**
*\brief: Imprime una lista de los jugadores con su confederacion
*\param: array de tipo eJugador, longitud del array, array de tipo eConfederacion, longitud del array.
*\return: retorna 1 si lo logro, retorna 0 si ocurrio algun error.
**/
int imprimirListadoDeJugadoresConSuConfederacion(eJugador arrayJugadores[], int longitudJugadores,
												eConfederacion arrayConfederaciones[], int longitudConfederaciones){

	int retorno = 0;

	if (arrayJugadores != NULL && arrayConfederaciones != NULL && longitudJugadores > 0 && longitudJugadores > 0){

		for (int i = 0; i < longitudJugadores; i++){

			listadoJugadoresConSuConfederacion(arrayJugadores[i], arrayConfederaciones, longitudConfederaciones);

		}

		retorno = 1;
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


	if(arrayJugadores != NULL && longitudJugadores > 0){

		for(int i = 0; i < longitudJugadores; i++){

			if(arrayJugadores[i].isEmpty == 1){

				acumuladorSalarios += arrayJugadores[i].salario;
				contadorJugadores++;

			}
		}

		if(acumuladorSalarios > 0){

			printf("El total de salarios de Jugadores cargados es: $%.2f\n", acumuladorSalarios);
			promedio = acumuladorSalarios / contadorJugadores;

			if(promedio > 0){

				printf("El salario promedio es: $%.2f\n", promedio);
			}

		}else{

			printf("No existe un total de salarios disponible hasta el momento\n");

		}

		for(int j = 0; j < longitudJugadores; j++){

			if(arrayJugadores[j].isEmpty == 1 && arrayJugadores[j].salario > promedio){

				jugadoresConSalarioMayorAlPromedio++;

			}
		}//FIN FOR MAYORES AL SALARIO PROMEDIO.

		printf("La cantidad de jugadores con un salario mayor al promedio son: %d\n",
				jugadoresConSalarioMayorAlPromedio);
		retorno = 1;
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

			printf("Se obtuvo el valor correctamente\n");

			if(buscarNombreDeConfederacion(arrayConfederaciones, longitudConfederaciones, idConMaximaniosDeContrato,
										nombreConfederacion)){

				printf("\nLa confederacion con mayor anios de contrato es: %s  y su cantidad es: %d\n",
						nombreConfederacion , resultado);
			}else{

				printf("ERROR, llame al departamento de sistemas\n");
			}

		}else{

			printf("ERROR, llame al departamento de sistemas\n");
		}

		system("pause");

		retorno = 1;
	}
	return retorno;
}



/**
*\brief: calculo el porcentaje de jugadores por cantidad de tipo de econfederaciones.
*\param: array de tipo eJugador, array de tipo eConfederacion, longitud de primer array.
*\return:
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


	if(arrayJugadores != NULL && longitudJugadores > 0){

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
		}

		if(calcularPorcentaje(&porcentajeConmebol,contadoriD100, contadorJugadores)&&
			calcularPorcentaje(&porcentajeUefa,contadoriD101, contadorJugadores)&&
			calcularPorcentaje(&porcentajeAfc,contadoriD102, contadorJugadores)&&
			calcularPorcentaje(&porcentajeCaf,contadoriD103, contadorJugadores)&&
			calcularPorcentaje(&porcentajeConcacaf,contadoriD104, contadorJugadores)&&
		    calcularPorcentaje(&porcentajeOfc,contadoriD105, contadorJugadores)){

			printf("Los promedios se realizaron Correctamente\n");

			printf("\nEl porcentaje es: %.2f",porcentajeConmebol);
			printf("\nEl porcentaje es: %.2f",porcentajeUefa);
			printf("\nEl porcentaje es: %.2f",porcentajeAfc);
			printf("\nEl porcentaje es: %.2f",porcentajeCaf);
			printf("\nEl porcentaje es: %.2f",porcentajeConcacaf);
			printf("\nEl porcentaje es: %.2f\n",porcentajeOfc);

		}else{

			printf("Ocurrio un ERROR, comuniquese con el departamenteo de sistemas\n");
		}

		system("pause");

		retorno = 1;
	}

	return retorno;
}


/**
*\brief: Calcula la region con mas jugadores.
*\param: array de tipo eJugadores, array de tipo eConfederacion, longitud del segundo array, longitud del primer array.
*\return: retorna 1 si lo logro, retorna 0 si ocurrio algun error.
**/
int regionMasJugadores(eJugador arrayJugadores[],eConfederacion arrayConfederaciones[], int longitudConfederacion,
					   int longitudJugadores){

	int retorno = 0;
	int contadoriD100 = 0;
	int contadoriD101 = 0;
	int contadoriD102 = 0;
	int contadoriD103 = 0;
	int contadoriD104 = 0;
	int contadoriD105 = 0;
	int resultado;
	int idDeConfederacion;
	char nombreDeRegion[50];

	if(arrayJugadores != NULL && arrayConfederaciones != NULL && longitudJugadores > 0 && longitudConfederacion > 0){

		for(int i = 0; i < longitudJugadores; i++){

			if(arrayJugadores[i].isEmpty == 1){

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
			retorno = 1;
		}

		if(obtenerMaximoPorId(contadoriD100, contadoriD101, contadoriD102, contadoriD103, contadoriD104,
		   contadoriD105, &resultado, &idDeConfederacion)){

			printf("Se obtuvo el valor correctamente\n");

			if(buscarNombreDeRegion(arrayConfederaciones, longitudConfederacion, idDeConfederacion, nombreDeRegion)){

				printf("\nLa region con mas jugadores es: %s  y su cantidad es: %d\n",
						nombreDeRegion , resultado); // listado de los jugadores de esa region.
			}else{

				printf("ERROR, llame al departamento de sistemas\n");
			}

		}else{

			printf("ERROR, llame al departamento de sistemas\n");
		}

		system("pause");

		retorno = 1;
	}

	return retorno;
}
