#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX (10001+100)

int main()
{
	char input[MAX], str[MAX];
	char tab[110][110];
	int t, i, j, m, tam, sq, k, flag;
	
	scanf("%d%*c", &t);
	
	for (i = 1; i <= t; i++)
	{
		flag = 0;
		sq = 0;
		gets(input);
		tam = strlen(input);
		
		for (j = 0; j < tam; j++)
			if ( isalpha( input[j] ) )
				str[sq++] = input[j];
			
		k  = (int) sqrt (sq);
		
		if ( k * k != sq)
			printf("Case #%d:\nNo magic :(\n", i);
		else
		{
			/*preenche tab*/
			for (m = 0; m < k; m++)
				for (j = 0; j < k; j++)
					tab[m][j] = str[m*k + j];
			
			/*checa os 3 casos*/
			for (m = 0; m < k; m++)
			{
				for (j = 0; j < k; j++)
					if (tab[m][j] != tab[j][m])
					{
						flag = 1;
						break;
					}
			}
			
			for (m = 0; m < k; m++)
			{
				for (j = 0; j < k; j++)
					if (tab[m][j] != tab[k-m-1][k-j-1])
					{
						flag = 1;
						break;
					}
			}
			
			for (m = 0; m < k; m++)
			{
				for (j = 0; j < k; j++)
					if (tab[m][j] != tab[k-j-1][k-m-1])
					{
						flag = 1;
						break;
					}
			}
				
			flag == 1 ? printf("Case #%d:\nNo magic :(\n", i) : printf("Case #%d:\n%d\n", i, k) ;
		}
	}
	return 0;
}