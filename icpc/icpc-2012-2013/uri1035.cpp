#include <cstdio>
using namespace std;

int main() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);

  if((b > c) && (d > a) && ( (c + d) > (a + b)) && ( c > 0) && (d > 0) && (~a & 1)  )
    puts("Valores aceitos");
  else
    puts("Valores nao aceitos");

  return 0;
}

/*
  5 6 7 8

  Valores nao aceitos
*/
