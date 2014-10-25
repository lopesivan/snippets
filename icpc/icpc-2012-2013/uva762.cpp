#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <climits>
#define MAX (529+1100-529)

using namespace std;
int n;
stack<int> pilha;
vector< list<int> > viz;
map< string, int > d1;
map< int, string > d2;
char input1[5], input2[5];
int nemesis, noroute;
int mark[MAX];

void dfs( int v , int level)
{
	list<int> ::iterator it;
	for (it = viz[v].begin(); it != viz[v].end(); ++it) {
		if ( level + 1 < mark[*it]) {
			mark[*it] = level + 1;
			dfs(*it, level+1);
		}
	}
}

void dfs2() /*bfs...*/
{
	int prox = nemesis;
	int level = mark[nemesis];
	pilha.push(prox);
	list<int> ::iterator it;
	
	while ( level > 0 ) {
		for (it = viz[prox].begin(); it != viz[prox].end(); ++it) {
			if ( mark[*it] == level - 1) {
				--level;
				prox = *it;
				pilha.push(prox);
				break;
			}
		}
		if ( it == viz[prox].end() ) {
			noroute = 1;
			return;
		}
	}
}

int main()
{
	int inicio = 0, i, ind;
	
	while ( scanf("%d", &n) == 1) {
		pilha = stack<int> ();
		viz.assign(MAX, list<int> () );
		d1.clear();
		d2.clear();
		ind = 0;
		
		if (inicio)
			puts("");
		inicio = 1;
		
		for (i = 0; i < n; ++i) {
			scanf("%s%s", input1, input2);
			if (d1.find(input1) == d1.end() ) {
				d1[input1] = ind;
				d2[ind++] = input1;
			}
			if (d1.find(input2) == d1.end() ) {
				d1[input2] = ind;
				d2[ind++] = input2;
			}
			
			viz[d1[input1]].push_back(d1[input2]);
			viz[d1[input2]].push_back(d1[input1]);
		}
		
		scanf("%s%s", input1, input2);
		
		if (d1.find(input1) == d1.end() || d1.find(input2) == d1.end() ) {
			puts("No route");
			continue;
		}
		else if (!strcmp(input1, input2)) {
			printf("%s %s\n", input1, input1);
			continue;
		}
		
		nemesis = d1[input2];
		
		for (int i = 0; i < MAX; ++i)
			mark[i] = INT_MAX;
		
		mark[d1[input1]] = 0;
		dfs(d1[input1], 0);
		noroute = 0;
		dfs2();
		
		/*for (int i = 0; i < ind; ++i) {
			printf("%s %d\n", d2[i].c_str(), mark[i]);
		}*/
		
		if ( noroute )
			puts("No route");
		else {
			while ( pilha.size() >= 2 ) {
				printf("%s ", d2[pilha.top()].c_str() );
				pilha.pop();
				printf("%s\n", d2[pilha.top()].c_str() );
			}
		}
	}
	
	return 0;
}