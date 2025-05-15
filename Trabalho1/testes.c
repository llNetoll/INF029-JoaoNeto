#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int bissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int main(){

    int datavalida = 1,conti;

    char str[11],sdia[10],smes[10],sano[10];

    strcpy(str, "29/02/23");

    int j=0;
    for(int i=0;str[i]!='/';i++)
    {
        sdia[j]=str[i];
        j++;
        conti=i;
    }

    sdia[j] = '\0';

    j=0;
    for(int i=conti+2;str[i]!='/';i++){
        smes[j]=str[i];
        j++;
        conti=i;
    }

    smes[j] = '\0';

    j=0;
    for(int i=conti+2;str[i]!='\0';i++){
        sano[j]=str[i];
        j++;
        conti=i;
    }

    sano[j]='\0';
    
    printf("Dia: %s\n",sdia);
    printf("Mes: %s\n",smes);
    printf("Ano: %s\n\n",sano);

    int dia = atoi(sdia);
    int mes = atoi(smes);
    int ano = atoi(sano);

    int diames[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(ano<100){
        ano = ano+2000;
    }

    if (mes < 1 || mes > 12 || dia < 1 || ano > 2025 || ano < 1000) {
        datavalida = 0;
    }
    else if (mes == 2 && dia == 29) {
        if (!bissexto(ano))
            datavalida = 0;
    }
    else if (dia > diames[mes]) {
        datavalida = 0;
    }

    
    printf("Dia inteiro: %d\n", dia);
    printf("Mes inteiro: %d\n", mes);
    printf("Ano inteiro: %d\n\n", ano);

    if(datavalida)
        printf("Data valida");
    else    
        printf("Data invalida");


}