#include <stdio.h>

int main()
{
	int t, i, c, d;
	float answer;
	
	scanf("%d",&t);
	
	for (i=1; i <= t; i++)
	{
		scanf("%d%d", &c, &d);
		
		answer = c + (float)d / 1.8;
		
		printf("Case %d: %.2f\n", i, answer);
	}
	
	return 0;
}