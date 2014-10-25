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
int TC = 0;
map<string,int> m;
map<int,string> m2;

void top_sort() {
  stack<int> q;
  int i;
  for (i = 0; i < n; ++i) {
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
  printf("Teste %d\n",++TC);
  //printf("counter %d\n", counter);
  if (counter == n) {
    printf("%s", m2[output[0]].c_str());
    for (int i = 1; i < n; ++i) {
      printf(" %s", m2[output[i]].c_str());
    }
    puts("");
  }
  else
    puts("impossivel");
  puts("");
}

void print_v() {
  for (int i = 0; i < n; ++i) {
    printf("%s:",m2[i].c_str());
    for (int j = 0; j < v[i].size(); ++j) {
      printf(" %s",m2[v[i][j]].c_str());
    }
    puts("");
  }
}

int main() {
  
  char tmp[20], master[20];
  int qt;

  while (scanf("%d", &n), n) {

    memset(d,0,sizeof d);
    for (int i = 0; i < n; ++i)
      v[i].clear();
    m.clear();
    m2.clear();
    
    for (int i = 0; i < n; ++i) {
      scanf("%s", tmp);
      m[tmp] = i;
      m2[i] = tmp;
    }

    for (int i = 0; i < n; ++i) {
      scanf("%s", master);
      scanf("%d", &qt);
      while (qt--) {
	scanf("%s", tmp);
	++d[m[tmp]];
	v[m[master]].push_back(m[tmp]);
      }
    }
    top_sort();
    print();
    //print_v();
  } 
  return 0;
}
  
  /*
    
    5
    Joao Maria Tadeu Jose Ricardo
    Joao 2 Maria Ricardo
    Maria 1 Tadeu
    Jose 1 Joao
    Tadeu 0
    Ricardo 0
    3
    Joao Maria Renata
    Maria 1 Joao
    Joao 1 Renata
    Renata 1 Maria
    5
    Joao Maria Tadeu Jose Ricardo
    Joao 2 Maria Ricardo
    Maria 1 Tadeu
    Jose 1 Joao
    Tadeu 0
    Ricardo 0
    0

    Expected:
    Teste 1
    Ricardo Tadeu Maria Joao Jose

    Teste 2
    impossivel
  */
