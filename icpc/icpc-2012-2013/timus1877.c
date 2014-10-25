#include <stdio.h>

int main()
{
	char l1[5],l2[5];
	
	scanf("%s%*c%s",l1,l2);
	
	if ( (l1[3]-'0')%2 == 0 || (l2[3]-'0')%2 == 1 )
		puts("yes");
	
	else
		puts("no");
	
	
	return 0;
}