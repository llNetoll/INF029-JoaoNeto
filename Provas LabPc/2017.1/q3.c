#include <stdio.h>

void transfere(){
    int num;

    FILE *arq = fopen("prova.txt","r");
    FILE *arq1 = fopen("prova.ads","wb");

    if(arq && arq1){
        while(fscanf(arq,"%d",&num)==1){

            fwrite(&num ,sizeof(num),1,arq1);

        }
        fclose(arq);
        fclose(arq1);
    }
    else
        printf("erro na abertura dos arquivos");
}

void lertransfere(){

    FILE *arq1 = fopen("prova.ads","rb");

    if(arq1){
        int num;
        while(fread(&num,sizeof(num),1,arq1)==1){
            printf("%d\n",num);
        }
        fclose(arq1);
    }
    else{
        printf("Erro ao abrir o arquivo");
    }

}

int main(){
    transfere();
    lertransfere();
}