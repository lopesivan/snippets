#include <cstdio>
#include <cstring>
#include <queue>
#include <list>
#include <vector>
#define MAX (100+5)

using namespace std;

int main()
{
	int a, b, qt, v, TC = 0;
	double average;
	
	bool existe[MAX];
	vector< list<int> > viz;
	list<int> ::iterator it;
	
	while (scanf("%d%d", &a, &b) , a || b)
	{
		memset(existe, false, sizeof existe);
		viz.assign(MAX, list<int> () );
		average = 0.0;
		
		viz[a].push_back(b);
		existe[a] = existe[b] = true;
		
		while (scanf("%d%d", &a, &b) , a || b)
		{
			viz[a].push_back(b);
			existe[a] = existe[b] = true;
		}
		
		//imprime lista
		/*for (int i = 1; i <= 10; ++i)
		{
			printf("nó %d:", i);
			
			for (it = viz[i].begin(); it != viz[i].end(); ++it)
				printf(" %d", *it);
			
			puts("");
		}*/
		
		qt = 0;
		for (int i = 1; i < MAX; ++i)
			if (existe[i])
				++qt;
		
		for (int i = 1; i < MAX; ++i)
		{
			if ( viz[i].size() )
			{
				queue<int> fila;
				vector<int> level(MAX, -1);
				
				/*bfs*/
				fila.push(i);
				level[i] = 0;
				
				while ( !fila.empty() )
				{
					v = fila.front();
					fila.pop();
					
					for (it = viz[v].begin(); it != viz[v].end(); ++it)
						if ( level[*it] == -1)
						{
							level[*it] = level[v] + 1;
							average += level[*it];
							fila.push(*it);
						}
				}
			}
		}
		
		average /= (qt)*(qt-1);
		
		printf("Case %d: average length between pages = %.3lf clicks\n", ++TC, average);
	}
	
	return 0;
}