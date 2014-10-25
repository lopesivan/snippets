#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxr = 1234;
const int maxc = 5678;
int R[maxr + 1], C[maxc + 1], rR[maxr + 1], rC[maxc + 1];

int main() {
  char s[2];
  int x, y, w, tmp;

  for (int i = 1; i <= maxc; ++i) {
    C[i] = i;
    rC[i] = i;
  }
  for (int i = 1; i <= maxr; ++i) {
    R[i] = i;
    rR[i]= i;
  }

  while( scanf("%s", s) == 1 ) {

    switch(s[0]) {
    case 'R':
      scanf("%d%d", &x, &y);
      swap(R[x], R[y]);
      rR[R[x]] = x;
      rR[R[y]] = y;
      break;
    case 'C':
      scanf("%d%d", &x, &y);
      swap(C[x], C[y]);
      rC[C[x]] = x;
      rC[C[y]] = y;
      break;
    case 'Q':
      scanf("%d%d", &x, &y);
      tmp = (R[x] - 1) * maxc + C[y];
      printf("%d\n", tmp);
      break;
    case 'W':
      scanf("%d", &w);
      // samples:
      // maxc = 400;
      // w = 500;
      x = 1 + ((w - 1)/ maxc);
      y = 1 + (w - 1) % maxc;
      printf("%d %d\n", rR[x], rC[y]);
      break;
    }
  }


  return 0;
}

/*
  R[3] = 7 significa, por exemplo, que quem está na linha 3 é a original linha 7
  rR[7] = 3 significa que a original linha 7 está agora na linha 3
  f(x) = y ==> f-1(y) = x: são funções inversas!
*/

/*
  Input:
  R 1 2
  Q 1 1
  Q 2 1
  W 1
  W 5679
  C 1 2
  Q 1 1
  Q 2 1
  W 1
  W 5679

  Output:
  5679
  1
  2 1
  1 1
  5680
  2
  2 2
  1 2
*/
