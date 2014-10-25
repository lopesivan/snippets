#include <stdio.h>

#define max(a,b) (((a)>=(b)) ? (a):(b))
#define min(a,b) (((a)<=(b)) ? (a):(b))

int main()
{
	int t, i, a, b, c, x, y, answer;
	
	scanf("%d", &t);
	
	for (i=1; i<=t; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		
		x = max(a, max(b, c));
		y = min(a, min(b, c));
		
		if (a!= x && a!=y)
			answer = a;
		else if (b!=x && b!=y)
			answer = b;
		else
			answer = c;
		
		printf("Case %d: %d\n", i, answer);
	}
	
	return 0;
}