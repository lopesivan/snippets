#include <cstdio>
#include <cmath>
#include <algorithm>
const int MAX = 12000; // 7600

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  int q, d, p;

  while( scanf("%d", &q) == 1 && q ) {
    scanf("%d%d", &d, &p);
    int tgt;

    for (tgt = 1; tgt < MAX; ++tgt) {
      int t1 = int(ceil(tgt/q));
      int t2 = int(ceil(tgt/p) + d);

      if (t1 == t2 && !(tgt % p) && !(tgt % q)) {
        // printf("%d %d %d\n", tgt, t1, t2);
        printf("%d ", tgt);
        tgt == 1 ? puts("pagina") : puts("paginas");
        // break;
      }
        
    }
  }

  return 0;
}
