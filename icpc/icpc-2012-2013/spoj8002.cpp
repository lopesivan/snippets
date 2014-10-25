#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAX = 1e5+100;
typedef long long int ll;

ll dataMul[MAX], dataAdd[MAX];
int n;

void zerar() {
  memset(dataAdd, 0, sizeof dataAdd);
  memset(dataMul, 0, sizeof dataMul);
}

void internalUpdate(ll at, ll mul, ll add) {
  while (at <= n) {
    dataMul[at] += mul;
    dataAdd[at] += add;
    at |= (at + 1);
  }
}

void update(ll left, ll right, ll by) {
  internalUpdate(left, by, -by * (left - 1));
  internalUpdate(right, -by, by * right);
}

ll query(ll at) {
  ll mul = 0;
  ll add = 0;
  ll start = at;
  while (at >= 0) {
    mul += dataMul[at];
    add += dataAdd[at];
    at = (at & (at + 1)) - 1;
  }
  return mul * start + add;
}

ll query(ll at1, ll at2) {
  /*return query(at2) - (at1 == 1 ? 0 : query(at1 - 1));*/
  return query(at2) - query(at1-1);
}

int main() {
  int TC, c;
  
  scanf("%d", &TC);

  while (TC--) {
    scanf("%d%d", &n, &c);
    zerar();

    for (int i = 0; i < c; ++i) {
      int type, a, b, c;

      scanf("%d", &type);
      scanf("%d%d", &a, &b);
      switch(type) {
      case 0:
	scanf("%d", &c);
	update(a, b, c);
	break;
      case 1:
	/* query sum from a to b */
	printf("%lld\n", query(a, b));
	break;
      }	
    }
  }
  return 0;
}
