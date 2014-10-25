#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX (11+2)

char input[MAX];
char perm[MAX];
int count[128];
int tam;

int cmp (const void *a, const void *b)
{
	return strcmp( (char*)a, (char*)b );
}

void backtrack(int level)
{
	if (level == tam)
	{
		perm[tam] = '\0';
		puts(perm);
	}
	else
	{
		int i;
		
		for (i = (int) '0'; i <= (int) 'z'; ++i)
		{
			if (count[i])
			{
				perm[level] = (char) i;
				--count[i];
				backtrack(level+1);
				++count[i];
			}
		}
	}
}

int main()
{
	int t, i;
	
	scanf("%d", &t);
	
	while (t--)
	{
		scanf("%s", input);
		tam = strlen(input);
		qsort(input, tam, sizeof input[0], cmp);
		
		memset(count, 0, sizeof count);
		for (i = 0; i < tam; ++i)
			++count[(int) input[i]];
		
		backtrack(0);
		puts("");
	}
	
	return 0;
}