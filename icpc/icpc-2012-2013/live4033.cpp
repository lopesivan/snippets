#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

int m, a, b, c, d, e, f, g, h, i, j, k;

inline int sunny(int x) {
  return a*x*x + b*x + c;
}

inline int cloudy(int x) {
  return d*x*x + e*x + f;
}

inline int raining(int x) {
  return g*x*x + h*x + i;
}

inline int tod(int x) {
  return (j*x + k) % 3;
}

int main() {

  int TC;
  scanf("%d", &TC);

  while(TC--) {
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &m, &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k);

    j = (j + 60) % 3; // 0, 1 ou 2 pf

    long long int dia = 0;
    long long int _m = 0;

    while (_m < m) {

      ++dia;

      switch( tod(dia) ) {
      case 0: //sunny
	_m += sunny(dia);
	break;
      case 1: //cloudy
	_m += cloudy(dia);
	break;
      default:
	_m += raining(dia);
      }
    }

    printf("%lld\n", dia);
  }

  return 0;
}
