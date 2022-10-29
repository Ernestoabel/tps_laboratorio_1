#ifndef JUGADOR_H_INCLUDE
#define JUGADOR_H_INCLUDE
#include "confederacion.h"
typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;
/**
 * @brief -Funcion que recorre el array de un campo para inicializar todos los elementos
 *
 * @param listaJugadores -Estructura eJugador a ser inicializada
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param estado -Valor a modificar por la funcion
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int inicializarJugadores(eJugador* listaJugadores,int cantidadJugadores,int estado);
/**
 * @brief -Funcion que recorre un campo en busqueda de un estado para ocupar su posicion en el array
 *
 * @param espacioLibre -Estructura eJugador a ser analizada por la funcion
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param estado -Valor a ser tenido en cuenta por la funcion para encontrar la posicion libre en un array
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int buscarEspacioLibreIdJugadores(eJugador* espacioLibre,int cantidadJugadores, int estado);
/**
 * @brief -Funcion para validar el dato ingresado por el usuario en el campo posicion
 *
 * @param posicionIngresada -Valor que ingresa por parametro para ser validado
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int validarPosicion(char* posicionIngresada);
/**
 * @brief -Funcion para obtener el indice de la descripcion en la estructura eConfederarion para ser imprimida
 *
 * @param unJugador -Estructura eJugador a ser analizada por la funcion
 * @param posicion -Puntero por referencia que devuelve una posicion del indice
 * @param indice -Valor para ser utilizado como indice en un ciclo for
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int posicionConfederacion(eJugador* unJugador,int* posicion,int indice);
/**
 * @brief -Funcion que se encarga de pedirle al usuario los valores para los campos de la estructura
 *
 * @param id -Puntero autoincremental de un campo de la estructura eJugador
 * @param estado -Valor por parametro para un campo de la estructura eJugador
 * @param listaConfederaciones -Estructura eConfederacion para ser impresa
 * @param cantidadConfederacion -Numero de elementos arrays de la estructura eConfederacion
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
eJugador cargaJugador(int* id,int estado,eConfederacion* listaConfederaciones,int cantidadConfederacion);
/**
 * @brief -Funcion que busca que haya jugadores cargados en el sistema
 *
 * @param listaJugadores -Estructura eJugador a ser analizada por la funcion
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param estado -Valor que se recive para saber si hay o no jugadores cargados
 * @return -Un entero para validar si hay o no jugadores en el sistema
 */
int validarQueHayaJugadores(eJugador* listaJugadores,int cantidadJugadores,int estado);
/**
 * @brief -Funcion para pedir un id cargado en el array del campo, en la estructura eJugador
 *
 * @param listaJugadores -Estructura eJugador a ser analizada por la funcion
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param id -Puntero donde sera guardado el indice del array correspondiente al numero de id ingrezado
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int ingresarIdParaModificar(eJugador* listaJugadores,int cantidadJugadores,int* id,int estado);
/**
 * @brief -Funcion que se encarga de cambiar el valor de un campo de la estructura
 *
 * @param listaJugadores -Estructura eJugador a ser analizada por la funcion
 * @param id -Puntero que se recive para reconocer que array modificar
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int modificarNombreJugador(eJugador* listaJugadores,int* id);
/**
 * @brief -Funcion que se encarga de cambiar el valor de un campo de la estructura
 *
 * @param listaJugadores -Estructura eJugador a ser analizada por la funcion
 * @param id -Puntero que se recive para reconocer que array modificar
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int modificarPosicionJugador(eJugador* listaJugadores,int* id);
/**
 * @brief -Funcion que se encarga de cambiar el valor de un campo de la estructura
 *
 * @param listaJugadores -Estructura eJugador a ser analizada por la funcion
 * @param id -Puntero que se recive para reconocer que array modificar
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int modificarCamisetaJugador(eJugador* listaJugadores,int* id);
/**
 * @brief -Funcion que se encarga de cambiar el valor de un campo de la estructura
 *
 * @param listaJugadores -Estructura eJugador a ser analizada por la funcion
 * @param id -Puntero que se recive para reconocer que array modificar
 * @param listaConfederaciones -Estructura eConfederacion para ser impresa
 * @param cantidadConfederacion -Numero de elementos arrays de la estructura eConfederacion
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int modificarConfederacionJugador(eJugador* listaJugadores,int* id,eConfederacion* listaConfederaciones,
		int cantidadConfederacion);
/**
 * @brief -Funcion que se encarga de cambiar el valor de un campo de la estructura
 *
 * @param listaJugadores -Estructura eJugador a ser analizada por la funcion
 * @param id -Puntero que se recive para reconocer que array modificar
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int modificarSalarioJugador(eJugador* listaJugadores,int* id);
/**
 * @brief -Funcion que se encarga de cambiar el valor de un campo de la estructura
 *
 * @param listaJugadores -Estructura eJugador a ser analizada por la funcion
 * @param id -Puntero que se recive para reconocer que array modificar
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int modificarAnioContratoJugador(eJugador* listaJugadores,int* id);
/**
 * @brief -Funcion que cambia el valor del campo isEmpty para darlo de baja del sistema
 *
 * @param listaJugadores -Estructura eJugador a ser analizada por la funcion
 * @param id -Puntero que se recive para reconocer que array modificar
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int bajaDeJugador(eJugador* listaJugadores,int* id,int estado);
/**
 * @brief -Funcion que indica la condicion de ordenamiento para el campo Id de la estructura eJugador
 *
 * @param primerRubro -Llamada utilizada para la primera posicion del array en el campo Id
 * @param segundoRubro -Llamada utilizada para la segunda posicion del array en el campo Id
 * @return -Un entero que se encarga de validar la condicion del ordenamiento
 */
