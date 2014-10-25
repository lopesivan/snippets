#include <cstdio>
using namespace std;

int main() {
  int a1, a2, b1, b2, c1, c2, k1, k2;
  scanf("%d%d%d%d%d%d", &a1, &a2, &b1, &b2, &c1, &c2);

  k2 = b2;
  k1 = c1;

  printf("%d %d\n",a1 - k1, a2 - k2);
  return 0;
}
