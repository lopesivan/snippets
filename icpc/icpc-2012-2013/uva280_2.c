#include <stdio.h>
#include <string.h>

#define MAX (100+5)

int n, topo;
int mark[MAX];
int pilha[MAX];
int qtviz[MAX];
int viz[MAX][MAX];

void push (int x)
{
	pilha[++topo] = x;
}

int pop()
{
	return topo > -1 ? pilha[topo--] : -1;
}

void dfs(int v)
{
	int i, tmp = qtviz[v], w;
	
	for (i = 0; i < tmp; ++i)
	{
		w = viz[v][i];
		
		if ( !mark[w] )
		{
			mark[w] = 1;
			dfs(w);
		}
	}
}

void count()
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
		memset(qtviz, 0, sizeof qtviz);
		
		while (scanf("%d", &v), v)
			while (scanf("%d", &w), w)
			{
				viz[v][qtviz[v]] = w;
				++qtviz[v];
			}
		
		scanf("%d", &queries);
		
		for (i = 0; i < queries; ++i)
		{
			scanf("%d", &v);
			memset(mark, 0, sizeof mark);
			topo = -1;
			dfs(v);
			count();
		}
		
		/*for (i = 1; i<=n; ++i)
		{
			printf("nó %d:", i);
			for (j = 0; j < qtviz[i];  ++j)
				printf(" %d", viz[i][j]);
			puts("");
		}*/
	}
	
	return 0;
}