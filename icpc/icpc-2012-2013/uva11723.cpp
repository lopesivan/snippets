#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  int r, n;
  int TC = 0;
  while (scanf("%d%d", &r, &n), r || n) {
    printf("Case %d: ", ++TC);
    int ans = ceil(double(r) / n) - 1;
    ans <= 26 ? printf("%d\n", ans) : puts("impossible");
  }
  return 0;
}
    
