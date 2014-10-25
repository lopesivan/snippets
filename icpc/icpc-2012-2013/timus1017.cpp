#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 510;

int DP[MAX][MAX];

int solve (int k, int n) {

  // consegui usar tudo
  if (n == 0)
    return 1;
  // não tenho o suficiente para completar
  else if ( k > n)
    return 0;
  
  else {
    int tmp = 0, i = 0, _k, _n;
    _k = k + i;
    _n = n - k - i;
    
    for (i = 0; _k <= _n; ++i) {
      
      _k = k + i;
      _n = n - k - i;

      if ( DP[_k][_n] == 0 ) {
	DP[_k][_n] += solve (_k, _n);
	tmp += DP[_k][_n];
      }
      else
	tmp += DP[_k][_n];
    }
    
    return tmp;
  }
  
}

int main() {

  int n;
  memset(DP, 0, sizeof DP);
  scanf("%d", &n);
  printf("%d\n", solve(1,n) );
  

  return 0;
}

/*
  212
 */
