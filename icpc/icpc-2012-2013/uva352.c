#include <stdio.h>
#define MAX (25+5)

int d[8][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1} };
char m[MAX][MAX];
int n;

void dfs (int i, int j) {
	if (i < 0 || j < 0 || i >=n || j>=n || m[i][j] == '0')
		return;
	
	m[i][j] = '0';
	
	int k;
	
	for (k = 0; k < 8; ++k)
		dfs( i + d[k][0], j + d[k][1]);
}

int main()
{
	int i, j, TC = 0, count;
	
	while ( scanf("%d%*c", &n) == 1 ) {
		count = 0;
		for (i = 0; i < n; ++i)
			scanf("%s", m[i]); /*&m[i][0]*/
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				if (m[i][j] == '1') {
					dfs(i, j);
					++count;
				}
		printf("Image number %d contains %d war eagles.\n", ++TC, count);
	}
	return 0;
}