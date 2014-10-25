#include <cstdio>

int main() {
  int q, d, p;

  while( scanf("%d", &q) == 1 && q ) {
    scanf("%d%d", &d, &p);

    int t = (p * d) / (p - q);
    int ans = q * t;

    printf("%d ", ans);
    ans == 1 ? puts("pagina") : puts("paginas");
  }

  return 0;
}
