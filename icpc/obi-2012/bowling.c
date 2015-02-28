#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRIKE "X"
#define SPARE "/"

int main()
{
	char input[50],*next,*backup;
	int score;
	int _bonus,__bonus,mult;
	
	while (gets(input))
	{
		if (!strcmp(input,"Game Over"))
			break;
		
		score=_bonus=__bonus=0;
		next= strtok(input," ");
		
		while (next != NULL)
		{
			mult=1;
			if (_bonus)
				mult++;
			
			if (!strcmp(STRIKE,next))
			{
				score+=mult*10;
				_bonus=1;
				
			}
			
			else
			{
				score+=mult*atoi(next);
				
				backup=next;
				next = strtok(NULL, " ");
				
				if (!strcmp(SPARE,next))
				{
					score+=mult*(10-atoi(backup));
					_bonus=1;
					
				}
				else
				{
					score+=mult*atoi(next);
					_bonus=0; 
				}
			}
			next = strtok(NULL, " ");
		}
		
		printf("%d\n",score);
	}
	
	return 0;
}