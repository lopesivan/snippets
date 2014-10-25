#include <cstdio>
#include <cstring>
#include <vector>
#include <list>
#include <stack>
#define MAX ((int) 1e6)

using namespace std;

int mark[MAX], n; /*=grau de entrada*/
int output[MAX];
stack<int> pilha;
vector< list<int> > viz;

void dfs()
{
	int v, ind = -1;
	list<int> ::iterator it;
	
	for (int i = 0; i < n; ++i)
		if (!mark[i])
			pilha.push(i);
	
	while (!pilha.empty()) {
		v = pilha.top();
		pilha.pop();
		
		output[++ind] = v;
		
		for (it = viz[v].begin(); it != viz[v].end(); ++it) {
			--mark[*it];
			if (!mark[*it])
				pilha.push(*it);
		}
	}
	
	int flag = 0;
	
	for (int i = 0; i < n; ++i)
		if (mark[i]) {
			flag = 1;
			break;
		}
	
	if (!flag) {
		for (int i = 0; i < n; ++i)
			printf("%d\n", output[i]+1);
	}
	else
		puts("IMPOSSIBLE");
	
}

int main() {
	int m, i, v, w;
	
	while (scanf("%d%d", &n, &m) , n || m ) {
		viz.assign (MAX, list<int> () );
		memset(mark, 0, sizeof mark);
		
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &v, &w); 
			--v, --w; /*1 to n*/
			viz[v].push_back(w);
			++mark[w];
		}
		
		dfs();
	}
	
	return 0;
}

/*como detectar ciclos???*/

// #include <cstdio>
// #include <cstring>
// #include <vector>
// #include <list>
// #define MAX ((int) 1e6)
// 
// using namespace std;
// 
// int mark[MAX];
// int output[MAX];
// int qt, flag;
// vector< list<int> > viz;
// 
// void dfs(int v)
// {
// 	if (!mark[v]) {
// 		mark[v] = 1;
// 		
// 		for (list<int> ::iterator it = viz[v].begin(); it != viz[v].end() && !flag; ++it) {
// 			if (!mark[*it])
// 				dfs(*it);
// 		}
// 		output[qt++] = v;
// 	}
// }
// 
// int main() {
// 	int n, m, i, v, w;
// 	
// 	while (scanf("%d%d", &n, &m) , n || m ) {
// 		viz.assign (MAX, list<int> () );
// 		
// 		for (i = 0; i < m; ++i) {
// 			scanf("%d%d", &v, &w); /*1 to n*/
// 			viz[v-1].push_back(w-1);
// 		}
// 		
// 		memset(mark, 0, sizeof mark);
// 		qt = 0;
// 		flag = 0;
// 		for (i = 0; i < n && !flag; ++i)
// 			dfs(i);
// 		
// 		if (!flag)
// 			for (i = qt-1; i >=0; --i)
// 				printf("%d\n", output[i]+1);
// 		else
// 			puts("IMPOSSIBLE");
// 	}
// 	
// 	return 0;
// }