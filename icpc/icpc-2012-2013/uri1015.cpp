#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  int x1, x2, y1, y2;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  double ans = sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
  printf("%.4lf\n", ans);

  return 0;
}

/*
  1 7
  5 9

  4.4721
*/
