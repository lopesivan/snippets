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

/* Sorts v using merge sort. The interval considered is [a,b] only */
void merge_sort(int *v, int a, int b);

void merge_sort(int *v, int a, int b) {

  // Let's: sort the two halves individually (recursively)
  // Then, merge them

  // (a + b)/2 == a + (b - a) / 2 -- que isso fique bem claro!!!
  // 1 4 --> 2 {1,2}
  // 1 5 --> 3 {1,2,3}
  // Lado esquerdo usualmente maior

  int middle = a + (b - a) / 2;

  // [1, 3] --> 2, continue
  // [1, 2] --> 1, não spawnar mais, please

  if ( a != middle ) {
    merge_sort(v, a, middle);
    merge_sort(v, middle + 1, b);
  }

  // here happens the merge
  // 2 4 5  and 1 2 4
  // a   m      m+1   b

  // 3          2
  // a == m     m+1     b   

  int n = b - a + 1;
  int *aux = new int[n];

  int i1 = a; // <= middle
  int i2 = middle + 1; // <= b
  
  for (int i = 0; i < n; ++i) {
    
    if (i1 > middle) {
      aux[i] = v[i2++];
      continue;
    }

    if (i2 > b) {
      aux[i] = v[i1++];
      continue;
    }

    if (v[i1] < v[i2])
      aux[i] = v[i1++];

    else
      aux[i] = v[i2++];
  }

  for (int i = 0; i < n; ++i)
    v[a + i] = aux[i];
}

int main() {
  int *v;
  int n;

  while( scanf("%d", &n) == 1 ) {
    v = new int[n];

    for (int i = 0; i < n; ++i)
      scanf("%d", &v[i]);

    merge_sort(v, 0, n - 1);

    for (int i = 0; i < n - 1; ++i)
      printf("%d ", v[i]);
    printf("%d\n", v[n-1]);

    delete v;
  }

  return 0;
}
