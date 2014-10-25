#include<cstdio>
#include<cstdlib>
using namespace std;

int main() {
  int n;
  while (scanf("%d", &n), n) {
    int i;
    for (i = 1; i < n ; ++i) {
      printf("%d ",i);
    }
    printf("%d\n",i);
  }

  return 0;
}

/*
5
3
10
0
*/
