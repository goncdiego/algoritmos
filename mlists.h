/*
    Este header posee todas las definiciones de las funciones
    que estan relacionadas con la estructura de multilistas,
    sea para su creacion, control, o visualizacion.
*/

#include "commondef.h"

//Creacion de Multilista
void crearHeader(header*);
void crearBody(body*);
//Control multilista
void mostrar(header*);


//TODO-FINISH
void mostrarFila(int,body*);
void mostrarEnMatriz(header*);

//NON IMPLEMENTED
void ingresarVertice(header*);
void ingresarSubnodo(header*);
void mostrarVertice(header*);
void mostrarSubnodo(body*);
void eliminarSubnodo(header*);
void eliminarGrafo(header*);
header *buscarNodo(header*, int);