#include <stdio.h>
#include <stdlib.h>
#define MAX (20000+1000)

int cmp (const void *a, const void *b)
{
	return (*((int*)b)) - (*((int*)a));
}

int main()
{
	int t, i, n, v[MAX];
	long long int discount;
	
	scanf("%d", &t);
	
	while (t--)
	{
		discount = 0;
		scanf("%d", &n);
		
		for (i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		
		qsort(v, n, sizeof v[0], cmp);
		
		for (i = 2; i < n; i+=3)
			discount += v[i];
		
		printf("%lld\n", discount);
	}
	
	return 0;
}