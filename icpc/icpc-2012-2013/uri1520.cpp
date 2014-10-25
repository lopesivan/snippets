#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
  int n;
  int v[150];
  int target;

  while ( scanf("%d", &n) == 1) {
    int a, b;
    memset(v, 0, sizeof v);
    
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &a, &b);

      for (int j = a; j <= b; ++j) {
        v[j]++;
      }
    }

    scanf("%d", &target);

    int offset = 0;
    for (int i = 1; i < target; ++i)
      offset += v[i];

    if (v[target])
      printf("%d found from %d to %d\n", target, offset, offset + v[target] - 1);
    else
      printf("%d not found\n", target);
  }

  return 0;
}

/*
  3
  1 3
  2 4
  3 5
  4
  4
  1 3
  2 4
  1 5
  3 6
  3
  2
  1 3
  3 5
  7

  4 found from 6 to 7
  3 found from 5 to 8
  7 not found
 */
