#include <stdio.h>
/**
 * @brief Funcion para el calculo flotante de un promedio
 *
 * @param datoUno Primer valor parceado del calculo promedio que va a ser divido por oto valor
 * @param datoDos Segundo valor del calculo promedio que dividira otro valor
 * @return Un numero flotante resultado del calculo promedio
 */
float calculoPromedio(int datoUno,int datoDos){
    float resultado;
    resultado=(float)datoUno/datoDos;
    return resultado;
}
