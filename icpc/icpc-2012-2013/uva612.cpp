#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>

using namespace std;

char input[60], aux[60];
int tam;

inline int count()
{
	char tmp;
	int i, j, qt = 0;
	strcpy(aux, input);
	
	for (i = 0; i < tam-1; ++i)
		for (j = 0; j < tam-1-i; ++j)
		{
			if (aux[j] > aux[j+1])
			{
				tmp = aux[j+1];
				aux[j+1] = aux[j];
				aux[j] = tmp;
				++qt;
			}
		}
		
	return qt;
}

int main()
{
	int t, n, i, tmp;
	multimap<int, string> d;
	multimap<int, string> ::iterator it;
	/*set < pair<int, string> > d;
	set < pair<int, string> > ::iterator it;*/
	
	scanf("%d", &t);
	
	while(t--)
	{
		d.clear();
		
		scanf("%d%d%*c", &tam, &n);
		
		for (i = 0; i < n; ++i)
		{
			gets(input);
			tmp = count();
			d.insert( make_pair(tmp, input) );
		}
		
		for (it = d.begin(); it!= d.end(); ++it)
			puts( it->second.c_str() );
		
		if (t)
			puts("");
	}
	
	return 0;
}