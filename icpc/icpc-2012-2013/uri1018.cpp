#include <cstdio>
using namespace std;

int main() {
  int d;
  scanf("%d", &d);
  printf("%d\n", d);
  
  int v[] = {100, 50, 20, 10, 5, 2, 1};

  for (unsigned i = 0; i < sizeof(v) / sizeof(int); ++i) {
    printf("%d nota(s) de R$ %d,00\n", d / v[i], v[i]);
    d -= (d / v[i]) * v[i];
  }
  
  return 0;
}

/*
  576

  576
  5 nota(s) de R$ 100,00
  1 nota(s) de R$ 50,00
  1 nota(s) de R$ 20,00
  0 nota(s) de R$ 10,00
  1 nota(s) de R$ 5,00
  0 nota(s) de R$ 2,00
  1 nota(s) de R$ 1,00
*/
