#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"

int main(void){
	setbuf(stdout, NULL);

	int menu;
	int uefa = 0;
	float promedioUefa;
	int conmebol = 0;
	float promedioConmebol;
	int concacaf = 0;
	float promedioConcacaf;
	int afc = 0;
	float promedioAfc;
	int ofc = 0;
	float promedioOfc;
	int caf = 0;
	float promedioCaf;
	int arqueros = 0 ;
	int defensores = 0;
	int mediocampistas = 0;
	int delanteros = 0;
	int totalJugadores = 0;
	int flagCostos = 0;
	int flagCalculos = 0;
	float costoHospedaje = 0;
	float costoComida = 0;
	float costoTransporte = 0;
	float costoTotal;
	float costoConRecargo;
	float acumuladorHospedaje = 0;
	float acumuladorComida = 0 ;
	float acumuladorTransporte = 0;
	float recargoUefa;


	do {

		mostrarMenu(&menu, acumuladorHospedaje, acumuladorComida, acumuladorTransporte, arqueros, defensores,mediocampistas,delanteros);

		switch(menu){

		case 1:

			cargarCostos(&costoHospedaje, &acumuladorHospedaje, &costoComida, &acumuladorComida, &costoTransporte, &acumuladorTransporte);
			flagCostos = 1;

			break;

		case 2:

			if(totalJugadores == 22){

				printf("Ya tenes 22 jugadores cargados\n");
				system("pause");

			}else{

				if(cargarJugador(&arqueros, &defensores, &mediocampistas, &delanteros)){

					cargarConfederacion(&uefa, &conmebol, &concacaf, &afc, &ofc, &caf, &totalJugadores);
				}

			}

			break;

		case 3:

			if(totalJugadores > 0 && flagCostos == 1){

				costoTotal = costoTransporte + costoComida + costoHospedaje;

				calcularPromedio(&promedioUefa, uefa, totalJugadores);
				calcularPromedio(&promedioConmebol ,conmebol, totalJugadores);
				calcularPromedio(&promedioConcacaf,concacaf, totalJugadores);
				calcularPromedio(&promedioAfc, afc, totalJugadores);
				calcularPromedio(&promedioOfc, ofc, totalJugadores);
				calcularPromedio(&promedioCaf,caf, totalJugadores);

					if(promedioUefa >= 50){

						recargoUefa = costoTotal * 0.35;  //1.35 es el Valor de recargo del 35%.
						costoConRecargo = costoTotal + recargoUefa;

					}

				flagCalculos = 1;

				printf("Se han realizado los calculos con exito\n");
				system("pause");

			}else{

				printf("Debe completar los campos anteriores\n");
				system("pause");

			}
			break;

		case 4:

			if(flagCalculos == 1){

				mostrarResultados(&promedioUefa, &promedioConmebol , &promedioConcacaf, &promedioAfc,
								&promedioOfc, &promedioCaf, &costoTotal, &recargoUefa, &costoConRecargo);

				system("pause"); // pulse un tecla para continuar...

			}else{

				printf("Primero debe realizar los calculos\n");
				system("pause");

			}
			break;

		case 5: //Sale del menu y finaliza el programa.

			break;

		default:

			printf("Ingrese una opcion valida\n");
			system("pause");

			break;
		}

		}while(menu != 5);

	if(menu == 5){

		printf("Usted a salido del menu\n");

	}

	return 0;
}
