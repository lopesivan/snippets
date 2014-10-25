#include <stdio.h>

int main()
{
	int a;
	
	while( scanf("%d",&a) )
	{
		if (!a)
			break;
		
		else
			printf("%d\n", a % 9 == 0 ? 9 : a % 9);
	}
	
	return 0;
}