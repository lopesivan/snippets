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

#define MAX (10000+100)
vector<int> v[MAX]; //lista de adjacência
int d[MAX]; //grau de entrada
int n, counter = 0;
int output[MAX]; //saída da top_sort()

void top_sort() {
  priority_queue<int, vector<int>, greater<int> > q; //reversed pq
  int i;
  for (i = 1; i<= n; ++i) {
    if (!d[i])
      q.push(i);
  }
  int u,w,tam;
  counter = 0;
  
  while (!q.empty()) {
    u =  q.top();
    output[counter++] = u;
    q.pop();
    for (i = v[u][0], tam = v[u].size(); i < tam; ++i) {
      w = v[u][i];
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

int main() {
  int m, a, b;
  scanf("%d%d", &n, &m);
  memset(d,0,sizeof d);
  while(m--) {
    scanf("%d%d", &a, &b);
    ++d[b];
    v[a].push_back(b);
  }
  top_sort();
  print();
  
  return 0;
}

/*
  
  8 9
  1 4
  1 2
  4 2
  4 3
  3 2
  5 2
  3 5
  8 2
  8 6

  Expected: 1 4 3 5 7 8 2 6 

  2 2
  1 2
  2 1
  
  Expected: Sandro fails.
  
  3 2
  3 2
  3 1
  
  Expected: 3 1 2
 
*/
