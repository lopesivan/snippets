#include <cstdio>
#include <cstdlib>
using namespace std;
int v[70];

int go (int x) {
  if (v[x] == x)
    return x;
  else
    return go(v[x]);
}

int main() {
  int n;
  int target;

  while( scanf("%d", &n) && n != 0) {
    for (int i = 1; i <= n; ++i)
      scanf("%d", &v[i]);
    
    scanf("%d", &target);

    printf("%d\n", go(target));
  }

  return 0;
}

/*
  3
  2 3 3
  1
  3
  1 3 2
  1
  0

  3
  1
*/
