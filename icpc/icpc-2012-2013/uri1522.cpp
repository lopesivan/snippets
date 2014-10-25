#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAX = 103;
int n;
int v[MAX][3];
int pd[MAX][MAX][MAX];

int solve(int a, int b, int c) {
  // printf("%d %d %d\n", a, b, c);

  // já resolvi isso antes
  if (pd[a][b][c] != -1)
    return pd[a][b][c];

  // ganhei!
  if (!a && !b && !c) {
    pd[a][b][c] = 1;
    return pd[a][b][c];
  }

  int ka = v[a][0];
  int kb = v[b][1];
  int kc = v[c][2];
  
  // o valor de um deles é igual a zero
  if ( !ka )
    pd[a][b][c] = solve( a - 1, b, c);

  else if ( !kb )
    pd[a][b][c] = solve (a, b - 1, c);

  else if ( !kc )
    pd[a][b][c] = solve (a, b, c - 1);

  else if ( ( ka == 1 && kb == 1 && kc == 1) || ( ka == 2 && kb == 2 && kc == 2) )
    pd[a][b][c] = solve(a - 1, b - 1, c - 1);

  if (pd[a][b][c] == 1)
    return pd[a][b][c];

  // -- 

  if ( ( kb == 1 && kc == 2 ) || ( kb == 2 && kc == 1) )
    pd[a][b][c] = solve(a, b - 1, c - 1);

  if (pd[a][b][c] == 1)
    return pd[a][b][c];

  if ( (ka == 1 && kc == 2) || (ka == 2 && kc == 1) )
    pd[a][b][c] = solve(a - 1, b, c - 1);

  if (pd[a][b][c] == 1)
    return pd[a][b][c];  

  if ( (ka == 1 && kb == 2) || (ka == 2 && kb == 1) )
    pd[a][b][c] = solve(a - 1, b - 1, c);

  if ( pd[a][b][c] == -1 )
    pd[a][b][c] = 0;
  
  return pd[a][b][c];
}

int main() {
  int tmp;
  
  while( scanf("%d", &n) && n != 0) {
    memset(pd, -1, sizeof pd);
    v[0][0] = v[0][1] = v[0][2] = -100;
    
    for (int i = n; i >= 1; --i) {
      for (int j = 0; j < 3; ++j) {
        scanf("%d", &tmp);
        v[i][j] = tmp % 3; // 0, 1 e 2 apenas
      }
    }
    printf("%d\n", solve(n, n, n));
  }

  return 0;
}
