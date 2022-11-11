#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "biblioteca_UTN.h"
#include "salidaDeDatos.h"

/**
 * @brief setter del campo id de la estructura Jugador
 *
 * @param this estructura a settear
 * @param id campo a settear
 * @return int para validar que la funcion realizo su cometido
 */
int jug_setId(Jugador* this,int id)
{
	int retorno=-1;
	if(this!=NULL){
		this->id=id;
		retorno=0;
	}
	return retorno;
}
/**
 * @brief getter que recibe el campo id de la estructura Jugador
 *
 * @param this estructura para recivir el getter
 * @param id campo a recivir el getter
 * @return int para validar que la funcion realizo su cometido
 */
int jug_getId(Jugador* this,int* id)
{
	int retorno=-1;
	if(this!=NULL){
		*id=this->id;
		retorno=0;
	}
	return retorno;
}
/**
 * @brief setter del campo nombreCompleto de la estructura Jugador
 *
 * @param this estructura a settear
 * @param nombreCompleto campo a settear
 * @return int para validar que la funcion realizo su cometido
 */
int jug_setNombreCompleto(Jugador*  this,char* nombreCompleto)
{
	int retorno=-1;
		if(this!=NULL){
			strcpy(this->nombreCompleto,nombreCompleto);
			retorno=0;
		}
	return retorno;
}
/**
 * @brief getter que recibe el campo nombreCompleto de la estructura Jugador
 *
 * @param this estructura para recivir el getter
 * @param nombreCompleto campo a recivir el getter
 * @return int para validar que la funcion realizo su cometido
 */
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno=-1;
	if(this!=NULL){
		strcpy(nombreCompleto,this->nombreCompleto);
		retorno=0;
	}
	return retorno;
}
/**
 * @brief setter del campo posicion de la estructura Jugador
 *
 * @param this estructura a settear
 * @param posicion campo a settear
 * @return int para validar que la funcion realizo su cometido
 */
int jug_setPosicion(Jugador*  this,char* posicion)
{
	int retorno=-1;
		if(this!=NULL){
			strcpy(this->posicion,posicion);
			retorno=0;
		}
	return retorno;
}
/**
 * @brief getter que recibe el campo posicion de la estructura Jugador
 *
 * @param this estructura para recivir el getter
 * @param posicion campo a recivir el getter
 * @return int para validar que la funcion realizo su cometido
 */
int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno=-1;
	if(this!=NULL){
		strcpy(posicion,this->posicion);
		retorno=0;
	}
	return retorno;
}
/**
 * @brief setter del campo nacionalidad de la estructura Jugador
 *
 * @param this estructura a settear
 * @param nacionalidad campo a settear
 * @return int para validar que la funcion realizo su cometido
 */
int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno=-1;
		if(this!=NULL){
			strcpy(this->nacionalidad,nacionalidad);
			retorno=0;
		}
	return retorno;
}
/**
 * @brief getter que recibe el campo nacionalidad de la estructura Jugador
 *
 * @param this estructura para recivir el getter
 * @param nacionalidad campo a recivir el getter
 * @return int para validar que la funcion realizo su cometido
 */
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno=-1;
	if(this!=NULL){
		strcpy(nacionalidad,this->nacionalidad);
		retorno=0;
	}
	return retorno;
}
/**
 * @brief setter del campo nacionalidad de la estructura Jugador
 *
 * @param this estructura a settear
 * @param nacionalidad campo a settear
 * @return int para validar que la funcion realizo su cometido
 */
int jug_setEdad(Jugador* this,int edad)
{
	int retorno=-1;
	if(this!=NULL){
		this->edad=edad;
		retorno=0;
	}
	return retorno;
}
/**
 * @brief getter que recibe el campo edad de la estructura Jugador
 *
 * @param this estructura para recivir el getter
 * @param edad campo a recivir el getter
 * @return int para validar que la funcion realizo su cometido
 */
int jug_getEdad(Jugador* this,int* edad)
{
	int retorno=-1;
	if(this!=NULL){
		*edad=this->edad;
		retorno=0;
	}
	return retorno;
}
/**
 * @brief setter del campo idSeleccion de la estructura Jugador
 *
 * @param this estructura a settear
 * @param idSeleccion campo a settear
 * @return int para validar que la funcion realizo su cometido
 */
int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno=-1;
	if(this!=NULL){
		this->idSeleccion=idSeleccion;
		retorno=0;
	}
	return retorno;
}
/**
 * @brief getter que recibe el campo idSeleccion de la estructura Jugador
 *
 * @param this estructura para recivir el getter
 * @param idSeleccion campo a recivir el getter
 * @return int para validar que la funcion realizo su cometido
 */
