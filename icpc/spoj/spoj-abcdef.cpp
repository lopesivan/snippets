#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
  int n;
  int i, j, k;
  int v[110];
  int a[1001000];
  int ans = 0;
  int ind = 0;
  int tmp;

  scanf("%d", &n);

  for (i = 0; i < n; ++i)
    scanf("%d", &v[i]);

  for (i = 0; i < n; ++i) {
    if (!v[i])
      continue;
    for (j = 0; j < n; ++j) {
      for (k = 0; k < n; ++k) {
        a[ind++] = v[i] * (v[j] + v[k]); // right side
      }
    }
  }

  sort(a, a + ind);

  for (i = 0; i < n ; ++i)
    for (j = 0; j < n; ++j)
      for (k = 0; k < n; ++k) {
        tmp = v[i] * v[j] + v[k];
        ans += upper_bound(a, a + ind, tmp) - lower_bound(a, a + ind, tmp);
      }


  printf("%d\n", ans);

  return 0;
}
