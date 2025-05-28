#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define NUM_BARCOS 6 

char tabuleiro1[TAM][TAM];
char tabuleiro2[TAM][TAM];

typedef struct {
    int tamanho;
    int quantidade;
} Barco;

Barco barcos[] = {
    {4, 1},
    {3, 1},
    {2, NUM_BARCOS - 5},
    {1, 3}
};

void inicializaTabuleiro(char tabuleiro[TAM][TAM]) {
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibeTabuleiro(char tabuleiro[TAM][TAM], int mostrarNavios) {
    printf("  ");
    for(int i = 0; i < TAM; i++) printf("%d ", i);
    printf("\n");
    
    for(int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for(int j = 0; j < TAM; j++) {
            if(tabuleiro[i][j] == 'N' && !mostrarNavios)
                printf("  ");
            else
                printf("[%c]", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int verificaPosicao(char tabuleiro[TAM][TAM], int x, int y, int tamanho, char orientacao) {
    if(orientacao == 'H') {
        if(y + tamanho > TAM) return 0;
        for(int i = 0; i < tamanho; i++)
            if(tabuleiro[x][y + i] != ' ') return 0;
    } else {
        if(x + tamanho > TAM) return 0;
        for(int i = 0; i < tamanho; i++)
            if(tabuleiro[x + i][y] != ' ') return 0;
    }
    return 1;
}

void posicionaBarcos(char tabuleiro[TAM][TAM]) {
    for(int i = 0; i < sizeof(barcos)/sizeof(barcos[0]); i++) {
        for(int q = 0; q < barcos[i].quantidade; q++) {
            int x, y;
            char orientacao;
            do {
                printf("Posicione barco de tamanho %d (H - horizontal, V - vertical): ", barcos[i].tamanho);
                scanf(" %c", &orientacao);
                printf("Digite linha e coluna inicial: ");
                scanf("%d %d", &x, &y);
            } while(!verificaPosicao(tabuleiro, x, y, barcos[i].tamanho, orientacao));
            
            for(int j = 0; j < barcos[i].tamanho; j++) {
                if(orientacao == 'H')
                    tabuleiro[x][y + j] = 'N';
                else
                    tabuleiro[x + j][y] = 'N';
            }
        }
    }
}

int atira(char tabuleiro[TAM][TAM], int x, int y) {
    if(x < 0 || x >= TAM || y < 0 || y >= TAM) {
        printf("Tiro fora do tabuleiro!\n");
        return 0;
    }
    if(tabuleiro[x][y] == 'N') {
        tabuleiro[x][y] = '0';
        printf("Acertou!\n");
        return 1;
    } else if(tabuleiro[x][y] == ' '){
        tabuleiro[x][y] = 'X';
        printf("Errou!\n");
    } else {
        printf("Posição já atacada!\n");
    }
    return 0;
}

int acabou(char tabuleiro[TAM][TAM]) {
    for(int i = 0; i < TAM; i++)
        for(int j = 0; j < TAM; j++)
            if(tabuleiro[i][j] == 'N')
                return 0;
    return 1;
}

void jogada(char atacante[TAM][TAM], char defensor[TAM][TAM]) {
    int x, y;
    printf("Digite coordenadas para atirar: ");
    scanf("%d %d", &x, &y);
    atira(defensor, x, y);
}

int main() {
    printf("### BATALHA NAVAL ###\n");
    
    inicializaTabuleiro(tabuleiro1);
    inicializaTabuleiro(tabuleiro2);
    
    printf("Jogador 1 posicione seus barcos:\n");
    posicionaBarcos(tabuleiro1);
    
    printf("Jogador 2 posicione seus barcos:\n");
    posicionaBarcos(tabuleiro2);
    
    int vez = 1;
    
    while(1) {
        printf("\n--- Tabuleiro Jogador 1 ---\n");
        exibeTabuleiro(tabuleiro1, 1);
        printf("--- Tabuleiro Jogador 2 ---\n");
        exibeTabuleiro(tabuleiro2, 1);
        
        if(vez == 1) {
            printf("\nJogador 1, sua vez:\n");
            jogada(tabuleiro1, tabuleiro2);
            if(acabou(tabuleiro2)) {
                printf("Jogador 1 venceu!\n");
                break;
            }
            vez = 2;
        } else {
            printf("\nJogador 2, sua vez:\n");
            jogada(tabuleiro2, tabuleiro1);
            if(acabou(tabuleiro1)) {
                printf("Jogador 2 venceu!\n");
                break;
            }
            vez = 1;
        }
    }
    
    return 0;
}
