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
    int opc, salir = 0;
    int aristas;
    int vertices;
    int gradoMax;
    
    header * p = (header*)malloc(sizeof(header));

    crearHeader(p);
    mostrar(p);
    vertices = contarVertices(p);
    aristas = contarAristas(p);
    gradoMax = gradoMaximo(p);

    printf("\n");
    
    

    while(!salir){
        opc = menu();
        switch(opc){
            default:
                printf("Opcion no valida.");
                break;
            case 0:
                esGrafo(vertices*2,sumaGrados(p));
                break;
            case 1:
                esPlano(aristas,vertices);
                break;
            case 2:
                esRegular(p);
                break;
            case 3:
                esBipartito(aristas,vertices);
                break;
            case 4:
                printf("Grado Max: %d\n", gradoMax);
                break;
            case 5:
                printf("Vertices: %d\n", vertices);
                break;
            case 6:
                printf("Aristas: %d\n", aristas);
                break;
            case 7:
                salir = 1;
                break;
        };
    };
    return 0;
};


int menu(){
		int opcion=0;
		do{
            printf("\n  >>>>>>>>>> MENU DE OPCIONES <<<<<<<<<< \n");
            printf("  ---------------------------------- \n");
            printf("  Seleccione una opcion:      \n");
            printf("  0. Probar si es grafo\n");
            printf("  1. Probar si es Plano\n");
            printf("  2. Probar si es Regular\n");
            printf("  3. Probar si es bipartito\n");
            printf("  4. Vertice con Mayor Grado\n");
            printf("  5. Numero de vertices\n");
            printf("  6. Numero de aristas\n");
            printf("  7. Salir \n");
            printf("  ----------------------------------  \n Opc: ");
            scanf("%d", &opcion);
            fflush(stdin);
		}while (opcion < MIN_OPC || opcion > MAX_OPC);
        return opcion;
}