int condicionOrdenarId(eJugador* primerId, eJugador* segundoId);
/**
 * @brief -Funcion que se encarga del burbujeo bajo las candiciones recibidas por punteros a funcion
 *
 * @param listaArticulos -LLamada a la estructura eJugador para ser ordenada
 * @param cantidad -Numero de elementos arrays de la estructura eJugador
 * @param primerCriterio -Puntero a funcion encargado de la condicion del primero ordenamiento
 * @param segundoCriterio -Puntero a funcion encargado de la condicion del segundo ordenamiento
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int ordenadorPorDobleCriterio(eJugador* listaJugadores,int cantidad,int estado,
		int(*primerCriterio)(eJugador*, eJugador*),int(*segundoCriterio)(eJugador*, eJugador*));
/**
 * @brief -Funcion que se encarga de la asignacion de los puntero a funcion, para que ordene
 * 			desendentemente por numero de id
 *
 * @param listaJugadores -LLamada a la estructura eJugador para ser ordenada
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int ordenarPorId(eJugador* listaJugadores,int cantidadJugadores,int estado);
/**
 * @brief -Funcion que se encarga de llamar otras funciones para case 1 del switch en el menu principal
 *
 * @param listaJugadores -LLamada a la estructura eJugador para el ingreso de arrays
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @param listaConfederaciones -Estructura eConfederacion para ser impresa
 * @param cantidadConfederacion -Numero de elementos arrays de la estructura eConfederacion
 * @param idJugador -Campo id de la estructura eJugador, que recive un valor para luego incrementarse
 * 			mediante la carga de arrays
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int funcionQueCargaUnJugador(eJugador* listaJugadores,int cantidadJugadores,int estado,
		eConfederacion* listaConfederaciones,int cantidadConfederacion,int* idJugador);
/**
 * @brief -Funcion que se encarga de llamar otras funciones para case 2 del switch en el menu principal
 *
 * @param listaJugadores -LLamada a la estructura eJugador para la modificacion de arrays
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @param listaConfederaciones -Estructura eConfederacion para ser impresa
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int funcionDeBajaDeJugador(eJugador* listaJugadores,int cantidadJugadores,int estado,
		eConfederacion* listaConfederaciones);
/**
 * @brief -Funcion que se encarga de llamar otras funciones para case 3 del switch en el menu principal
 *
 * @param listaJugadores -LLamada a la estructura eJugador para la modificacion de arrays
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @param listaConfederaciones -Estructura eConfederacion para ser impresa
 * @param cantidadConfederacion -Numero de elementos arrays de la estructura eConfederacion
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int funcionQueContieneModificaciones(eJugador* listaJugadores,int cantidadJugadores,int estado,
		eConfederacion* listaConfederaciones,int cantidadConfederacion);
#endif
