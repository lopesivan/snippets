#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;

int get_int(char* p) {
  int tam = strlen(p);

  bool flag = true;
  for (int i = 0; i < tam; ++i) {
    if (!isdigit(p[i])) {
      flag = false;
      break;
    }
  }

  if (flag) {
    int tmp;
    sscanf(p, "%d", &tmp);
    return tmp;
  } 
  else
    return -1;
}

int main() {
  int TC;
  char input[100];
  char* p;
  scanf("%d\n", &TC);
  int a[3];

  while(TC--) {
    scanf("\n");
    scanf("%[^\n]\n", input);

    p = strtok(input, "+= ");
    int i = 0;

    while (p != NULL) {
      a[i++] = get_int(p);
      p = strtok(NULL, "+= ");
    }

    if (a[0] == -1)
      printf("%d + %d = %d\n", a[2] - a[1], a[1], a[2]);
    else if (a[1] == -1)
      printf("%d + %d = %d\n", a[0], a[2] - a[0], a[2]);
    else
      printf("%d + %d = %d\n", a[0], a[1], a[0] + a[1]);
  }

  return 0;
}
