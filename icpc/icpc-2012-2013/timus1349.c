/* Tip: Last Fermat's Theorem */

#include <stdio.h>

int main()
{
	int n;
	
	scanf("%d",&n);
	
	if (n==0 || n>2)
		printf("%d",-1);
	
	else if (n==1)
		printf("%d %d %d",1,2,3);
	
	else if (n==2)
		printf("%d %d %d", 3,4,5);
	
	return 0;
	
}