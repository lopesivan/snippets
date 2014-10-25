#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX = 100100;

int main() {
  int n, TC = 0;
  int PD[MAX][3];
  int tmp;

  while( scanf("%d", &n), n) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < 3; ++j)
        scanf("%d", &PD[i][j]);

    // attention to negative numbers!
    PD[0][2] += PD[0][1];

    // second row
    PD[1][0] += PD[0][1];
    PD[1][1] += min(PD[0][1], min(PD[0][2], PD[1][0]));
    PD[1][2] += min(PD[0][1], min(PD[0][2], PD[1][1]));

    for (int i = 2; i < n; ++i)
      for (int j = 0; j < 3; ++j) {
        tmp = PD[i-1][1];
        if (j != 2)
          tmp = min(tmp, PD[i-1][0]);
        if (j != 0)
          tmp = min(tmp, PD[i-1][2]);
        if (j > 0)
          tmp = min(tmp, PD[i][j-1]);

        PD[i][j] += tmp;
      }

    // for (int i = 0; i < n; ++i) {
    //   for (int j = 0; j < 3; ++j) {
    //     printf("%2d ", PD[i][j]);
    //   }
    //   puts("");
    // }


    int ans = PD[n-1][1];
    printf("%d. %d\n", ++TC, ans);
  }

  return 0;
}

/*
  Input:
  4
  13 7 5
  7 13 6
  14 3 12
  15 6 16
  4
  13 7 5
  7 13 6
  14 3 12
  15 6 16
  0

  Output:
  1. 22
*/
