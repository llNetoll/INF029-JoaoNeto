#include <stdio.h>
#include <stdlib.h>

lerlinhaporlinha(FILE *arq){
    int numero;

    if(fscanf(arq,"%d",&numero)== 1){
        printf("%d\n",numero);

        lerlinhaporlinha(arq);
    }
    
}  