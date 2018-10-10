#include "mlists.h"

void crearHeader(header*p){
    printf("\n Nuevo Header: ");
    scanf("%d",&p->vertice);
    if(p->vertice == 0)
        p->nextHeader = NULL;
    else
    {
        p->nextBody = (body*)malloc(sizeof(body));
        crearBody(p->nextBody);
        p->nextHeader = (header*)malloc(sizeof(header));
        crearHeader(p->nextHeader);
    }
}


void crearBody(body * p){
    printf("\n Nuevo body: ");
     scanf("%d",&p->vertice);
    if(p->vertice == 0)
        p->next = NULL;
    else
    {
        p->next = (body*)malloc(sizeof(body));
        crearBody(p->next);
    }
}
void mostrar(header*p){
    printf("\n");
    body * aux = p->nextBody;
    printf("\t %d",p->vertice); //Mostramos el vertice
    while(aux->next!=NULL){ //Si el siguiente body es distinto de NULL
        printf("\t %d",aux->vertice);//Mostramos su vertice
        aux = aux->next;//Avanzamos al siguiente
    };
    if (p->nextHeader->vertice!=0) mostrar(p->nextHeader); //Si el siguiente header no es NULL, lo mostramos
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