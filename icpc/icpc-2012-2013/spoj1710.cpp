#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1010;

int n;
int v[MAX];
int pd[2][MAX][MAX];

int gogo(int i, int j, int vez) {

  if (i > j) { //critério de parada
    return 0;
  }

  if (!vez) { //player 1
    if (pd[0][i][j] == -1) {
      pd[0][i][j] = max (
			 v[i] + gogo(i+1, j, 1 - vez),
			 v[j] + gogo(i, j-1, 1 - vez)
			 );
    }
  }

  else {

    if (pd[1][i][j] == -1) {
      int imax = v[j] > v[i] ? j : i;

      if (imax == j)
	pd[1][i][j] = -v[j] + gogo(i, j - 1, 1 - vez);
      else
	pd[1][i][j] = -v[i] + gogo(i + 1, j, 1 - vez);
    }
}

  return pd[vez][i][j];
}

int main() {
  int TC = 0;
  while(scanf("%d", &n), n) {
    for (int i = 0; i < n; ++i)
      scanf("%d", &v[i]);
    memset(pd, -1, sizeof pd);
    gogo(0, n-1, 0);
    printf("In game %d, the greedy strategy might lose by as many as %d points.\n", ++TC, pd[0][0][n-1]);
  }

  return 0;
}
