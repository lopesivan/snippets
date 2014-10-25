#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  int TC, tam;
  char str[50100];
  scanf("%d", &TC);
  while(TC--) {
    scanf("%*d %s\n", str);
    tam = strlen(str);
    printf("%c\n", str[tam - 1]);
  }
  
  return 0;
}

/*
  Input:
  1
  3 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB 

  Output:
  B
*/
