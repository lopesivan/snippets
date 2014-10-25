#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
  int n;
  char next[1000];

  scanf("%d%*c", &n);

  while (n--) {
    scanf("%[^\n]%*c", next);

    int i;
    int tam = strlen(next);

    for (i = 0; i < tam; ++i)
      if (isalpha(next[i]))
	  next[i] += 3;

    char next2[1000];

    for (i = 0; i < tam; ++i)
      next2[i] = next[tam-1-i];
    next2[tam] = '\0';

    for (i = tam/2; i < tam; ++i)
      --next2[i];

    puts(next2);
    
  }

  return 0;
}
