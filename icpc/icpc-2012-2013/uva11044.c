#include <stdio.h>

/*int min (int a, int b)
{
	return a <= b ? a : b;
}

int max (int a, int b)
{
	return a >= b ? a : b;
}*/

int calc (int x)
{
	x -= 2;
	
	if (x % 3 == 0)
		return x / 3;
	else
		return x / 3 + 1;
}

int main()
{
	int t, m, n;
	
	scanf("%d", &t);
	
	while (t--)
	{
		scanf("%d%d",&n, &m);
		
		printf("%d\n", calc(n) * calc (m) );
	}
	
	return 0;
}