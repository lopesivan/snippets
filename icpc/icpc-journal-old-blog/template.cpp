/*
  Sample Input:
  3
  1 2 3

  Sample Output:
  1 2 3
*/

#include <cstdio>
#include <algorithm>
using namespace std;

/* Minidescription. Sorts v using... */
void regex(int *v, int n);

void regex(int *v, int n) {

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
