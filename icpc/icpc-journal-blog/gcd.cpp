/*
  Sample Input:
  10 3
  50 20

  Sample output:
  1
  10
*/

#include <cstdio>
using namespace std;

/* Recursive function. */
int gcd_recursive(int a, int b);

// We use Euclid's Theorem
// gcd(a, b) = gcd(a, a % b) = gcd(b, a % b)
// 50 20
// 20 10
// 10 0

// 20 50
// 50 20

int gcd_recursive(int a, int b) {
  if (!b)
    return a;
  else
    return gcd_recursive(b, a % b);
}

int main() {
  int a, b;
  
  while( scanf("%d%d", &a, &b) == 2)
    printf("%d\n", gcd_recursive(a, b));

  return 0;
}
