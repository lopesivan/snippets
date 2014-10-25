#include <stdio.h>
#include <string.h>

int n;
int g[100+5][100+5];
int mark[100+5];

void dfs(int v)
{
	int i;
	
	for (i = 1; i <= n; ++i)
		if ( g[v][i] && !mark[i] )
		{
			mark[i] = 1;
			dfs(i);
		}
}

void count()
{
	int qt = 0, i;
	
	for (i = 1; i <=n; ++i)
		if (!mark[i])
			++qt;
	
	if (!qt)
		printf("0\n");
	else
	{
		printf("%d", qt);
		for (i = 1; i <=n; ++i)
			if (!mark[i])
				printf(" %d", i);
		puts("");
	}
}

int main()
{
	int i, v, w, queries;
	
	while( scanf("%d", &n), n)
	{
		memset(g, 0, sizeof g);
		
		while (scanf("%d", &v), v)
			while (scanf("%d", &w), w)
				g[v][w] = 1;
		
		scanf("%d", &queries);
		
		for (i = 0; i < queries; ++i)
		{
			scanf("%d", &v);
			memset(mark, 0, sizeof mark);
			dfs(v);
			count();
		}
	}
	
	return 0;
}