#include <stdio.h>
#include <string.h>

char perm[20];
int count[2];
int n, h;

void backtrack(int level)
{
	if (level == n)
	{
		perm[level] = '\0';
		puts(perm);
	}
	else
	{
		int i;
		
		for (i = 0; i < 2; ++i)
		{
			if (count[i])
			{
				perm[level] = (i == 0 ? '0' : '1');
				--count[i];
				backtrack( level+1 );
				++count[i];
			}
		}
	}
}

int main()
{
	int t;
	
	scanf("%d", &t);
	
	while (t--)
	{
		scanf("%d%d", &n, &h);
		
		count[0] = n-h;
		count[1] = h;
		backtrack(0);
		
		if (t)
			puts("");
	}
	
	return 0;
}