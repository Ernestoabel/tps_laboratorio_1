#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"
/**
 * @brief getter que recibe el campo id de la estructura Seleccion
 *
 * @param this estructura para recivir el getter
 * @param id campo a recivir el getter
 * @return int para validar que la funcion realizo su cometido
 */
int selec_getId(Seleccion* this,int* id)
{
	int retorno=-1;
	if(this!=NULL){
		*id=this->id;
		retorno=0;
	}
	return retorno;
}
/**
 * @brief getter que recibe el campo pais de la estructura Seleccion
 *
 * @param this estructura para recivir el getter
 * @param pais campo a recivir el getter
 * @return int para validar que la funcion realizo su cometido
 */
int selec_getPais(Seleccion* this,char* pais)
{
	int retorno=-1;
	if(this!=NULL){
		strcpy(pais,this->pais);
		retorno=0;
	}
	return retorno;
}
/**
 * @brief getter que recibe el campo confederacion de la estructura Seleccion
 *
 * @param this estructura para recivir el getter
 * @param confederacion campo a recivir el getter
 * @return int para validar que la funcion realizo su cometido
 */
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno=-1;
	if(this!=NULL){
		strcpy(confederacion,this->confederacion);
		retorno=0;
	}
	return retorno;
}
/**
 * @brief setter del campo convocados de la estructura Seleccion
 *
 * @param this estructura a settear
 * @param convocados campo a settear
 * @return int para validar que la funcion realizo su cometido
 */
int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno=-1;
	if(this!=NULL){
		this->convocados=convocados;
		retorno=0;
	}
	return retorno;
}
/**
 * @brief getter que recibe el campo convocados de la estructura Seleccion
 *
 * @param this estructura para recivir el getter
 * @param convocados campo a recivir el getter
 * @return int para validar que la funcion realizo su cometido
 */
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno=-1;
	if(this!=NULL){
		*convocados=this->convocados;
		retorno=0;
	}
	return retorno;
}
/**
 * @brief constructor que reserva e inicializa una estructura Seleccion
 *
 * @return la estructura inicializada
 */
Seleccion* selec_new()
{
	return (Seleccion*) calloc(1,sizeof(Seleccion));
}
/**
 * @brief destructor de la estructura Seleccion
 *
 * @param this estructura Seleccion a liberar de memoria
 */
void selec_delete(Seleccion* this)
{
	free(this);
}
/**
 * @brief constructor que recibe valores de los campor por parametro para ser devuelta
 * por return como estructura
 *
 * @param idStr campo id de la estructura Seleccion
 * @param paisStr campo pais de la estructura Seleccion
 * @param confederacionStr campo confederacion de la estructura Seleccion
 * @param convocadosStr campo convocados de la estructura Seleccion
 * @return una estructura con valores en todos sus campos
 */
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* unaSeleccion;
	unaSeleccion=selec_new();
	if(unaSeleccion !=NULL){
		unaSeleccion->id=atoi(idStr);
		strcpy(unaSeleccion->pais,paisStr);
		strcpy(unaSeleccion->confederacion,confederacionStr);
		unaSeleccion->convocados=atoi(convocadosStr);
	}
	return unaSeleccion;
}
/**
 * @brief funcion para imprimir la situciaon del jugador ante la convocatoria
 *
 * @param idSeleccion valor recivido para ser condicionado
 * @param mensaje string devuelto para mostrar la condicion del jugador
 * @return int para validar que la funcion realizo su cometido
 */
int validarConvocados(int idSeleccion,char* mensaje)
{
	int retorno=-1;
	if(idSeleccion==0){
		strcpy(mensaje,"NO CONVOCADO");
		retorno=0;
	}else{
		strcpy(mensaje,"ESTA CONVOCADO");
		retorno=0;
	}
	return retorno;
}
/**
 * @brief Funcion utiliza para la validacion en la convocatoria de una seleccion, solo puede ser
 * convocado si es de la nacionalidad de la seleccion
 *
 * @param pArrayListSeleccion LinkedList de selecciones para ser validados
 * @param idSeleccion valor para ser condicionado
 * @param pMensaje string devuelto por referencia
 * @param indice entero devuelto por referencia
 * @return int para validar que la funcion realizo su cometido
 */
