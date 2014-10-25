#include <stdio.h>
#include <stdlib.h>
#define MAX (10001+100)
#define min(a,b) (((a)<=(b)) ? (a) : (b));

int cmp (const void *a, const void *b)
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
	int n, i, j, impar, flag;
	int d[MAX];
	long long int sum, sumtmp;
	
	while (scanf("%d", &n), n)
	{
		flag = impar = sum = 0;
		
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", d+i);
			
			/*if (d[i] >= n || d[i] < 0)
				flag = 1;*/
			
			if (d[i] % 2)
				++impar;
		}
		
		if (impar % 2)
			flag = 1;
		
		/*erdos-gallai (1960)*/
		qsort(d+1, n, sizeof d[0], cmp);
		
		for (i = 1; i <= d[1]; ++i)
		{
			sum += d[i];
			sumtmp = (long long) i * (long long) (i-1);
			
			for (j = i+1; j <= n; ++j)
				sumtmp += (long long)  min(i, d[j]);
			
			if ( sum > sumtmp)
				flag = 1;
		}
		
		flag == 0 ? puts("Possible") : puts("Not possible");
	}
	
	return 0;
}