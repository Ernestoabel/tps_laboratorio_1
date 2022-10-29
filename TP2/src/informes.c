#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca_UTN.h"
#include "jugador.h"
#include "confederacion.h"
#include "salidaDeDatos.h"
#include "informes.h"
#include "calculos.h"

int funcionQueContieneLosInformes(eJugador* listaJugadores,eConfederacion* listaConfederacion,int cantidadJugadores,int cantidadConfederacion,int estado)
{
	int retorno=-1,sueldosPorArribaDelPromedio,elegirConfederacion;
	float promedio,totalSueldos;
	char opcion,volverAlMenu,continuarListando;
	do{
	opcion=menuInformes();
		switch(opcion){
			case 1:
				if(ordenarJugadoresAlfabeticamente(listaJugadores,listaConfederacion,cantidadJugadores,cantidadConfederacion,estado)==0)
				if(mostrarJugadores(listaJugadores,cantidadJugadores,estado,listaConfederacion)==0)
				utn_pausaPrograma();
				break;
			case 2:
				do{
					if(mostrarConfederaciones(listaConfederacion,cantidadConfederacion)==0)
					if(utn_getEntero(&elegirConfederacion,"\nINGRESE EL ID DE LA CONFEDERACION DEL JUGADOR\n","--ERROR--",100,105)==0)
					if(mostrarJugadoresPorConfederacion(listaJugadores,cantidadJugadores,listaConfederacion,&elegirConfederacion,estado)==0)
					continuarListando=continuarCarga("\n¿LISTAR OTRA CONFEDERACION?");
				}while(continuarListando!='N');
				break;
			case 3:
				totalSueldos=sacarPromedioDeSueldos(listaJugadores,cantidadJugadores,&promedio,estado);
				printf("\nEL TOTAL DE SUELDOS ES %.2f Y SU POMEDIO ES %.2f\n",totalSueldos,promedio);
				sueldosPorArribaDelPromedio=contarJugadoresPorArribaPromedioSueldo(listaJugadores,cantidadJugadores,promedio,estado);
				printf("\nLA CANTIDAD DE JUGADORES QUE SUPERAN EL PROMEDIO SON %d\n",sueldosPorArribaDelPromedio);
				utn_pausaPrograma();
				break;
			case 4:
				if(ordenarPorConfederacion(listaJugadores,cantidadJugadores,estado)==0)
				if(informarConfederacionMasAniosContrato(listaJugadores,cantidadJugadores,listaConfederacion,estado)==0)
				utn_pausaPrograma();
				break;
			case 5:
				if(informarPorcentajeDeJugadores(listaJugadores,cantidadJugadores,estado)==0)
				utn_pausaPrograma();
				break;
			case 6:
				if(ordenarPorConfederacion(listaJugadores,cantidadJugadores,estado)==0)
				if(informarConfederacionMasJugadores(listaJugadores,cantidadJugadores,listaConfederacion,estado)==0)
				utn_pausaPrograma();
				break;
			case 7:
				volverAlMenu=continuarCarga("\nCONFIRME VOLVER AL MENU PRINCIPAL DEL SISTEMA");
				break;
		}
	}while(volverAlMenu!='S');

	return retorno;
}
int asignarDescripcion(eJugador* listaJugadores,eConfederacion* listaConfederacion,int cantidadConfederacion, char* descripcion ,int posicion)
{
	int retorno=-1;
	if(listaJugadores!=NULL && listaConfederacion!=NULL){
		retorno=0;
		for(int i=0;i<cantidadConfederacion;i++){
			if((*(listaJugadores+posicion)).idConfederacion==(*(listaConfederacion+i)).id){
				strcpy(descripcion,(*(listaConfederacion+i)).nombre);
			}
		}
	}
	return retorno;
}
int ordenarJugadoresAlfabeticamente(eJugador* listaJugadores,eConfederacion* listaConfederacion,int cantidadJugadores,int cantidadConfederacion,int estado)
{
	int retorno=-1;
	char descripcionUno[50];
	char descripcionDos[50];
	eJugador jugadorAuxiliar;

	if(listaJugadores!=NULL && listaConfederacion!=NULL){
		for(int i=0;i<cantidadJugadores-1;i++){
			retorno=0;
			for(int j=i+1;j<cantidadJugadores;j++){
				if((*(listaJugadores+j)).isEmpty==estado){
					asignarDescripcion(listaJugadores,listaConfederacion,cantidadConfederacion, descripcionUno ,i);
					asignarDescripcion(listaJugadores,listaConfederacion,cantidadConfederacion, descripcionDos ,j);
					if(strcmp(descripcionUno, descripcionDos)>0){
						jugadorAuxiliar=(*(listaJugadores+i));
						(*(listaJugadores+i))=(*(listaJugadores+j));
						(*(listaJugadores+j))=jugadorAuxiliar;
					}
					else if(strcmp(descripcionUno, descripcionDos)==0){
						if(strcmp( (*(listaJugadores+i)).nombre,(*(listaJugadores+j)).nombre)>0){
							jugadorAuxiliar=(*(listaJugadores+i));
							(*(listaJugadores+i))=(*(listaJugadores+j));
							(*(listaJugadores+j))=jugadorAuxiliar;
						}
					}
				}
			}
		}
	}

	return retorno;
}
int mostrarJugadoresPorConfederacion(eJugador* listaJugadores,int cantidadJugadores,eConfederacion* listaConfederacion,int* idConfederacion,int estado)
{
	int retorno=-1,i,indice;
	    if(listaJugadores!=NULL){
	    	printf("\n=============================================================================================================================\n");
	    	printf("%s%s%s%s%s%s%s",
	    			"|  ID  |","        NOMBRE                       |","   POSICION    |"," NºCAMISETA |","    SUELDO    |"," CONFEDERACION |"," AÑOS DE CONTRATO |");
	    	printf("\n+------+-------------------------------------+---------------+------------+--------------+---------------+------------------+\n");
	    	for(i=0;i<cantidadJugadores;i++){
	            if((*(listaJugadores+i)).isEmpty==estado){
	            	if((*(listaJugadores+i)).idConfederacion==*idConfederacion){
	            		posicionConfederacion(listaJugadores,&indice,i);
	            		printf("| %4d | %-35s | %-13s |     %2hi     | %12.2f | %-13s |        %1hi         |\n",(*(listaJugadores+i)).id,(*(listaJugadores+i)).nombre,
	            				(*(listaJugadores+i)).posicion,(*(listaJugadores+i)).numeroCamiseta,
								(*(listaJugadores+i)).salario,(*(listaConfederacion+indice)).nombre,(*(listaJugadores+i)).aniosContrato);
	            	}
	            }
	        }
	    	printf("=============================================================================================================================\n");
	        retorno=0;
	    }
	return retorno;
}
int ordenarPorConfederacion(eJugador* ordenar,int cantidadJugadores,int estado)
{
    int retorno=-1,i,j;
    eJugador auxiliar;
    if(ordenar!=NULL){
        for(i=0;i<cantidadJugadores-1;i++){
            for(j=i+1;j<cantidadJugadores;j++){
            	if((*(ordenar+i)).isEmpty==estado){
					if ((*(ordenar+i)).idConfederacion>(*(ordenar+j)).idConfederacion){
						auxiliar=*(ordenar+i);
						*(ordenar+i)=*(ordenar+j);
						*(ordenar+j)=auxiliar;
					}
				}
            }
        }
        retorno=0;
    }
    return retorno;
}
int informarConfederacionMasAniosContrato(eJugador* listaJugadores,int cantidadJugadores,eConfederacion* listaConfederaciones,int estado)
{
	int retorno=-1,i,acumuladorAuxiliar=0,acumuladorAniosMaximo,idMAximo,indice;
	if(listaJugadores!=NULL && listaConfederaciones!=NULL){
		for(i=0;i<cantidadJugadores;i++){
				if(i==0){
					acumuladorAuxiliar = acumuladorDeAniosDeContrato(listaJugadores,cantidadJugadores,(*(listaJugadores+0)).idConfederacion,estado);
					idMAximo = listaJugadores[0].idConfederacion;
					acumuladorAniosMaximo=acumuladorAuxiliar;
				}else{
					if((*(listaJugadores+i)).idConfederacion != (*(listaJugadores+i-1)).idConfederacion){
						acumuladorAuxiliar = acumuladorDeAniosDeContrato(listaJugadores,cantidadJugadores,(*(listaJugadores+i)).idConfederacion,estado);
						if(acumuladorAuxiliar>acumuladorAniosMaximo){
							idMAximo = (*(listaJugadores+i)).idConfederacion;
							acumuladorAniosMaximo=acumuladorAuxiliar;
						}
					}
				}
		}
	}
	if(listaJugadores!=NULL && listaConfederaciones!=NULL){
		for(i=0;i<cantidadJugadores;i++){
			if((*(listaJugadores+i)).isEmpty==estado && idMAximo==(*(listaJugadores+i)).idConfederacion){
				posicionConfederacion(listaJugadores,&indice,i);
				printf("\nLA CONFEDERACION CON MAS AÑOS DE CONTRATO ES %s Y EL TOTAL DE AÑOS ES %d\n",(*(listaConfederaciones+indice)).nombre,
						acumuladorAniosMaximo);
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
int informarConfederacionMasJugadores(eJugador* listaJugadores,int cantidadJugadores,eConfederacion* listaConfederaciones,int estado)
{
	int retorno=-1,i,contadorAuxiliar=0,contadorAniosMaximo,idMAximo,indice;
	if(listaJugadores!=NULL && listaConfederaciones!=NULL){
		for(i=0;i<cantidadJugadores;i++){
				if(i==0){
					contadorJugadoresPorConfederacion(listaJugadores,cantidadJugadores,estado,&contadorAuxiliar,(*(listaJugadores+0)).idConfederacion);
					idMAximo = listaJugadores[0].idConfederacion;
					contadorAniosMaximo=contadorAuxiliar;
				}else{
					if((*(listaJugadores+i)).idConfederacion != (*(listaJugadores+i-1)).idConfederacion){
						contadorJugadoresPorConfederacion(listaJugadores,cantidadJugadores,estado,&contadorAuxiliar,(*(listaJugadores+i)).idConfederacion);
						if(contadorAuxiliar>contadorAniosMaximo){
							idMAximo = (*(listaJugadores+i)).idConfederacion;
							contadorAniosMaximo=contadorAuxiliar;
						}
					}
				}
		}
	}
	if(listaJugadores!=NULL && listaConfederaciones!=NULL){
    	printf("\n======================================================================================================================================\n");
    	printf("%s%s%s%s%s%s%s",
    			"|  ID  |","        NOMBRE                       |","   POSICION    |"," NºCAMISETA |","    SUELDO    |","        REGION          |"," AÑOS DE CONTRATO |");
    	printf("\n+------+-------------------------------------+---------------+------------+--------------+------------------------+------------------+\n");
    	for(i=0;i<cantidadJugadores;i++){
            if((*(listaJugadores+i)).isEmpty==estado && idMAximo==(*(listaJugadores+i)).idConfederacion){
            	posicionConfederacion(listaJugadores,&indice,i);
                printf("| %4d | %-35s | %-13s |     %2hi     | %12.2f | %-22s |        %1hi         |\n",(*(listaJugadores+i)).id,(*(listaJugadores+i)).nombre,
                		(*(listaJugadores+i)).posicion,(*(listaJugadores+i)).numeroCamiseta,
						(*(listaJugadores+i)).salario,(*(listaConfederaciones+indice)).region,(*(listaJugadores+i)).aniosContrato);
            }
        }
    	printf("======================================================================================================================================\n");
	}
	return retorno;
}
int informarPorcentajeDeJugadores(eJugador* listaJugadores,int cantidadJugadores,int estado)
{
	int retorno=-1,contador,contadorConmebol,contadorUefa,contadorAfc,contadorCaf,contadorConcacaf;
	int contadorOfc;
	float porcentajeConmebol,porcentajeUefa,porcentajeAfc,porcentajeCaf,porcentajeConcacaf,porcentaOfc;
	if(listaJugadores!=NULL && cantidadJugadores>0){
		if(contadorJugadoresTotales(listaJugadores,cantidadJugadores,estado,&contador)==0){}
		if(contadorJugadoresPorConfederacion(listaJugadores,cantidadJugadores,estado,&contadorConmebol,100)==0){}
		if(contadorJugadoresPorConfederacion(listaJugadores,cantidadJugadores,estado,&contadorUefa,101)==0){}
		if(contadorJugadoresPorConfederacion(listaJugadores,cantidadJugadores,estado,&contadorAfc,102)==0){}
		if(contadorJugadoresPorConfederacion(listaJugadores,cantidadJugadores,estado,&contadorCaf,103)==0){}
		if(contadorJugadoresPorConfederacion(listaJugadores,cantidadJugadores,estado,&contadorConcacaf,104)==0){}
		if(contadorJugadoresPorConfederacion(listaJugadores,cantidadJugadores,estado,&contadorOfc,105)==0){}
		if(calculoPromedio(contadorConmebol,contador,&porcentajeConmebol)==0){}
		if(calculoPromedio(contadorUefa,contador,&porcentajeUefa)==0){}
		if(calculoPromedio(contadorAfc,contador,&porcentajeAfc)==0){}
		if(calculoPromedio(contadorCaf,contador,&porcentajeCaf)==0){}
		if(calculoPromedio(contadorConcacaf,contador,&porcentajeConcacaf)==0){}
		if(calculoPromedio(contadorOfc,contador,&porcentaOfc)==0){}
		printf("\nPROMEDIO CONMEBOL %.2f\nPROMEDIO UEFA %.2f\nPROMEDIO AFC %.2f\nPROMEDIO CAF %.2f\n"
				"PROMEDIO CONCACAF %.2f\nPROMEDIO OFC %.2f\n",porcentajeConmebol,porcentajeUefa,
				porcentajeAfc,porcentajeCaf,porcentajeConcacaf,porcentaOfc);
		retorno=0;
	}
	return retorno;
}