int validarNacionalidadParaConvocados(LinkedList* pArrayListSeleccion,int idSeleccion,char* pMensaje,int* indice)
{
	char mensaje[51];
	int i,cantidad,id,retorno;
	Seleccion* unaSeleccion;
	unaSeleccion=selec_new();
	if(pArrayListSeleccion!=NULL && unaSeleccion!=NULL){
		cantidad=ll_len(pArrayListSeleccion);
		for(i=0;i<cantidad;i++){
			unaSeleccion= (Seleccion*) ll_get(pArrayListSeleccion,i);
			selec_getId(unaSeleccion,&id);
			if(id==idSeleccion){
				*indice=i;
				retorno=0;
			}
		}
		if(idSeleccion==3){
			strcpy(mensaje,"Argentino");
		}
		if(idSeleccion==6){
			strcpy(mensaje,"Brasilero");
		}
		if(idSeleccion==32){
			strcpy(mensaje,"Uruguayo");
		}
		if(idSeleccion==26){
			strcpy(mensaje,"Portugues");
		}
		if(idSeleccion==20){
			strcpy(mensaje,"Ingles");
		}
		if(idSeleccion==1){
			strcpy(mensaje,"Aleman");
		}
		if(idSeleccion==24){
			strcpy(mensaje,"Mexicano");
		}
		if(idSeleccion==15){
			strcpy(mensaje,"Estado Unidense");
		}
		if(idSeleccion==7){
			strcpy(mensaje,"Camerunes");
		}
		if(idSeleccion==28){
			strcpy(mensaje,"Senegales");
		}
		if(idSeleccion==4){
			strcpy(mensaje,"Australiano");
		}
		if(idSeleccion==27){
			strcpy(mensaje,"Qatari");
		}
		if(idSeleccion==2){
			strcpy(mensaje,"Saudita");
		}
		if(idSeleccion==9){
			strcpy(mensaje,"Coreano del sur");
		}
		if(idSeleccion==21){
			strcpy(mensaje,"Irani");
		}
		if(idSeleccion==22){
			strcpy(mensaje,"Japones");
		}
		if(idSeleccion==18){
			strcpy(mensaje,"Ghanes");
		}
		if(idSeleccion==23){
			strcpy(mensaje,"Marroqui");
		}
		if(idSeleccion==31){
			strcpy(mensaje,"Tunecino");
		}
		if(idSeleccion==8){
			strcpy(mensaje,"Canadiense");
		}
		if(idSeleccion==10){
			strcpy(mensaje,"Costarricense");
		}
		if(idSeleccion==13){
			strcpy(mensaje,"Ecuatoriano");
		}
		if(idSeleccion==5){
			strcpy(mensaje,"Belga");
		}
		if(idSeleccion==11){
			strcpy(mensaje,"Croata");
		}
		if(idSeleccion==12){
			strcpy(mensaje,"Danes");
		}
		if(idSeleccion==14){
			strcpy(mensaje,"Espaniol");
		}
		if(idSeleccion==16){
			strcpy(mensaje,"Frances");
		}
		if(idSeleccion==17){
			strcpy(mensaje,"Gales");
		}
		if(idSeleccion==19){
			strcpy(mensaje,"Holandes");
		}
		if(idSeleccion==25){
			strcpy(mensaje,"Polaco");
		}
		if(idSeleccion==30){
			strcpy(mensaje,"Suizo");
		}
		if(idSeleccion==29){
			strcpy(mensaje,"Serbio");
		}
		strcpy(pMensaje,mensaje);
	}
	return retorno;
}
/**
 * @brief funcion para validad la confederacion ingresada por el usuario
 *
 * @param confederacion entero devuelto por referencia
 * @param mensaje string recivido para ser condicionado
 * @return int para validar que la funcion realizo su cometido
 */
int validarConfederacion(int* confederacion,char* mensaje)
{
	int retorno=-1;
	if(strcmp(mensaje,"AFC")==0){
		*confederacion=1;
		retorno=0;
	}else if(strcmp(mensaje,"CAF")==0){
		*confederacion=2;
		retorno=0;
	}else if(strcmp(mensaje,"CONCACAF")==0){
		*confederacion=3;
		retorno=0;
	}else if(strcmp(mensaje,"CONMNEBOL")==0){
		*confederacion=4;
		retorno=0;
	}else if(strcmp(mensaje,"UEFA")==0){
		*confederacion=5;
		retorno=0;
	}
	return retorno;
}
/**
 * @brief Funcion para la condicion de un ordenamiento por confederacion
 *
 * @param unaSeleccion puntero a void que recive el elemento a ordenar
 * @param auxSeleccion puntero a void que recive el elemento auxiliar a ordenar
 * @return int para validar que la funcion realizo su cometido
 */
int ordenarSeleccionPorConfederacion(void* unaSeleccion, void* auxSeleccion)
{
    int retorno=0;
    char primeraConfederacion[51],segundaConfederacion[51];
    if(unaSeleccion!=NULL && auxSeleccion!=NULL){
    	selec_getConfederacion(unaSeleccion,primeraConfederacion);
    	selec_getConfederacion(auxSeleccion,segundaConfederacion);
        if(strcmp(primeraConfederacion,segundaConfederacion)>0){
            retorno=1;
        }else if(strcmp(primeraConfederacion,segundaConfederacion)>0){
        	retorno=-1;
        }
    }
    return retorno;
}
