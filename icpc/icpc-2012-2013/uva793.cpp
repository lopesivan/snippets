#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> root;

void init(int n)
{
	int i;
	
	root.assign(n, 0);
	for (i = 0; i < n; ++i)
		root[i] = i;
}

int findset(int i)
{
	return (root[i] == i) ? (i) : root[i] = findset(root[i]);
}

bool issameset(int i, int j)
{
	return findset(i) == findset(j);
}

void unionset(int i, int j)
{
	root[findset(i)] = findset(j);
}

int main()
{
	int t, n, pc1, pc2, yes, no;
	char input[20], type;
	
	scanf("%d", &t);
	
	while (t--)
	{
		scanf("%d%*c", &n);
		init(n);
		yes = no = 0;
		
		while( gets(input) )
		{
			if (!strlen(input))
				break;
			
			sscanf(input, "%c %d %d %*c", &type, &pc1, &pc2);
			--pc1, --pc2;
			
			switch(type)
			{
				case 'c':
					unionset(pc1, pc2);
					break;
				case 'q':
					issameset(pc1, pc2) ? ++yes : ++no;
			}
		}
		
		printf("%d,%d\n", yes, no);
		
		if(t)
			puts("");
	}
	
	return 0;
}