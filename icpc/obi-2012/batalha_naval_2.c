#include <stdio.h>
#include <string.h>

#define MAX 100+5
#define AGUA 0
#define NAVIO 1
#define ACERTOU 2
#define VISITEI 3

int n,m,navios=0;
int tab[MAX][MAX];
/*dir,bot,left,top*/
int viz[4][2]={{1,0},{0,-1},{-1,0},{0,1}};

/*espécie de dfs para coordenadas*/
int busca(int x, int y)
{
    if (x<0 || y<0 || x>=n || y>=m || tab[x][y]==VISITEI || tab[x][y]==AGUA)
        return 1;

    int temp=1,i;

    /*o ideal é retornar 1. mas basta encontrar um 0 (navio) na dfs para retornar zero! (e lógico)*/
    if (tab[x][y]==NAVIO)
        temp=0;

    tab[x][y]=VISITEI;

    for (i=0; i<4; i++)
    {
        int retbusca=   busca( x+viz[i][0]   ,  y+viz[i][1]   );
        temp=retbusca && temp;
    }

    return temp;

}

int main()
{
    int i,j;
    int k,l,c;
    char celula;

    scanf("%d%d",&n,&m);

    /*pega tabuleiro*/
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
        {
            scanf(" %c",&celula);

            if (celula=='.')
                tab[i][j]=AGUA;
            else if (celula=='#')
                tab[i][j]=NAVIO;
        }

    /*pega disparos*/
    scanf("%d",&k);

    for (i=0; i<k; i++)
    {
        scanf("%d%d",&l,&c);
        l--,c--;

        if (tab[l][c]==NAVIO)
            tab[l][c]=ACERTOU;
    }

    /*realiza buscas*/
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
        {
            if (tab[i][j]==ACERTOU)
            {
                navios+=busca(i,j);
            }
        }

    printf("%d",navios);


    return 0;
}
