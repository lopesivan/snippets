#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tab[8][8];
int tab2[8][8];

void ataca(int linha, int coluna)
{
	int i, j;
	
	++tab2[linha][coluna];
	
	for (i = -1; i <= 1; ++i)
		for (j = -1; j <= 1, (i || j); ++j)
		{
			
		}
}

int main()
{
	int t, i, j;
	
	scanf("%d", &t);
	
	while (t--)
	{
		for (i = 0; i < 8; ++i)
			for (j = 0; j < 8; ++j)
				scanf("%d%d", &tab[i][j]);
			
		memset(tab2, 0, sizeof tab2);
	}
	
	return 0;
}