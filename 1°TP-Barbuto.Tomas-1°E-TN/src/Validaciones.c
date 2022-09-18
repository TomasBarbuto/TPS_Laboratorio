#include <stdio.h>
#include <stdlib.h>


/**
 * \Brief Ingresa numero y rango del mismo
 * \param Valida si el numero esta en rango
 * \return (0) para verdadero o (-1) para falso
 */

float calcularPromedio(int multiplicador, int divisor)
{
	float promedio;

	promedio = (float)(multiplicador * 100) / divisor;

	return promedio;
}

void mostrarMenu(int *menu, float acumuladorHospedaje, float acumuladorComida, float acumuladorTransporte, int arqueros, int defensores, int mediocampistas, int delanteros){


	printf("\nBievenido al menu de la seleccion\n"
					"1-Ingreso de costos de mantenimiento\n"
					"\tCosto de hospedaje -> $ %.2f\n"
					"\tCosto de Comida -> $ %.2f\n"
					"\tCosto de Transporte -> $ %.2f\n"
					"2-Carga de Jugadores\n"
					"\tArqueros -> %d\n"
					"\tDefensores -> %d\n"
					"\tMediocentro -> %d\n"
					"\tDelanteros -> %d\n"
					"3-Realizar todos los calculos\n"
					"4-Informar todos los resultados\n"
					"5-Salir\n",acumuladorHospedaje, acumuladorComida, acumuladorTransporte, arqueros, defensores,mediocampistas,delanteros);
			scanf("%d",menu);

}

void cargarCostos(float *costoHospedaje, float *acumuladorHospedaje, float *costoComida, float *acumuladorComida, float *costoTransporte, float *acumuladorTransporte){

	int subMenuCostos;

	printf("Ingreso de los costos de mantenimiento\n"
							"1- Costo de Hospedaje\n"
							"2- Costo de Comida\n"
							"3- Costo de Transporte\n"
							"Valor: ");

					scanf("%d", &subMenuCostos);

					//mostrar submenu

				switch (subMenuCostos){ //cargarCostos..

				case 1:
					printf("Ingrese el costo de hospedaje: ");
					scanf("%f", costoHospedaje);
					*acumuladorHospedaje += *costoHospedaje;
					break;

				case 2:
					printf("Ingrese el costo de Comida: ");
					scanf("%f", costoComida);
					*acumuladorComida += *costoComida;
					break;


				case 3:
					printf("Ingrese el costo de Transportes: ");
					scanf("%f", costoTransporte);
					*acumuladorTransporte += *costoTransporte;
					break;

				default:
					printf("Ingrese una opcion valida\n");
					break;
				}


}

int validarRango(int numero, int maximo, int minimo){

	int retorno;

	if(numero >= minimo && numero <= maximo){

		retorno = 1;
	}else{

		retorno = 0;
	}

	return retorno;
}

int cargarJugador(int numeroDeCamiseta, int posicionJugador, int *arqueros, int *defensores, int *mediocampistas, int *delanteros){

	int retorno = 0;

	printf("Ingrese lo datos correspondientes para cada jugador\n"
					   "Ingrese numero de camiseta: ");

	scanf("%d", &numeroDeCamiseta);

	printf("Ingrese posicion del jugador\n"
			"1- Arquero\n"
			"2- Defensor\n"
			"3- Mediocentro\n"
			"4- Delantero\n"
			"Valor: ");

	scanf("%d", &posicionJugador);

	switch (posicionJugador){

	case 1:
		if(*arqueros == 2){
			printf("Ya no hay lugares para arqueros\n");
		}else{
			*arqueros = *arqueros + 1;
			retorno = 1;
		}
		break;

	case 2:
		if(*defensores == 8){
			printf("Ya no hay lugares para defensores\n");
		}else{
			*defensores = *defensores + 1;
			retorno = 1;
		}
		break;

	case 3:
		if(*mediocampistas == 8){
			printf("Ya no hay lugares para mediocampistas\n");
		}else{
			*mediocampistas = *mediocampistas + 1;
			retorno = 1;
		}
		break;

	case 4:
		if(*delanteros == 4){
			printf("Ya no hay lugares para delanteros\n");
		}else{
			*delanteros = *delanteros + 1;
			retorno = 1;
		}
		break;

	default:
		printf("Ingrese una posicion valida\n");
		break;

	}
	return retorno;
}

void cargarConfederacion(int *uefa, int *conmebol, int *concacaf, int *afc, int *ofc, int *caf, int *totalJugadores)
{

	int confederacion;

		printf("Ingrese la confederacion correspondiente\n"
				"1- UEFA\n"
				"2- CONMEBOL\n"
				"3- CONCACAF\n"
				"4- AFC\n"
				"5- OFC\n"
				"6- CAF\n"
				"Valor: ");

		scanf("%d", &confederacion);

		if(validarRango(confederacion, 6, 1))
		{
			switch(confederacion){ //Funcion validar.

			case 1:
				*uefa = *uefa + 1;
				*totalJugadores = *totalJugadores + 1;
				break;

			case 2:
				*conmebol = *conmebol + 1;
				*totalJugadores= *totalJugadores + 1;
				break;

			case 3:
				*concacaf = *concacaf + 1;
				*totalJugadores = *totalJugadores + 1;
				break;

			case 4:
				*afc = *afc + 1;
				*totalJugadores = *totalJugadores + 1;
				break;

			case 5:
				*ofc = *ofc + 1;
				*totalJugadores= *totalJugadores + 1;
				break;

			case 6:
				*caf = *caf + 1;
				*totalJugadores = *totalJugadores + 1;
				break;

			default:
				break;
			}
		}
		else
		{
			printf("Ingrese un valor valido");
		}

}


















