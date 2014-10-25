#include <cstdio>
using namespace std;

int main() {
  double d;
  scanf("%lf", &d);
  d *= 100;
  
  int v1[] = {10000, 5000, 2000, 1000, 500, 200};
  int v2[] = {100, 50, 25, 10, 5, 1};

  puts("NOTAS:");
  for (unsigned i = 0; i < sizeof(v1) / sizeof(int); ++i) {
    printf("%d nota(s) de R$ %.2lf\n", int(d / v1[i]), double(v1[i]) / 100 );
    d -= (int(d) / v1[i]) * v1[i];
  }

  puts("MOEDAS:");
  for (unsigned i = 0; i < sizeof(v2) / sizeof(int); ++i) {
    printf("%d moeda(s) de R$ %.2lf\n", int(d / v2[i]), double(v2[i]) / 100 );
    d -= (int(d) / v2[i]) * v2[i];
  }
  
  return 0;
}

/*
  576.73

  NOTAS:
  5 nota(s) de R$ 100.00
  1 nota(s) de R$ 50.00
  1 nota(s) de R$ 20.00
  0 nota(s) de R$ 10.00
  1 nota(s) de R$ 5.00
  0 nota(s) de R$ 2.00
  MOEDAS:
  1 moeda(s) de R$ 1.00
  1 moeda(s) de R$ 0.50
  0 moeda(s) de R$ 0.25
  2 moeda(s) de R$ 0.10
  0 moeda(s) de R$ 0.05
  3 moeda(s) de R$ 0.01

*/
