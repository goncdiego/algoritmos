/*
    Common Definitions:
        Este header se encarga de contener todas las definiciones
        generales que se utilizan a lo largo de todo el proyecto.
*/
#ifndef COMMONDEF
#define COMMONDEF

#include <stdlib.h>
#include <stdio.h>
#define NOM_ARCHIVO "file.txt" //Direccion y nombre de archivo que contiene la matriz
#define FILAS 4 //Las filas que posee la matriz del archivo
#define COLUMNAS 4 //Las columnas que posee la matriz del archivo
#define ARISTAS 4 //Las aristas que posee la matriz del archivo
#define MIN_OPC 1 //Minima opcion del menu
#define MAX_OPC 4 //Maxima opcion del menu

//Multilista header y body
typedef struct multilista{
    int vertice;
    struct grafo * nextHeader;
    struct b * nextBody;
}header;

typedef struct b{
    int vertice;
     struct b * next;
}body;

//para leer el archivo file.txt
struct grafo {
   int vertice;
   int hijo;
}g;


// ??
int aux[FILAS];


#endif