#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "salidaDeDatos.h"
#include "parser.h"

int main()
{
	setbuf(stdout,NULL);
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    LinkedList* listaJugadoresConvocados = ll_newLinkedList();
    int opcionPrincipal,opcionMenuListados,id;
    char confirmarSalir,volverlAlMenu,continuarCargando;

    do{
    	opcionPrincipal=menu();
        switch(opcionPrincipal)
        {
            case 1:
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            	controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones);
            	parser_y_apertura_IdFromText(&id);
                break;
            case 2:
            	if(ll_isEmpty(listaJugadores)==0){
            		do{
						controller_agregarJugador(listaJugadores,&id);
						continuarCargando=continuarCarga("\n¿CONTINUAR CARGANDO JUGADORES?\n");
            		}while(continuarCargando!='N');
            	}else{
            		printf("\nCARGUE EL ARCHIVO PARA INGRESAR\n");
            	}
            	break;
            case 3:
            	if(ll_isEmpty(listaJugadores)==0){
            		controller_editarJugador(listaJugadores);
            	}else{
            		printf("\nCARGUE EL ARCHIVO PARA INGRESAR\n");
            	}
            	break;
            case 4:
            	if(ll_isEmpty(listaJugadores)==0){
            		controller_removerJugador(listaJugadores);
            	}else{
            		printf("\nCARGUE EL ARCHIVO PARA INGRESAR\n");
            	}
            	break;
            case 5:
            	if(ll_isEmpty(listaJugadores)==0){
					do{
						opcionMenuListados=menuListados();
						switch(opcionMenuListados){
							case 1:
								controller_listarJugadores(listaJugadores);
								break;
							case 2:
								controller_listarSelecciones(listaSelecciones);
								break;
							case 3:
								mostrarJugadores(listaJugadores,3,"");
								break;
							case 4:
								volverlAlMenu=continuarCarga("\nCONFIRME PARA VOLVER AL MENU PRINCIPAL");
								break;
						}
					}while(volverlAlMenu!='S');
            	}else{
            		printf("\nCARGUE EL ARCHIVO PARA INGRESAR\n");
            	}
            	break;
            case 6:
            	if(ll_isEmpty(listaJugadores)==0){
            		controller_editarSeleccion(listaSelecciones,listaJugadores);
            	}else{
            		printf("\nCARGUE EL ARCHIVO PARA INGRESAR\n");
            	}
            	break;
            case 7:
            	if(ll_isEmpty(listaJugadores)==0){
            		controller_ordenarJugadores(listaJugadores,listaSelecciones);
            	}else{
            		printf("\nCARGUE EL ARCHIVO PARA INGRESAR\n");
            	}
            	break;
            case 8:
            	if(ll_isEmpty(listaJugadores)==0){
            		controller_guardarJugadoresModoBinario("SeleccionConvocada.dat",listaJugadores);
            	}else{
            		printf("\nCARGUE EL ARCHIVO PARA INGRESAR\n");
            	}
            	break;
            case 9:
            	controller_cargarJugadoresDesdeBinario("SeleccionConvocada.dat",listaJugadoresConvocados);
            	controller_listarJugadores(listaJugadoresConvocados);
            	break;
            case 10:
            	if(ll_isEmpty(listaJugadores)==0){
            		controller_guardarJugadoresModoTexto("jugadores.csv",listaJugadores);
            		controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones);
            		parser_y_guardado_IdToText(id);
            	}else{
            		printf("\nCARGUE EL ARCHIVO PARA INGRESAR\n");
            	}
            	break;
            case 11:
            	confirmarSalir=continuarCarga("\nCONFIRME PARA SALIR DEL SISTEMA");
            	break;
        }
    }while(confirmarSalir!='S');

    return 0;
}

