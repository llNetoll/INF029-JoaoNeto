#include <stdio.h>
#include <stdlib.h>

void ImprimeInvertido(char vet[],int tamanhoString){

    tamanhoString--;
    if(tamanhoString >= 0){
        printf("%c",vet[tamanhoString]);
        ImprimeInvertido(vet,tamanhoString);
    }

    return;
}

int main(){

    char string[5]={'A','L','A','N','A'};

    ImprimeInvertido(string,5);
    return 0;
}
