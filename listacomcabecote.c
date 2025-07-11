#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

void criarlista(Lista *lista){
    lista->inicio = NULL;
    lista->inicio = 0;
}

void inserirnoinicio(Lista *lista,int num){
    No *novo = malloc(sizeof(No));

    novo->valor =  num;
    novo->proximo = NULL;
    novo->proximo = lista->inicio;
    lista->inicio = novo;

}

void inserirnofinal(Lista *lista,int num){
    No *novo = malloc(sizeof(No));
    No *aux;

    novo->valor = num;
    novo->proximo = NULL;
    aux = lista->inicio;

    while(aux->proximo != NULL)
        aux = aux->proximo;

    aux->proximo = novo;

    
    
}