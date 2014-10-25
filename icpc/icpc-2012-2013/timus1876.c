#include <stdio.h>

int max (int a, int b)
{
	if (a>=b)
		return a;
	else
		return b;
}

int main()
{
	int a,b;
	
	scanf("%d%d",&a,&b);
	
	printf("%d", max( (2*b+40) , 2*a+39) ); /*mais na direita, mais na esquerda*/
	
	
	
	return 0;
}