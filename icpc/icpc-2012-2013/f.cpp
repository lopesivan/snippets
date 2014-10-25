#include <cstdio>
const int MOD = 1000000009;

int main() {
  int n;
  
  while( scanf("%d", &n) == 1 && n) {
    // n! / 6      (6 = 3!)

    long long int ans = 1;
    for (int i = n; i >= 4; --i) {
      ans = (ans * i) % MOD;
    }

    printf("%lld\n", ans);
    
  }

  return 0;
}
