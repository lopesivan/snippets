#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1010;

int main() {
  int n;
  int v[MAX], q[MAX];

  while ( scanf("%d", &n) == 1 && n != 0 ) {
    
    for (int i = 0; i < n; ++i) {
      scanf("%d", &v[i]);
      q[i]= v[i];
    }

    sort(q, q + n);

    for (int i = 0; i < n; ++i) {
      if (v[i] == q[n-2]) {
        printf("%d\n", i + 1);
        break;
      }
    }

  }

  return 0;
}
