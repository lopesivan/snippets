#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 1100;

int main() {
  int m[MAX];
  memset(m, -1, sizeof m);
  int n, v;

  for (int v = 30; v >= 1; --v) {
    int vatual = v;
    int pos = vatual;
    int iatual = vatual;
    
    while (pos <= 1000 && vatual > 0) {
      m[pos] = v;
      iatual--;
      if (!iatual) {
        vatual--;
        iatual = vatual;
      }
      pos += vatual;
    }
  }

  // for (int i = 0; i < 31; ++i) {
  //   printf("m[%d] = %d\n", i, m[i]);
  // }

  while ( scanf("%d%d", &n, &v) == 2 && n != 0 && v != 0 ) {
    if (m[n] <= v && m[n] != -1)
      puts("possivel");
    else
      puts("impossivel");
  }

  return 0;
}
