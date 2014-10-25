#include <stdio.h>

#define mod(x) (((x)>=0) ? (x) : (-(x)))

int main()
{
	int t, n, answer;
	
	scanf("%d", &t);
	
	while (t--)
	{
		scanf("%d", &n);
		
		/*answer = (((63*n)+7492)*5)-498;*/
		answer = 315*n + 36962;
		
		printf("%d\n", mod((answer/10)%10) );
	}
	
	return 0;
}