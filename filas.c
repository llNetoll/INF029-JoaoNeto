#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
}No;

void queue(No **fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    novo->valor = num;
    novo->proximo = NULL;

    if(*fila ==NULL)
        *fila = novo;
    else{
        aux = *fila;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }

    aux->proximo = novo;
    }

}

void dequeue(No **fila){
    No *aux;

    if(*fila == NULL)
        printf("A fila está vazia");
    else{
        aux = *fila;
        *fila = aux->proximo;
        free(aux);
    }
}

void imprimirfila(No *fila){
    while(fila){
        printf("%d -> ",fila->valor);
        fila = fila->proximo;
    }
}

int main(){

    No *fila = NULL;

    queue(&fila,1);
    queue(&fila,2);
    queue(&fila,3);
    queue(&fila,4);
    dequeue(&fila);
    dequeue(&fila);

    imprimirfila(fila);

}