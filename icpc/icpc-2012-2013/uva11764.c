#include <stdio.h>
#define MAX (50+10)

int main()
{
	int t, i, n, j, v[MAX], low, high;
	
	scanf("%d", &t);
	
	for (i = 1; i <= t; i++)
	{
		low = high = 0;
		
		scanf("%d", &n);
		
		for (j = 0; j < n; j++)
			scanf("%d", v + j);
		
		for (j = 0; j < n-1; j++)
		{
			if ( v[j+1] > v[j] )
				high++;
			else if ( v[j] > v[j+1] )
				low++;
		}
		
		printf("Case %d: %d %d\n", i, high, low);
	}
	return 0;
}