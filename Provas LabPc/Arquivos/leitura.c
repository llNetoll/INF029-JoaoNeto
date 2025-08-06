#include <stdio.h>

int main(){
    char vetor[4][20];

    FILE *arq = fopen("familia.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
    
    fgets(vetor[0],10,arq);
    fgets(vetor[1],10,arq);
    fgets(vetor[2],10,arq);
    fgets(vetor[3],10,arq);

    fclose(arq);

    printf("%s",vetor[0]);
    printf("%s",vetor[1]);
    printf("%s",vetor[2]);
    printf("%s",vetor[3]);
}