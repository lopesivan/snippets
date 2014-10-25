#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <list>
#include <queue>
#define MAX (30+3)

using namespace std;

int main()
{
	int n, ttl, v, w, ind, TC = 0;
	list<int> ::iterator it;
	
	while ( scanf("%d", &n), n )
	{
		map<int, int> d;
		vector< list<int> > viz (MAX, list<int> () );
		ind = 0;
		
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &v, &w);
			
			if ( d.find(v) == d.end() )
				d[v] = ind++;
			if ( d.find(w) == d.end() )
				d[w] = ind++;
			
			viz[d[v]].push_back(d[w]);
			viz[d[w]].push_back(d[v]);
		}
		
		//print lista
		/*for (int i = 0; i < ind; ++i)
		{
			printf("nó %d:", i);
			for (it = viz[i].begin(); it != viz[i].end(); ++it)
				printf(" %d", *it);
			puts("");
		}*/
		
		while( scanf("%d%d", &v, &ttl), v || ttl)
		{
			int answer = 0, w;
			queue<int> fila;
			vector<int> level(MAX, -1);
			
			fila.push(d[v]);
			level[d[v]] = 0;
			
			while( !fila.empty() )
			{
				w = fila.front();
				fila.pop();
				
				for (it = viz[w].begin(); it != viz[w].end(); ++it)
				{
					if ( level[*it] == -1)
					{
						level[*it] = level[w] + 1;
					
						fila.push(*it);
					}
				}
			}
			
			for (int i = 0; i < ind; ++i)
				if ( level[i] == -1 || level[i] > ttl )
					++answer;
			
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++TC, answer, v, ttl );
		}
	}
	
	return 0;
}