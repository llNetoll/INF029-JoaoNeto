#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

int* vetorPrincipal[TAM];
int tamanhoEstrutura[TAM];
int quantidadeElementos[10];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    posicao--;

    int retorno = 0;
    // se posição é um valor válido {entre 1 e 10}
    if(posicao < 0 || posicao > 9){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    // a posicao pode já existir estrutura auxiliar
    else if(vetorPrincipal[posicao]!=NULL){
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    // o tamanho ser muito grande                                                   //Depois checar se tem um padrão
    else if(tamanho > 10){
        retorno = SEM_ESPACO_DE_MEMORIA;
        return retorno;
    }
    // o tamanho nao pode ser menor que 1
    else if(tamanho < 1){
        retorno = TAMANHO_INVALIDO;
        return retorno;
    }    
    // deu tudo certo, crie
    else{
        vetorPrincipal[posicao] = (int*) malloc(tamanho*sizeof(int));
        retorno = SUCESSO;
        tamanhoEstrutura[posicao]=tamanho;
        quantidadeElementos[posicao]=0;

        return retorno;
    }

    

}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
    int Espaco = 0;

    posicao--;
    if(posicao<0||posicao>9)
        posicao_invalida=1;
    if (posicao_invalida)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if(vetorPrincipal[posicao]!=NULL)
            existeEstruturaAuxiliar=1;

        if (existeEstruturaAuxiliar)
        {
            if(quantidadeElementos[posicao]<tamanhoEstrutura[posicao])
                temEspaco = 1;
            else
                temEspaco = 0;

            if (temEspaco)
            {
                vetorPrincipal[posicao][quantidadeElementos[posicao]]=valor;
                quantidadeElementos[posicao]++;
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno=0;

    posicao--;
    if(posicao<0||posicao>9){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    else if(vetorPrincipal[posicao]==NULL){
        retorno=SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    else if(quantidadeElementos[posicao]==0){
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
    }
    else{
        quantidadeElementos[posicao]--;
        retorno = SUCESSO;
        return retorno;
    }

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno=0;
    int i;

    posicao--;
    if(posicao<0||posicao>9){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    else if(vetorPrincipal[posicao]==NULL){
        retorno=SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    else if(quantidadeElementos[posicao]==0){
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
    }
    else{
        for(i=0;i<quantidadeElementos[posicao];i++){
            if(vetorPrincipal[posicao][i]==valor)
                break;
        }
        if(i==quantidadeElementos[posicao]){
            retorno = NUMERO_INEXISTENTE;
            return retorno;
        }

        for(int j=i;j<quantidadeElementos[posicao]-1;j++){
            vetorPrincipal[posicao][j]=vetorPrincipal[posicao][j+1];
        }
        quantidadeElementos[posicao]--;
        retorno = SUCESSO;
        return retorno;
    }

}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;
    posicao--;
    if(posicao<0||posicao>9){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    else if(vetorPrincipal[posicao]==NULL){
        retorno=SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    else{
        for(int i=0;i<quantidadeElementos[posicao];i++){
            vetorAux[i]=vetorPrincipal[posicao][i];
            retorno = SUCESSO;
        }
         return retorno;
    }
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;

    posicao--;
    if(posicao<0||posicao>9){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    if(vetorPrincipal[posicao]==NULL){
        retorno=SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    int n = quantidadeElementos[posicao];

    for (int i = 0; i < n; i++) {
        vetorAux[i] = vetorPrincipal[posicao][i];
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i-1; j++) {
            if (vetorAux[j] > vetorAux[j + 1]) {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temp;
            }
        }
    }
    retorno = SUCESSO;
    return retorno;
}


/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int contvet = 0;
    int i;
    int retorno = 0;

    for(int i=0; i<10; i++){
            for(int j=0;j<quantidadeElementos[i];j++){
               vetorAux[contvet] = vetorPrincipal[i][j];
               contvet++;
            }
    }
    if(contvet==0){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
        return retorno;
    }
    else
        retorno=SUCESSO;

    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    int contvet = 0;
    int i,n;

    for(int i=0; i<10; i++){
        for(int j=0;j<quantidadeElementos[i];j++){
            vetorAux[contvet] = vetorPrincipal[i][j];
            contvet++;
        }
    }
    if(contvet==0){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
        return retorno;
    }
    n = contvet;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i-1; j++) {
            if (vetorAux[j] > vetorAux[j + 1]) {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temp;
            }
        }
    }
    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;

    posicao--;
    if(posicao<0||posicao>9){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    if(vetorPrincipal[posicao]==NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }


    novoTamanho = novoTamanho +  tamanhoEstrutura[posicao];
    if(novoTamanho > 10){
        retorno = SEM_ESPACO_DE_MEMORIA;
        return retorno;
    }
    if(novoTamanho<1){
        retorno = NOVO_TAMANHO_INVALIDO;
        return retorno;
    }

    int* temp = (int*) realloc(vetorPrincipal[posicao], novoTamanho * sizeof(int));

    vetorPrincipal[posicao]=temp;

    if (quantidadeElementos[posicao] > novoTamanho)
        quantidadeElementos[posicao] = novoTamanho;

    tamanhoEstrutura[posicao] = novoTamanho;

    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
        int retorno = 0;


    posicao--;
    if(posicao<0||posicao>9){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    if(vetorPrincipal[posicao]==NULL){
        retorno=SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    if(quantidadeElementos[posicao]==0){
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
    }

    return quantidadeElementos[posicao];


}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    for(int i=0; i<10; i++){
        vetorPrincipal[i]=NULL;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
}
