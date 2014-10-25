#include <stdio.h>
#include <string.h>

#define MAX (100+5)

int n, topo;
int g[MAX][MAX];
int mark[MAX];
int pilha[MAX];

inline void push (int x)
{
	pilha[++topo] = x;
}

inline int pop()
{
	return topo > -1 ? pilha[topo--] : -1;
}

inline void dfs(int v)
{
	int i;
	
	for (i = 1; i <= n; ++i)
		if ( g[v][i] && !mark[i] )
		{
			mark[i] = 1;
			dfs(i);
		}
}

inline void count()
{
	int i, next;
	
	for (i = n; i >=1 ; --i)
		if (!mark[i])
			push(i);
	
	if (topo == -1)
		printf("0\n");
	else
	{
		printf("%d", topo+1);
		while (next = pop(), next != -1)
			printf(" %d", next);
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
			topo = -1;
			dfs(v);
			count();
		}
	}
	
	return 0;
}