#include <stdio.h>

typedef struct no{
    int valor;
    struct no proximo;
}No;



void imprimirlista(No *lista){


    if(lista == NULL)
        return;

    imprimirlista(lista -> proximo);
    printf(lista->valor); 


}