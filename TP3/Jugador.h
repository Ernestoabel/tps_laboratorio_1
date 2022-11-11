#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr,
		char* posicionStr, char* nacionalidadStr, char* idSelccionStr);
Jugador* jug_newParametrosAlta(int* idStr);

void jug_delete(Jugador* this);


int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);

int buscarIdMaximo(LinkedList* pArrayListJugador,int* idMaximo);
int buscarJugPorId(LinkedList* pArrayListJugador, int idBuscado, int* indice);
int validarPosicion(char* posicionIngresada);
int validarNacionalidad(char* nacionalidadIngresada);
int validarIdDeConvocados(LinkedList* pArrayListJugador,int idJugador,char* mensaje,int* indice);

int ordenarPorNombreJugador(void* unJugador, void* auxJugador);
int ordenarPorNacionalidadJugador(void* unJugador, void* auxJugador);
int ordenarPorEdadJugador(void* unJugador, void* auxJugador);
int ordenarPorIdJugador(void* unJugador, void* auxJugador);

#endif // jug_H_INCLUDED