int jug_getIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno=-1;
	if(this!=NULL){
		*idSeleccion=this->idSeleccion;
		retorno=0;
	}
	return retorno;
}
/**
 * @brief constructor que reserva e inicializa una estructura Jugador
 *
 * @return la estructura inicializada
 */
Jugador* jug_new()
{
	return (Jugador*) calloc(1,sizeof(Jugador));
}
/**
 * @brief destructor de la estructura Jugador
 *
 * @param this estructura Jugador a liberar de memoria
 */
void jug_delete(Jugador* this)
{
	free(this);
}
/**
 * @brief constructor que recibe valores de los campor por parametro para ser devuelta
 * por return como estructura
 *
 * @param idStr campo id de la estructura Jugador
 * @param nombreCompletoStr campo nombreCompleto de la estructura Jugador
 * @param edadStr campo edad de la estructura Jugador
 * @param posicionStr campo posicion de la estructura Jugador
 * @param nacionalidadStr campo nacionalidad de la estructura Jugador
 * @param idSelccionStr campo idDeSeleccion de la estructura Jugador
 * @return estructura Jugadores con valores en todos sus campos
 */
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr,
		char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* unJugador;
	unJugador=jug_new();
	if(unJugador !=NULL){
		if(jug_setId(unJugador,atoi(idStr))!=0 ||
		jug_setNombreCompleto(unJugador,nombreCompletoStr)!=0 ||
		jug_setEdad(unJugador,atoi(edadStr))!=0 ||
		jug_setPosicion(unJugador,posicionStr)!=0 ||
		jug_setNacionalidad(unJugador,nacionalidadStr)!=0 ||
		jug_setIdSeleccion(unJugador,atoi(idSelccionStr))!=0){
			jug_delete(unJugador);
			unJugador=NULL;
		}
	}
	return unJugador;
}
/**
 * @brief funcion que se encarga de buscar el idMaximo y devolverlo por pàrametro
 *
 * @param pArrayListJugador lista de jugadores para ser recorrida
 * @param idMaximo puntero para ser devuelto por referencia
 * @return int para validar que la funcion realizo su cometido
 */
int buscarIdMaximo(LinkedList* pArrayListJugador,int* idMaximo)
{
	int retorno=-1,tam;
	Jugador* unJugador;
	if(pArrayListJugador!=NULL){
		tam= ll_len(pArrayListJugador);
		for(int i=0;i<tam;i++){
			unJugador=ll_get(pArrayListJugador, i);
			jug_getId(unJugador,*&idMaximo);
			retorno=0;
		}
	}
	return retorno;
}
/**
 * @brief funcion que se encarga de devolver la posicion en la linkedlist,
 *  de un id en particular
 *
 * @param pArrayListJugador lista de jugadores a ser recorrida
 * @param idBuscado valor del id a ser buscado
 * @param indice puntero para ser devuelto por referencia
 * @return int para validar que la funcion realizo su cometido
 */
