#include <stdio.h>
#include <string.h>
#define MAX (1025)
#define max(a,b) (((a)>=(b)) ? (a) : (b))
#define min(a,b) (((a)<=(b)) ? (a) : (b))

int main()
{
	int t, tab[MAX][MAX], d, n, i, j, k, x, y, tmp, px, py, kill;
	
	scanf("%d", &t);
	
	while(t--)
	{
		memset(tab, 0, sizeof tab);
		px  = py = (-1);
		kill = 0;
		
		scanf("%d%d", &d, &n);
		
		for (k = 0; k < n; ++k)
		{
			scanf("%d%d%d", &x, &y, &tmp);
			
			for (i = max(0, x - d); i <= min(MAX-1, x + d); ++i)
				for (j = max(0, y - d); j <= min(MAX-1, y + d); ++j)
					tab[i][j] += tmp;
		}
		
		for (i = 0; i < MAX; ++i)
			for (j = 0; j < MAX; ++j)
				if (tab[i][j] > kill)
				{
					kill = tab[i][j];
					px = i;
					py = j;
				}
				
		printf("%d %d %d\n", px, py, kill);
	}
	
	return 0;
}