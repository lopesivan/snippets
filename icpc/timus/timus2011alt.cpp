#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int v[150];
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }

  int ans = 0;
  for (int i = 0; i < 5; ++i)
    ans += std::next_permutation(v, v + n);

  ans == 5? puts("Yes") : puts("No");
  return 0;
}
