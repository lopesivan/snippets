#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp (const void *a, const void *b)
{
	int *c, *d;
	
	c = (int*)a;
	d = (int*)b;
	
	if (*c > *d)
		return 1;
	else if (*c < *d)
		return (-1);
	else
		return 0;
}

int main()
{
	int n, i, tmp, j, inicio = 1;
	int v[100];
	
	while( scanf("%d", &n) == 1 )
	{
		for (i = 0; i < 100; i++)
			v[i] = 0;
		inicio = 1;
		
		if (!n)
			break;
		
		for (i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			v[tmp]++;
		}
		
		/*qsort(v, 100, sizeof v[0], cmp);*/
		
		for (i = 0; i < 100; i++)
		{
			if (v[i] != 0)
			{
				for (j = 0; j < v[i]; j++)
				{
					if (inicio)
						printf("%d", i);
					else
						printf(" %d", i);
					inicio = 0;
				}
			}
		}
		puts("");
	}
	
	return 0;
} 
