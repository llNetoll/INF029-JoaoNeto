#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char matriz[3][3];
    char jogada[3];
    int v,h,acabou = 1;

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

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(matriz[i][j]=='X' || matriz[i][j]=='0')
                    printf("%c ",matriz[i][j]);
                else
                    printf(" ");
            }
            printf("\n");

        }

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

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(matriz[i][j]=='X' || matriz[i][j]=='0')
                    printf("%c ",matriz[i][j]);
                else
                    printf(" ");
            }
            printf("\n");

        }

        acabou=0;

    }







    return 0;

}
