# include <stdio.h>
# include <string.h>

# define MIN(a,b) (a<b?a:b)
# define MAXN 1024
# define INF 0x3f3f3f3f

int foi[MAXN];
int dist[MAXN];
int qtos[MAXN];

int lista[MAXN][MAXN];
int custo[MAXN][MAXN];

void dijkstra( int v, int n ){
	int marcados = 0;
	int i, w;
	memset(dist, INF, sizeof dist);
	memset(foi, 0, sizeof foi);
	dist[v] = 0;
	while( marcados != n ) {
		int menor = INF, curr = -1;
		for(i = 0; i < n; i++){
			if( foi[i] ) continue;
			if( dist[i] < menor ){
				menor = dist[i];
				curr = i;
			}
		}
		if( menor == INF ) break;
		for(i = 0; i < qtos[curr]; i++){
			w = lista[curr][i];
			if( foi[w] ) continue;
			dist[w] = MIN(dist[w], dist[curr] + custo[curr][i]); 
		}
		foi[curr] = 1;
		marcados++;
	}
}

