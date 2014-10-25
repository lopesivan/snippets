#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRIKE 'X'
#define SPARE '/'

char input[50];

int get_pin(int i) /*retorna o valor do pin*/
{
	char c=input[i];
	
	switch(c)
	{
		case STRIKE:
			return 10;
			break;
		case SPARE:
			return (10-get_pin(i-2));
			break;
		default:
			return atoi(&c);
	}
}

int main()
{
	int soma,i,r;
	
	while (gets(input))
	{
		if (!strcmp("Game Over", input))
			break;
		
		soma=0;
		
		for (i=0,r=0; r<10; i+=2,r++)
		{
			if (input[i]==STRIKE)
			{
				soma+=10+get_pin(i+2)+get_pin(i+4);
			}
			
			else if (input[i+2]==SPARE)
			{
				soma+=10+get_pin(i+4);
				i+=2;
			}
			
			else
			{
				soma+=get_pin(i)+get_pin(i+2);
				i+=2;
			}
		}
		
		printf("%d\n",soma);
	}
	
	return 0;
	
}