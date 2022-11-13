#ifndef CONFEDERACION_H_INCLUDE
#define CONFEDERACION_H_INCLUDE
typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
}eConfederacion;
/**
 * @brief -Funcion que recorre el array de un campo para inicializar todos los elementos
 *
 * @param listaConfederacion -Estructura eConfederacion a ser inicializada
 * @param cantidadConfederacion -Numero de elementos arrays de la estructura eConfederacion
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int inicializarConfederaciones(eConfederacion* listaConfederacion,int cantidadConfederacion);
/**
 * @brief -Funcion que recorre un campo en busqueda de un estado para ocupar su posicion en el array
 *
 * @param listaConfederacion -Estructura eConfederacion a ser analizada por la funcion
 * @param cantidadConfederacion -Numero de elementos arrays de la estructura eConfederacion
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int buscarEspacioLibreIdConfederaciones(eConfederacion* listaConfederacion,int cantidadConfederacion);
/**
 * @brief -Funcion que se encarga de pedirle al usuario los valores para los campos de la estructura
 *
 * @param id -Puntero autoincremental de un campo de la estructura eConfederacion
 * @param cantidadConfederacion -Numero de elementos arrays de la estructura eConfederacion
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
eConfederacion cargaConfederacion(int* id,int cantidadConfederacion);
/**
 * @brief -Funcion para pedir un id cargado en el array del campo, en la estructura eConfederacion
 *
 * @param listaConfederacion -Estructura eConfederacion a ser analizada por la funcion
 * @param cantidadConfederacion -Numero de elementos arrays de la estructura eConfederacion
 * @param id -Puntero donde sera guardado el indice del array correspondiente al numero de id ingrezado
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int ingresarIdParaModificarConfederacion(eConfederacion* listaConfederacion,int cantidadConfederacion,int* id);
/**
 * @brief -Funcion que se encarga de cambiar el valor de un campo de la estructura
 *
 * @param listaConfederacion -Estructura eConfederacion a ser analizada por la funcion
 * @param id -Puntero que se recive para reconocer que array modificar
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int modificarNombreConfederacion(eConfederacion* listaConfederacion,int* id);
/**
 * @brief -Funcion que se encarga de cambiar el valor de un campo de la estructura
 *
 * @param listaConfederacion -Estructura eConfederacion a ser analizada por la funcion
 * @param id -Puntero que se recive para reconocer que array modificar
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int modificarRegionConfederacion(eConfederacion* listaConfederacion,int* id);
/**
 * @brief -Funcion que se encarga de cambiar el valor de un campo de la estructura
 *
 * @param listaConfederacion -Estructura eConfederacion a ser analizada por la funcion
 * @param id -Puntero que se recive para reconocer que array modificar
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int modificarAnioCreacionConfederacion(eConfederacion* listaConfederacion,int* id);
/**
 * @brief -Funcion que cambia el valor del campo id para darlo de baja del sistema
 *
 * @param listaConfederacion -Estructura eConfederacion a ser analizada por la funcion
 * @param id -Puntero que se recive para reconocer que array modificar
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int bajaDeConfederacion(eConfederacion* listaConfederacion,int* id);
#endif
