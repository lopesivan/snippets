#include <stdio.h>
#define NMAX 1000

int main()
{
    int v[NMAX][NMAX];
    int i,j;
    int n;
    int soma, soma2,flag=0;

    scanf("%d",&n);

    /*adquire tudo*/
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%d",&v[i][j]);

    /*checa linhas*/
    for (i=0; i<n; i++)
    {
        soma=0;
        for (j=0; j<n; j++)
        {
            soma+=v[i][j];
        }
        if (!i)
            soma2=soma;
        else if (soma!=soma2)
        {
            flag=1;
            break;
        }

    }

    if (flag==1)
    {
        printf("0\n");
        return 0;
    }

    /*checa colunas*/
    for (j=0; j<n; j++)
    {
        soma=0;
        for (i=0; i<n; i++)
        {
            soma+=v[i][j];
        }
        if (soma!=soma2)
        {
            flag=1;
            break;
        }
    }

    if (flag==1)
    {
        printf("0\n");
        return 0;
    }

    /*diagonal1*/
    soma=0;
    for (i=0; i<n; i++)
        soma+=v[i][i];

    if (soma!=soma2)
        flag=1;

    if (flag==1)
    {
        printf("0\n");
        return 0;
    }

    /*diagonal2*/
    soma=0;
    for (i=0; i<n; i++)
        soma+=v[i][n-i-1];

    if (soma!=soma2)
        flag=1;

    if (flag==1)
    {
        printf("0\n");
        return 0;
    }

    if (!flag)
    {
        printf("%d\n",soma2);
        return 0;
    }
}
