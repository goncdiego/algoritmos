/*
    Realizar un programa que reciba como par�metro una matriz de adyacencia,
    la cual puede ser la representaci�n de un grafo no dirigido.
    Se pide realizar la carga en una estructura din�mica, y a partir de ella
    determinar los siguientes puntos en caso de ser un grafo :

    El programa funciona a partir de la carga de la matriz de adyacencia en el archivo "file.txt"
    La cantidad de Aristas del grafo se define globalmente en ARISTAS
    al igual que la cantidad de FILAS y COLUMNAS del grafo

*/

#include "commondef.h"
#include "mlists.h"
#include "tools.h"


int menu();


int main(int argc, char * argv[]){

    header * p = (header*)malloc(sizeof(header));

    crearHeader(p);
    mostrar(p);

    return 0;
};


int menu(){
		int opcion=0;
		do{
            printf("\n  >>>>>>>>>> MENU DE OPCIONES <<<<<<<<<< \n");
            printf("  ---------------------------------- \n");
            printf("  Seleccione una opcion:      \n");
            printf("  1. Probar si es Plano\n");
            printf("  2. Probar si es Regular\n");
            printf("  3. Vertice con Mayor Grado\n");
            printf("  4. Salir \n");
            printf("  ----------------------------------  \n");
            scanf("%d", &opcion);
            fflush(stdin);
		}while (opcion < MIN_OPC || opcion > MAX_OPC);
}