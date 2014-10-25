/*
  Sample Input:
  9 10
  1 3 4 8 10 1029 1889 39293 109201
  3 4
  3 4 5


  Sample Output:
  4
  1

*/

#include <algorithm>
#include <cstdio>
using namespace std;

/* Returns the position of v where key is (0-based index). If not
   found, returns -1. If found several of them, returns the position
   of the first one. The interval considered is [a,b] */
int binary_search(int *v, int a, int b, int key);

int binary_search(int *v, int a, int b, int key) {

  // 0 1 2 3

  int middle = a + (b - a) / 2;

  if (v[middle] == key) {
    // return middle;
    while( middle >= 0 && v[middle] == key )
      --middle;
    return middle + 1;
  }
  
  else if (middle == a)
    return -1;
           
  else if (v[middle] > key)
    return binary_search(v, a, middle, key);
  
  else if (v[middle] < key)
    return binary_search(v, middle + 1, b, key);
  
  else
    return -2; // shouldn't happen!
}

int main() {
  int *v, key, n;

  while( scanf("%d%d", &n, &key) == 2 ) {
    v = new int[n];

    for (int i = 0; i < n; ++i)
      scanf("%d", &v[i]);

    printf("%d\n", binary_search(v, 0, n - 1, key));

    delete v;
  }

  return 0;
}
