#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX (100000)

int main()
{
	char s[MAX];
	int tam, i, count, j;
	
	while ( gets(s) )
	{
		tam = strlen(s);
		count = 0;
		
		for (i = 0, j = 0; i < tam; i++)
		{
			if ( isalpha(s[i]) )
				j=1;
			else if (j != 0)
				count++, j = 0;
		}
		
		if (j!=0)
			count++;
			
		printf("%d\n", count);
	}
	
	return 0;
}