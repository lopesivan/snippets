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

#include <climits>
#include <cstdio>
#include <algorithm>
using namespace std;

/* Sorts v using insertion sort. */
void selection_sort(int *v, int n);

void selection_sort(int *v, int n) {
  int imenor;

  // passar por tudo, tomar o mínimo, trocar
  for (int i = 0; i < n;  ++i) {

    int menor = INT_MAX;

    for (int j = i; j < n; ++j) {
      if (v[j] < menor) {
        imenor = j;
        menor = v[j];
      }
    }
    swap( v[i], v[imenor] );
  }
}

int main() {
  int *v;
  int n;

  while ( scanf("%d", &n) == 1) {
    v = new int[n];
    
    for (int i = 0; i < n; ++i)
      scanf("%d", &v[i]);

    selection_sort(v, n);

    for (int i = 0; i < n - 1; ++i)
      printf("%d ", v[i]);
    printf("%d\n", v[n-1]);

    delete v;
  }

  return 0;
}
