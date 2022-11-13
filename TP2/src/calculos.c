#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jugador.h"
#include "confederacion.h"

int sacarPromedioDeSueldos(eJugador* calcular,int cantidadJugadores,float* resultado,int estado)
{
    int contadorJugadores=0,i;
    float totalSueldos=0;
    if(calcular!=NULL){
        for(i=0;i<cantidadJugadores;i++){
            if((*(calcular+i)).isEmpty==estado){
            	contadorJugadores++;
                totalSueldos+=(*(calcular+i)).salario;
            }
        }
        *resultado=totalSueldos/contadorJugadores;
    }
    return totalSueldos;
}
int contarJugadoresPorArribaPromedioSueldo(eJugador* calcular,int cantidadJugadores, float promedio,int estado)
{
    int contadorJugadores=0,i;
    if(calcular!=NULL){
        for(i=0;i<cantidadJugadores;i++){
        	if((*(calcular+i)).isEmpty==estado){
				if((*(calcular+i)).salario>promedio){
					contadorJugadores++;
				}
        	}
        }
    }
    return contadorJugadores;
}
int acumuladorDeAniosDeContrato(eJugador* listaJugadores,int cantidadJugadores,int confederacion,int estado)
{
	int i,acumulador=0;
	for(i=0;i<cantidadJugadores;i++){
		if((*(listaJugadores+i)).isEmpty==estado && (*(listaJugadores+i)).idConfederacion==confederacion){
			acumulador+=(&(*(listaJugadores+i)))->aniosContrato;
		}

	}
	return acumulador;
}
int calculoPromedio(int datoUno,int datoDos,float* resultado)
{
    int retorno=-1;
    if(datoUno>0 && datoDos>0){
    	*resultado=(float)datoUno/datoDos*100;
    	retorno=0;
    }
    return retorno;
}
int contadorJugadoresTotales(eJugador* listaJugadores,int cantidadJugadores,int estado,int* contador)
{
	int retorno=-1,i;
	*contador=0;
	if(listaJugadores!=NULL && cantidadJugadores>0){
		for(i=0;i<cantidadJugadores;i++){
			if((*(listaJugadores+i)).isEmpty==estado){
				(*contador)++;
			}
		}
		retorno=0;
	}
	return retorno;
}
int contadorJugadoresPorConfederacion(eJugador* listaJugadores,int cantidadJugadores,int estado,int* contador,int idConfederacion)
{
	int retorno=-1,i;
	*contador=0;
	if(listaJugadores!=NULL && cantidadJugadores>0){
		for(i=0;i<cantidadJugadores;i++){
			if((*(listaJugadores+i)).isEmpty==estado && (*(listaJugadores+i)).idConfederacion==idConfederacion){
				(*contador)++;
			}
		}
		retorno=0;
	}
	return retorno;
}
