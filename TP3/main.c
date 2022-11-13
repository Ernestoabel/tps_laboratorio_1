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
            	if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores)==0){
            	}else{
            		printf("\nERROR EN LA FUNCION controller_cargarJugadoresDesdeTexto");
            	}
            	if(controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones)==0){
            	}else{
            		printf("\nERROR EN LA FUNCION controller_cargarSeleccionesDesdeTexto");
            	}
            	if(parser_y_apertura_IdFromText(&id)==0){
            	}else{
            		printf("\nERROR EN LA FUNCION parser_y_apertura_IdFromText");
            	}
                break;
            case 2:
            	if(ll_isEmpty(listaJugadores)==0){
            		do{
						if(controller_agregarJugador(listaJugadores,&id)==0){
						}else{
		            		printf("\nERROR EN LA FUNCION controller_agregarJugador");
		            	}
						continuarCargando=continuarCarga("\n�CONTINUAR CARGANDO JUGADORES?\n");
            		}while(continuarCargando!='N');
            	}else{
            		printf("\nCARGUE EL ARCHIVO PARA INGRESAR\n");
            	}
            	break;
            case 3:
            	if(ll_isEmpty(listaJugadores)==0){
            		if(controller_editarJugador(listaJugadores)==0){
            		}else{
	            		printf("\nERROR EN LA FUNCION controller_editarJugador");
	            	}
            	}else{
            		printf("\nCARGUE EL ARCHIVO PARA INGRESAR\n");
            	}
            	break;
            case 4:
            	if(ll_isEmpty(listaJugadores)==0){
            		if(controller_removerJugador(listaJugadores,listaSelecciones)==0){
            		}else{
	            		printf("\nERROR EN LA FUNCION controller_removerJugador");
	            	}
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
								if(controller_listarJugadores(listaJugadores)==0){
								}else{
				            		printf("\nERROR EN LA FUNCION controller_listarJugadores");
				            	}
								break;
							case 2:
								if(controller_listarSelecciones(listaSelecciones)==0){
								}else{
				            		printf("\nERROR EN LA FUNCION controller_listarSelecciones");
				            	}
								break;
							case 3:
								if(mostrarJugadores(listaJugadores,3,"")==0){
								}else{
				            		printf("\nERROR EN LA FUNCION mostrarJugadores");
				            	}
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
            		if(controller_editarSeleccion(listaSelecciones,listaJugadores)){
            		}else{
	            		printf("\nERROR EN LA FUNCION controller_editarSeleccion");
	            	}
            	}else{
            		printf("\nCARGUE EL ARCHIVO PARA INGRESAR\n");
            	}
            	break;
            case 7:
            	if(ll_isEmpty(listaJugadores)==0){
            		if(controller_ordenarJugadores(listaJugadores,listaSelecciones)==0){
            		}else{
	            		printf("\nERROR EN LA FUNCION controller_ordenarJugadores");
	            	}
            	}else{
            		printf("\nCARGUE EL ARCHIVO PARA INGRESAR\n");
            	}
            	break;
            case 8:
            	if(ll_isEmpty(listaJugadores)==0){
            		if(controller_guardarJugadoresModoBinario("SeleccionConvocada.dat",listaJugadores)==0){
            		}else{
	            		printf("\nERROR EN LA FUNCION controller_guardarJugadoresModoBinario");
	            	}
            	}else{
            		printf("\nCARGUE EL ARCHIVO PARA INGRESAR\n");
            	}
            	break;
            case 9:
            	if(controller_cargarJugadoresDesdeBinario("SeleccionConvocada.dat",listaJugadoresConvocados)==0){
            	}else{
            		printf("\nERROR EN LA FUNCION controller_cargarJugadoresDesdeBinario");
            	}
            	if(controller_listarJugadores(listaJugadoresConvocados)==0){
            	}else{
            		printf("\nERROR EN LA FUNCION controller_listarJugadores");
            	}
            	break;
            case 10:
            	if(ll_isEmpty(listaJugadores)==0){
            		if(controller_guardarJugadoresModoTexto("jugadores.csv",listaJugadores)==0){
            		}else{
                		printf("\nERROR EN LA FUNCION controller_guardarJugadoresModoTexto");
                	}
            		if(controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones)==0){
            		}else{
                		printf("\nERROR EN LA FUNCION controller_guardarSeleccionesModoTexto");
                	}
            		if(parser_y_guardado_IdToText(id)==0){
            		}else{
                		printf("\nERROR EN LA FUNCION parser_y_guardado_IdToText");
                	}
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

