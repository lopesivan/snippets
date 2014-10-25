#include <cstdio>
using namespace std;

long long int pot2(long long int nemesis) {
  // nemesis = 100101011

  bool flag = false;
  long long int i = 1;
  
  while(nemesis - i > 0) {
    if (nemesis & i) {
      flag = true;
      nemesis -= i;
    }
    i <<= 1;
  }

  if (!nemesis)
    return 1;

  return flag ? nemesis << 1 : nemesis;
}

long long int pot22(long long int k) {
  int i;
  for(i = 0; (1LL<<i) < k; i++);
  return 1LL<<i;
}

int main() {
  long long int g, t, a, d;

  while( scanf("%lld%lld%lld%lld", &g, &t, &a, &d), g != -1 && t != -1 && a != -1 && d != -1 ) {
    printf("%lld*%lld/%lld+%lld=", g, a, t, d);

    long long int games = t * (t-1) / 2 * g;
    long long int over = pot2(g * a + d);
    games += over - 1;
    long long int add = over - (g * a + d);
    printf("%lld+%lld\n", games, add);
  }

  // for (int i = 0; i < 31; ++i)
  //   printf("%3d %3lld %3lld\n", i, pot2(i), pot22(i));

  return 0;
}

/*
  Input:
  8 4 2 0
  8 4 2 1
  -1 -1 -1 -1

  Output:
  8*2/4+0=63+0
  8*2/4+1=79+15
*/
