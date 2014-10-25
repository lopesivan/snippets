#include <stdio.h>

#define mod(x) (((x)>=0) ? (x) : (40+(x)))

int main()
{
	int a, b, c, d;
	int graus;
	
	while ( scanf("%d%d%d%d", &a, &b, &c, &d) == 4 )
	{
		if ( ! (a || b || c || d) )
			break;
		
		graus = 120;
		
		graus += mod ((a-b) % 40) + mod((c-b) % 40) + mod((c-d)%40);
		
		
		printf("%d\n", graus*9);
	}
	
	return 0;
}