#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int i,j;
  int lim = 2*n+1;

  for (i = 0; i < lim; ++i) {
    for (j = 0; j < lim; ++j) {
      i == j ? printf("0") : printf("%d",(i+j)<=lim? i+j : i+j-lim );
      j != lim-1 ? printf(" ") : puts("");
    }
  }

  return 0;
}
