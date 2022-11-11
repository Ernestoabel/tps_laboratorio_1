#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param FILE* pFile archivo para ser leido
 * \param pArrayListJugador LinkedList* a ser cargada con datos recividos por el archivo
 * \return int para validad que la funcion realizo su cometido
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno=-1,cantidad;
	char bufferJugador[6][200];
	Jugador* unJugador=NULL;

	if(pFile!=NULL && pArrayListJugador!=NULL){

			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferJugador[0],bufferJugador[1],bufferJugador[2],
					bufferJugador[3],bufferJugador[4],bufferJugador[5]);

			while(!feof(pFile))
			{

				cantidad=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferJugador[0],bufferJugador[1],
						bufferJugador[2],bufferJugador[3],bufferJugador[4],bufferJugador[5]);
				if(cantidad<6){
					jug_delete(unJugador);
					unJugador=NULL;
					retorno=-1;
					break;
				}else{
					unJugador=jug_newParametros(bufferJugador[0],bufferJugador[1],bufferJugador[2],
							bufferJugador[3],bufferJugador[4],bufferJugador[5]);
					if(unJugador!=NULL){
						ll_add(pArrayListJugador,(Jugador*)unJugador);
					}
				retorno=0;
				}
			}

	}
    return retorno;
}
/**
 * @brief parsea y recibe el valor id de un archivo de texto,
 * utilizado para el alta de un jugador nuevo
 *
 * @param id puntero a ser devuelto por referencia
 * @return int para validad que la funcion realizo su cometido
 */
int parser_y_apertura_IdFromText(int* id)
{
	FILE* pIdFile;
	Jugador* unJugador=NULL;
	unJugador=jug_new();
	char idTexto[2][10];
	int retorno=-1;
	if(unJugador!=NULL){
		pIdFile=fopen("IdJugador.txt","r");
		fscanf(pIdFile,"%[^,],%[^\n]",idTexto[0],idTexto[1]);
		*id=atoi(idTexto[1]);
		fclose(pIdFile);
		retorno=0;
	}
	return retorno;
}
/**
 * @brief parsea y guarda el valor de un id unico utilizado para el alta de un jugador nuevo,
 * en un archivo de texto
 *
 * @param id valor recibido para ser guardado
 * @return int para validad que la funcion realizo su cometido
 */
int parser_y_guardado_IdToText(int id)
{
	FILE* pIdFile;
	Jugador* unJugador=NULL;
	unJugador=jug_new();
	char buffer[10],auxiliar[10];
	int retorno=-1,longitud;
	if(unJugador!=NULL){
		pIdFile=fopen("IdJugador.txt","w");
		strcat(buffer,"ID");
		strcat(buffer,",");
		strcat(buffer,itoa(id,auxiliar,10));
		strcat(buffer,"\n");
		longitud = strlen(buffer);
		fwrite(buffer,sizeof(char),longitud,pIdFile);
		fclose(pIdFile);
		retorno=0;
	}
	return retorno;
}
/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param FILE* pFile recivido para ser abierto y leido
 * \param pArrayListJugador LinkedList* lista de jugadores para recivir los datos parseados
 * \return int para validad que la funcion realizo su cometido
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	Jugador* unJugador;
	while(!feof(pFile)){
		unJugador=jug_new();
		if(fread(unJugador,sizeof(Jugador),1,pFile)==1){
			ll_add(pArrayListJugador,(Jugador*)unJugador);
		}
	}
    return 1;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param FILE* pFile recivido para ser abierto y leido
 * \param pArrayListSeleccion LinkedList* lista de selecciones para recivir los datos parseados
 * \return int para validad que la funcion realizo su cometido
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno=-1,cant;
	char bufferSeleccion[4][100];
	Seleccion* unaSeleccion=NULL;

	if(pFile!=NULL && pArrayListSeleccion!=NULL){

			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferSeleccion[0],bufferSeleccion[1],
					bufferSeleccion[2],bufferSeleccion[3]);
			while(!feof(pFile))
			{

				cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferSeleccion[0],bufferSeleccion[1],
						bufferSeleccion[2],bufferSeleccion[3]);
				if(cant<4){
					selec_delete(unaSeleccion);
					unaSeleccion=NULL;
					retorno=-1;
					break;
				}else{
					unaSeleccion=selec_newParametros(bufferSeleccion[0],bufferSeleccion[1],
							bufferSeleccion[2],bufferSeleccion[3]);
					if(unaSeleccion!=NULL){
						ll_add(pArrayListSeleccion,(Seleccion*)unaSeleccion);
					}
					retorno=0;
				}
			}

	}
    return retorno;
}

