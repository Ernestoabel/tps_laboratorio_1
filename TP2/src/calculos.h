/**
 * @brief -Funcion que calcula el promedio de datos recividos por parametros
 *
 * @param calcular -Estructura eJugador a ser promediado uno de sus campos
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param resultado -Puntero que devuelve el resultado del calculo promedio
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @return -El acumuludado del campo sueldo
 */
int sacarPromedioDeSueldos(eJugador* calcular,int cantidadJugadores,float* resultado,int estado);
/**
 * @brief -Funcion que calcula la cantidad de jugadores por ariiba del promedio recivido por parametros
 *
 * @param calcular -Estructura eJugador a ser condicionada en uno de sus campos
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param promedio -Puntero que recive el promedio
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @return -El contador de los jugadores por arriba del sueldo promedio
 */
int contarJugadoresPorArribaPromedioSueldo(eJugador* calcular,int cantidadJugadores, float promedio,int estado);
/**
 * @brief -Funcion que acumula la cantidad de años de contrato de una confederacion pasada por parametro
 *
 * @param listaJugadores -Estructura eJugador a ser condicionada en uno de sus campos
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param confederacion -Entero que recive el id de confederacion
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int acumuladorDeAniosDeContrato(eJugador* listaJugadores,int cantidadJugadores,int confederacion,int estado);
/**
 * @brief -Funcion que recive dos datos por parametro para ser calculados por promedio
 *
 * @param datoUno -Primer entero para ser calculado
 * @param datoDos -Segudno entero para ser calculado
 * @param resultado -Puntero flotante que devuelve el resultado del calculo
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int calculoPromedio(int datoUno,int datoDos,float* resultado);
/**
 * @brief -Funcion que cuenta la cantidad de jugadores cargados en el sistema
 *
 * @param listaJugadores -Estructura eJugador a ser condicionada en uno de sus campos
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @param contador -Puntero entero que devueve el valor del contador
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int contadorJugadoresTotales(eJugador* listaJugadores,int cantidadJugadores,int estado,int* contador);
/**
 * @brief -Funcion que cuenta la cantidad de jugadores cargados en el sistema por confederacion
 *
 * @param listaJugadores -Estructura eJugador a ser condicionada en uno de sus campos
 * @param cantidadJugadores -Numero de elementos arrays de la estructura eJugador
 * @param estado -Valor que se recive para condicionar el recorrido en un for
 * @param contador -Puntero entero que devueve el valor del contador
 * @param idConfederacion -Valor recivido que es utilizado para condicionar el ciclo for
 * @return -Un entero para validar si la funcion pudo realizar su cometido
 */
int contadorJugadoresPorConfederacion(eJugador* listaJugadores,int cantidadJugadores,int estado,int* contador,int idConfederacion);

