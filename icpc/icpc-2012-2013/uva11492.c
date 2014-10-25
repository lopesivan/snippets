#include <stdio.h>
#include <stdlib.h>

int _cmp (const void *a, const void *b)
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
int __cmp (const void *a, const void *b)
{
	int *c, *d;
	
	c = (int*)a;
	d = (int*)b;
	
	if (*c < *d)
		return 1;
	else if (*c > *d)
		return (-1);
	else 
		return 0;
}



int main()
{
	int t, v[10], _v[10], __v[10], _flag, __flag, i;
	
	scanf("%d", &t);
	puts("Lumberjacks:");
	
	while (t--)
	{
		__flag = _flag = 1;
		
		for (i=0; i<10; i++)
		{
			scanf("%d", v+i);
			__v[i] = _v[i] = v[i];
		}
		
		qsort(_v, 10, sizeof(int), _cmp); /*crescente*/
		qsort(__v, 10, sizeof(int), __cmp); /*decrescente*/
		
		for (i=0; i < 10; i++)
		{
			if (_v[i]!=v[i])
			{
				_flag = 0;
				break;
			}
		}
		
		for (i=0; i < 10; i++)
		{
			if (__v[i]!=v[i])
			{
				__flag = 0;
				break;
			}
		}
		
		_flag || __flag ? puts("Ordered") : puts("Unordered");
	}
	
	return 0;
}