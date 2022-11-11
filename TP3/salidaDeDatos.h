#include "jugador.h"
/**
 * @brief -Funcion que permite la impresion de opciones de un menu ede modificaciones
 * , con un retorno entero que valida la opcion de un switch
 *
 * @return -Entero validado para la utilizacion en el switch
 */
int menuModificar(void);
/**
 * @brief -Funcion que permite la impresion de opciones de un menu principal
 * , con un retorno entero que valida la opcion de un switch
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
 * @brief -Funcion que permite la impresion de opciones de un menu de listados
 * , con un retorno entero que valida la opcion de un switch
 *
 * @return -Entero validado para la utilizacion en el switch
 */
int menuListados(void);
/**
 * @brief -Funcion que permite la impresion de opciones de un menu con opciones de convocatoria
 * , con un retorno entero que valida la opcion de un switch
 *
 * @return -Entero validado para la utilizacion en el switch
 */
int menuConvocados(void);
/**
 * @brief -Funcion que permite la impresion de opciones de un menu de listados ordenados
 * , con un retorno entero que valida la opcion de un switch
 *
 * @return -Entero validado para la utilizacion en el switch
 */
int menuListadosOrdenados(void);
/**
 * @brief funcion para la impresion de opciones de posicion
 *
 */
void opcionesDePosicion(void);
/**
 * @brief funcion para la impresion de opciones de confederaciones
 *
 */
void opcionesDeConfederacion(void);
/**
 * @brief funcion para la impresion de opciones de nacionalidades
 *
 */
void opcionesDeNacionalidad(void);
/**
 * @brief -Funcion que se encarga imprimir el listado de jugadores cargados
 *
 * @param pArrayListJugador LinkedList a ser impresa
 * @param condicion para imprimir los datos de la LinkedList
 * @param nacionalidadIngresada string recivido para una de las condiciones de la impresion

 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int mostrarJugadores(LinkedList* pArrayListJugador,int condicion,char* nacionalidadIngresada);
/**
 * @brief -Funcion que se encarga imprimir el listado de selecciones cargadas
 *
 * @param pArrayListSeleccion LinkedList a ser impresa
 *
 *  @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int mostrarConfederaciones(LinkedList* pArrayListSeleccion);
