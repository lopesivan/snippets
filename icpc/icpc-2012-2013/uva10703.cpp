#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define MAX (500+30)

using namespace std;

int main()
{
	bool v[MAX][MAX];
	int w, h, n, i, j, k, count,a, b, c, d;
	
	while ( scanf("%d%d%d", &w, &h, &n) == 3)
	{
		if (!w && !h && !n)
			break;
		
		/*for (i = 0; i < w; ++i)
			for (j = 0; j < h; ++j)
				v[i][j] = 0;*/
		
		memset(v, 0, sizeof v);
		
		for (k = 0; k < n; ++k)
		{
			scanf("%d%d%d%d", &a, &b, &c, &d);
			--a,--b,--c,--d;
			
			for (i = min(a,c) ; i <= max(a,c); ++i)
				for (j = min(b,d) ; j <= max(b,d) ; ++j)
					v[i][j] = 1;
		}
		
		count = 0;
		
		for (i = 0; i < w; ++i)
			for (j = 0; j < h; ++j)
				if (v[i][j] == 0)
					++count;
		
		if (count == 0)
			puts("There is no empty spots.");
		else if (count == 1)
			puts("There is one empty spot.");
		else
			printf("There are %d empty spots.\n", count);
	}
	
	return 0;
}