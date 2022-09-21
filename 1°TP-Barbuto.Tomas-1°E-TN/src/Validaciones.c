#include <stdio.h>
#include <stdlib.h>



/**
*\brief: Solicita dos numeros al usuario, para realizar el calculo promedio
		 y pasarlo por puntero.

*\parammensajeEselmensajeasermostrado
*\returnElnúmeroingresadoporelusuario
*
*/

float calcularPromedio(float *pResultado, int multiplicador, int divisor){

	float promedio;

	promedio = (float)(multiplicador * 100) / divisor;

	*pResultado = promedio;

	return promedio;
}

void mostrarMenu(int *menu, float acumuladorHospedaje, float acumuladorComida, float acumuladorTransporte,
				int arqueros, int defensores, int mediocampistas, int delanteros){

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
			"5-Salir\n",acumuladorHospedaje, acumuladorComida, acumuladorTransporte,
			arqueros, defensores,mediocampistas,delanteros);

	scanf("%d",menu);

}

/**
*\briefSolicitaunnúmeroalusuarioydevuelveelresultado
*\parammensajeEselmensajeasermostrado
*\returnElnúmeroingresadoporelusuario
*
*/

void cargarCostos(float *costoHospedaje, float *acumuladorHospedaje, float *costoComida,
				float *acumuladorComida, float *costoTransporte, float *acumuladorTransporte){

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
	//void no retorna nada.
}

/**
*\briefSolicitaunnúmeroalusuarioydevuelveelresultado
*\parammensajeEselmensajeasermostrado
*\returnElnúmeroingresadoporelusuario
*
*/

int validarRango(int numero, int maximo, int minimo){

	int retorno;

	if(numero >= minimo && numero <= maximo){

		retorno = 1;

	}else{

		retorno = 0;

	}

	return retorno;
}

/**
*\briefSolicitaunnúmeroalusuarioydevuelveelresultado
*\parammensajeEselmensajeasermostrado
*\returnElnúmeroingresadoporelusuario
*
*/

int cargarJugador(int *posicionUno, int *posicionDos, int *posicionTres, int *posicionCuatro){

	int retorno = 0;
	int numero;
	int llave;

	printf("Ingrese lo datos correspondientes para cada jugador\n"
					   "Ingrese numero de camiseta: ");

	scanf("%d", &numero);

	printf("Ingrese posicion del jugador\n"
			"1- Arquero\n"
			"2- Defensor\n"
			"3- Mediocentro\n"
			"4- Delantero\n"
			"Valor: ");

	scanf("%d", &llave);

	switch(llave){

	case 1:

		if(*posicionUno == 2){

			printf("Ya no hay lugares para arqueros\n");
			system("pause");

		}else{

			*posicionUno = *posicionUno + 1;
			retorno = 1;

		}

		break;

	case 2:

		if(*posicionDos == 8){

			printf("Ya no hay lugares para defensores\n");
			system("pause");

		}else{

			*posicionDos = *posicionDos + 1;
			retorno = 1;

		}
		break;

	case 3:

		if(*posicionTres == 8){

			printf("Ya no hay lugares para mediocampistas\n");
			system("pause");

		}else{

			*posicionTres = *posicionTres + 1;
			retorno = 1;

		}

		break;

	case 4:

		if(*posicionCuatro == 4){

			printf("Ya no hay lugares para delanteros\n");
			system("pause");

		}else{

			*posicionCuatro = *posicionCuatro + 1;
			retorno = 1;
		}

		break;

	default:

		printf("Ingrese una posicion valida\n");
		system("pause");

		break;

	}

	return retorno;
}

/**
*\briefSolicitaunnúmeroalusuarioydevuelveelresultado
*\parammensajeEselmensajeasermostrado
*\returnElnúmeroingresadoporelusuario
*
*/

void cargarConfederacion(int *pContadorUno, int *pContadorDos, int *pContadorTres,
						int *pContadorCuatro, int *pContadorCinco, int *pContadorSeis, int *pCantidadTotal){

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

	if(validarRango(confederacion, 6, 1)){

		switch(confederacion){

		case 1:

			*pContadorUno = *pContadorUno + 1;
			break;

		case 2:

			*pContadorDos = *pContadorDos + 1;
			break;

		case 3:

			*pContadorTres = *pContadorTres + 1;
			break;

		case 4:

			*pContadorCuatro = *pContadorCuatro + 1;
			break;

		case 5:

			*pContadorCinco = *pContadorCinco + 1;
			break;

		case 6:

			*pContadorSeis = *pContadorSeis + 1;
			break;

		}

		*pCantidadTotal = *pContadorUno + *pContadorDos + *pContadorTres +
						*pContadorCuatro + *pContadorCinco + *pContadorSeis;

	}else{

		printf("Ingrese un valor valido");
		system("pause");

	}

}

/**
*\brief: Muestra por consola los resultados obtenidos, y verifica si el pPromedioUno es mayoritario
*		 agregandole recargo de %35.
*\param:
*\return Void
*
*/

void mostrarResultados(float *pPromedioUno, float *pPromedioDos, float *pPromedioTres, float *pPromedioCuatro,
					float *pPromedioCinco, float *pPromedioSeis, float *pCostoTotal, float *pRecargo, float *pCostoRecargo){

	printf("Porcentaje Uefa: %.2f\n"
			"Porcentaje Conmebol: %.2f\n"
			"Porcentaje Concacaf: %.2f\n"
			"Porcentaje Afc: %.2f\n"
			"Porcentaje Ofc: %.2f\n"
			"Porcentaje Caf: %.2f\n", *pPromedioUno, *pPromedioDos
			, *pPromedioTres, *pPromedioCuatro, *pPromedioCinco, *pPromedioSeis);

	if(*pPromedioUno >= 50){

		printf("El costo de mantenimiento era de $%.2f y recibio un aumento de $%.2f,"
				" su nuevo valor es de: $%.2f\n", *pCostoTotal, *pRecargo, *pCostoRecargo);

	}else{

		printf("El costo de mantenimiento es: $%.2f\n", *pCostoTotal);

	}

		system("pause"); // pulse un tecla para continuar...

}


