#include <stdio.h>
#include <stdlib.h>
#define MAX (50000)

int v[MAX];

/* 1 5 (7) 8 9 13 18 23*/

int buscaUp(int key, int inicio, int fim)
{
	int tmp;
	int meio = (inicio + fim)/2;
	
	if (inicio == fim)
		return (-1);
	
	if (v[meio] <= key)
		return buscaUp(key, meio+1, fim);
	else /*(v[meio] > key)*/
	{
		tmp =  buscaUp(key, inicio, meio);
		return tmp == -1 ? meio : tmp;
	}
}
int buscaDown(int key, int inicio, int fim)
{
	int tmp;
	int meio = (inicio + fim)/2;
	
	if (inicio == fim)
		return (-1);
	
	if (v[meio] >= key)
		return buscaDown(key, inicio, meio);
	else /*(v[meio] < key)*/
	{
		tmp = buscaDown(key, meio+1, fim);
		return tmp == (-1) ? meio : tmp;
	}
}

int main()
{
	int n, q, i, next, up, down;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; ++i)
		scanf("%d", &v[i]);
	
	scanf("%d", &q);
	
	for (i = 0; i < q; ++i)
	{
		scanf("%d", &next);
		
		up = buscaUp(next, 0, n);
		down = buscaDown(next, 0, n);
		
		down == (-1) ? printf("X ") : printf("%d ", v[down]);
		up == (-1) ? printf("X\n") : printf("%d\n", v[up]);
	}
	
	return 0;
}