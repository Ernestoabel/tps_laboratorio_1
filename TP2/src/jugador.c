#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jugador.h"
#include "confederacion.h"
#include "biblioteca_UTN.h"
#include "salidaDeDatos.h"
int inicializarJugadores(eJugador* listaJugadores,int cantidadJugadores,int estado)
{
	int retorno=-1,i;
	if(listaJugadores != NULL && cantidadJugadores > 0 ){
		for(i = 0; i<cantidadJugadores; i++){
			(*(listaJugadores+i)).isEmpty = estado;
		}
		retorno = 0;
	}
	return retorno;
}
int buscarEspacioLibreIdJugadores(eJugador* listaJugadores,int cantidadJugadores, int estado)
{
    int retorno=-1;
    int i;
    if(listaJugadores!=NULL){
    	for(i=0;i<cantidadJugadores;i++){
    		if((*(listaJugadores+i)).isEmpty==estado){
    			retorno = i;
    			break;
    		}
        }
    }
    return retorno;
}
int validarPosicion(char* posicionIngresada)
{
	int retorno=-1;
	if(strcmp(posicionIngresada,"ARQUERO")==0){
		retorno=0;
	}else if(strcmp(posicionIngresada,"DEFENSOR")==0){
		retorno=0;
	}else if(strcmp(posicionIngresada,"MEDIOCAMPISTA")==0){
		retorno=0;
	}else if(strcmp(posicionIngresada,"DELANTERO")==0){
		retorno=0;
	}else{
		printf("\nINGRESE UNA POSICION VALIDA\n");
	}
	return retorno;
}
int posicionConfederacion(eJugador* unJugador,int* posicion,int indice)
{
	int retorno=-1;
	if((*(unJugador+indice)).idConfederacion==100){
		*posicion=0;
		retorno=0;
	}
	if((*(unJugador+indice)).idConfederacion==101){
		*posicion=1;
		retorno=0;
	}
	if((*(unJugador+indice)).idConfederacion==102){
		*posicion=2;
		retorno=0;
	}
	if((*(unJugador+indice)).idConfederacion==103){
		*posicion=3;
		retorno=0;
	}
	if((*(unJugador+indice)).idConfederacion==104){
		*posicion=4;
		retorno=0;
	}
	if((*(unJugador+indice)).idConfederacion==105){
		*posicion=5;
		retorno=0;
	}
	return retorno;
}
eJugador cargaJugador(int* id,int estado,eConfederacion* listaConfederaciones,int cantidadConfederacion)
{
	eJugador cargaUnJugador;
	char nombre[25],apellido[25];
	if(id != NULL){
		do{
			if(utn_getCadenaCaracteres(50,nombre,"\nINGRESE EL NOMBRE DEL JUGADOR\n","--ERROR--")==0){}
		}while(utn_cadenaSoloLetra(nombre)!=1);
		do{
			if(utn_getCadenaCaracteres(50,apellido,"\nINGRESE EL APELLIDO DEL JUGADOR\n","--ERROR--")==0){}
		}while(utn_cadenaSoloLetra(apellido)!=1);
			strcat(nombre," ");
			strcat(nombre,apellido);
			strcpy(cargaUnJugador.nombre,nombre);
		do{
			printf("\n		INGRESE\nARQUERO--DEFENSOR--MEDIOCAMPISTA--DELANTERO");
			if(utn_getCadenaCaracteres(50,cargaUnJugador.posicion,"\nINGRESE LA POSICION DEL JUGADOR\n","--ERROR--")==0){}
		}while(validarPosicion(cargaUnJugador.posicion)!=0);
		if(utn_getEnteroShort(&cargaUnJugador.numeroCamiseta,"\nINGRESE EL DORSAL DEL JUGADOR\n(ENTRE 1 Y 99)\n","--ERROR--",1,99)==0){}
		if(mostrarConfederaciones(listaConfederaciones,cantidadConfederacion)==0){}
		if(utn_getEntero(&cargaUnJugador.idConfederacion,"\nINGRESE EL ID DE LA CONFEDERACION DEL JUGADOR\n","--ERROR--",100,105)==0){}
		if(utn_getFlotante(&cargaUnJugador.salario,"\nINGRESE EL SALARIO DEL JUGADOR\n(MENOR A 100 MILLONES)\n","--ERROR--",1,99999999)==0){}
		if(utn_getEnteroShort(&cargaUnJugador.aniosContrato,"\nINGRESE LOS AÑOS DE CONTRATO DEL JUGADOR\n(MAYOR A 1 Y MENOR A 10)\n","--ERROR--",1,9)==0){}
		cargaUnJugador.id = *id;
		(*id)++;
		cargaUnJugador.isEmpty=estado;
	}
	return cargaUnJugador;
}
int validarQueHayaJugadores(eJugador* listaJugadores,int cantidadJugadores,int estado)
{
	int retorno=-1,i;
	if(listaJugadores != NULL && cantidadJugadores > 0 ){
		for(i = 0; i<cantidadJugadores; i++){
			if((*(listaJugadores+i)).isEmpty==estado){
				retorno = 0;
			}
		}
	}

		return retorno;
}
int ingresarIdParaModificar(eJugador* listaJugadores,int cantidadJugadores,int* id,int estado)
{
    int i,retorno=-1,entro=0;
    if(listaJugadores!=NULL){
        do{
        	retorno=0;
        	utn_getEntero(id,"\nINGRESE ID\n","\n--ERROR--\n",1,3000);
            for(i=0;i<cantidadJugadores;i++){
                if((*(listaJugadores+i)).isEmpty==estado){
                    if((*(listaJugadores+i)).id==(*id)){
                    	(*id)=i;
                        entro=1;
                        break;
                    }
                }
            }
            if(entro==0){
            	printf("\nEL NUMERO DE ID NO CORRESPONDE A UN JUGADOR CARGADO\n");
            }
        }while(entro!=1);
        retorno=0;
    }
    return retorno;
}
int modificarNombreJugador(eJugador* listaJugadores,int* id)
{
	int retorno=-1;
	char nombre[25],apellido[25];
	if(listaJugadores!=NULL){
		do{
			if(utn_getCadenaCaracteres(50,nombre,"\nINGRESE EL NOMBRE DEL JUGADOR\n","--ERROR--")==0){}
		}while(utn_cadenaSoloLetra(nombre)!=1);
		do{
			if(utn_getCadenaCaracteres(50,apellido,"\nINGRESE EL APELLIDO DEL JUGADOR\n","--ERROR--")==0){}
		}while(utn_cadenaSoloLetra(apellido)!=1);
		strcat(nombre," ");
		strcat(nombre,apellido);
		strcpy((listaJugadores+(*id))->nombre,nombre);
		retorno=0;
	}
	return retorno;
}
int modificarPosicionJugador(eJugador* listaJugadores,int* id)
{
	int retorno=-1;
	if(listaJugadores!=NULL){
		do{
			printf("\n		INGRESE\nARQUERO--DEFENSOR--MEDIOCAMPISTA--DELANTERO");
			utn_getCadenaCaracteres(50,(*(listaJugadores+*id)).posicion,"\nINGRESE LA POSICION DEL JUGADOR\n","--ERROR--");
		}while(validarPosicion((*(listaJugadores+*id)).posicion)!=0);
		retorno=0;
	}
	return retorno;
}
int modificarCamisetaJugador(eJugador* listaJugadores,int* id)
{
	int retorno=-1;
	if(listaJugadores!=NULL){
		utn_getEnteroShort(&(listaJugadores+(*id))->numeroCamiseta,"\nINGRESE EL DORSAL DEL JUGADOR\n(ENTRE 1 Y 99)\n","--ERROR--",1,99);
		retorno=0;
	}
	return retorno;
}
int modificarConfederacionJugador(eJugador* listaJugadores,int* id,eConfederacion* listaConfederaciones,int cantidadConfederacion)
{
	int retorno=-1;
	if(listaJugadores!=NULL){
		mostrarConfederaciones(listaConfederaciones,cantidadConfederacion);
		utn_getEntero(&(listaJugadores+(*id))->idConfederacion,"\nINGRESE EL ID DE LA CONFEDERACION DEL JUGADOR\n","--ERROR--",100,105);
		retorno=0;
	}
	return retorno;
}
int modificarSalarioJugador(eJugador* listaJugadores,int* id)
{
	int retorno=-1;
	if(listaJugadores!=NULL){
		utn_getFlotante(&(listaJugadores+(*id))->salario,"\nINGRESE EL SALARIO DEL JUGADOR\n(MENOR A 100 MILLONES)\n","--ERROR--",1,99999999);
		retorno=0;
	}
	return retorno;
}
int modificarAnioContratoJugador(eJugador* listaJugadores,int* id)
{
	int retorno=-1;
	if(listaJugadores!=NULL){
		utn_getEnteroShort(&(listaJugadores+(*id))->aniosContrato,"\nINGRESE LOS AÑOS DE CONTRATO DEL JUGADOR\n(MAYOR A 1 Y MENOR A 10)\n","--ERROR--",1,9);
		retorno=0;
	}
	return retorno;
}
int bajaDeJugador(eJugador* listaJugadores,int* id,int estado)
{
    int retorno = -1,baja;
	if(listaJugadores != NULL){
		baja=continuarCarga("\nCONFIRME BAJA DEL ARTICULO\n");
		if(baja=='S'){
			(*(listaJugadores+(*id))).isEmpty=estado;
		}else if(baja=='N'){
			printf("\nBAJA CANCELADA\n");
		}
		retorno = 0;
	}
	return retorno;
}
int condicionOrdenarId(eJugador* primerId, eJugador* segundoId)
{
	int retorno=-1;
	if(primerId!=NULL&&segundoId!=NULL){
		if((*(primerId)).id>(*(primerId+1)).id){
			retorno=0;
		}
	}
	return retorno;
}
int ordenadorPorDobleCriterio(eJugador* listaJugadores,int cantidad,int estado, int(*primerCriterio)(eJugador*, eJugador*),int(*segundoCriterio)(eJugador*, eJugador*))
{
	int retorno=-1,bandera;
	eJugador auxiliar;
	if(listaJugadores!=NULL){
		do{
			bandera=1;
			for(int i=0;i<cantidad-1;i++){
				for(int j=i+1;j<cantidad;j++){
					if((listaJugadores+i)->isEmpty==estado){
						if(primerCriterio((listaJugadores+i),(listaJugadores+i))==0){
							bandera=0;
							auxiliar=(*(listaJugadores+i));
							(*(listaJugadores+i))=(*(listaJugadores+j));
							(*(listaJugadores+j))=auxiliar;
						}else if(primerCriterio((listaJugadores+i),(listaJugadores+i))==1){
							if(segundoCriterio((listaJugadores+i),(listaJugadores+i))==0){
								bandera=0;
								auxiliar=(*(listaJugadores+i));
								(*(listaJugadores+i))=(*(listaJugadores+j));
								(*(listaJugadores+j))=auxiliar;
							}
						}
					}
				}
				retorno=0;
			}
		}while(bandera!=1);
	}
	return retorno;
}
int ordenarPorId(eJugador* listaJugadores,int cantidadJugadores,int estado)
{
	int retorno=-1,(*primerCriterio)(eJugador*, eJugador*),(*segundoCriterio)(eJugador*, eJugador*);
		if(listaJugadores!=NULL){
			primerCriterio=condicionOrdenarId;
			segundoCriterio=condicionOrdenarId;
			if(ordenadorPorDobleCriterio(listaJugadores,cantidadJugadores,estado,primerCriterio,segundoCriterio)==0)
			retorno=0;
		}
	return retorno;
}
int funcionQueCargaUnJugador(eJugador* listaJugadores,int cantidadJugadores,int estado,
		eConfederacion* listaConfederaciones,int cantidadConfederacion,int* idJugador)
{
	int retorno=-1,espacioVacio;
	char confirmarSalidaAlta;
	if(listaJugadores!=NULL && listaConfederaciones!=NULL){
		do{
			if(ordenarPorId(listaJugadores,cantidadJugadores,estado)==0)
			espacioVacio=buscarEspacioLibreIdJugadores(listaJugadores,cantidadJugadores,0);
			(*(listaJugadores+espacioVacio))=cargaJugador(&(*idJugador),estado,listaConfederaciones,cantidadConfederacion);
			if(mostrarJugadores(listaJugadores,cantidadJugadores,estado,listaConfederaciones)==0)
			confirmarSalidaAlta=continuarCarga("\n¿CARGAR EL SIGUIENTE JUGADOR?");
		}while(confirmarSalidaAlta!='N');
		retorno=0;
	}
	return retorno;
}
int funcionDeBajaDeJugador(eJugador* listaJugadores,int cantidadJugadores,int estado,
		eConfederacion* listaConfederaciones)
{
	int retorno=-1,id;
	char confirmarSalidaAlta;
	if(listaJugadores!=NULL && listaConfederaciones!=NULL){
		do{
			if(validarQueHayaJugadores(listaJugadores,cantidadJugadores,estado)==0){
				if(mostrarJugadores(listaJugadores,cantidadJugadores,estado,listaConfederaciones)==0){}
				if(ingresarIdParaModificar(listaJugadores,cantidadJugadores,&id,estado)==0){}
				if(bajaDeJugador(listaJugadores,&id,0)==0){}
			}else{
				printf("\nNO HAY JUGADORES CARGADOS EN EL SISTEMA\n");
			}
			confirmarSalidaAlta=continuarCarga("\n¿DAR DE BAJA OTRO JUGADOR?");
		}while(confirmarSalidaAlta!='N');
	retorno=0;
	}
	return retorno;
}
int funcionQueContieneModificaciones(eJugador* listaJugadores,int cantidadJugadores,int estado,
		eConfederacion* listaConfederaciones,int cantidadConfederacion)
{
	int retorno=-1,id,submenu;
	char confirmarSalidaAlta,volverAlMenu;
	if(listaJugadores!=NULL && listaConfederaciones!=NULL){
		do{
			submenu=menuModificar();
			if(ordenarPorId(listaJugadores,cantidadJugadores,estado)==0)
			switch(submenu){
			case 1:
				do{
					if(mostrarJugadores(listaJugadores,cantidadJugadores,estado,listaConfederaciones)==0)
					if(ingresarIdParaModificar(listaJugadores,cantidadJugadores,&id,estado)==0)
					if(modificarNombreJugador(listaJugadores,&id)==0)
					if(mostrarJugadores(listaJugadores,cantidadJugadores,estado,listaConfederaciones)==0)
					confirmarSalidaAlta=continuarCarga("\n¿MODIFICAR OTRO JUGADOR?");
				}while(confirmarSalidaAlta!='N');
				break;
			case 2:
				do{
					if(mostrarJugadores(listaJugadores,cantidadJugadores,estado,listaConfederaciones)==0)
					if(ingresarIdParaModificar(listaJugadores,cantidadJugadores,&id,estado)==0)
					if(modificarPosicionJugador(listaJugadores,&id)==0)
					if(mostrarJugadores(listaJugadores,cantidadJugadores,estado,listaConfederaciones)==0)
					confirmarSalidaAlta=continuarCarga("\n¿MODIFICAR OTRO JUGADOR?");
				}while(confirmarSalidaAlta!='N');
				break;
			case 3:
				do{
					if(mostrarJugadores(listaJugadores,cantidadJugadores,estado,listaConfederaciones)==0)
					if(ingresarIdParaModificar(listaJugadores,cantidadJugadores,&id,estado)==0)
					if(modificarCamisetaJugador(listaJugadores,&id)==0)
					if(mostrarJugadores(listaJugadores,cantidadJugadores,estado,listaConfederaciones)==0)
					confirmarSalidaAlta=continuarCarga("\n¿MODIFICAR OTRO JUGADOR?");
				}while(confirmarSalidaAlta!='N');
				break;
			case 4:
				do{
					if(mostrarJugadores(listaJugadores,cantidadJugadores,estado,listaConfederaciones)==0)
					if(ingresarIdParaModificar(listaJugadores,cantidadJugadores,&id,estado)==0)
					if(modificarConfederacionJugador(listaJugadores,&id,listaConfederaciones,cantidadConfederacion)==0)
					if(mostrarJugadores(listaJugadores,cantidadJugadores,estado,listaConfederaciones)==0)
					confirmarSalidaAlta=continuarCarga("\n¿MODIFICAR OTRO JUGADOR?");
				}while(confirmarSalidaAlta!='N');
				break;
			case 5:
				do{
					if(mostrarJugadores(listaJugadores,cantidadJugadores,estado,listaConfederaciones)==0)
					if(ingresarIdParaModificar(listaJugadores,cantidadJugadores,&id,estado)==0)
					if(modificarSalarioJugador(listaJugadores,&id)==0)
					if(mostrarJugadores(listaJugadores,cantidadJugadores,estado,listaConfederaciones)==0)
					confirmarSalidaAlta=continuarCarga("\n¿MODIFICAR OTRO JUGADOR?");
				}while(confirmarSalidaAlta!='N');
				break;
			case 6:
				do{
					if(mostrarJugadores(listaJugadores,cantidadJugadores,estado,listaConfederaciones)==0)
					if(ingresarIdParaModificar(listaJugadores,cantidadJugadores,&id,estado)==0)
					if(modificarAnioContratoJugador(listaJugadores,&id)==0)
					if(mostrarJugadores(listaJugadores,cantidadJugadores,estado,listaConfederaciones)==0)
					confirmarSalidaAlta=continuarCarga("\n¿MODIFICAR OTRO JUGADOR?");
				}while(confirmarSalidaAlta!='N');
				break;
			case 7:
				volverAlMenu=continuarCarga("\nCONFIRME VOLVER AL MENU PRINCIPAL DEL SISTEMA");
				break;
			}
		}while(volverAlMenu!='S');
		retorno=0;
	}
	return retorno;
}
