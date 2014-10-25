#include <cstdio>
using namespace std;

int main() {
  int d;
  scanf("%d", &d);

  int v[] = {3600, 60, 1};

  for (unsigned i = 0; i < 3; ++i) {
    printf("%d", d / v[i]);
    d -= (d / v[i]) * v[i];
    
    if (i < 2)
      printf(":");
  }

  puts("");

  return 0;
}

/*
  556

  0:9:16
*/
