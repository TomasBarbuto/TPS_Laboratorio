


#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int menu;
	int numeroDeCamiseta;
	int posicionJugador;
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
				if(totalJugadores == 22)
				{

					printf("Ya tenes 22 jugadores cargados\n");
					system("pause");

				}
				else
				{

					if(cargarJugador(&numeroDeCamiseta, &posicionJugador, &arqueros, &defensores, &mediocampistas, &delanteros)){

						cargarConfederacion(&uefa, &conmebol, &concacaf, &afc, &ofc, &caf, &totalJugadores);
					}

				}

			break;

		case 3:

			if(totalJugadores > 0 && flagCostos == 1 && costoHospedaje != 0 && costoTransporte != 0 && costoComida != 0){

				costoTotal = costoTransporte + costoComida + costoHospedaje;
				promedioUefa = calcularPromedio(uefa, totalJugadores);
				promedioConmebol = calcularPromedio(conmebol, totalJugadores);
				promedioConcacaf = calcularPromedio(concacaf, totalJugadores);
				promedioAfc = calcularPromedio(afc, totalJugadores);
				promedioOfc = calcularPromedio(ofc, totalJugadores);
				promedioCaf = calcularPromedio(caf, totalJugadores);

					if(promedioUefa >= 50){
						recargoUefa = costoTotal * 0.35;  //1.35 es el Valor de recargo del 35%.
						costoConRecargo = costoTotal + recargoUefa;
					}

				flagCalculos = 1;

				printf("tSe han realizado los calculos con exito\n");
				system("pause");

			}else{

				printf("Debe completar los campos anteriores\n");
				system("pause");


			}
			break;

		case 4:

			if(flagCalculos == 1){

				printf("Porcentaje Uefa: %.2f\n"
						"Porcentaje Conmebol: %.2f\n"
						"Porcentaje Concacaf: %.2f\n"
						"Porcentaje Afc: %.2f\n"
						"Porcentaje Ofc: %.2f\n"
						"Porcentaje Caf: %.2f\n",promedioUefa,promedioConmebol,promedioConcacaf,promedioAfc,promedioOfc,promedioCaf);
				if(promedioUefa >= 50){
					printf("El costo de mantenimiento era de $%.2f y recibio un aumento de $%.2f, su nuevo valor es de: $%.2f\n", costoTotal, recargoUefa, costoConRecargo);
				}else{
					printf("El costo de mantenimiento es: $%.2f\n",costoTotal);
				}
				system("pause"); // pulse un tecla para continuar...

			}else{

				printf("Primero debe realizar los calculos\n");
				system("pause");
			}
			break;

		case 5:
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
