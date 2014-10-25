#include <stdio.h>

#define mod(x) ((x)>=0? (x) : (-(x)))

int main()
{
	int n;
	long long int s, d, a, b;
	
	scanf("%d", &n);
	
	while(n--)
	{
		scanf("%lld%lld", &s, &d);
		
		/* a + b = s
		 * a - b = d
		 * a = (s + d)/2
		 * b = (s - d)/2
		 */
		b = (s - d)/2;
		a = (s + d)/2;
		
		if (b < 0 || (s%2)!=(d%2) )
			puts("impossible");
		else
			printf("%lld %lld\n", a, b);
	}
	
	return 0;
}