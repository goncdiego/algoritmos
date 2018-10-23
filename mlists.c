#include "mlists.h"

//Crea un nodoHeader y deriva a el creador de sus subnodos
void crearHeader(header*p){
    printf("\n Nuevo Header: ");
    scanf("%d",&p->vertice);
    if(p->vertice == CORTE_DE_CARGA)
        p->nextHeader = NULL;
    else
    {
        p->nextBody = (body*)malloc(sizeof(body));
        crearBody(p->nextBody);
        p->nextHeader = (header*)malloc(sizeof(header));
        crearHeader(p->nextHeader);
    }
}

//Creador de subnodos
void crearBody(body * p){
    printf("\n Nuevo body: ");
     scanf("%d",&p->vertice);
    if(p->vertice == CORTE_DE_CARGA)
        p->next = NULL;
    else
    {
        p->next = (body*)malloc(sizeof(body));
        crearBody(p->next);
    }
}

//Muestra la matriz de adyacencia
//ATENCION: La matriz es impresa de forma lateral
//Utilizar el "MostrarEnMatriz"(No implementado) para mostrar en forma correcta
void mostrar(header*p){
    printf("\n");
    body * aux = p->nextBody;
    printf("\t %d",p->vertice); //Mostramos el vertice
    while(aux->next!=NULL){ //Si el siguiente body es distinto de NULL
        printf("\t %d",aux->vertice);//Mostramos su vertice
        aux = aux->next;//Avanzamos al siguiente
    };
    if (p->nextHeader->vertice!=CORTE_DE_CARGA) mostrar(p->nextHeader); //Si el siguiente header no es NULL, lo mostramos
};

void mostrarFila(int num,body * p){
    int i;
    for(i = 0; i <= num; i++){
        p = p->next;
    }
    printf("\t %d",p->vertice);
};

void mostrarEnMatriz(header*p){
    int fila = 0;

}

// Buscamos subnodo por posicion y lo eliminamos
void eliminarSubnodo(header* p){
    int x,y;
    printf("Ingrese las coordenadas del nodo a eliminar: \n");
    printf("X: ");
    scanf("%d", x);
    printf("Y: ");
    scanf("%d", y);
    if(y != 0){
        body * auxPrev;
        body * selected = NULL;
        int contx = 0,conty = 0;
        while(1){
            body * aux = p->nextBody;
            auxPrev = p->nextBody;
            while(aux->next!=NULL){ //Si el siguiente body es distinto de NULL
                if(conty == y-1)
                    auxPrev = aux;
                aux = aux->next;//Avanzamos al siguiente
                conty++;
                if(conty == y && contx == x){
                    selected = aux;
                    auxPrev->next = aux->next;
                }
            };
            if (p->nextHeader->vertice!=CORTE_DE_CARGA){
                p = p->nextHeader;
                contx++;
                conty = 0;
            };
            if(selected != NULL){
            printf("Vertice de eliminado: %d", selected->vertice);
            return free(selected); //Double free or corruption, core dump
            }
            if(contx > x){
                printf("No se encontro el nodo a eliminar\n");
                return -1;
            }
        }
    }else{
        printf("No se pueden eliminar cabeceras\n");
    }
};

//Recorrer el grafo eliminando sus nodos
//Recursivo
void eliminarGrafo(header* p){
    body * aux = p->nextBody;
    body * auxPrev = NULL;
    header * auxHead = NULL;
    while(aux->next!=NULL){ //Si el siguiente body es distinto de NULL
        auxPrev = aux;
        aux = aux->next;//Avanzamos al siguiente
        free(auxPrev);
    };
    free(aux);
    auxHead = p;
    if (p->nextHeader->vertice!=CORTE_DE_CARGA) eliminarGrafo(p->nextHeader); //Si el siguiente header no es NULL, lo mostramos
    free(auxHead);
};


header * buscarNodo(header* p,int value){
    printf("No implementado\n");
};