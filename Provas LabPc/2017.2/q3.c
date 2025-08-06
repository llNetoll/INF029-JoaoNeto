
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerarquivo(){

    FILE *arq = fopen("arquivo.txt","r");
    FILE *arq1 = fopen("resuldado.ads","w");

    int faltas;
    float media;
    char matricula[20];
    char linha[100];
    char status[30];

    while(fgets(linha,sizeof(linha),arq) != NULL){
        sscanf(linha,"%[^;];%f;%d",matricula,&media,&faltas);

        if(faltas >= 10)
            strcpy(status,"Reprovado por falta");
        else if(media>=5)
            strcpy(status,"Aprovado por media");
        else
            strcpy(status,"Reprovado por media");

        fprintf(arq1,"%s;%s\n",matricula,status);
    }

    fclose(arq);
    fclose(arq1);

}

int main(){
    lerarquivo();
}