#include <stdio.h>
#include <string.h>

#define N 100

void dfs(int v);

int e,l;

int mark[N];
int pai[N];
int adj[N][N];

void dfs(int v)
{
     int i;

     if (!mark[v])
     {
        mark[v]=1;
        for (i=0; i<e; i++)
        {
            if (adj[v][i] && !mark[i])
            {
               pai[i]=v;
               dfs(i);
            }
        }
     }


}

int main()
{

    int v=0,i;
    int n1,n2;
    int flag;

    scanf("%d%d",&e,&l);

    while (e || l)
    {
        flag=0;

        memset(mark, 0, sizeof mark);
        memset(pai, 0, sizeof pai);
        memset(adj, 0, sizeof adj);

        for (i=0; i<l; i++)
        {
            scanf("%d%d",&n1,&n2);
            adj[n1-1][n2-1]=adj[n2-1][n1-1]=1;
        }

        dfs(0);

        printf("Teste %d\n",++v);

        for (i=0; i<e; i++)
        {
            if (!mark[i])
            {
               flag=1;
               printf("falha\n\n");
               break;
            }
        }

        if(!flag)
        {
                 printf("normal\n\n");
        }


        scanf("%d%d",&e,&l);
    }

    return 0;
}

