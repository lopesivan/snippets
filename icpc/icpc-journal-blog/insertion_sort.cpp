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

#include <cstdio>
#include <algorithm>
using namespace std;

/* Sorts v using insertion sort. */
void insertion_sort(int *v, int n);

void insertion_sort(int *v, int n) {
  
  // 5 4 3 2 1

  for (int i = 0; i < n; ++i) {
    for (int j = i; j > 0; --j) {
      if (v[j] < v[j-1])
        swap(v[j], v[j-1]);
      else
        break;
    }
  }
}

int main() {
  int *v;
  int n;

  while ( scanf("%d", &n) == 1) {
    v = new int[n];
    
    for (int i = 0; i < n; ++i)
      scanf("%d", &v[i]);

    insertion_sort(v, n);

    for (int i = 0; i < n - 1; ++i)
      printf("%d ", v[i]);
    printf("%d\n", v[n-1]);

    delete v;
  }

  return 0;
}
