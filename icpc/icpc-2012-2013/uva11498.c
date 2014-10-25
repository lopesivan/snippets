#include <stdio.h>

int main()
{
	int n, a, b, c, d;
	
	while ( scanf("%d", &n) )
	{
		if (!n)
			break;
		
		scanf("%d%d", &a, &b);
		
		while (n--)
		{
			scanf("%d%d", &c, &d);
			
			if (a==c || b==d)
				puts("divisa");
			else if (c < a && d > b)
				puts("NO");
			else if (c < a && d < b)
				puts("SO");
			else if (c > a && d > b)
				puts("NE");
			else /*c > a && d < b*/
				puts("SE");
				
		}
	}
	
	return 0;
}