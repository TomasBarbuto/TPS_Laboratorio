#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_

typedef struct{

	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	int isEmpty;

}eConfederacion;

int iniciarConfederacionHarcodeada(eConfederacion arrayConfederaciones[]); // Va a iniciar las confederaciones harcodeadas.
int listarConfederaciones(eConfederacion arrayConfederaciones[], int longitud);
int buscarNombreDeConfederacion(eConfederacion arrayConfederaciones[], int longitudConfederaciones, int idConfederacion
		                        ,char pConfederacion[]);;
int buscarNombreDeRegion(eConfederacion arrayConfederaciones[], int longitudConfederaciones, int idConfederacion,
					     char pConfederacion[]);

//ABM CONFEDERACIONES.
int idConfederacion();
int inicializarConfederacionesNuevas(eConfederacion arrayConfederaciones[], int longitudConfederaciones);
int buscarVacioConfederacion(eConfederacion arrayConfederaciones[], int longitudConfederaciones);
void mostrarDatoConfederacion(eConfederacion arrayConfederaciones);
int darAltaConfederacion(eConfederacion arrayConfederaciones[], int longitudConfederaciones);
int validarExistenciaDeConfederacion(eConfederacion arrayConfederaciones[], int longitudConfederaciones, int id);
int darBajaConfederacion(eConfederacion arrayConfederaciones[], int longitudConfederaciones);
int modificarConfederacion(eConfederacion arrayConfederaciones[], int longitudConfederaciones);

#endif /* CONFEDERACIONES_H_ */
