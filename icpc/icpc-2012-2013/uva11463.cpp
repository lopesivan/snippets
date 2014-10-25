#include <cstdio>
#include <cstring>
#include <queue>
#define MAX (100+5)
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;

int viz[MAX][MAX+1]; /*lista de adjacência*/
int mark[MAX], mark2[MAX]; /*vetor de marcação com as distâncias mínimas*/
int n;

inline void bfs (int v) {
	int i;
	queue<int> fila;
	fila.push(v);
	mark[v] = 0; /*raiz*/
	
	while ( !fila.empty() )
	{
		int w = fila.front();
		fila.pop();
		
		for (i = 0; i < viz[w][MAX]; ++i)
		if (mark[viz[w][i]] == -1) {
			mark[viz[w][i]] = mark[w] + 1;
			fila.push(viz[w][i]);
		}
	}
}
inline void bfs2 (int v) {
	int i;
	queue<int> fila;
	fila.push(v);
	mark2[v] = 0;
	
	while ( !fila.empty() )
	{
		int w = fila.front();
		fila.pop();
		
		for (i = 0; i < viz[w][MAX]; ++i)
		if (mark2[viz[w][i]] == -1) {
			mark2[viz[w][i]] = mark2[w] + 1;
			fila.push(viz[w][i]);
		}
	}
}

inline int getmax()
{
	int maior = 0;
	
	for (int i = 0; i < n; ++i)
		maior = max (maior, mark[i] + mark2[i]);
	
	return maior;
}

int main()
{
	int t, TC = 0, i, m, v, w;
	
	scanf("%d", &t);
	for (TC = 1; TC <= t; ++TC) {
		scanf("%d%d", &n, &m);
		for (i = 0; i < MAX; ++i)
			viz[i][MAX] = 0;
				
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &v, &w);
			viz[v][viz[v][MAX]++] = w;
			viz[w][viz[w][MAX]++] = v;
		}
		scanf("%d%d", &v, &w);
				
		memset(mark, -1, sizeof mark);
		memset(mark2, -1, sizeof mark2);
		
		bfs(v);
		bfs2(w);
		
		/*for (i = 0; i < n; ++i)
			printf("mark %d: %d\n", i, mark[i]);
		for (i = 0; i < n; ++i)
			printf("mark2 %d: %d\n", i, mark2[i]);*/
				
		printf("Case %d: %d\n", TC, getmax());
	}
	
	return 0;
}