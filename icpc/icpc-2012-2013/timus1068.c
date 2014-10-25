#include <stdio.h>

int main()
{
	int n;
	int sum=0;
	
	scanf("%d",&n);
	
	if (n>=1)
		sum= (1+n)*n/2;
	
	else
		sum = (1+n)*(-n+2)/2;
	
	printf("%d",sum);
	
	
	return 0;
}