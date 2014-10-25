#include <cstdio>
using namespace std;

int main() {
  double a, b;
  scanf("%lf%lf", &a, &b);
  double ans = ((3.5 * a) + (7.5 * b)) / 11.0;
  printf("MEDIA = %.5lf\n", ans);

  return 0;
}

/*
  5.0
  7.1

  MEDIA = 6.43182
*/
