#include <cstdio>
using namespace std;

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%.3lf km/l\n", double(a)/b);

  return 0;
}
/*
  500
  35

  14.286 km/l
*/
