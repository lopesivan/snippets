#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> root;
int num;

void init(int n)
{
	int i;
	
	num = n;
	root.assign(n, 0);
	
	for (i = 0; i < n; i++)
		root[i] = i;
}

int findset(int i)
{
	return ( root[i] == i ) ? (i) : (root[i] = findset(root[i]));
}

bool issameset(int i, int j)
{
	return findset(i) == findset(j);
}

void unionset(int i, int j)
{
	if ( issameset(i, j) == true )
		return;
	
		root[findset(i)] = findset(j);
		num--;
}

int main()
{
	int m, n, i, a, b, t = 0;
	
	while ( scanf("%d%d", &n, &m) == 2 )
	{
		if (!n && !m)
			break;
		
		init(n);
		
		for( i = 0; i < m; i++)
		{
			scanf("%d%d", &a, &b);
			unionset(a, b);
		}
		
		printf("Case %d: %d\n", ++t, num);
	}
	
	return 0;
}