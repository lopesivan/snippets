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
list<int> v[MAX]; //lista de adjacência
int d[MAX]; //grau de entrada
int n, counter = 0;
int output[MAX]; //saída da top_sort()

void top_sort() {
  priority_queue<int, vector<int>, greater<int> > q; //reversed pq
  for (int i = 1; i<= n; ++i) {
    if (!d[i])
      q.push(i);
  }
  int u,w;
  counter = 0;
  list<int>::iterator it;
  
  while (!q.empty()) {
    u =  q.top();
    output[counter++] = u;
    q.pop();
    for (it = v[u].begin(); it != v[u].end(); ++it) {
      w = *it;
      d[w]--;
      if (!d[w])
	q.push(w);
    }
  }
}

void print() {
  if (counter == n) {
    printf("%d",output[0]);
    for (int i = 1; i < n; ++i) {
      printf(" %d",output[i]);
    }
  }
  else
    puts("Sandro fails.");
}

void plist() {
  for (int i = 1; i <= n; ++i) {
    printf("%d: ", i);
    for (list<int>::iterator it = v[i].begin(); it != v[i].end(); ++it)
      printf("%d ", *it);
    puts("");
  }
}

int main() {
  int m, a, b;
  while(scanf("%d%d", &n, &m), n || m) {
    memset(d,0,sizeof d);
    for (int i = 0; i < MAX; ++i) {
      v[i].clear();
    }
    while (m--) {
      scanf("%d%d", &a, &b);
      ++d[b];
      v[a].push_back(b);
    }
    plist();
    top_sort();
    print();
  }
  return 0;
}

/*
  
  5 4
  1 2
  2 3
  1 3
  1 5
  0 0

  Sample Output : 1 4 2 5 3 
*/
