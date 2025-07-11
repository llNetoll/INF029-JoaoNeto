#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void push(No **topo, int num){
    No *novo = malloc(sizeof(No));

    novo->valor = num;
    novo->proximo = NULL;

    if(*topo == NULL)
        *topo = novo;
    else{
        novo->proximo = *topo;
        *topo = novo;
    }

}

void pop(No **topo){
    No *aux;
    aux = *topo;

    if(*topo == NULL)
        printf("Pilha vazia");
    else{
        *topo = aux->proximo;
        free(aux);
    }
}

void imprimirpilha(No *topo){
    printf("\n-----------TOPO-----------\n");
    while(topo != NULL){
        printf("%d\n",topo->valor);
        topo = topo->proximo;
    }
    printf("-----------Fim-----------");

}

int main(){

    No *topo = NULL;

    push(&topo,2);
    push(&topo,56);
    push(&topo,13);
    push(&topo,12);
    push(&topo,7);
    push(&topo,3);
    imprimirpilha(topo); 

    pop(&topo);
    pop(&topo);
    pop(&topo);
    imprimirpilha(topo); 




}
    
    