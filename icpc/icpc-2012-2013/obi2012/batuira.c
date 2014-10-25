#include <stdio.h>
#include <string.h>

#define infty 0x3f3f3f3f
#define MAX 100+5
#define min(a,b) a<b?(a):(b)

int adj[MAX][MAX];
int custo[MAX][MAX];
int n;

void floyd()
{
    int i,j,k;
    /*inicio*/
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
            if (adj[i][j])
                custo[i][j]=adj[i][j];
            else
                custo[i][j]=infty;
        }
    for (i=0; i<n; i++)
        custo[i][i]=0;

    for (k=0; k<n; k++)
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                custo[i][j]=min(custo[i][j], custo[i][k]+custo[k][j]);
}

int main()
{
    int x,y,z,v=0;

    while ( scanf("%d",&n)!=EOF)
    {
        if (!n)
            break;
        memset(adj,0,sizeof adj);

        while(1)
        {
            scanf("%d%d%d",&x,&y,&z);
            if (!(x || y || z))
                    break;
            x--,y--;
            adj[x][y]=adj[y][x]=z;
        }

        floyd();

        printf("Teste %d\n%d\n\n",++v,custo[0][n-1]);
    }

    return 0;
}
