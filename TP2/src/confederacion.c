#include <stdio.h>
#include <stdlib.h>
#include "confederacion.h"
#include "biblioteca_UTN.h"
#include "salidaDeDatos.h"

int inicializarConfederaciones(eConfederacion* listaConfederacion,int cantidadConfederacion)
{
	int retorno=-1,i;
	if(listaConfederacion != NULL && cantidadConfederacion > 0 ){
		for(i = 0; i<cantidadConfederacion; i++){
			(*(listaConfederacion+i)).id = 0;
		}
		retorno = 0;
	}
	return retorno;
}
int buscarEspacioLibreIdConfederaciones(eConfederacion* listaConfederacion,int cantidadConfederacion)
{
    int retorno=-1;
    int i;
    if(listaConfederacion!=NULL){
    	for(i=0;i<cantidadConfederacion;i++){
    		if((*(listaConfederacion+i)).id==0){
    			retorno = i;
    			break;
    		}
        }
    }
    return retorno;
}
eConfederacion cargaConfederacion(int* id,int cantidadConfederacion)
{
	eConfederacion cargaUnaConfederacion;
	if(id != NULL){
		do{
			if(utn_getCadenaCaracteres(50,cargaUnaConfederacion.nombre,"\nINGRESE EL NOMBRE DE LA CONFEDERACION\n","--ERROR--")==0){}
		}while(utn_cadenaSoloLetra(cargaUnaConfederacion.nombre)!=1);
		do{
			if(utn_getCadenaCaracteres(50,cargaUnaConfederacion.region,"\nINGRESE LA REGION DE LA CONFEDERACION\n","--ERROR--")==0){}
		}while(utn_cadenaSoloLetra(cargaUnaConfederacion.region)!=1);
		if(utn_getEntero(&cargaUnaConfederacion.anioCreacion,"\nINGRESE EL AÑO DE CREACION DE LA CONFEDERACION\n","--ERROR--",100,105)==0){}
		cargaUnaConfederacion.id = *id;
		(*id)++;
	}
	return cargaUnaConfederacion;
}
int ingresarIdParaModificarConfederacion(eConfederacion* listaConfederacion,int cantidadConfederacion,int* id)
{
    int i,retorno=-1,entro=0;
    if(listaConfederacion!=NULL){
        do{
        	retorno=0;
        	utn_getEntero(id,"\nINGRESE ID\n","\n--ERROR--\n",1,3000);
            for(i=0;i<cantidadConfederacion;i++){
                if((*(listaConfederacion+i)).id>0){
                    if((*(listaConfederacion+i)).id==(*id)){
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
int modificarNombreConfederacion(eConfederacion* listaConfederacion,int* id)
{
	int retorno=-1;
	if(listaConfederacion!=NULL){
		do{
			if(utn_getCadenaCaracteres(50,listaConfederacion->nombre,"\nINGRESE EL NOMBRE DE LA CONFEDERACION\n","--ERROR--")==0){}
		}while(utn_cadenaSoloLetra(listaConfederacion->nombre)!=1);
		retorno=0;
	}
	return retorno;
}
int modificarRegionConfederacion(eConfederacion* listaConfederacion,int* id)
{
	int retorno=-1;
	if(listaConfederacion!=NULL){
		do{
			if(utn_getCadenaCaracteres(50,listaConfederacion->region,"\nINGRESE LA REGION DE LA CONFEDERACION\n","--ERROR--")==0){}
		}while(utn_cadenaSoloLetra(listaConfederacion->region)!=1);
		retorno=0;
	}
	return retorno;
}
int modificarAnioCreacionConfederacion(eConfederacion* listaConfederacion,int* id)
{
	int retorno=-1;
	if(listaConfederacion!=NULL){
		if(utn_getEntero(&listaConfederacion->anioCreacion,"\nINGRESE EL AÑO DE CREACION DE LA CONFEDERACION\n","--ERROR--",100,105)==0){}
		retorno=0;
	}
	return retorno;
}
int bajaDeConfederacion(eConfederacion* listaConfederacion,int* id)
{
    int retorno = -1,baja;
	if(listaConfederacion != NULL){
		baja=continuarCarga("\nCONFIRME BAJA DEL ARTICULO\n");
		if(baja=='S'){
			(*(listaConfederacion+(*id))).id=0;
		}else if(baja=='N'){
			printf("\nBAJA CANCELADA\n");
		}
		retorno = 0;
	}
	return retorno;
}
