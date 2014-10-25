#include <stdio.h>

int main()
{
    int ano, prox;
    scanf("%d",&ano);
    
    prox = ano + 76 - ((ano-1986)%76);
    
    printf("%d",prox);
    
    
    return 0;
}