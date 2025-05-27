#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirTabuleiro(char matriz[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        // Imprime cada linha do tabuleiro com divisórias verticais
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

        // Imprime a linha horizontal de separação (exceto após a última linha)
        if (i < 2)
            printf("---+---+---\n");
    }
}


int main()
{

    char matriz[3][3];
    char jogada[3];
    int v,h,acabou = 1, i , j, cont = 0;

    imprimirTabuleiro(matriz);

    while(acabou!=0)
    {
        //jogador 1
        printf("jogador 1 informe a sua jogada: ");
        scanf("%2s",jogada);

        if(jogada[0]=='A')
            v=0;
        if(jogada[0]=='B')
            v=1;
        if(jogada[0]=='C')
            v=2;


        if(jogada[1]=='1')
            h=0;
        if(jogada[1]=='2')
            h=1;
        if(jogada[1]=='3')
            h=2;

        matriz[v][h]='X';


        imprimirTabuleiro(matriz);


        //verificações na horizontal
        if(matriz[v][h]==matriz[v][h-1] && matriz[v][h]==matriz[v][h-2])
        {
            acabou=0;
            printf("Jogador 1 campeão!!");
            break;

        }

        if(matriz[v][h]==matriz[v][h+1] && matriz[v][h]==matriz[v][h+2])
        {
            acabou=0;
            printf("Jogador 1 campeão!!");
            break;

        }

        if(matriz[v][h]==matriz[v][h-1] && matriz[v][h]==matriz[v][h+1])
        {
            acabou=0;
            printf("Jogador 1 campeão!!");
            break;

        }

        //verificações na vertical
        if(matriz[v][h]==matriz[v-1][h] && matriz[v][h]==matriz[v-2][h])
        {
            acabou=0;
            printf("Jogador 1 campeão!!");
            break;

        }

        if(matriz[v][h]==matriz[v+1][h] && matriz[v][h]==matriz[v+2][h])
        {
            acabou=0;
            printf("Jogador 1 campeão!!");
            break;

        }

        if(matriz[v][h]==matriz[v-1][h] && matriz[v][h]==matriz[v+1][h])
        {
            acabou=0;
            printf("Jogador 1 campeão!!");
            break;

        }

        //Diagonal canto superior esquerdo
        if(matriz[v][h]==matriz[v+1][h+1] && matriz[v][h]==matriz[v+2][h+2])
        {
            acabou=0;
            printf("Jogador 1 campeão!!");
            break;

        }

        //Diagonal canto superior direito
        if(matriz[v][h]==matriz[v+1][h-1] && matriz[v][h]==matriz[v+2][h-2])
        {
            acabou=0;
            printf("Jogador 1 campeão!!");
            break;

        }

        //Diagonal canto inferior esquerdo
        if(matriz[v][h]==matriz[v-1][h+1] && matriz[v][h]==matriz[v-2][h+2])
        {
            acabou=0;
            printf("Jogador 1 campeão!!");
            break;

        }

        //Diagonal canto inferior direito
        if(matriz[v][h]==matriz[v-1][h-1] && matriz[v][h]==matriz[v-2][h-2])
        {
            acabou=0;
            printf("Jogador 1 campeão!!");
            break;

        }

        //Diagonais meio
        if(matriz[v][h]==matriz[v+1][h+1] && matriz[v][h]==matriz[v-1][h-1])
        {
            acabou=0;
            printf("Jogador 1 campeão!!");
            break;

        }

        if(matriz[v][h]==matriz[v-1][h+1] && matriz[v][h]==matriz[v+1][h-1])
        {
            acabou=0;
            printf("Jogador 1 campeão!!");
            break;

        }

        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(matriz[i][j]=='X' || matriz[i][j]=='0')
                    cont++;
                if(cont == 9)
                    acabou=0;
                    break;
            }
        }

        if(acabou==1)
        {

            //jogador 2
            printf("jogador 2 informe a sua jogada: ");
            scanf("%2s",jogada);

            if(jogada[0]=='A')
                v=0;
            if(jogada[0]=='B')
                v=1;
            if(jogada[0]=='C')
                v=2;


            if(jogada[1]=='1')
                h=0;
            if(jogada[1]=='2')
                h=1;
            if(jogada[1]=='3')
                h=2;

            matriz[v][h]='0';

            imprimirTabuleiro(matriz);

            //verificações na horizontal
            if(matriz[v][h]==matriz[v][h-1] && matriz[v][h]==matriz[v][h-2])
            {
                acabou=0;
                printf("Jogador 2 campeão!!");
                break;

            }

            if(matriz[v][h]==matriz[v][h+1] && matriz[v][h]==matriz[v][h+2])
            {
                acabou=0;
                printf("Jogador 2 campeão!!");
                break;

            }

            if(matriz[v][h]==matriz[v][h-1] && matriz[v][h]==matriz[v][h+1])
            {
                acabou=0;
                printf("Jogador 2 campeão!!");
                break;

            }

            //verificações na vertical
            if(matriz[v][h]==matriz[v-1][h] && matriz[v][h]==matriz[v-2][h])
            {
                acabou=0;
                printf("Jogador 2 campeão!!");
                break;

            }

            if(matriz[v][h]==matriz[v+1][h] && matriz[v][h]==matriz[v+2][h])
            {
                acabou=0;
                printf("Jogador 2 campeão!!");
                break;

            }

            if(matriz[v][h]==matriz[v-1][h] && matriz[v][h]==matriz[v+1][h])
            {
                acabou=0;
                printf("Jogador 2 campeão!!");
                break;

            }

            //Diagonal canto superior esquerdo
            if(matriz[v][h]==matriz[v+1][h+1] && matriz[v][h]==matriz[v+2][h+2])
            {
                acabou=0;
                printf("Jogador 2 campeão!!");
                break;

            }

            //Diagonal canto superior direito
            if(matriz[v][h]==matriz[v+1][h-1] && matriz[v][h]==matriz[v+2][h-2])
            {
                acabou=0;
                printf("Jogador 2 campeão!!");
                break;

            }

            //Diagonal canto inferior esquerdo
            if(matriz[v][h]==matriz[v-1][h+1] && matriz[v][h]==matriz[v-2][h+2])
            {
                acabou=0;
                printf("Jogador 2 campeão!!");
                break;

            }

            //Diagonal canto inferior direito
            if(matriz[v][h]==matriz[v-1][h-1] && matriz[v][h]==matriz[v-2][h-2])
            {
                acabou=0;
                printf("Jogador 2 campeão!!");
                break;

            }

            //Diagonais meio
            if(matriz[v][h]==matriz[v+1][h+1] && matriz[v][h]==matriz[v-1][h-1])
            {
                acabou=0;
                printf("Jogador 2 campeão!!");
                break;

            }

            if(matriz[v][h]==matriz[v-1][h+1] && matriz[v][h]==matriz[v+1][h-1])
            {
                acabou=0;
                printf("Jogador 2 campeão!!");
                break;

            }

        }
    }




    return 0;

}
