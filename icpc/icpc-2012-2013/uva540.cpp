#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <vector>

using namespace std;

vector< queue<int> > fila;
map<int, int> time;

int main()
{
	int qt, i, j, TC = 0, tmp, next, next_team, count;
	char line[100];
	
	while ( scanf("%d", &qt), qt)
	{
		fila.assign (qt+1, queue<int>() );
		
		//preenche dict
		time.clear();
		for (i = 0; i < qt; ++i)
		{
			scanf("%d", &count);
			
			for (j = 0; j < count; ++j)
			{
				scanf("%d", &tmp);
				time[tmp] = i;
			}
		}
		
		printf("Scenario #%d\n", ++TC);
		
		getchar();
		while ( scanf("%s ", line) , strcmp(line, "STOP") )
		{
			if ( !strcmp(line, "ENQUEUE") )
			{
				scanf("%d%*c", &next);
				
				if ( fila[time[next]].empty() )
					fila[qt].push(time[next]);
				fila[ time[next] ].push(next);
			}
			else
			{
				next_team = fila[qt].front();
				
				printf("%d\n", fila[next_team].front() );
				fila[next_team].pop();
				
				if (fila[next_team].empty())
					fila[qt].pop();
			}
		}
		puts("");
	}
	
	return 0;
}