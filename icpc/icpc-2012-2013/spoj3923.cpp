#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 110;

int main() {
  int TC;
  int i, j;
  int v[MAX][MAX], PD[MAX][MAX];
  
  scanf("%d", &TC);

  while (TC--) {
    int h, w;
    scanf("%d%d", &h, &w);
    for (i = 0; i < h; ++i) {
      for (j = 0; j < w; ++j) {
	scanf("%d", &v[i][j]);

	if (!i)
	  PD[i][j] = v[i][j];
	else {
	  int maior = PD[i-1][j];
	  if (j > 0)
	    maior = max(maior,PD[i-1][j-1]);
	  if (j < w - 1)
	    maior = max(maior,PD[i-1][j+1]);
	  PD[i][j] = v[i][j] + maior;
	}
      }
    }

    // for (i = 0; i < h; ++i, puts(""))
    //   for (j = 0; j < w; ++j)
    // 	printf("%4d ", PD[i][j]);
    
    int maior = -1;
    for (i = h - 1, j = 0; j < w; ++j)
      maior = max(maior, PD[i][j]);

    printf("%d\n", maior);


  }

  return 0;
}

/*
  Input:
  1
  6 5
  3 1 7 4 2
  2 1 3 1 1
  1 2 2 1 8
  2 2 1 5 3
  2 1 4 4 4
  5 2 7 5 1

  Output:
  32
*/
