/*
  Sample Input:
  3
  1 2 3
  3
  3 2 1

  Sample Output:
  1 2 3
  1 2 3
*/

#include <algorithm>
#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;

/* Sorts v using counting sort. This is an in place version. */
void counting_sort(int *v, int n);

void counting_sort(int *v, int n) {
  int maior = INT_MIN;

  for (int i = 0; i < n; ++i)
    maior = max(maior, v[i]);

  int *count = new int[maior + 1]; // please do not overflow...
  memset(count, 0, (maior + 1) * sizeof(int));

  for (int i = 0; i < n; ++i)
    ++count[ v[i] ];

  // count is like
  // 0 1 2 3 4 ...
  // 5 0 3 2 0 ...

  int qt = 0;
  for (int i = 0; i <= maior && qt < n; ++i) {
    if (count[i] > 0) {
      for (int k = 0; k < count[i]; ++k)
        v[qt++] = i;
    }
  }

}

int main() {
  int *v;
  int n;

  while( scanf("%d", &n) == 1 ) {
    v = new int[n];

    for (int i = 0; i < n; ++i)
      scanf("%d", &v[i]);

    counting_sort(v, n);

    for (int i = 0; i < n - 1; ++i)
      printf("%d ", v[i]);
    printf("%d\n", v[n-1]);

    delete v;
  }

  return 0;
}
