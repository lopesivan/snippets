#include <stdio.h>
#include <string.h>

#define MAX (30)

char input[MAX];
char output[MAX];
int tam, i;


char reverse (char c)
{
	switch(c)
	{
		case 'A': return 'A';
		case 'H': return 'H';
		case 'I': return 'I';
		case 'M': return 'M';
		case 'O': return 'O';
		case 'T': return 'T';
		case 'U': return 'U';
		case 'V': return 'V';
		case 'W': return 'W';
		case 'X': return 'X';
		case 'Y': return 'Y';
		case '1': return '1';
		case '8': return '8';
		case 'E': return '3';
		case 'J': return 'L';
		case 'L': return 'J';
		case 'S': return '2';
		case 'Z': return '5';
		case '2': return 'S';
		case '3': return 'E';
		case '5': return 'Z';
		default: return 'a';
	}
}

int pal()
{
	tam = strlen(input);
	
	for (i = 0; i < tam; i++)
		output[i] = input[tam-1-i];
	output[tam]='\0';
	
	return strcmp(input, output) == 0 ? 1 : 0;
}

int mir()
{
	tam = strlen(input);
	
	for (i = 0; i < tam; i++)
		output[i] = reverse (input[tam-1-i]);
	output[tam]='\0';
	
	return strcmp(input, output) == 0? 1 : 0;
}

int main()
{
	while ( gets(input) )
	{
		printf("%s", input);
		if ( pal() && mir() )
			puts(" -- is a mirrored palindrome.\n");
		else if ( pal() )
			puts(" -- is a regular palindrome.\n");
		else if ( mir() )
			puts(" -- is a mirrored string.\n");
		else
			puts(" -- is not a palindrome.\n");
	}
	
	return 0;
}