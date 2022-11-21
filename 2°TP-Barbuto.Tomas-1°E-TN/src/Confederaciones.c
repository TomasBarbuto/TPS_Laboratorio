#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Confederaciones.h"
#include "Jugadores.h"
#include "Validaciones.h"
#include "Menu.h"

/**
*\brief: Iniciar el campo isEmpty = 0, del array de tipo eConfederacion.
*\param: variable de tipo eConfederacion.
*\return: Retorna 1 si lo inicio correctamente, Retorna 0 si ocurrio algun error.
**/
int iniciarConfederacionHarcodeada(eConfederacion arrayConfederaciones[]){

	int retorno = 0;

	if(arrayConfederaciones != NULL){

		arrayConfederaciones[0].id = 100;
		strncpy(arrayConfederaciones[0].nombre,"CONMEBOL", 50);
		strncpy(arrayConfederaciones[0].region,"SUDAMERICA", 50);
		arrayConfederaciones[0].anioCreacion = 1916;
		arrayConfederaciones[0].isEmpty = 1;

		arrayConfederaciones[1].id = 101;
		strncpy(arrayConfederaciones[1].nombre,"UEFA", 50);
		strncpy(arrayConfederaciones[1].region,"EUROPA", 50);
		arrayConfederaciones[1].anioCreacion = 1954;
		arrayConfederaciones[1].isEmpty = 1;

		arrayConfederaciones[2].id = 102;
		strncpy(arrayConfederaciones[2].nombre,"AFC", 50);
		strncpy(arrayConfederaciones[2].region,"ASIA", 50);
		arrayConfederaciones[2].anioCreacion = 1954;
		arrayConfederaciones[2].isEmpty = 1;

		arrayConfederaciones[3].id = 103;
		strncpy(arrayConfederaciones[3].nombre,"CAF", 50);
		strncpy(arrayConfederaciones[3].region,"AFRICA", 50);
		arrayConfederaciones[3].anioCreacion = 1957;
		arrayConfederaciones[3].isEmpty = 1;

		arrayConfederaciones[4].id = 104;
		strncpy(arrayConfederaciones[4].nombre,"CONCACAF", 50);
		strncpy(arrayConfederaciones[4].region,"NO Y CEN AMERICA", 50);
		arrayConfederaciones[4].anioCreacion = 1961;
		arrayConfederaciones[4].isEmpty = 1;

		arrayConfederaciones[5].id = 105;
		strncpy(arrayConfederaciones[5].nombre,"OFC", 50);
		strncpy(arrayConfederaciones[5].region,"OCEANIA", 50);
		arrayConfederaciones[5].anioCreacion = 1966;
		arrayConfederaciones[5].isEmpty = 1;

		retorno = 1;
	}
	return retorno;
}

/**
*\brief: Muestra los datos de indices del array de tipo eConfederacion.
*\param: Array de tipo eConfederacion, Longitud del array.
*\return: Retorna 1 si puede mostrarlo, Retorna 0 si ocurrio un error.
**/
int listarConfederaciones(eConfederacion arrayConfederaciones[], int longitud){

	int retorno = 0;

	if (arrayConfederaciones != NULL && longitud > 0) {

		printf("\n| %5s | %25s | %17s | %15s |\n", "ID", "NOMBRE CONFEDERACION", "REGION", "AÑOS DE CONTRATO");
		for (int i = 0; i < longitud; i++) {

			printf("| %5d | %25s | %17s | %16d |\n", arrayConfederaciones[i].id,arrayConfederaciones[i].nombre,
					arrayConfederaciones[i].region,arrayConfederaciones[i].anioCreacion);

		}
		retorno = 1;
	}

	return retorno;
}

/**
*\brief: Busca coincidencias entre dos array por un id, si la encuentra retorna por puntero un array con el nombre correspondiente.
*\param: array de tipo eConfederacion, int longitud del array, int id a comparar, puntero a char.
*\return: retorna 1 si encontro coincidencia, retorna 0 si no lo hizo y ocurrio un error.
**/
int buscarNombreDeConfederacion(eConfederacion arrayConfederaciones[], int longitudConfederaciones, int idConfederacion,
								char pConfederacion[]){

    int retorno = 0;

    if(arrayConfederaciones != NULL && pConfederacion != NULL  && longitudConfederaciones > 0 ){

        for(int i = 0; i < longitudConfederaciones; i++){

            if(arrayConfederaciones[i].id == idConfederacion){

                strncpy(pConfederacion, arrayConfederaciones[i].nombre, 50);
                retorno = 1;
                break; // si encuentra coincidencia break.
            }
        }
    }
    return retorno;
}

