/*
    Este header posee todas las definiciones de las funciones
    que estan relacionadas con la estructura de multilistas,
    sea para su creacion, control, o visualizacion.
*/
#ifndef MLISTS
#define MLISTS 

#include "commondef.h"

//Creacion de Multilista
void crearHeader(header*);
void crearBody(body*);
//Control multilista
void mostrar(header*);
void eliminarSubnodo(header*);
void eliminarGrafo(header*);


//TODO-FINISH
//NOT IMPLEMENTED
//void agregarVertice(header*); No solicitado
//void agregarSubnodo(header*); No solicitado
header *buscarNodo(header*, int);
void mostrarFila(int,body*);
void mostrarEnMatriz(header*);

#endif 