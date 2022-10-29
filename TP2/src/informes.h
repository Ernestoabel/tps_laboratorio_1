/**
 * @brief -Funcion que se encarga de llamar otras funciones para case 3 del switch en el menu principal
 *
 * @param listaJugadores -LLamada a la estructura eJugador para las respectivas funciones
 * @param listaConfederaciones -LLamada a la estructura eConfederacion para las respectivas funciones
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param cantidadConfederacion -Numero de elementos arrays de la estructura eConfederacion
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int funcionQueContieneLosInformes(eJugador* listaJugadores,eConfederacion* listaConfederacion,int cantidadJugadores,int cantidadConfederacion,int estado);
/**
 * @brief -Funcion que se encarga de devolver una cadena de caracteres por referencia para ser utilizada en un ordenamiento
 *
 * @param listaJugadores -LLamada a la estructura eJugador para las respectivas funciones
 * @param listaConfederaciones -LLamada a la estructura eConfederacion para las respectivas funciones
 * @param cantidadConfederacion -Numero de elementos arrays de la estructura eConfederacion
 * @param descripcion -Cadena de caracteres devuleta por refentica
 * @param posicion -Entero que recive un valor para ser recorrido en un ciclo for
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int asignarDescripcion(eJugador* listaJugadores,eConfederacion* listaConfederacion,int cantidadConfederacion, char* descripcion ,int posicion);
/**
 * @brief -Funcion que se encarga de un ordenamieto por doble condicion
 *
 * @param listaJugadores -LLamada a la estructura eJugador para ser burbujeada
 * @param listaConfederaciones -LLamada a la estructura eConfederacion para el uso de otra funcion
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param cantidadConfederacion -Numero de elementos arrays de la estructura eConfederacion
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int ordenarJugadoresAlfabeticamente(eJugador* listaJugadores,eConfederacion* listaConfederacion,int cantidadJugadores,int cantidadConfederacion,int estado);
/**
 * @brief -Funcion que se encarga de imprimir un listado mediante una condicion
 *
 * @param listaJugadores -LLamada a la estructura eJugador para ser condicionada y e impresa
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param listaConfederaciones -LLamada a la estructura eConfederacion para ser impresa
 * @param cantidadConfederacion -Numero de elementos arrays de la estructura eConfederacion
 * @param idConfederacion -Puntero que recive una direccion de memoria con una valor para ser condicionado
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int mostrarJugadoresPorConfederacion(eJugador* listaJugadores,int cantidadJugadores,eConfederacion* listaConfederacion,int* idConfederacion,int estado);
/**
 * @brief -Funcion que se encarga de ordenar la estructura eJugador por el campo idCofederacion para el calculo
 * 			en otras funciones
 *
 * @param listaJugadores -LLamada a la estructura eJugador para ser burbujeada
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int ordenarPorConfederacion(eJugador* ordenar,int cantidadJugadores,int estado);
/**
 * @brief -Funcion que se encarga de calcular, mediante la estructura eJugador ordenada, la confederacion con mas años de contrato
 *
 * @param listaJugadores -LLamada a la estructura eJugador para ser condicionada y contada
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param listaConfederaciones -LLamada a la estructura eConfederacion para ser impresa
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int informarConfederacionMasAniosContrato(eJugador* listaJugadores,int cantidadJugadores,eConfederacion* listaConfederaciones,int estado);
/**
 * @brief -Funcion que se encarga de calcular, mediante la estructura eJugador ordenada, la confederacion con mas jugadores y listarla
 *
 * @param listaJugadores -LLamada a la estructura eJugador para ser condicionada y contada
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param listaConfederaciones -LLamada a la estructura eConfederacion para ser impresa
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int informarConfederacionMasJugadores(eJugador* listaJugadores,int cantidadJugadores,eConfederacion* listaConfederaciones,int estado);
/**
 * @brief -Funcion que se encarga, mediante el llamado a otras funciones, imprimir el porcentaje de jugadores en cada confederacion
 *
 * @param listaJugadores -LLamada a la estructura eJugador para ser utilizada en otras funciones
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int informarPorcentajeDeJugadores(eJugador* listaJugadores,int cantidadJugadores,int estado);

