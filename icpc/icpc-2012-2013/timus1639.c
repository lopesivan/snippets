#include <stdio.h>

int main()
{
	int a,b;
	
	scanf("%d%d",&a,&b);
	
	if ( (a*b)%2 == 0)
		printf("[:=[first]");
	else
		printf("[second]=:]");
	
	return 0;
}