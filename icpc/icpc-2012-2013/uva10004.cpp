#include <cstdio>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#define MAX (200+5)

using namespace std;

int main()
{
	int n, l, v, w;
	
	while (scanf("%d", &n), n)
	{
		vector< list<int> > viz;
		viz.assign (MAX, list<int> () );
		list<int> ::iterator it;
		int mark[MAX];
		memset(mark, 0, sizeof mark);
		bool flag = 1;
		
		scanf("%d", &l);
		
		for (int i = 0; i < l; ++i)
		{
			scanf("%d%d", &v, &w);
			viz[v].push_back(w);
			viz[w].push_back(v);
		}
		
		queue<int> fila;
		mark[0] = 1;
		fila.push(0);
		
		while (!fila.empty() )
		{
			int v = fila.front();
			fila.pop();
			
			for (it = viz[v].begin(); it != viz[v].end(); ++it)
			{
				if (mark[*it] == 0)
				{
					mark[*it] = 3 - mark[v];
					fila.push(*it);
				}
				else if ( mark[*it] == mark[v] )
					flag = 0;
			}
		}
		
		flag == 1? puts("BICOLORABLE.") : puts("NOT BICOLORABLE.");
	}
	
	return 0;
}