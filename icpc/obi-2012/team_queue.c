#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int inicio=0, fim=0;

push (int *f, int v[][1000], int part)
{

}

int pop (int *f)
{
    if (fim!=inicio)
        return v[--fim];
}

int main()
{
    int v=0,i,j,teams, elementos;
    int vec[1000][1000];
    int fila[1000000];
    char s[10];
    int prox;

    scanf("%d",&teams);

    while (teams)
    {
        v++;

        for (j=0; j<teams; j++)
        {
            scanf("%d",&elementos);
            for (i=0;i<elementos; i++)
                scanf("%d",&vec[j][i]);
        }

        gets(s);

        while (strcmp(s,"STOP"))
        {

        }




        scanf("%d",&teams);
    }


    return 0;
}
