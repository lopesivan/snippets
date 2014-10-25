#include <stdio.h>
#include <string.h>

#define MAX (101+10)

int main()
{
	char input[MAX];
	int i, j, t, answer, tam;
	
	scanf("%d%*c", &t);
	
	for (i=1; i <= t; i++)
	{
		answer = 0;
		gets(input);
		
		tam = strlen(input);
		
		for (j=0; j < tam; j++)
		{
			switch (input[j])
			{
				case 'a':
				case 'd':
				case 'g':
				case 'j':
				case 'm':
				case 'p':
				case 't':
				case 'w':
				case ' ':
					answer++;
					break;
				
				case 'b':
				case 'e':
				case 'h':
				case 'k':
				case 'n':
				case 'q':
				case 'u':
				case 'x':
					answer += 2;
					break;
					
				case 'c':
				case 'f':
				case 'i':
				case 'l':
				case 'o':
				case 'r':
				case 'v':
				case 'y':
					answer += 3;
					break;
				
				case 's':
				case 'z':
					answer += 4;
			}
		}
		
		printf("Case #%d: %d\n", i, answer);
	}
	
	return 0;
}