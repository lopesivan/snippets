#include <stdio.h>
#include <string.h>

int main()
{
	int n,k,fat=1,mod;
	char input[25];
	
	scanf("%d%*c",&n);
	
	gets(input);
	k=strlen(input);
	
	mod=n%k;
	
	for (; n != mod ; n-=k)
	{
		fat*=n;
	}
	
	if (mod!=0)
		fat*=mod;
		
	printf("%d",fat);	
	
	return 0;
}