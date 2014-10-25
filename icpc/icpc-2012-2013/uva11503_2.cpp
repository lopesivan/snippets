#include <cstdio>
#include <cstring>
#include <map>
#include <string>

using namespace std;

map<string,string> root;
map<string, int> count;

void init()
{
	root.clear();
	count.clear();
}

string findset(string i)
{
	if ( count.find(i) == count.end() )
		count[i] = 1;
	
	if ( root.find(i) == root.end() )
		root[i] = i;
	
	return (root[i] == i) ? (i) : root[i] = findset(root[i]);
}

bool issameset(string i, string j)
{
	return findset(i) == findset(j);
}

void unionset(string i, string j)
{
	if ( issameset(i, j) ) return;
	
	count[findset(j)] += count[findset(i)];
	
	/* count.erase[findset(i)] */
	root[findset(i)] = findset(j);
}

int main()
{
	int t, n;
	char input1[30], input2[30];
	
	scanf("%d", &t);
	
	while (t--)
	{
		init();
		scanf("%d", &n);
		
		while (n--)
		{
			scanf("%s%s", input1, input2);
			
			unionset(input1, input2);
			
			printf("%d\n", count[findset(input1)]);
		}
	}
	
	return 0;
}