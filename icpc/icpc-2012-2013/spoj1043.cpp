#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
using namespace std;
const int MAX = 51000;
const int MAX2 = 132000; // ~2^17 = 2^h - 1, onde h = ceil( log2(51000) ) + 1;

// atributos
int h;
int n;
int modw;
int ibase;
int v[MAX];
int w[MAX2];
// fim atributos

int isPosition(int l, int sub) {
  while (sub > 0 && (sub != 2 * l) && (sub != (2 * l + 1) ) ) {
    sub /= 2;
  }

  if ( sub == 2 * l )
    return 1;
  else if ( sub == (2 * l + 1) )
    return 2;
  else
    return 0;
}

int prop(int a, int b) {
  // max(a, b, a + b);
  int maior = max(a,b);
  return max(maior, a + b);
}

void construct(int n) {
  for (int i = 1; i < MAX2; ++i)
    w[i] = INT_MIN / 2;
  
  h = ceil ( log(n)/log(2) ) + 1;
  assert( 4 == (ceil ( log(5)/log(2) ) + 1) );
  
  modw = ((int) pow(2,h)) - 1;
  assert( 15 == ((int) pow(2,4)) - 1 );

  ibase = (int) pow(2,h-1);
  assert ( 8 == (int) pow(2,4-1) );
  
  for (int i = 1; i <= n; ++i)
    w[ibase + i - 1] = v[i];

  for (int i = ibase - 1; i >= 1; --i) {
    w[i] = prop( w[2*i], w[2*i+1] );
  }
}

void update(int l, int value) {
  int imap = ibase + l - 1;
  w[imap] = value;
  imap /= 2;

  while (imap > 0) {
    w[imap] = prop( w[2*imap], w[2*imap + 1] );
    imap /= 2;
  }
}

int query(int l1, int l2) {
  int imap1 = ibase + l1 - 1;
  int imap2 = ibase + l2 - 1;
  int ret = INT_MIN / 2;

  int i = 1;

  if ( isPosition(imap2, i) == 1 ) {
    i *= 2;
  }
  else if ( isPosition(imap2,i) == 2 && isPosition(imap1,i) == 2) {
    i = 2 * i + 1;
  }
  else {
    // imap2 na direita e imap1 na esquerda
    int i2 = 2 * i + 1;
    while ( i2 != imap2 ) {
      if ( isPosition(i2, imap2) == 1 )
	i2 *= 2;
      else {
	ret = prop(ret, w[2*i2]);
	i2 = i2 * 2 + 1;
      }
    }
    ret = prop(ret, w[imap2]);

    int i1 = 2 * i;
    while ( i1 != imap1 ) {
      if ( isPosition(i1, imap1) == 2 )
	i1 = 2 * i1 + 1;
      else {
	ret = prop(ret, w[2*i1+1]);
	i1 *= 2;
      }
    }
    ret = prop(ret, w[imap1]);
  }
  return ret;
}

int main() {

  // construction
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &v[i]);
  construct(n);

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
*/
