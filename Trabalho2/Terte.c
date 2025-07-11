#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserirnoinicio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
    novo->valor=num;
    novo->proximo=*lista;

    *lista=novo;
    }
    else
        printf("Erro ao alocar memória");
}

void inserirnofinal(No **lista, int num){
    No *novo = malloc(sizeof(No));
    No *aux;

    novo->valor = num;
    novo->proximo = NULL;

        if(*lista==NULL)
            *lista=novo;
        else{
            aux = *lista;
            while(aux->proximo != NULL)
                aux = aux->proximo;       
            aux->proximo = novo;
        }
}

void inserirnomeio(No **lista, int elementoAnterior, int num){
    No *novo = malloc(sizeof(No));
    No *aux;

    novo->valor = num;
    aux = *lista;
    if(*lista==NULL){
        novo->proximo=NULL;
        *lista = novo;
    }
    else{
        while(aux->valor != elementoAnterior && aux->proximo != NULL)
            aux = aux->proximo;

        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }


}

void mostrarlista(No *no){
    printf("\nLista: ");
    while(no){
        printf("%d -> ",no->valor);
        no = no->proximo;


    }
    printf("\n\n");
}

int main(){
    No *lista=NULL;

    inserirnoinicio(&lista,10);
    inserirnoinicio(&lista,22);
    inserirnoinicio(&lista,13);
    inserirnoinicio(&lista,5);
    inserirnoinicio(&lista,40);

    mostrarlista(lista);

    inserirnofinal(&lista,11);
    inserirnomeio(&lista,5,4); 

    mostrarlista(lista);
}