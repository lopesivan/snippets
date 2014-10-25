#include <cstdio>
#include <cstdlib>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
  const int n = 5;
  int g[10][10];
  int i, j;

  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
      scanf("%d", &g[i][j]);

  int _d[4][5] = {
    {1,3,2,4,5},
    {1,3,4,2,5},
    {1,2,3,4,5},
    {1,4,3,2,5}};

  int d[4][5];
  for (i = 0; i < 4; ++i)
    for (j = 0; j < 5; ++j)
      d[i][j] = _d[i][j] - 1;

  int menor = INT_MAX;
  int ians;

  for (i = 0; i < 4; ++i) {
    int dist = 0;
    for (j = 0; j < 4; ++j) {
      dist += g[ d[i][j] ] [ d[i][j+1] ];
    }
    if (dist < menor) {
      menor = dist;
      ians = i;
    }
  }
  printf("%d\n", menor);
  for (j = 0; j < 4; ++j)
    printf("%d ", _d[ians][j]);
  printf("%d\n", _d[ians][j]);
  
  return 0;
}
