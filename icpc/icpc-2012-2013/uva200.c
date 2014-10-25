#include <stdio.h>
#include <string.h>
#define MAX (26)
#define MAX2 (10000)
#define min(a,b) ((a)<(b) ? (a) : (b))

int g[MAX][MAX];
int mark[MAX];
int qt;
char output[MAX];

void dfs (int v)
{
	int i;
	mark[v] = 1;
	
	for (i = 0; i < MAX; ++i) {
		if (v != i && g[v][i] && !mark[i])
			dfs(i);
	}
	output[qt++] = v + 'A';
}

int main() {
	int tam, i, j, k, cd = 0;
	char d[MAX2][25], s[25];
	memset(g, 0, sizeof g);
	
	while ( scanf("%s", s) == 1 ) {
		if (!strcmp(s, "#")) {
			
			for (i = 0; i < cd - 1; ++i) {
					j = i+1;
					tam = min ( strlen(d[i]), strlen(d[j]) );
					k = 0;
					
					while (k < tam && d[i][k] == d[j][k] )
						++k;
					if (k < tam)
						g[d[i][k] - 'A'][d[j][k] - 'A'] = 1;
				}
			
			memset(mark, 0, sizeof mark);
			qt = 0;
			dfs(d[0][0]-'A');
			
			for (i = qt-1; i >=0; --i)
				putchar(output[i]);
			puts("");
			memset(g, 0, sizeof g);
			cd = 0;
		}
		else {
			strcpy( d[cd++], s) ;
		}
	}
	return 0;
}