/**
*\brief: Busca coincidencias entre dos array por un id, si la encuentra retorna por puntero un array con la region correspondiente.
*\param: array de tipo eConfederacion, int longitud del array, int id a comparar, puntero a char.
*\return: retorna 1 si encontro coincidencia, retorna 0 si no lo hizo y ocurrio un error.
**/
int buscarNombreDeRegion(eConfederacion arrayConfederaciones[], int longitudConfederaciones, int idConfederacion,
								char pConfederacion[]){

    int retorno = 0;

    if(arrayConfederaciones != NULL && pConfederacion != NULL  && longitudConfederaciones > 0 ){

        for(int i = 0; i < longitudConfederaciones; i++){

            if(arrayConfederaciones[i].id == idConfederacion){

                strncpy(pConfederacion, arrayConfederaciones[i].region, 50);
                retorno = 1;
                break; // si encuentra coincidencia break.
            }
        }
    }
    return retorno;
}

/**
*\brief: Otorga un ID autoincremental.
*\param: ---
*\return: retorna el id autoincrementado.
**/
int idConfederacion() {

	static int idConfederacion = 105;
	idConfederacion++;

	return idConfederacion;
}

/**
*\brief: Inicia el campo isempty del array de tipo eConfederacion en 0.
*\param: Array de tipo eConfederacion, longitud del Array.
*\return: Retorna 1 si funciono y 0 si ocurre algun error.
**/
int inicializarConfederacionesNuevas(eConfederacion arrayConfederaciones[], int longitudConfederaciones) {

	int retorno = 0;

	if (arrayConfederaciones != NULL && longitudConfederaciones > 6) {

		for (int i = 6; i < longitudConfederaciones; i++){

				arrayConfederaciones[i].isEmpty = 0; // 0.VACIO 1.LLENO

		}
		retorno = 1;
	}
	return retorno;
}

