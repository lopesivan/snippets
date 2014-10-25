#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> root;
vector<int> tam_grupo;
int qt;

void init(int n)
{
	int i;
	
	root.assign(n, 0);
	
	for (i = 0; i < n; i++)
		root[i] = i;
	
	tam_grupo.assign(n, 1);
	
	qt = n;
	
}

int findset(int i)
{
	if (root[i] == i)
		return i;
	
	root[i] = findset(root[i]);
	
	return root[i];
}

int issameset(int i, int j)
{
	return findset(i) == findset(j);
}

void unionset(int i, int j)
{
	if (issameset(i, j)) return;
	
	tam_grupo [findset(j)] += tam_grupo [findset(i)];
	
	root[findset(i)] = findset(j);
	
	qt--;
}

int tam(int i)
{
	return tam_grupo[findset(i)];
}

int main()
{
	int c, n, m, a, b, maiortam;
	
	scanf("%d", &c);
	
	while (c--)
	{
		maiortam = -1;
		
		scanf("%d%d", &n, &m);
		
		init(n);
		
		while (m--)
		{
			scanf("%d%d", &a, &b);
			--a, --b;
			
			unionset(a,b);
			
			maiortam = max(maiortam, tam(a));
		}
		
		printf("%d\n", maiortam);
		
	}
	return 0;
}