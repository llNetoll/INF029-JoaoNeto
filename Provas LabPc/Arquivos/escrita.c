#include <stdio.h>

int main(){


    FILE *arq = fopen("familia.txt","w");
    if(arq){
        fprintf(arq,"Neto\n");
        fprintf(arq,"Carol\n");
        fprintf(arq,"Jan\n");
        fprintf(arq,"Rafa\n");
    }
    else
        printf("Não foi possível ler o arquivo");

}