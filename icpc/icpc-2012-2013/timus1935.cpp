#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int maior=-1, tmp;
  int sum = 0;  

  for (int i = 0; i < n; ++i) {
    scanf("%d", &tmp);
    sum += tmp;
    maior = max(maior, tmp);
  }
  sum+=maior;

  printf("%d\n", sum);

  return 0;
}
