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
int binary_gcd(int a, int b);

// We use the following:
// gcd(a, a) = a
// gcd(a, 0) = a
// gcd(0, a) = a
// gcd(par, par) = 2 * gcd(par / 2, par / 2)
// gcd(par, impar) = gcd(par / 2, impar)


int binary_gcd(int a, int b) {
  if (a == b)
    return a;
  if (!a)                       // a == 0
    return b;
  if (!b)                       // b == 0
    return a;

  if (~a & 1) {                 // a par
    if (~b & 1)                 // b par
      return binary_gcd(a >> 1, b >> 1) << 1;
    else                        // b ímpar;
      return binary_gcd(a >> 1, b);
  }
  else {                        // a ímpar
    if (~b & 1)                 // b par
      return binary_gcd(a, b >> 1);
    else {                      // b ímpar
      if (a > b)
        return binary_gcd( (a - b) >> 1, b);
      else
        return binary_gcd( (b - a) >> 1, a);
    }
  }
}

int main() {
  int a, b;
  
  while( scanf("%d%d", &a, &b) == 2)
    printf("%d\n", binary_gcd(a, b));

  return 0;
}
