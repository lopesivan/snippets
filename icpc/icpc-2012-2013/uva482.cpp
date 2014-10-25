#include <cstdio>

using namespace std;

#define MAX (10000+100)

int main()
{
	int indices[MAX];
	char input[MAX][100];
	int t, i, j;
	char c;
	
	scanf("%d", &t);
	
	while (t--)
	{
		i = 0;
		
		while (scanf("%d",&indices[i++]) == 1 )
		{
			c = getchar();
			
			if (c == '\n')
				break;
		}
		
		for( j = 0; j < i; ++j)
			scanf(" %s ", input[ indices[j]-1 ] );
		
		scanf("%*[\n]");
		
		for (j = 0; j < i; ++j)
			printf("%s\n", input[j]);
		
		if (t)
			puts("");
	}
	
	return 0;
}