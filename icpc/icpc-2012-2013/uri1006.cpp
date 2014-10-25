#include <cstdio>
using namespace std;

int main() {
  double a, b, c;
  scanf("%lf%lf%lf", &a, &b, &c);

  a *= 2;
  b *= 3;
  c *= 5;

  printf("MEDIA = %.1lf\n", (a + b + c) / 10.0 );

  return 0;
}

/*
  5.0
  6.0
  7.0

  MEDIA = 6.3
*/
