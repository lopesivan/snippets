#include <cstdio>
#include <cstring>

char tab[50][50];
int gold, h, w;
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int ros[8][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,1}, {1,-1}, {-1,-1} };

bool check(int i, int j)
{
	int k;
	
	for (k = 0; k < 4; ++k)
	{
		if (tab[i + dir[k][0]][j + dir[k][1]] == 'T')
			return false;
	}
	
	return true;
}

void dfs(int i, int j)
{
	/*if (i < 0 || i >= 50 || j < 0 || j>= 50)
		return;*/
	
	if (tab[i][j] == '#' || tab[i][j] == 'T')
		return;
	
	if (tab[i][j] == 'G')
		gold++;
	
	tab[i][j] = '!';
	
	
	int k; 
	
	for (k = 0; k < 4; ++k)
	{
		if ( (tab[i + dir[k][0]][j + dir[k][1]] != '!' ) && check(i, j) )
			dfs( i + dir[k][0], j + dir[k][1]);
	}
}

int main()
{
	int i, j, px, py;
	
	while ( scanf("%d%d%*c", &h, &w) == 2 )
	{
		memset(tab, 0, sizeof tab);
		gold = 0;
		
		for (i = 0; i < w; i++)
		{
			for (j = 0; j < h; j++)
			{
				scanf("%c", &tab[i][j]);
				if (tab[i][j] == 'P')
					px = i, py = j;
			}
			getchar();
		}
		
		/*for (i = 0; i < w; i++)
		{
			for (j = 0; j < h; j++)
				printf("%c", tab[i][j]);
			puts("");
		}*/
		
		dfs(px, py);
		
		printf("%d\n", gold);
	}
	
	return 0;
}