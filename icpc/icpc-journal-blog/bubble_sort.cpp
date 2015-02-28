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
using namespace std;

/* Sorts v using bubble sort. */
void bubble_sort(int *v, int n);

void bubble_sort(int *v, int n) {

  // n = 5
  // 0 1 2 3 4 -- indices
  // 5 4 3 2 1 -- sample input
  // 4 3 2 1 5 -- end of the first iteration
  // 3 2 1 4 5 -- end of the second iteration

  for (int i = n - 1; i >= 0; --i) {
    bool swapped = false;
    for (int j = 0; j < i; ++j) {
      if (v[j] > v[j + 1]) {
        swap( v[j], v[j+1] );
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }

}

int main() {
  int *v;
  int n;

  while( scanf("%d", &n) == 1 ) {
    v = new int[n];

    for (int i = 0; i < n; ++i)
      scanf("%d", &v[i]);

    bubble_sort(v, n);

    for (int i = 0; i < n - 1; ++i)
      printf("%d ", v[i]);
    printf("%d\n", v[n-1]);

    delete v;
  }

  return 0;
}
