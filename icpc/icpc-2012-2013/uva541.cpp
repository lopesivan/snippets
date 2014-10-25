#include <cstdio>

#define MAX (100+10)

using namespace std;

int main()
{
	int n, i, j, imparlinhas, imparcolunas, sum, lastlinha, lastcoluna;
	int m[MAX][MAX];
	
	while (scanf("%d", &n) == 1)
	{
		if (!n)
			break;
		
		imparlinhas = imparcolunas = 0;
		
		//pega matriz
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				scanf("%d", &m[i][j]);
		
		//impar das linhas
		for (i = 0; i < n; ++i)
		{
			sum = 0;
			for  (j = 0; j < n; ++j)
				sum += m[i][j];
			if (sum%2 == 1)
			{
				++imparlinhas;
				lastlinha = i+1;
			}
		}		
		
		//impar das colunas
		for (j = 0; j < n; ++j)
		{
			sum = 0;
			for  (i = 0; i < n; ++i)
				sum += m[i][j];
			if (sum%2 == 1)
			{
				++imparcolunas;
				lastcoluna = j+1;
			}
		}
		
		if (!imparcolunas  && !imparlinhas)
			puts("OK");
		else if (imparcolunas == 1 && imparlinhas == 1)
			printf("Change bit (%d,%d)\n", lastlinha, lastcoluna);
		else
			puts("Corrupt");
		
	}
	
	
	return 0;
}