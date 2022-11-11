#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_UTN.h"
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

int menuModificar(void)
{
	int opcion;
	printf("\n================================\n|       MODIFICAR JUGADOR      |\n+------------------------------+");
	printf("\n|1.MODIFICAR NOMBRE            |");
	printf("\n|2.MODIFICAR EDAD              |");
	printf("\n|3.MODIFICAR POSISICION        |");
	printf("\n|4.MODIFICAR NACIONALIDAD      |");
	printf("\n|5.VOLVER AL MENU PRINCIPAL    |\n================================\n");
	fflush(stdin);
	utn_getEntero(&opcion,"\nINGRESE OPCION: ","\n--Error--\nOPCION NO VALIDA\n",1,5);
    return opcion;
}
int menu(void)
{
	int opcion;
	printf("\n============================\n|       FIFA SYSTEM        |\n+--------------------------+");
	printf("\n|1.CARGA DE ARCHIVO        |");
	printf("\n|2.ALTA DE JUGADOR         |");
	printf("\n|3.MODIFICACION DE JUGADOR |");
	printf("\n|4.BAJA DE JUGADOR         |");
	printf("\n|5.LISTADOS                |");
	printf("\n|6.CONVOCAR JUGADORES      |");
	printf("\n|7.ORDENAR Y LISTAR        |");
	printf("\n|8.GENERAR ARCHIVO BINARIO |");
	printf("\n|9.CARGAR ARCHIVO BINARIO  |");
	printf("\n|10.GUARDAR ARCHIVOS .CSV  |");
	printf("\n|11.SALIR                  |\n============================\n");
	fflush(stdin);
	utn_getEntero(&opcion,"\nINGRESE OPCION: ","\n--Error--\nOPCION NO VALIDA\n",1,11);
	return opcion;
}
int menuListados(void)
{
	int opcion;
	printf("\n===================================================\n"
			"|         MENU LISTADOS                           |\n"
			"+-------------------------------------------------+");
	printf("\n|1.LISTADO DE JUGADORES                           |");
	printf("\n|2.LISTADO DE SELECCIONES                         |");
	printf("\n|3.JUGADORES CONVOCADOS                           |");
	printf("\n|4.VOLVER AL MENU PRINCIPAL                       |\n"
			"===================================================\n");
	fflush(stdin);
	utn_getEntero(&opcion,"\nINGRESE OPCION: ","\n--Error--\nOPCION NO VALIDA\n",1,4);
    return opcion;
}
int menuConvocados(void)
{
	int opcion;
	printf("\n===================================================\n"
			"|         MENU CONVOCADOS                         |\n"
			"+-------------------------------------------------+");
	printf("\n|1.CONVOCAR JUGADORES                             |");
	printf("\n|2.QUITAR DE LA SELECCION                         |");
	printf("\n|3.VOLVER AL MENU PRINCIPAL                       |\n"
			"===================================================\n");
	fflush(stdin);
	utn_getEntero(&opcion,"\nINGRESE OPCION: ","\n--Error--\nOPCION NO VALIDA\n",1,3);
    return opcion;
}
int menuListadosOrdenados(void)
{
	int opcion;
	printf("\n===================================================\n"
			"|         MENU LISTADOS ORDENADOS                 |\n"
			"+-------------------------------------------------+");
	printf("\n|1.JUGADORES POR NACIONALIDAD                     |");
	printf("\n|2.SELECCIONES POR CONFEDERACION                  |");
	printf("\n|3.JUGADORES POR EDAD                             |");
	printf("\n|4.JUGADORES POR NOMBRE                           |");
	printf("\n|5.VOLVER AL MENU PRINCIPAL                       |\n"
			"===================================================\n");
	fflush(stdin);
	utn_getEntero(&opcion,"\nINGRESE OPCION: ","\n--Error--\nOPCION NO VALIDA\n",1,5);
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
void opcionesDePosicion(void)
{
	printf("\n		INGRESE\nPortero--Defensa central--Lateral izquiero--Lateral derecho\n"
			"Pivote--Mediocentro--Extremo izquierdo--Extremo derecho\n"
			"Mediapunta--Delantero centro\n");
}
void opcionesDeConfederacion(void)
{
	printf("\nAFC  --  CAF  --  CONCACAF\n"
			"   CONMNEBOL  --  UEFA\n");
}
void opcionesDeNacionalidad(void)
{
	printf("\n		INGRESE\nArgentino--Brasilero--Uruguayo--Portugues--Ingles\n"
					"Aleman--Mexicano--Estado Unidense--Camerunes--Senegales\n"
					"Australiano--Qatari--Saudita--Coreano del sur--Irani\n"
					"Japones--Ghanes--Marroqui--Tunecino--Canadiense\n"
					"Espaniol--Frances--Gales--Holandes--Polaco\n"
					"Suizo--Serbio--Costarricense--Ecuatoriano--Belga\n"
					"Danes--Croata\n");
}
int mostrarJugadores(LinkedList* pArrayListJugador,int condicion,char* nacionalidadIngresada)
{
    int retorno=-1,i,cantidad,id,edad,idSeleccion;
    char nombreCompleto[51],posicion[51],nacionalidad[51],mensaje[51];
    Jugador* unJugador=jug_new();
    if(pArrayListJugador!=NULL && unJugador!=NULL){
    	cantidad=ll_len(pArrayListJugador);
    	printf("\n========================================================================================================================\n");
    	printf("%s%s%s%s%s%s",
    			"|  ID  |","        NOMBRE COMPLETO                       |"," EDAD |","      POSICION        |","  NACIONALIDAD   |","   CONVOCADO    |");
    	printf("\n+------+----------------------------------------------+------+----------------------+-----------------+----------------+\n");
    	for(i=0;i<cantidad;i++){
    		unJugador= (Jugador*) ll_get(pArrayListJugador,i);
    		jug_getId(unJugador,&id);
    		jug_getNombreCompleto(unJugador,nombreCompleto);
			jug_getEdad(unJugador,&edad);
			jug_getPosicion(unJugador,posicion);
			jug_getNacionalidad(unJugador,nacionalidad);
			jug_getIdSeleccion(unJugador,&idSeleccion);
			if(condicion==1){
				if(validarConvocados(idSeleccion,mensaje)==0){
					printf("| %4d | %-44s |  %2d  | %-20s | %-15s | %-14s |\n",
							id,nombreCompleto,edad,posicion,nacionalidad,mensaje);
    			}
			}else if(condicion==2){
				if(validarConvocados(idSeleccion,mensaje)==0){
					if(strcmp(nacionalidad,nacionalidadIngresada)==0){
						printf("| %4d | %-44s |  %2d  | %-20s | %-15s | %-14s |\n",
								id,nombreCompleto,edad,posicion,nacionalidad,mensaje);
					}
				}
			}else if(condicion==3){
				if(validarConvocados(idSeleccion,mensaje)==0){
					if(idSeleccion!=0){
						printf("| %4d | %-44s |  %2d  | %-20s | %-15s | %-14s |\n",
							id,nombreCompleto,edad,posicion,nacionalidad,mensaje);
					}
				}
			}
		}
    	printf("========================================================================================================================\n");
        retorno=0;
    }
    return retorno;
}
int mostrarConfederaciones(LinkedList* pArrayListSeleccion)
{
    int retorno=-1,i,cantidad,id,convocados;
    char pais[51],confederacion[51];
    Seleccion* unaSeleccion=selec_new();
    if(pArrayListSeleccion!=NULL && unaSeleccion!=NULL){
    	cantidad=ll_len(pArrayListSeleccion);
    	printf("\n======================================================\n");
    	printf("%s%s%s%s",
    			"|  ID  |","     PAIS       |"," CONFEDERACION |"," CONVOCADOS |");
    	printf("\n+------+----------------+---------------+------------+\n");
    	for(i=0;i<cantidad;i++){
    		unaSeleccion= (Seleccion*) ll_get(pArrayListSeleccion,i);
    		selec_getId(unaSeleccion,&id);
    		selec_getPais(unaSeleccion,pais);
    		selec_getConfederacion(unaSeleccion,confederacion);
    		selec_getConvocados(unaSeleccion,&convocados);
    		printf("| %4d | %-14s |    %-8s   |     %2d     |\n",
    				id,pais,confederacion,convocados);

        }
    	printf("======================================================\n");
        retorno=0;
    }
    return retorno;
}
