#include <cstdio>
using namespace std;

int main() {
  int a, b, c;

  while (scanf("%d%d%d", &a, &b, &c), a || b || c) {

    if ( (b - a) == (c - b) )
      printf("AP %d\n", c + (c - b));
    else
      printf("GP %d\n", c * c / b);
  }

  return 0;
}

/*
  Input:
  4 7 10
  2 6 18
  0 0 0

  Output:
  AP 13
  GP 54
*/
