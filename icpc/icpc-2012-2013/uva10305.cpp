#include <cstdio>
#include <cstring>
#include <list>
#define MAX (101+5)

using namespace std;

list<int> order;

inline list<int> ::iterator find (int v, int *_v)
{
	*_v = 0;
	
	for (list<int> ::iterator it = order.begin(); it != order.end(); ++it, ++*_v)
		if (*it == v)
			return it;
	return order.end(); //junk
}

int main()
{
	int n, m, v, w, tmp;
	list<int> ::iterator it, iz;
	bool existe[MAX];
	
	while( scanf("%d%d", &n, &m), n || m)
	{
		order = list<int> ();
		memset(existe, false, sizeof existe);
		
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d", &v, &w);
			
			if ( !(existe[v] || existe[w]) )
			{
				order.push_back(v);
				order.push_back(w);
				existe[v] = existe[w] = true;
			}
			else if ( existe[v] && !existe[w] )
			{
				it = find(v, &tmp);
				++it;
				order.insert(it, w);
				existe[w] = true;
			}
			else if ( existe[w] && !existe[v] )
			{
				it = find(w, &tmp);
				order.insert(it, v);
				existe[v] = true;
			}
			else
			{
				int _v, _w;
				it = find(v, &_v);
				iz = find(w, &_w);
				
				// if (iz > it) OK!!
				if ( _v > _w)
					order.splice ( iz, order, it);
			}
		}
		
		for (int i = 1; i <= n; ++i)
			if ( !existe[i] )
				order.push_back(i);
		
		printf("%d", *(order.begin()) );
		for ( it = order.begin(), ++it; it != order.end(); ++it)
			printf(" %d", *it);
		puts("");
	}
	return 0;
}