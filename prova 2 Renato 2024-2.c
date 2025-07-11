#include <stdio.h>
#include <stdlib.h>

/*void alocaEspaco(int **p, int num){
    *p = (int *) malloc(num * sizeof(int));
}

int main(){
    int *p = NULL;
    int num;
    scanf("%d",&num);

    alocaEspaco(&p,num);
}*/

typedef struct vetores{
    int *vetorprincipal[10];
    int tamanhoestrutura[10];
    int quantidadeelementosestrutura[10];
}Vetores;


typedef struct no{
    int valor;
    struct no *proximo;
    struct no *anterior;
}No;

void pegaDados(Vetores v,int posicao,int vetoraux[]){
    float soma=0;

    if(v.quantidadeelementosestrutura[posicao] != 0){

        for(int i=0;i<v.quantidadeelementosestrutura[posicao];i++)
        {
            soma = soma + v.vetorprincipal[posicao][i];
        }

        float media = soma/v.quantidadeelementosestrutura[posicao];

        int j = 0;

        for(int i=0;i<v.quantidadeelementosestrutura[posicao];i++)
        {
            if(v.vetorprincipal[posicao][i]>media){
                vetoraux[j] = v.vetorprincipal[posicao][i];
                j++;

            }
        }
    }
    else
        printf("Sem estrutura auxiliar nessa posição");
    
}

void inserirDados(Vetores v,No **lista){
    

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<v.quantidadeelementosestrutura[i];j++)
        {
            No *novo = malloc(sizeof(No));
            if(v.quantidadeelementosestrutura[i]>0){
                novo->valor = v.vetorprincipal[i][j];
                if(*lista == NULL){
                    *lista = novo;
                    novo->proximo = NULL;
                    novo->anterior = NULL;
                }
                else{
                    novo->proximo = *lista;
                    novo->anterior = NULL;
                    (*lista)->anterior = novo;
                    *lista = novo;
                    
                }
                    
                    
            }
        }
    }


}