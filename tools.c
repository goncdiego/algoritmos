#include "tools.h"

//Contamos las aristas del grafo
int contarAristas(header * p){
    int vertices = 0;
    while(1){
        body * aux = p->nextBody;
        vertices++;//contamos el vertice
        while(aux->next!=NULL){ //Si el siguiente body es distinto de NULL
            vertices++;//Contamos el vertice
            aux = aux->next;//Avanzamos al siguiente
        };
        if (p->nextHeader->vertice!=0)
            p = p->nextHeader;
        else return vertices;
    }
};

//Contamos los vertices del grafo
int contarVertices(header*p){
    return 0;
};


//Determina si el grafo es plano
void esPlano(int aristas, int vertices){
    if (aristas <= 3*vertices - 6 )
    {
        printf("Es Plano, conexo y simple \n");
    }
    else
    {
        printf("No es un grafo plano \n");
    }
}

//Determina si el grafo es bipartito
void esBipartito(int aristas, int vertices){
    if (aristas <= 2*vertices - 4)
    {
        printf("Es Plano, conexo, simple y bipartito \n");
    }
    else
    {
       printf("No es grafo plano bipartito \n");
    }
}


//Determina si el supuesto es grafo
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

//Determina el grado maximo del grafo
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

//Determina si el grafo es regular
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