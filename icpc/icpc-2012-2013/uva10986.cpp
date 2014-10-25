#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<set>
#include<utility>
#include<vector>
#include<list>
#define INFTY ( (int) 1e9 )
#define MAX (20000 + 50)

using namespace std;

vector < list < pair <int, int> > > viz;
list< pair<int, int> > ::iterator it;
int n;

void djikstra (int s, int t)
{
	 int v, d;
   
      bool mark[MAX];
	 memset(mark, 0, sizeof mark);
	 
	 int dist[MAX];
	 for (int i = 0; i < n; ++i)
	    dist[i] = INFTY;
	 dist[s] = 0;
	 
	 set < pair<int, int> > h;
	 
	 h.insert( make_pair(0, s) );
	  
	 while (!h.empty())
	 {
	    d = (h.begin())->first;
	    v = (h.begin())->second;
	    h.erase( h.begin() );
	    mark[v] = true;
	    
	    if (v == t)
		  break;
	    
	    for (it = viz[v].begin(); it != viz[v].end(); ++it) {
		  
		  if (mark[it->first] == false && dist[v] + it->second < dist[it->first] ) {
			
			h.erase( make_pair( dist[it->first], it->first ) );
			dist[it->first] = dist[v] + it->second;
			h.insert( make_pair( dist[it->first], it->first) );
		  }
	    }
	    
	 }
	 
	 dist[t] == INFTY ? puts("unreachable") : printf("%d\n", dist[t]);
}

int main() {
	int TC, v, w, d;
	int  m, s, t;
	
	scanf("%d", &TC);
	
	for (int k = 1; k <= TC; ++k) {
	    scanf("%d%d%d%d", &n, &m, &s, &t);
	    
	    viz.assign (MAX, list< pair<int, int> > () );
	    
	    for (int i = 0; i < m; ++i) {
		  scanf("%d%d%d", &v, &w, &d);
		  
		  viz[v].push_back( make_pair(w, d) );
		  viz[w].push_back( make_pair(v, d) );
	    }
	    
	    printf("Case #%d: ", k);	    
	    djikstra(s, t);
	}
	return 0;
}