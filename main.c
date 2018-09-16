/*
Realizar un programa que reciba como parámetro una matriz de adyacencia,
la cual puede ser la representación de un grafo no dirigido.
Se pide realizar la carga en una estructura dinámica, y a partir de ella
determinar los siguientes puntos en caso de ser un grafo :

Verificar si es un grafo (la sumatoria de grados de todos los vertices tiene que ser igual al doble de aristas)
Cargar los vertices y los subnodos de cada uno de ellos en la multilista

OK..Informar la cantidad de vértices
OK..Informar la cantidad de aristas
OK..Determinar si es un grafo bipartito
OK..Determinar si es un grafo plano
OK..Determinar si es un grafo simple
OK..Determinar si es un grafo completo

Informar cuál es el vértice de mayor grado (sumar los elementos de cada fila (excepto el vertice), e informar cual es el vertice que tiene mayor)
Determinar si es grafo regular (si todos los vertices tienen el mism grado)
Poder agregar vertices
Poder eliminar vertices

Vertices: cant. de filas de la matriz
Total de Aristas: sumatoria de todas las filas (total de grados)

*/

#include <stdio.h>
#include <stdlib.h>
#define NOM_ARCHIVO  "file.txt"
#define FILAS 4
#define COLUMNAS 4


//para la multilista
typedef struct nodo {
    int dato;
    struct nodo *siguiente;
    struct subnodo *lista;
}nodo;

//para la multilista
typedef struct subnodo {
    int dato;
    struct subnodo *siguiente;
}subnodo;

//para leer el archivo file.txt
struct grafo {
   int vertice;
   int hijo;
}g;

void esGrafo(int aristas, int vertices, int num_filas);
void esPlano(int aristas, int vertices);
void esBipartito(int aristas, int vertices);
void ingresarVertice(nodo *registro);
void ingresarSubnodo(nodo *registro);
void mostrarVertice(nodo *registro);
void mostrarSubnodo(subnodo *registro);
void eliminarSubnodo(nodo *registro);
void eliminarGrafo(nodo *registro);
nodo *buscarNodo(nodo *registro, int dato);


nodo *buscarNodo(nodo *registro, int dato)
	{
	// si el registro sigbar es NULL no encontro el vertice
	if (registro->siguiente == NULL){
		printf("No se encontro el vertice \n");
		return 0;
    }else{
		if (strcmp(registro->dato, dato) == 0){
			return registro;
        }else{
			return (buscarNodo(registro->siguiente, dato));
			}
		}
	}

void agregarVertice(nodo *registro)
{
	subnodo *nuevo;
    int varvertice;

	//varvertice va a tener el vertice que voy a copiar del archivo.txt
    if (strcmpi(varvertice, NULL) == 0){
        registro->siguiente=NULL;
        return;
    }else{
        registro->dato=varvertice;
        registro->siguiente=(subnodo *)malloc(sizeof(subnodo));
        agregarSubnodo(registro->lista);
        registro->siguiente=(nodo *)malloc(sizeof(nodo));
        agregarVertice(registro->siguiente);
    }
}

void agregarSubnodo(subnodo *registro)
{
	int varsubnodo;
    subnodo*nuevo;

	//varsubnodo va a tener los subnodos de c/u de los vertices que voy a copiar del archivo.txt
    if (strcmpi(varsubnodo, NULL) == 0){
        registro->siguiente=NULL;
        return;
    }else{
        registro->dato=varsubnodo;
        registro->siguiente=(subnodo *)malloc(sizeof(subnodo));
        agregarSubnodo(registro->siguiente);
    }
}

void mostrarVertice(nodo *registro){
if (registro->siguiente != NULL){
	printf("Vertice: %d  \n",registro->dato);
    mostrarSubnodo(registro->lista);
	mostrarVertice(registro->siguiente);
	}
}

void mostrarSubnodo(subnodo *registro){
if (registro->siguiente != NULL){
	printf("Subnodo : %d \n", registro->dato);
	mostrarSubnodo(registro->siguiente);
	}
}

void esPlano(int aristas, int vertices)
{
    if (aristas <= 3*vertices - 6 )
    {
        printf("Es Plano, conexo y simple \n");
    }
    else
    {
        printf("No es un grafo plano \n");
    }
}

void esBipartito(int aristas, int vertices)
{
    if (aristas <= 2*vertices - 4)
    {
        printf("Es Plano, conexo, simple y bipartito \n");
    }
    else
    {
       printf("No es grafo plano bipartito \n");
    }
}

int menu(){
		int opcion;
		do{
            printf("\n  >>>>>>>>>> MENU DE OPCIONES: <<<<<<<<<< \n");
            printf("  ---------------------------------- \n");
            printf("  Seleccione una opcion:      \n");
            printf("  1. Crear Vertice \n");
            printf("  2. Eliminar Vertice \n");
            printf("  3. Eliminar Grafo \n");
            printf("  4. Probar si es Plano\n");
            printf("  6. Mostrar Grafo\n");
            printf("  5. Salir \n");
            printf("  ----------------------------------  \n");
            scanf("%d", &opcion);
            fflush(stdin);
		}while (opcion < 1 || opcion > 5);
}

void esGrafo(int aristas, int vertices, int num_filas)
{
   int resp;
   if (aristas==vertices)
   {
        printf("Es un grafo.... \n");
        do {
	    resp = menu();
		switch (resp)
		{
		    case 5 :
                printf("Saliendo...");
                printf("\n\n");
                system("pause");
                break;
            case 4 :
                esPlano(aristas, num_filas);
                esBipartito(aristas, num_filas);
                printf("\n\n");
                system("pause");
                break;
            default:
                printf("Opcion no contemplada", resp);
                printf("\n\n");
                break;
        }
	}while(resp != 5);
   }
   else
   {
       printf("No es un grafo, no hay operaciones disponibles \n");
       fflush(stdin);
       getchar();
   }
}

int main(void)
{
   FILE *entrada;
   int ch=0, acu=0, num_filas=0, i=0, j=0, aristas=0, ingreso=0;
   int aux[FILAS][COLUMNAS];
   int numerosExtraidos[100];
   //struct grafo g;

   if ((entrada = fopen(NOM_ARCHIVO, "r")) == NULL){
      perror(NOM_ARCHIVO);
      return EXIT_FAILURE;
   }

   num_filas = 0;
   while((ch = fgetc(entrada)) != EOF)
      if (ch == '\n')
         num_filas++;

   rewind(entrada);

   printf("Matriz de Adyacencia: \n");
   for (i=0; i<FILAS; i++)
   {
       fscanf(entrada, "%d", &g.vertice);
       printf("\n");
       printf("%d ", g.vertice);
         for (j=0; j<COLUMNAS; j++)
         {
             fscanf(entrada, "%d", &g.hijo);
             printf("%d ", g.hijo);
             acu=acu+g.hijo;
         }
   }

   fclose(entrada);
   aristas=2*num_filas;
   printf("\n\n");
   printf("Nro de Vertices: %d\n", num_filas);
   printf("Nro de Aristas: %d\n", aristas);
   printf("Sumatoria grados: %d\n", acu);
   esGrafo(aristas, acu, num_filas);
   //esPlano(aristas, num_filas);
   //esBipartito(aristas, num_filas);

   return EXIT_SUCCESS;
}
