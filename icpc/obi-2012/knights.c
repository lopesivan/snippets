#include <stdio.h>
#include <string.h>
#define MAX (500+5)

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

void ataca(int,int,int),ptab(void), solve(int);

int k,m,n;
int tab[MAX][MAX];

int cav[8][2]=
{
	{2,1},
	{2,-1},
	{-2,1},
	{-2,-1},
	{1,2},
	{1,-2},
	{-1,2},
	{-1,-2}
};

void ataca(int r,int c,int inc) /*soma inc a vizinhanca atacavel do cavalo em (r,c)*/
{
	int i;
	
	for (i=0; i<8; i++)
	{
		if (r+cav[i][0] >= 0 && r+cav[i][0] <m && c+cav[i][1]>=0 && c+cav[i][1]<n)
			tab[r+cav[i][0]][c+cav[i][1]]+=inc;
	}
	
	tab[r][c]+=inc;
}

void ptab() /*imprime o tabuleiro, para debug*/
{
	int i,j;
	for (j=0; j<m; j++)
	{
		for (i=0; i<n; i++)
			printf("%d ",tab[j][i]);
		puts("");
	}
}

void solve(int level)
{
	int i,j;
	
	for (j=0; j<m; j++)
		for (i=0; i<n; i++)
			if (tab[i][j]==0)
			{
				ataca(i,j,1);
				solve(level+1);
				k=max(k,level+1);
				ataca(i,j,-1);
			}
}

int main()
{	
	while (scanf("%d%d",&m,&n) == 2)
	{	
		if (!(m || n))
			break;
		memset(tab,0,sizeof tab);
		k=0;
		
		solve(0);
		printf("%d knights may be placed on a %d row %d column board.\n",k,m,n);
	}
	
	return 0;
	
}