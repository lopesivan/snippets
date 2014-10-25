#include <cstdio>
using namespace std;

int main() {
  int n1, n2;
  double v1, v2;
  scanf("%*d%d%lf", &n1, &v1);
  scanf("%*d%d%lf", &n2, &v2);
  printf("VALOR A PAGAR: R$ %.2lf\n", n1 * v1 + n2 * v2);

  return 0;
}

/*
  12 1 5.30
  16 2 5.10

  VALOR A PAGAR: R$ 15.50
*/
