#include <stdio.h>
#include <string.h>

#define MAX (4+1)
#define BLOCK -1
#define SPACE 0
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

void ataca(int,int,int,int), imprimetab(void);
void solve(int,int);

int tab[MAX][MAX];
int n;
int maxpam;

/*a ideia é a seguinte:
*se tem um espaço em branco, então eu o ataco (preenchendo ele e os adjacentes)
*além disso, consegui mais uma torre para a minha contagem, então chamo solve recursivamente com maxrook+1 (que inicialmente é zero, por sinal)
*faço isso até não haver mais nenhum espaço em branco
*nesse caso, segue que maxpam já possui o valor máximo que eu consegui adentrar na árvore (i.e., o maior maxrook+1 que eu consegui alcançar!)
*/

void solve(int n, int maxrook)
{
    int i,j;

    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (tab[i][j]== SPACE)
            {
                ataca(i,j,n,1);
                solve(n,maxrook+1);
                maxpam=max(maxpam,maxrook+1);
                ataca(i,j,n,-1);
            }
        }
    }

}

/*imprime tabuleiro para debug*/
void imprimetab()
{
    printf("\n****************************\n");
    int i,j;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
            printf("%2d ",tab[i][j]);
        printf("\n");
    }
    printf("\n****************************\n");
}

/*soma t a todos os vizinhos de r antes dos blocos*/
void ataca(int r, int c, int n, int t)
{
    int i,x,y;

    for (i=-1; i<=1; i+=2)
    {
        for (x=r, y=c; x>=0 && y>=0 && x<n && y<n ; x+=i)
        {
            if (tab[x][y] == BLOCK)
                break;
            else
                tab[x][y]+=t;
        }

        for (x=r, y=c; x>=0 && y>=0 && x<n && y<n ; y+=i)
        {
            if (tab[x][y]==BLOCK)
                break;
            else
                tab[x][y]+=t;
        }
    }
}

int main()
{
    int i,j;
    char c;
    while (scanf("%d",&n) != EOF)
    {
        if(!n)
            break;
        memset(tab,0,sizeof tab);
        maxpam=0;

        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                {
                    scanf(" %c",&c);
                    if (c=='.')
                        tab[i][j]=SPACE;
                    else if (c=='X')
                        tab[i][j]=BLOCK;
                }

        solve(n,0);

        printf("%d\n",maxpam);
    }

    return 0;
}
