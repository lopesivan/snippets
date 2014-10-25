#include <stdio.h>
#define MAX (100+10)

int d[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
char m[MAX][MAX];
int n;
int count;

void dfs (int i, int j)
{
	if (i < 0 || j < 0 || i >= n || j >= n || m[i][j] == '.')
		return;
	
	m[i][j] = '.';
	
	int k;
	for (k = 0; k < 4; ++k)
		dfs(i + d[k][0], j + d[k][1]);
}

int main() {
	
	int t, i, j, TC = 0;
	scanf("%d", &t);
	while (t--) {
		count = 0;
		scanf("%d%*c", &n);
		for (i = 0; i < n; ++i)
			scanf("%s", m[i]);
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				if (m[i][j] == 'x') {
					++count;
					dfs(i, j);
				}
		printf("Case %d: %d\n", ++TC, count);
	}
	
	return 0;
}