#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
	char input[500000];
	int tam, i, j, flag;
	
	while( gets(input) )
	{
		if ( !strcmp(input, "DONE") )
			break;
		
		flag = i = 0;
		tam = strlen(input);
		j = tam - 1;
		
		while (i < j)
		{
			while ( isalpha(input[i]) == 0  && i<j)
				++i;
			while ( isalpha(input[j]) == 0  && i<j)
				--j;
			
			if ( tolower(input[i]) != tolower(input[j]) )
			{
				flag = 1;
				break;
			}
			else
			{
				++i;
				--j;
			}
		}
		
		flag == 0 ? puts("You won't be eaten!") : puts("Uh oh..");
	}
	
	return 0;
}