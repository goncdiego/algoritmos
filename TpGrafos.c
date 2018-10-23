/*
    Jaime Gonzalez Bonorino
    Realizar un programa que reciba como parametro una matriz de adyacencia,
    la cual puede ser la representacian de un grafo no dirigido.
    Se pide realizar la carga en una estructura din�mica, y a partir de ella
    determinar los siguientes puntos en caso de ser un grafo
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
                if(esRegular(p) != -1)
                    printf("Es regular\n");
                else printf("No es regular\n");
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
                eliminarSubnodo(p);
                mostrar(p);
                break;
            case 8:
                eliminarGrafo(p);
                printf("El grafo ha sido eliminado de la memoria\n");
                printf("Saliendo...");
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
            printf("  7. Eliminar subnodo\n");
            printf("  8. Eliminar grafo y salir\n");
            printf("  ----------------------------------  \n Opc: ");
            scanf("%d", &opcion);
            fflush(stdin);
		}while (opcion < MIN_OPC || opcion > MAX_OPC);
        return opcion;
}