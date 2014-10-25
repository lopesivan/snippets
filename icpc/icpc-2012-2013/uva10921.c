#include <stdio.h>

#define MAX (100001+100)

int main()
{
	char input[MAX];
	int i;
	
	while( gets(input) )
	{
		for (i = 0; input[i]; i++)
		{
			switch (input[i])
			{
				case '-':
				case '1':
				case '0':
					putchar(input[i]);
					break;
				case 'A':
				case 'B':
				case 'C':
					putchar('2');
					break;
				case 'D':
				case 'E':
				case 'F':
					putchar('3');
					break;
				case 'G':
				case 'H':
				case 'I':
					putchar('4');
					break;
				case 'J':
				case 'K':
				case 'L':
					putchar('5');
					break;
				case 'M':
				case 'N':
				case 'O':
					putchar('6');
					break;
				case 'P':
				case 'Q':
				case 'R':
				case 'S':
					putchar('7');
					break;
				case 'T':
				case 'U':
				case 'V':
					putchar('8');
					break;
				case 'W':
				case 'Y':
				case 'Z':
				case 'X':
					putchar('9');
					break;
				
			}
		}
		puts("");
	}
	
	return 0;
}