/**
*\brief: Recorre un array de tipo eConfederacion buscando algun espacio vacio. (isempty = 0)
*\param: Array de tipo eConfederacion, longitud del array.
*\return: Retorna el indice vacio  y -1 si no encontro.
**/
int buscarVacioConfederacion(eConfederacion arrayConfederaciones[], int longitudConfederaciones) {

	int retorno = -1;

	if (arrayConfederaciones != NULL && longitudConfederaciones > 0) {

		for (int i = 0; i < longitudConfederaciones; i++) {

			if (arrayConfederaciones[i].isEmpty == 0) {

				retorno = i; //ya encontre vacio, break.
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief: Retorna un grafico con los datos de una Confederacion.
*\param: array de tipo eConfederacion
*\return: void
**/
void mostrarDatoConfederacion(eConfederacion arrayConfederaciones){

	printf("\n+----------------------------------------------------------------------------------+\n");
	printf("| %2s |%8s | %5s | %1s |\n","ID","NOMBRE","REGION","AÑOS DE CONTRATO");
	printf("+----------------------------------------------------------------------------------+\n");

	printf("| %d |%8s | %5s | %d |\n", arrayConfederaciones.id,
			arrayConfederaciones.nombre, arrayConfederaciones.region, arrayConfederaciones.anioCreacion);

}

/**
*\brief: Carga datos en el array de tipo eConfederacion.
*\param: Array de tipo eConfederacion, longitud del array.
*\return: Retorna 1 si cargo correctamente y 0 si no.
**/
int darAltaConfederacion(eConfederacion arrayConfederaciones[], int longitudConfederaciones) {

	int retorno = 0;
	int indice;
	int confirmar;
	eConfederacion auxConfederacion;

	if (arrayConfederaciones != NULL && longitudConfederaciones > 0) {

		do{
			indice = buscarVacioConfederacion(arrayConfederaciones, longitudConfederaciones);

			if(indice != -1){



				if(utn_getNombre(auxConfederacion.nombre, 50, "\nIngrese Nombre: ",
				   "\nSupero los caracteres aceptados\n", 5) &&
				   utn_getNombre(auxConfederacion.region, 50, "\nIngrese region: ",
				   "\nSupero los caracteres aceptados\n", 5) &&
				   utn_getNumero(&auxConfederacion.anioCreacion, "\nIngrese anio de creacion: ", "\nAnio No valido\n",
				   1916, 2022, 5)){

					auxConfederacion.isEmpty = 1;
					auxConfederacion.id = idConfederacion();

				}else{

					printf("Ocurrio un error, llame al departamento de sistemas\n");
					break;
				}
			}

			mostrarDatoConfederacion(auxConfederacion);

			if(utn_getNumero(&confirmar, "\nIngrese 1 si los datos ingresados son correctos o 0 si desea volver a cargar\n"
				"Opcion: ", "\nNo ingreso algo valido\n", 0, 1, 5)){

				printf("Usted Confirmo los Datos Ingresados...\n");
			}else{

				auxConfederacion.id = idConfederacion()-2;
			}

		}while(confirmar != 1);

		arrayConfederaciones[indice] = auxConfederacion;
		retorno = 1;
	}

	return retorno;
}

/**
*\brief: Busca una coincidencia entre id y el array eConfederacion.
*\param: Array de tipo eConfederacion, longitud de tipo int, id de tipo int
*\return: retorna la posicion donde encontro la coincidencia, si no encuentra retorna -1.
**/
int validarExistenciaDeConfederacion(eConfederacion arrayConfederaciones[], int longitudConfederaciones, int id) {

	int retorno = -1;

	if (arrayConfederaciones != NULL && longitudConfederaciones > 0 && id > 0) {

		for (int i = 0; i < longitudConfederaciones; i++) {

			if (arrayConfederaciones[i].id == id) {

				retorno = i; //ya encontre el id, break.
				break;
			}
		}
	}

	return retorno;
}


/**
*\brief: Otorga la baja a un indice del array de tipo eConfederacion.
*\param: array de tipo eConfederacion, Longitud del array.
*\return: Retorna 0 si fue exitoso, Retorna -1 si ocurrio un error.
**/
int darBajaConfederacion(eConfederacion arrayConfederaciones[], int longitudConfederaciones) {

	int retorno = -1;
	int id;
	int indice;
	int confirmar;

	if (arrayConfederaciones != NULL && longitudConfederaciones > 0) {

		listarConfederaciones(arrayConfederaciones, longitudConfederaciones);

		do{
			if(!utn_getNumero(&id, "Que id quiere dar de baja?\nNumero: ",
					"Numero no valido\nReingrese El ID", 1, 3000, 5)){

				printf("Ocurrio un error, llame al departamento de sistemas\n");
				break;

			}else{

				indice = validarExistenciaDeConfederacion(arrayConfederaciones, longitudConfederaciones, id);

			}
			if (indice != -1) {

				arrayConfederaciones[indice].isEmpty = 0;

				mostrarDatoConfederacion(arrayConfederaciones[indice]);

				if(!utn_getNumero(&confirmar, "\nConfirme si desea dar de baja\n"
					"0-ELEGIR OTRO ID\n1- CONFIRMAR\nOPCION:", "\nNo es una opcion valida\n", 0,1,5)){

					printf("Ocurrio un error, llame al departamento de sistemas\n");
					break;
				}

			}

		}while(confirmar != 1);

		retorno = 0;
	}

	return retorno;
}

/**
*\brief: Modifica valores de una variable de tipo eConfederacion seleccionada.
*\param: array de tipo eConfederacion, Longitud del array.
*\return: Retorna 1 si se pudo modificar, Retorna 0 si no se logro.
**/
int modificarConfederacion(eConfederacion arrayConfederaciones[], int longitudConfederaciones) {

	int retorno = 0;
	int id;
	int indice;
	int opcion;

	if (arrayConfederaciones != NULL && longitudConfederaciones > 0) {

		retorno = 1;

		if(listarConfederaciones(arrayConfederaciones, longitudConfederaciones) &&
		utn_getNumero(&id, "Que id quiere dar de baja?\nNumero: ", "Numero no valido\nReingrese El ID",
				1, 3000, 5)){

			indice = validarExistenciaDeConfederacion(arrayConfederaciones, longitudConfederaciones, id);

		}

		if (indice == -1) {

			printf("No se encontro el ID seleccionado\n");
			system("pause");

		}else{

			do{
				mostrarMenuModificarConfederacion();
				if(utn_getNumero(&opcion, "\nOpcion: ", "Opcion no valida", 1, 4, 5)){

					switch (opcion) {

					case 1:
						if(!utn_getNombre(arrayConfederaciones[indice].nombre, 50, "\nIngrese nuevo nombre(max 50): ",
								"Usted ingreso mas de 50 caracteres. REINTENTE\n", 5)){

							retorno = 0;
							break;
						}
						break;

					case 2:
						if(!utn_getNombre(arrayConfederaciones[indice].region, 50, "\nIngrese la nueva region (max 50): ",
									"\nSupero los caracteres aceptados\n", 5)){

							retorno = 0;
							break;
						}
						break;

					case 3:
						if(!utn_getNumero(&arrayConfederaciones[indice].anioCreacion, "\nIngrese nuevo anio de creacion: ",
								"\nAño No valido\n", 1916, 2022, 5)){

							retorno = 0;
							break;
						}
						break;

					case 4:
						break;
					}
					system("pause");


				}else{

					printf("Ocurrio un error, Sera redirigido\n");
					break;

				}
			}while(opcion != 4);
		}
	}
	return retorno;
}

