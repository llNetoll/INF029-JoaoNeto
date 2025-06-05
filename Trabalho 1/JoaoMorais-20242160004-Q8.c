#include <stdio.h>

void imprimirTabuleiro(char matriz[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matriz[i][j] == 'X' || matriz[i][j] == '0')
                printf(" %c ", matriz[i][j]);
            else
                printf("   ");
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("---+---+---\n");
    }
}

int main()
{
    char matriz[3][3] = {0};
    char jogada[3];
    int v, h, acabou = 1, i, j, cont = 0;

    imprimirTabuleiro(matriz);

    while (acabou != 0)
    {
        // Jogador 1
        marco:
        printf("Jogador 1 informe a sua jogada: ");
        scanf("%2s", jogada);

        if (jogada[0] == 'A' || jogada[0] == 'a') v = 0;
        if (jogada[0] == 'B' || jogada[0] == 'b') v = 1;
        if (jogada[0] == 'C' || jogada[0] == 'c') v = 2;

        if (jogada[1] == '1') h = 0;
        if (jogada[1] == '2') h = 1;
        if (jogada[1] == '3') h = 2;

        
        if((jogada[0] != 'A' && jogada[0] != 'B' && jogada[0] != 'C' && jogada[0] != 'a' && jogada[0] != 'b' && jogada[0] != 'c') || (jogada[1] != '1' && jogada[1] != '2' && jogada[1] != '3'))
        {
            printf("Jogada Invalida\n\n");
            goto marco;
        }


        if(matriz[v][h]=='X' || matriz[v][h]=='0')
        {
            printf("PosiCao invalida, tente novamente.\n\n");
            goto marco;
        }
        else
        {
            matriz[v][h] = 'X';
        }
        
        imprimirTabuleiro(matriz);

        // Verificações de vitória

        // Horizontal
        if (h - 2 >= 0 && matriz[v][h] == matriz[v][h - 1] && matriz[v][h] == matriz[v][h - 2])
        {
            acabou = 0;
            printf("Jogador 1 campeao!!\n");
            break;
        }
        if (h + 2 <= 2 && matriz[v][h] == matriz[v][h + 1] && matriz[v][h] == matriz[v][h + 2])
        {
            acabou = 0;
            printf("Jogador 1 campeao!!\n");
            break;
        }
        if (h - 1 >= 0 && h + 1 <= 2 && matriz[v][h] == matriz[v][h - 1] && matriz[v][h] == matriz[v][h + 1])
        {
            acabou = 0;
            printf("Jogador 1 campeao!!\n");
            break;
        }

        // Vertical
        if (v - 2 >= 0 && matriz[v][h] == matriz[v - 1][h] && matriz[v][h] == matriz[v - 2][h])
        {
            acabou = 0;
            printf("Jogador 1 campeao!!\n");
            break;
        }
        if (v + 2 <= 2 && matriz[v][h] == matriz[v + 1][h] && matriz[v][h] == matriz[v + 2][h])
        {
            acabou = 0;
            printf("Jogador 1 campeao!!\n");
            break;
        }
        if (v - 1 >= 0 && v + 1 <= 2 && matriz[v][h] == matriz[v - 1][h] && matriz[v][h] == matriz[v + 1][h])
        {
            acabou = 0;
            printf("Jogador 1 campeao!!\n");
            break;
        }

        // Diagonais
        if (v + 2 <= 2 && h + 2 <= 2 && matriz[v][h] == matriz[v + 1][h + 1] && matriz[v][h] == matriz[v + 2][h + 2])
        {
            acabou = 0;
            printf("Jogador 1 campeao!!\n");
            break;
        }
        if (v + 2 <= 2 && h - 2 >= 0 && matriz[v][h] == matriz[v + 1][h - 1] && matriz[v][h] == matriz[v + 2][h - 2])
        {
            acabou = 0;
            printf("Jogador 1 campeao!!\n");
            break;
        }
        if (v - 2 >= 0 && h + 2 <= 2 && matriz[v][h] == matriz[v - 1][h + 1] && matriz[v][h] == matriz[v - 2][h + 2])
        {
            acabou = 0;
            printf("Jogador 1 campeao!!\n");
            break;
        }
        if (v - 2 >= 0 && h - 2 >= 0 && matriz[v][h] == matriz[v - 1][h - 1] && matriz[v][h] == matriz[v - 2][h - 2])
        {
            acabou = 0;
            printf("Jogador 1 campeao!!\n");
            break;
        }
        if (v - 1 >= 0 && v + 1 <= 2 && h - 1 >= 0 && h + 1 <= 2 &&
            matriz[v][h] == matriz[v + 1][h + 1] && matriz[v][h] == matriz[v - 1][h - 1])
        {
            acabou = 0;
            printf("Jogador 1 campeao!!\n");
            break;
        }
        if (v - 1 >= 0 && v + 1 <= 2 && h - 1 >= 0 && h + 1 <= 2 &&
            matriz[v][h] == matriz[v - 1][h + 1] && matriz[v][h] == matriz[v + 1][h - 1])
        {
            acabou = 0;
            printf("Jogador 1 campeao!!\n");
            break;
        }

        // Verificação de empate
        cont = 0;
        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                if (matriz[i][j] == 'X' || matriz[i][j] == '0')
                    cont++;
        if (cont == 9)
        {
            acabou = 0;
            printf("Empate!\n");
            break;
        }

        // Jogador 2
        marco1:
        printf("Jogador 2 informe a sua jogada: ");
        scanf("%2s", jogada);

        if (jogada[0] == 'A' || jogada[0] == 'a') v = 0;
        if (jogada[0] == 'B' || jogada[0] == 'b') v = 1;
        if (jogada[0] == 'C' || jogada[0] == 'c') v = 2;

        if (jogada[1] == '1') h = 0;
        if (jogada[1] == '2') h = 1;
        if (jogada[1] == '3') h = 2;

        if((jogada[0] != 'A' && jogada[0] != 'B' && jogada[0] != 'C' && jogada[0] != 'a' && jogada[0] != 'b' && jogada[0] != 'c') || (jogada[1] != '1' && jogada[1] != '2' && jogada[1] != '3'))
        {
            printf("Jogada Invalida.\n\n");
            goto marco1;
        }


        if(matriz[v][h]=='X' || matriz[v][h]=='0')
        {
            printf("PosiCao invalida, tente novamente.\n\n");
            goto marco1;
        }
        else
        {
            matriz[v][h] = '0';
        }
        imprimirTabuleiro(matriz);

        // Verificações de vitória para jogador 2
        if (h - 2 >= 0 && matriz[v][h] == matriz[v][h - 1] && matriz[v][h] == matriz[v][h - 2])
        {
            acabou = 0;
            printf("Jogador 2 campeao!!\n");
            break;
        }
        if (h + 2 <= 2 && matriz[v][h] == matriz[v][h + 1] && matriz[v][h] == matriz[v][h + 2])
        {
            acabou = 0;
            printf("Jogador 2 campeao!!\n");
            break;
        }
        if (h - 1 >= 0 && h + 1 <= 2 && matriz[v][h] == matriz[v][h - 1] && matriz[v][h] == matriz[v][h + 1])
        {
            acabou = 0;
            printf("Jogador 2 campeao!!\n");
            break;
        }

        if (v - 2 >= 0 && matriz[v][h] == matriz[v - 1][h] && matriz[v][h] == matriz[v - 2][h])
        {
            acabou = 0;
            printf("Jogador 2 campeao!!\n");
            break;
        }
        if (v + 2 <= 2 && matriz[v][h] == matriz[v + 1][h] && matriz[v][h] == matriz[v + 2][h])
        {
            acabou = 0;
            printf("Jogador 2 campeao!!\n");
            break;
        }
        if (v - 1 >= 0 && v + 1 <= 2 && matriz[v][h] == matriz[v - 1][h] && matriz[v][h] == matriz[v + 1][h])
        {
            acabou = 0;
            printf("Jogador 2 campeao!!\n");
            break;
        }

        if (v + 2 <= 2 && h + 2 <= 2 && matriz[v][h] == matriz[v + 1][h + 1] && matriz[v][h] == matriz[v + 2][h + 2])
        {
            acabou = 0;
            printf("Jogador 2 campeao!!\n");
            break;
        }
        if (v + 2 <= 2 && h - 2 >= 0 && matriz[v][h] == matriz[v + 1][h - 1] && matriz[v][h] == matriz[v + 2][h - 2])
        {
            acabou = 0;
            printf("Jogador 2 campeao!!\n");
            break;
        }
        if (v - 2 >= 0 && h + 2 <= 2 && matriz[v][h] == matriz[v - 1][h + 1] && matriz[v][h] == matriz[v - 2][h + 2])
        {
            acabou = 0;
            printf("Jogador 2 campeao!!\n");
            break;
        }
        if (v - 2 >= 0 && h - 2 >= 0 && matriz[v][h] == matriz[v - 1][h - 1] && matriz[v][h] == matriz[v - 2][h - 2])
        {
            acabou = 0;
            printf("Jogador 2 campeao!!\n");
            break;
        }
        if (v - 1 >= 0 && v + 1 <= 2 && h - 1 >= 0 && h + 1 <= 2 &&
            matriz[v][h] == matriz[v + 1][h + 1] && matriz[v][h] == matriz[v - 1][h - 1])
        {
            acabou = 0;
            printf("Jogador 2 campeao!!\n");
            break;
        }
        if (v - 1 >= 0 && v + 1 <= 2 && h - 1 >= 0 && h + 1 <= 2 &&
            matriz[v][h] == matriz[v - 1][h + 1] && matriz[v][h] == matriz[v + 1][h - 1])
        {
            acabou = 0;
            printf("Jogador 2 campeao!!\n");
            break;
        }
    }

    return 0;
}
