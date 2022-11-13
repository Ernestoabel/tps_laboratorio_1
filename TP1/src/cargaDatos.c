#include <stdio.h>
/**
 * @brief Funcion generica para la carga de un valor flotante validado en positivo
 *
 * @return Un numero flotante
 */
float ingresoFlotante(void){
    float dato;
    printf ("\nIngrese el monto: ");
    fflush(stdin);
    scanf ("%f", &dato);
    while(dato<0)
    {
        printf ("\nIngrese un monto positivo: ");
        scanf ("%f", &dato);
    }
    return dato;
}
/**
 * @brief Funcion generica para la carga de un valor entero validado en un rango
 *
 * @return Un numero entero
 */
int ingresoEntero(void){
    int dato;
    printf("\nIngrese el dorsal del jugador: ");
    fflush(stdin);
    scanf("%d",&dato);
    while(dato<1||dato>99)
    {
        printf("\nIngrese el dorsal del jugador entre 1 y 99: ");
        scanf("%d",&dato);
    }
    return dato;
}
