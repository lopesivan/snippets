#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>

using namespace std;

int prox;
map<string, int> dict;
vector<int> root, count;

void init(int n)
{
	int i;
	
	prox = 0;
	root.assign(n, 0);
	for (i = 0; i < n; ++i)
		root[i] = i;
	
	count.assign(n, 1);
	dict.clear();
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
	if ( issameset(i, j) ) return;

	count[findset(j)] += count[findset(i)];
	root[findset(i)] = findset(j);
}

int main()
{
	int t, n;
	char input1[30], input2[30];
	
	scanf("%d", &t);
	
	while (t--)
	{
		scanf("%d", &n);
		init(n+1);
		
		while (n--)
		{
			scanf("%s%s", input1, input2);
			
			if ( dict.find(input1) == dict.end() )
				dict[input1]=prox++;
			
			if ( dict.find(input2) == dict.end() )
				dict[input2]=prox++;
			
			unionset(dict[input1], dict[input2]);
			printf("%d\n", count[findset(dict[input1])]);
		}
	}
	
	return 0;
}