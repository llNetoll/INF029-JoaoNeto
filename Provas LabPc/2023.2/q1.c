#include <stdio.h>
#include <stdlib.h>

int pares(int N){

    if( N % 2 != 0)
        return 0;
    if(N > 0){
        return 0;
        printf("0");
    }
    else{
        printf("%d ",N);
        N = pares(N+2);
    }
        

}

int main(){
    pares(-6);
}