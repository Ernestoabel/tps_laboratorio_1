/*
 ============================================================================
 Name        : Trabajo Practico n2 laboratorio 1
 Author      : Ernesto Fatala
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "confederacion.h"
#include "jugador.h"
#include "informes.h"
#include "salidaDeDatos.h"

#define TAMCONFEDERACIONES 6
#define TAMJUGADORES 3000
#define OCUPADO 1
#define VACIO 0

int main(void) {
	setbuf(stdout, NULL);
	eConfederacion listaConfederaciones[TAMCONFEDERACIONES]={
			{100,"CONMEBOL","SUDAMERICA",1916},{101,"UEFA","EUROPA",1954},
			{102,"AFC","ASIA",1954},{103,"CAF","AFRICA",1957},
			{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961},{105,"OFC","OCEANIA",1966},
	};/*
	eJugador listaJugadores[TAMJUGADORES]={
			{1,"DIBU MARTINEZ","ARQUERO",1,101,1500000,4,OCUPADO},{2,"NICOLAS OTAMENDI","DEFENSOR",6,101,2965000,2,OCUPADO},
			{3,"FEDERICO GATTONI","DEFENSOR",2,100,450000,5,OCUPADO},{4,"MARCOS ACUÑA","DEFENSOR",3,101,2400000,5,OCUPADO},
			{5,"GONZALO MONTIEL","DEFENSOR",4,101,950000,3,OCUPADO},{6,"LEANDRO PAREDES","MEDIOCAMPISTA",5,101,4160000,2,OCUPADO},
			{7,"ENZO FERNANDEZ","MEDIOCAMPISTA",8,101,1560000,5,OCUPADO},{8,"RODRIGO DEPAUL","MEDIOCAMPISTA",7,101,5125000,5,OCUPADO},
			{9,"LAUTARO MARTINEZ","DELANTERO",9,101,12322000,3,OCUPADO},{10,"LIONEL MESSI","DELANTERO",10,101,35000000,1,OCUPADO},
			{11,"ANGEL DIMARIA","DELANTERO",11,101,15000000,1,OCUPADO},{12,"FRANCO ARMANI","ARQUERO",12,100,1500000,1,OCUPADO},
	};*/
	eJugador listaJugadores[TAMJUGADORES];
	inicializarJugadores(listaJugadores,TAMJUGADORES,VACIO);
	int menuPrincipal,idJugadores=1,banderaCarga=0;
	char confirmarSalidaAlta;

	do{
		menuPrincipal=menu();
		switch (menuPrincipal){
			case 1:
				if(funcionQueCargaUnJugador(listaJugadores,TAMJUGADORES,OCUPADO,
						listaConfederaciones,TAMCONFEDERACIONES,&idJugadores)==0)
				banderaCarga=1;
				break;
			case 2:
				if(banderaCarga==1){
					if(funcionDeBajaDeJugador(listaJugadores,TAMJUGADORES,OCUPADO,
						listaConfederaciones)==0){}
				}else{
					printf("\nNO HAY JUGADORES CARGADOS EN EL SISTEMA\n");
				}
				if(validarQueHayaJugadores(listaJugadores,TAMJUGADORES,OCUPADO)==0){
					banderaCarga=1;
				}else{
					banderaCarga=0;
				}
				break;
			case 3:
				if(banderaCarga==1){
					if(funcionQueContieneModificaciones(listaJugadores,TAMJUGADORES,OCUPADO,
						listaConfederaciones,TAMCONFEDERACIONES)==0){}
				}else{
					printf("\nNO HAY JUGADORES CARGADOS EN EL SISTEMA\n");
				}
				break;
			case 4:
				if(banderaCarga==1){
				if(funcionQueContieneLosInformes(listaJugadores,listaConfederaciones,
						TAMJUGADORES,TAMCONFEDERACIONES,OCUPADO)==0){}
				}else{
					printf("\nNO HAY JUGADORES CARGADOS EN EL SISTEMA\n");
				}
				break;
			case 5:
				confirmarSalidaAlta=continuarCarga("\nCONFIRME SALIR DEL SISTEMA");
				break;
		}
	}while(confirmarSalidaAlta!='S');
	return EXIT_SUCCESS;
}
