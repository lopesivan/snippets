#include <cstdio>
#include <cmath>

int main() {
  int a, b, c;

  while( scanf("%d", &a) == 1 && a) {
    scanf("%d%d", &b, &c);
    double ans = floor( sqrt ( a * b * double(double(100)/c)  )   );
    printf("%d\n", int(ans));
    
  }

  return 0;
}
