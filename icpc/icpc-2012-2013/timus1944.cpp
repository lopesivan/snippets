#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <utility>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX (250+50)
#define TABMAX (200+50)
#define vi vector<int>
#define vii vector<vi>
#define pi pair<int, int>

#define PLUSINF int(1e9)
#define MINUSINF int(-1e9)

int main() {

  int i, j, k;
  int n;
  int x, y;
  char tab[TABMAX][TABMAX];

  for (i = 0; i < TABMAX; ++i) {
    for (j = 0; j < TABMAX; ++j) {
      tab[i][j] = '.';

      if (i == 100 && j == 100)
	tab[i][j] = '+';
      else if (i == 100)
	tab[i][j] = '|';
      else if (j == 100)
	tab[i][j] = '-';
    }
  }

  // for (i = 0; i < TABMAX; ++i) {
  //   for (j = 0; j < TABMAX; ++j) {
  //     printf("%c", tab[i][j]);
  //   }
  //   puts("");
  // }

  scanf("%d", &n);

  int xmax,xmin,ymax,ymin;
  xmax = ymax = -1000;
  xmin = ymin = 1000;

  for (i = 0; i < n; ++i) {
    scanf("%d%d", &x, &y);
    x += 100;
    y += 100;
    tab[x][y] = '*';

    xmax = max(xmax,x);
    xmin = min(xmin,x);
    ymax = max(ymax,y);
    ymin = min(ymin,y);
  } 

  xmax=max(xmax,100);
  ymax=max(ymax,100);
  xmin=min(xmin,100);
  ymin=min(ymin,100);

  for (j = ymax; j >= ymin; --j) {
    for (i = xmin; i <= xmax; ++i) {
      printf("%c", tab[i][j]);
    }
    puts("");
  }

  return 0;
}
