#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n, x, y;

int ok(int a, int b) {
  return a >= 1 && a <= n && b >=1 && b <= n;
}

bool canto() {
  return (x == 1 && y == 1) || (x == n && y == n) || (x == 1 && y == n) || (x == n && y ==1);
}

bool edge() {
  return (x == 1 && y != 1 && y != n) || (x != 1 && x != n && y == n) || (x != 1 && x != n && y == 1) || (x == n && y != 1 && y != n);
}


int dking[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int king() {
  int ans = 0;
  int tgx, tgy;
  for (int i = 0; i < 8; ++i) {
    tgx = x + dking[i][0];
    tgy = y + dking[i][1];
    if ( ok(tgx,tgy))
      ++ans;
  }
  return ans;
  // if (canto())
  //   return 3;
  // else if (edge())
  //   return 5;
  // else
  //   return 8;
}

int rook() {
  return 2 * n - 2;
}

int bishop() {
  return \
    min(y - 1, x - 1) + \
    min(y - 1, n - x) + \
    min(n - x, n - y) + \
    min(x - 1, n - y);
}

int queen() {
  return rook() + bishop();
}

int dknight[8][2] = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
int knight() {
  int ans = 0;
  int tgx, tgy;
  for (int i = 0; i < 8; ++i) {
    tgx = x + dknight[i][0];
    tgy = y + dknight[i][1];
    if ( ok(tgx,tgy))
      ++ans;
  }
  return ans;
}

int main() {
  scanf("%d %d %d", &n, &x, &y);

  printf("King: %d\n", king());
  printf("Knight: %d\n", knight());
  printf("Bishop: %d\n", bishop());
  printf("Rook: %d\n", rook());
  printf("Queen: %d\n", queen());
  
  return 0;
}
