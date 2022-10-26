#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_

typedef struct{

	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;

}eConfederacion;

int iniciarConfederacion(eConfederacion arrayConfederaciones[]);
int listarConfederaciones(eConfederacion arrayConfederaciones[], int longitud);

#endif /* CONFEDERACIONES_H_ */
