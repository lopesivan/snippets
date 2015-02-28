#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 50 /*n = n�mero de nos*/

int cmp(const void *a, const void *b)
{
    int *c , *d;
    c = (int * ) a;
    d = (int * ) b;

    if (*c > *d)
       return 1;
    else if(*c < *d)
       return -1;

    return 0;
}

int p,j; /*para indicar numero de pedagios*/
int pai[N];
int mark[N];
int adj[N][N];
int saida[N];

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

void bfs (int r) /*r = n� raiz*/
{
     int i, node;
     j=0;

     queue(r);
     mark[r]=0;
     pai[r]=-1;


     while ((node=dequeue()) != -1)
     {

         for (i=0; i<N; i++)
         {
             if (adj[node][i]==1 && mark[i]==-1)
             {
                queue(i);
                pai[i]=node;
                mark[i]=mark[node]+1;

                if (mark[i]<=p)
                {
                   saida[j]=i+1;
                   j++;
                }
             }
         }

     }

     qsort(saida, j, sizeof (saida[0]), cmp);


}

int main()
{

    int v=0,i,c,e,l;
    int n1,n2;

    scanf("%d%d%d%d",&c,&e,&l,&p);

    while (c || e || l || p)
    {
          memset(mark, -1, sizeof mark);
          memset(adj, 0, sizeof adj);
          memset(pai, 0, sizeof pai);
          inicio=fim=0;

          for (i=0; i<e; i++)
          {
              scanf("%d%d",&n1,&n2);
              adj[n1-1][n2-1]=adj[n2-1][n1-1]=1;
          }

          printf("Teste %d\n",++v);

          bfs(l-1);

          for (i=0; i<j; i++)
              printf("%d ",saida[i]);

          printf("\n\n");


          scanf("%d%d%d%d",&c,&e,&l,&p);
    }


    return 0;
}

