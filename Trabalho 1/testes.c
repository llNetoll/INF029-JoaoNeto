#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*int main(){

    int datavalida = 1,conti = 0,bissexto;

    char str[11],sdia[10],smes[10],sano[10];
    strcpy(str, "/9/2014");

    int j=0;
    for(int i=0;str[i]!='/';i++)
    {
        sdia[j]=str[i];
        j++;
        conti=i;
    }

    sdia[j] = '\0';

    if (str[conti+1] == '\0') datavalida = 0;

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

    printf("Dia: %d\n",dia);
    printf("Mes: %d\n",mes);
    printf("Ano: %d\n\n",ano);

    int diames[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        bissexto = 1;
    } else {
        bissexto =  0;
    }

    if(ano<100){
        ano = ano+2000;
    }

    if (mes < 1 || mes > 12 || dia < 1 || ano > 2025 || ano < 1000) {
        datavalida = 0;
    }
    else if (mes == 2 && dia == 29) {
        if (!bissexto)
            datavalida = 0;
    }
    else if (dia > diames[mes]) {
        datavalida = 0;
    }

    if(datavalida)
        printf("Data valida");
    else    
        printf("Data invalida");


}*/

/*int main(){

    int c=0,d=0,u=0,m=0;
    int num=4560;

    
    if(num>=1000){
        m=num/1000;
        c=(num%1000)/100;
        d=((num%1000)%100)/10;
        u=((num%1000)%100)%10;
        num=u*1000+d*100+c*10+m;
    }
    else if(num>=100){
        c=num/100;
        d=(num%100)/10;
        u=(num%100)%10;
        num=u*100+d*10+c;
    }
    else if(num>=10){
        d=num/10;
        u=num%10;
        num=u*10+c;
    }
    else{
        u=num;
    }
    
  

    //return num;
    printf("%d",num);

}*/

/*int main(){

    char sdia[10],smes[10],sano[10];
    int conti;
    char datainicial[11],datafinal[11];
    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "01/06/2016");

    int j=0;
    for(int i=0;datainicial[i]!='/';i++)
    {
        sdia[j]=datainicial[i];
        j++;
        conti=i;
    }


    j=0;
    for(int i=conti+2;datainicial[i]!='/';i++){
        smes[j]=datainicial[i];
        j++;
        conti=i;
    }

    smes[j] = '\0';

    j=0;
    for(int i=conti+2;datainicial[i]!='\0';i++){
        sano[j]=datainicial[i];
        j++;
        conti=i;
    }

    sano[j]='\0';

    int dia1 = atoi(sdia);
    int mes1 = atoi(smes);
    int ano1 = atoi(sano);

    
    printf("Dia: %d\n",dia1);
    printf("Mes: %d\n",mes1);
    printf("Ano: %d\n\n",ano1);

    j=0;
    for(int i=0;datafinal[i]!='/';i++)
    {
        sdia[j]=datafinal[i];
        j++;
        conti=i;
    }


    j=0;
    for(int i=conti+2;datafinal[i]!='/';i++){
        smes[j]=datafinal[i];
        j++;
        conti=i;
    }

    smes[j] = '\0';

    j=0;
    for(int i=conti+2;datafinal[i]!='\0';i++){
        sano[j]=datafinal[i];
        j++;
        conti=i;
    }

    sano[j]='\0';

    int dia2 = atoi(sdia);
    int mes2 = atoi(smes);
    int ano2 = atoi(sano);

    printf("Dia: %d\n",dia2);
    printf("Mes: %d\n",mes2);
    printf("Ano: %d\n\n",ano2);

}*/

int main(){

    char strTexto[250];
    char strTexto1[250];
    char strBusca[50];
    int posicoes[30];
    int j=0;
    int contp = 0;

    strcpy(strTexto, "Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca, "mui");

    for(int i=0;i < strlen(strTexto);i++)
    {
        if(strTexto[i]!=-61)
        {
            strTexto1[j]=strTexto[i];
            j++;
        }    
    }
    strTexto1[j] = '\0';

    for(int i=0;i < strlen(strTexto1);i++)
    {
        int achou=0;
        if(strTexto1[i] == strBusca[0])
        {
            int cont=1;
            for(j=i+1; cont < strlen(strBusca);j++)
            {
                if(strTexto1[j]==strBusca[cont]){
                    cont++;
                }
                else
                    break;

            }

            if(cont == strlen(strBusca))
                achou = 1;

        }
        if(achou)
        {
            posicoes[contp]=i+1;
            posicoes[contp+1]=i+(strlen(strBusca));
            contp = contp+2;
        }
    }

    printf("posicao 0: %d\n",posicoes[0]);
    printf("posicao 1: %d\n",posicoes[1]);
    printf("posicao 2: %d\n",posicoes[2]);
    printf("posicao 3: %d\n",posicoes[3]);
    printf("posicao 4: %d\n",posicoes[4]);
    printf("posicao 5: %d\n",posicoes[5]);

}