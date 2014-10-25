/*via backtracking e recursão*
*a ideia é usar um índice para indexar todas as permutações
* por exemplo, ind=4 faz as permutações da 4ª letra (da direita para a esquerda) até a última letra
* ind=2 faz as permutações das duas últimas letras (2ª de trás pra frente e última letra)
*obviamente, ind=1 imprime a string
*assim, o algoritmo é no fundo uma dfs

*para fazer essa associação, t[strlen(t)-ind] é como se fosse t[-ind] no python, algo como acessar os indices de trás pra frente: 0123 vira 4321

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 11

char s[MAX];
int tam;

int cmp(const void *a, const void *b)
{
    return(strcmp((const char*)a,(const char*)b));
}

void profile (char *t, int a, int b)
{
    if (a!=b)
    {
        char temp=t[a];
        t[a]=t[b];
        t[b]=temp;
    }
}

void permutation(char *s, int ind)
{
    if (ind==1)
        puts(s);
    else
    {
        int i;
        char t[MAX];
        strcpy(t,s);

        for (i=0; i<ind; i++)
        {
            profile(t,tam-ind+0,tam-ind+i);
            permutation(t,ind-1);
        }
    }


}

int main()
{
    int n,i;
    scanf("%d",&n);

    for (i=0; i<n; i++)
    {
        scanf(" %s",s);
        tam=strlen(s);
        qsort(s,tam,sizeof s[0],cmp);
        permutation(s,tam);
        printf("\n");
    }

    return 0;
}
