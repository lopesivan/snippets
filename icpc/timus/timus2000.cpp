#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
  int n, i;
  int v[110000];
  int soma1 = 0, total = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &v[i]);
    total += v[i];
  }

  int p1, p2;
  scanf("%d%d", &p1, &p2);

  if (p1 < p2) {
    int diff = (p2 - p1) / 2;
    for (i = 1; i <= p1 + diff; ++i)
      soma1 += v[i];
  }
  else if (p1 > p2) {
    int diff = (p1 - p2) / 2;
    for (int i = p1 - diff; i <= n; ++i)
      soma1 += v[i];
  }
  else {
    soma1 = 0;
    for (i = 0; i <= p1; ++i)
      soma1 += v[i];
    int soma1_alt = 0;
    for (i = p1; i <= n; ++i)
      soma1_alt += v[i];
    soma1 = max(soma1, soma1_alt);
  }
  
  printf("%d %d\n", soma1, total - soma1);
  return 0;
}
