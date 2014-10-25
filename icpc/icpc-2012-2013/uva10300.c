#include <stdio.h>

int main()
{
	int n, sum, f, a, b;
	
	scanf("%d", &n);
	
	while (n--)
	{
		sum = 0;
		scanf("%d", &f);
		
		while (f--)
		{
			scanf("%d%*d%d", &a, &b);
			sum += a*b;
			
		}
		
		printf("%d\n", sum);
	}
	return 0;
}