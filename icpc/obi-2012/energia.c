#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100 /*n = número de nos*/

int pai[N];
int mark[N];
int adj[N][N];

int e, l;

/*implementacoes de fila nao-circular*/

int fila[N];
int inicio=0, fim=0;

int queue(int a)
{
    if (a<N)
       fila[fim++]=a;
    else
        printf("Fila cheia! = Buffer Overflow\n");
}

int dequeue()
{
    if (inicio!=fim)
       return fila[inicio++];
    else
        return -1;
}

/*bfs*/

void bfs (int r) /*r = nó raiz*/
{
     inicio=fim=0;
     int i, node;

     queue(r);
     mark[r]=0;
     pai[r]=-1;

     while ((node=dequeue()) != -1)
     {

         for (i=0; i<e; i++)
         {
             if (adj[node][i]==1 && mark[i]==-1)
             {
                queue(i);
                pai[i]=node;
                mark[i]=mark[node]+1;

             }
         }

     }

}

int main()
{

    int v=0, i;
    int flag;
    int n1,n2;

    scanf("%d%d",&e,&l);

    while (e || l)
    {
            memset(mark, -1, sizeof mark);
            memset(adj, 0, sizeof adj);
            memset(pai, 0, sizeof pai);

            flag=0;

            for (i=0; i<l; i++)
            {
                scanf("%d%d",&n1,&n2);
                adj[n1-1][n2-1]=adj[n2-1][n1-1]=1;
            }

            bfs(0);

            printf("Teste %d\n", ++v);

            for (i=0; i<e; i++)
            {
                if (mark[i]==-1)
                {
                   printf("falha\n\n");
                   flag=1;
                   break;
                }
            }

            if (!flag)
               printf("normal\n\n");

            scanf("%d%d",&e,&l);
    }




    return 0;
}

