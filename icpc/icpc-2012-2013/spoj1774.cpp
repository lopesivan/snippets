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

const int MAX = 51000;
int n1, n2, d;
int answer;
vi g[MAX];
int din[MAX];

inline bool first(int i) {
  return i <= n1;
}

inline bool second(int i) {
  return !first(i);
}

void printq(stack<int> s) {
  while (!s.empty()) {
    printf("%d ", s.top());
    s.pop();
  }
  puts("-------");
}

void toposort() {
  int i, k, u, v;
  set<int> pq1,pq2;

  for (i = 1; i <= n1 + n2; ++i) {
    if (!din[i]) {
      if (first(i))
	pq1.insert(i);
      else
	pq2.insert(i);
    }
  }

  int tries[2];
  tries[0] = tries[1] = 2;
  int last;

  for (k = 0, last = k; k < 2; ++k) {

    while(! (pq1.empty() && pq2.empty()) ) {
      if (last == 0) {
	if (!pq1.empty()) {
	  u = *pq1.begin();
	  pq1.erase(pq1.begin());
	  last = 0;
	}
	else if (!pq2.empty()) {
	  u = *pq2.begin();
	  pq2.erase(pq2.begin());
	  last = 1;
	  ++tries[k];
	}
      }
      else {
	if (!pq2.empty()) {
	  u = *pq2.begin();
	  pq2.erase(pq2.begin());
	  last = 1;
	}
	else if (!pq1.empty()) {
	  u = *pq1.begin();
	  pq1.erase(pq1.begin());
	  last = 0;
	  ++tries[k];
	}
      }

      // printf("u: %d\n", u);

      for (i = 0; i < (int)g[u].size(); ++i) {
	v = g[u][i];
	--din[v];
	if (!din[v]) {
	  if (first(v))
	    pq1.insert(v);
	  else
	    pq2.insert(v);
	}
      } 
    }
  }
  
  printf("%d %d\n", tries[0], tries[1]);
  answer = min(tries[0], tries[1]);
  
}
int main() {
  int a, b;
  while(scanf("%d%d%d", &n1, &n2, &d), n1 || n2 || d) {

    for (int i = 0; i < MAX; ++i) {
      g[i].clear();
    }
    memset(din, 0, sizeof din);
    
    for (int i = 0; i < d; ++i) {
      scanf("%d%d", &a, &b);
      g[b].push_back(a);
      ++din[a];
    }

    toposort();

    printf("%d\n", answer);
  }
  
  return 0;
}

/*
  Input:
  3 2 1
  1 2
  2 2 2
  1 3
  4 2
  2 1 1
  1 3
  0 0 0

  Output:
  3
  4
  3
*/
