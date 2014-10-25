#include <stdio.h>
#include <string.h>

#define MAX (100+5)

int n, nemesis, answer;
int viz[MAX][MAX];
int qviz[MAX];
int mark[MAX];

void dfs(int v)
{
	int i, tmp = qviz[v], w;
	
	mark[v] = 1;
	
	for (i = 0; i < tmp; ++i)
	{
		w = viz[v][i];
		
		if (!mark[w] && w != nemesis)
			dfs(w);
	}
}

void count()
{
	int i;
	
	for (i = 1; i<=n; ++i)
		if (!mark[i])
		{
			++answer;
			break;
		}
}

int main()
{
	int v, w, i;
	char c;
	
	while (scanf("%d", &n), n)
	{
		memset(qviz, 0, sizeof qviz);
		answer = 0;
		
		while ( scanf("%d%*c", &v), v)
		{
			while (scanf("%d%c", &w, &c) == 2)
			{
				viz[v][qviz[v]++] = w;
				viz[w][qviz[w]++] = v;
				
				if ( c == '\n')
					break;
			}
		}
		
		if (n == 1)
			printf("0\n");
		else
		{
			for (i = 1; i <= n; ++i)
			{
				memset(mark, 0, sizeof mark);
				nemesis = i;
				mark[nemesis] = 1;
				dfs( i==1? 2 : 1 );
				count();
			}
		}
		
		printf("%d\n", answer);
	}
	
	return 0;
}