int buscarJugPorId(LinkedList* pArrayListJugador, int idBuscado, int* indice)
{
	int retorno=-1,tam;
	Jugador* unJugador;
	if(pArrayListJugador!=NULL){
		tam= ll_len(pArrayListJugador);
		for(int i=0;i<tam;i++){
			unJugador=ll_get(pArrayListJugador, i);
			if((*(unJugador)).id==idBuscado){
				*indice=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * @brief funcion para validar la posicion ingresada por el usuario
 *
 * @param posicionIngresada string a ser comparado
 * @return int para validar que la funcion realizo su cometido
 */
int validarPosicion(char* posicionIngresada)
{
	int retorno=-1;
	if(strcmp(posicionIngresada,"Portero")==0 || strcmp(posicionIngresada,"Defensa central")==0 ||
	strcmp(posicionIngresada,"Lateral izquiero")==0 || strcmp(posicionIngresada,"Lateral derecho")==0 ||
	strcmp(posicionIngresada,"Pivote")==0 || strcmp(posicionIngresada,"Mediocentro")==0 ||
	strcmp(posicionIngresada,"Extremo izquierdo")==0 || strcmp(posicionIngresada,"Extremo derecho")==0 ||
	strcmp(posicionIngresada,"Mediapunta")==0 || strcmp(posicionIngresada,"Delantero centro")==0 ){
		retorno=0;
	}else{
		printf("\nINGRESE UNA POSICION VALIDA\n");
	}
	return retorno;
}
/**
 * @brief funcion para validar la nacionalidad ingresada por el usuario
 *
 * @param nacionalidadIngresada string a ser comparado
 * @return int para validar que la funcion realizo su cometido
 */
int validarNacionalidad(char* nacionalidadIngresada)
{
	int retorno=-1;
	if(strcmp(nacionalidadIngresada,"Argentino")==0 || strcmp(nacionalidadIngresada,"Brasilero")==0 ||
	strcmp(nacionalidadIngresada,"Uruguayo")==0 || strcmp(nacionalidadIngresada,"Portugues")==0 ||
	strcmp(nacionalidadIngresada,"Ingles")==0 || strcmp(nacionalidadIngresada,"Aleman")==0 ||
	strcmp(nacionalidadIngresada,"Mexicano")==0 || strcmp(nacionalidadIngresada,"Estado Unidense")==0 ||
	strcmp(nacionalidadIngresada,"Camerunes")==0 || strcmp(nacionalidadIngresada,"Senegales")==0 ||
	strcmp(nacionalidadIngresada,"Australiano")==0 || strcmp(nacionalidadIngresada,"Qatari")==0 ||
	strcmp(nacionalidadIngresada,"Saudita")==0 || strcmp(nacionalidadIngresada,"Coreano del sur")==0 ||
	strcmp(nacionalidadIngresada,"Irani")==0 || strcmp(nacionalidadIngresada,"Japones")==0 ||
	strcmp(nacionalidadIngresada,"Ghanes")==0 || strcmp(nacionalidadIngresada,"Marroqui")==0 ||
	strcmp(nacionalidadIngresada,"Tunecino")==0 || strcmp(nacionalidadIngresada,"Canadiense")==0 ||
	strcmp(nacionalidadIngresada,"Costarricense")==0 || strcmp(nacionalidadIngresada,"Ecuatoriano")==0 ||
	strcmp(nacionalidadIngresada,"Belga")==0 || strcmp(nacionalidadIngresada,"Croata")==0 ||
	strcmp(nacionalidadIngresada,"Danes")==0 || strcmp(nacionalidadIngresada,"Espaniol")==0 ||
	strcmp(nacionalidadIngresada,"Frances")==0 || strcmp(nacionalidadIngresada,"Gales")==0 ||
	strcmp(nacionalidadIngresada,"Holandes")==0 || strcmp(nacionalidadIngresada,"Polaco")==0 ||
	strcmp(nacionalidadIngresada,"Suizo")==0 || strcmp(nacionalidadIngresada,"Serbio")==0){
		retorno=0;
	}else{
		printf("\nINGRESE UNA NACIONALIDAD VALIDA\n");

	}
	return retorno;
}
/**
 * @brief constructor que pide los datos, para los campos de la estructura Jugador,
 * al usuario.
 *
 * @param idStr id de jugador para ser recibido y aumentado en uno por cada carga
 * @return estructura Jugador con valores en todos sus campos
 */
Jugador* jug_newParametrosAlta(int* idStr)
{
	Jugador* unJugador;
	int edadStr;
	char nombreCompletoStr[51],posicionStr[51],nacionalidadStr[51];
	unJugador=jug_new();
	if(unJugador !=NULL){
		utn_getCadenaCaracteres(51,nombreCompletoStr,"\nINGRESE EL NOMBRE COMPLETO DEL JUGADOR\n","\n--ERROR--\n");
		utn_getEntero(&edadStr,"\nINGRESE LA EDAD DEL JUGADOR (ENTRE 14 Y 50)\n","\n--ERROR--\n",14,50);
		do{
			opcionesDePosicion();
			utn_getCadenaCaracteres(51,posicionStr,"\nINGRESE LA POSICION DEL JUGADOR\n","--ERROR--");
		}while(validarPosicion(posicionStr)!=0);
		do{
			opcionesDeNacionalidad();
			utn_getCadenaCaracteres(51,nacionalidadStr,"\nINGRESE LA NACIONALIDAD DEL JUGADOR\n","--ERROR--");
		}while(validarNacionalidad(nacionalidadStr)!=0);
		if(jug_setId(unJugador,*idStr)!=0 ||
		jug_setNombreCompleto(unJugador,nombreCompletoStr)!=0 ||
		jug_setEdad(unJugador,edadStr)!=0 ||
		jug_setPosicion(unJugador,posicionStr)!=0 ||
		jug_setNacionalidad(unJugador,nacionalidadStr)!=0 ||
		jug_setIdSeleccion(unJugador,0)!=0){
			jug_delete(unJugador);
			unJugador=NULL;
		}
	}
	return unJugador;
}
/**
 * @brief Funcion para validar un id al momento de realizar una convocatoria
 *
 * @param pArrayListJugador LinkedList de jugadores para ser analizada
 * @param idJugador recivido para ser validado
 * @param mensaje nacionalidad recivida para ser validada ante una convocatoria
 * @param indice puntero para ser devuelto por referencia
 * @return int para validar que la funcion realizo su cometido
 */
int validarIdDeConvocados(LinkedList* pArrayListJugador,int idJugador,char* mensaje,int* indice)
{
	int retorno=-1,cantidad,i,id;
	char nacionalidad[51];
	Jugador* unJugador;
	unJugador=jug_new();
	if(pArrayListJugador!=NULL && unJugador!=NULL){
		cantidad=ll_len(pArrayListJugador);
		for(i=0;i<cantidad;i++){
			unJugador= (Jugador*) ll_get(pArrayListJugador,i);
			jug_getNacionalidad(unJugador,nacionalidad);
			jug_getId(unJugador,&id);
			if(strcmp(mensaje,nacionalidad)==0){
				if(idJugador==id){
					*indice=i;
					retorno=0;
					break;
				}
			}
		}
	}
	return retorno;
}
/**
 * @brief Funcion para la condicion de un ordenamiento por nombre
 *
 * @param unJugador puntero a void que recive el elemento a ordenar
 * @param auxJugador puntero a void que recive el elemento auxiliar a ordenar
 * @return int para validar que la funcion realizo su cometido
 */
int ordenarPorNombreJugador(void* unJugador, void* auxJugador)
{
    int retorno=0;
    char primerNombre[51],segundoNombre[51];
    if(unJugador!=NULL && auxJugador!=NULL){
    	jug_getNombreCompleto(unJugador,primerNombre);
		jug_getNombreCompleto(auxJugador,segundoNombre);
        if(stricmp(primerNombre,segundoNombre)>0){
            retorno=1;
        }else if(stricmp(primerNombre,segundoNombre)<0){
        	retorno=-1;
        }
    }
    return retorno;
}
/**
 * @brief Funcion para la condicion de un ordenamiento por nacionalidad
 *
 * @param unJugador puntero a void que recive el elemento a ordenar
 * @param auxJugador puntero a void que recive el elemento auxiliar a ordenar
 * @return int para validar que la funcion realizo su cometido
 */
int ordenarPorNacionalidadJugador(void* unJugador, void* auxJugador)
{
    int retorno=0;
    char primeraNacionalidad[51],segundaNacionalidad[51];
    if(unJugador!=NULL && auxJugador!=NULL){
    	jug_getNacionalidad(unJugador,primeraNacionalidad);
    	jug_getNacionalidad(auxJugador,segundaNacionalidad);
        if(strcmp(primeraNacionalidad,segundaNacionalidad)>0){
            retorno=1;
        }else if(strcmp(primeraNacionalidad,segundaNacionalidad)<0){
        	retorno=-1;
        }
    }
    return retorno;
}
/**
 * @brief Funcion para la condicion de un ordenamiento por edad
 *
 * @param unJugador puntero a void que recive el elemento a ordenar
 * @param auxJugador puntero a void que recive el elemento auxiliar a ordenar
 * @return int para validar que la funcion realizo su cometido
 */
int ordenarPorEdadJugador(void* unJugador, void* auxJugador)
{
    int retorno=0,primerEdad,segundaEdad;
    if(unJugador!=NULL && auxJugador!=NULL){
    	jug_getEdad(unJugador,&primerEdad);
    	jug_getEdad(auxJugador,&segundaEdad);
        if(primerEdad>segundaEdad){
            retorno=1;
        }else if(primerEdad<segundaEdad){
        	retorno=-1;
        }
    }
    return retorno;
}
/**
 * @brief Funcion para la condicion de un ordenamiento por id
 *
 * @param unJugador puntero a void que recive el elemento a ordenar
 * @param auxJugador puntero a void que recive el elemento auxiliar a ordenar
 * @return int para validar que la funcion realizo su cometido
 */
int ordenarPorIdJugador(void* unJugador, void* auxJugador)
{
    int retorno=0,primerId,segundaId;
    if(unJugador!=NULL && auxJugador!=NULL){
    	jug_getId(unJugador,&primerId);
    	jug_getId(auxJugador,&segundaId);
        if(primerId>segundaId){
            retorno=1;
        }else if(primerId<segundaId){
        	retorno=-1;
        }
    }
    return retorno;
}
