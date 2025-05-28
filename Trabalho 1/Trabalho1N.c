// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: João de Souza Morais Neto
//  email: joaomoraisneto2000@gmail.com
//  Matrícula: 20242160004
//  Semestre: 2025.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "Trabalho1N.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char * str)
{
  int datavalida = 1,conti=0,bissexto;
  char sdia[10],smes[10],sano[10];

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

  int dia = atoi(sdia);
  int mes = atoi(smes);
  int ano = atoi(sano);

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        bissexto = 1;
    } else {
        bissexto = 0;
    }

  int diames[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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

  if (datavalida)
      return 1;
  else
      return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    int conti=0,bissexto;
    
    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{


      char sdia[10],smes[10],sano[10];

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

    //----------------------------------------------Data final-----------------------------------------------------

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

    int diames[13] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((ano2 % 4 == 0 && ano2 % 100 != 0) || (ano2 % 400 == 0)){
      diames[3] = 29;
    }
    
      //verifique se a data final não é menor que a data inicial
      if(ano2<ano1){
        dma.retorno = 4;
        return dma;
      }
      else if(ano1==ano2 && mes1>mes2){
        dma.retorno = 4;
        return dma;
      }
      else if(ano1==ano2 && mes1==mes2 && dia1>dia2){
        dma.retorno = 4;
        return dma;
      }
      //calcule a distancia entre as datas
      else{
        int ano = ano2 - ano1;
        int mes = mes2 - mes1;
        int dia = dia2 - dia1;

        if(dia<0){
          mes--;
          dia = dia + diames[mes2-1];
        }
        if(mes<0){
          ano--;
          mes = mes + 12;
        }

        dma.qtdAnos=ano;
        dma.qtdMeses=mes;
        dma.qtdDias=dia;

      }

      //se tudo der certo
      dma.retorno = 1;
      return dma;
      

      }



    }

    
 


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
 
  int qtdOcorrencias=0;

  if (!isCaseSensitive){
    if(c>=97 && c<=122)
      c=c-32;
    
    for(int i = 0; texto[i]!='\0';i++)
    {
      if(texto[i]>=97 && texto[i]<=122)
        texto[i]=texto[i]-32;       
    }  
  }    
      

   for(int i=0; texto[i]!='\0';i++){
    if(texto[i]==c){
      qtdOcorrencias++;
    }

   }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, 
    deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", 
    e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrências = 0;
    char strTexto1[250];
    int j=0;
    int contp = 0;

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

            if(cont == strlen(strBusca)){
              achou = 1;
              qtdOcorrências++;
            }
              
            

        }
        if(achou)
        {
            posicoes[contp]=i+1;
            posicoes[contp+1]=i+(strlen(strBusca));
            contp = contp+2;
        }
    }

    return qtdOcorrências;

}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
  int m=0,c=0,d=0,u=0;

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
      num=u*10+d;
  }
  else{
      u=num;
  }
  
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0, cont, i;
    char strbase[10], strbusca[6];

    if(numerobusca<10)
    {
      itoa(numerobase, strbase, 10);
      itoa(numerobusca, strbusca, 10);

      for(i=0;i<strlen(strbase);i++)
      {
        if(strbase[i]==strbusca[0])
          qtdOcorrencias++;
      }
    }
    else
    {

    itoa(numerobase, strbase, 10);
    itoa(numerobusca, strbusca, 10);

    for(int i=0;i<strlen(strbase);i++)
      cont = 1;
      if(strbase[i]==strbusca[0])
        {
          for(int j=i+1;cont<strlen(strbusca);j++)
          {
            if(strbase[j]==strbusca[cont]){
              cont++;
            }
          }
          if(cont==strlen(strbusca))
            qtdOcorrencias++;
        }
      }


    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
 {
     int achou = 0, j ,l , i;
     char clone[6];


    for(int i=0;i<8;i++)
    {
        for(int j=0;j<10;j++)
        {
            if (matriz[i][j]==palavra[0])
            {
                int cont = 1;
                for(int k=j+1;cont<strlen(palavra);k++)
                {
                    if(palavra[cont]==matriz[i][k])
                    {
                        cont++;
                    }
                    else break;
                }
                if(cont==strlen(palavra))
                    achou=1;
            }
        }
      }

    if(achou==0)                                   
    {
      for(int i=4,j=0;j<strlen(palavra);i--,j++){        //função para inverter as strings caso nao ache
        clone[j]=palavra[i];
      }
      clone[5]='\0';
    }

    //verificação após inversão
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<10;j++)
        {
            if (matriz[i][j]==clone[0])
            {
                int cont = 1;
                for(int k=j+1;cont<strlen(clone);k++)
                {
                    if(clone[cont]==matriz[i][k])
                    {
                        cont++;
                    }
                    else break;
                }
                if(cont==strlen(clone))
                    achou=1;
            }
        }
    }

    //diagonal - cima esqueda
    for(i=0;i<8;i++)
    {
        for(j=0;j<10;j++)
        {
            if (matriz[i][j]==palavra[0])
            {
                int cont = 1;
                for(int k=j-1,l=i-1;cont<strlen(palavra);k--,l--)
                {
                    if(palavra[cont]==matriz[l][k])
                    {
                        cont++;
                    }
                    else break;
                }
                if(cont==strlen(palavra))
                    achou=1;
            }
        }
    }

    //diagonal baixo direita
    for(i=0;i<8;i++)
    {
        for(j=0;j<10;j++)
        {
            if (matriz[i][j]==palavra[0])
            {
                int cont = 1;
                for(int k=j+1,l=i+1;cont<strlen(palavra);k++,l++)
                {
                    if(palavra[cont]==matriz[l][k])
                    {
                        cont++;
                    }
                    else break;
                }
                if(cont==strlen(palavra))
                    achou=1;
            }
        }
    }
      
    //diagonal cima direita
    for(i=0;i<8;i++)
    {
        for(j=0;j<10;j++)
        {
            if (matriz[i][j]==palavra[0])
            {
                int cont = 1;
                for(int k=j+1,l=i-1;cont<strlen(palavra);k++,l--)
                {
                    if(palavra[cont]==matriz[l][k])
                    {
                        cont++;
                    }
                    else break;
                }
                if(cont==strlen(palavra))
                    achou=1;
            }
        }
    }

    //diagonal baixo esquerda
    for(i=0;i<8;i++)
    {
        for(j=0;j<10;j++)
        {
            if (matriz[i][j]==palavra[0])
            {
                int cont = 1;
                for(int k=j-1,l=i+1;cont<strlen(palavra);k--,l++)
                {
                    if(palavra[cont]==matriz[l][k])
                    {
                        cont++;
                    }
                    else break;
                }
                if(cont==strlen(palavra))
                    achou=1;
            }
        }
    }

  

     return achou;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}

