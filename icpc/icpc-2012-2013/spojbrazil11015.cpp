#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long int ll;
typedef list<int> li;
typedef pair<int,int> pii;
typedef set<int> si;
typedef vector<int> vi;
typedef vector<vi> vii;

const double EPS = 1e-9;
const double PI = 3.14159265358979;

#define mp make_pair

#define Max(a,b) ( (a) > (b) ? (a) : (b) )
#define Min(a,b) ( (a) < (b) ? (a) : (b) )
#define Mod(x) ( (x) > 0 ? (x) : (-(x)) )

#define MAX (100+100)
vector<int> v[MAX]; //lista de adjacência
int d[MAX]; //grau de entrada
int n, counter = 0;
int output[MAX]; //saída da top_sort()

void top_sort() {
  priority_queue<int,vector<int>,greater<int> > q;
  int i;
  for (i = 1; i <= n; ++i) {
    if (!d[i])
      q.push(i);
  }
  int u,w,tam;
  counter = 0;

  while (!q.empty()) {
    u =  q.top();
    output[counter++] = u;
    q.pop();
    for (i = 0, tam = v[u].size(); i < tam; ++i) {
      w = v[u][i];
      d[w]--;
      if (!d[w])
	q.push(w);
    }
  }
}

void print() {
  //printf("counter %d\n", counter);
  if (counter == n) {
    printf("%d", output[0]);
    for (int i = 1; i < n; ++i) {
      printf(" %d", output[i]);
    }
    puts("");
  }
  else
    puts("impossivel");
}

int main() {
  
  int master, tmp;
  int qt, m;

  scanf("%d%d", &n, &m);
  
  memset(d,0,sizeof d);
  for (int i = 0; i < n; ++i)
    v[i].clear();
    
  for (int i = 0; i < m; ++i) {
    scanf("%d", &master);
    scanf("%d", &qt);
    while (qt--) {
      scanf("%d", &tmp);
      ++d[master];
      v[tmp].push_back(master);
    }
  }

  top_sort();
  print();

  return 0;
}
  
