#include <stdio.h>

#define DOT (0)
#define MINE (-1)
#define MAX (100+10)

int main()
{
	char x;
	int n,m,v=0,i,j,a,b;
	int tab[MAX][MAX];
	
	scanf("%d%d%*c",&n,&m);
	
	while (1)
	{
		v++;
		
		/*adquire*/
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				x = getchar();
				
				if (x == '.')
					tab[i][j]=DOT;
				else
					tab[i][j]=MINE;
			}
			getchar();
		}
		
		/*processa*/
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
			{
				if (tab[i][j]==MINE)
				{
					for (a = -1; a<=1; a++)
						for (b=-1; b<=1; b++)
						{
							if (!a && !b)
								continue;
							else
							{
								if ((i+a < n) && (i+a >= 0) && (j+b >= 0) && (j+b < m))
									if (tab[i+a][j+b] != MINE)
										tab[i+a][j+b]++;
							}
						}
				}
			}
		
		/*imprime*/
		printf("Field #%d:\n",v);
		
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				if (tab[i][j]==MINE)
					putchar('*');
				else
					printf("%d",tab[i][j]);
			}
			puts("");
		}
		
		scanf("%d%d%*c",&n,&m);
		
		if (!n && !m)
			break;
		else
			puts("");
	}
	
	return 0;
}