#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_UTN.h"
#include "confederacion.h"
#include "jugador.h"

int menuModificar(void)
{
	int opcion;
	printf("\n================================\n|       MODIFICAR JUGADOR      |\n+------------------------------+");
	printf("\n|1.MODIFICAR NOMBRE            |");
	printf("\n|2.MODIFICAR POSICION          |");
	printf("\n|3.MODIFICAR Nº DE CAMISETA    |");
	printf("\n|4.MODIFICAR CONFEDERACION     |");
	printf("\n|5.MODIFICAR SALARIO           |");
	printf("\n|6.MODIFICAR AÑOS DE CONTRATO  |");
	printf("\n|7.VOLVER AL MENU PRINCIPAL    |\n================================\n");
	fflush(stdin);
	utn_getEntero(&opcion,"\nINGRESE OPCION: ","\n--Error--\nOPCION NO VALIDA\n",1,7);
    return opcion;
}
int menu(void)
{
	int opcion;
	printf("\n============================\n|       FIFA SYSTEM        |\n+--------------------------+");
	printf("\n|1.ALTA DE JUGADOR         |");
	printf("\n|2.BAJA DE JUGADOR         |");
	printf("\n|3.MODIFICACION DE JUGADOR |");
	printf("\n|4.INFORMES                |");
	printf("\n|5.SALIR DEL PROGRAMA      |\n============================\n");
	fflush(stdin);
	utn_getEntero(&opcion,"\nINGRESE OPCION: ","\n--Error--\nOPCION NO VALIDA\n",1,5);
	return opcion;
}
int menuInformes(void)
{
	int opcion;
	printf("\n===================================================\n"
			"|         MENU INFORMES                           |\n"
			"+-------------------------------------------------+");
	printf("\n|1.LISTADO DE JUGADORES                           |");
	printf("\n|2.LISTADO POR CONFEDERACION                      |");
	printf("\n|3.TOTAL Y PROMEDIO DE SALARIOS                   |");
	printf("\n|4.CONFEDERACION CON MAYOR CANTIDAD DE AÑOS       |");
	printf("\n|5.PORCENTAJE DE JUGADORES POR CADA CONFEDERACION |");
	printf("\n|6.LISTADO DE LA REGION CON MAS JUGADORES         |");
	printf("\n|7.VOLVER AL MENU PRINCIPAL                       |\n"
			"===================================================\n");
	fflush(stdin);
	utn_getEntero(&opcion,"\nINGRESE OPCION: ","\n--Error--\nOPCION NO VALIDA\n",1,7);
    return opcion;
}
char continuarCarga(char* mensaje)
{
	int validar;
	char opcion;
	do{
		printf("%s",mensaje);
		fflush(stdin);
		validar=utn_getDosCaracter(&opcion,"\nINGRESE OPCION S/N: ","\n--Error--\nOPCION NO VALIDA\n",'S','N');
	}while(validar!=0);
	return opcion;
}
int mostrarJugadores(eJugador* listaJugadores,int cantidadJugadores,int estado,eConfederacion* descripcion)
{
    int retorno=-1,i,indice;
    if(listaJugadores!=NULL && descripcion!=NULL){
    	printf("\n=============================================================================================================================\n");
    	printf("%s%s%s%s%s%s%s",
    			"|  ID  |","        NOMBRE                       |","   POSICION    |"," NºCAMISETA |","    SUELDO    |"," CONFEDERACION |"," AÑOS DE CONTRATO |");
    	printf("\n+------+-------------------------------------+---------------+------------+--------------+---------------+------------------+\n");
    	for(i=0;i<cantidadJugadores;i++){
            if((*(listaJugadores+i)).isEmpty==estado){
            	posicionConfederacion(listaJugadores,&indice,i);
                printf("| %4d | %-35s | %-13s |     %2hi     | %12.2f | %-13s |        %1hi         |\n",(*(listaJugadores+i)).id,(*(listaJugadores+i)).nombre,
                		(*(listaJugadores+i)).posicion,(*(listaJugadores+i)).numeroCamiseta,
						(*(listaJugadores+i)).salario,(*(descripcion+indice)).nombre,(*(listaJugadores+i)).aniosContrato);
            }
        }
    	printf("=============================================================================================================================\n");
        retorno=0;
    }
    return retorno;
}
int mostrarConfederaciones(eConfederacion* listaConfederacion,int cantidadConfederacion)
{
	int retorno=1,i;
	if(listaConfederacion!=NULL){
		printf("\n===========================================================\n");
		printf("|%s|%s|%s|%s|"," ID   "," NOMBRE   ","     REGION             "," AÑO CREACION ");
		printf("\n-----------------------------------------------------------\n");
		for(i=0;i<cantidadConfederacion;i++){
			printf("| %3d  | %-8s | %-22s |   %4d       |\n",(*(listaConfederacion+i)).id,(*(listaConfederacion+i)).nombre,
					(*(listaConfederacion+i)).region,(*(listaConfederacion+i)).anioCreacion);
		}
		printf("===========================================================\n");
		retorno=0;
	}
	return retorno;
}
