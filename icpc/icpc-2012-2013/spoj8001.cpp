#include <cstdio>
#include <vector>
#include <map>
using namespace std;
typedef long long int ll;

// approach 1: brute force ==> without memory
// approach 2: doubling fibonacci

const int MAX = 1e9+100;
map<int,ll> fib;

inline ll resto(ll x) {
  const int m = 1000000007;
  return ((x % m) + m) % m;
}

inline ll f(int i) {
  switch(i) {
  case 0:
    return 0;
  case 1:
    return 1;
  case 2: //necessário!!!!! senão dá overflow
    return 1;
  default:
    if (fib[i] != 0)
      return fib[i];
    else {
      ll fatual = resto(f(i/2));
      ll fsuc = resto(f((i/2)+1));
      if (i % 2)
	fib[i] = resto( resto(fsuc*fsuc) + resto(fatual*fatual) );
      else
	fib[i] = resto ( fatual * ( resto( 2 * fsuc ) - fatual) );
      return fib[i];
    }      
  }
}

int main() {
  int TC, a, b;
  scanf("%d", &TC);

  while (TC--) {
    scanf("%d%d", &a, &b);
    int ans = resto(f(b+2) - 1);
    int ans2 = resto(f(a+1)-1);
    int ans3 = resto(ans - ans2);
    printf("%d\n", ans3);
  }
  
  return 0;
}
