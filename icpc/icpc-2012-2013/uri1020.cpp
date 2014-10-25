#include <cstdio>
using namespace std;

int main() {
  int d;
  scanf("%d", &d);

  int v[] = {365, 30, 1};

  for (unsigned i = 0; i < 3; ++i) {
    printf("%d ", d / v[i]);
    d -= (d / v[i]) * v[i];
    
    switch(i) {
    case 0:
      puts("ano(s)");
      break;
    case 1:
      puts("mes(es)");
      break;
    case 2:
      puts("dia(s)");
      break;
    }
  }

  return 0;
}

/*
  400

  1 ano(s)
  1 mes(es)
  5 dia(s)
*/

