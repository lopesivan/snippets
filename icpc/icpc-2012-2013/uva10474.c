#include <stdio.h>
#include <stdlib.h>
#define MAX (1000000)

int v[MAX], n;

int pos(int meio)
{
	int i;
	
	/*for (i = meio; i > 0; --i)
	{
		if (v[i-1] == v[i])
			--meio;
		else
			break;
	}*/
	
	i = meio;
	while ( i > 0 && v[i-1] == v[i])
		--meio, --i;
		
	return meio;
}

int busca(int key, int inicio, int fim)
{
	int meio = (inicio + fim)/2;
	
	if (inicio == fim)
		return (-1);
	
	if (v[meio] == key)
		return pos(meio);
	else if (v[meio] > key)
		return busca(key, inicio, meio);
	else /*v[meio] < key*/
		return busca(key, meio+1, fim);
}

int cmp (const void *a, const void *b)
{
	int *c, *d;
	
	c = (int*) a;
	d = (int*) b;
	
	if (*c > *d)
		return 1;
	else if (*c < *d)
		return (-1);
	else
		return 0;
}

int main()
{
	int q, i, next, var, t = 0;
	
	while ( scanf("%d%d", &n, &q), n || q)
	{
		printf("CASE# %d:\n", ++t);
		
		for (i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		
		qsort(v, n, sizeof v[0], cmp);
		
		for (i = 0; i < q; ++i)
		{
			scanf("%d", &next);
			
			var = busca(next, 0, n);
			
			if ( var == -1)
				printf("%d not found\n", next);
			else
				printf("%d found at %d\n", next, var+1);
		}
	}
	
	return 0;
}