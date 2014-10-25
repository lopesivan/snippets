#include <stdio.h>

int main()
{
	int t,a,b;
	
	scanf("%d",&t);
	
	while (t--)
	{
		scanf("%d%d",&a,&b);
		
		if (a < b)
			putchar('<');
		else if(a > b)
			putchar('>');
		else
			putchar('=');
		
		puts("");
		
	}
	
	
	return 0;
}