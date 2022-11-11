#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "salidaDeDatos.h"
#include "biblioteca_UTN.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char* recive el archivo a cargar
 * \param pArrayListJugador LinkedList* con la lista de jugadores a ser cargada
 * \return int para validar si la funcion realizo su comedito
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	FILE* pJugadoresFile=fopen(path,"r");
	int retorno=-1;
	if(pJugadoresFile!=NULL){
		if(parser_JugadorFromText(pJugadoresFile ,pArrayListJugador)==0){
			printf("\nARCHIVO %s LEIDO CORECTAMENTE\n",path);
			retorno=0;
		}else{
			printf("ERROR AL CARGAR EL ARCHIVO");
		}
	}
	fclose(pJugadoresFile);
    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char* recive el archivo a cargar
 * \param pArrayListJugador LinkedList* con la lista de jugadores convocados a ser cargada
 * \return int para validar si la funcion realizo su comedito
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	FILE* pJugadoresFile=fopen(path,"rb");
	int retorno=-1;
	if(pJugadoresFile!=NULL && pArrayListJugador!= NULL){
		parser_JugadorFromBinary(pJugadoresFile,pArrayListJugador);
		retorno=0;
	}
	fclose(pJugadoresFile);
	return retorno;
}

/** \brief Alta de jugadores funcion para agregar un jugador ingresado por el usuario
 * para ser sumado a la linkelist
 *
 * \param pArrayListJugador LinkedList* lista de jugadores para agregar los necesarios
 * \param int puntero que recibe un valor id para ser incrementado mientras se agrega un jugador
 * \return int para validar si la funcion realizo su comedito
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador,int* id)
{
	Jugador* unJugador=NULL;
	unJugador=jug_new();
	int retorno=-1;
	if(pArrayListJugador!=NULL && unJugador!=NULL){
		(*id)++;
		unJugador=jug_newParametrosAlta(id);
		ll_add(pArrayListJugador,(Jugador*)unJugador);
		retorno=0;
	}

    return retorno;
}

/** \brief Modificar datos del jugador cargado dentro de la LinkedList
 *
 * \param pArrayListJugador LinkedList* recibe la lista de jugadores
 * \return int para validar si la funcion realizo su comedito
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int retorno=-1,cantidad,i,opcionDeMenu,idAModificar,edadStr,indice;
	Jugador* unJugador=jug_new();
	char nombreCompletoStr[51],posicionStr[51],nacionalidadStr[51],confirmarSalir;
	if(pArrayListJugador!=NULL && unJugador!=NULL){
		buscarIdMaximo(pArrayListJugador,&cantidad);
		ll_sort(pArrayListJugador,ordenarPorIdJugador, 1);
		do{
			if(mostrarJugadores(pArrayListJugador,1,"")==0){
				utn_getEntero(&idAModificar,"\nSELECCIONE UN ID PARA MODIFICAR\n","--ERROR--",0,cantidad);
				buscarJugPorId(pArrayListJugador,idAModificar,&indice);
				for(i=0;i<cantidad;i++){
				    unJugador= (Jugador*) ll_get(pArrayListJugador,indice);
				    break;
				}
			}
			opcionDeMenu=menuModificar();
			switch(opcionDeMenu){
				case 1:
					utn_getCadenaCaracteres(51,nombreCompletoStr,"\nINGRESE EL NOMBRE COMPLETO DEL JUGADOR\n","\n--ERROR--\n");
					jug_setNombreCompleto(unJugador,nombreCompletoStr);
					ll_set(pArrayListJugador,indice,unJugador);
					break;
				case 2:
					utn_getEntero(&edadStr,"\nINGRESE LA EDAD DEL JUGADOR (ENTRE 14 Y 50)\n","\n--ERROR--\n",14,50);
					jug_setEdad(unJugador,edadStr);
					ll_set(pArrayListJugador,indice,unJugador);
					break;
				case 3:
					do{
						opcionesDePosicion();
						utn_getCadenaCaracteres(50,posicionStr,"\nINGRESE LA POSICION DEL JUGADOR\n","--ERROR--");
					}while(validarPosicion(posicionStr)!=0);
					jug_setPosicion(unJugador,posicionStr);
					ll_set(pArrayListJugador,indice,unJugador);
					break;
				case 4:
					do{
						opcionesDeNacionalidad();
						utn_getCadenaCaracteres(50,nacionalidadStr,"\nINGRESE LA NACIONALIDAD DEL JUGADOR\n","--ERROR--");
					}while(validarNacionalidad(nacionalidadStr)!=0);
					jug_setNacionalidad(unJugador,nacionalidadStr);
					ll_set(pArrayListJugador,indice,unJugador);
					break;
				case 5:
					confirmarSalir=continuarCarga("\nCONFIRME PARA VOLVER AL MENU PRINCIPAL");
					break;
			}
		retorno=0;
		}while(confirmarSalir!='S');
	}
    return retorno;
}

/** \brief Baja del jugador seleccionado por el usurio
 *
 * \param pArrayListJugador LinkedList* lista de jugadores cargadores
 * \return int para validar si la funcion realizo su comedito
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	char confirmarSalir;
	int cantidad,idAModificar,indice;
	if(pArrayListJugador!=NULL){
		ll_sort(pArrayListJugador,ordenarPorIdJugador, 1);
		do{
			if(mostrarJugadores(pArrayListJugador,1,"")==0){
				buscarIdMaximo(pArrayListJugador,&cantidad);
				utn_getEntero(&idAModificar,"\nSELECCIONE UN ID PARA ELIMINAR\n","--ERROR--",0,cantidad);
				buscarJugPorId(pArrayListJugador,idAModificar,&indice);
				ll_remove(pArrayListJugador,indice);
				printf("JUGADOR ELIMINADO");
			}
			confirmarSalir=continuarCarga("\nCONFIRME PARA VOLVER AL MENU PRINCIPAL");
		}while(confirmarSalir!='S');
	}
    return 1;
}

/** \brief Listar jugadores
 *
 * \param pArrayListJugador LinkedList* recibe la lista de jugadores
 * para ser impresa por consola
 * \return int para validar si la funcion realizo su comedito
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno=-1;
	if(pArrayListJugador!=NULL){
		ll_sort(pArrayListJugador,ordenarPorIdJugador, 1);
		mostrarJugadores(pArrayListJugador,1,"");
		retorno=0;
	}
    return retorno;
}
/** \brief Ordenar selecciones segun criterio del usuario
 *
 * \param pArrayListSeleccion LinkedList* recibe la lista de selecciones
 * \return int para validar si la funcion realizo su comedito
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno=-1,opcion;
	if(pArrayListSeleccion!=NULL){
		utn_getEntero(&opcion,"\nINGRESE 1 PARA ORDENAR DE MANERA ASCENDENTE\n"
				"INGRESE 0 PARA ORDENAR DE MANERA DESCENDENTE\n","\n--ERROR--\n",0,1);
		ll_sort(pArrayListSeleccion,ordenarSeleccionPorConfederacion, opcion);
		mostrarConfederaciones(pArrayListSeleccion);
		retorno=0;
	}
    return retorno;
}
/** \brief Ordenar jugadores segun criterio seleccionado por el usuario
 *
 * \param pArrayListJugador LinkedList* recibe la lista de jugadores
 * \param pArrayListSeleccion LinkedList* recibe la lista de selecciones
 * \return int para validar si la funcion realizo su comedito
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno=-1,opcionMenuOrdenar,opcion;
	char volverlAlMenu;
	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL){
		do{
			opcionMenuOrdenar=menuListadosOrdenados();
			switch(opcionMenuOrdenar){
			case 1:
				utn_getEntero(&opcion,"\nINGRESE 1 PARA ORDENAR DE MANERA ASCENDENTE\n"
						"INGRESE 0 PARA ORDENAR DE MANERA DESCENDENTE\n","\n--ERROR--\n",0,1);
				ll_sort(pArrayListJugador,ordenarPorNacionalidadJugador, opcion);
				mostrarJugadores(pArrayListJugador,1,"");
				break;
			case 2:
				controller_ordenarSelecciones(pArrayListSeleccion);
				break;
			case 3:
				utn_getEntero(&opcion,"\nINGRESE 1 PARA ORDENAR DE MANERA ASCENDENTE\n"
						"INGRESE 0 PARA ORDENAR DE MANERA DESCENDENTE\n","\n--ERROR--\n",0,1);
				ll_sort(pArrayListJugador,ordenarPorEdadJugador, opcion);
				mostrarJugadores(pArrayListJugador,1,"");
				break;
			case 4:
				utn_getEntero(&opcion,"\nINGRESE 1 PARA ORDENAR DE MANERA ASCENDENTE\n"
						"INGRESE 0 PARA ORDENAR DE MANERA DESCENDENTE\n","\n--ERROR--\n",0,1);
				ll_sort(pArrayListJugador,ordenarPorNombreJugador, opcion);
				mostrarJugadores(pArrayListJugador,1,"");
				break;
			case 5:
				volverlAlMenu=continuarCarga("\nCONFIRME PARA VOLVER AL MENU PRINCIPAL");
				break;
			}
		}while(volverlAlMenu!='S');
	}
    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char* archivo a ser escrito
 * \param pArrayListSeleccion LinkedList* recibe la lista de jugadores
 * \return int para validar si la funcion realizo su comedito
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	char indice[200]={"id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion\n"};
	char buffer[300];
	FILE* pJugadoresFile;
	Jugador* unJugador;
	int longitud,cantidad,id,edad,idSeleccion,tamanio,retorno=-1;
	char nombreCompleto[51],posicion[51],nacionalidad[51],numeros[10];
	ll_sort(pArrayListJugador,ordenarPorIdJugador, 1);
	tamanio=ll_len(pArrayListJugador);
	if ((pJugadoresFile=fopen(path,"w"))==NULL){
		printf("No se puede abrir el archivo");
		exit(1);
	}
	longitud = strlen(indice);
	fwrite(indice,sizeof(char),longitud,pJugadoresFile);

	for(int i=0;i<tamanio;i++){
		unJugador= (Jugador*) ll_get(pArrayListJugador,i);
		jug_getId(unJugador,&id);
		jug_getNombreCompleto(unJugador,nombreCompleto);
		jug_getEdad(unJugador,&edad);
		jug_getPosicion(unJugador,posicion);
		jug_getNacionalidad(unJugador,nacionalidad);
		jug_getIdSeleccion(unJugador,&idSeleccion);
		strcpy(buffer,itoa(id,numeros,10));
		strcat(buffer,",");
		strcat(buffer,nombreCompleto);
		strcat(buffer,",");
		strcat(buffer,itoa(edad,numeros,10));
		strcat(buffer,",");
		strcat(buffer,posicion);
		strcat(buffer,",");
		strcat(buffer,nacionalidad);
		strcat(buffer,",");
		strcat(buffer,itoa(idSeleccion,numeros,10));
		strcat(buffer,"\n");
		longitud = strlen(buffer);
		cantidad= fwrite(buffer,sizeof(char),longitud,pJugadoresFile);
		if (cantidad<longitud){
			printf("Error al escribir el archivo");
			exit(1);
		}
	}
	retorno=0;
	printf("\nARCHIVO %s GUARDADO\n",path);
	fclose(pJugadoresFile);
    return retorno;
}

/** \brief Guarda los datos de los jugadores convocados por confederacion,
 *  elegida por el usuario, en el archivo binario.
 *
 * \param path char* archivo binario a ser escrito
 * \param pArrayListJugador LinkedList* recibe la lista de jugadores
 * \return int para validar si la funcion realizo su comedito
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	FILE* pSeleccionConvocadaFile;
	Jugador* unJugador=NULL;
	unJugador=jug_new();
	int cantidad,retorno=-1,id,confederacion,bandera=0;
	char confederacionIngresada[51],continuarCargando;
	ll_sort(pArrayListJugador,ordenarPorIdJugador, 1);
	cantidad=ll_len(pArrayListJugador);
	if ((pSeleccionConvocadaFile=fopen(path,"wb"))==NULL){
			printf("NO SE PUEDE ABRIR EL ARCHIVO");
	}
	do{
		do{
			opcionesDeConfederacion();
		utn_getCadenaCaracteres(51,confederacionIngresada,"\nINGRESE LA CONFEDERACION A GUARDAR\n"
				,"\n--ERROR--\n");
		}while(validarConfederacion(&confederacion,confederacionIngresada)!=0);
		for(int i=0;i<cantidad;i++){
			unJugador= (Jugador*) ll_get(pArrayListJugador,i);
			jug_getIdSeleccion(unJugador,&id);
			if(confederacion==1){
				if(id==2 || id==4 || id==9 || id==21 || id==22 || id==27){
					fwrite(unJugador,sizeof(Jugador),1,pSeleccionConvocadaFile);
					bandera=1;
				}
			}else if(confederacion==2){
				if(id==7 || id==18 || id==23 || id==28 || id==31){
					fwrite(unJugador,sizeof(Jugador),1,pSeleccionConvocadaFile);
					bandera=1;
				}
			}else if(confederacion==3){
				if(id==8 || id==10 || id==15 || id==24){
					fwrite(unJugador,sizeof(Jugador),1,pSeleccionConvocadaFile);
					bandera=1;
				}
			}else if(confederacion==4){
				if(id==3 || id==6 || id==13 || id==32){
					fwrite(unJugador,sizeof(Jugador),1,pSeleccionConvocadaFile);
					bandera=1;
				}
			}else if(confederacion==5){
				if(id==1 || id==5 || id==11 || id==12 || id==14 || id==16 ||
						id==17 || id==19 || id==20 || id==25 || id==26 || id==29 || id==30){
					fwrite(unJugador,sizeof(Jugador),1,pSeleccionConvocadaFile);
					bandera=1;
				}
			}
		}
		if(bandera==0){
			printf("\nNO HAY JUGADORES CONVOCADOS EN ESA CONFEDERACION\n");
			continuarCargando=continuarCarga("\n¿CANCELAR LA GENERACION DEL ARCHIVO?\n");
			if(continuarCargando=='S'){
				bandera=1;
			}
		}
	}while(bandera!=1);
	fclose(pSeleccionConvocadaFile);
    return retorno;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char* archivo a ser leido
 * \param pArrayListSeleccion LinkedList* recibe la lista de selecciones
 * \return int para validar si la funcion realizo su comedito
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	FILE* pSeleccionFile=fopen(path,"r");
	if(pSeleccionFile!=NULL){
		if(parser_SeleccionFromText(pSeleccionFile ,pArrayListSeleccion)==0){
			printf("\nARCHIVO %s LEIDO CORECTAMENTE\n",path);
		}else{
			printf("ERROR AL CARGAR EL ARCHIVO");
		}
	}
	fclose(pSeleccionFile);
    return 1;
}

/** \brief Modificar datos de convocados en una seleccion
 *
 * \param pArrayListSeleccion LinkedList* recibe la lista de selecciones
 * \param pArrayListJugador LinkedList* recibe la lista de jugadores
 * \return int para validar si la funcion realizo su comedito
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion,LinkedList* pArrayListJugador)
{
	Jugador* unJugador;
	Seleccion* unaSeleccion;
	unJugador=jug_new();
	unaSeleccion=selec_new();
	int retorno=-1,idSeleccion,opcionDeMenu,cantidad,idJugador,indiceJugador,i,indiceSeleccion,convocados;
	int entraIdSeleccion,entraIdJugador,getIdJugador;
	char confirmarVolver,nacionalidad[51],continuarCargando;
	if(pArrayListSeleccion!=NULL && unJugador!=NULL && unaSeleccion!=NULL){
		buscarIdMaximo(pArrayListJugador,&cantidad);
		ll_sort(pArrayListJugador,ordenarPorIdJugador, 1);
		do{
			opcionDeMenu=menuConvocados();
			switch(opcionDeMenu){
			case 1:
				do{
					mostrarConfederaciones(pArrayListSeleccion);
					utn_getEntero(&idSeleccion,"\nINGRESAR SELECCION PARA CONVOCAR\n","\n--ERROR--\n",1,32);
					entraIdSeleccion=validarNacionalidadParaConvocados(pArrayListSeleccion,idSeleccion,nacionalidad,&indiceSeleccion);
				}while(entraIdSeleccion!=0);
				do{
					do{
						mostrarJugadores(pArrayListJugador,2,nacionalidad);
						utn_getEntero(&idJugador,"\nINGRESAR ID DE JUGADOR PARA CONVOCAR\n","\n--ERROR--\n",1,cantidad);
						entraIdJugador=validarIdDeConvocados(pArrayListJugador,idJugador,nacionalidad,&indiceJugador);
					}while(entraIdJugador!=0);
					for(i=0;i<cantidad;i++){
						unJugador= (Jugador*) ll_get(pArrayListJugador,indiceJugador);
						break;
					}
					for(i=0;i<cantidad;i++){
						unaSeleccion= (Seleccion*) ll_get(pArrayListSeleccion,indiceSeleccion);
						break;
					}
					jug_getIdSeleccion(unJugador,&getIdJugador);
					if(getIdJugador==0){
						jug_setIdSeleccion(unJugador,idSeleccion);
						selec_getConvocados(unaSeleccion,&convocados);
						if(convocados<22){
							convocados++;
							selec_setConvocados(unaSeleccion,convocados);
							printf("\nJUGADOR CONVOCADO\n");
						}
					}else{
						printf("\nEL JUGADOR YA FUE CONVOCADO\n");
					}

					ll_set(pArrayListJugador,indiceJugador,unJugador);
					ll_set(pArrayListSeleccion,indiceSeleccion,unaSeleccion);
					continuarCargando=continuarCarga("\n¿CONTINUAR CONVOCANDO JUGADORES EN ESTA SELECCION?\n");
				}while(continuarCargando!='N');
				break;
			case 2:
				mostrarConfederaciones(pArrayListSeleccion);
				utn_getEntero(&idSeleccion,"\nINGRESAR SELECCION PARA NO CONVOCAR\n","\n--ERROR--\n",1,32);
				if(validarNacionalidadParaConvocados(pArrayListSeleccion,idSeleccion,nacionalidad,&indiceSeleccion)==0){
					do{
						mostrarJugadores(pArrayListJugador,2,nacionalidad);
						utn_getEntero(&idJugador,"\nINGRESAR ID DE JUGADOR PARA NO CONVOCAR\n","\n--ERROR--\n",1,cantidad);
						if(validarIdDeConvocados(pArrayListJugador,idJugador,nacionalidad,&indiceJugador)==0){
							for(i=0;i<cantidad;i++){
								unJugador= (Jugador*) ll_get(pArrayListJugador,indiceJugador);
								break;
							}
							for(i=0;i<cantidad;i++){
								unaSeleccion= (Seleccion*) ll_get(pArrayListSeleccion,indiceSeleccion);
								break;
							}
							jug_getIdSeleccion(unJugador,&getIdJugador);
							if(getIdJugador!=0){
							jug_setIdSeleccion(unJugador,0);
							selec_getConvocados(unaSeleccion,&convocados);
								if(convocados>0){
									convocados--;
									selec_setConvocados(unaSeleccion,convocados);
									printf("\nJUGADOR NO CONVOCADO\n");
								}
							}else{
								printf("\nEL JUGADOR NO FUE CONVOCADO\n");
							}
							ll_set(pArrayListJugador,indiceJugador,unJugador);
							ll_set(pArrayListSeleccion,indiceSeleccion,unaSeleccion);
						}
					continuarCargando=continuarCarga("\n¿CONTINUAR DESCONVOCANDO JUGADORES EN ESTA SELECCION?\n");
					}while(continuarCargando!='N');
				}
				break;
			case 3:
				confirmarVolver=continuarCarga("\nCONFIRME PARA VOLVER AL SISTEMA");
				break;
			}
		}while(confirmarVolver!='S');

		retorno=0;
	}
    return retorno;
}


/** \brief Listar selecciones
 *
 * \param pArrayListSeleccion LinkedList* recibe la lista de selecciones,
 * para ser impresa por consola
 * \return int para validar si la funcion realizo su comedito
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	if(pArrayListSeleccion!=NULL){
		mostrarConfederaciones(pArrayListSeleccion);
		retorno=0;
	}
    return retorno;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char* archivo a ser escrito
 * \param pArrayListSeleccion LinkedList* recibe la lista de selecciones
 * \return int para validar si la funcion realizo su comedito
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	char indice[200]={"id,pais,confederacion,convocados\n"};
	char buffer[300];
	FILE* pSeleccionesFile;
	Seleccion* unaSeleccion;
	unaSeleccion=selec_new();;
	int longitud,id,convocados,tamanio,retorno=-1;
	char pais[51],confederacion[51],numeros[10];
	if(pArrayListSeleccion!=NULL && unaSeleccion!=NULL){
		tamanio=ll_len(pArrayListSeleccion);
		pSeleccionesFile=fopen(path,"wb");
		longitud = strlen(indice);
		fwrite(indice,sizeof(char),longitud,pSeleccionesFile);

		for(int i=0;i<tamanio;i++){
			unaSeleccion= (Seleccion*) ll_get(pArrayListSeleccion,i);
			selec_getId(unaSeleccion,&id);
			selec_getPais(unaSeleccion,pais);
			selec_getConfederacion(unaSeleccion,confederacion);
			selec_getConvocados(unaSeleccion,&convocados);
			strcpy(buffer,itoa(id,numeros,10));
			strcat(buffer,",");
			strcat(buffer,pais);
			strcat(buffer,",");
			strcat(buffer,confederacion);
			strcat(buffer,",");
			strcat(buffer,itoa(convocados,numeros,10));
			strcat(buffer,"\n");
			longitud = strlen(buffer);
			fwrite(buffer,sizeof(char),longitud,pSeleccionesFile);

		}
		retorno=0;
		printf("\nARCHIVO %s GUARDADO\n",path);
		fclose(pSeleccionesFile);
	}

	return retorno;
}


