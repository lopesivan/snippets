#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[100];

int get(int i)
{
	switch( input[i] )
	{
		case '/':
			return 10 - get(i-2);
		case 'X':
			return 10;
		default:
			return atoi(input+i);
	}
}

int main()
{
	int i, r, score;
	
	while ( gets(input) )
	{
		if ( !strcmp(input, "Game Over"))
			break;
		
		score = 0;
		
		for (r = 0, i = 0; r < 10; r++)
		{
			switch ( input[i] )
			{
				case 'X':
					score += 10 + get(i+2) + get(i+4);
					i += 2;
					break;
				default:
					score += get(i) + get(i+2);
					if ( input[i+2] == '/')
						score += get(i+4);
					i += 4;
			}
		}
		
		printf("%d\n", score);
	}
	
	return 0;
}