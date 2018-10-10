/*
Realizar un programa que reciba como parámetro una matriz de adyacencia,
la cual puede ser la representación de un grafo no dirigido.
Se pide realizar la carga en una estructura dinámica, y a partir de ella
determinar los siguientes puntos en caso de ser un grafo :

El programa funciona a partir de la carga de la matriz de adyacencia en el archivo "file.txt"
La cantidad de Aristas del grafo se define globalmente en ARISTAS
al igual que la cantidad de FILAS y COLUMNAS del grafo

*/

#include <stdio.h>
#include <stdlib.h>
#define NOM_ARCHIVO  "file.txt"
#define FILAS 4
#define COLUMNAS 4
#define ARISTAS 4


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

int aux[FILAS];

void esGrafo(int aristas, int vertices, int num_filas);
void esPlano(int aristas, int vertices);
void esBipartito(int aristas, int vertices);
void esRegular(int aux []);
void gradoMaximo(int aux []);
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

void agregarVertice(nodo *registro, int vertice)
{
	subnodo *nuevo;

	//varvertice va a tener el vertice que voy a copiar del archivo.txt
    if (vertice == NULL){
        registro->siguiente=NULL;
        return;
    }else{
        registro->dato=vertice;
        registro->siguiente=(subnodo *)malloc(sizeof(subnodo));
        agregarSubnodo(registro->lista);
        registro->siguiente=(nodo *)malloc(sizeof(nodo));
        agregarVertice(registro->siguiente, vertice);
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
            printf("  1. Probar si es Plano\n");
            printf("  2. Probar si es Regular\n");
            printf("  3. Vertice con Mayor Grado\n");
            printf("  4. Salir \n");
            printf("  ----------------------------------  \n");
            scanf("%d", &opcion);
            fflush(stdin);
		}while (opcion < 1 || opcion > 4);
}

void esGrafo(int doble_aristas, int acu, int num_filas)
{
   int resp;
   if (doble_aristas==acu)
   {
        printf("Es un grafo.... \n");
        do {
	    resp = menu();
		switch (resp)
		{
            case 1 :
                esPlano(doble_aristas, num_filas);
                esBipartito(doble_aristas, num_filas);
                printf("\n\n");
                system("pause");
                break;
            case 2 :
                esRegular(aux);
                printf("\n\n");
                system("pause");
                break;
            case 3 :
                gradoMaximo(aux);
                printf("\n\n");
                system("pause");
                break;
            case 4 :
                printf("Saliendo...");
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

void gradoMaximo(int aux []){
    int i=0, max=0, pos=0;
     for(i=0;i<FILAS;i++)
     {
         if (aux[i]>max)
         {
            max=aux[i];
            pos=i;
         }
     }
     printf("Vertice con mayor grado es el v:[%d] con Grado: %d\n", pos+1, max);
}

void esRegular(int aux []){
    int i=0, cont=0;
     for(i=0;i<FILAS;i++)
     {
         if (aux[i]==aux[i+1])
         {
            cont++;
         }
     }
     if (cont==FILAS)
         printf("Es Grafo regular de %d vertices - grado %d\n", FILAS, aux[0]);
     else
         printf("No es un grafo regular \n", cont);
}

int main(void)
{
   FILE *entrada;
   int ch=0, acu=0, num_filas=0, i=0, j=0, doble_aristas=0, aristas=0, ingreso=0, k=0, conti=0, acum=0;
   nodo *headNodo;
   nodo *encontrado;
   headNodo=(nodo *)malloc(sizeof(nodo));
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
       conti++;
       fscanf(entrada, "%d", &g.vertice);
       printf("\n");
       printf("%d ", g.vertice);
         for (j=0; j<COLUMNAS; j++)
         {
             fscanf(entrada, "%d", &g.hijo);
             printf("%d ", g.hijo);
             acu=acu+g.hijo;
             acum=acum+g.hijo;
         }
         if (conti <=FILAS )
         {
                 acum=acum+g.hijo;
                 //printf("fila %d - acum %d", conti, acum);
         }
         aux[k]=acum;
         k++;
         acum=0;
   }

   fclose(entrada);
   doble_aristas=2*ARISTAS;
   printf("\n\n");
   printf("Nro de Vertices: %d\n", conti);
   printf("Nro de Aristas: %d\n", ARISTAS);
   printf("Sumatoria grados: %d\n", acu);
   esGrafo(doble_aristas, acu, num_filas);
   return EXIT_SUCCESS;
}
