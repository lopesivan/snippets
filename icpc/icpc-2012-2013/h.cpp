#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <climits>
#include <cmath>
#include <limits>
using namespace std;
const int MAX = 105;

int n;
pair<double, double> pos[MAX];
double raio[MAX];
double g[MAX][MAX];
double ans[MAX][MAX];

inline double sq(double x) {
  return x * x;
}

inline double dist(pair<double,double> p1, pair<double,double> p2) {
  return sqrt( sq(p1.first - p2.first) + sq(p1.second - p2.second)  );
}

void calc() {
  double tmp;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      tmp = dist(pos[i], pos[j]);
      if ((tmp > raio[i])  || (tmp > raio[j] ))
        g[i][j] = -1;
      else
        g[i][j] = tmp;
    }
  }
}

void floyd() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (g[i][j] == -1) {
        ans[i][j] = numeric_limits<double>::max() / 3;
      }
      else
        ans[i][j] = g[i][j];
    }
  }

  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        ans[i][j] = min( ans[i][j],  ans[i][k] + ans[k][j]  );
}


int main() {
  int x, y, r;

  while( scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; ++i) {
      scanf("%d%d%d", &x, &y, &r);
      pos[i] = pair<double,double>(double(x), double(y));
      raio[i] = double(r);
    }

    calc();
    floyd();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        printf("%2d %2d %3lf %3lf\n", i, j, g[i][j], ans[i][j]);
      }
    }

    int nqueries, a, b;
    scanf("%d", &nqueries);
    for (int i = 0; i < nqueries; ++i) {
      scanf("%d%d", &a, &b);
      printf("%lf\n", (ans[a][b]) );
    }
  }

  return 0;
}
