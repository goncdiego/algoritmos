#include "tools.h"

//Contamos las aristas del grafo
int contarAristas(header * p){
    int aristas = 0;
    while(1){
        body * aux = p->nextBody;
        if(p->vertice > 0)aristas += p->vertice;//Aumentamos las aristas
        while(aux->next!=NULL){ //Si el siguiente body es distinto de NULL
            if(aux->vertice > 0)aristas += aux->vertice;//Aumentamos las aristas
            aux = aux->next;//Avanzamos al siguiente
        };
        if (p->nextHeader->vertice!=CORTE_DE_CARGA)
            p = p->nextHeader;
        else return aristas/2;
    }
};

//Contamos los vertices del grafo
int contarVertices(header*p){
    int vertices = 0;
    while(1){
        body * aux = p->nextBody;
        vertices++;//contamos el vertice
        while(aux->next!=NULL){ //Si el siguiente body es distinto de NULL
            //vertices++;//Contamos el vertice
            aux = aux->next;//Avanzamos al siguiente
        };
        if (p->nextHeader->vertice!=CORTE_DE_CARGA)
            p = p->nextHeader;
        else return vertices;
    }
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
void esGrafo(int doble_aristas, int sumaGrados){
   if (doble_aristas==sumaGrados)
        printf("Es un grafo.\n");
   else
        printf("No es un grafo.\n");
}

//Determina el grado maximo del grafo
int gradoMaximo(header* p){
    int grado = 0;
    int gradoMax = 0;
    while(1){
        body * aux = p->nextBody;
        grado = 0;
        grado += p->vertice;//Aumentamos el grado
        while(aux->next!=NULL){ //Si el siguiente body es distinto de NULL
            grado += aux->vertice;//Aumentamos el grado
            aux = aux->next;//Avanzamos al siguiente
        };
        // Si el contador es mayor que el grado maximo
        if(gradoMax < grado) gradoMax =  grado;//seteamos grado max 
        
        if (p->nextHeader->vertice!=CORTE_DE_CARGA)
            p = p->nextHeader;
        else return gradoMax;
    }
}


//Determina la suma de todos los grados
int sumaGrados(header* p){
    int grado = 0;
    int sumaGrados = 0;
    while(1){
        body * aux = p->nextBody;
        grado = 0;
        grado += p->vertice;//Aumentamos el grado
        while(aux->next!=NULL){ //Si el siguiente body es distinto de NULL
            grado += aux->vertice;//Aumentamos el grado
            aux = aux->next;//Avanzamos al siguiente
        };
        // Si el contador es mayor que el grado maximo
        sumaGrados +=  grado;//Acumulamos grados 
        
        if (p->nextHeader->vertice!=CORTE_DE_CARGA)
            p = p->nextHeader;
        else return sumaGrados;
    }
}


//Determina si el grafo es regular
//Devuelve el grado de los vertices si es regular y devuelve -1 si no es regular
int esRegular(header * p){
    int grado = 0;
    int gradoPrev = 0;
    while(1){
        body * aux = p->nextBody;
        grado = 0;
        grado += p->vertice;//Aumentamos el grado
        while(aux->next!=NULL){ //Si el siguiente body es distinto de NULL
            grado += aux->vertice;//Aumentamos el grado
            aux = aux->next;//Avanzamos al siguiente
        };
        //Primera pasada establece el gradoPrev
        if(gradoPrev == 0)
            gradoPrev = grado;
        // Verificamos si el grado es igual al grado previo
        if(gradoPrev != grado)
            return -1;
            
        if (p->nextHeader->vertice!=CORTE_DE_CARGA)
            p = p->nextHeader;
        else return gradoPrev;
    }
}