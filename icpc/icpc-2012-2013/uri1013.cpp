#include <cstdio>
using namespace std;
#define max(a,b) (((a) > (b)) ? (a) : (b))

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);

  int maior = max(a,b);
  maior = max(maior, c);
  printf("%d eh o maior\n", maior);

  return 0;
}

/*
  7 14 6

  14 eh o maior
*/
