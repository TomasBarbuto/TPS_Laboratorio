
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);
int controller_agregarJugador(LinkedList* pArrayListJugador);
int controller_editarJugador(LinkedList* pArrayListJugador);
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);//Modifique parametro, agrege linkedlist de seleccion para restar convocados si asi fuese.
int controller_listarJugadores(LinkedList* pArrayListJugador);
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_ConvocarJugadores(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador);
int controller_ListarConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_cargarIdAutoincremental(char* path, char* auxid);
int controller_guardarIdAutoincremental(char* path, int ultimoId);
int controller_removerJugadorDeSeleccion(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador);
int controller_listarJugadoresConSeleccion(LinkedList* pArrayListJugador, LinkedList* pArraylistSeleccion);
int controller_guardarJugadorPorConfederacionBinario(char *path, LinkedList* pArrayListJugador,
											  LinkedList* pArrayListSeleccion, char Confederacion[]);
int controller_cargarJugadoresPorConfederacionBinario(char *path, LinkedList* pArrayListJugador,
										      LinkedList* pArrayListSeleccion, char Confederacion[]);
int controller_listarJugadoresNoConvocados(LinkedList* pArrayListJugador);
int imprimirJugador(LinkedList* pArrayListaJugadores, int index);
int validarExistenciaDeJugador(LinkedList* pArrayJugadores, int idParam);
int imprimirJugadorSeleccion(LinkedList* pArrayListaJugadores, LinkedList* pArrayListaSeleccion, int index);
int imprimirSeleccion(LinkedList* pArrayListaSelecciones, int index);
int validarExistenciaDeSeleccion(LinkedList* pArrayListaSelecciones, int idParam);
int buscarNombreDeConfederacion(LinkedList *pArrayListSeleccion, int idSeleccion, char pConfederacion[]);
int buscarNombreDeSeleccion(LinkedList *pArrayListSeleccion, int idSeleccion, char pSeleccion[]);
int buscarIdMaximo(LinkedList* pArrayListJugador);
