#include "jugador.h"
int menuModificar(void);
/**
 * @brief -Funcion que permite la impresion de opciones de un menu, con un retorno entero que valida la opcion de un switch
 *
 * @return -Entero validado para la utilizacion en el switch
 */
int menu(void);
/**
 * @brief -Funcion que se encarga de preguntar y validar la interrupcion de un bucle
 *
 * @param mensaje -Mensaje impreso con las especificacion para continuar o no con el bucle
 * @return -Char para validar la interrupcion del bucle donde se llamo a la funcion
 */
char continuarCarga(char* mensaje);
/**
 * @brief -Funcion que permite la impresion de opciones de un menu, con un retorno entero que valida la opcion de un switch
 *
 * @return -Entero validado para la utilizacion en el switch
 */
int menuInformes(void);
/**
 * @brief -Funcion que se encarga imprimir el listado de jugadores cargados
 *
 * @param listaJugadores -LLamada a la estructura eJugador para ser impresa
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @param descripcion -LLamada a la estructura eConfederacion para imprimir su campo descripcion

 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int mostrarJugadores(eJugador* listaJugadores,int cantidadJugadores,int estado,eConfederacion* descripcion);
/**
 * @brief -Funcion que se encarga imprimir el listado de confederaciones cargadas
 *
 * @param listaJugadores -LLamada a la estructura eConfederacion para ser impresa
 * @param cantidadConfederacion -Numero de elementos arrays de la estructura eConfederacion
 *
 *  @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int mostrarConfederaciones(eConfederacion* listaConfederacion,int cantidadConfederacion);
