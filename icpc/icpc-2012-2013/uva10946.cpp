#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <functional>
#include <vector>
#define MAX (50+5)

using namespace std;

int d[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int qt, x, y;
char m[MAX][MAX], c;
vector< pair<int, int> > output ((MAX*MAX)+100, make_pair(0,0) );

void dfs (int i , int j)
{
	if (i < 0 || j < 0 || i >= x || j >= y || m[i][j] != c)
		return;
	
	m[i][j] = '.';
	--output[qt].first;
	
	for (int k = 0; k < 4; ++k)
		dfs ( i + d[k][0], j + d[k][1] );
}

int main()
{
	int i, j, TC = 0;
	
	while (scanf("%d%d", &x, &y), x || y)
	{
		output.assign ((MAX*MAX)+100, make_pair(0,0) );
		qt = 0;
		
		/*
		 getchar();
		 for (i = 0; i < x; ++i)
		{
			for (j = 0; j < y; ++j)
				m[i][j] = getchar();
			getchar();
		}*/
		
		for (i = 0; i < x; ++i)
			scanf("%s", m[i]);
		
		for (i = 0; i < x; ++i)
			for (j = 0; j < y; ++j)
				if (m[i][j] != '.')
				{
					c = m[i][j];
					dfs(i, j);
					output[qt++].second = c;
				}
		
		sort (output.begin(), output.begin() + qt );
		
		printf("Problem %d:\n", ++TC);
		
		for (i = 0;  i < qt; ++i)
			printf("%c %d\n", output[i].second, -output[i].first);
	}
}