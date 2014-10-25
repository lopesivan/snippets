#include <cstdio>
using namespace std;

int main() {
  scanf("%*[^\n]\n");
  double fixed, sales;
  scanf("%lf%lf", &fixed, &sales);
  printf("TOTAL = R$ %.2lf\n", fixed + 0.15 * sales);

  return 0;
}

/*
  JOAO
  500.00
  1230.30

  TOTAL = R$ 684.54
*/
