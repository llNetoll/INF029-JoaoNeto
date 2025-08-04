#include <stdio.h>
#include <stdlib.h>

int funcA(int x);
int funcB(int x);
int funcC(int x);


int funcA(int x){
    if(x == 0)
        return x;
    
    printf("%d ",x);
    x = x-1;

    return funcB(x);
}

int funcB(int x){
    if(x == 0)
        return x;

    printf("%d ",x);
    x = x-1;

    return funcC(x);
}

int funcC(int x){
    if(x == 0)
        return x;
    printf("%d ",x);
    x = x-1;

    return funcA(x);
}


int main(){

    funcA(4);
    return 0;

}

