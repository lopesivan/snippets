#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 51000;

// atributos
int v[MAX];

// segment tree
vector<int> w;
int n, h, modw, ibase;
//const int NEUTRAL = (INT_MIN / 2) + 1;
//const int NEUTRAL = 0;
const int NEUTRAL = -50000;
// Fim atributos

void printAll() {
  cout << "v :" << endl;
  for (int i = 1; i <= n; ++i)
    cout << v[i] << " ";
  cout << endl;

  cout << "w :" << endl;
  int pot = 1, j = 0;
  for (int i = 1; i <= modw; ++i) {
    cout << w[i] << " ";
    ++j;
    if (j == pot) {
      pot *= 2;
      j = 0;
      cout << endl;
    }
  }
  cout << endl;
}

// return max(a, b, a+b)
int prop(int a, int b) {
  int maior = max(a,b);
  return max(maior, a + b);
}

inline void update(int i) {
  w[i] = prop( w[2*i], w[2*i + 1] );
}

void update(int i, int value) {
  int iw = ibase + i - 1;
  assert( iw >= ibase && iw <= modw );

  w[iw] = value;
  do {
    iw /= 2;
    update(iw);    
  } while (iw >= 1);
}

// {} ql e qr: da query
// [] sl e sr: o que é representado pela segtree
// index: índice atual
int query(const int ql, const int qr, int sl, int sr, int index) {

  // {} []
  //if (qr <= sl)
  //  return NEUTRAL;
  // [] {}
  //if (ql >= sr)
  //  return NEUTRAL;

  
  // {  []   }
  if (sl >= ql && sr <= qr) {
    //    puts("caso 1");
    //    printf("-- %d %d\n", sl, sr);
    return w[index];
  }
  // ]  {   ou   }  [
  if (sr < ql || sl > qr) {
    //    puts("caso 2");
    //    printf("-- %d %d\n", sl, sr);
    return NEUTRAL;
  }
  // [  {}   ]
  //if (ql >= sl && qr <= sr) {
  //  puts("caso 3");
  //      printf("-- %d %d\n", sl, sr);
    int diff = (sr - sl) / 2;

    // [1,4] --> diff = 1 --> [1,2] e [3,4]

    return prop(
		query(ql, qr, sl, sl + diff, 2 * index),
		query(ql, qr, sl + diff + 1, sr, 2 * index + 1));
    //}
    //throw std::exception();
    
}

int query(int ql, int qr) {
  return query(ql, qr, 1, ibase, 1);
}

inline void updateAll() {
  for (int i = ibase - 1; i >= 1; --i)
    update(i);
}

void construct(int n) {
  h = (1 + ceil(log(n)/log(2)));
  modw = pow(2,h) - 1;

  w = vector<int>(modw + 1, NEUTRAL); // 1-based index
  ibase = pow(2, h-1);

  // preencher as folhas da segtree
  for (int i = ibase; i <= ibase + n - 1; ++i)
    w[i] = v[i - ibase + 1];

  // preencher os nós internos da segtree
  updateAll();
}

int main() {
  // construction
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &v[i]);
  construct(n);

  //printAll();

  // queries
  int m, a, b;
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &a, &b);
    printf("%d\n", query(a,b));
  }

  return 0;
}

/*
  Input:
  3 
  -1 2 3
  1
  1 2
  Output:
  2

  Input:
  6
  1 2 3 4 -1 -2
  1
  1 7
  Output:
  10

  Input:
  5
  1 3 -5 -2 10
  9
  1 1
  2 2
  3 3
  4 4
  5 5
  1 2
  1 3
  3 4
  1 5

  Output:
  1
  3
  -5
  -2
  10
  4
  4
  -2
  14

  Input:
  5
  -2 -3 -5 -4 -1
  1
  1 5

  Output:
  -1
  
*/
